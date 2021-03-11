using AStar;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AStarMapQuadTest : MonoBehaviour
{
    private MapTerrainData _mapTerrainData;
    private MapQuad _mapQuad;
    private AStar.AStar aStar;
    private Node pathNode;
    private GameObject personGo;
    private GameObject destination;
    private float speed = 2;

    private AStarMapQuadDrawPath aStarMapQuadDrawPath = new AStarMapQuadDrawPath();

    private void Start()
    {
        _mapQuad = new MapQuad("Terrain1", 0, 0, 20, 10);
        _mapQuad.CreateGrid();
        aStarMapQuadDrawPath.CreateNode(_mapQuad);

        aStar = new AStar.AStar();
        aStar.SetMap(_mapQuad);

        CreatePerson();
    }

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.A))
        {
            StartSearchPath();
        }

        while (_stackPos.Count > 0)
        {
            Position position = _stackPos.Peek();

            Vector3 dir = new Vector3(position.X, 0, position.Y) - personGo.transform.position;
            personGo.transform.Translate(dir.normalized * speed, Space.World);
        }

    }

    private Stack<Position> _stackPos = new Stack<Position>();
    private void StartSearchPath()
    {
        Position from = new Position(personGo.transform.position.x, personGo.transform.position.z);
        Position to = new Position(destination.transform.position.x, destination.transform.position.z);
        pathNode = aStar.SearchPath(from, to);

        _stackPos.Clear();
        while (null != pathNode)
        {
            Position pos = _mapQuad.NodeToPosition(pathNode);
            _stackPos.Push(pos);
            //Debug.Log(pathNode.Row + "    " + pathNode.Col);
            pathNode = pathNode.Parent;
        }
    }

    private void CreatePerson()
    {
        personGo = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        personGo.name = "Person";
        personGo.transform.position = new Vector3(2.5f, 0.3f, 5.5f);
        personGo.GetComponent<Renderer>().material.color = Color.green;

        destination = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        destination.name = "Destination";
        destination.transform.position = new Vector3(6.5f, 0.3f, 2.5f);
        destination.GetComponent<Renderer>().material.color = Color.black;
    }
}


public class AStarMapQuadDrawPath
{
    public AStarMapQuadDrawPath()
    {

    }

    public void CreateNode(MapQuad _mapQuad)
    {
        GameObject parent = new GameObject("NodeParent");
        parent.transform.position = Vector3.zero;
        Node[] nodeArr = _mapQuad.Grid();
        for (int i = 0; i < nodeArr.Length; ++i)
        {
            Node node = nodeArr[i];
            Position pos = _mapQuad.NodeToPosition(node);
            GameObject go = GameObject.CreatePrimitive(PrimitiveType.Cube);
            go.name = string.Format("{0}_{1}", node.Row, node.Col);
            go.transform.position = new Vector3(pos.X, 0, pos.Y);
            go.transform.localScale = new Vector3(_mapQuad.NodeWidth(), 1, _mapQuad.NodeLength()) * 0.9f;
            go.transform.SetParent(parent.transform);

            go.GetComponent<Renderer>().material.color = NodeColor(node.NodeType);
        }
    }

    private Color NodeColor(NodeType nodeType)
    {
        if (nodeType == NodeType.Null)
        {
            return Color.black;
        }

        if (nodeType == NodeType.Smooth)
        {
            return new Color32(230, 230, 230, 255);
        }

        if (nodeType == NodeType.Mud)
        {
            return new Color32(139, 123, 115, 255);
        }

        if (nodeType == NodeType.Grass)
        {
            return new Color32(169, 208, 142, 255);
        }

        if (nodeType == NodeType.Desert)
        {
            return new Color32(255, 230, 153, 255);
        }

        if (nodeType == NodeType.Obstacle)
        {
            return new Color32(198, 89, 17, 255);
        }

        return Color.white;
    }
}
