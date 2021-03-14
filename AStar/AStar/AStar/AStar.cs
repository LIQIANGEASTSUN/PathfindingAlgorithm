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

            Position from = new Position(-5, -5);
            Position to = new Position(5, 5);

            Node node = aStar.SearchPath(from, to);
        }

    }


    public class AStar
    {
        private IMap _map;

        public AStar()
        {
        }

        public void SetMap(IMap map)
        {
            _map = map;
        }

        public Node SearchPath(Position from, Position to)
        {



            return null;
        }

    }
}
