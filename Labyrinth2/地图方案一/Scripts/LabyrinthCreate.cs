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

    void Start()
    {
        Instance = this;
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
        int totalRow = LabyrinthData.Instance.TotalRow;
        int totalCol = LabyrinthData.Instance.TotalCol;
        for (int i = 0; i < totalRow; ++i)
        {
            for (int j = 0; j < totalCol; ++j)
            {
                int index = i * totalCol + j;
                MapCell mapCell = LabyrinthData.Instance.MapCellDic[index];
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
    // 0  5  (5, 0, 0)
    // 5  1  (1, -5, 0)
    // 6  9  (9, -6, 0)
    // 11  4  (4, -11, 0)
    // 12  8  (8, -12, 0)
}
