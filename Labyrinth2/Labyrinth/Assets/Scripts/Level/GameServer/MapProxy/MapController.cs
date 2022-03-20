using PathFinding;
using UnityEngine;

/// <summary>
/// 地图格子类型
/// </summary>
public enum MapGridType
{
    // 入口
    Entry = 1,
    // 出口
    Exit = 2,
}

public class MapController : IMapProxy
{
    private IMap _imap;
    private Vector2Int _entryGrid;
    private Vector2Int _exitGrid;

    private const string _tableLevelName = "level";

    public MapController(IMap imap)
    {
        _imap = imap;
    }

    public void Init()
    {
        AnalysisTable();
    }

    public IMap IMap()
    {
        return _imap;
    }

    public Node NodeNeighbor(Node node, int index)
    {
        return _imap.NodeNeighbor(node, index);
    }

    public Vector2 NodeToPosition(Node node)
    {
        return _imap.NodeToPosition(node);
    }

    public Node PositionToNode(float x, float y)
    {
        return _imap.PositionToNode(x, y);
    }

    public Node EntryNode()
    {
        return _imap.GetNode(_entryGrid.x, _entryGrid.y);
    }

    public Node ExitNode()
    {
        return _imap.GetNode(_exitGrid.x, _exitGrid.y);
    }

    private void AnalysisTable()
    {
        int levelId = GameServer.GetInstance().LevelProxy.LevelId();
        string mapConfig = TableDatas.GetData(_tableLevelName, levelId.ToString(), "MapConfig");
        string roleCount = TableDatas.GetData(mapConfig, "9999", "ruleCount");
        string[] rowCol = roleCount.Split(',');
        int totalRow = int.Parse(rowCol[0]);
        int totalCol = int.Parse(rowCol[1]);

        for (int r = 0; r < totalRow; r++)
        {
            for (int c = 0; c < totalCol; c++)
            {
                string gridField = string.Format("grid{0}", c);
                string grid = TableDatas.GetData(mapConfig, r.ToString(), gridField);
                string[] gridSplit = grid.Split(',');
                int row = int.Parse(gridSplit[0]);
                int col = int.Parse(gridSplit[1]);

                string gridTypeField = string.Format("gridType{0}", c);
                int gridType = int.Parse(TableDatas.GetData(mapConfig, r.ToString(), gridTypeField));

                CheckNode(row, col, gridType);
            }
        }
    }

    private void CheckNode(int row, int col, int gridType)
    {
        if (gridType == (int)MapGridType.Entry)
        {
            _entryGrid = new Vector2Int(row, col);
        }
        if (gridType == (int)MapGridType.Exit)
        {
            _exitGrid = new Vector2Int(row, col);
        }
    }

    public void Release()
    {
        
    }
}
