using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// 主界面
/// </summary>
public class UIMainView : IUIView
{
    private Transform _tr;
    private IUIController _uiController;
    private UIMainPlane UIMainPlane;

    private Button _closeBtn;
    private Button _shopBtn;

    public void Init(Transform tr, IUIController controller)
    {
        _tr = tr;
        _uiController = controller;
        UIMainPlane = controller as UIMainPlane;

        _closeBtn = _tr.Find("CloseBtn").GetComponent<Button>();
        _closeBtn.onClick.RemoveAllListeners();
        _closeBtn.onClick.AddListener(UIMainPlane.CloseOnClick);

        _shopBtn = _tr.Find("ShopBtn").GetComponent<Button>();
        _shopBtn.onClick.RemoveAllListeners();
        _shopBtn.onClick.AddListener(UIMainPlane.ShopOnClick);
    }

}
