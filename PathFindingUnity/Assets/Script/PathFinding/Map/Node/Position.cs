
namespace PathFinding
{
    public struct Position
    {
        private float _x;
        private float _y;

        public Position(float x, float y)
        {
            _x = x;
            _y = y;
        }

        public float X
        {
            get { return _x; }
        }

        public float Y
        {
            get { return _y; }
        }
        public static Position operator -(Position left, Position right)
        {
            Position p = new Position(left.X - right.X, left.Y - right.Y);
            return p;
        }
        public static Position operator +(Position left, Position right)
        {
            Position p = new Position(left.X + right.X, left.Y + right.Y);
            return p;
        }

        public static Position operator *(Position left, float value)
        {
            Position p = new Position(left.X * value, left.Y * value);
            return p;
        }

        public static float Dot(Position left, Position right)
        {
            return left.X * right.X + left.Y * right.Y;
        }
    }
}