using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AStar
{
    public class MapQuad : IMap
    {
        private MapTerrainData _mapTerrainData;
        private MapSize _mapSize;
        private Node[] _grid = null;
        private float _width;
        private float _length;

        private int _row;
        private int _col;

        private const int _neighborCount = 8;
        private int[,] neighborArr = new int[,] {
            {-1,  1}, { 0,  1}, { 1,  1},
            {-1,  0},           { 1,  0},
            {-1, -1}, { 0, -1}, { 1, -1}
        };

        public MapQuad(string mapFile, float minX, float minY, float maxX, float maxY)
        {
            _mapTerrainData = new MapTerrainData(mapFile);
            _mapSize = new MapSize(minX, minY, maxX, maxY);
        }

        public void CreateGrid()
        {
            _row = _mapTerrainData.Row;
            _col = _mapTerrainData.Col;

            _width = (_mapSize._maxX - _mapSize._minX) / _col;
            _length = (_mapSize._maxY - _mapSize._minY) / _row;

            _grid = new Node[_row * _col];

            for (int i = 0; i < _row; ++i)
            {
                for (int j = 0; j < _col; ++j)
                {
                    float cost = 0;
                    int nodeType = _mapTerrainData.GetNodeData(i, j, ref cost);

                    int index = RCToIndex(i, j);
                    Node node = new Node(i, j, _neighborCount);
                    node.NodeType = (NodeType)nodeType;
                    node.SetCost(cost);
                    _grid[index] = node;
                   
                }
            }
        }

        public Node[] Grid()
        {
            return _grid;
        }

        public MapSize MapSize()
        {
            return _mapSize;
        }

        public float NodeWidth()
        {
            return _width;
        }

        public float NodeLength()
        {
            return _length;
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

            int row = (int)((_mapSize._maxY - y) / _length);
            int col = (int)((x - _mapSize._minX) / _width);

            int index = RCToIndex(row, col);
            return _grid[index];
        }

        /// <summary>
        /// 根据 Node 获取坐标
        /// </summary>
        public Position NodeToPosition(Node node)
        {
            float x = _mapSize._minX + (node.Col + 0.5f) * _width;
            float y = _mapSize._maxY - (node.Row + 0.5f) * _length;
            return new Position(x, y);
        }

        /// <summary>
        /// 获取 Node 的第 index 个邻居
        /// </summary>
        public Node NodeNeighbor(Node node, int index)
        {
            int row = node.Row + neighborArr[index, 0];
            int col = node.Col + neighborArr[index, 1];

            index = RCToIndex(row, col);
            if (index < 0 || index >= _grid.Length)
            {
                return null;
            }
            return _grid[index];
        }

        private int RCToIndex(int row, int col)
        {
            int index = row * _col + col;
            return index;
        }

        public float G(NodeType nodeType)
        {
            if (nodeType == NodeType.Smooth)
            {
                return 1;
            }
            if (nodeType == NodeType.Mud)
            {
                return 2;
            }
            if (nodeType == NodeType.Grass)
            {
                return 3;
            }
            if (nodeType == NodeType.Desert)
            {
                return 4;
            }
            if (nodeType == NodeType.Obstacle)
            {
                return float.MaxValue;
            }

            return 0;
        }
    }
}
