
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
        Hex = 5,
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
        Node PositionToNode(float rowPos, float colPos);

        /// <summary>
        /// 计算 节点坐标
        /// </summary>
        /// <param name="row"></param>
        /// <param name="col"></param>
        /// <returns></returns>
        Position NodeToPosition(int row, int col);

        /// <summary>
        /// 根据 Node 获取坐标
        /// </summary>
        Position NodeToPosition(Node node);

        /// <summary>
        /// 获取 Node 的第 index 个邻居
        /// </summary>
        Node NodeNeighborWithDistance(Node node, int index, ref float distance);

        /// <summary>
        /// 获取节点的 第 index 个邻居
        /// </summary>
        /// <param name="node"></param>
        /// <param name="index">第 index 个邻居</param>
        /// <returns></returns>
        Node NodeNeighbor(Node node, int index);

        /// <summary>
        /// 获取节点
        /// </summary>
        /// <param name="row"></param>
        /// <param name="col"></param>
        /// <returns></returns>
        Node GetNode(int row, int col);

        /// <summary>
        /// 获取给定的行列方向，是节点的第几个邻居
        /// </summary>
        /// <param name="dirRow"></param>
        /// <param name="dirCol"></param>
        /// <returns></returns>
        int GetNodeNeighborIndex(Node node, int dirRow, int dirCol);

        void Update();
    }

    // 地图尺寸：行、列
    public struct MapSize
    {
        public float _minColPos;
        public float _minRowPos;
        public float _maxColPos;
        public float _maxRowPos;

        /// <summary>
        /// 行列坐标最大值最小值根据自己需求定义
        /// 比如：
        /// (1)在 X、Z 平面上创建地图，可以使用 X 坐标计算 列，Z 坐标计算 行，地图最小行列位置为 (X = 10, Z = 10)，最大行列位置为 (X = 30，Z = 30) 
        /// (2)在 X、Y 平面上创建地图，可以使用 X 坐标计算 列，Y 坐标计算 行，地图最小行列位置为 (X = 10, Y = 10)，最大行列位置为 (X = 30，Y = 30) 
        /// </summary>
        /// <param name="minRowPos">行最小的坐标值</param>
        /// <param name="minColPos">列做小的坐标值</param>
        /// <param name="maxRowPos">行最大的坐标值</param>
        /// <param name="maxColPos">列最大的坐标值</param>
        public MapSize(float minRowPos, float minColPos, float maxRowPos, float maxColPos)
        {
            _minRowPos = minRowPos;
            _minColPos = minColPos;
            _maxRowPos = maxRowPos;
            _maxColPos = maxColPos;
        }

        public bool Contians(float rowPos, float colPos)
        {
            return _minColPos <= colPos && colPos <= _maxColPos && _minRowPos <= rowPos && rowPos <= _maxRowPos;
        }
    }
}
