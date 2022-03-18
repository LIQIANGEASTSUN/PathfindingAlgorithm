using PathFinding;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level
{
    private IMap _mapData;
    private MapController _mapController;
    private LabyrinthCreate _labyrinthCreate;
    private PathFind _pathFind;

    public Level()
    {
        string mapFile = "labyrinth2";
        _mapData = new MapData(mapFile);
        _labyrinthCreate = new LabyrinthCreate();
        _pathFind = new PathFind();

        _mapController = new MapController(_mapData);

        #region GameServer Register
        GameServer.GetInstance().SetMapProxy(_mapController);
        #endregion

        Init();
    }

    public void Init()
    {
        _mapData.Init();
        _labyrinthCreate.Init();
        _pathFind.Init();
    }

    public void Update()
    {
        if (null != _pathFind)
        {
            _pathFind.Update();
        }

        RoleController.GetInstance().LateUpdate();
    }

    public void Release()
    {
        _mapData.Release();
        _labyrinthCreate.Release();
        _pathFind.Release();
    }

}
