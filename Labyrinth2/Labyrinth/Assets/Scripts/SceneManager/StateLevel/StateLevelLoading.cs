using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// 游戏启动时Loading
/// </summary>
public class StateLevelLoading : StateLevelBase
{

    public StateLevelLoading()
    {
        _state = StateEnum.LEVEL_LOADING;

        //Transition transition = new Transition(StateEnum.RESET, EatToReset);
        //_transitionList.Add(transition);
    }


}
