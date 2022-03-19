using PathFinding;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level
{
    private int _levelId;
    private IMap _mapData;
    private MapController _mapController;
    private LabyrinthCreate _labyrinthCreate;
    private PathFind _pathFind;

    public Level(int levelId)
    {
        _levelId = levelId;

        string mapConfig = TableDatas.GetData("level", _levelId.ToString(), "MapConfig");
        _mapData = new MapData(mapConfig);
        _labyrinthCreate = new LabyrinthCreate(_levelId);
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
