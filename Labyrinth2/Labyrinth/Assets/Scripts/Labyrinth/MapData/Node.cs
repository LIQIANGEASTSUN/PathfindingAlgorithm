using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PathFinding
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
        public static Position operator- (Position left, Position right)
        {
            Position p = new Position(left.X - right.X, left.Y - right.Y);
            return p;
        }
        public static Position operator+ (Position left, Position right)
        {
            Position p = new Position(left.X + right.X, left.Y + right.Y);
            return p;
        }
        public static float Dot(Position left, Position right)
        {
            return left.X * right.X + left.Y * right.Y;
        }
    }

    public struct PositionInt
    {
        private int _x;
        private int _y;

        public PositionInt(int x, int y)
        {
            _x = x;
            _y = y;
        }

        public int X
        {
            get { return _x; }
        }

        public int Y
        {
            get { return _y; }
        }
        public static PositionInt operator -(PositionInt left, PositionInt right)
        {
            PositionInt p = new PositionInt(left.X - right.X, left.Y - right.Y);
            return p;
        }
        public static PositionInt operator +(PositionInt left, PositionInt right)
        {
            PositionInt p = new PositionInt(left.X + right.X, left.Y + right.Y);
            return p;
        }
        public static int Dot(PositionInt left, PositionInt right)
        {
            return left.X * right.X + left.Y * right.Y;
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

    public enum NodeState
    {
        Null = 0,
        InOpenTable = 1,
        InColsedTable = 2,
        Known = 3,
    }

    public class Node : IComparable<Node>
    {
        private int _row;
        private int _col;
        private int _neighborCount;
        private Node _parent;
        private float _h;
        private float _g;
        private float _cost;
        private NodeType _nodeType;
        private NodeState _nodeState;
        private List<Position> _forceNeighbourList = new List<Position>();
        private int _value;
        private int _flag;

        public Node(int row, int col, int neighborCount)
        {
            _row = row;
            _col = col;
            _neighborCount = neighborCount;
        }

        public float F
        {
            get { return H + G; }
        }

        public float H
        {
            get { return _h; }
            set { _h = value; }
        }

        public float G
        {
            get { return _g; }
            set { _g = value; }
        }

        public float Cost
        {
            get { return _cost; }
            set { _cost = value; }
        }

        public int Row
        {
            get { return _row; }
        }

        public int Col
        {
            get { return _col; }
        }

        public int Value
        {
            get { return _value; }
            set { _value = value; }
        }
        
        public int Flag
        {
            get { return _flag; }
            set { _flag = value; }
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

        public NodeState NodeState
        {
            get { return _nodeState; }
            set { _nodeState = value; }
        }

        public int neighborCount
        {
            get { return _neighborCount; }
        }

        public void Clear()
        {
            Parent = null;
            H = 0;
            G = 0;
            NodeState = NodeState.Null;
            ForceNeighbourList.Clear();
        }

        public List<Position> ForceNeighbourList
        {
            get { return _forceNeighbourList; }
        }
        public int CompareTo(Node node)
        {
            return F.CompareTo(node.F);
        }
    }
}
