using System.Collections.Generic;
using UnityEngine;
using PathFinding;

public class FindPath
{
    private IMap _imap;
    private AStar _aStar;
    List<Node> list = new List<Node>();

    public FindPath(IMap map, AStar aStar)
    {
        _imap = map;
        _aStar = aStar;
    }

    public void Update()
    {
        ShowPath();
    }

    private string msg;
    public void OnGUI()
    {
        if(GUI.Button(new Rect(10, 10, 100, 60), "寻路"))
        {
            Node resultNode = _aStar.SearchPath(2, 0, 12, 9);
            while (null != resultNode)
            {
                list.Add(resultNode);
                resultNode = resultNode.Parent;
            }
        }
    }

    private float interval = 0.06f;
    private float lastTime;
    private List<GameObject> goList = new List<GameObject>();
    private void ShowPath()
    {
        interval -= Time.deltaTime;
        if (interval >= 0)
        {
            return;
        }
        interval = 0.06f;

        if (list.Count <= 0)
        {
            return;
        }

        Node node = list[list.Count - 1];
        list.RemoveAt(list.Count - 1);

        Vector2 position = _imap.NodeToPosition(node);
        GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        go.transform.localScale = Vector3.one * 0.5f;
        go.transform.localPosition = position;
        go.GetComponent<Renderer>().material.color = Color.green;
        goList.Add(go);
    }
}
