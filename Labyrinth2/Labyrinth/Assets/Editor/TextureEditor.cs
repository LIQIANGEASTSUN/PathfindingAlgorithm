using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class TextureEditor : Editor
{

    [MenuItem("Window/TextureEditor")]
    public static void TextureEditorFunction()
    {
        Debug.LogError("TextureEditorFunction");

        TextureChange textureChange = new TextureChange();
        for (int i = 0; i < 15; ++i)
        {
            string filePath = string.Format("Assets/Resources/Tile{0}.png", i);
            Texture2D texture2D = (Texture2D)AssetDatabase.LoadAssetAtPath(filePath, typeof(Texture2D));
            Debug.LogError(texture2D.width + "   " + texture2D.height);
            textureChange.WriteColor(i, texture2D);
        }
    }

}
