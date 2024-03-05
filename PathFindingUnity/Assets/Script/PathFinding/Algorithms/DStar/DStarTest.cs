using System.Collections.Generic;
using UnityEngine;
using PathFinding;

public class DStarTest : MonoBehaviour
{
    //  地图，此例子使用的是矩形网格地图
    private MapQuad _mapQuad;
    private DStar dStar;

    // 寻路找到的路径节点
    private Node pathNode;

    private void Start()
    {
        // 获取地图数据
        _mapQuad = new MapQuad("Terrain6", 0, 0, 20, 10);
        // 初始化 算法，并将地图数据传递进去
        dStar = new DStar(_mapQuad);

        // D* 寻路，小跟堆需要使用 节点的 K 值排序
        Node.compareUseK = true;
        new MapToolsDrawNode(_mapQuad);

        CreatePerson();
    }

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

        // 搜索路径，如果返回结果为 null，则说明没有找到路径，否则说明已找到路径，且 pathNode 为(from)起点
        // 顺着 pathNode 一直向上查找 parentNode，最终将到达(to)终点 
        pathNode = dStar.SearchPath(from, to);

        SetObstacle();
    }

    // 将可行走的节点改变成不可行走的障碍
    private void SetObstacle()
    {
        List<int[]> list = new List<int[]>()
        {
            new int[]{11, 10},
            new int[]{12, 10},
            new int[]{13, 10},
            new int[]{4, 10},
            new int[]{3, 10},
            new int[]{4, 8},
            new int[]{3, 8},
        };
        // 将一些可行走节点改成障碍物
        foreach (var data in list)
        {
            Node node = _mapQuad.GetNode(data[0], data[1]);
            node.NodeType = NodeType.Obstacle;
        }
    }

    /// <summary>
    /// 开始按照路径行走
    /// </summary>
    private void Move()
    {
        if (null == pathNode)
        {
            return;
        }

        Position position = _mapQuad.NodeToPosition(pathNode);
        Vector3 destinationPos = new Vector3(position.X, 0.3f, position.Y);
        Vector3 dir = destinationPos - personGo.transform.position;
        personGo.transform.Translate(dir.normalized * speed * Time.deltaTime, Space.World);

        // 判断是否到达一个节点
        if (Vector3.Distance(personGo.transform.position, destinationPos) > 0.05f)
        {
            return;
        }
        CreatePathPos();

        Node currentNode = pathNode;
        // 到达节点了，更新下一个节点
        pathNode = pathNode.Parent;
        if (null == pathNode)
        {
            return;
        }

        // _queueNode 中的节点是寻路得到的节点，原本都是可行走的
        // 如果下一个可行走的节点变成障碍物了，则在节点 node 周围重新计算新路径
        if (pathNode.NodeType != NodeType.Obstacle)
        {
            return;
        }

        // 从 currentNode 节点，重新寻路
        if (dStar.ReSearch(currentNode, pathNode))
        {
            pathNode = currentNode; // 继续从 currentNode 节点开始行走
        }
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
        //if (CreateOpenList())
        //{
        //    return;
        //}
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