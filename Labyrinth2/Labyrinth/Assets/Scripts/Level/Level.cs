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
        _mapController = new MapController(_mapData);
        _labyrinthCreate = new LabyrinthCreate();
        _pathFind = new PathFind();
    }

    public void Update()
    {
        if (null != _pathFind)
        {
            _pathFind.Update();
        }

        RoleController.GetInstance().LateUpdate();
    }
}
