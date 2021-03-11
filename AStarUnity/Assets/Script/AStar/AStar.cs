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
            foreach (var node in closedList)
            {
                node.Clear();
            }

            foreach(var node in openHeap._list)
            {
                node.Clear();
            }
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

                Neighbor(node, desitinationNode);
            }

            return null;
        }

        private void Neighbor(Node currentNode, Node desitinationNode)
        {
            //UnityEngine.Debug.LogError("Node:" + currentNode.Row + "   " + currentNode.Col + "    " + currentNode.G + "   " + currentNode.H);
            for (int i = 0; i < currentNode.neighborCount; ++i)
            {
                float distance = 0;
                Node neighborNode = _map.NodeNeighbor(currentNode, i, ref distance);
                InsertToOpenHeap(neighborNode, currentNode, desitinationNode, distance);
            }
        }

        private void InsertToOpenHeap(Node neighborNode, Node currentNode, Node desitinationNode, float distance)
        {
            if (null == neighborNode || neighborNode.NodeType == NodeType.Obstacle || neighborNode.NodeType == NodeType.Null)
            {
                return;
            }

            if (closedList.Contains(neighborNode))
            {
                return;
            }

            // 在 open 表中
            if (openHeap._list.Contains(neighborNode))
            {
                if (neighborNode.G > (currentNode.G + currentNode.Cost * distance))
                {
                    neighborNode.G = currentNode.G + currentNode.Cost * distance;
                    neighborNode.Parent = currentNode;
                    openHeap.HeapCreate();
                }
            }
            else
            {
                neighborNode.G = currentNode.G + currentNode.Cost * distance;
                float h = Math.Abs(neighborNode.Row - desitinationNode.Row) + Math.Abs(neighborNode.Col - desitinationNode.Col);
                neighborNode.H = h * neighborNode.Cost;
                neighborNode.Parent = currentNode;
                openHeap.Insert(neighborNode);
            }

            //UnityEngine.Debug.LogError(neighborNode.Row + "  " + neighborNode.Col + "   G:" + neighborNode.G + "   H:" + neighborNode.H);
        }

    }

}
