using DataStruct.Heap;
using System;
using System.Collections.Generic;
using UnityEngine;

namespace PathFinding
{
    // Jump Point Search 算法
    public class JPS
    {
        // 地图数据
        private IMap _map;
        // 小根堆保存开放节点，目的在于提高获取最小F值点效率
        private Heap<Node> openHeap;
        // closed 表
        private List<Node> closedList;

        public JPS(IMap map)
        {
            openHeap = new Heap<Node>();
            openHeap.SetHeapType(false);
            closedList = new List<Node>();
            _map = map;
        }

        public Node SearchPath(Position from, Position desitination)
        {
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
            Node originNode = _map.PositionToNode(from.X, from.Y);
            // 终点
            Node desitinationNode = _map.PositionToNode(desitination.X, desitination.Y);
            if (originNode.Row == desitinationNode.Row && originNode.Col == desitinationNode.Col)
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

                Check(node);

                // 如果 node 是终点 则路径查找成功，并退出
                if (node.Row == desitinationNode.Row && node.Col == desitinationNode.Col)
                {
                    return node;
                }

                CheckNode(originNode, desitinationNode, node);
            }

            return null;
        }

        private void CheckNode(Node origin, Node desitination, Node node)
        {
            if (null == node.Parent)
            {
                // 搜索上下左右四个方向
                for (int i = 1; i < node.neighborCount; i += 2)
                {
                    Node temp = _map.NodeNeighbor(node, i);
                    SearchHV(origin, desitination, node, temp);
                }
            }
            else
            {
                int horizontalDir = Dir(node.Row, node.Parent.Row);
                int verticalDir = Dir(node.Col, node.Parent.Col);

                if (horizontalDir != 0)
                {
                    Node temp = _map.GetNode(node.Row + horizontalDir, node.Col);
                    SearchHV(origin, desitination, node, temp);
                }
                if (verticalDir != 0)
                {
                    Node temp = _map.GetNode(node.Row, node.Col + verticalDir);
                    SearchHV(origin, desitination, node, temp);
                }
            }

            if (null == node.Parent)
            {
                for (int i = 0; i < node.neighborCount; i += 2)
                {
                    Node temp = _map.NodeNeighbor(node, i);
                    SearchDiagonal(origin, desitination, node, temp);
                }
            }
            else
            {
                int horizontalDir = Dir(node.Row, node.Parent.Row);
                int verticalDir = Dir(node.Col, node.Parent.Col);
                if (horizontalDir != 0 && verticalDir != 0)
                {
                    Node temp = _map.GetNode(node.Row + horizontalDir, node.Col + verticalDir);
                    SearchDiagonal(origin, desitination, node, temp);
                }
                
                for (int i = 0; i < node.ForceNeighbourList.Count; ++i)
                {
                    Position pos = node.ForceNeighbourList[i];
                    Node forceNeighbour = _map.PositionToNode(pos.X, pos.Y);
                    SearchDiagonal(origin, desitination, node, forceNeighbour);
                }
            }
        }

        /// <summary>
        /// 节点是否使跳跃点
        /// </summary>
        private Node IsJumpPoint(Node origin, Node desitination, Node preNode, Node node, int rowDir, int colDir)
        {
            if (!InvalidNode(node) || node.NodeType == NodeType.Null || node.NodeType == NodeType.Obstacle)
            {
                return null;
            }

            //一： 如果 node 是起点/终点,则 node 是跳点
            if (IsSameNode(node, origin) || IsSameNode(node, desitination))
            {
                return node;
            }

            //二： 如果 node 至少有一个强迫邻居,则 node 是跳点
            if (HasForceNeighbour(preNode, node))
            {
                return node;
            }

            // 如果父节点在斜方向上(意味着这是斜向搜索),节点 node 的水平或者垂直方向上有满足条件 一、二的点
            if (rowDir!= 0 && colDir != 0)
            {
                return JumpSearchHV( origin, desitination, node, rowDir, colDir);
            }

            return null;
        }

        /// <summary>
        /// 节点是否有强制邻居
        /// </summary>
        public bool HasForceNeighbour(Node preNode, Node node)
        {
            if (null == preNode || null == node)
            {
                return false;
            }

            Position dir = new Position(Dir(node.Row, preNode.Row), Dir(node.Col, preNode.Col));
            return JPSTool.HasForceNeighbour(_map, node, dir);
        }

