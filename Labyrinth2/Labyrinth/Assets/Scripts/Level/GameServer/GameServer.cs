using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameServer : SingletonObject<GameServer>
{

    private IMapProxy _mapProxy;
    private ILevelProxy _levelProxy;


    public IMapProxy MapProxy
    {
        get {
            return _mapProxy;
        }
    }

    public void SetMapProxy(IMapProxy mapProxy)
    {
        _mapProxy = mapProxy;
    }

    public ILevelProxy LevelProxy
    {
        get
        {
            return _levelProxy;
        }
    }

    public void SetLevelProxy(ILevelProxy levelProxy)
    {
        _levelProxy = levelProxy;
    }

}
