using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using PathFinding;

public class MapDataPlanB : MapDataBase
{
    private Dictionary<int, int> _tableDic = new Dictionary<int, int>();

    public MapDataPlanB(string tableName) : base(tableName)
    {

    }

    protected override void Init()
    {
        base.Init();
        AnalysisTable();
    }

    protected override void AnalysisTable()
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
}
