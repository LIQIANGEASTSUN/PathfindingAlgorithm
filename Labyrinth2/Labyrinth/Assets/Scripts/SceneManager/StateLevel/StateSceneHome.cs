using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Scene:家园
/// </summary>
public class StateSceneHome : StateSceneBase
{

    public StateSceneHome()
    {
        _state = StateEnum.SCENE_HOME;
    }

    public override void OnEnter()
    {
        base.OnEnter();
        UIManager.GetInstance().Open(UIPlaneType.Main_View, null);
        UIManager.GetInstance().Open(UIPlaneType.Level_Info_View, null);
    }

}
