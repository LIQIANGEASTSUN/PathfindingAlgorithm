using System.Collections.Generic;

public delegate bool TransitionCallback();
/// <summary>
/// 状态装换条件
/// </summary>
public class Transition
{
    // 切换状态事件
    private TransitionCallback _transitionCallback;
    private List<Parameter> _parameterList = new List<Parameter>();

    public Transition(StateEnum toState, TransitionCallback transitionCallback)
    {
        ToState = toState;
        _transitionCallback = transitionCallback;
    }

    public Transition(StateEnum toState, List<Parameter> parameterList)
    {
        ToState = toState;
        _parameterList = parameterList;
    }

    public StateEnum ToState { get; set; }

    public List<Parameter> ParameterList
    {
        get { return _parameterList; }
    }

    public bool CanTransition()
    {
        if (null == _transitionCallback)
        {
            return false;
        }
        return _transitionCallback();
    }
}

// 条件参数
public class Parameter
{
    // 参数名字
    public string _parameterName;
    // 参数类型
    public ParameterType _parameterType;
    // 参数比较类型
    public ParameterCompare _compare;
    // int 参考值
    public int intValue;
    // float 参考值
    public float floatValue;
    // bool 参考值
    public bool boolValue;
    // string参考值
    public string stringValue;

    /*
    Parameter parameter = new Parameter();
    // 参数名为 Age
    parameter._parameterName = "Age";
    // 参数类型为 int 类型
    parameter._parameterType = ParameterType.INT;
    // 参数 int参考值是 5
    parameter.intValue = 5;
    // 参数比较类型是 大于等于
    parameter._compare = ParameterCompare.GREATER_EQUALS;

    // 参数意思就是，我要和一个属性字段为Age的int类型值做比较，如果Age >= 5 则返回true
    */
}

// 参数类型
public enum ParameterType
{
    Int = 1,    // int 类型

    Float = 2,  // float 类型

    Bool = 3,   // bool 类型

    String = 4, // 字符串类型
}

// 参数比较类型
public enum ParameterCompare
{
    /// <summary>
    /// 无效值
    /// </summary>
    INVALID = 0,

    /// <summary>
    /// 大于
    /// </summary>
    GREATER = 1 << 0,

    /// <summary>
    /// 小于
    /// </summary>
    LESS = 1 << 1,

    /// <summary>
    /// 等于
    /// </summary>
    EQUALS = 1 << 2,

    /// <summary>
    /// 不等于
    /// </summary>
    NOT_EQUAL = 1 << 3,

    /// <summary>
    /// 大于等于
    /// </summary>
    GREATER_EQUALS = 1 << 4,

    /// <summary>
    /// 小于等于
    /// </summary>
    LESS_EQUAL = 1 << 5,
}