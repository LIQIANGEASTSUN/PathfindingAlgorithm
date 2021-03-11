using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AStar
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

    public enum NodeType
    {
        /// <summary>
        /// 空地
        /// </summary>
        Null = -1,

        /// <summary>
        /// 平坦的路
        /// </summary>
        Smooth = 0,

        /// <summary>
        /// 泥路
        /// </summary>
        Mud = 1,

        /// <summary>
        /// 草地
        /// </summary>
        Grass = 2,

        /// <summary>
        /// 沙地
        /// </summary>
        Desert = 3,

        /// <summary>
        /// 障碍物
        /// </summary>
        Obstacle = 10,
    }

    public class Node : IComparable<Node>
    {
        private int _row;
        private int _col;
        private int _adjoinCount;
        private Node _parent;
        private float _h;
        private float _g;
        private NodeType _nodeType;

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

        public NodeType NodeType
        {
            get { return _nodeType; }
            set { _nodeType = value; }
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
