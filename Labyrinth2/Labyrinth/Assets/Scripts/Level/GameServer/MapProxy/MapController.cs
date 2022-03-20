using System.Collections;
using System.Collections.Generic;
using PathFinding;
using UnityEngine;

/// <summary>
/// 地图格子类型
/// </summary>
public enum MapGridType
{
    // 入口
    Entry = 1,
    // 出口
    Exit = 2,
}

public class MapController : IMapProxy
{
    private IMap _imap;

    private const string _tableName = "";

    public MapController(IMap imap)
    {
        _imap = imap;
    }

    public void Init()
    {

    }

    public IMap IMap()
    {
        return _imap;
    }

    public Node NodeNeighbor(Node node, int index)
    {
        return _imap.NodeNeighbor(node, index);
    }

    public Vector2 NodeToPosition(Node node)
    {
        return _imap.NodeToPosition(node);
    }

    public Node PositionToNode(float x, float y)
    {
        return _imap.PositionToNode(x, y);
    }

    public Node EntryNode()
    {
        return null;
    }

    public Node ExitNode()
    {
        return null;
    }

    public void Release()
    {
        
    }
}
