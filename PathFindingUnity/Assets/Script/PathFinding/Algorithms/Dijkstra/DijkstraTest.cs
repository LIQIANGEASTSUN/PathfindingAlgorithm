using PathFinding;
using System.Collections.Generic;
using UnityEngine;

public class DijkstraTest : MonoBehaviour
{
    //  地图，此例子使用的是矩形网格地图
    private IMap _imap;
    private Dijkstra dijkstra;
    
    private void Start()
    {
        // 获取地图数据
        _imap = QuadMapCreate.CreateQuad("Terrain6", 0, 0, 10, 20);
        // 初始化 算法，并将地图数据传递进去
        dijkstra = new Dijkstra(_imap);

        CreatePerson();
        new MapToolsDrawNode(_imap);
    }

    private Stack<Position> _stackPos = new Stack<Position>();
    /// <summary>
    /// 搜索路径
    /// </summary>
    private void StartSearchPath()
    {
        DestroyGO();

        // 获取开始位置、终点位置
        Position from = new Position(personGo.transform.position.z, personGo.transform.position.x);
        Position to = new Position(destination.transform.position.z, destination.transform.position.x);

        // 搜索路径，如果返回结果为 null，则说明没有找到路径，否则说明已找到路径，且 pathNode 为终点节点
        // 顺着 pathNode 一直向上查找 parentNode，最终将到达开始点
        Node pathNode = dijkstra.SearchPath(from, to);

        //需要通过 pathNode 逆序向上查找 parentNode
        //所以使用 栈：FILO 先进后出,存放路径点
        _stackPos.Clear();
        while (null != pathNode)
        {
            Position pos = _imap.NodeToPosition(pathNode);
            // 数据入栈
            _stackPos.Push(pos);
            pathNode = pathNode.Parent;
        }

        // 顺次执行 _stackPos.Peek(); 将 路点从 栈中取出即是从 开始点到结束点的路径
    }

    private void Move()
    {
        if (_stackPos.Count <= 0)
        {
            return;
        }

        Position position = _stackPos.Peek();
        Vector3 destinationPos = new Vector3(position.ColPos, 0.3f, position.RowPos);
        Vector3 dir = destinationPos - personGo.transform.position;
        personGo.transform.Translate(dir.normalized * speed * Time.deltaTime, Space.World);
        if (Vector3.Distance(personGo.transform.position, destinationPos) > 0.05f)
        {
            return;
        }

        // 到达一个节点，将路径点移除
        _stackPos.Pop();
        CreatePathPos();
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

    private void DestroyGO()
    {
        for (int i = pathGoList.Count - 1; i >= 0; --i)
        {
            GameObject.Destroy(pathGoList[i]);
        }
        pathGoList.Clear();
    }

    /// <summary>
    /// 创建走过的节点
    /// </summary>
    private void CreatePathPos()
    {
        GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        go.transform.localScale = Vector3.one * 0.2f;
        go.transform.position = new Vector3(personGo.transform.position.x, 0.6f, personGo.transform.position.z);
        go.GetComponent<Renderer>().material.color = Color.red;
        pathGoList.Add(go);
    }

    /// <summary>
    /// 创建加入到 OpenList 表的节点
    /// </summary>
    /// <returns></returns>
    private bool CreateOpenList()
    {
        if (insertOpenList.Count <= 0)
        {
            return false;
        }
        Node node = insertOpenList[0];
        insertOpenList.RemoveAt(0);

        Position pos = _imap.NodeToPosition(node);
        GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        go.transform.localScale = Vector3.one * 0.2f;
        go.transform.position = new Vector3(pos.ColPos + 0.1f, 0.6f, pos.RowPos + 0.1f);
        go.GetComponent<Renderer>().material.color = Color.blue;
        pathGoList.Add(go);

        return true;
    }

    private GameObject personGo;
    private GameObject destination;
    private void CreatePerson()
    {
        // 角色出发点
        personGo = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        personGo.name = "Person";
        personGo.transform.position = new Vector3(10.5f, 0.3f, 4.2f);
        personGo.GetComponent<Renderer>().material.color = Color.green;

        // 目标终点
        destination = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        destination.name = "Destination";
        destination.transform.position = new Vector3(4.5f, 0.3f, 4.2f);
        destination.GetComponent<Renderer>().material.color = Color.black;
    }
    #endregion
}
