using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UIRoleOperationModel : IUIModel
{
    private IUIDataBase _data;
    public void Init(IUIDataBase data)
    {
        _data = data;
    }
}
