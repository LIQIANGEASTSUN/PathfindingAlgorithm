using System.Collections.Generic;
using UnityEngine;
using PathFinding;

public class DStarTest : MonoBehaviour
{
    //  地图，此例子使用的是矩形网格地图
    private MapQuad _mapQuad;
    private DStar dStar;

    private void Start()
    {
        // 获取地图数据
        _mapQuad = new MapQuad("Terrain6", 0, 0, 20, 10);
        // 初始化 算法，并将地图数据传递进去
        dStar = new DStar(_mapQuad);

        Node.compareUseK = true;

        CreatePerson();
        new MapToolsDrawNode(_mapQuad);
    }

    private Queue<Node> _queuePos = new Queue<Node>();
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
        Node pathNode = dStar.SearchPath(from, to);

        //需要通过 pathNode 逆序向上查找 parentNode
        //所以使用 栈：FILO 先进后出,存放路径点
        _queuePos.Clear();
        while (null != pathNode)
        {
            // 数据入栈
            _queuePos.Enqueue(pathNode);
            pathNode = pathNode.Parent;
        }

        List<int[]> list = new List<int[]>()
        {
            new int[]{11, 10},
            new int[]{12, 10},
            new int[]{13, 10},
        };
        // 将一些可行走节点改成障碍物
        //foreach(var data in list)
        //{
        //    Node node = _mapQuad.GetNode(data[0], data[1]);
        //    node.NodeType = NodeType.Obstacle;
        //    dStar.MODIFY_COST(node, 100000);
        //}

        // 顺次执行 _stackPos.Peek(); 将 路点从 栈中取出即是从 开始点到结束点的路径
    }

    private void OnGUI()
    {
        GUI.skin.button.fontSize = 40;
        if (GUI.Button(new Rect(10, 10, 200, 80), "Start"))
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
    private void Update()
    {
        if (CreateOpenList())
        {
            return;
        }

        Move();
    }

    // 创建加入到 OpenList 的节点
    private bool CreateOpenList()
    {
        while (insertOpenList.Count > 0)
        {
            Node node = insertOpenList[0];
            insertOpenList.RemoveAt(0);

            Position pos = _mapQuad.NodeToPosition(node);
            GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            go.transform.localScale = Vector3.one * 0.2f;
            go.transform.position = new Vector3(pos.X + 0.1f, 0.6f, pos.Y + 0.1f);
            go.GetComponent<Renderer>().material.color = Color.blue;
            pathGoList.Add(go);
            return true;
        }
        return insertOpenList.Count > 0;
    }

    // 创建走过的节点
    private void CreatePathPos()
    {
        GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        go.transform.localScale = Vector3.one * 0.2f;
        go.transform.position = new Vector3(personGo.transform.position.x, 0.6f, personGo.transform.position.z);
        go.GetComponent<Renderer>().material.color = Color.red;
        pathGoList.Add(go);
    }

    /// <summary>
    /// 开始按照路径行走
    /// </summary>
    private void Move()
    {
        if (_queuePos.Count <= 0)
        {
            return;
        }

        Node node = _queuePos.Peek();
        Position position = _mapQuad.NodeToPosition(node);
        Vector3 destinationPos = new Vector3(position.X, 0.3f, position.Y);
        Vector3 dir = destinationPos - personGo.transform.position;
        personGo.transform.Translate(dir.normalized * speed * Time.deltaTime, Space.World);

        // 判断是否到达一个节点
        if (Vector3.Distance(personGo.transform.position, destinationPos) > 0.05f)
        {
            return;
        }
        CreatePathPos();

        // 到达节点了，将节点移除
        node = _queuePos.Dequeue();
        if (_queuePos.Count <= 0)
        {
            return;
        }

        Node next = _queuePos.Peek();
        // 如果下一个可行走的节点变成障碍物了，则在节点 node 周围重新计算新路径
        if (next.NodeType != NodeType.Obstacle)
        {
            return;
        }

        bool result = dStar.ReSearch(node, next);
        if (result)
        {
            _queuePos.Clear();
            while (null != node)
            {
                _queuePos.Enqueue(node);
                node = node.Parent;
            }
        }
    }

    private void CreatePerson()
    {
        personGo = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        personGo.name = "Person";
        personGo.transform.position = new Vector3(10.5f, 0.3f, 4.2f);
        personGo.GetComponent<Renderer>().material.color = Color.green;

        destination = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        destination.name = "Destination";
        destination.transform.position = new Vector3(4.5f, 0.3f, 4.2f);
        destination.GetComponent<Renderer>().material.color = Color.black;
    }
    #endregion
}