        private void SearchHV(Node origin, Node desitination, Node currentNode, Node temp)
        {
            if (!InvalidNode(temp) || temp.NodeType == NodeType.Null || temp.NodeType == NodeType.Obstacle)
            {
                return;
            }

            int horizontalDir = Dir(temp.Row, currentNode.Row);
            int verticalDir = Dir(temp.Col, currentNode.Col);
            Node jumpNode = IsJumpPoint(origin, desitination, currentNode, temp, horizontalDir, verticalDir);
            if (null != jumpNode)
            {
                if (!InvalidNode(jumpNode))
                {
                    return;
                }
                InsertToOpenHeap(jumpNode, currentNode, desitination);
            }

            jumpNode = JumpSearchHV(origin, desitination, temp, horizontalDir, verticalDir);
            if (null != jumpNode)
            {
                if (!InvalidNode(jumpNode))
                {
                    return;
                }
                InsertToOpenHeap(jumpNode, currentNode, desitination);
            }
        }

        private void SearchDiagonal(Node origin, Node desitination, Node currentNode, Node temp)
        {
            if (null == temp)
            {
                return;
            }
            int horizontalDir = Dir(temp.Row, currentNode.Row);
            int verticalDir = Dir(temp.Col, currentNode.Col);
            Node preNode = currentNode;
            while (true)
            {
                if (null == temp || temp.NodeState == NodeState.InColsedTable || temp.NodeState == NodeState.InOpenTable)
                {
                    break;
                }

                if (null != IsJumpPoint(origin, desitination, preNode, temp, horizontalDir, verticalDir))
                {
                    InsertToOpenHeap(temp, currentNode, desitination);
                    break;
                }

                if (temp.NodeType == NodeType.Null || temp.NodeType == NodeType.Obstacle)
                {
                    break;
                }

                preNode = temp;
                temp = _map.GetNode(temp.Row + horizontalDir, temp.Col + verticalDir);
            }
        }

        private void InsertToOpenHeap(Node jumpNode, Node currentNode, Node desitination)
        {
            jumpNode.Parent = currentNode;
            jumpNode.G = currentNode.G + Distance(currentNode, jumpNode);
            jumpNode.H = Offset(jumpNode, desitination);
            jumpNode.NodeState = NodeState.InOpenTable;
            openHeap.Insert(jumpNode);
            InsertOpen(jumpNode);
        }

        /// <summary>
        /// 横向、竖向 跳跃搜索
        /// </summary>
        private Node JumpSearchHV(Node origin, Node desitination, Node node, int rowDir, int colDir)
        {
            int i = node.Row;
            while(rowDir != 0)
            {
                i += rowDir;
                Node temp = _map.GetNode(i, node.Col);
                if (null == temp || temp.NodeType == NodeType.Null || temp.NodeType == NodeType.Obstacle)
                {
                    break;
                }

                if (null != IsJumpPoint(origin, desitination, node, temp, rowDir, 0))
                {
                    return temp;
                }
            }

            i = node.Col;
            while (colDir != 0)
            {
                i += colDir;
                Node temp = _map.GetNode(node.Row, i);
                if (null == temp || temp.NodeType == NodeType.Null || temp.NodeType == NodeType.Obstacle)
                {
                    break;
                }

                if (null != IsJumpPoint(origin, desitination, node, temp, 0, colDir))
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

        private bool IsNeighbour(Node n1, Node n2)
        {
            return Math.Abs(n1.Row - n2.Row) <= 1 && Math.Abs(n1.Col - n2.Col) <= 1;
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
            if (null == node || node.NodeState == NodeState.InColsedTable || node.NodeState == NodeState.InOpenTable)
            {
                return false;
            }
            return true;
        }

        private void Check(Node node)
        {
            //string name = string.Format("open:{0}_{1}", node.Row, node.Col);
            //Debug.LogError(name);
            KeyValuePair<int, Node> kv = new KeyValuePair<int, Node>(1, node);
            JPSTest.checkNodeList.Add(kv);
        }

        private void InsertOpen(Node node)
        {
            //string name = string.Format("insertOpen:{0}_{1}", node.Row, node.Col);
            //Debug.LogError(name);
            KeyValuePair<int, Node> kv = new KeyValuePair<int, Node>(0, node);
            JPSTest.checkNodeList.Add(kv);
        }
    }
}