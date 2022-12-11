﻿using System.Collections;
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
        private Vector3[] corners = new Vector3[6];

        // 行
        private int maxRow;
        // 列
        private int maxCol;

        // 地图尺寸
        private MapSize _mapSize;

        public Dictionary<int, HexNode> _grid = new Dictionary<int, HexNode>();

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
            _mapSize = new MapSize(minX, minY, maxX, maxY);

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
            corners = new Vector3[6] {
                new Vector3(outerRadius * 0.25f, 0, innerRadius * 0.5f),
                new Vector3(outerRadius * 0.5f, 0, 0),
                new Vector3(outerRadius * 0.25f, 0, -innerRadius * 0.5f),
                new Vector3(-outerRadius * 0.25f, 0, -innerRadius * 0.5f),
                new Vector3(-outerRadius * 0.5f, 0, 0),
                new Vector3(-outerRadius * 0.25f, 0, innerRadius * 0.5f)
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

            float x = (0.75f * col) * outerRadius;
            float z = (float)(row + (col % 2) * 0.5) * innerRadius;
            hexCell.Position = new Position(x, z);

            _grid[index] = hexCell;
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

        /// <summary>
        /// 根据坐标获取 Node
        /// </summary>
        public Node PositionToNode(float x, float y)
        {
            if (!_mapSize.Contians(x, y))
            {
                return null;
            }

            float value = (x / outerRadius) / 0.75f;
            int col = Mathf.RoundToInt(value);

            value = y / innerRadius - (col % 2) * 0.5f;
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
            return _grid[index];
        }

        private int RCToIndex(int row, int col)
        {
            int index = row * maxCol + col;
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
            for (int i = 0; i < corners.Length; ++i)
            {
                Position position = hexCell.Position;
                Vector3 center = new Vector3(position.X, 0, position.Y);

                Vector3 pos = corners[i] * 0.95f;
                pos += center;
                pos.y = 1;

                int secondIndex = (i + 1) % corners.Length;
                Vector3 pos2 = corners[secondIndex] * 0.95f + center;
                pos2.y = 1;

                Debug.DrawRay(pos, (pos2 - pos), Color.red);
            }
        }
    }
}