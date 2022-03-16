using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LabyrinthTexture : MonoBehaviour
{
    public static LabyrinthTexture labyrinthTexture;
    private List<Texture2D> textureList = new List<Texture2D>();
    // Start is called before the first frame update
    void Start()
    {
        labyrinthTexture = this;

        TextureChange textureChange = new TextureChange();
        for (int i = 0; i < 15; ++i)
        {
            //string filePath = string.Format("Assets/Resources/Tile{0}.png", i);
            string filePath = string.Format("Tile{0}.png", i);
            Texture2D texture2D = Resources.Load<Texture2D>(filePath);
            textureChange.WriteColor(i, texture2D);
            textureList.Add(texture2D);
        }
    }

    public List<Texture2D> TextureList
    {
        get { return textureList; }
    }
    
}
