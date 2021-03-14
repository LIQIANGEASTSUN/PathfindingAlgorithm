using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AStar.AStar
{
    public class MapQuad : IMap
    {
        private MapSize _mapSize;
        private Node[] _grid = null;
        private float _width;
        private float _length;

        private int _row;
        private int _col;

        private const int _adjoinCount = 8;
        private int[,] adjoinArr = new int[,] {
            {-1,  1}, { 0,  1}, { 1,  1},
            {-1,  0},           { 1,  0},
            {-1, -1}, { 0, -1}, { 1, -1}
        };

        public MapQuad(float minX, float minY, float maxX, float maxY, float width, float length)
        {
            _mapSize = new MapSize(minX, minY, maxX, maxY);
            _width = width;
            _length = length;
        }

        public void CreateGrid()
        {
            _row = (int)Math.Ceiling((_mapSize._maxX - _mapSize._minX) / _width);
            _col = (int)Math.Ceiling((_mapSize._maxY - _mapSize._minY) / _length);

            _grid = new Node[_row * _col];

            for (int i = 0; i < _row; ++i)
            {
                for (int j = 0; j < _col; ++j)
                {
                    int index = RCToIndex(i, j);
                    _grid[index] = new Node(i, j, _adjoinCount);
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

        public Node PositionToRC(float x, float y)
        {
            if (!_mapSize.Contians(x, y))
            {
                return null;
            }
            int row = (int)Math.Ceiling((x - _mapSize._minX) / _width);
            int col = (int)Math.Ceiling((y - _mapSize._minY) / _width);

            int index = RCToIndex(row, col);
            return _grid[index];
        }

        public Position RCToPosition(int index)
        {
            if (index < 0 || index >= _grid.Length)
            {
                return new Position(0, 0);
            }

            int row = index / _col;
            int col = index % _col;
            float x = _mapSize._minX + row * _width;
            float y = _mapSize._minY + col * _width;
            return new Position(x, y);
        }

        private int RCToIndex(int row, int col)
        {
            int index = row * _col + col;
            return index;
        }

        private Node NodeAdjoin(Node node, int index)
        {
            int row = node.Row + adjoinArr[index, 0];
            int col = node.Col + adjoinArr[index, 1];

            index = RCToIndex(row, col);
            if (index < 0 || index >= _grid.Length)
            {
                return null;
            }
            return _grid[index];
        }
    }
}
