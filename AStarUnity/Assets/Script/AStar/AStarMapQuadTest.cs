using AStar;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AStarMapQuadTest : MonoBehaviour
{
    private MapQuad _mapQuad;
    private AStar.AStar aStar;
    private Node pathNode;

    private void Start()
    {
        Test();
    }

    private void Update()
    {
        //DrawMapQuad(_mapQuad);
    }

    public void Test()
    {
        _mapQuad = new MapQuad(-10, -10, 10, 10, 1, 1);
        _mapQuad.CreateGrid();

        aStar = new AStar.AStar();
        aStar.SetMap(_mapQuad);

        Position from = new Position(-5, -5);
        Position to = new Position(5, 5);

        GameObject fromGo = GameObject.CreatePrimitive(PrimitiveType.Cube);
        fromGo.transform.position = new Vector3(from.X, 0, from.Y);

        GameObject toGo = GameObject.CreatePrimitive(PrimitiveType.Cube);
        toGo.transform.position = new Vector3(to.X, 0, to.Y);

        pathNode = aStar.SearchPath(from, to);

        while (null != pathNode)
        {
            Debug.Log(pathNode.Row + "    " + pathNode.Col);
            pathNode = pathNode.Parent;
        }
    }

    private void OnDrawGizmos()
    {
        DrawMapQuad(_mapQuad);
    }

    private void DrawMapQuad(MapQuad mapQuad)
    {
        if (null == mapQuad)
        {
            return;
        }
        Node[] nodeArr = mapQuad.Grid();

        for (int i = 0; i < nodeArr.Length; ++i)
        {
            Node node = nodeArr[i];
            Position pos = mapQuad.NodeToPosition(node);

            Gizmos.DrawWireCube(new Vector3(pos.X, 0, pos.Y), new Vector3(mapQuad.NodeWidth(), 0, mapQuad.NodeLength()));
        }
    }

}
