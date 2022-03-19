using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Scene:家园
/// </summary>
public class StateSceneHome : StateSceneBase
{
    private bool _changeToLevel = false;
    public StateSceneHome()
    {
        _state = StateEnum.SCENE_HOME;

        Transition transition = new Transition(StateEnum.SCENE_LEVEL, ChangeToLevel);
        _transitionList.Add(transition);
    }

    public override void OnEnter()
    {
        base.OnEnter();
        UIManager.GetInstance().Open(UIPlaneType.Main_View, null);
        UIManager.GetInstance().Open(UIPlaneType.Level_Info_View, null);
        //_changeToLevel = true;
    }

    public override void OnExit()
    {
        base.OnExit();
        UIManager.GetInstance().Close(UIPlaneType.Main_View);
        UIManager.GetInstance().Close(UIPlaneType.Level_Info_View);
    }

    private bool ChangeToLevel()
    {
        return _changeToLevel;
    }

}
