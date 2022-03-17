using PathFinding;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class MapData : IMap
{
    public string _tableName = "labyrinth2";
    private MapSize _mapSize;
    private int _totalRow;
    private int _totalCol;
    protected Node[] _nodeGrid = new Node[] { };
    private Dictionary<int, int> _tableDic = new Dictionary<int, int>();

    public static int[][] _neighborArr = new int[][] {
        new int[]{ -1, 0}, // 上
        new int[]{  1, 0}, // 下
        new int[]{  0,-1}, // 左
        new int[]{  0, 1}, // 右
    };

    public MapData(string tableName)
    {
        SetTableName(tableName);
        Init();
    }

    public void SetTableName(string tableName)
    {
        _tableName = tableName;
    }

    protected void Init()
    {
        _totalRow = int.Parse(TableDatas.GetData(_tableName, "9999", "c0"));
        _totalCol = int.Parse(TableDatas.GetData(_tableName, "9999", "c1"));
        _mapSize = new MapSize(0, 0, _totalRow, _totalCol);
        AnalysisTable();
    }

    protected void AnalysisTable()
    {
        _nodeGrid = new Node[TotalRow * TotalCol];
        for (int i = 0; i < TotalRow; ++i)
        {
            for (int j = 0; j < TotalCol; ++j)
            {
                int index = 0;
                Node node = new Node(i, j, 4);
                node.Value = ReacCell(i, j, ref index);
                CheckCell(node);
                _nodeGrid[index] = node;
            }
        }
    }

    private int ReadCall(int row, int col)
    {
        int index = 0;
        return ReacCell(row, col, ref index);
    }

    private int ReacCell(int row, int col, ref int index)
    {
        if (row < 0 || row >= TotalRow || col < 0 || col >= TotalCol)
        {
            return 0;
        }
        index = CellIndex(row, col);
        int value = 0;
        if (!_tableDic.TryGetValue(index, out value))
        {
            string content = ReadCellValue(row, col);
            value = int.Parse(content);
            _tableDic.Add(index, value);
        }
        return value;
    }

    private void CheckCell(Node node)
    {
        int row = node.Row;
        int col = node.Col;
        for (int i = 0; i < _neighborArr.Length; ++i)
        {
            int[] arr = _neighborArr[i];
            int newRow = row + arr[0];
            int newCol = col + arr[1];
            int value = ReadCall(row + arr[0], col + arr[1]);
            if (node.Value == -1)
            {
                if (value == 0)
                {
                    node.Flag |= (1 << i);
                }
            }
            else
            {
                if (value == -1 || node.Value == value)
                {
                    continue;
                }
                node.Flag |= (1 << i);
            }
        }
    }

    protected string ReadCellValue(int row, int col)
    {
        string colName = string.Format("c{0}", col);
        return TableDatas.GetData(_tableName, row.ToString(), colName);
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

    public Position NodeToTilePosition(Node node)
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
