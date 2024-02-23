
using System;
using System.Collections.Generic;
using System.Diagnostics;

namespace PathFinding
{
    /// <summary>
    /// Jps+ 地图预处理
    /// </summary>
    public class JPSPlusPreproccess
    {
        private IMap map = null;
        private JPSTool jpsTool = new JPSTool();
        private bool isPreprocess = false;
        public JPSPlusPreproccess()
        {
        }

        public void SetMap(IMap map)
        {
            this.map = map;
            jpsTool.SetMap(map);
        }

        public bool IsPreprocess
        {
            get { return isPreprocess; }
            private set { isPreprocess = value; }
        }

        /// <summary>
        /// 预处理地图
        /// </summary>
        public void Preprocess()
        {
            IsPreprocess = true;

            Node[] grid = map.Grid();
            foreach(var node in grid) {
                //if (node.Row == 8 && node.Col == 2)
                {
                    //UnityEngine.Debug.LogError("测试");
                    PreprocessNode(node);
                }
            }
        }

        private void PreprocessNode(Node node)
        {
            for (int i = 0; i < node.neighborCount; i ++)
            {
                Node temp = map.NodeNeighbor(node, i);
                if(!SearchJumpNode(node, temp, i))
                {
                    SearchInvalid(node, temp, i);
                }
            }
        }

        /// <summary>
        /// 节点按照各个方向查找 跳跃点
        /// </summary>
        /// <param name="currentNode"></param>
        /// <param name="temp"></param>
        /// <param name="index"></param>
        private bool SearchJumpNode(Node currentNode, Node temp, int index)
        {
            bool hasJump = false;
            if (null == temp)
            {
                return false;
            }

            int horizontalDir = jpsTool.Dir(temp.Row, currentNode.Row);
            int verticalDir = jpsTool.Dir(temp.Col, currentNode.Col);
            Node preNode = currentNode;
            while (true)
            {
                if (!jpsTool.InvalidNode(temp))
                {
                    break;
                }

                if (null != jpsTool.IsJumpPoint(preNode, temp, horizontalDir, verticalDir))
                {
                    int offsetX = temp.Row - currentNode.Row;
                    int offsetY = temp.Col - currentNode.Col;
                    int step = (offsetX != 0) ? Math.Abs(offsetX) : Math.Abs(offsetY);
                    currentNode.JpsPlus[index] = step;

                    UnityEngine.Debug.LogError(currentNode.Row + "   " + currentNode.Col + "   index:" + index + "   step:" + step);
                    hasJump = true;
                    break;
                }

                preNode = temp;
                temp = map.GetNode(temp.Row + horizontalDir, temp.Col + verticalDir);
            }

            return hasJump;
        }

        /// <summary>
        /// 搜索墙、无效地块、地图便捷等
        /// </summary>
        /// <param name="currentNode"></param>
        /// <param name="temp"></param>
        /// <param name="index"></param>
        private void SearchInvalid(Node currentNode, Node temp, int index)
        {
            if (null == temp)
            {
                currentNode.JpsPlus[index] = 1;
                return;
            }

            int horizontalDir = jpsTool.Dir(temp.Row, currentNode.Row);
            int verticalDir = jpsTool.Dir(temp.Col, currentNode.Col);
            int step = 1;
            while (true)
            {
                if (null == temp || temp.NodeType == NodeType.Null || temp.NodeType == NodeType.Obstacle)
                {
                    currentNode.JpsPlus[index] = (step - 1) * -1;
                    break;
                }

                ++step;
                int row = currentNode.Row + horizontalDir * step;
                int col = currentNode.Col + verticalDir * step;
                temp = map.GetNode(row, col);
            }
        }
    }
}