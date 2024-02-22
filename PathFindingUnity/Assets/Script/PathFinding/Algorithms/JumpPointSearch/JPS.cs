using DataStruct.Heap;
using System;
using System.Collections.Generic;

namespace PathFinding
{
    // Jump Point Search 算法
    public class JPS
    {
        // 地图数据
        private IMap map;
        // 小根堆保存开放节点，目的在于提高获取最小F值点效率
        private Heap<Node> openHeap;
        // closed 表
        private List<Node> closedList;

        // 起点
        private Node originNode = null;
        // 终点
        private Node desitinationNode = null;

        public JPS(IMap map)
        {
            openHeap = new Heap<Node>();
            openHeap.SetHeapType(false);
            closedList = new List<Node>();
            this.map = map;
        }

        public Node SearchPath(Position from, Position desitination)
        {
            if (from.X == desitination.X && from.Y == desitination.Y)
            {
                return null;
            }

            // 重置上次访问过的节点
            foreach (var node in closedList)
            {
                node.Clear();
            }
            foreach (var node in openHeap.DataList)
            {
                node.Clear();
            }
            openHeap.MakeEmpty();
            closedList.Clear();

            originNode = map.PositionToNode(from.X, from.Y);
            desitinationNode = map.PositionToNode(desitination.X, desitination.Y);
            if ((null == originNode || null == desitinationNode))
            {
                return null;
            }

            originNode.NodeState = NodeState.InOpenTable;
            // 将起点加入到 open 表
            openHeap.Insert(originNode);
            while (openHeap.Count() > 0)
            {
                // 取出 open 表中 F 值最小的节点
                Node node = openHeap.DelRoot();
                // 将 node 添加到 closed 表
                node.NodeState = NodeState.InColsedTable;
                closedList.Add(node);

                AddTestCheck(node);
                // 如果 node 是终点 则路径查找成功，并退出
                if (node.Row == desitinationNode.Row && node.Col == desitinationNode.Col)
                {
                    return node;
                }
                CheckNode(node);
            }

            return null;
        }

        private void CheckNode(Node node)
        {
            if (null == node.Parent)
            {
                // 搜索 上下左右 四 个方向
                for (int i = 1; i < node.neighborCount; i += 2)
                {
                    Node temp = map.NodeNeighbor(node, i);
                    Search(node, temp);
                }
                // 搜索斜向 四 个方向
                for (int i = 0; i < node.neighborCount; i += 2)
                {
                    Node temp = map.NodeNeighbor(node, i);
                    Search(node, temp);
                }
                return;
            }

            int horizontalDir = Dir(node.Row, node.Parent.Row);
            int verticalDir = Dir(node.Col, node.Parent.Col);
            if (horizontalDir != 0)
            {
                Search(node, node.Row + horizontalDir, node.Col);
            }
            if (verticalDir != 0)
            {
                Search(node, node.Row, node.Col + verticalDir);
            }

            if (horizontalDir != 0 && verticalDir != 0)
            {
                Search(node, node.Row + horizontalDir, node.Col + verticalDir);
            }

            foreach(var forceNeighbour in node.ForceNeighbourList)
            {
                Search(node, forceNeighbour);
            }
        }

        /// <summary>
        /// 节点是否有强制邻居
        /// </summary>
        private bool HasForceNeighbour(Node preNode, Node node)
        {
            if (null == preNode || null == node)
            {
                return false;
            }

            Position dir = new Position(Dir(node.Row, preNode.Row), Dir(node.Col, preNode.Col));
            return JPSTool.HasForceNeighbour(map, node, dir);
        }

        private void Search(Node currentNode, int row, int col)
        {
            Node temp = map.GetNode(row, col);
            Search(currentNode, temp);
        }

        private void Search(Node currentNode, Node temp)
        {
            if (!InvalidNode(temp) || temp.NodeType == NodeType.Null || temp.NodeType == NodeType.Obstacle)
            {
                return;
            }

            int horizontalDir = Dir(temp.Row, currentNode.Row);
            int verticalDir = Dir(temp.Col, currentNode.Col);
            Node preNode = currentNode;
            while (true)
            {
                if (null == temp || temp.NodeState == NodeState.InColsedTable || temp.NodeState == NodeState.InOpenTable
                    || temp.NodeType == NodeType.Null || temp.NodeType == NodeType.Obstacle)
                {
                    break;
                }

                if (null != IsJumpPoint(preNode, temp, horizontalDir, verticalDir))
                {
                    InsertToOpenHeap(temp, currentNode);
                    break;
                }

                preNode = temp;
                temp = map.GetNode(temp.Row + horizontalDir, temp.Col + verticalDir);
            }
        }

