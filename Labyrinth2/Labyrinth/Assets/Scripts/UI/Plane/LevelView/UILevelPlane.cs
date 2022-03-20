using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UILevelPlane : UIBasePlane
{
    private UILevelView _uiLevelView;
    private UILevelModel uiLevelModel;

    public override void Init(UIPlaneType type)
    {
        base.Init(type);
        View = new UILevelView();
        Model = new UILevelModel();
    }

    public override void OnEnter(IUIDataBase data)
    {
        base.OnEnter(data);
        _uiLevelView = View as UILevelView;
        uiLevelModel = Model as UILevelModel;

        RefreshUI();
        RegisterEvent();
    }

    public override void Exit()
    {
        base.Exit();
        UnRegisterEvent();
    }

    private void RefreshUI()
    {
    }

    public void NextLevel()
    {
        Debug.LogError("NextLevel");
    }

    private void MoveToExit()
    {
        _uiLevelView.ShowNextBtn(true);
    }

    private void RegisterEvent()
    {
        GameNotifycation.GetInstance().AddEventListener(ENUM_MSG_TYPE.MSG_MOVE_TO_EXIT, MoveToExit);
    }

    private void UnRegisterEvent()
    {
        GameNotifycation.GetInstance().RemoveEventListener(ENUM_MSG_TYPE.MSG_MOVE_TO_EXIT, MoveToExit);
    }
}
