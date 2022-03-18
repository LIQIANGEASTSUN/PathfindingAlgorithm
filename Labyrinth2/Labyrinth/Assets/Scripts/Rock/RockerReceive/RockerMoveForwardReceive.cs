using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// 摇杆操作人移动,只向人的前方移动
/// </summary>
public class RockerMoveForwardReceive : IRock
{
    public void Begin(Vector2 pos)
    {

    }

    public void End(Vector2 pos)
    {

    }

    public void Move(Vector2 pos, float percentage)
    {
        //Vector3 dir = RoleController.GetInstance().Forward;
        RoleController.GetInstance().Move(pos);
    }
}
