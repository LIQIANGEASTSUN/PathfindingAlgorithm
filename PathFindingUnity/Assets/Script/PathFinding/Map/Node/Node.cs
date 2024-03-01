using System;
using System.Collections.Generic;

namespace PathFinding
{
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
        New = 0,
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
        private List<Node> _forceNeighbourList = new List<Node>();
        private Position _position;
        // Jps+ 预处理地块信息
        private int[] _jpsPlus = null;

        public static bool compareUseK = false;

        public Node(int row, int col, int neighborCount)
        {
            _row = row;
            _col = col;
            _neighborCount = neighborCount;
            _jpsPlus = new int[neighborCount];
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

        private float _k;
        public float K
        {
            get { return _k; }
            set { _k = value; }
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

        public NodeState NodeState
        {
            get { return _nodeState; }
            set { _nodeState = value; }
        }

        public int neighborCount
        {
            get { return _neighborCount; }
        }

        public int[] JpsPlus
        {
            get { return _jpsPlus; }
        }

        public void Clear()
        {
            Parent = null;
            H = 0;
            G = 0;
            NodeState = NodeState.New;
            ForceNeighbourList.Clear();
        }

        public List<Node> ForceNeighbourList
        {
            get { return _forceNeighbourList; }
        }

        public Position Position
        {
            get { return _position; }
            set { _position = value; }
        }

        public int CompareTo(Node node)
        {
            if (compareUseK)
            {
                return K.CompareTo(node.K);
            }
            return F.CompareTo(node.F);
        }

    }
}
