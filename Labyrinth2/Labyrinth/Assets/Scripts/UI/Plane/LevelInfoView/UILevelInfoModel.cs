using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UILevelInfoModel : IUIModel
{
    private IUIDataBase _data;
    public void Init(IUIDataBase data)
    {
        _data = data;
    }

}
