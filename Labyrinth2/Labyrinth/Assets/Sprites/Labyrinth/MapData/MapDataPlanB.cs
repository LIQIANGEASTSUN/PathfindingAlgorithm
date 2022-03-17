using System.Collections;
using System.Collections.Generic;
using UnityEngine;

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
        for (int i = 0; i < TotalRow; ++i)
        {
            for (int j = 0; j < TotalCol; ++j)
            {
                int index = 0;
                MapCell mapCell = new MapCell(i, j);
                mapCell.value = ReacCell(i, j, ref index);
                CheckCell(mapCell);
                MapCellDic.Add(index, mapCell);
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

    private void CheckCell(MapCell mapCell)
    {
        if (mapCell.value == -1)
        {
            mapCell.flag = 0;
            return;
        }

        int row = mapCell.row;
        int col = mapCell.col;
        for (int i = 0; i < _cellDir.Length; ++i)
        {
            int[] arr = _cellDir[i];
            int newRow = row + arr[0];
            int newCol = col + arr[1];
            int value = ReadCall(row + arr[0], col + arr[1]);
            if (value == -1 || mapCell.value == value)
            {
                continue;
            }
            mapCell.flag |= (1 << i);
        }
    }
}
