using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LevelController : ILevelProxy
{
    private Level _level;
    public LevelController(Level level)
    {
        _level = level;
    }

    public int LevelId()
    {
        return _level.LevelId;
    }
}
