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
    }

    public void Init()
    {
        _labyrinthTexture = new LabyrinthTexture();
        GetTileMap();
        Create();
    }

    private void GetTileMap()
    {
        int levelId = GameServer.GetInstance().LevelProxy.LevelId();
        string tileMapPrefab = TableDatas.GetData("level", levelId.ToString(), "TileMapPrefab");
        GameObject go = ResourcesManager.GetInstance().Load<GameObject>(tileMapPrefab);
        GameObject tileMapGo = GameObject.Instantiate(go);
        tileMapGo.transform.localScale = Vector3.one;
        tileMapGo.transform.position = Vector3.zero;
        tileMapGo.transform.rotation = Quaternion.identity;
        _tileMap = tileMapGo.GetComponentInChildren<Tilemap>();

        TilemapRenderer tileMapRenderer = _tileMap.GetComponentInChildren<TilemapRenderer>();
        tileMapRenderer.enabled = true;
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

    public void Release()
    {
        _labyrinthTexture.Release();
    }
}