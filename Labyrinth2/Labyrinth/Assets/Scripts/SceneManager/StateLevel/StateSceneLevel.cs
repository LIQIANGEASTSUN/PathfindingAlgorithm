using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Scene:关卡
/// </summary>
public class StateSceneLevel : StateSceneBase
{
    private Level _level;
    public StateSceneLevel()
    {
        _state = StateEnum.SCENE_LEVEL;
    }

    public override void OnEnter()
    {
        base.OnEnter();
        UIManager.GetInstance().Open(UIPlaneType.Role_Operation_View, null);
        _level = new Level(1001);
    }

    public override void OnExecute()
    {
        base.OnExecute();
        _level.Update();
    }

    public override void OnExit()
    {
        base.OnExit();
    }

}
