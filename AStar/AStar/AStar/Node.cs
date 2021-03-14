using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AStar.AStar
{

    public struct Position
    {
        private float _x;
        private float _y;

        public Position(float x, float y)
        {
            _x = x;
            _y = y;
        }

        public float X
        {
            get { return _x; }
        }

        public float Y
        {
            get { return _y; }
        }
    }

    public class Node
    {
        private int _row;
        private int _col;
        private int _adjoinCount;
        private Node _parent;

        public Node(int row, int col, int adjoinCount)
        {
            _row = row;
            _col = col;
            _adjoinCount = adjoinCount;
        }

        public int Row
        {
            get { return _row; }
        }

        public int Col
        {
            get { return _col; }
        }

        public Node Parent
        {
            get { return _parent; }
            set { _parent = value; }
        }

        public int AdjoinCount
        {
            get { return _adjoinCount; }
        }

    }
}
