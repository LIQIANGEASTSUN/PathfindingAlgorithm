using System.Collections.Generic;
using UnityEngine;
using System;

namespace PathFinding
{
    /// <summary>
    /// 正六边形格子地图
    // 横向六边形
    // 长边对应的 Col 列，短边对应的 Row 行
    //   ****
    // *      *   -> X 轴
    //   ****
    /// </summary>
    public class MapHex : IMap
    {
        // 六边形外径比例
        public const float OUTER_RADIUS = 1;
        // 六边形内径比例
        public const float INNER_RADIUS = 0.866f;
        // 六边形外径
        public float outerRadius = 1;
        // 六边形内径
        public float innerRadius = 1;

        // 六边形六个顶点相对于中心的坐标
        private Position[] corners = new Position[6];

        // 行
        private int maxRow;
        // 列
        private int maxCol;

        // 地图尺寸
        private MapSize _mapSize;

        public Dictionary<int, HexNode> gridDic = new Dictionary<int, HexNode>();

        // 奇数列节点 6 个邻居的相对二维坐标
        private int[,] oddColneighborArr = new int[,] {
            {  1,  0},   // 上
            {  1,  1},   // 右上
            {  0,  1},   // 右下
            { -1,  0},   // 下
            {  0, -1},   // 左下
            {  1, -1},   // 左上
        };

        // 偶数列节点 6 个邻居的相对二维坐标
        private int[,] evenColneighborArr = new int[,] {
            {  1,  0},   // 上
            {  0,  1},   // 右上
            { -1,  1},   // 右下
            { -1,  0},   // 下
            { -1, -1},   // 左下
            {  0, -1},   // 左上
        };

        /// <summary>
        /// 六边形地图构造函数
        /// 行列坐标最大值最小值根据自己需求定义
        /// 比如：
        /// (1)在 X、Z 平面上创建地图，可以使用 X 坐标计算 列，Z 坐标计算 行，地图最小行列位置为 (X = 10, Z = 10)，最大行列位置为 (X = 30，Z = 30) 
        /// (2)在 X、Y 平面上创建地图，可以使用 X 坐标计算 列，Y 坐标计算 行，地图最小行列位置为 (X = 10, Y = 10)，最大行列位置为 (X = 30，Y = 30) 
        /// </summary>
        /// <param name="minRowPos">行最小的坐标值</param>
        /// <param name="minColPos">列做小的坐标值</param>
        /// <param name="maxRowPos">行最大的坐标值</param>
        /// <param name="maxColPos">列最大的坐标值</param>
        /// <param name="radius"></param>
        public MapHex(float minRowPos, float minColPos, float maxRowPos, float maxColPos, float radius)
        {
            MapType = MapType.Hex;
            _mapSize = new MapSize(minRowPos, minColPos, maxRowPos, maxColPos);

            outerRadius = OUTER_RADIUS * radius;
            innerRadius = INNER_RADIUS * radius;
            SetCorners();

            float rowHeight = maxRowPos - minRowPos;
            maxRow = Mathf.CeilToInt(rowHeight / innerRadius);

            float colWidth = maxColPos - minColPos;
            maxCol = (int)Math.Round((colWidth / outerRadius) / 0.75f) + 1;

            CreateGrid();
        }

        private void SetCorners()
        {
            corners = new Position[6] {
                new Position(innerRadius * 0.5f, outerRadius * 0.25f),
                new Position( 0, outerRadius * 0.5f),
                new Position(-innerRadius * 0.5f, outerRadius * 0.25f),
                new Position(-innerRadius * 0.5f, -outerRadius * 0.25f),
                new Position(0, -outerRadius * 0.5f),
                new Position(innerRadius * 0.5f, -outerRadius * 0.25f)
            };
        }

        public MapType MapType { get; set; }

        /// <summary>
        /// 创建网格
        /// </summary>
        public void CreateGrid()
        {
            for (int row = 0; row < maxRow; ++row)
            {
                for (int col = 0; col < maxCol; ++col)
                {
                    CreateNode(row, col);
                }
            }
        }

        private void CreateNode(int row, int col)
        {
            int index = RCToIndex(row, col);
            HexNode hexCell = new HexNode(row, col);
            hexCell.NodeType = NodeType.Smooth;
            hexCell.Cost = 1;

            hexCell.Position = NodeToPosition(row, col);
            gridDic[index] = hexCell;
        }

        // 地图所有节点
        public Node[] Grid()
        {
            Node[] nodeArr = new Node[gridDic.Count];
            for (int row = 0; row < maxRow; ++row)
            {
                for (int col = 0; col < maxCol; ++col)
                {
                    int index = RCToIndex(row, col);
                    gridDic.TryGetValue(index, out HexNode node);
                    nodeArr[index] = node;
                }
            }
            return nodeArr;
        }

        // 地图尺寸
        public MapSize MapSize()
        {
            return _mapSize;
        }

