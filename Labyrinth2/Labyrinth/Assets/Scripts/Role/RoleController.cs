using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RoleController : SingletonObject<RoleController>
{
    private Transform _roleTr;
    private float _moveSpeed = 1.5f;
    private float _rotateSpeed = 0.2f;

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
    }

    public void Rotate(Quaternion quaternion)
    {
        _roleTr.rotation = quaternion;
    }

    public Vector3 RoleForward
    {
        get { return _roleTr.up; }
    }

    public Vector3 RolePosition
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

}
