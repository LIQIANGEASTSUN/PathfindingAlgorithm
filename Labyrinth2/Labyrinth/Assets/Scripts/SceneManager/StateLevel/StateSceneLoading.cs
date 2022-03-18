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

    }

    public override void OnExecute()
    {
        base.OnExecute();

    }

    public override void OnExit()
    {
        base.OnExit();

    }

//    ConfigLoad.Instance.Load(LoadConfigCallBack);
//        UIManager.GetInstance().Open(UIPlaneType.Role_Operation, null);
//}

//// Update is called once per frame
//void Update()
//{
//    if (null != _level)
//    {
//        _level.Update();
//    }
//    UIManager.GetInstance().Update();
//}

//private void LoadConfigCallBack()
//{
//    _level = new Level();
//}

}
