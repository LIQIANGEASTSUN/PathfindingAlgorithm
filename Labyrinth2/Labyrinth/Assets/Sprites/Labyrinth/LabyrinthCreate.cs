using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Text;

public class LabyrinthCreate : MonoBehaviour
{
    public static LabyrinthCreate Instance;
    void Start()
    {
        Instance = this;
        Create();
    }

    public GameObject green;
    public GameObject red;
    private void Create()
    {
        int[][] grid = LabyrinthData.Instance.Grid;
        for (int i = 0; i < grid.Length; ++i)
        {
            int[] row = grid[i];
            for (int j = 0; j < row.Length; ++j)
            {
                Vector3 pos = new Vector3(i, 0, j);
                GameObject go;
                if (row[j] == 1)
                {
                    go = GameObject.Instantiate(red);
                }
                else
                {
                    go = GameObject.Instantiate(green);
                }
                go.transform.localScale = Vector3.one * 0.9f;
                go.transform.localPosition = pos;
                go.transform.SetParent(transform);
                go.transform.SetAsLastSibling();
            }
        }
    }
}
