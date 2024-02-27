using System;

namespace PathFinding
{
    /// <summary>
    /// Jps+ 地图预处理
    /// 用 8 个数值，分别记录节点八个方向上:跳点、墙（障碍、边界）的距离，如下所示
    ///    2、3、0
    ///   -3、N、5
    ///   -4、0、3
    /// 预处理
    /// 第一步：对每个节点的八个方向进行跳点的可达性判断，并记录好跳点直线可达性
    /// 水平、垂直方向 距离 n 步 是跳点，则此方向记录 abs(n)，如果没有跳点记录 0
    /// 斜向 距离 (n, n) 的节点是跳点，则此方向记录 abs(n)，如果没有跳点记录 0
    /// 
    /// 第二步：对节点的八个方向上，记录值还是 0 的方向上移动1步后碰到障碍（或边界）则记为0，
    /// 如果移动 n+1 步后会碰到障碍（或边界）的数据记为负数距离 -n
    /// 
    /// 
    /// 
    /// 做好了地图的预处理之后，我们就可以使用JPS+算法了。
    /// 大致思路与JPS算法相同，不过这次有了预处理的数据，我们可以更快的进行直线搜索和斜向搜索。

    /// 在某个搜索方向上有：
    /// 1.对于正数距离 n（意味着距离跳点 n 格），我们可以直接将n步远的节点作为跳点添加进openlist
    /// 2.对于0距离（意味着一步都不可移动），我们无需在该方向搜索；
    /// 3.对于负数距离 -n（意味着距离边界或障碍 n 格），我们直接将n步远的节点进行一次跳点判断（有可能满足跳点的三个条件，不过得益于预处理的数据，这步也可以很快完成）。
    /// 
    /// 
    /// JPS+ 还没有完成，不能使用
    /// 需要添加 Goal Bounding 辅助
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