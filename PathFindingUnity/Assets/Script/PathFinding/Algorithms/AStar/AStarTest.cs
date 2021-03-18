using PathFinding;
using System.Collections.Generic;
using UnityEngine;

public class AStarTest : MonoBehaviour
{
    // 地图
    private MapQuad _mapQuad;
    // 算法
    private AStar _aStar;

    private void Start()
    {
        // 获取地图数据
        _mapQuad = new MapQuad("Terrain1", 0, 0, 20, 10);

        _aStar = new AStar(_mapQuad);
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
        Node pathNode = _aStar.SearchPath(from, to);

        // 栈：FILO 先进后出,存放路径点
        _stackPos.Clear();
        while (null != pathNode)
        {
            Position pos = _mapQuad.NodeToPosition(pathNode);
            // 数据入栈
            _stackPos.Push(pos);
            pathNode = pathNode.Parent;
        }

        // 顺次执行 _stackPos.Peek(); 将 路点从 栈中取出即是从 开始点到结束点的路径
    }

    private void Update()
    {
        DebugUse();
    }

    private void OnGUI()
    {
        if (GUI.Button(new Rect(10, 10, 200, 50), "Start"))
        {
            StartSearchPath();
        }
    }

    #region Debug
    private GameObject personGo;
    private GameObject destination;
    private float _intervalTime = 0.1f;
    private float speed = 3;
    private bool _init = false;
    private List<GameObject> pathGoList = new List<GameObject>();
    private void DebugUse()
    {
        if (!_init)
        {
            _init = true;
            // 将地图数据路点创建出来，为了看到路点
            new MapToolsDrawNode(_mapQuad);
            CreatePerson();
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
    #endregion
}
