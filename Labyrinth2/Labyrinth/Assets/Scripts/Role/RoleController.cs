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
    private RoleMoveController _roleMoveController;

    public RoleController()
    {
    }

    public void Init()
    {
        _roleMoveController = new RoleMoveController(this);
        _roleMoveController.ChangeNodeCallBack(MoveChangeNodeCallBack);
        LoadRole();
    }

    public void LateUpdate()
    {
    }

    private void LoadRole()
    {
        GameObject go = ResourcesManager.GetInstance().Load<GameObject>("Role");
        go = GameObject.Instantiate(go);
        _roleTr = go.transform;
        _roleTr.localScale = Vector3.one;
        _roleTr.rotation = Quaternion.identity;

        Node entryNode = GameServer.GetInstance().MapProxy.EntryNode();
        SetPosition(GameServer.GetInstance().MapProxy.NodeToPosition(entryNode));
    }

    public void Release()
    {
        GameObject.Destroy(_roleTr.gameObject);
    }

    public void Move(Vector3 dir)
    {
        _roleMoveController.Move(dir);
    }

    private void MoveChangeNodeCallBack(Node currentNode)
    {
        Node exitNode = GameServer.GetInstance().MapProxy.ExitNode();
        if (exitNode.Row == currentNode.Row && exitNode.Col == currentNode.Col)
        {
            GameNotifycation.GetInstance().Notify(ENUM_MSG_TYPE.MSG_MOVE_TO_EXIT);
        }
    }

    public void Rotate(Quaternion quaternion)
    {
        _roleTr.rotation = quaternion;
    }

    public void SetPosition(Vector3 position)
    {
        _roleTr.position = position;
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
}