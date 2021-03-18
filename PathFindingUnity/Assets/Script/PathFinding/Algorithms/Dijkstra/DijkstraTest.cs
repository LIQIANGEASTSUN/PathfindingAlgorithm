using PathFinding;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DijkstraTest : MonoBehaviour
{
    //  地图，此例子使用的是矩形网格地图
    private MapQuad _mapQuad;
    private Dijkstra dijkstra;
    
    private void Start()
    {
        // 获取地图数据
        _mapQuad = new MapQuad("Terrain2", 0, 0, 20, 10);
        // 初始化 算法，并将地图数据传递进去
        dijkstra = new Dijkstra(_mapQuad);
    }

    private Stack<Position> _stackPos = new Stack<Position>();
    private void StartSearchPath()
    {
        for (int i = pathGoList.Count - 1; i >= 0; --i)
        {
            GameObject.Destroy(pathGoList[i]);
        }
        pathGoList.Clear();

        // 获取开始位置、终点位置
        Position from = new Position(personGo.transform.position.x, personGo.transform.position.z);
        Position to = new Position(destination.transform.position.x, destination.transform.position.z);

        // 搜索路径，如果返回结果为 null，则说明没有找到路径，否则说明已找到路径，且 pathNode 为终点节点
        // 顺着 pathNode 一直向上查找 parentNode，最终将到达开始点
        Node pathNode = dijkstra.SearchPath(from, to);

        //需要通过 pathNode 逆序向上查找 parentNode
        //所以使用 栈：FILO 先进后出,存放路径点
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
    private float speed = 3;
    public static List<Node> insertOpenList = new List<Node>();
    private List<GameObject> pathGoList = new List<GameObject>();
    private float _intervalTime = 0.1f;
    private float _insertTime = 0.02f;
    private bool _isInit = false;
    private void Update()
    {
        if (!_isInit)
        {
            _isInit = true;
            CreatePerson();
            new MapToolsDrawNode(_mapQuad);
        }

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
