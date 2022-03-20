using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System;

public class UILevelView : IUIView
{
    private Transform _tr;
    private IUIController _uiController;
    private UILevelPlane _uiLevelPlane;

    private TextMesh _energyText;
    private TextMesh _levelText;
    private Button _nextButton;

    public void Init(Transform tr, IUIController controller)
    {
        _tr = tr;
        _uiController = controller;
        _uiLevelPlane = controller as UILevelPlane;

        _energyText = tr.Find("Panel/Energy/Text").GetComponent<TextMesh>();
        _levelText = tr.Find("Panel/Level/Text").GetComponent<TextMesh>();

        _nextButton = tr.Find("Panel/NextLevelBtn").GetComponent<Button>();
        _nextButton.onClick.AddListener(NextClick);
    }

    public void ShowNextBtn(bool value)
    {
        _nextButton.gameObject.SetActive(value);
    }

    private void NextClick()
    {
        _uiLevelPlane.NextLevel();
    }

}
