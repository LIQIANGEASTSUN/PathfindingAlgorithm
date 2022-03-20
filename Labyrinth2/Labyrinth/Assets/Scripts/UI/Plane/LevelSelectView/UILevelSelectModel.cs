using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UILevelSelectModel : IUIModel
{
    private IUIDataBase _data;
    private const string _tableName = "level";

    private List<LevelData> _levelList = new List<LevelData>();
    private int _currentPage = 0;
    private int _maxPage = 0;
    private const int _pageCount = 9;
    public void Init(IUIDataBase data)
    {
        _data = data;
    }

    public void LevelData()
    {
        string[] ids = TableDatas.GetIds(_tableName);
        foreach (var id in ids)
        {
            int levelId = int.Parse(id.ToString());
            LevelData levelData = new LevelData(levelId);
            _levelList.Add(levelData);
        }
        _maxPage = Mathf.CeilToInt(_levelList.Count * 1.0f / _pageCount) - 1;
    }

    public void SetPage(int value)
    {
        _currentPage = value;
    }

    public void ChangePage(int value)
    {
        _currentPage += value;
        _currentPage = UnityEngine.Mathf.Clamp(_currentPage, 0, _pageCount - 1);
    }

    public LevelPageEnum CurrentPageType()
    {
        LevelPageEnum type = LevelPageEnum.Node;
        if (_currentPage > 0)
        {
            type |= LevelPageEnum.Has_Previous;
        }
        if (_currentPage <= _maxPage - 1)
        {
            type |= LevelPageEnum.Has_Next;
        }
        return type;
    }

    public List<LevelData> PageDataList()
    {
        int minIndex = _currentPage * _pageCount;
        int maxIndex = (_currentPage + 1)* _pageCount;
        List<LevelData> resultList = new List<LevelData>();
        for (int i = minIndex; i < maxIndex; ++i)
        {
            if (_levelList.Count > i)
            {
                resultList.Add(_levelList[i]);
            }
        }
        return resultList;
    }

}

public struct LevelData
{
    public int _levelId;
    public LevelData(int levelId)
    {
        _levelId = levelId;
    }

}
