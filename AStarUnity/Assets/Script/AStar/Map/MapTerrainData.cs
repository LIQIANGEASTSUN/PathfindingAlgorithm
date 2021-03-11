using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AStar
{
    public class MapTerrainData
    {
        private string _fileName;
        private int _row;
        private int _col;

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

            _row = list.Count;
            _col = 20;
        }

        public int Row
        {
            get { return _row; }
        }

        public int Col
        {
            get { return _col; }
        }

        public int GetNodeData(int row, int col, ref float g)
        {
            string colName = string.Format("col{0}", col);
            string content = TableRead.Instance.GetData(_fileName, row, colName);
            string[] dataArr = content.Split('_');

            int nodeType = int.Parse(dataArr[0]);
            g = float.Parse(dataArr[1]);
            return nodeType;
        }

    }
}
