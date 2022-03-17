using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AngleTools
{

    /// <summary>
    /// 从 from 向量到 to 向量的夹角
    /// </summary>
    /// <param name="from">开始向量</param>
    /// <param name="to">结束向量</param>
    /// <param name="cross">叉乘结果</param>
    /// <returns></returns>
    public static float Angle(Vector3 from, Vector3 to, ref Vector3 cross)
    {
        float angle = Vector3.Angle(from, to);
        cross = Vector3.Cross(from, to);
        return angle;
    }

    /// <summary>
    /// UI 上从 from 向量到 to 向量的夹角
    /// 要求 向量的 z 值为 0
    /// 因为UI上向量只有 X、Y 轴的值（Z轴值一直为0）
    /// from 到 to 是绕 Z 轴旋转的，根据左手坐标系旋转定理
    /// Z轴正向朝向屏幕内，所以视觉上看顺时针为负角度，逆时针为正角度
    /// 可以根据叉乘结果的 z 值与 0 比较 判断顺时针还是逆时针
    /// </summary>
    /// <param name="from"></param>
    /// <param name="to"></param>
    /// <returns></returns>
    public static float AngleUI(Vector3 from, Vector3 to)
    {
        Vector3 cross = Vector3.zero;
        float angle = Angle(from, to, ref cross);
        int sign = cross.z > 0 ? 1 : -1;
        return angle * sign;
    }

    /// <summary>
    /// 3D世界中水平面上从 from 向量到 to 向量的夹角
    /// 要求 向量的 y 值为 0
    /// from 到 to 是绕 Y 轴旋转的，根据左手坐标系旋转定理
    /// Y轴朝上，所以视觉上看顺时针为正角度，逆时针为负角度
    /// 可以根据叉乘结果的 y 值与 0 比较判断顺时针还是逆时针
    /// </summary>
    /// <param name="from"></param>
    /// <param name="to"></param>
    /// <returns></returns>
    public static float AngleModel(Vector3 from, Vector3 to)
    {
        Vector3 cross = Vector3.zero;
        float angle = Angle(from, to, ref cross);
        int sign = cross.y > 0 ? 1 : -1;
        return angle * sign;
    }

}
