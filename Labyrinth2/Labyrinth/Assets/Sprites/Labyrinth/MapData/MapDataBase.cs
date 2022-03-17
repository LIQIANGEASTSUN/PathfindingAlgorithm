using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MapCell
{
    public int row;
    public int col;
    public int value;
    public int flag;

    public MapCell(int row, int col)
    {
        this.row = row;
        this.col = col;
    }
}

public abstract class MapDataBase
{
    public string _tableName = "labyrinth2";
    private int _totalRow = 0;
    private int _totalCol = 0;
    private Dictionary<int, MapCell> _mapCellDic = new Dictionary<int, MapCell>();

    protected int[][] _cellDir = new int[][] {
        new int[]{ -1, 0}, // 上
        new int[]{  1, 0}, // 下
        new int[]{  0,-1}, // 左
        new int[]{  0, 1}, // 右
    };

    public MapDataBase(string tableName)
    {
        SetTableName(tableName);
        Init();
    }

    public void SetTableName(string tableName)
    {
        _tableName = tableName;
    }

    protected virtual void Init()
    {
        string path = Application.streamingAssetsPath;
        TableRead.Instance.ReadCustomPath(path);

        _totalRow = int.Parse(TableRead.Instance.GetData(_tableName, 9999, "c0"));
        _totalCol = int.Parse(TableRead.Instance.GetData(_tableName, 9999, "c1"));
    }

    protected abstract void AnalysisTable();

    protected string ReadCellValue(int row, int col)
    {
        string colName = string.Format("c{0}", col);
        return TableRead.Instance.GetData(_tableName, row, colName);
    }

    protected int CellIndex(int row, int col)
    {
        return row * TotalCol + col;
    }

    protected string WallHash(int row, int col)
    {
        string hash = string.Format("{0}_{1}", row, col);
        return hash;
    }

    public int TotalRow
    {
        get
        {
            return _totalRow;
        }
    }

    public int TotalCol
    {
        get
        {
            return _totalCol;
        }
    }

    public Dictionary<int, MapCell> MapCellDic
    {
        get
        {
            return _mapCellDic;
        }
    }
}
