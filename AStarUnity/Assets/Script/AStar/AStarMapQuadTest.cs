using AStar;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AStarMapQuadTest : MonoBehaviour
{
    private MapQuad _mapQuad;
    private AStar.AStar aStar;

    private GameObject personGo;
    private GameObject destination;
    private float speed = 3;

    private List<GameObject> pathGoList = new List<GameObject>();
    private void Start()
    {
        _mapQuad = new MapQuad("Terrain1", 0, 0, 20, 10);
        _mapQuad.CreateGrid();
        new AStarMapQuadDrawPath(_mapQuad);

        aStar = new AStar.AStar();
        aStar.SetMap(_mapQuad);

        CreatePerson();
    }

    private float _intervalTime = 0.1f;
    private void Update()
    {
        if (_stackPos.Count > 0)
        {
            Position position = _stackPos.Peek();
            Vector3 destinationPos = new Vector3(position.X, 0.3f, position.Y);
            Vector3 dir = destinationPos - personGo.transform.position;
            personGo.transform.Translate(dir.normalized * speed * Time.deltaTime, Space.World);
            if (Vector3.Distance(personGo.transform.position, destinationPos) <= 0.05f)
            {
                _stackPos.Pop();
            }

            _intervalTime -= Time.deltaTime;
            if (_intervalTime <= 0)
            {
                _intervalTime = 0.1f;
                GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
                go.transform.localScale = Vector3.one * 0.2f;
                go.transform.position = new Vector3(personGo.transform.position.x, 0.6f, personGo.transform.position.z);
                go.GetComponent<Renderer>().material.color = Color.red;
                pathGoList.Add(go);
            }
        }
    }

    private void OnGUI()
    {
        if (GUI.Button(new Rect(10, 10, 200, 50), "Start"))
        {
            StartSearchPath();
        }
    }

    private Stack<Position> _stackPos = new Stack<Position>();
    private void StartSearchPath()
    {
        for (int i = pathGoList.Count - 1; i >= 0; --i)
        {
            GameObject.Destroy(pathGoList[i]);
        }
        pathGoList.Clear();

        Position from = new Position(personGo.transform.position.x, personGo.transform.position.z);
        Position to = new Position(destination.transform.position.x, destination.transform.position.z);
        Node pathNode = aStar.SearchPath(from, to);

        _stackPos.Clear();
        int count = 0;
        while (null != pathNode)
        {
            ++count;
            Position pos = _mapQuad.NodeToPosition(pathNode);
            _stackPos.Push(pos);
            if (count > 200)
            {
                break;
            }
            pathNode = pathNode.Parent;
        }
    }

    private void CreatePerson()
    {
        personGo = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        personGo.name = "Person";
        personGo.transform.position = new Vector3(19.5f, 0.3f, 6.5f);
        personGo.GetComponent<Renderer>().material.color = Color.green;

        destination = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        destination.name = "Destination";
        destination.transform.position = new Vector3(2.5f, 0.3f, 2.5f);
        destination.GetComponent<Renderer>().material.color = Color.black;
    }
}


public class AStarMapQuadDrawPath
{
    public AStarMapQuadDrawPath(MapQuad mapQuad)
    {
        CreateNode(mapQuad);
    }

    public void CreateNode(MapQuad mapQuad)
    {
        GameObject parent = new GameObject("NodeParent");
        parent.transform.position = Vector3.zero;
        Node[] nodeArr = mapQuad.Grid();
        for (int i = 0; i < nodeArr.Length; ++i)
        {
            Node node = nodeArr[i];
            if (node.NodeType == NodeType.Null)
            {
                continue;
            }
            Position pos = mapQuad.NodeToPosition(node);
            GameObject go = GameObject.CreatePrimitive(PrimitiveType.Cube);
            go.name = string.Format("{0}_{1}", node.Row, node.Col);
            go.transform.position = new Vector3(pos.X, 0, pos.Y);
            go.transform.localScale = new Vector3(mapQuad.NodeWidth(), 1, mapQuad.NodeLength()) * 0.9f;
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
