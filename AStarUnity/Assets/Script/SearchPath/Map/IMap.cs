using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AStar
{
    public interface IMap
    {
        void CreateGrid();

        Node[] Grid();

        MapSize MapSize();

        /// <summary>
        /// 根据坐标获取 Node
        /// </summary>
        Node PositionToNode(float x, float y);

        /// <summary>
        /// 根据 Node 获取坐标
        /// </summary>
        Position NodeToPosition(Node node);

        /// <summary>
        /// 获取 Node 的第 index 个邻居
        /// </summary>
        Node NodeNeighbor(Node node, int index, ref float distance);
        Node NodeNeighbor(Node node, int index);
        Node GetNode(int row, int col);
    }

    public struct MapSize
    {
        public float _minX;
        public float _minY;
        public float _maxX;
        public float _maxY;

        public MapSize(float minX, float minY, float maxX, float maxY)
        {
            _minX = minX;
            _minY = minY;
            _maxX = maxX;
            _maxY = maxY;
        }

        public bool Contians(float x, float y)
        {
            return _minX < x && x < _maxX && _minY < y && y < _maxY;
        }
    }
}
