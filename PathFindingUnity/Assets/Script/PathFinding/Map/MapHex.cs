using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

namespace PathFinding
{
    public class MapHex : IMap
    {
        public Dictionary<int, HexNode> _grid = new Dictionary<int, HexNode>();

        public const float OUTER_RADIUS = 1;
        public const float INNER_RADIUS = 0.866f;
        public float outerRadius = 1;
        public float innerRadius = 1;

        private int _row;
        private int _col;

        private MapSize _mapSize;

        private const int _neighborCount = 6;
        // 每个节点 8 个邻居的相对二维坐标
        private int[,] neighborArr = new int[,] {
            {  1,  0},   // 上
            {  1,  1},   // 右上
            {  0,  1},   // 右下
            { -1,  0},   // 下
            {  0, -1},   // 左下
            {  1, -1},   // 左上
        };

        public MapHex(float minX, float minY, float maxX, float maxY, float radius)
        {
            MapType = MapType.Hex;
            _mapSize = new MapSize(minX, minY, maxX, maxY);

            outerRadius = OUTER_RADIUS * radius;
            innerRadius = INNER_RADIUS * radius;

            float rowHeight = maxY - minY;
            _row = Mathf.CeilToInt(rowHeight / innerRadius);

            float colWidth = maxX - minX;
            float value = colWidth / outerRadius;
            value = value - 0.5f;
            _col = 1 + (int)Math.Round(value / 0.75f);

            UnityEngine.Debug.LogError(_row + "    " + _col);
            CreateGrid();
        }

        public MapType MapType { get; set; }

        // 行 以 z 轴正方向为 正
        // 列 以 x 轴正方向为 正
        // 创建网格
        public void CreateGrid()
        {
            _grid = new Dictionary<int, HexNode>();

            for (int i = 0; i < _row; ++i)
            {
                for (int j = 0; j < _col; ++j)
                {
                    CreateNode(i, j);
                }
            }

            HexNode hexNode = (HexNode)GetNode(4, 5);
            CreateGo(hexNode);
            for (int i = 0; i < _neighborCount; ++i)
            {
                HexNode node = (HexNode)NodeNeighbor(hexNode, i);
                CreateGo(node);
            }
        }
        private void CreateNode(int row, int col)
        {
            int index = RCToIndex(row, col);
            float cost = 1;
            int nodeType = (int)NodeType.Smooth; // _mapTerrainData.GetNodeData(i, j, ref cost);
            HexNode hexCell = new HexNode(row, col);
            hexCell.NodeType = (NodeType)nodeType;
            hexCell.Cost = cost;

            float x = (0.5f + 0.75f * col) * outerRadius;
            float z = (float)(0.5f + row + (col % 2) * 0.5) * innerRadius;
            hexCell.Position = new Position(x, z);

            hexCell.corners = new Vector3[6] {
                new Vector3(outerRadius * 0.25f, 0, innerRadius * 0.5f),
                new Vector3(outerRadius * 0.5f, 0, 0),
                new Vector3(outerRadius * 0.25f, 0, -innerRadius * 0.5f),
                new Vector3(-outerRadius * 0.25f, 0, -innerRadius * 0.5f),
                new Vector3(-outerRadius * 0.5f, 0, 0),
                new Vector3(-outerRadius * 0.25f, 0, innerRadius * 0.5f)
            };

            _grid[index] = hexCell;
        }

        private void CreateGo(HexNode hexCell)
        {
            GameObject go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            go.transform.localScale = Vector3.one * 0.3f;

            Vector3 center = new Vector3(hexCell.Position.X, 0, hexCell.Position.Y);
            go.transform.position = center;
            go.name = string.Format("{0}_{1}", hexCell.Row, hexCell.Col);
        }

        // 地图所有节点
        public Node[] Grid()
        {
            Node[] nodeArr = new Node[_grid.Count];
            int index = 0;
            foreach (var kv in _grid)
            {
                nodeArr[index] = kv.Value;
                ++index;
            }
            return nodeArr;
        }

        // 地图尺寸
        public MapSize MapSize()
        {
            return _mapSize;
        }

        // 地块 外径 长
        public float NodeOuterRadius()
        {
            return outerRadius;
        }

        // 地块 内径 长
        public float NodeInnerRadius()
        {
            return innerRadius;
        }

        /// <summary>
        /// 根据坐标获取 Node
        /// </summary>
        public Node PositionToNode(float x, float y)
        {
            if (!_mapSize.Contians(x, y))
            {
                return null;
            }

            float value = ((x / outerRadius) - 0.5f) / 0.75f;
            int col = Mathf.RoundToInt(value);

            value = (y / innerRadius) - 0.5f - (col % 2) * 0.5f;
            int row = Mathf.RoundToInt(value);

            int index = RCToIndex(row, col);
            return _grid[index];
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
            int row = node.Row + neighborArr[index, 0];
            int col = node.Col + neighborArr[index, 1];
            Node temp = GetNode(row, col);
            if (null != temp)
            {
                distance = (float)Math.Sqrt(Math.Abs(neighborArr[index, 0]) + Math.Abs(neighborArr[index, 1]));
            }
            return temp;
        }

        public Node NodeNeighbor(Node node, int index)
        {
            int row = node.Row + neighborArr[index, 0];
            int col = node.Col + neighborArr[index, 1];
            Node temp = GetNode(row, col);
            return temp;
        }
        public Node GetNode(int row, int col)
        {
            if (row < 0 || row >= _row || col < 0 || col >= _col)
            {
                return null;
            }

            int index = RCToIndex(row, col);
            return _grid[index];
        }

        private int RCToIndex(int row, int col)
        {
            int index = row * _col + col;
            return index;
        }

        public void Update()
        {
            foreach (var kv in _grid)
            {
                DrawHexCell(kv.Value);
            }
        }

        private void DrawHexCell(HexNode hexCell)
        {
            //if (hexCell.Row != 0 || hexCell.Col != 0)
            //{
            //    return;
            //}

            for (int i = 0; i < hexCell.corners.Length; ++i)
            {
                Position position = hexCell.Position;
                Vector3 center = new Vector3(position.X, 0, position.Y);

                Vector3 pos = hexCell.corners[i];
                pos += center;
                pos.y = 1;


                int secondIndex = (i + 1) % hexCell.corners.Length;
                Vector3 pos2 = hexCell.corners[secondIndex] + center;
                pos2.y = 1;

                Debug.DrawRay(pos, (pos2 - pos), Color.red);
            }
        }
    }

}