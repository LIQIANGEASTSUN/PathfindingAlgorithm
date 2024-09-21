using System.Collections.Generic;

namespace PathFinding
{
    /// <summary>
    /// 地图数据，保存在 csv 中的数据
    /// </summary>
    public class MapTerrainData
    {
        private string _fileName;
        private int _maxRow;
        private int _maxCol;

        public MapTerrainData(string fileName)
        {
            _fileName = fileName;
            TableRead.Instance.Init();
            string path = "Assets/StreamingAssets";
            TableRead.Instance.ReadCustomPath(path);

            List<int> list = TableRead.Instance.GetKeyList(_fileName);
            list.Sort((a, b) =>
            {
                return a - b;
            });

            _maxRow = list.Count;

            if (list.Count > 0)
            {
                _maxCol = int.Parse(TableRead.Instance.GetData(_fileName, list[0], "ColCount")); 
            }
        }

        public int MaxRow
        {
            get { return _maxRow; }
        }

        public int MaxCol
        {
            get { return _maxCol; }
        }

        /// <summary>
        /// 获取节点类型和不同地形的消耗
        /// csv 中每一项格式  1_5: 1 表示平坦路，5表示走平坦路消耗
        /// </summary>
        /// <param name="row"></param>
        /// <param name="col"></param>
        /// <param name="g"></param>
        /// <returns></returns>
        public int GetNodeData(int row, int col, ref float g)
        {
            // 地图中 行是从下到上 依次递增
            // Excel 中行是从 上到下 依次递增，所以转换一下
            row = MaxRow - row - 1;
            // 地图中 列是从左到右 依次递增
            string colName = string.Format("col{0}", col);
            string content = TableRead.Instance.GetData(_fileName, row, colName);
            string[] dataArr = content.Split('_');

            int nodeType = int.Parse(dataArr[0]);
            g = float.Parse(dataArr[1]);
            return nodeType;
        }

    }
}
