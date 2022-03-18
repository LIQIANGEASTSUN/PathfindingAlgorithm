using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

/// <summary>
/// 第三人称视角，摇杆同时操作角色转向和移动
/// 操作摇杆人转向，人向摇杆操作方向移动
/// </summary>
public class TPPMoveAndRotateRocker
{
    private Transform _transform;
    private RoleRockerInput _roleRockerInput;

    public TPPMoveAndRotateRocker(Transform transform)
    {
        _transform = transform;
        Init();
    }

    private void Init()
    {
        _roleRockerInput = new RoleRockerInput(_transform);

        // 控制人转向
        RockerRotateReceive rockerRotateReceive = new RockerRotateReceive();
        _roleRockerInput.AddRocker(rockerRotateReceive);
        // 控制人移动
        RockerMoveForwardReceive rockerMoveForwardReceive = new RockerMoveForwardReceive();
        _roleRockerInput.AddRocker(rockerMoveForwardReceive);
        // 控制摇杆按钮上的指示方向的箭头
        RolerRockerArrowReceive rolerRockerArrowReceive = new RolerRockerArrowReceive(_transform);
        _roleRockerInput.AddRocker(rolerRockerArrowReceive);
    }

    public void Update()
    {
        _roleRockerInput.Update();
    }
}