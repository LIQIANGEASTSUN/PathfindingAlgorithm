using PathFinding;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PathFind
{
    private AStar _aStar;
    List<Node> list = new List<Node>();

    public PathFind()
    {
        _aStar = new AStar();
    }

    public void Init()
    {
        RegisterEvent();
    }

    public void Update()
    {
        ShowPath();
    }

    public void Find()
    {
        Node resultNode = _aStar.SearchPath(2, 0, 7, 12);
        while (null != resultNode)
        {
            list.Add(resultNode);
            resultNode = resultNode.Parent;
        }
    }

    public void Clear()
    {
        for (int i = goList.Count - 1; i >= 0; --i)
        {
            GameObject.Destroy(goList[i]);
        }
        goList.Clear();
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

        Vector2 position = GameServer.GetInstance().MapProxy.NodeToPosition(node);
        GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        go.transform.localScale = Vector3.one * 0.5f;
        go.transform.localPosition = position;
        go.GetComponent<Renderer>().material.color = Color.green;
        goList.Add(go);
    }

    public void Release()
    {
        Clear();
        UnRegisterEvent();
    }

    private void RegisterEvent()
    {
        GameNotifycation.GetInstance().AddEventListener(ENUM_MSG_TYPE.MSG_PATH_FIND, Find);
    }

    private void UnRegisterEvent()
    {
        GameNotifycation.GetInstance().RemoveEventListener(ENUM_MSG_TYPE.MSG_PATH_FIND, Find);
    }

}
