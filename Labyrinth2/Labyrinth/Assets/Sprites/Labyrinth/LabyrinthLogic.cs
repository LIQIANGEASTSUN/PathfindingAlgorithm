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
    private int[][] _grid;
    private int _entryRow = 0;
    private int _entryCol = 0;
    private HashSet<int> hash = new HashSet<int>();
    private List<List<int>> resultList = new List<List<int>>();
    int[][] dir = new int[][] {
        new int[]{-1, 0}, // 上
        new int[]{ 1, 0}, // 下
        new int[]{ 0,-1}, // 左
        new int[]{ 0, 1}  // 右
    };

    public List<List<int>> ResultList
    {
        get { return resultList; }
    }

    public bool FindPath(int[][] grid, int entryRow, int entryCol, SearchType type)
    {
        _grid = grid;
        _entryRow = entryRow;
        _entryCol = entryCol;
        hash.Clear();
        resultList.Clear();

        if (type == SearchType.RECURSION)
        {
            dfs(_grid.Length, _entryRow, _entryCol, new List<int>());
        }
        else if (type == SearchType.ITERATION)
        {
            dfs(_grid.Length, _entryRow, _entryCol);
        }
        return resultList.Count > 0;
    }

    #region 递归实现
    // 递归实现
    private void dfs(int n, int row, int col, List<int> list)
    {
        if (IsExit(row, col, n))
        {
            // 找到出口了，保存路径
            resultList.Add(new List<int>(list));
            return;
        }

        // 节点的上下左右节点中搜索
        for (int i = 0; i < dir.Length; ++i)
        {
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            int index = newRow * n + newCol;
            // 剪枝函数
            // 已经搜索过的节点不重复添加(避免死循环)
            // 障碍物节点不能通过
            if (hash.Contains(index) || !Valid(newRow, newCol, n))
            {
                continue;
            }
            // 记录已经搜索过的节点
            hash.Add(index);
            // 将可以通过的节点保存
            list.Add(index);
            dfs(n, newRow, newCol, list);
            // 回溯
            list.RemoveAt(list.Count - 1);
        }
    }
    #endregion

    #region 迭代实现
    private void dfs(int n, int row, int col)
    {
        int index = row * n + col;
        Node node = new Node(index);
        Stack<Node> stack = new Stack<Node>();
        stack.Push(node);
        while (stack.Count > 0)
        {
            node = stack.Pop();
            index = node.index;
            row = index / n;
            col = index % n;
            if (IsExit(row, col, n))
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

            for (int i = dir.Length - 1; i >= 0; --i)
            {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                index = newRow * n + newCol;
                if (!Valid(newRow, newCol, n) || hash.Contains(index))
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
    private bool Valid(int row, int col, int n)
    {
        return row >= 0 && row < n && col >= 0 && col < n && _grid[row][col] == 0;
    }

    // 是否出口
    private bool IsExit(int row, int col, int n)
    {
        return !IsEntry(row, col) && (row <= 0 || row >= n - 1 || col <= 0 || col >= n - 1);
    }

    // 是否入口
    private bool IsEntry(int row, int col)
    {
        return (row == _entryRow && col == _entryCol);
    }
}