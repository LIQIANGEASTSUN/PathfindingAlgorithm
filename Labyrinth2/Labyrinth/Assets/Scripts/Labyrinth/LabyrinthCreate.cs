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
    private MapData _mapData;

    public void Init()
    {
        _labyrinthTexture = new LabyrinthTexture();
        //_mapDataBase = new MapDataPlanA("labyrinth1");
        _mapData = new MapData("labyrinth2");

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
        int totalRow = _mapData.TotalRow;
        int totalCol = _mapData.TotalCol;
        for (int i = 0; i < totalRow; ++i)
        {
            for (int j = 0; j < totalCol; ++j)
            {
                int index = i * totalCol + j;
                Node node = _mapData.Grid()[index];
                LoadTileAsset(node);
            }
        }
    }

    private void LoadTileAsset(Node node)
    {
        Vector3Int position = _mapData.NodeToTilePosition(node);
        Tile tile = _tileMap.GetTile<Tile>(position);
        tile.sprite = _labyrinthTexture.SpriteList[node.Flag];
        _tileMap.RefreshTile(position);
    }

    public MapData MapData
    {
        get { return _mapData; }
    }
}
