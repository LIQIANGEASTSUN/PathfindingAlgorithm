using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 角色操作界面
/// </summary>
public class UIRoleOperationView : IUIView
{
    private Transform _tr;
    private IUIController _uiController;
    private UIRoleOperationPlane _uiRoleOperationPlane;

    private TPPMoveAndRotateRocker _tPPMoveAndRotateRocker;
    private Transform _rockerBtnTr;
    private Button _pathFindBtn;

    public void Init(Transform tr, IUIController controller)
    {
        _tr = tr;
        _uiController = controller;
        _uiRoleOperationPlane = controller as UIRoleOperationPlane;

        _rockerBtnTr = _tr.Find("ThirdPersonPerspective/TPPMoveAndRotateRocker");
        _tPPMoveAndRotateRocker = new TPPMoveAndRotateRocker(_rockerBtnTr);

        _pathFindBtn = _tr.Find("PathFindBtn").GetComponent<Button>();
        _pathFindBtn.onClick.AddListener(PathFindClick);
    }

    // Update is called once per frame
    public void Update()
    {
        _tPPMoveAndRotateRocker.Update();
    }

    private void PathFindClick()
    {
        GameNotifycation.GetInstance().Notify(ENUM_MSG_TYPE.MSG_PATH_FIND);
    }
}
