using System;

namespace PathFinding
{
    public class JPSTool
    {
        // 地图数据
        private IMap map;
        // 起点
        private Node originNode = null;
        // 终点
        private Node desitinationNode = null;
        public JPSTool() {
        
        }

        public void SetMap(IMap map)
        {
            this.map = map;
        }

        public void SetNode(Node originNode, Node desitinationNode)
        {
            this.originNode = originNode;
            this.desitinationNode = desitinationNode;
        }

        /// <summary>
        /// 搜索方向
        /// </summary>
        public int Dir(int v1, int v2)
        {
            int value = v1 - v2;
            if (value > 0)
            {
                return 1;
            }
            else if (value == 0)
            {
                return 0;
            }
            return -1;
        }

        /// <summary>
        /// 节点是否跳跃点
        /// </summary>
        public Node IsJumpPoint(Node preNode, Node node, int rowDir, int colDir)
        {
            if (!InvalidNode(node))
            {
                return null;
            }

            //一： 如果 node 是起点/终点,则 node 是跳点
            if (IsSameNode(node, originNode) || IsSameNode(node, desitinationNode))
            {
                return node;
            }

            //二： 如果 node 至少有一个强迫邻居,则 node 是跳点
            if (HasForceNeighbour(map, preNode, node))
            {
                return node;
            }

            if (rowDir == 0 || colDir == 0)
            {
                return null;
            }

            // 如果父节点在斜方向上(意味着这是斜向搜索)
            // 节点 node 的水平或者垂直方向上有满足条件 一、二的点,则节点也是跳跃点
            Node jumpNode = JumpSearchHV(node, rowDir, 0);
            if (null != jumpNode)
            {
                return jumpNode;
            }
            jumpNode = JumpSearchHV(node, 0, colDir);
            return jumpNode;
        }

        public bool InvalidNode(Node node)
        {
            if (null == node || node.NodeState == NodeState.InColsedTable || node.NodeType == NodeType.Null || node.NodeType == NodeType.Obstacle)
            {
                return false;
            }
            return true;
        }

        /// <summary>
        /// 判断相同节点
        /// </summary>
        public bool IsSameNode(Node left, Node right)
        {
            if (null == left || null == right)
            {
                return false;
            }
            return left.Row == right.Row && left.Col == right.Col;
        }

        /// <summary>
        /// 横向、竖向 跳跃搜索
        /// rowDir 和 colDir 必须有且只有一个为 0
        /// </summary>
        public Node JumpSearchHV(Node node, int rowDir, int colDir)
        {
            if (rowDir != 0 && colDir != 0)
            {
                return null;
            }
            int row = node.Row;
            int col = node.Col;
            while (true)
            {
                row += rowDir;
                col += colDir;
                Node temp = map.GetNode(row, col);
                if (!InvalidNode(temp))
                {
                    break;
                }

                if (null != IsJumpPoint(node, temp, rowDir, colDir))
                {
                    return temp;
                }
            }
            return null;
        }


        /// <summary>
        /// 节点是否有强制邻居
        /// </summary>
        public bool HasForceNeighbour(IMap _map, Node preNode, Node node)
        {
            if (null == preNode || null == node)
            {
                return false;
            }

            if (node.NodeType == NodeType.Null || node.NodeType == NodeType.Obstacle)
            {
                return false;
            }

            int dirX = Dir(node.Row, preNode.Row);
            int dirY = Dir(node.Col, preNode.Col);
            //node.ForceNeighbourList.Clear();
            // 横、纵 方向
            if (dirX == 0 || dirY == 0)
            {
                bool result1 = CheckHVForceNeighbour(_map, node, dirX, dirY, 1);
                bool result2 = CheckHVForceNeighbour(_map, node, dirX, dirY, -1);
                return result1 || result2;
            }
            else // 对角/斜向
            {
                bool result1 = CheckDiagonalForceNeighbour(_map, node, dirX, dirY, 1);
                bool result2 = CheckDiagonalForceNeighbour(_map, node, dirX, dirY, -1);
                return result1 || result2;
            }
        }

        // 判断水平、垂直方向(水平向右、水平向左、竖直向上、竖直向下)的强制邻居
        private bool CheckHVForceNeighbour(IMap _map, Node node, float dirX, float dirY, int sign)
        {
            float obstacleNodePosX = node.Row + Math.Abs(dirY) * sign;
            float obstacleNodePosY = node.Col + Math.Abs(dirX) * sign;
            float neighbourPosX = obstacleNodePosX + dirX;
            float neighbourPosY = obstacleNodePosY + dirY;

            Node obstacleNode = _map.GetNode((int)obstacleNodePosX, (int)obstacleNodePosY);
            Node neighbourNode = _map.GetNode((int)neighbourPosX, (int)neighbourPosY);

            if (null == neighbourNode || neighbourNode.NodeType == NodeType.Null || neighbourNode.NodeType == NodeType.Obstacle)
            {
                return false;
            }

            if (null == obstacleNode || obstacleNode.NodeType == NodeType.Null || obstacleNode.NodeType == NodeType.Obstacle)
            {
                node.ForceNeighbourList.Add(neighbourNode);
                return true;
            }

            return false;
        }

        // 判断斜向(左上、左下、右上、右下)的强制邻居
        private bool CheckDiagonalForceNeighbour(IMap _map, Node node, float dirX, float dirY, int sign)
        {
            float obstacleDirX = 0;
            float obstacleDirY = 0;
            float neighbourDirX = 0;
            float neighbourDirY = 0;
            if (sign == 1)
            {
                obstacleDirX = dirX;
                neighbourDirX = dirX;
            }
            else
            {
                obstacleDirY = dirY;
                neighbourDirY = dirY;
            }

            float obstacleNodePosX = (node.Row - dirX) + obstacleDirX;
            float obstacleNodePosY = (node.Col - dirY) + obstacleDirY;
            float neighbourPosX = obstacleNodePosX + neighbourDirX;
            float neighbourPosY = obstacleNodePosY + neighbourDirY;

            Node obstacleNode = _map.GetNode((int)obstacleNodePosX, (int)obstacleNodePosY);
            Node neighbourNode = _map.GetNode((int)neighbourPosX, (int)neighbourPosY);

            if (null == neighbourNode || neighbourNode.NodeType == NodeType.Null || neighbourNode.NodeType == NodeType.Obstacle)
            {
                return false;
            }

            if (null == obstacleNode || obstacleNode.NodeType == NodeType.Null || obstacleNode.NodeType == NodeType.Obstacle)
            {
                node.ForceNeighbourList.Add(neighbourNode);
                return true;
            }

            return false;
        }
    }
}