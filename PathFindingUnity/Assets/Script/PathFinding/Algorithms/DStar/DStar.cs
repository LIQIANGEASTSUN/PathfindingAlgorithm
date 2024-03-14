using System;
using System.Collections.Generic;
using System.Diagnostics;
using DataStruct.Heap;

namespace PathFinding
{
    /// <summary>
    /// D* 寻路算法
    /// </summary>
    public class DStar
    {
        private IMap _map;
        private Heap<Node> _openHeap = new Heap<Node>(false);
        private List<Node> _closeList = new List<Node>();

        public DStar(IMap map)
        {
            _map = map;
        }

        public Node SearchPath(Position from, Position desitination)
        {
            foreach (var node in _openHeap.DataList)
            {
                node.Clear();
            }
            foreach (var node in _closeList)
            {
                node.Clear();
            }
            _openHeap.MakeEmpty();
            _closeList.Clear();

            Node fromNode = _map.PositionToNode(from.X, from.Y);
            Node desitinationNode = _map.PositionToNode(desitination.X, desitination.Y);

            desitinationNode.H = 0;
            _openHeap.Insert(desitinationNode);

            while (_openHeap.Count() > 0)
            {
                float k = PROCESS_STATE();
                if (fromNode.NodeState == NodeState.InColsedTable)
                {
                    break;
                }
                if (k <= 0)
                {
                    break;
                }
            }

            return fromNode.NodeState == NodeState.InColsedTable ? fromNode : null;
        }

        private bool reSearch = false;
        public bool ReSearch(Node node, Node next)
        {
            reSearch = true;
            MODIFY_COST(node, next, 100000);
            float kmin = 0;
            do
            {
                kmin = PROCESS_STATE();
            }
            while (kmin >= 0 && kmin < node.H);
            //while (kmin >= 0 && node.K < node.H);
            // 上面两个 while 经过测试都可以完成再次寻路
            // 看论文中的两个方案

            return true;
        }

        private float PROCESS_STATE()
        {
            if (_openHeap.Count() <= 0)
            {
                return -1;
            }

            Node X = _openHeap.DelRoot();
            X.NodeState = NodeState.InColsedTable;
            _closeList.Add(X);
            float k_old = X.K;
            if (k_old < X.H)
            {
                for (int i = 0; i < X.neighborCount; ++i)
                {
                    float distance = 0;
                    Node Y = _map.NodeNeighborWithDistance(X, i, ref distance);
                    if (!IsValid(Y))
                    {
                        continue;
                    }
                    if (Y.H <= k_old && X.H > Y.H + Cost(Y, X))
                    {
                        //尝试在现有路径条件下，先更新当前cost
                        X.Parent = Y;
                        X.H = Y.H + Cost(Y, X);
                    }
                }
            }
            if (k_old == X.H)
            {
                for (int i = 0; i < X.neighborCount; ++i)
                {
                    float distance = 0;
                    Node Y = _map.NodeNeighborWithDistance(X, i, ref distance);
                    if (!IsValid(Y))
                    {
                        continue;
                    }
                    if (Y.NodeState == NodeState.New
                        || ((Y.Parent == X) && Y.H != X.H + Cost(X, Y))
                        || ((Y.Parent != X) && Y.H > X.H + Cost(X, Y))
                    )
                    {
                        Y.Parent = X;
                        INSERT(Y, X.H + Cost(X, Y));
                    }
                }
            }
            else
            {
                for (int i = 0; i < X.neighborCount; ++i)
                {
                    float distance = 0;
                    Node Y = _map.NodeNeighborWithDistance(X, i, ref distance);
                    if (!IsValid(Y))
                    {
                        continue;
                    }
                    if (Y.NodeState == NodeState.New
                        || ((Y.Parent == X) && Y.H != X.H + Cost(X, Y)))//传递异常信息c(X,Y)带来的变化
                    {
                        Y.Parent = X;
                        INSERT(Y, X.H + Cost(X, Y));
                    }
                    else
                    {
                        if ((Y.Parent != X) && Y.H > X.H + Cost(X, Y) ){ //将X再次插入队列，从RAISE模式变成了LOWER模式来扩展修正Y
                            INSERT(X, X.H);
                        }
                        else
                        {
                            if ((Y.Parent != X) 
                                && X.H > Y.H + Cost(Y, X) 
                                && Y.NodeState == NodeState.InColsedTable 
                                && Y.H > k_old )
                            {  //寻找次优解，新的路径
                                INSERT(Y, Y.H);
                            }
                        }
                    }
                }
            }

            if (_openHeap.Count() <= 0)
            {
                return -1;
            }
            Node node = _openHeap.GetRoot();
            return node.K;
        }

        private bool IsValid(Node node)
        {
            if (null == node || node.NodeType == NodeType.Obstacle || node.NodeType == NodeType.Null)
            {
                return false;
            }
            return true;
        }

        private void INSERT(Node x, float cost)
        {
            //if (reSearch)
            //{
            //    UnityEngine.Debug.LogError("Insert:" + x.Row + "  " + x.Col);
            //}

            // 隐含着将X节点加入到OPEN_QUOPEN(如果不存在的的话)
            if (x.NodeState == NodeState.New)
            {
                x.K = cost;
                _openHeap.Insert(x);
            }
            else if (x.NodeState == NodeState.InOpenTable)
            {
                x.K = Math.Min(x.K, cost);
            }
            else
            {
                // t(X) == CLOSED
                x.K = Math.Min(x.H, cost);  //可使得X节点从RAISE进入LOWER模式
                _openHeap.Insert(x);
            }

            x.H = cost;
            x.NodeState = NodeState.InOpenTable;
            _openHeap.HeapCreate();
            DStarTest.insertOpenList.Add(x);
        }

        // 假设人走到节点 Y，准备前往节点 X 的时候，发现节点 X 突然塌陷或者出现障碍物进行 Cost 修正
        // 实际一个节点上障碍物的出现可能导致周边的节点都受到影响，尤其是 n.parent ==X的节点，
        // 所以最好的办法是所有的关联节点都进行修正，并且是双边修正
        public void MODIFY_COST(Node Y, Node X, float cost)
        {
            X.H = cost;
            if (Y.NodeState == NodeState.InColsedTable)
            {
                INSERT(Y, X.H + Cost(X, Y));
            }
        }

        private float Cost(Node x, Node y) { 
            int offsetRow = Math.Abs(x.Row - y.Row);
            int offsetCol = Math.Abs(x.Col - y.Col);
            float value = (float)(Math.Sqrt(offsetRow) + Math.Sqrt(offsetCol));
            return value;
        }
    }
}