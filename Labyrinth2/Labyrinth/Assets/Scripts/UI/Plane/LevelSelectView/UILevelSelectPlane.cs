using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum LevelPageEnum
{
    Node = 0,
    Has_Previous = 1,
    Has_Next = 2,
    Both = 3,
}

public class UILevelSelectPlane : UIBasePlane
{
    private UILevelSelectView _uiLevelInfoView;
    private UILevelSelectModel _uiLevelInfoModel;

    public override void Init(UIPlaneType type)
    {
        base.Init(type);
        View = new UILevelSelectView();
        Model = new UILevelSelectModel();
    }

    public override void OnEnter(IUIDataBase data)
    {
        base.OnEnter(data);
        _uiLevelInfoView = View as UILevelSelectView;
        _uiLevelInfoModel = Model as UILevelSelectModel;
        _uiLevelInfoModel.LevelData();
        _uiLevelInfoModel.SetPage(0);

        RefreshUI();
        RegisterEvent();
    }

    public override void Exit()
    {
        base.Exit();
        _uiLevelInfoView.Release();
        UnRegisterEvent();
    }

    private void RefreshUI()
    {
        RefreshLevelItem();
    }

    private void RefreshLevelItem()
    {
        LevelPageEnum pageType = _uiLevelInfoModel.CurrentPageType();
        List<LevelData> itemList = _uiLevelInfoModel.PageDataList();
        _uiLevelInfoView.RefreshLevel(itemList, pageType);
    }

    public void PreviousOnClick()
    {
        _uiLevelInfoModel.ChangePage(-1);
        RefreshLevelItem();
    }

    public void NextOnClick()
    {
        _uiLevelInfoModel.ChangePage(1);
        RefreshLevelItem();
    }

    private void RegisterEvent()
    {

    }

    private void UnRegisterEvent()
    {

    }
}
