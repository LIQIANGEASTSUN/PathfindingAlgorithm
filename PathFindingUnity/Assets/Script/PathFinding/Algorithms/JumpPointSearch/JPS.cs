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
        private Heap<Node> openHeap = new Heap<Node>(false);
        // closed 表
        private List<Node> closedList = new List<Node>();
        // 终点
        private Node desitinationNode = null;
        private JPSTool jpsTool = new JPSTool();
        private JPSPlusPreproccess jpsPlusPreproccess = new JPSPlusPreproccess();
        public JPS(IMap map)
        {
            this.map = map;
            jpsTool.SetMap(map);
            jpsPlusPreproccess.SetMap(map);
        }

        /// <summary>
        /// 预处理 Jps+
        /// 这里这是作为 Demo 使用，运行游戏后，点击预处理按钮
        /// 先把地图跳跃点搜索，如果是正式游戏使用，则需要提前预处理好地图
        /// </summary>
        public void Preprocess()
        {
            jpsPlusPreproccess.Preprocess();
        }

        public bool IsPreprocess
        {
            get { return jpsPlusPreproccess.IsPreprocess; }
        }

        public Node SearchPath(Position from, Position desitination)
        {
            if (from.ColPos == desitination.ColPos && from.RowPos == desitination.RowPos)
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

            // 起点
            Node originNode = map.PositionToNode(from.RowPos, from.ColPos);
            desitinationNode = map.PositionToNode(desitination.RowPos, desitination.ColPos);
            if ((null == originNode || null == desitinationNode))
            {
                return null;
            }

            jpsTool.SetNode(originNode, desitinationNode);
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
                if (jpsTool.IsSameNode(node, desitinationNode))
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

            int horizontalDir = jpsTool.Dir(node.Row, node.Parent.Row);
            int verticalDir = jpsTool.Dir(node.Col, node.Parent.Col);
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

        private void Search(Node currentNode, int row, int col)
        {
            Node temp = map.GetNode(row, col);
            Search(currentNode, temp);
        }

        private void Search(Node currentNode, Node temp)
        {
            if (!jpsTool.InvalidNode(temp))
            {
                return;
            }

            int horizontalDir = jpsTool.Dir(temp.Row, currentNode.Row);
            int verticalDir = jpsTool.Dir(temp.Col, currentNode.Col);
            if (jpsPlusPreproccess.IsPreprocess)
            {
                // 如果地图进行了预处理，并且 step >= 0 直接使用预处理数据
                // 如果 step < 0 则说明此方向上有边界或者障碍点，对这个点进行搜索
                int index = map.GetNodeNeighborIndex(currentNode, horizontalDir, verticalDir);
                int step = currentNode.JpsPlus[index];
                if (step >= 0)
                {
                    SearchPlus(currentNode, temp, step);
                    return;
                }
            }

            Node preNode = currentNode;
            while (true)
            {
                if (!jpsTool.InvalidNode(temp) || temp.NodeState == NodeState.InOpenTable)
                {
                    break;
                }

                if (null != jpsTool.IsJumpPoint(preNode, temp, horizontalDir, verticalDir))
                {
                    InsertToOpenHeap(temp, currentNode);
                    break;
                }

                preNode = temp;
                temp = map.GetNode(temp.Row + horizontalDir, temp.Col + verticalDir);
            }
        }

        /// <summary>
        /// JPS+ 预处理的搜索
        /// </summary>
        /// <param name="currentNode"></param>
        /// <param name="temp"></param>
        private void SearchPlus(Node currentNode, Node temp, int step)
        {
            if (!jpsTool.InvalidNode(temp) || temp.NodeState == NodeState.InOpenTable)
            {
                return;
            }

            if (step <= 0)
            {
                return;
            }

            int horizontalDir = jpsTool.Dir(temp.Row, currentNode.Row);
            int verticalDir = jpsTool.Dir(temp.Col, currentNode.Col);
            int row = currentNode.Row + horizontalDir * step;
            int col = currentNode.Col + verticalDir * step;
            temp = map.GetNode(row, col);
            InsertToOpenHeap(temp, currentNode);
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