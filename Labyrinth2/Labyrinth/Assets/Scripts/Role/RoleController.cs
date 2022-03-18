using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using PathFinding;

public class RoleController : SingletonObject<RoleController>
{
    private Transform _roleTr;
    private float _moveSpeed = 0.5f;
    private float _rotateSpeed = 0.2f;
    private Node _currentNode;
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
        _roleTr.Translate(dir * _moveSpeed * Time.deltaTime, Space.World);
        //Debug.LogError("Move");
        CurrentNode();
        ClosestAxis();
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
            Debug.LogError(_currentNode.Row + "   " + _currentNode.Col);
        }

        return _currentNode;
    }

    private int ClosestAxis()
    {
        float value = 0;
        int index = 0;
        Vector2 offset = Offset();
        for (int i = 0; i < _axisArr.Length; ++i)
        {
            Vector2 axis = _axisArr[i];
            float dot = Vector2.Dot(offset, axis);
            if (dot > value)
            {
                value = dot;
                index = i;
            }
        }
        return index;
    }

    private Vector2 Offset()
    {
        Vector2 pos = GameServer.GetInstance().MapProxy.NodeToPosition(_currentNode);
        return new Vector2(Position.x - pos.x, Position.y - pos.y);
    }

}