        public bool PositionToRowCol(float rowPos, float colPos, ref int row, ref int col)
        {
            if (!_mapSize.Contians(rowPos, colPos))
            {
                return false;
            }

            Position position = new Position(rowPos, colPos);
            bool result = false;

            rowPos = rowPos - _mapSize._minRowPos;
            colPos = colPos - _mapSize._minColPos;

            float value = (colPos / outerRadius) / 0.75f;
            int mideleCol = Mathf.RoundToInt(value);

            for (col = mideleCol - 1; col <= mideleCol + 1; ++col)
            {
                value = rowPos / innerRadius - (col % 2) * 0.5f;
                row = Mathf.RoundToInt(value);

                Node node = GetNode(row, col);
                if (NodeContainPosition((HexNode)node, position))
                {
                    result = true;
                    break;
                }
            }

            return result;
        }

        /// <summary>
        /// 根据坐标获取 Node
        /// </summary>
        public Node PositionToNode(float rowPos, float colPos)
        {
            int row = 0;
            int col = 0;

            if (!PositionToRowCol(rowPos, colPos, ref row, ref col))
            {
                return null;
            }

            int index = RCToIndex(row, col);
            return gridDic[index];
        }

        public Position NodeToPosition(int row, int col)
        {
            float rowPos = _mapSize._minRowPos + (float)(row + (col % 2) * 0.5) * innerRadius;
            float colPos = _mapSize._minColPos + (0.75f * col) * outerRadius;
            Position position = new Position(rowPos, colPos);
            return position;
        }

        /// <summary>
        /// 根据 Node 获取坐标
        /// </summary>
        public Position NodeToPosition(Node node)
        {
            return node.Position;
        }

        /// <summary>
        /// 获取 Node 的第 index 个邻居
        /// </summary>
        public Node NodeNeighborWithDistance(Node node, int index, ref float distance)
        {
            int[] dir = NodeNeighbourDir(node, index);
            int row = node.Row + dir[0];
            int col = node.Col + dir[1];
            Node temp = GetNode(row, col);
            if (null != temp)
            {
                distance = (float)Math.Sqrt(Math.Abs(dir[0]) + Math.Abs(dir[1]));
            }
            return temp;
        }

        public Node NodeNeighbor(Node node, int index)
        {
            int[] dir = NodeNeighbourDir(node, index);
            int row = node.Row + dir[0];
            int col = node.Col + dir[1];
            Node temp = GetNode(row, col);
            return temp;
        }

        public int GetNodeNeighborIndex(Node node, int dirRow, int dirCol)
        {
            int index = 0;
            int[,] neighbors = null;
            if (node.Col % 2 == 0)
            {
                neighbors = evenColneighborArr;
            }
            else
            {
                neighbors = oddColneighborArr;
            }
            for (int i = 0; i < neighbors.Length; ++i)
            {
                if (dirRow == neighbors[i, 0] && dirCol == neighbors[i, 1])
                {
                    index = i;
                    break;
                }
            }
            return index;
        }

        public int[] NodeNeighbourDir(Node node, int index)
        {
            int[] dir = new int[2];
            if (node.Col % 2 == 0)
            {
                dir[0] = evenColneighborArr[index, 0];
                dir[1] = evenColneighborArr[index, 1];
            }
            else
            {
                dir[0] = oddColneighborArr[index, 0];
                dir[1] = oddColneighborArr[index, 1];
            }

            return dir;
        }

        public Node GetNode(int row, int col)
        {
            if (row < 0 || row >= maxRow || col < 0 || col >= maxCol)
            {
                return null;
            }

            int index = RCToIndex(row, col);
            HexNode node = null;
            gridDic.TryGetValue(index, out node);
            return node;
        }

        private int RCToIndex(int row, int col)
        {
            int index = row * maxCol + col;
            return index;
        }

        private bool NodeContainPosition(HexNode hexNode, Position position)
        {
            if (null == hexNode)
            {
                return false;
            }

            Position center = hexNode.Position;
            for (int i = 0; i < corners.Length; ++i)
            {
                Position vectex1 = center + corners[i];

                int secondIndex = (i + 1) % corners.Length;
                Position vectex2 = center + corners[secondIndex];

                Position vectexOffset = vectex2 - vectex1;
                Vector3 vectexVector = new Vector3(vectexOffset.ColPos, 0, vectexOffset.RowPos).normalized;

                Position offset = position - vectex1;
                Vector3 offsetVector = new Vector3(offset.ColPos, 0, offset.RowPos).normalized;

                Vector3 cross = Vector3.Cross(vectexVector, offsetVector);
                if (cross.y < 0)
                {
                    return false;
                }
            }

            return true;
        }

        public void Update()
        {
#if UNITY_EDITOR
            foreach (var kv in gridDic)
            {
                DrawHexCell(kv.Value);
            }
#endif
        }

        private void DrawHexCell(HexNode hexCell)
        {
            Position center = hexCell.Position;
            for (int i = 0; i < corners.Length; ++i)
            {
                Position pos = center + corners[i];

                int secondIndex = (i + 1) % corners.Length;
                Position pos2 = center + corners[secondIndex];

                Vector3 p1 = new Vector3(pos.ColPos, 0, pos.RowPos);
                Vector3 p2 = new Vector3(pos2.ColPos, 0, pos2.RowPos);
                Debug.DrawRay(p1, p2 - p1, Color.red);
            }
        }
    }
}