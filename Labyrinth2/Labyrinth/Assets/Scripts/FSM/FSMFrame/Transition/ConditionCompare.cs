using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public static class ConditionCompare
{

    public static bool CompareParameter(Parameter environment, Parameter parameter)
    {
        ParameterCompare behaviorCompare = ParameterCompare.INVALID;
        if (parameter._parameterType != environment._parameterType)
        {
            return false;
        }

        if (parameter._parameterType == ParameterType.Float)
        {
            behaviorCompare = CompareFloat(environment.floatValue, parameter.floatValue);
        }
        else if (parameter._parameterType == ParameterType.Int)
        {
            behaviorCompare = CompareInt(environment.intValue, parameter.intValue);
        }
        else if (parameter._parameterType == ParameterType.Bool)
        {
            behaviorCompare = CompareBool(environment.boolValue, parameter.boolValue);
        }
        else if (parameter._parameterType == ParameterType.String)
        {
            behaviorCompare = CompareString(environment.stringValue, parameter.stringValue);
        }

        return (behaviorCompare & parameter._compare) != 0;
    }

    private static ParameterCompare CompareFloat(float floatValue1, float floatValue2)
    {
        ParameterCompare BehaviorCompare = ParameterCompare.INVALID;
        if (floatValue1 > floatValue2)
        {
            BehaviorCompare |= ParameterCompare.GREATER;
        }
        else if (floatValue1 < floatValue2)
        {
            BehaviorCompare |= ParameterCompare.LESS;
        }

        return BehaviorCompare;
    }

    private static ParameterCompare CompareInt(int intValue1, int intValue2)
    {
        ParameterCompare behaviorCompare = ParameterCompare.INVALID;
        if (intValue1 > intValue2)
        {
            behaviorCompare |= ParameterCompare.GREATER;
            behaviorCompare |= ParameterCompare.NOT_EQUAL;
        }
        else if (intValue1 < intValue2)
        {
            behaviorCompare |= ParameterCompare.LESS;
            behaviorCompare |= ParameterCompare.NOT_EQUAL;
        }
        else
        {
            behaviorCompare |= ParameterCompare.EQUALS;
        }

        if (intValue1 >= intValue2)
        {
            behaviorCompare |= ParameterCompare.GREATER_EQUALS;
        }

        if (intValue1 <= intValue2)
        {
            behaviorCompare |= ParameterCompare.LESS_EQUAL;
        }

        return behaviorCompare;
    }

    private static ParameterCompare CompareBool(bool boolValue1, bool boolValue2)
    {
        ParameterCompare behaviorCompare = (boolValue1 == boolValue2) ? ParameterCompare.EQUALS : ParameterCompare.NOT_EQUAL;
        return behaviorCompare;
    }

    private static ParameterCompare CompareString(string stringValue1, string stringValue2)
    {
        ParameterCompare behaviorCompare = (stringValue1.CompareTo(stringValue2) == 0) ? ParameterCompare.EQUALS : ParameterCompare.NOT_EQUAL;
        return behaviorCompare;
    }
}
