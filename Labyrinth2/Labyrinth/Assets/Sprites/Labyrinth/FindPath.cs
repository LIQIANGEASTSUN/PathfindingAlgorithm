using System.Collections.Generic;
using UnityEngine;

public class FindPath : MonoBehaviour
{
    private LabyrinthLogic labyrinthLogic;
    List<int> list = new List<int>();
    public void Start()
    {
        labyrinthLogic = new LabyrinthLogic();
    }

    public void Update()
    {
        ShowPath();
    }

    private string msg;
    private void OnGUI()
    {
        if(GUI.Button(new Rect(10, 10, 100, 60), "寻路:递归实现"))
        {
            Find(SearchType.RECURSION);
            SetPathData();
        }

        if (GUI.Button(new Rect(10, 100, 100, 60), "寻路:迭代实现"))
        {
            Find(SearchType.ITERATION);
            SetPathData();
        }

        if (labyrinthLogic.ResultList.Count > 0)
        {
            if (GUI.Button(new Rect(10, 200, 100, 60), msg))
            {
                SetPathData();
            }
        }
    }

    private void Find(SearchType type)
    {
        //LabyrinthData.Instance.ResetGrid();
        //labyrinthLogic.FindPath(LabyrinthData.Instance.Grid, 4, 0, type);
    }

    private float interval = 0.06f;
    private float lastTime;
    private List<GameObject> goList = new List<GameObject>();
    private void ShowPath()
    {
        //interval -= Time.deltaTime;
        //if (interval >= 0)
        //{
        //    return;
        //}
        //interval = 0.06f;

        //if (list.Count <= 0)
        //{
        //    return;
        //}

        //int n = LabyrinthData.Instance.Grid.Length;
        //int index = list[0];
        //list.RemoveAt(0);

        //int row = index / n;
        //int col = index % n;
        //Vector3 pos = new Vector3(row, 1, col);
        //GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        //go.transform.localScale = Vector3.one * 0.5f;
        //go.transform.localPosition = pos;
        //go.GetComponent<Renderer>().material.color = Color.green;
        //goList.Add(go);
    }

    private void SetPathData()
    {
        if (labyrinthLogic.ResultList.Count > 0)
        {
            list = labyrinthLogic.ResultList[0];
            labyrinthLogic.ResultList.RemoveAt(0);
        }
        for (int i = goList.Count - 1; i >= 0; --i)
        {
            GameObject.Destroy(goList[i]);
        }
        goList.Clear();
        msg = string.Format("还有{0}条路径\n展示下一条路径", labyrinthLogic.ResultList.Count);
    }
}
