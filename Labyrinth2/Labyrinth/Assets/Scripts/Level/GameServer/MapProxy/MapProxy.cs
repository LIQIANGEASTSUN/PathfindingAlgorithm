using System.Collections;
using System.Collections.Generic;
using PathFinding;
using UnityEngine;

public class MapProxy : IMapProxy
{
    private IMapProxy _mapProxy;
    public MapProxy(IMapProxy mapProxy)
    {
        this._mapProxy = mapProxy;
    }

    public void Init()
    {
        _mapProxy.Init();
    }

    public IMap IMap()
    {
        return _mapProxy.IMap();
    }

    public Vector2 NodeToPosition(Node node)
    {
        return _mapProxy.NodeToPosition(node);
    }

    public Node PositionToNode(float x, float y)
    {
        return _mapProxy.PositionToNode(x, y);
    }

    public Node NodeNeighbor(Node node, int index)
    {
        return _mapProxy.NodeNeighbor(node, index);
    }

    public Node EntryNode()
    {
        return _mapProxy.EntryNode();
    }

    public Node ExitNode()
    {
        return _mapProxy.ExitNode();
    }

}
