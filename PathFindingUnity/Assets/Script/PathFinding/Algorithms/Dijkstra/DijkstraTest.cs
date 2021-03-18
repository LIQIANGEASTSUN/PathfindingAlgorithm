using PathFinding;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DijkstraTest : MonoBehaviour
{
    private MapQuad _mapQuad;
    private Dijkstra dijkstra;

    private GameObject personGo;
    private GameObject destination;
    private float speed = 3;

    public static List<Node> insertOpenList = new List<Node>();

    private List<GameObject> pathGoList = new List<GameObject>();
    private void Start()
    {
        _mapQuad = new MapQuad("Terrain2", 0, 0, 20, 10);
        new MapToolsDrawNode(_mapQuad);

        dijkstra = new Dijkstra();
        dijkstra.SetMap(_mapQuad);

        CreatePerson();
    }

    private float _intervalTime = 0.1f;
    private float _insertTime = 0.02f;
    private void Update()
    {
        _insertTime -= Time.deltaTime;
        if (insertOpenList.Count > 0 && _insertTime <= 0)
        {
            _insertTime = 0.02f;

            Node node = insertOpenList[0];
            insertOpenList.RemoveAt(0);

            Position pos = _mapQuad.NodeToPosition(node);
            GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            go.transform.localScale = Vector3.one * 0.2f;
            go.transform.position = new Vector3(pos.X + 0.1f, 0.6f, pos.Y + 0.1f);
            go.GetComponent<Renderer>().material.color = Color.blue;
            pathGoList.Add(go);
        }
        if (insertOpenList.Count > 0)
        {
            return;
        }

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
        Node pathNode = dijkstra.SearchPath(from, to);

        // 栈：FILO 先进后出,存放路径点
        _stackPos.Clear();
        while (null != pathNode)
        {
            Position pos = _mapQuad.NodeToPosition(pathNode);
            // 数据入栈
            _stackPos.Push(pos);
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
