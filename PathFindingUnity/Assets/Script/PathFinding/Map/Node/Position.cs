
namespace PathFinding
{
    public struct Position
    {
        // 行坐标
        private float _rowPos;
        // 列坐标
        private float _colPos;

        public Position(float rowPos, float colPos)
        {
            _rowPos = rowPos;
            _colPos = colPos;
        }

        public float RowPos
        {
            get { return _rowPos; }
        }

        public float ColPos
        {
            get { return _colPos; }
        }

        public static Position operator -(Position left, Position right)
        {
            Position p = new Position(left.RowPos - right.RowPos, left.ColPos - right.ColPos);
            return p;
        }

        public static Position operator +(Position left, Position right)
        {
            Position p = new Position(left.RowPos + right.RowPos, left.ColPos + right.ColPos);
            return p;
        }

        public static Position operator *(Position left, float value)
        {
            Position p = new Position(left.RowPos * value, left.ColPos * value);
            return p;
        }

        public static float Dot(Position left, Position right)
        {
            return  left.RowPos * right.RowPos + left.ColPos * right.ColPos;
        }
    }
}