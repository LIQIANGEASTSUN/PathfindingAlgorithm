using PathFinding;
using UnityEngine;

/// <summary>
/// Debug 下 将地图显示出来
/// </summary>
public class MapToolsDrawNode
{
    public MapToolsDrawNode(IMap map)
    {
        CreateNode(map);
    }

    public void CreateNode(IMap map)
    {
        GameObject parent = new GameObject("NodeParent");
        parent.transform.position = Vector3.zero;
        Node[] nodeArr = map.Grid();
        for (int i = 0; i < nodeArr.Length; ++i)
        {
            Node node = nodeArr[i];
            if (node.NodeType == NodeType.Null)
            {
                continue;
            }
            Position pos = map.NodeToPosition(node);
            GameObject go = GameObject.CreatePrimitive(PrimitiveType.Cube);
            go.name = string.Format("{0}_{1}", node.Row, node.Col);
            go.transform.position = new Vector3(pos.X, 0, pos.Y);
            go.transform.localScale = new Vector3(0.5f, 0.05f, 0.5f); //new Vector3(mapQuad.NodeWidth(), 1, mapQuad.NodeLength()) * 0.9f;
            go.transform.SetParent(parent.transform);

            go.GetComponent<Renderer>().material.color = NodeColor(node.NodeType);
        }
    }

    public Color NodeColor(NodeType nodeType)
    {
        if (nodeType == NodeType.Null)
        {
            return Color.black;
        }

        if (nodeType == NodeType.Smooth)
        {
            return new Color32(230, 230, 230, 255);
        }

        if (nodeType == NodeType.Mud)
        {
            return new Color32(139, 123, 115, 255);
        }

        if (nodeType == NodeType.Grass)
        {
            return new Color32(169, 208, 142, 255);
        }

        if (nodeType == NodeType.Desert)
        {
            return new Color32(255, 230, 153, 255);
        }

        if (nodeType == NodeType.Obstacle)
        {
            return new Color32(198, 89, 17, 255);
        }

        return Color.white;
    }
}
