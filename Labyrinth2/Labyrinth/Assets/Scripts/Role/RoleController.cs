using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using PathFinding;

public enum DirEnum
{
    none = -1,
    up = 0,
    down = 1,
    left = 2,
    right = 3,
}

public class RoleController : SingletonObject<RoleController>
{
    private Transform _roleTr;
    private float _moveSpeed = 0.5f;
    private float _rotateSpeed = 0.2f;
    private Node _currentNode;
    private Vector2 _currentNodePosition;
    private const float _useRockerDirMin = 0.05f;

    private Vector2[] _axisArr = new Vector2[] {
        new Vector2( 0,  1),
        new Vector2( 0, -1),
        new Vector2(-1,  0),
        new Vector2( 1,  0),
    };

    public RoleController()
    {
        _roleTr = GameObject.Find("Role").transform;
    }

    public void LateUpdate()
    {
    }

    public void Move(Vector3 dir)
    {
        CurrentNode();
        if (UseRockerDir())
        {
            if (!TransitionRockerDir(dir, ref dir))
            {
                return;
            }
        }
        else
        {
            DirEnum axis = DirEnum.none;
            if (!TransitionRockerDirWithAxis(dir, ref dir, ref axis))
            {
                return;
            }

            Debug.LogError(dir.ToString("f2"));
            //Vector3 pos = Position;
            //if (axis == DirEnum.up || axis == DirEnum.down)
            //{
            //    pos.x = _currentNodePosition.x;
            //}
            //else if (axis == DirEnum.left || axis == DirEnum.right)
            //{
            //    pos.y = _currentNodePosition.y;
            //}
            //_roleTr.transform.position = pos;
        }
        _roleTr.Translate(dir * _moveSpeed * Time.deltaTime, Space.World);
        MoveDirToRotate(dir);
    }

    private bool TransitionRockerDir(Vector3 dir, ref Vector3 result)
    {
        DirEnum axis = DirClosetAxis(dir);
        if (!ValidAxis(axis))
        {
            return false;
        }
        result = _axisArr[(int)axis];
        return true;
    }

    private bool TransitionRockerDirWithAxis(Vector3 dir, ref Vector3 result, ref DirEnum axis)
    {
        axis = RoleClosestAxis();
        if (!ValidAxis(axis))
        {
            return false;
        }
        result = _axisArr[(int)axis];
        float dot = Vector2.Dot(dir, _axisArr[(int)axis]);
        if (dot < 0)
        {
            result *= 1;
        }
        return true;
    }

    private bool ValidAxis(DirEnum axis)
    {
        if (axis == DirEnum.none)
        {
            return false;
        }
        int bit = 1 << (int)axis;
        return (_currentNode.Flag & bit) == 0;
    }

    private void MoveDirToRotate(Vector3 dir)
    {
        float rockerAngle = AngleTools.AngleUI(Vector3.up, dir);
        Quaternion quaternion = Quaternion.AngleAxis(rockerAngle, Vector3.forward);
        Rotate(quaternion);
    }

    public void Rotate(Quaternion quaternion)
    {
        _roleTr.rotation = quaternion;
    }

    public Vector3 Forward
    {
        get { return _roleTr.up; }
    }

    public Vector3 Position
    {
        get {
            return _roleTr.position;
        }
    }

    public Quaternion RoleRotate
    {
        get {
            return _roleTr.rotation;
        }
    }
    
    public float RotateSpeed
    {
        get { return _rotateSpeed; }
    }

    private Node CurrentNode()
    {
        if (null != _currentNode)
        {
            Vector2 offset = Offset();
            float offsetX = Mathf.Abs(offset.x);
            float offsetY = Mathf.Abs(offset.y);
            if (offsetX > 0.5f || offsetY >= 0.5f)
            {
                _currentNode = null;
            }
        }
        if (null == _currentNode)
        {
            _currentNode = GameServer.GetInstance().MapProxy.PositionToNode(Position.x, Position.y);
            _currentNodePosition = GameServer.GetInstance().MapProxy.NodeToPosition(_currentNode);
            //Debug.LogError(_currentNode.Row + "   " + _currentNode.Col);
        }

        return _currentNode;
    }

    /// <summary>
    /// 角色距离当前格子上、下、左、右 四个轴最近的轴
    /// </summary>
    private DirEnum RoleClosestAxis()
    {
        float value = 0;
        DirEnum axis = DirEnum.none;
        Vector2 offset = Offset();
        for (int i = 0; i < _axisArr.Length; ++i)
        {
            Vector2 axisDir = _axisArr[i];
            float dot = Vector2.Dot(offset, axisDir);
            if (dot > value)
            {
                value = dot;
                axis = (DirEnum)i;
            }
        }
        return axis;
    }

    /// <summary>
    /// 上、下、左、右 四个轴与摇杆方向相似度最高的轴
    /// </summary>
    private DirEnum DirClosetAxis(Vector2 pos)
    {
        float value = 0;
        DirEnum axis = DirEnum.none;
        for (int i = 0; i < _axisArr.Length; ++i)
        {
            Vector2 axisDir = _axisArr[i];
            float dot = Vector2.Dot(pos, axisDir);
            if (dot > 0 && dot > value)
            {
                value = dot;
                axis = (DirEnum)i;
            }
        }
        return axis;
    }

    /// <summary>
    /// 当角色距离当前节点中心 x、y 的距离都小于等于某个值的时候，移动方向取摇杆方向
    /// </summary>
    /// <returns></returns>
    private bool UseRockerDir()
    {
        Vector2 offset = Offset();
        if (Mathf.Abs(offset.x) < _useRockerDirMin && Mathf.Abs(offset.y) < _useRockerDirMin)
        {
            return true;
        }
        return false;
    }

    private Vector2 Offset()
    {
        Vector2 pos = GameServer.GetInstance().MapProxy.NodeToPosition(_currentNode);
        return new Vector2(Position.x - pos.x, Position.y - pos.y);
    }

}
