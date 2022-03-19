using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Scene:关卡
/// </summary>
public class StateSceneLevel : StateSceneBase
{
    private int _go_to_levelId = -1;
    private Level _level;
    public StateSceneLevel()
    {
        _state = StateEnum.SCENE_LEVEL;
    }

    public override void OnEnter()
    {
        base.OnEnter();
        _level = new Level(_go_to_levelId);
        UIManager.GetInstance().Open(UIPlaneType.Role_Operation_View, null);
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

    public override void TransitionData(object obj)
    {
        _go_to_levelId = (int)obj;
    }

}
