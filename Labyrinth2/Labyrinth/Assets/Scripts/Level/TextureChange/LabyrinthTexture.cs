﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LabyrinthTexture
{
    private List<Sprite> _spriteList = new List<Sprite>();
    // Start is called before the first frame update
    public LabyrinthTexture()
    {
        TextureChange textureChange = new TextureChange();
        for (int i = 0; i < 16; ++i)
        {
            //string filePath = string.Format("Assets/Resources/Tile{0}.png", i);
            string filePath = string.Format("Tile{0}", i);
            Texture2D texture2D = ResourcesManager.GetInstance().Load<Texture2D>(filePath);
            textureChange.WriteColor(i, texture2D);
            Sprite sprite = TextureToSprite(texture2D);
            _spriteList.Add(sprite);
        }
    }

    private Sprite TextureToSprite(Texture2D texture2D)
    {
        Sprite sprite = Sprite.Create(texture2D, new Rect(0, 0, texture2D.width, texture2D.height), Vector2.zero);
        return sprite;
    }

    public List<Sprite> SpriteList
    {
        get { return _spriteList; }
    }

    public void Release()
    {
        _spriteList.Clear();
    }

}
