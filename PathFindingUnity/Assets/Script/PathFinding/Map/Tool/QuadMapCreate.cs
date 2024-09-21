using PathFinding;

public class QuadMapCreate
{

    public static IMap CreateQuad(string mapFile, float minRowPos, float minColPos, float maxRowPos, float maxColPos)
    {
         MapTerrainData _mapTerrainData;
        _mapTerrainData = new MapTerrainData(mapFile);

        int maxRow = _mapTerrainData.MaxRow;
        int maxCol = _mapTerrainData.MaxCol;

        float rowHeight = (maxRowPos - minRowPos) / maxRow;
        float colWidth = (maxColPos - minColPos) / maxCol;

        MapQuad mapQuad = new MapQuad(minRowPos, minColPos, maxRowPos, maxColPos, rowHeight, colWidth);

        Node[] nodeArr = mapQuad.Grid();
        foreach(var node in nodeArr)
        {
            float cost = 0;
            int nodeType = _mapTerrainData.GetNodeData(node.Row, node.Col, ref cost);
            node.NodeType = (NodeType)nodeType;
            node.Cost = cost;

            mapQuad.NodeToPosition(node.Row, node.Col);
        }

        return mapQuad;
    }
}
