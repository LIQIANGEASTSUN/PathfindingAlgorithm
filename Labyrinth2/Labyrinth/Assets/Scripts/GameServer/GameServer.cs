using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameServer : SingletonObject<GameServer>
{

    private IMapProxy _mapProxy;

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


}
