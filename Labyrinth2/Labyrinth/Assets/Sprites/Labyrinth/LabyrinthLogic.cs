using System.Collections.Generic;

public class Node
{
    public Node parent;
    public int index;
    public Node(int index)
    {
        this.index = index;
    }
    public Node(int index, Node parent)
    {
        this.index = index;
        this.parent = parent;
    }
}

// 寻路算法逻辑实现方式
public enum SearchType
{
    /// <summary>
    /// 递归实现
    /// </summary>
    RECURSION = 1,

    /// <summary>
    /// 迭代实现
    /// </summary>
    ITERATION = 2,
}

public class LabyrinthLogic
{
    private int _entryRow = 0;
    private int _entryCol = 0;
    public int _exitRow = 12;
    public int _exitCol = 9;

    private HashSet<int> hash = new HashSet<int>();
    private List<List<int>> resultList = new List<List<int>>();

    private MapDataBase _mapDataBase;
    public LabyrinthLogic(MapDataBase mapDataBase)
    {
        _mapDataBase = mapDataBase;
    }

    public List<List<int>> ResultList
    {
        get { return resultList; }
    }

    public bool FindPath(int entryRow, int entryCol, SearchType type)
    {
        _entryRow = entryRow;
        _entryCol = entryCol;
        hash.Clear();
        resultList.Clear();

        if (type == SearchType.RECURSION)
        {
            dfs(_mapDataBase.TotalRow, _entryRow, _entryCol, new List<int>());
        }
        else if (type == SearchType.ITERATION)
        {
            dfs(_mapDataBase.TotalRow, _entryRow, _entryCol);
        }
        return resultList.Count > 0;
    }

    #region 递归实现
    // 递归实现
    private void dfs(int totalRow, int row, int col, List<int> list)
    {
        if (IsExit(row, col))
        {
            // 找到出口了，保存路径
            resultList.Add(new List<int>(list));
            return;
        }

        // 节点的上下左右节点中搜索
        for (int i = 0; i < MapDataBase._cellDir.Length; ++i)
        {
            int newRow = row + MapDataBase._cellDir[i][0];
            int newCol = col + MapDataBase._cellDir[i][1];
            int index = newRow * totalRow + newCol;
            // 剪枝函数
            // 已经搜索过的节点不重复添加(避免死循环)
            // 障碍物节点不能通过
            if (hash.Contains(index) || !Valid(row, col, newRow, newCol))
            {
                continue;
            }
            // 记录已经搜索过的节点
            hash.Add(index);
            // 将可以通过的节点保存
            list.Add(index);
            dfs(totalRow, newRow, newCol, list);
            // 回溯
            list.RemoveAt(list.Count - 1);
        }
    }
    #endregion

    #region 迭代实现
    private void dfs(int totalRow, int row, int col)
    {
        int index = row * totalRow + col;
        Node node = new Node(index);
        Stack<Node> stack = new Stack<Node>();
        stack.Push(node);
        while (stack.Count > 0)
        {
            node = stack.Pop();
            index = node.index;
            row = index / totalRow;
            col = index % totalRow;
            if (IsExit(row, col))
            {
                List<int> list = new List<int>();
                while (null != node)
                {
                    list.Insert(0, node.index);
                    node = node.parent;
                }
                resultList.Add(list);
                continue;
            }

            for (int i = MapDataBase._cellDir.Length - 1; i >= 0; --i)
            {
                int newRow = row + MapDataBase._cellDir[i][0];
                int newCol = col + MapDataBase._cellDir[i][1];
                index = newRow * totalRow + newCol;
                if (hash.Contains(index) || !Valid(row, col, newRow, newCol))
                {
                    continue;
                }
                // 子节点设置父节点
                Node childNode = new Node(index, node);
                hash.Add(index);
                stack.Push(childNode);
            }
        }
    }
    #endregion

    // 是否有效节点，在地图范围内且节点值为0 的为有效节点
    private bool Valid(int row, int col, int nextRow, int nextCol)
    {
        if (IsOutRange(row, col) || IsOutRange(nextRow, nextCol))
        {
            return false;
        }
        return row >= 0 && row < n && col >= 0 && col < n && _grid[row][col] == 0;
    }

    private bool IsOutRange(int row, int col)
    {
        return row < 0 || row >= _mapDataBase.TotalRow || col < 0 || col >= _mapDataBase.TotalCol;
    }

    // 是否出口
    private bool IsExit(int row, int col)
    {
        return _exitRow== row && _exitCol == col;
    }

    // 是否入口
    private bool IsEntry(int row, int col)
    {
        return (row == _entryRow && col == _entryCol);
    }
}