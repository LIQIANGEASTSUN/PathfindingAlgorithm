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

    public class Node : IComparable<Node>
    {
        private int _row;
        private int _col;
        private int _adjoinCount;
        private Node _parent;
        private float _h;
        private float _g;

        public Node(int row, int col, int adjoinCount)
        {
            _row = row;
            _col = col;
            _adjoinCount = adjoinCount;
        }

        public void SetH(float h)
        {
            _h = h;
        }

        public void SetG(float g)
        {
            _g = g;
        }

        public float F
        {
            get { return _h + _g; }
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

        public int CompareTo(Node node)
        {
            return F.CompareTo(node.F);
        }
    }
}
