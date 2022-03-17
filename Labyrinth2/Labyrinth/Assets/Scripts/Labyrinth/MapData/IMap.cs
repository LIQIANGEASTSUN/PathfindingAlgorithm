
namespace PathFinding
{
    public interface IMap
    {
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
        public int _minX;
        public int _minY;
        public int _maxX;
        public int _maxY;

        public MapSize(int minX, int minY, int maxX, int maxY)
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
