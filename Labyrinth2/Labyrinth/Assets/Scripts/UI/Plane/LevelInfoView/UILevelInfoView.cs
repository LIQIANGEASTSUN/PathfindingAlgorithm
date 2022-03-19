using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UILevelInfoView : IUIView
{
    private Transform _tr;
    private IUIController _uiController;
    private UILevelInfoPlane _uiLevelInfoPlane;

    public void Init(Transform tr, IUIController controller)
    {
        _tr = tr;
        _uiController = controller;
        _uiLevelInfoPlane = controller as UILevelInfoPlane;


    }


}
