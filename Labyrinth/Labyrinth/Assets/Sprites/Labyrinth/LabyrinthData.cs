using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LabyrinthData : MonoBehaviour
{
    public static LabyrinthData Instance;
    public const string tableName = "labyrinth";
    private int[][] grid;
    void Awake()
    {
        Instance = this;
        string path = Application.streamingAssetsPath;
        TableRead.Instance.ReadCustomPath(path);

        ResetGrid();
    }

    public void ResetGrid()
    {
        List<int> keyList = TableRead.Instance.GetKeyList(tableName);
        grid = new int[keyList.Count][];
        for (int i = 0; i < keyList.Count; ++i)
        {
            int id = keyList[i];
            int[] row = new int[20];
            for (int j = 0; j < 20; ++j)
            {
                string colName = string.Format("c{0}", j);
                int value = int.Parse(TableRead.Instance.GetData(tableName, id, colName));
                row[j] = value;
            }
            grid[i] = row;
        }
    }

    public int[][] Grid
    {
        get { return grid; }
    }
}
