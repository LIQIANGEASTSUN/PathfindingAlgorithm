using System;

namespace PathFinding
{
    public class JPSTool
    {
        /// <summary>
        /// 节点是否有强制邻居
        /// </summary>
        public static bool HasForceNeighbour(IMap _map, Node node, Position dir)
        {
            if (null == node || node.NodeType == NodeType.Null || node.NodeType == NodeType.Obstacle)
            {
                return false;
            }

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
                Position pos = _map.NodeToPosition(neighbourNode);
                node.ForceNeighbourList.Add(pos);
                return true;
            }

            return false;
        }

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
                Position pos = _map.NodeToPosition(neighbourNode);
                node.ForceNeighbourList.Add(pos);
                return true;
            }

            return false;
        }
    }
}
