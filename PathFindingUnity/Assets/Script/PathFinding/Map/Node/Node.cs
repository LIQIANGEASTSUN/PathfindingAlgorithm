using System;
using System.Collections.Generic;

namespace PathFinding
{
    /// <summary>
    /// 
    /// </summary>
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

    /// <summary>
    /// 节点状态
    /// </summary>
    public enum NodeState
    {
        /// <summary>
        /// 未访问的节点
        /// </summary>
        New = 0,
        /// <summary>
        /// 在开放列表中
        /// </summary>
        InOpenTable = 1,
        /// <summary>
        /// 在关闭列表中
        /// </summary>
        InColsedTable = 2,
        /// <summary>
        /// 已经访问过的节点
        /// </summary>
        Known = 3,
    }

    public class Node : IComparable<Node>
    {
        // 节点行
        private int _row;
        // 节点列
        private int _col;
        // 节点邻居节点的个数
        private int _neighborCount;
        // 父节点
        private Node _parent;
        private float _h = 0;
        private float _g = 0;
        // 节点自身消耗
        private float _cost;
        // 节点类型
        private NodeType _nodeType;
        // 节点状态
        private NodeState _nodeState;
        // Jps 寻路中强制邻居节点
        private List<Node> _forceNeighbourList = new List<Node>();
        // 节点坐标
        private Position _position;
        // Jps+ 预处理地块信息
        private int[] _jpsPlus = null;

        /// <summary>
        /// 只有 Dstar 使用
        /// </summary>
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

        /// <summary>
        /// K 只有 Dstar 使用
        /// </summary>
        private float _k = 0;
        public float K
        {
            get { return _k; }
            set {  _k = value; }
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

        public static bool operator == (Node left, Node right)
        {
            // If both are null, or both are same instance, return true.
            if (System.Object.ReferenceEquals(left, right))
            {
                return true;
            }

            // If one is null, but not both, return false.
            if ((object)left == null || (object)right == null)
            {
                return false;
            }

            // Return true if the fields match:
            return left.Row == right.Row && left.Col == right.Col;
        }

        public static bool operator != (Node left, Node right)
        {
            return !(left == right);
        }

        public override bool Equals(object obj)
        {
            if (obj is Node node)
            {
                return this == node;
            }
            return false;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }
}
