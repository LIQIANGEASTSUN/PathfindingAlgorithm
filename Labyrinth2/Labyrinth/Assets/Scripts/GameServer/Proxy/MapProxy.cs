using System.Collections;
using System.Collections.Generic;
using PathFinding;
using UnityEngine;

public class MapProxy : IMapProxy
{
    private IMapProxy mapProxy;
    public MapProxy(IMapProxy mapProxy)
    {
        this.mapProxy = mapProxy;
    }

    public IMap IMap()
    {
        return mapProxy.IMap();
    }

    public Vector2 NodeToPosition(Node node)
    {
        return mapProxy.NodeToPosition(node);
    }

    public Node PositionToNode(float x, float y)
    {
        return mapProxy.PositionToNode(x, y);
    }

    public Node NodeNeighbor(Node node, int index)
    {
        return mapProxy.NodeNeighbor(node, index);
    }
}
