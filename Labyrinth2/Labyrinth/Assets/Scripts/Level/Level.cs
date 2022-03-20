using PathFinding;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level
{
    private int _levelId;
    private IMap _mapData;

    private LabyrinthCreate _labyrinthCreate;
    private PathFind _pathFind;

    #region Proxy
    private MapController _mapController;
    private LevelController _levelController;
    #endregion

    public Level(int levelId)
    {
        _levelId = levelId;

        string mapConfig = TableDatas.GetData("level", _levelId.ToString(), "MapConfig");
        _mapData = new MapData(mapConfig);

        #region GameServer Register
        _mapController = new MapController(_mapData);
        GameServer.GetInstance().SetMapProxy(_mapController);

        _levelController = new LevelController(this);
        GameServer.GetInstance().SetLevelProxy(_levelController);
        #endregion

        _labyrinthCreate = new LabyrinthCreate();
        _pathFind = new PathFind();

        Init();
    }

    public void Init()
    {
        _mapData.Init();
        _labyrinthCreate.Init();
        _pathFind.Init();
        _mapController.Init();
        RoleController.GetInstance().Init();
    }

    public void Update()
    {
        if (null != _pathFind)
        {
            _pathFind.Update();
        }

        RoleController.GetInstance().LateUpdate();
    }

    public int LevelId
    {
        get
        {
            return _levelId;
        }
    }

    public void Release()
    {
        _mapData.Release();
        _labyrinthCreate.Release();
        _pathFind.Release();
        _mapController.Release();
        _levelController.Release();
        RoleController.GetInstance().Release();
    }

}
