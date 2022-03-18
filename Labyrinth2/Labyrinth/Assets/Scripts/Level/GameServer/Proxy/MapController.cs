using System.Collections;
using System.Collections.Generic;
using PathFinding;
using UnityEngine;

public class MapController : IMapProxy
{
    private IMap _imap;
    public MapController(IMap imap)
    {
        _imap = imap;
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
}
