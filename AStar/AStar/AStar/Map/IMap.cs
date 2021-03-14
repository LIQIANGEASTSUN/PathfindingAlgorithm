using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AStar.AStar
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
        /// 根据 Node index 获取 坐标
        /// </summary>
        /// <param name="row"></param>
        /// <param name="col"></param>
        /// <returns></returns>
        Position RCToPosition(int index);

        /// <summary>
        /// 获取 Node 的第 index 个邻居
        /// </summary>
        Node NodeAdjoin(Node node, int index);
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
