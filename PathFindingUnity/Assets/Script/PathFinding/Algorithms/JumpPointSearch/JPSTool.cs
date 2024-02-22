using System;

namespace PathFinding
{
    public class JPSTool
    {
        /// <summary>
        /// 搜索方向
        /// </summary>
        public static int Dir(int v1, int v2)
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
        /// 节点是否有强制邻居
        /// </summary>
        public static bool HasForceNeighbour(IMap _map, Node preNode, Node node)
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
            node.ForceNeighbourList.Clear();
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
        private static bool CheckHVForceNeighbour(IMap _map, Node node, float dirX, float dirY, int sign)
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
        private static bool CheckDiagonalForceNeighbour(IMap _map, Node node, float dirX, float dirY, int sign)
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