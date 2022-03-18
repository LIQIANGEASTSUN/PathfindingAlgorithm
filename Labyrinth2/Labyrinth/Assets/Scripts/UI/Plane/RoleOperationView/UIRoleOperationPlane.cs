using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIRoleOperationPlane : UIBasePlane
{
    private UIRoleOperationView _uiRoleOperationView;
    private UIRoleOperationModel _uiRoleOperationModel;

    public override void Init(UIPlaneType type)
    {
        base.Init(type);
        View = new UIRoleOperationView();
        Model = new UIRoleOperationModel();
    }

    public override void OnEnter(IUIDataBase data)
    {
        base.OnEnter(data);
        _uiRoleOperationView = View as UIRoleOperationView;
        _uiRoleOperationModel = Model as UIRoleOperationModel;
    }

    public override void Update()
    {
        base.Update();
        _uiRoleOperationView.Update();
    }

    //public void CloseOnClick()
    //{
    //    Close();
    //}

    //// 返回按钮
    //public void BackOnClick()
    //{
    //    UIManager.GetInstance().Close(UIPlaneType.Role_Operation);
    //    Back();
    //}

    //// 打开背包界面，关闭商店界面
    //public void BackpackerOnClick1()
    //{
    //    UIManager.GetInstance().Close(UIPlaneType.Role_Operation);
    //    //UIManager.GetInstance().Open(UIPlaneType.Backpacker, null);
    //}

    //// 打开背包界面，不关闭商店界面
    //public void BackpackerOnClick2()
    //{
    //    //UIManager.GetInstance().Open(UIPlaneType.Backpacker, null);
    //}

}
