using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UILevelInfoPlane : UIBasePlane
{
    private UILevelInfoView _uiLevelInfoView;
    private UILevelInfoModel _uiLevelInfoModel;

    public override void Init(UIPlaneType type)
    {
        base.Init(type);
        View = new UILevelInfoView();
        Model = new UILevelInfoModel();
    }

    public override void OnEnter(IUIDataBase data)
    {
        base.OnEnter(data);
        _uiLevelInfoView = View as UILevelInfoView;
        _uiLevelInfoModel = Model as UILevelInfoModel;

        RegisterEvent();
    }

    public override void Exit()
    {
        base.Exit();
        UnRegisterEvent();
    }

    private void RegisterEvent()
    {

    }

    private void UnRegisterEvent()
    {

    }
}
