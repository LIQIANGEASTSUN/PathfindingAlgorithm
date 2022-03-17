using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Text;
using UnityEngine.Tilemaps;

public class LabyrinthCreate : MonoBehaviour
{
    public static LabyrinthCreate Instance;
    private Tilemap _tileMap;
    private LabyrinthTexture _labyrinthTexture;

    private MapDataBase _mapDataBase;

    void Start()
    {
        Instance = this;
        _labyrinthTexture = new LabyrinthTexture();

        _mapDataBase = new MapDataPlanA("labyrinth2");

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
                MapCell mapCell = _mapDataBase.MapCellDic[index];
                LoadTileAsset(mapCell);
            }
        }
    }

    private void LoadTileAsset(MapCell mapCell)
    {
        Vector3Int pos = new Vector3Int(mapCell.col, mapCell.row * -1, 0);
        Tile tile = _tileMap.GetTile<Tile>(pos);
        tile.sprite = _labyrinthTexture.SpriteList[mapCell.flag];
        _tileMap.RefreshTile(pos);
        Debug.LogError(mapCell.row + "  " + mapCell.col + "  " + pos + "   " + mapCell.flag);
    }
}
