using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// 摇杆操作人转向
/// </summary>
public class RockerRotateReceive : IRock
{
    public RockerRotateReceive()
    {

    }

    public void Begin(Vector2 pos)
    {

    }

    public void Move(Vector2 pos, float percentage)
    {
        Vector3 dir = (Vector3)(pos.normalized);
        float rockerAngle = AngleTools.AngleUI(Vector3.up, dir);
        Quaternion quaternion = Quaternion.AngleAxis(rockerAngle, Vector3.forward);
        RoleController.GetInstance().Rotate(quaternion);
    }

    public void End(Vector2 pos)
    {

    }
}