using System;
using UnityEngine;

namespace PathFinding
{
    /// <summary>
    /// 矩形格子地图
    /// </summary>
    public class MapQuad : IMap
    {
        private MapSize _mapSize;
        private Node[] _grid = null;
        private float _rowHeight;
        private float _colWidth;

        private int maxRow;
        private int maxCol;

        private const int _neighborCount = 8;
        // 每个节点 8 个邻居的相对二维坐标
        private int[,] neighborArr = new int[,] {
            { -1, -1},
            { -1,  0},
            { -1,  1},
            {  0,  1},
            {  1,  1},
            {  1,  0},
            {  1, -1},
            {  0, -1}
        };

        // float minRowPos, float minColPos, float maxRowPos, float maxColPos
        public MapQuad(float minRowPos, float minColPos, float maxRowPos, float maxColPos, float rowHeight, float colWidth)
        {
            MapType = MapType.Quad;
            _mapSize = new MapSize(minRowPos, minColPos, maxRowPos, maxColPos);
            _rowHeight = rowHeight;
            _colWidth = colWidth;

            maxRow = Mathf.CeilToInt((_mapSize._maxRowPos - _mapSize._minRowPos) / _rowHeight);
            maxCol = Mathf.CeilToInt((_mapSize._maxColPos - _mapSize._minColPos) / _colWidth);

            CreateGrid();
        }

        public MapType MapType { get; set; }

        // 创建网格
        private void CreateGrid()
        {
            // 使用一维数组存放 node
            _grid = new Node[maxRow * maxCol];
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
            Node node = new Node(row, col, _neighborCount);
            node.NodeType = NodeType.Smooth;
            node.Cost = 1;

            node.Position = NodeToPosition(node.Row, node.Col);
            _grid[index] = node;
        }

        public Position NodeToPosition(int row, int col)
        {
            float rowPos = _mapSize._minRowPos + (row + 0.5f) * _rowHeight; //_mapSize._maxRowPos - (row + 0.5f) * _rowHeight;
            float colPos = _mapSize._minColPos + (col + 0.5f) * _colWidth;
            Position position = new Position(rowPos, colPos);
            return position;
        }

        // 地图所有节点
        public Node[] Grid()
        {
            return _grid;
        }

        // 地图尺寸
        public MapSize MapSize()
        {
            return _mapSize;
        }

        // 地块 Node 宽
        public float NodeWidth()
        {
            return _colWidth;
        }

        // 地块 Node 长
        public float NodeLength()
        {
            return _rowHeight;
        }

        /// <summary>
        /// 根据坐标获取 Node
        /// </summary>
        public Node PositionToNode(float rowPos, float colPos)
        {
            if (!_mapSize.Contians(rowPos, colPos))
            {
                return null;
            }

            int row = (int)((rowPos - _mapSize._minRowPos) / _rowHeight);
            int col = (int)((colPos - _mapSize._minColPos) / _colWidth);

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

        public int GetNodeNeighborIndex(Node node, int dirRow, int dirCol)
        {
            int index = 0;
            for (int i = 0; i < neighborArr.Length; ++i)
            {
                if (dirRow == neighborArr[i, 0] && dirCol == neighborArr[i, 1])
                {
                    index = i;
                    break;
                }
            }
            return index;
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

        }
    }
}
