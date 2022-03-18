using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Scene:游戏启动时Loading
/// </summary>
public class StateSceneLoading : StateSceneBase
{

    public StateSceneLoading()
    {
        _state = StateEnum.SCENE_LOADING;

        //Transition transition = new Transition(StateEnum.RESET, EatToReset);
        //_transitionList.Add(transition);
    }

    public override void OnEnter()
    {
        base.OnEnter();
        ConfigLoad.Instance.Load(LoadConfigCallBack);
    }

    public override void OnExecute()
    {
        base.OnExecute();

    }

    public override void OnExit()
    {
        base.OnExit();

    }

    private void LoadConfigCallBack()
    {
        Debug.LogError("LoadCallBack");
    }

}
