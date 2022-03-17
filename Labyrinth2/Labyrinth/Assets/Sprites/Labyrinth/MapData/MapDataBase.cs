using PathFinding;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public abstract class MapDataBase : IMap
{
    public string _tableName = "labyrinth2";
    private MapSize _mapSize;
    private int _totalRow;
    private int _totalCol;
    protected Node[] _nodeGrid = new Node[] { };

    public static int[][] _neighborArr = new int[][] {
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
        _mapSize = new MapSize(0, 0, _totalRow, _totalCol);
    }

    protected abstract void AnalysisTable();

    protected string ReadCellValue(int row, int col)
    {
        string colName = string.Format("c{0}", col);
        return TableRead.Instance.GetData(_tableName, row, colName);
    }

    public int CellIndex(int row, int col)
    {
        return row * _mapSize._maxY + col;
    }

    public int TotalRow
    {
        get { return _totalRow; }
        set { _totalRow = value; }
    }

    public int TotalCol
    {
        get { return _totalCol; }
        set { _totalCol = value; }
    }

    public Node[] Grid()
    {
        return _nodeGrid;
    }

    public MapSize MapSize()
    {
        return _mapSize;
    }

    /// <summary>
    /// 根据坐标获取 Node
    /// </summary>
    public Node PositionToNode(float x, float y)
    {
        return PositionToNode((int)x, (int)y);
    }

    /// <summary>
    /// 根据坐标获取 Node
    /// </summary>
    public Node PositionToNode(int x, int y)
    {
        int index = CellIndex(x, y);
        return _nodeGrid[index];
    }

    /// <summary>
    /// 根据 Node 获取坐标
    /// </summary>
    public Position NodeToPosition(Node node)
    {
        Position position = new Position(node.Col, node.Row * -1);
        return position;
    }

    /// <summary>
    /// 获取 Node 的第 index 个邻居
    /// </summary>
    public Node NodeNeighbor(Node node, int index, ref float distance)
    {
        int row = node.Row + _neighborArr[index][0];
        int col = node.Col + _neighborArr[index][1];
        Node temp = GetNode(row, col);
        if (null != temp)
        {
            distance = (float)Math.Sqrt(Math.Abs(_neighborArr[index][0]) + Math.Abs(_neighborArr[index][1]));
        }
        return temp;
    }

    public Node NodeNeighbor(Node node, int index)
    {
        int row = node.Row + _neighborArr[index][0];
        int col = node.Col + _neighborArr[index][1];
        Node temp = GetNode(row, col);
        return temp;
    }

    public Node GetNode(int row, int col)
    {
        if (row < 0 || row >= TotalRow || col < 0 || col >= TotalCol)
        {
            return null;
        }

        int index = CellIndex(row, col);
        return _nodeGrid[index];
    }
}
