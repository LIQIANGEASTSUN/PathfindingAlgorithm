using System.Collections.Generic;
using UnityEngine;


public class StateMachine
{
    // 保存所有的状态
    private Dictionary<StateEnum, StateBase> _stateDic = new Dictionary<StateEnum, StateBase>();
    // 记录当前状态
    private StateBase _currentState;
    // 环境变量
    private Dictionary<string, Parameter> _parameterDic = new Dictionary<string, Parameter>();

    public StateMachine()
    {

    }

    public void AddState(StateBase stateBase)
    {
        _stateDic.Add(stateBase.State, stateBase);
    }

    public Dictionary<StateEnum, StateBase> StateDic
    {
        get { return _stateDic; }
    }

    // 获取当前状态
    public StateBase CurrentState
    {
        get { return _currentState; }
        private set { _currentState = value; }
    }

    // 状态转换方法
    public void TransitionState(StateEnum stateEnum)
    {
        // 如果当前状态不为空，先退出当前状态
        if (null != CurrentState)
        {
            CurrentState.OnExit();
        }

        // 令当前状态等于转换的新状态
        CurrentState = _stateDic[stateEnum];
        // 转换的新状态执行 进入方法
        CurrentState.OnEnter();
        CurrentState.OnExecute();
    }

    // 每帧执行的方法
    public void OnExecute()
    {
        if (null != CurrentState)
        {
            CurrentState.OnExecute();
        }

        // 判断CurrentState所有转换条件
        for (int i = 0; i < CurrentState.TransitionList.Count; ++i)
        {
            Transition transition = CurrentState.TransitionList[i];
            // 如果转换条件为 true，则转换状态
            if (transition.CanTransition() || CompareTransition(transition))
            {
                TransitionState(transition.ToState);
                break;
            }
        }
    }

    // 判断 Transition 是否满足
    private bool CompareTransition(Transition transition)
    {
        if (transition.ParameterList.Count <= 0)
        {
            return false;
        }
        for (int i = 0; i < transition.ParameterList.Count; ++i)
        {
            Parameter parameter = transition.ParameterList[i];
            Parameter environment = null;
            if (!_parameterDic.TryGetValue(parameter._parameterName, out environment)
                || !ConditionCompare.CompareParameter(environment, parameter))
            {
                return false;
            }
        }
        return true;
    }

    // 更新环境变量的值
    public void UpdateParameter(string parameterName, int intValue)
    {
        Parameter parameter = GetParameter(parameterName);
        parameter._parameterType = ParameterType.Int;
        parameter.intValue = intValue;
    }

    // 更新环境变量的值
    public void UpdateParameter(string parameterName, float floatValue)
    {
        Parameter parameter = GetParameter(parameterName);
        parameter._parameterType = ParameterType.Float;
        parameter.floatValue = floatValue;
    }

    // 更新环境变量的值
    public void UpdateParameter(string parameterName, bool boolValue)
    {
        Parameter parameter = GetParameter(parameterName);
        parameter._parameterType = ParameterType.Bool;
        parameter.boolValue = boolValue;
    }

    // 更新环境变量的值
    public void UpdateParameter(string parameterName, string stringValue)
    {
        Parameter parameter = GetParameter(parameterName);
        parameter._parameterType = ParameterType.String;
        parameter.stringValue = stringValue;
    }

    // 获取环境变量
    private Parameter GetParameter(string parameterName)
    {
        Parameter parameter = null;
        if (!_parameterDic.TryGetValue(parameterName, out parameter))
        {
            parameter = new Parameter();
            _parameterDic[parameterName] = parameter;
        }
        return parameter;
    }

    #region Config
    /// <summary>
    /// 配置表，对于不同的角色可以有不同的配置表，灵活多变
    /// </summary>
    /// <param name="fileName">配置文件名</param>
    public void SetConfigFile(string fileName)
    {
        TableRead.Instance.Init();
        TableRead.Instance.ReadCustomPath(Application.streamingAssetsPath);
        List<int> list = TableRead.Instance.GetKeyList(fileName);
        foreach (var key in list)
        {
            AnalysisTransition(fileName, key);
        }
    }

    // 解析每一行的 Transition
    private void AnalysisTransition(string fileName, int key)
    {
        int currentState = int.Parse(TableRead.Instance.GetData(fileName, key, "CurrentState"));
        int toState = int.Parse(TableRead.Instance.GetData(fileName, key, "ToState"));

        List<Parameter> parameterList = new List<Parameter>();
        for (int i = 1; i <= 2; ++i)
        {
            string name = TableRead.Instance.GetData(fileName, key, string.Format("Name{0}", i));
            if (string.IsNullOrEmpty(name))
            {
                continue;
            }
            Parameter parameter = new Parameter();
            parameter._parameterName = name;
            parameter._parameterType = (ParameterType)(int.Parse(TableRead.Instance.GetData(fileName, key, string.Format("Type{0}", i))));
            string value = TableRead.Instance.GetData(fileName, key, string.Format("Value{0}", i));
            // 根据类型将 value 解析为 int/float/bool/string 
            if (parameter._parameterType == ParameterType.Int)
            {
                parameter.intValue = int.Parse(value);
            }
            else if (parameter._parameterType == ParameterType.Float)
            {
                parameter.floatValue = float.Parse(value);
            }
            else if (parameter._parameterType == ParameterType.Bool)
            {
                parameter.boolValue = bool.Parse(value);
            }
            else if (parameter._parameterType == ParameterType.String)
            {
                parameter.stringValue = value;
            }
            parameter._compare = (ParameterCompare)(int.Parse(TableRead.Instance.GetData(fileName, key, string.Format("Compare{0}", i))));
            //将每个参数添加到集合中
            parameterList.Add(parameter);
        }

        // 实例化 Transition
        Transition transition = new Transition((StateEnum)toState, parameterList);
        // 根据配置 currentState 获取状态
        StateBase stateBase = _stateDic[(StateEnum)currentState];
        // 将Transition 添加到状态中
        stateBase.TransitionList.Add(transition);
    }
    #endregion
}