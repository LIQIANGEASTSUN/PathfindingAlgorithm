using System.Collections.Generic;
using UnityEngine;
using System;

namespace PathFinding
{
    // 正六边形格子地图
    // 横向六边形
    // 长边对应的 X 轴，短边对应的 Z 轴
    //   ****
    // *      *   -> X 轴
    //   ****
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
        private MapSize mapSize;

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

        public MapHex(float minX, float minY, float maxX, float maxY, float radius)
        {
            MapType = MapType.Hex;
            mapSize = new MapSize(minX, minY, maxX, maxY);

            outerRadius = OUTER_RADIUS * radius;
            innerRadius = INNER_RADIUS * radius;
            SetCorners();

            float rowHeight = maxY - minY;
            maxRow = Mathf.CeilToInt(rowHeight / innerRadius);

            float colWidth = maxX - minX;
            maxCol = (int)Math.Round((colWidth / outerRadius) / 0.75f) + 1;

            CreateGrid();
        }

        private void SetCorners()
        {
            corners = new Position[6] {
                new Position(outerRadius * 0.25f, innerRadius * 0.5f),
                new Position(outerRadius * 0.5f, 0),
                new Position(outerRadius * 0.25f, -innerRadius * 0.5f),
                new Position(-outerRadius * 0.25f, -innerRadius * 0.5f),
                new Position(-outerRadius * 0.5f, 0),
                new Position(-outerRadius * 0.25f, innerRadius * 0.5f)
            };
        }

        public MapType MapType { get; set; }

        // 行 以 z 轴正方向为 正
        // 列 以 x 轴正方向为 正
        // 创建网格
        public void CreateGrid()
        {
            for (int i = 0; i < maxRow; ++i)
            {
                for (int j = 0; j < maxCol; ++j)
                {
                    CreateNode(i, j);
                }
            }
        }

        private void CreateNode(int row, int col)
        {
            int index = RCToIndex(row, col);
            int nodeType = (int)NodeType.Smooth;
            HexNode hexCell = new HexNode(row, col);
            hexCell.NodeType = (NodeType)nodeType;
            hexCell.Cost = 1;

            float x = mapSize._minX + (0.75f * col) * outerRadius;
            float z = mapSize._minY + (float)(row + (col % 2) * 0.5) * innerRadius;

            hexCell.Position = new Position(x, z);

            gridDic[index] = hexCell;
        }

        // 地图所有节点
        public Node[] Grid()
        {
            Node[] nodeArr = new Node[gridDic.Count];
            int index = 0;
            foreach (var kv in gridDic)
            {
                nodeArr[index] = kv.Value;
                ++index;
            }
            return nodeArr;
        }

        // 地图尺寸
        public MapSize MapSize()
        {
            return mapSize;
        }

        public bool PositionToRowCol(float x, float y, ref int row, ref int col)
        {
            row = 0;
            col = 0;
            if (!mapSize.Contians(x, y))
            {
                return false;
            }

            Position position = new Position(x, y);
            bool result = false;

            x = x - mapSize._minX;
            y = y - mapSize._minY;

            float value = (x / outerRadius) / 0.75f;
            int mideleCol = Mathf.RoundToInt(value);


            for (col = mideleCol - 1; col <= mideleCol + 1; ++col)
            {
                value = y / innerRadius - (col % 2) * 0.5f;
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
        public Node PositionToNode(float x, float y)
        {
            int row = 0;
            int col = 0;

            if (!PositionToRowCol(x, y, ref row, ref col))
            {
                return null;
            }

            int index = RCToIndex(row, col);
            return gridDic[index];
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
                Vector3 vectexVector = new Vector3(vectexOffset.X, 0, vectexOffset.Y).normalized;

                Position offset = position - vectex1;
                Vector3 offsetVector = new Vector3(offset.X, 0, offset.Y).normalized;

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
            foreach (var kv in gridDic)
            {
                DrawHexCell(kv.Value);
            }
        }

        private void DrawHexCell(HexNode hexCell)
        {
            Position center = hexCell.Position;
            for (int i = 0; i < corners.Length; ++i)
            {
                Position pos = center + corners[i];

                int secondIndex = (i + 1) % corners.Length;
                Position pos2 = center + corners[secondIndex];

                Vector3 p1 = new Vector3(pos.X, 0, pos.Y);
                Vector3 p2 = new Vector3(pos2.X, 0, pos2.Y);
                Debug.DrawRay(p1, p2 - p1, Color.red);
            }
        }
    }
}