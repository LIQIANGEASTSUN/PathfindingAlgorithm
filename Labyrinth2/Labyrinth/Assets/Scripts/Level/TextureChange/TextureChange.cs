using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TextureChange
{
    private int borderWidth = 6;

    public void WriteColor(int index, Texture2D texture2D)
    {
        WriteUp(index, texture2D);
        WriteDown(index, texture2D);
        WriteLeft(index, texture2D);
        WriteRight(index, texture2D);
        texture2D.Apply();
    }

    private void WriteUp(int index, Texture2D texture2D)
    {
        if ((index & 1) == 0)
        {
            return;
        }

        Write(0, texture2D.width, texture2D.height - borderWidth, texture2D.height, texture2D);
    }

    private void WriteDown(int index, Texture2D texture2D)
    {
        if ((index & 2) == 0)
        {
            return;
        }
        Write(0, texture2D.width, 0, borderWidth, texture2D);
    }

    private void WriteLeft(int index, Texture2D texture2D)
    {
        if ((index & 4) == 0)
        {
            return;
        }
        Write(0, borderWidth, 0, texture2D.height, texture2D);
    }

    private void WriteRight(int index, Texture2D texture2D)
    {
        if ((index & 8) == 0)
        {
            return;
        }
        Write(texture2D.width - borderWidth, texture2D.width, 0, texture2D.height, texture2D);
    }

    private void Write(int startX, int endX, int startY, int endY, Texture2D texture2D)
    {
        for (int i = startX; i < endX; ++i)
        {
            for (int j = startY; j < endY; ++j)
            {
                texture2D.SetPixel(i, j, Color.white);
            }
        }
    }
}
