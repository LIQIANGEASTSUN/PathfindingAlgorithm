using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SceneManager : SingletonObject<SceneManager>
{
    private StateMachine _stateMachine;
    public SceneManager()
    {

    }

    public void Init()
    {
        _stateMachine = new StateMachine();
        StateSceneLoading stateSceneLoading = new StateSceneLoading();
        _stateMachine.AddState(stateSceneLoading);

        StateSceneHome stateSceneHome = new StateSceneHome();
        _stateMachine.AddState(stateSceneHome);

        StateSceneLevel stateSceneLevel = new StateSceneLevel();
        _stateMachine.AddState(stateSceneLevel);

        _stateMachine.TransitionState(StateEnum.SCENE_LOADING);
    }

    public void Update()
    {
        _stateMachine.OnExecute();
    }

}
