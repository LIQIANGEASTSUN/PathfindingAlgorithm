using UnityEngine;
using PathFinding;
using System;

public class RoleMoveController
{
    private RoleController _roleController;
    private float _moveSpeed = 3f;
    private Node _currentNode;
    private Vector2 _currentNodePosition;
    private Action<Node> _changeNodeCallBack;
    private const float _useRockerDirMin = 0.05f;

    private Vector2[] _axisArr = new Vector2[] {
        new Vector2( 0,  1),
        new Vector2( 0, -1),
        new Vector2(-1,  0),
        new Vector2( 1,  0),
    };

    public RoleMoveController(RoleController roleController)
    {
        _roleController = roleController;
    }

    public void ChangeNodeCallBack(Action<Node> callBack)
    {
        _changeNodeCallBack = callBack;
    }

    public void Move(Vector3 dir)
    {
        CurrentPositionToNode();
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
            PressRoleToAxis(axis);
        }
        Vector3 position = _roleController.Position + dir * _moveSpeed * Time.deltaTime;
        _roleController.SetPosition(position);
    }

    /// <summary>
    /// 将摇杆方向转换为沿着轴(上、下、左、右 _axisArr)的方向
    /// 摇杆方向与 (上、下、左、右 _axisArr)某一个轴 的点乘 > 0, 则摇杆方向转换为 该轴的方向
    /// </summary>
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

    /// <summary>
    /// 将摇杆方向转换为沿着轴(上、下、左、右 _axisArr)的方向
    /// 如角色当前最近的轴是 上，则摇杆方向与 上(0, 1) 点乘 > 0 则摇杆方向转换为上，否则转换为下
    /// </summary>
    private bool TransitionRockerDirWithAxis(Vector3 dir, ref Vector3 result, ref DirEnum axis)
    {
        axis = RoleClosestAxis();
        if (!ValidAxis(axis))
        {
            return false;
        }
        float dot = Vector2.Dot(dir, _axisArr[(int)axis]);
        result = (dot > 0) ? _axisArr[(int)axis] : _axisArr[(int)axis] * -1;
        return true;
    }

    /// <summary>
    /// 沿着轴走的时候将角色贴到轴上，防止坐标偏移
    /// </summary>
    private void PressRoleToAxis(DirEnum axis)
    {
        Vector3 pos = _roleController.Position;
        if (axis == DirEnum.up || axis == DirEnum.down)
        {
            pos.x = _currentNodePosition.x;
        }
        else if (axis == DirEnum.left || axis == DirEnum.right)
        {
            pos.y = _currentNodePosition.y;
        }
        _roleController.SetPosition(pos);
    }

    /// <summary>
    /// 方向轴对于当前节点是否有效，如果轴方向上有墙，则无效
    /// </summary>
    private bool ValidAxis(DirEnum axis)
    {
        if (axis == DirEnum.none)
        {
            return false;
        }
        int bit = 1 << (int)axis;
        return (CurrentNode.Flag & bit) == 0;
    }

    /// <summary>
    /// 角色当前所在节点
    /// </summary>
    private void CurrentPositionToNode()
    {
        if (null != CurrentNode)
        {
            Vector2 offset = Offset();
            float offsetX = Mathf.Abs(offset.x);
            float offsetY = Mathf.Abs(offset.y);
            if (offsetX > 0.5f || offsetY >= 0.5f)
            {
                CurrentNode = null;
            }
        }
        if (null == CurrentNode)
        {
            CurrentNode = GameServer.GetInstance().MapProxy.PositionToNode(_roleController.Position.x, _roleController.Position.y);
            _currentNodePosition = GameServer.GetInstance().MapProxy.NodeToPosition(CurrentNode);
            _changeNodeCallBack?.Invoke(CurrentNode);
        }
    }

    private Node CurrentNode
    {
        get
        {
            return _currentNode;
        }
        set
        {
            _currentNode = value;
        }
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
    private bool UseRockerDir()
    {
        Vector2 offset = Offset();
        if (Mathf.Abs(offset.x) < _useRockerDirMin && Mathf.Abs(offset.y) < _useRockerDirMin)
        {
            return true;
        }
        return false;
    }

    /// <summary>
    /// 偏移量 = 角色坐标 - 当前节点坐标
    /// </summary>
    private Vector2 Offset()
    {
        Vector2 pos = GameServer.GetInstance().MapProxy.NodeToPosition(CurrentNode);
        return new Vector2(_roleController.Position.x - pos.x, _roleController.Position.y - pos.y);
    }
}