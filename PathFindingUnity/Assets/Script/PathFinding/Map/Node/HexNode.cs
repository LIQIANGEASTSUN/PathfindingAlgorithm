using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace PathFinding
{
    // 六边形节点
    public class HexNode : Node
    {
        public float outerRadius = MapHex.OUTER_RADIUS;
        public float innerRadius = MapHex.INNER_RADIUS;

        public HexNode(int row, int col) : base(row, col, 6)
        {

        }
    }

}
