using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SceneManager
{
    private StateMachine _stateMachine;
    public SceneManager()
    {

    }

    public void Init()
    {
        _stateMachine = new StateMachine();
        StateLevelLoading stateLevelLoading = new StateLevelLoading();
        _stateMachine.AddState(stateLevelLoading);
    }

}
