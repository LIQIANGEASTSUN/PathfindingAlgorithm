using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIMainPlane : UIBasePlane
{
    private UIMainView _mainView;
    private UIMainModel _mainModel;

    public override void Init(UIPlaneType type)
    {
        base.Init(type);
        View = new UIMainView();
        Model = new UIMainModel();
    }

    public override void OnEnter(IUIDataBase data)
    {
        base.OnEnter(data);

        _mainView = View as UIMainView;
        _mainModel = Model as UIMainModel;
    }

    public void CloseOnClick()
    {
        Close();
    }

    public void ShopOnClick()
    {
        //UIManager.GetInstance().Open(UIPlaneType.Shop, null);
    }

}
