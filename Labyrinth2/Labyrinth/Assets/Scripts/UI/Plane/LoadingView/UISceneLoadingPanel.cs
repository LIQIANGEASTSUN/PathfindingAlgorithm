using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class UISceneLoadingPanel : UIBasePlane
{
    private UISceneLoadingView _uiSceneLoadingView;
    private UISceneLoadingModel _uiSceneLoadingModel;

    public override void Init(UIPlaneType type)
    {
        base.Init(type);
        View = new UISceneLoadingView();
        Model = new UISceneLoadingModel();
    }

    public override void OnEnter(IUIDataBase data)
    {
        base.OnEnter(data);
        _uiSceneLoadingView = View as UISceneLoadingView;
        _uiSceneLoadingModel = Model as UISceneLoadingModel;

        RegisterEvent();
    }

    public override void Exit()
    {
        base.Exit();
        UnRegisterEvent();
    }

    private void ConfigLoadProcess(float value)
    {
        _uiSceneLoadingView.SliderValueChange(value);
        if (value >= 1)
        {
            _uiSceneLoadingView.LoadingComplete();
        }
    }

    private void RegisterEvent()
    {
        GameNotifycation.GetInstance().AddEventListener<float>(ENUM_MSG_TYPE.MSG_CONFIG_LOADING_PROCESS, ConfigLoadProcess);
    }

    private void UnRegisterEvent()
    {
        GameNotifycation.GetInstance().RemoveEventListener<float>(ENUM_MSG_TYPE.MSG_CONFIG_LOADING_PROCESS, ConfigLoadProcess);
    }

}
