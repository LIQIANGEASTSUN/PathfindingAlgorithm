using System.Collections.Generic;
using System;
using DataStruct.Heap;

namespace PathFinding
{

    public class Dijkstra
    {
        // 地图数据
        private IMap _map;
        private Heap<Node> _openHeap;
        private List<Node> _closeList = new List<Node>();

        public Dijkstra()
        {
            _openHeap = new Heap<Node>();
            _openHeap.SetHeapType(false);

        }

        public void SetMap(IMap map)
        {
            _map = map;
        }

        public Node SearchPath(Position from, Position desitination)
        {
            foreach(var node in _openHeap.DataList)
            {
                node.Clear();
            }
            foreach(var node in _closeList)
            {
                node.Clear();
            }
            _openHeap.MakeEmpty();
            _closeList.Clear();

            Node fromNode = _map.PositionToNode(from.X, from.Y);
            Node desitinationNode = _map.PositionToNode(desitination.X, desitination.Y);

            fromNode.G = 0;
            _openHeap.Insert(fromNode);

            while (_openHeap.Count() > 0)
            {
                Node node = _openHeap.DelRoot();
                node.NodeState = NodeState.InColsedTable;
                _closeList.Add(node);

                if (node.Row == desitinationNode.Row && node.Col == desitinationNode.Col)
                {
                    return node;
                }

                Neighbor(node, desitinationNode);
            }

            return null;
        }

        private void Neighbor(Node currentNode, Node desitinationNode)
        {
            // 遍历获取 currentNode 所有相邻节点
            for (int i = 0; i < currentNode.neighborCount; ++i)
            {
                float distance = 0;
                Node neighborNode = _map.NodeNeighbor(currentNode, i, ref distance);
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
                    _openHeap.HeapCreate();
                }
            }
            else
            {
                // 设置 neighborNode.G 值 = 从 起点 到 neighborNode 的总 G
                neighborNode.G = currentNode.G + currentNode.Cost * distance;
                // 设置父节点
                neighborNode.Parent = currentNode;
                neighborNode.NodeState = NodeState.InOpenTable;
                _openHeap.Insert(neighborNode);

                DijkstraTest.insertOpenList.Add(neighborNode);
            }
        }
    }

}
