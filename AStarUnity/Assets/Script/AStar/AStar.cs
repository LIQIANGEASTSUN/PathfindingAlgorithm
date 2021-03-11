﻿using DataStruct.Heap;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AStar
{
    public class AStar
    {
        private IMap _map;

        // 小根堆保存开放节点
        private Heap<Node> openHeap;
        private List<Node> closedList;

        public AStar()
        {
            openHeap = new Heap<Node>();
            openHeap.SetHeapType(false);
            closedList = new List<Node>();
        }

        public void SetMap(IMap map)
        {
            _map = map;
        }

        public Node SearchPath(Position from, Position desitination)
        {
            openHeap.MakeEmpty();
            closedList.Clear();

            Node fromNode = _map.PositionToNode(from.X, from.Y);
            Node desitinationNode = _map.PositionToNode(desitination.X, desitination.Y);

            openHeap.Insert(fromNode);

            while (openHeap.Count() > 0)
            {
                Node node = openHeap.DelRoot();
                closedList.Add(node);

                if (node.Row == desitinationNode.Row && node.Col == desitinationNode.Col)
                {
                    return node;
                }

                for (int i = 0; i < node.AdjoinCount; ++i)
                {
                    Node adjoinNode = _map.NodeAdjoin(node, i);
                    if (   null == adjoinNode
                        || closedList.Contains(adjoinNode)
                        || openHeap.DataList.Contains(adjoinNode)
                        || adjoinNode.NodeType == NodeType.Obstacle)
                    {
                        continue;
                    }

                    adjoinNode.Parent = node;

                    float g = Math.Abs(adjoinNode.Row - node.Row) + Math.Abs(adjoinNode.Col - node.Col) + _map.G(node.NodeType);
                    adjoinNode.SetG(g);

                    float h = Math.Abs(adjoinNode.Row - desitinationNode.Row) + Math.Abs(adjoinNode.Col - desitinationNode.Col);
                    adjoinNode.SetH(h);

                    openHeap.Insert(adjoinNode);
                }
            }

            return null;
        }

    }
}
