using System;

namespace PathFinding
{
    public class MapQuad : IMap
    {
        private MapTerrainData _mapTerrainData;
        private MapSize _mapSize;
        private Node[] _grid = null;
        private float _width;
        private float _length;

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

        public MapQuad(string mapFile, float minX, float minY, float maxX, float maxY)
        {
            MapType = MapType.Quad;
            _mapTerrainData = new MapTerrainData(mapFile);
            _mapSize = new MapSize(minX, minY, maxX, maxY);
            CreateGrid();
        }

        public MapType MapType { get; set; }

        // 创建网格
        private void CreateGrid()
        {
            maxRow = _mapTerrainData.Row;
            maxCol = _mapTerrainData.Col;

            _width = (_mapSize._maxX - _mapSize._minX) / maxCol;
            _length = (_mapSize._maxY - _mapSize._minY) / maxRow;

            // 使用一维数组存放 node
            _grid = new Node[maxRow * maxCol];

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
            float cost = 0;
            int nodeType = _mapTerrainData.GetNodeData(row, col, ref cost);

            int index = RCToIndex(row, col);
            Node node = new Node(row, col, _neighborCount);
            node.NodeType = (NodeType)nodeType;
            node.Cost = cost;

            float x = _mapSize._minX + (node.Col + 0.5f) * _width;
            float y = _mapSize._maxY - (node.Row + 0.5f) * _length;
            node.Position = new Position(x, y);

            _grid[index] = node;
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
            return _width;
        }

        // 地块 Node 长
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