        private void InsertToOpenHeap(Node jumpNode, Node currentNode)
        {
            // 设置 neighborNode.G 值 = 从 起点 到 neighborNode 的总 G
            float G = currentNode.G + Distance(currentNode, jumpNode);
            // 使用 曼哈顿 方法计算 H 值，即(neighborNode 到 终点的 Row、Col 偏移量绝对值之和)
            float H = Offset(jumpNode, desitinationNode);
            float F = H + G;
            // 在 open 表中
            if (jumpNode.NodeState == NodeState.InOpenTable)
            {
                // 比较 jumpNode 记录的 F 值是否比 从 currentNode 到 neighborNode 的 F 值更大
                // 如果 jumpNode.F 更大，则更新 jumpNode.F 并设置 neighborNode.Parent = currentNode;
                if (jumpNode.F > F)
                {
                    jumpNode.G = G;
                    jumpNode.H = H;
                    // 设置父节点
                    jumpNode.Parent = currentNode;
                    // 改变了 G 值，小根堆需要重排序
                    openHeap.HeapCreate();
                }
            }
            else
            {
                jumpNode.G = G;
                jumpNode.H = H;
                // 设置父节点
                jumpNode.Parent = currentNode;
                jumpNode.NodeState = NodeState.InOpenTable;
                openHeap.Insert(jumpNode);
                AddTestInsertOpen(jumpNode);
            }
        }

        /// <summary>
        /// 节点是否跳跃点
        /// </summary>
        private Node IsJumpPoint(Node preNode, Node node, int rowDir, int colDir)
        {
            if (!InvalidNode(node) || node.NodeType == NodeType.Null || node.NodeType == NodeType.Obstacle)
            {
                return null;
            }

            //一： 如果 node 是起点/终点,则 node 是跳点
            if (IsSameNode(node, originNode) || IsSameNode(node, desitinationNode))
            {
                return node;
            }

            //二： 如果 node 至少有一个强迫邻居,则 node 是跳点
            if (HasForceNeighbour(preNode, node))
            {
                return node;
            }

            if (rowDir == 0 || colDir == 0)
            {
                return null;
            }

            // 如果父节点在斜方向上(意味着这是斜向搜索)
            // 节点 node 的水平或者垂直方向上有满足条件 一、二的点,则节点也是跳跃点
            Node jumpNode = JumpSearchHV(node, rowDir, 0);
            if (null != jumpNode)
            {
                return jumpNode;
            }
            jumpNode = JumpSearchHV(node, 0, colDir);
            return jumpNode;
        }

        /// <summary>
        /// 横向、竖向 跳跃搜索
        /// rowDir 和 colDir 必须有且只有一个为 0
        /// </summary>
        private Node JumpSearchHV(Node node, int rowDir, int colDir)
        {
            if (rowDir != 0 && colDir != 0)
            {
                return null;
            }
            int row = node.Row;
            int col = node.Col;
            while (true)
            {
                row += rowDir;
                col += colDir;
                Node temp = map.GetNode(row, col);
                if (null == temp || temp.NodeType == NodeType.Null || temp.NodeType == NodeType.Obstacle)
                {
                    break;
                }

                if (null != IsJumpPoint(node, temp, rowDir, colDir))
                {
                    return temp;
                }
            }

            return null;
        }

        /// <summary>
        /// 判断相同节点
        /// </summary>
        private bool IsSameNode(Node left, Node right)
        {
            if (null == left || null == right)
            {
                return false;
            }
            return left.Row == right.Row && left.Col == right.Col;
        }

        private int Offset(Node n1, Node n2)
        {
            return Math.Abs(n1.Row - n2.Row) + Math.Abs(n1.Col - n2.Col);
        }

        private float Distance(Node n1, Node n2)
        {
            int r = n1.Row - n2.Row;
            int c = n1.Col - n2.Col;
            return (float)Math.Sqrt(r * r + c * c);
        }

        /// <summary>
        /// 搜索方向
        /// </summary>
        private int Dir(int v1, int v2)
        {
            int value = v1 - v2;
            if (value > 0)
            {
                return 1;
            }
            else if (value == 0)
            {
                return 0;
            }
            return -1;
        }

        private bool InvalidNode(Node node)
        {
            if (null == node || node.NodeState == NodeState.InColsedTable)
            {
                return false;
            }
            return true;
        }

        // 测试时使用
        private void AddTestCheck(Node node)
        {
            //string name = string.Format("open:{0}_{1}", node.Row, node.Col);
            //Debug.LogError(name);
            KeyValuePair<int, Node> kv = new KeyValuePair<int, Node>(1, node);
            JPSTest.checkNodeList.Add(kv);
        }

        // 测试时使用
        private void AddTestInsertOpen(Node node)
        {
            //string name = string.Format("insertOpen:{0}_{1}", node.Row, node.Col);
            //Debug.LogError(name);
            KeyValuePair<int, Node> kv = new KeyValuePair<int, Node>(0, node);
            JPSTest.checkNodeList.Add(kv);
        }
    }
}