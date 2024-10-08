﻿using DataStruct.Heap;
using System;
using System.Collections.Generic;

namespace PathFinding
{
    // A* 寻路算法
    public class AStar
    {
        // 地图数据
        private IMap _map;

        // 小根堆保存开放节点，目的在于提高获取最小F值点效率
        private Heap<Node> openHeap = new Heap<Node>(false);
        // closed 表
        private List<Node> closedList = new List<Node>();

        public AStar(IMap map)
        {
            _map = map;
        }

        public Node SearchPath(Position from, Position desitination)
        {
            // 起点
            Node fromNode = _map.PositionToNode(from.RowPos, from.ColPos);
            // 终点
            Node desitinationNode = _map.PositionToNode(desitination.RowPos, desitination.ColPos);
            if (fromNode.Row == desitinationNode.Row && fromNode.Col == desitinationNode.Col)
            {
                return null;
            }

            fromNode.NodeState = NodeState.InOpenTable;
            // 将起点加入到 open 表
            openHeap.Insert(fromNode);

            Node result = null;
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
                    result = node;
                    break;
                }

                Neighbor(node, desitinationNode);
            }

            return result;
        }

        private void Clear()
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
        }

        /// <summary>
        /// 获取 currentNode 所有的相邻节点加入到 open 表
        /// </summary>
        private void Neighbor(Node currentNode, Node desitinationNode)
        {
            // 遍历获取 currentNode 所有相邻节点
            for (int i = 0; i < currentNode.neighborCount; ++i)
            {
                float distance = 0;
                Node neighborNode = _map.NodeNeighborWithDistance(currentNode, i, ref distance);
                InsertToOpenHeap(neighborNode, currentNode, desitinationNode, distance);
            }
        }

        /// <summary>
        /// 将 neighborNode 加入到 open 表
        /// </summary>
        private void InsertToOpenHeap(Node neighborNode, Node currentNode, Node desitinationNode, float distance)
        {
            // 空、不可通过节点不做处理
            if (null == neighborNode || neighborNode.NodeType == NodeType.Obstacle || neighborNode.NodeType == NodeType.Null)
            {
                return;
            }

            // 已经加入到 closed 表的 node 不做处理
            if (neighborNode.NodeState == NodeState.InColsedTable)
            {
                return;
            }

            // 在 open 表中
            if (neighborNode.NodeState == NodeState.InOpenTable)
            {
                // 比较 neighborNode 记录的 G 值是否比 从 currentNode 到 neighborNode 的G 值更大
                // 如果 neighborNode.G 更大，则更新 neighborNode.G 并设置 neighborNode.Parent = currentNode;
                if (neighborNode.G > (currentNode.G + currentNode.Cost * distance))
                {
                    neighborNode.G = currentNode.G + currentNode.Cost * distance;
                    neighborNode.Parent = currentNode;
                    // 改变了 G 值，小根堆需要重排序
                    openHeap.HeapCreate();
                }
            }
            else
            {
                // 设置 neighborNode.G 值 = 从 起点 到 neighborNode 的总 G
                neighborNode.G = currentNode.G + currentNode.Cost * distance;

                // 使用 曼哈顿 方法计算 H 值，即(neighborNode 到 终点的 Row、Col 偏移量绝对值之和)
                float h = Math.Abs(neighborNode.Row - desitinationNode.Row) + Math.Abs(neighborNode.Col - desitinationNode.Col);
                neighborNode.H = h * neighborNode.Cost;

                // 设置父节点
                neighborNode.Parent = currentNode;

                neighborNode.NodeState = NodeState.InOpenTable;
                openHeap.Insert(neighborNode);
                InsertOpen(neighborNode);
            }
        }

        private void Check(Node node)
        {
            //string name = string.Format("open:{0}_{1}", node.Row, node.Col);
            //Debug.LogError(name);
            KeyValuePair<int, Node> kv = new KeyValuePair<int, Node>(1, node);
            AStarTest.checkNodeList.Add(kv);
        }

        private void InsertOpen(Node node)
        {
            //string name = string.Format("insertOpen:{0}_{1}", node.Row, node.Col);
            //Debug.LogError(name);
            KeyValuePair<int, Node> kv = new KeyValuePair<int, Node>(0, node);
            AStarTest.checkNodeList.Add(kv);
        }
    }
}
