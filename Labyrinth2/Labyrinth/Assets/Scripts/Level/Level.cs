using PathFinding;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Level
{

    private IMap _mapData;
    private LabyrinthCreate _labyrinthCreate;
    private MapController mapController;
    private AStar _aStar;
    private FindPath _findPath;

    public Level()
    {
        _mapData = new MapData("labyrinth2");
        mapController = new MapController(_mapData);
        _labyrinthCreate = new LabyrinthCreate();
        _aStar = new AStar();
        _findPath = new FindPath(_aStar);
    }

    public void Update()
    {

        if (null != _findPath)
        {
            _findPath.Update();
        }

        RoleController.GetInstance().LateUpdate();

    }


}
