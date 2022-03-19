using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LevelProxy : ILevelProxy
{
    private ILevelProxy _proxy;

    public LevelProxy(ILevelProxy proxy)
    {
        _proxy = proxy;
    }

    public int LevelId()
    {
        return _proxy.LevelId();
    }
}
