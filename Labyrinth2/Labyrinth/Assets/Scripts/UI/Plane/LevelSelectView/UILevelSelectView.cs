using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System;

public class UILevelSelectView : IUIView
{
    private Transform _tr;
    private IUIController _uiController;
    private UILevelSelectPlane _uiLevelInfoPlane;
    private Transform _gridTr;
    private Transform _itemCloneTr;

    private Button _previousBtn;
    private Button _nextPageBtn;

    private List<LevelItem> _itemList = new List<LevelItem>();

    public void Init(Transform tr, IUIController controller)
    {
        _tr = tr;
        _uiController = controller;
        _uiLevelInfoPlane = controller as UILevelSelectPlane;

        _gridTr = tr.Find("Panel/Grid");
        _itemCloneTr = _gridTr.Find("Item");

        _previousBtn = tr.Find("PreviousBtn").GetComponent<Button>();
        _previousBtn.onClick.AddListener(PreviousOnClick);

        _nextPageBtn = tr.Find("NextBtn").GetComponent<Button>();
        _nextPageBtn.onClick.AddListener(NextOnClick);
    }

    public void RefreshLevel(List<LevelData> levelDataList, LevelPageEnum pageType)
    {
        ReleaseItem();
        for (int i = 0; i < levelDataList.Count; i++)
        {
            LevelData levelData = levelDataList[i];
            LevelItem levelItem = new LevelItem(_itemCloneTr, levelData);
            levelItem.SetClickCallBack(ItemClick);
            _itemList.Add(levelItem);
        }
        RefreshPageBtn(pageType);
    }

    private void RefreshPageBtn(LevelPageEnum pageType)
    {
        bool showPrevious = (pageType & LevelPageEnum.Has_Previous) != 0;
        _previousBtn.gameObject.SetActive(showPrevious);
        bool showNext = (pageType & LevelPageEnum.Has_Next) != 0;
        _nextPageBtn.gameObject.SetActive(showNext);
    }

    private void PreviousOnClick()
    {
        _uiLevelInfoPlane.PreviousOnClick();
    }

    private void NextOnClick()
    {
        _uiLevelInfoPlane.NextOnClick();
    }

    private void ItemClick(LevelData levelData)
    {
        GameNotifycation.GetInstance().Notify<int>(ENUM_MSG_TYPE.MSG_GO_TO_LEVEL, levelData._levelId);
    }

    public void Release()
    {
        ReleaseItem();
    }

    private void ReleaseItem()
    {
        for (int i = _itemList.Count - 1; i >= 0; i--)
        {
            LevelItem itme = _itemList[i];
            itme.Release();
        }
        _itemList.Clear();
    }

}

public class LevelItem
{
    private Transform _tr;
    private Button _btn;
    private LevelData _levelData;
    private Action<LevelData> _clickCallBack;

    private Text _levelText;

    public LevelItem(Transform tr, LevelData levelData)
    {
        _levelData = levelData;

        GameObject go = GameObject.Instantiate(tr.gameObject);
        _tr = go.transform;
        _tr.SetParent(tr.parent);
        _tr.localScale = Vector3.one;
        _tr.localRotation = Quaternion.identity;
        _tr.SetAsLastSibling();
        _tr.gameObject.SetActive(true);

        _btn = _tr.GetComponent<Button>();
        _btn.onClick.AddListener(Click);

        _levelText = _tr.Find("Text").GetComponent<Text>();
        _levelText.text = levelData._levelId.ToString();
    }

    public void SetClickCallBack(Action<LevelData> callBack)
    {
        _clickCallBack = callBack;
    }

    private void Click()
    {
        _clickCallBack?.Invoke(_levelData);
    }

    public void Release()
    {
        GameObject.Destroy(_tr.gameObject);
    }
}
