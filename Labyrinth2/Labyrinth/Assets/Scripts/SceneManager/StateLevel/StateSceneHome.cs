using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Scene:家园
/// </summary>
public class StateSceneHome : StateSceneBase
{
    private bool _changeToLevel = false;
    private int _go_to_levelId = -1;
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
        RegisterEvent();
    }

    public override void OnExit()
    {
        base.OnExit();
        UIManager.GetInstance().Close(UIPlaneType.Main_View);
        UIManager.GetInstance().Close(UIPlaneType.Level_Info_View);
        UnRegisterEvent();
    }

    private void SetTransitionData()
    {
        _transitionObj = _go_to_levelId;
        int a = 0;
    }

    private bool ChangeToLevel()
    {
        return _changeToLevel;
    }

    private void GoToLevel(int levelId)
    {
        _changeToLevel = true;
        _go_to_levelId = levelId;
        SetTransitionData();
    }

    private void RegisterEvent()
    {
        GameNotifycation.GetInstance().AddEventListener<int>(ENUM_MSG_TYPE.MSG_GO_TO_LEVEL, GoToLevel);
    }

    private void UnRegisterEvent()
    {
        GameNotifycation.GetInstance().RemoveEventListener<int>(ENUM_MSG_TYPE.MSG_GO_TO_LEVEL, GoToLevel);
    }

}
