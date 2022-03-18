using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UISceneLoadingView : IUIView
{
    private Transform _tr;
    private IUIController _uiController;
    private UISceneLoadingPanel _uiSceneLoadingPanel;

    private Slider _slider;
    private Button _startBtn;

    public void Init(Transform tr, IUIController controller)
    {
        _tr = tr;
        _uiController = controller;
        _uiSceneLoadingPanel = controller as UISceneLoadingPanel;

        _slider = _tr.Find("Slider").GetComponent<Slider>();

        _startBtn = _tr.Find("StartBtn").GetComponent<Button>();
        _startBtn.onClick.AddListener(StartClick);
    }

    private void StartClick()
    {
        GameNotifycation.GetInstance().Notify<int>(ENUM_MSG_TYPE.MSG_CHANGE_SCENE, (int)StateEnum.SCENE_HOME);
    }

    private void SliderValueChange(float value)
    {
        _slider.value = value;
    }
}
