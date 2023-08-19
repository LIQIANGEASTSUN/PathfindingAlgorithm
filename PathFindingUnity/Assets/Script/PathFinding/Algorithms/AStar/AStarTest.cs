using PathFinding;
using System.Collections.Generic;
using UnityEngine;

public class AStarTest : MonoBehaviour
{
    public MapType mapType = MapType.Quad;
    private IMap imap;

    // 算法
    private AStar _aStar;

    private void Start()
    {
        CreateMap();
        // 获取地图数据
        // 初始化 算法，并将地图数据传递进去
        _aStar = new AStar(imap);
    }

    private void CreateMap()
    {
        if (mapType == MapType.Quad)
        {
            CreateMapQuad();
        }
        else if (mapType == MapType.Hex)
        {
            CreateHexMap();
        }
    }

    private void CreateMapQuad()
    {
        // 地图，此例子使用的是矩形网格地图
        imap = new MapQuad("Terrain6", 0, 0, 20, 10);
    }

    private void CreateHexMap()
    {
        float minX = 10;
        float minY = 10;
        float maxX = 30;
        float maxY = 30;
        float radius = 1;
        imap = new MapHex(minX, minY, maxX, maxY, radius);
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
        Node pathNode = _aStar.SearchPath(from, to);

        //需要通过 pathNode 逆序向上查找 parentNode
        //所以使用 栈：FILO 先进后出,存放路径点
        _stackPos.Clear();
        while (null != pathNode)
        {
            Position pos = imap.NodeToPosition(pathNode);
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
    private void Update()
    {
        DebugUse();

        imap.Update();
    }

    private GameObject personGo;
    private GameObject destination;
    private float _intervalTime = 0.3f;
    private float _insertTime = 0.1f;
    private float speed = 3;
    private bool _init = false;
    private List<GameObject> pathGoList = new List<GameObject>();
    public static List<KeyValuePair<int, Node>> checkNodeList = new List<KeyValuePair<int, Node>>();
    private void DebugUse()
    {
        if (!_init)
        {
            _init = true;
            // 将地图数据路点创建出来，为了看到路点
            new MapToolsDrawNode(imap);
            CreatePerson();
        }

        _insertTime -= Time.deltaTime;
        if (checkNodeList.Count > 0 && _insertTime <= 0)
        {
            _insertTime = 0.06f;

            KeyValuePair<int, Node> kv = checkNodeList[0];

            Node node = kv.Value;
            checkNodeList.RemoveAt(0);

            Position pos = imap.NodeToPosition(node);
            GameObject go = GameObject.CreatePrimitive(PrimitiveType.Capsule);
            go.transform.position = (kv.Key == 1) ? new Vector3(pos.X + 0.1f, 0f, pos.Y + 0.1f) : new Vector3(pos.X - 0.1f, 0f, pos.Y - 0.1f);
            go.transform.localScale = Vector3.one * 0.3f;
            go.name = (kv.Key == 1) ? string.Format("open:{0}_{1}", node.Row, node.Col) : string.Format("insertOpen:{0}_{1}", node.Row, node.Col);
            go.GetComponent<Renderer>().material.color = (kv.Key == 1) ? Color.green : Color.blue;

            pathGoList.Add(go);
        }
        if (checkNodeList.Count > 0)
        {
            return;
        }

        if (_stackPos.Count > 0)
        {
            Position position = _stackPos.Peek();
            Vector3 destinationPos = new Vector3(position.X, 0.13f, position.Y);
            Vector3 dir = destinationPos - personGo.transform.position;
            personGo.transform.Translate(dir.normalized * speed * Time.deltaTime, Space.World);
            if (Vector3.Distance(personGo.transform.position, destinationPos) <= 0.05f)
            {
                _stackPos.Pop();
            }

            _intervalTime -= Time.deltaTime;
            if (_intervalTime <= 0)
            {
                _intervalTime = 0.06f;
                GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
                go.transform.localScale = Vector3.one * 0.2f;
                go.transform.position = new Vector3(personGo.transform.position.x, 0.1f, personGo.transform.position.z);
                go.GetComponent<Renderer>().material.color = Color.red;
                pathGoList.Add(go);
            }
        }
    }

    private Vector3 persionPos = new Vector3(10.5f, 0.1f, 4.2f);
    private Vector3 desitinationPos = new Vector3(4.5f, 0.1f, 4.2f);
    private void CreatePerson()
    {
        personGo = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        personGo.name = "Person";
        personGo.transform.position = persionPos;
        personGo.GetComponent<Renderer>().material.color = Color.green;

        destination = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        destination.name = "Destination";
        destination.transform.position = desitinationPos;
        destination.GetComponent<Renderer>().material.color = Color.black;
    }
    #endregion
}
