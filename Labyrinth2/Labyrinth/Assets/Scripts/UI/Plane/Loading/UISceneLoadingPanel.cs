using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UISceneLoadingPanel : UIBasePlane
{
    private UISceneLoadingView _uiSceneLoadingView;
    private UISceneLoadingModel _uiSceneLoadingModel;

    public override void Init(UIPlaneType type)
    {
        base.Init(type);
        View = new UIRoleOperationView();
        Model = new UIRoleOperationModel();
    }

    public override void OnEnter(IUIDataBase data)
    {
        base.OnEnter(data);
        _uiSceneLoadingView = View as UISceneLoadingView;
        _uiSceneLoadingModel = Model as UISceneLoadingModel;
    }
}
