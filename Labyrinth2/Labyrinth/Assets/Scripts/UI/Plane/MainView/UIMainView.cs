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

    public void Init(Transform tr, IUIController controller)
    {
        _tr = tr;
        _uiController = controller;
        UIMainPlane = controller as UIMainPlane;

    }

}
