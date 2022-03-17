using System.Collections.Generic;
using UnityEngine;

public class GLDrawArea : MonoBehaviour {

    private void OnEnable()
    {
        CreateLineMaterial();
    }

    private Material lineMaterial;
    private void CreateLineMaterial()
    {
        if (!lineMaterial)
        {
            // Unity has a built-in shader that is useful for drawing
            // simple colored things.
            Shader shader = Shader.Find("Hidden/Internal-Colored");
            lineMaterial = new Material(shader);
            lineMaterial.hideFlags = HideFlags.HideAndDontSave;
            // Turn on alpha blending
            lineMaterial.SetInt("_SrcBlend", (int)UnityEngine.Rendering.BlendMode.SrcAlpha);
            lineMaterial.SetInt("_DstBlend", (int)UnityEngine.Rendering.BlendMode.OneMinusSrcAlpha);
            // Turn backface culling off
            lineMaterial.SetInt("_Cull", (int)UnityEngine.Rendering.CullMode.Off);
            // Turn off depth writes
            lineMaterial.SetInt("_ZWrite", 0);
        }
    }

    private List<KeyValuePair<Rect, Color>> drawAreaList = new List<KeyValuePair<Rect, Color>>();

    public void AddDreaArea(Rect rect, Color color)
    {
        KeyValuePair<Rect, Color> kv = new KeyValuePair<Rect, Color>(rect, color);
        drawAreaList.Add(kv);
    }

    void OnPostRender()
    {
        for (int i = 0; i < drawAreaList.Count; ++i)
        {
            KeyValuePair<Rect, Color> kv = drawAreaList[i];
            DrawRect(kv.Key, kv.Value);
        }
    }

    private void DrawRect(Rect rect, Color color)
    {
        if (!lineMaterial)
            return;
        GL.PushMatrix();//保存摄像机变换矩阵
        lineMaterial.SetPass(0);

        GL.LoadPixelMatrix();//设置用屏幕坐标绘图

        float startX = rect.x;
        float startY = rect.y;
        float endX = rect.xMax;
        float endY = rect.yMax;

        GL.Begin(GL.LINES);
        GL.Color(color);//设置方框的边框颜色 边框不透明

        GL.Vertex3(startX, startY, 0);
        GL.Vertex3(endX, startY, 0);

        GL.Vertex3(endX, startY, 0);
        GL.Vertex3(endX, endY, 0);

        GL.Vertex3(endX, endY, 0);
        GL.Vertex3(startX, endY, 0);

        GL.Vertex3(startX, endY, 0);
        GL.Vertex3(startX, startY, 0);

        GL.End();
        GL.PopMatrix();//恢复摄像机投影矩阵
    }
}
