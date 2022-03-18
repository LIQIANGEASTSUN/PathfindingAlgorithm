using PathFinding;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface IMapProxy
{

    /// <summary>
    /// 根据坐标获取 Node
    /// </summary>
    Node PositionToNode(float x, float y);

    /// <summary>
    /// 根据 Node 获取坐标
    /// </summary>
    Vector2 NodeToPosition(Node node);

    /// <summary>
    /// 获取 Node 的第 index 个邻居
    /// </summary>
    Node NodeNeighbor(Node node, int index);

}
