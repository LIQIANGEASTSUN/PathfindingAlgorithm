using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Text;
using UnityEngine.Tilemaps;
using PathFinding;

public class LabyrinthCreate
{
    private Tilemap _tileMap;
    private LabyrinthTexture _labyrinthTexture;

    public LabyrinthCreate()
    {
        _labyrinthTexture = new LabyrinthTexture();
        GetTileMap();
        Create();
    }

    private void GetTileMap()
    {
        GameObject go = GameObject.Find("labyrinthLevel0");
        _tileMap = go.GetComponentInChildren<Tilemap>();
    }

    private void Create()
    {
        int totalRow = GameServer.GetInstance().MapProxy.IMap().TotalRow;
        int totalCol = GameServer.GetInstance().MapProxy.IMap().TotalCol;
        for (int i = 0; i < totalRow; ++i)
        {
            for (int j = 0; j < totalCol; ++j)
            {
                int index = i * totalCol + j;
                Node node = GameServer.GetInstance().MapProxy.IMap().Grid()[index];
                LoadTileAsset(node);
            }
        }
    }

    private void LoadTileAsset(Node node)
    {
        Vector3Int position = GameServer.GetInstance().MapProxy.IMap().NodeToTilePosition(node);
        Tile tile = _tileMap.GetTile<Tile>(position);
        tile.sprite = _labyrinthTexture.SpriteList[node.Flag];
        _tileMap.RefreshTile(position);
    }
}