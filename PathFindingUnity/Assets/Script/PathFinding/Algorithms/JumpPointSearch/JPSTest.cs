using System.Collections.Generic;
using UnityEngine;
using PathFinding;

public class JPSTest : MonoBehaviour
{
    private MapQuad _mapQuad;
    private JPS _jps;
    private void Start()
    {
        // 获取地图数据
        _mapQuad = new MapQuad("Terrain6", 0, 0, 20, 10);
        // 初始化 算法，并将地图数据传递进去
        _jps = new JPS(_mapQuad);
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
        Node pathNode = _jps.SearchPath(from, to);

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




    #region DebugUse
    private float _intervalTime = 0;
    private GameObject personGo;
    private GameObject destination;
    private float speed = 3;
    private List<GameObject> pathGoList = new List<GameObject>();
    private bool _init = false;
    public static List<KeyValuePair<int, Node>> checkNodeList = new List<KeyValuePair<int, Node>>();
    private float _checkTime = 0.3f;
    private void Update()
    {
        if (!_init)
        {
            _init = true;
            new MapToolsDrawNode(_mapQuad);
            CreatePerson();
        }

        _checkTime -= Time.deltaTime;
        if (checkNodeList.Count > 0 && _checkTime <= 0)
        {
            _checkTime = 0.3f;
            KeyValuePair<int, Node> kv = checkNodeList[0];
            checkNodeList.RemoveAt(0);

            Node node = kv.Value;
            Position pos = _mapQuad.NodeToPosition(node);
            GameObject go = GameObject.CreatePrimitive(PrimitiveType.Capsule);
            go.transform.position = (kv.Key == 1) ? new Vector3(pos.X + 0.1f, 1f, pos.Y + 0.1f) : new Vector3(pos.X - 0.1f, 1f, pos.Y - 0.1f);
            go.transform.localScale = Vector3.one * 0.3f;
            go.name = (kv.Key == 1) ? string.Format("open:{0}_{1}", node.Row, node.Col) : string.Format("insertOpen:{0}_{1}", node.Row, node.Col);
            go.GetComponent<Renderer>().material.color = (kv.Key == 1) ? Color.green : Color.blue;
        }

        if (checkNodeList.Count > 0)
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

    private Vector3 persionPos = new Vector3(2.5f, 0.3f, 3.85f);
    private Vector3 desitinationPos = new Vector3(10.5f, 0.3f, 4f);
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
