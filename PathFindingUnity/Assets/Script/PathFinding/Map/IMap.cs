
namespace PathFinding
{
    // 地图类型
    public enum MapType
    {
        /// <summary>
        /// 矩形地图
        /// </summary>
        Quad = 1,
        /// <summary>
        /// 六边形地图
        /// </summary>
        Hex = 2,
    }

    public interface IMap
    {
        // 地图类型
        MapType MapType { get; set; }

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
        Node NodeNeighborWithDistance(Node node, int index, ref float distance);
        Node NodeNeighbor(Node node, int index);
        Node GetNode(int row, int col);

        /// <summary>
        /// 获取 给的行列是节点的第几个邻居
        /// </summary>
        /// <param name="row"></param>
        /// <param name="col"></param>
        /// <returns></returns>
        int GetNodeNeighborIndex(Node node, int dirRow, int dirCol);

        void Update();
    }

    // 地图尺寸：行、列
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
            return _minX <= x && x <= _maxX && _minY <= y && y <= _maxY;
        }
    }
}
