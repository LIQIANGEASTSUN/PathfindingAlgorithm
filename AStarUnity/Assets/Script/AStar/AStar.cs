using DataStruct.Heap;
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
            if (fromNode.Row == desitinationNode.Row && fromNode.Col == desitinationNode.Col)
            {
                return null;
            }

            openHeap.Insert(fromNode);

            while (openHeap.Count() > 0)
            {
                Node node = openHeap.DelRoot();
                closedList.Add(node);

                if (node.Row == desitinationNode.Row && node.Col == desitinationNode.Col)
                {
                    return node;
                }

                for (int i = 0; i < node.neighborCount; ++i)
                {
                    Node neighborNode = _map.NodeNeighbor(node, i);
                    if (   null == neighborNode
                        || closedList.Contains(neighborNode)
                        || openHeap.DataList.Contains(neighborNode)
                        || neighborNode.NodeType == NodeType.Obstacle)
                    {
                        continue;
                    }

                    neighborNode.Parent = node;

                    int offsetRow = neighborNode.Row - node.Row;
                    int offsetCol = neighborNode.Col - node.Col;
                    float g = (float)Math.Sqrt(offsetRow * offsetRow + offsetCol * offsetCol) + _map.G(node.NodeType);
                    neighborNode.SetG(g);

                    float h = Math.Abs(neighborNode.Row - desitinationNode.Row) + Math.Abs(neighborNode.Col - desitinationNode.Col);
                    neighborNode.SetH(h);

                    openHeap.Insert(neighborNode);
                }
            }

            return null;
        }

        private void Neighbor()
        {

        }

    }
}
