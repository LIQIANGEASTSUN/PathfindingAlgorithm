using DataStruct.Heap;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AStar.AStar
{
    public class AStarTest
    {

        public static void Test()
        {
            MapQuad _mapQuad = new MapQuad(-10, -10, 10, 10, 1, 1);
            _mapQuad.CreateGrid();

            AStar aStar = new AStar();
            aStar.SetMap(_mapQuad);

            Position from = new Position(-5, -5);
            Position to = new Position(5, 5);

            Node node = aStar.SearchPath(from, to);

            while (null != node)
            {
                Console.WriteLine(node.Row + "    " + node.Col);
                node = node.Parent;
            }
        }

    }


    public class AStar
    {
        private IMap _map;

        // 小根堆保存开放节点
        private Heap<Node> openHeap;
        private List<Node> openList;
        private List<Node> closedList;

        public AStar()
        {
            openHeap = new Heap<Node>();
            openHeap.SetHeapType(false);
            openList = new List<Node>();
            closedList = new List<Node>();
        }

        public void SetMap(IMap map)
        {
            _map = map;
        }

        public Node SearchPath(Position from, Position desitination)
        {
            Node fromNode = _map.PositionToNode(from.X, from.Y);
            Node desitinationNode = _map.PositionToNode(desitination.X, desitination.Y);

            openHeap.Insert(fromNode);
            openList.Add(fromNode);


            while (openHeap.Count() > 0)
            {
                Node node = openHeap.DelRoot();
                openList.Remove(node);
                closedList.Add(node);

                if (node.Row == desitinationNode.Row && node.Col == desitinationNode.Col)
                {
                    break;
                }

                float baseG = 1;
                for (int i = 0; i < node.AdjoinCount; ++i)
                {
                    Node adjoinNode = _map.NodeAdjoin(node, i);
                    if (closedList.Contains(adjoinNode) || openList.Contains(adjoinNode))
                    {
                        continue;
                    }

                    adjoinNode.Parent = node;

                    float g = Math.Abs(adjoinNode.Row - node.Row) + Math.Abs(adjoinNode.Col - node.Col) + baseG;
                    adjoinNode.SetG(g);

                    float h = Math.Abs(adjoinNode.Row - desitinationNode.Row) + Math.Abs(adjoinNode.Col - desitinationNode.Col);
                    adjoinNode.SetH(h);

                    openHeap.Insert(adjoinNode);
                    openList.Add(adjoinNode);
                }
            }

            return desitinationNode;
        }

    }
}
