using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Scene:游戏启动时Loading
/// </summary>
public class StateSceneLoading : StateSceneBase
{
    private bool _configLoadComplete = false;
    private int _changeSceneType = -1;
    public StateSceneLoading()
    {
        _state = StateEnum.SCENE_LOADING;

        Transition transition = new Transition(StateEnum.SCENE_HOME, ChangeToHome);
        _transitionList.Add(transition);
    }

    public override void OnEnter()
    {
        base.OnEnter();
        RegisterEvent();

        UIManager.GetInstance().Open(UIPlaneType.Scene_Loading_View, null);
        ConfigLoad.Instance.Load(LoadConfigCallBack);
    }

    public override void OnExecute()
    {
        base.OnExecute();
    }

    public override void OnExit()
    {
        base.OnExit();
        UnRegisterEvent();

        UIManager.GetInstance().Close(UIPlaneType.Scene_Loading_View);
    }

    private void LoadConfigCallBack()
    {
        _configLoadComplete = true;
        GameNotifycation.GetInstance().Notify<float>(ENUM_MSG_TYPE.MSG_CONFIG_LOADING_PROCESS, 1);
    }

    private bool ChangeToHome()
    {
        return _configLoadComplete && _changeSceneType == (int)StateEnum.SCENE_HOME;
    }

    private void ChangeScene(int type)
    {
        _changeSceneType = type;
    }

    private void RegisterEvent()
    {
        GameNotifycation.GetInstance().AddEventListener<int>(ENUM_MSG_TYPE.MSG_CHANGE_SCENE, ChangeScene);
    }

    private void UnRegisterEvent()
    {
        GameNotifycation.GetInstance().RemoveEventListener<int>(ENUM_MSG_TYPE.MSG_CHANGE_SCENE, ChangeScene);
    }

}
