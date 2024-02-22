﻿using System;

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

            Position dir = new Position(Dir(node.Row, preNode.Row), Dir(node.Col, preNode.Col));
            node.ForceNeighbourList.Clear();
            // 横、纵 方向
            if (dir.X == 0 || dir.Y == 0)
            {
                bool result1 = CheckHVForceNeighbour(_map, node, dir, 1);
                bool result2 = CheckHVForceNeighbour(_map, node, dir, -1);
                return result1 || result2;
            }
            else // 对角/斜向
            {
                bool result1 = CheckDiagonalForceNeighbour(_map, node, dir, 1);
                bool result2 = CheckDiagonalForceNeighbour(_map, node, dir, -1);
                return result1 || result2;
            }
        }

        // 判断水平、垂直方向(水平向右、水平向左、竖直向上、竖直向下)的强制邻居
        private static bool CheckHVForceNeighbour(IMap _map, Node node, Position dir, int sign)
        {
            Position obstacleDir = new Position(Math.Abs(dir.Y) * sign, Math.Abs(dir.X) * sign);
            Position obstacleNodePos = new Position(node.Row, node.Col) + obstacleDir;
            Position neighbourPos = obstacleNodePos + dir;

            Node obstacleNode = _map.GetNode((int)obstacleNodePos.X, (int)obstacleNodePos.Y);
            Node neighbourNode = _map.GetNode((int)neighbourPos.X, (int)neighbourPos.Y);

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
        private static bool CheckDiagonalForceNeighbour(IMap _map, Node node, Position dir, int sign)
        {
            Position prePos = new Position(node.Row, node.Col) - dir;
            Position obstacleDir;
            Position neighbourDir;
            if (sign == 1)
            {
                obstacleDir = new Position(dir.X, 0);
                neighbourDir = new Position(dir.X, 0);
            }
            else
            {
                obstacleDir = new Position(0, dir.Y);
                neighbourDir = new Position(0, dir.Y);
            }

            Position obstacleNodePos = prePos + obstacleDir;
            Position neighbourPos = obstacleNodePos + neighbourDir;

            Node obstacleNode = _map.GetNode((int)obstacleNodePos.X, (int)obstacleNodePos.Y);
            Node neighbourNode = _map.GetNode((int)neighbourPos.X, (int)neighbourPos.Y);

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