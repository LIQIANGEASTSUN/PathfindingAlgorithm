using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace PathFinding
{
    // 六边形节点
    public class HexNode : Node
    {
        public Vector3[] corners = null;

        public HexNode(int row, int col) : base(row, col, 6)
        {

        }
    }

}
