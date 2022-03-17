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
    private MapDataBase _mapDataBase;

    public void Init()
    {
        _labyrinthTexture = new LabyrinthTexture();
        //_mapDataBase = new MapDataPlanA("labyrinth1");
        _mapDataBase = new MapDataPlanB("labyrinth2");

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
        int totalRow = _mapDataBase.TotalRow;
        int totalCol = _mapDataBase.TotalCol;
        for (int i = 0; i < totalRow; ++i)
        {
            for (int j = 0; j < totalCol; ++j)
            {
                int index = i * totalCol + j;
                Node node = _mapDataBase.Grid()[index];
                LoadTileAsset(node);
            }
        }
    }

    private void LoadTileAsset(Node node)
    {
        Position position = _mapDataBase.NodeToPosition(node);
        Vector3Int pos = new Vector3Int((int)position.X, (int)position.Y, 0);
        Tile tile = _tileMap.GetTile<Tile>(pos);
        tile.sprite = _labyrinthTexture.SpriteList[node.Flag];
        _tileMap.RefreshTile(pos);
    }

    public MapDataBase MapDataBase
    {
        get { return _mapDataBase; }
    }
}
