using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LabyrinthData : MonoBehaviour
{
    public static LabyrinthData Instance;
    public const string tableName = "labyrinth2";
    private int[][] grid = new int[][] { };

    private int _totalRow = 0;
    private int _totalCol = 0;
    private HashSet<string> _wallHash = new HashSet<string>();
    private Dictionary<int, MapCell> _mapCellDic = new Dictionary<int, MapCell>();

    void Awake()
    {
        Instance = this;
        string path = Application.streamingAssetsPath;
        TableRead.Instance.ReadCustomPath(path);

        _totalRow = int.Parse(TableRead.Instance.GetData(tableName, 9999, "c0"));
        _totalCol = int.Parse(TableRead.Instance.GetData(tableName, 9999, "c1"));

        ReadWall();
        CreateMapCell();
    }

    private void ReadWall()
    {
        for (int i = 0; i < _totalRow; ++i)
        {
            for (int j = 0; j < _totalCol; ++j)
            {
                if ((i % 2 == 0 && j % 2 == 0)
                    || (i % 2 == 1 && j % 2 == 1))
                {
                    continue;
                }

                string colName = string.Format("c{0}", j);
                string wallStr = TableRead.Instance.GetData(tableName, i, colName);
                if (!string.IsNullOrEmpty(wallStr))
                {
                    string hash = WallHash(i, j);
                    _wallHash.Add(hash);
                }
            }
        }
    }

    private string WallHash(int row, int col)
    {
        string hash = string.Format("{0}_{1}", row, col);
        return hash;
    }

    private void CreateMapCell()
    {
        for (int i = 0; i < _totalRow; ++i)
        {
            for (int j = 0; j < _totalCol; ++j)
            {
                MapCell mapCell = new MapCell() { row = i, col = j };
                int index = i * _totalCol + j;
                CheckCell(mapCell);
                _mapCellDic.Add(index, mapCell);
            }
        }
    }

    private int[][] dir = new int[][] {
        new int[]{ -1, 0}, // 上
        new int[]{  1, 0}, // 下
        new int[]{  0,-1}, // 左
        new int[]{  0, 1}, // 右
    };
    private void CheckCell(MapCell mapCell)
    {
        int row = mapCell.row * 2 + 1;
        int col = mapCell.col * 2 + 1;

        for (int i = 0; i < dir.Length; ++i)
        {
            int[] arr = dir[i];
            string hash = WallHash(row + arr[0], col + arr[1]);
            if (_wallHash.Contains(hash))
            {
                mapCell.flag |= (1 << i);
            }
        }
    }

    public int TotalRow
    {
        get {
            return _totalRow;
        }
    }

    public int TotalCol
    {
        get {
            return _totalCol;
        }
    }

    public Dictionary<int, MapCell> MapCellDic
    {
        get {
            return _mapCellDic;
        }
    }

    public int[][] Grid
    {
        get { return grid; }
    }
}

public class MapCell
{
    public int row;
    public int col;
    public int flag;
}
