using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MapDataPlanA : MapDataBase
{
    private HashSet<string> _wallHash = new HashSet<string>();

    public MapDataPlanA(string tableName) : base(tableName)
    {

    }

    protected override void Init()
    {
        base.Init();
        AnalysisTable();
        CreateMapCell();
    }

    protected override void AnalysisTable()
    {
        for (int i = 0; i < TotalRow * 2 + 1; ++i)
        {
            for (int j = 0; j < TotalCol * 2 + 1; ++j)
            {
                if ((i % 2 == 0 && j % 2 == 0)
                    || (i % 2 == 1 && j % 2 == 1))
                {
                    continue;
                }

                string colName = string.Format("c{0}", j);
                string wallStr = TableRead.Instance.GetData(_tableName, i, colName);
                if (!string.IsNullOrEmpty(wallStr))
                {
                    string hash = WallHash(i, j);
                    _wallHash.Add(hash);
                }
            }
        }
    }

    protected override void CreateMapCell()
    {
        for (int i = 0; i < TotalRow; ++i)
        {
            for (int j = 0; j < TotalCol; ++j)
            {
                MapCell mapCell = new MapCell() { row = i, col = j };
                int index = i * TotalCol + j;
                CheckCell(mapCell);
                MapCellDic.Add(index, mapCell);
            }
        }
    }

    private void CheckCell(MapCell mapCell)
    {
        int row = mapCell.row * 2 + 1;
        int col = mapCell.col * 2 + 1;

        for (int i = 0; i < _cellDir.Length; ++i)
        {
            int[] arr = _cellDir[i];
            string hash = WallHash(row + arr[0], col + arr[1]);
            if (_wallHash.Contains(hash))
            {
                mapCell.flag |= (1 << i);
            }
        }
    }
}
