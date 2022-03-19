using System.Collections.Generic;
using System;

public abstract class StateBase
{
    // 当前类型
    protected StateEnum _state;
    protected List<Transition> _transitionList = new List<Transition>();
    protected System.Object _transitionObj = null;

    public StateBase(){
    }

    public virtual void TransitionData(System.Object obj)
    {
    }

    // 进入该状态
    public abstract void OnEnter();

    // 执行该状态的行为
    public abstract void OnExecute();

    // 退出该状态
    public abstract void OnExit();

    //返回当前类型
    public StateEnum State
    {
        get { return _state; }
    }

    public List<Transition> TransitionList
    {
        get { return _transitionList; }
    }

    public System.Object TransitionObj
    {
        get { return _transitionObj; }
    }

}
