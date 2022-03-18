using System;
using System.Collections;
using System.Collections.Generic;

public class GameNotifycation : SingletonObject<GameNotifycation>
{

    //Handle
    public delegate void NotifycationDelegate();
    public delegate void NotifycationDelegate<T>(T args);

    public delegate void NotifycationDelegate<T1, T2>(T1 args1, T2 args2);
    public delegate void NotifycationDelegate<T1, T2, T3>(T1 args1, T2 args2, T3 args3);
    public delegate void NotifycationDelegate<T1, T2, T3, T4>(T1 args1, T2 args2, T3 args3, T4 args4);
    public delegate void NotifycationDelegate<T1, T2, T3, T4, T5>(T1 args1, T2 args2, T3 args3, T4 args4, T5 args5);
    public delegate void NotifycationDelegate<T1, T2, T3, T4, T5, T6>(T1 args1, T2 args2, T3 args3, T4 args4, T5 args5, T6 args6);
    public delegate void NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7>(T1 args1, T2 args2, T3 args3, T4 args4, T5 args5, T6 args6, T7 args7);
    public delegate void NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7, T8>(T1 args1, T2 args2, T3 args3, T4 args4, T5 args5, T6 args6, T7 args7, T8 args8);
    public delegate void NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7, T8, T9>(T1 args1, T2 args2, T3 args3, T4 args4, T5 args5, T6 args6, T7 args7, T8 args8, T9 args9);

    private Dictionary<ENUM_MSG_TYPE, Delegate> eventListeners = new Dictionary<ENUM_MSG_TYPE, Delegate>();

    #region AddListener

    //添加监听
    public void AddEventListener(ENUM_MSG_TYPE msgType, NotifycationDelegate listener)
    {
        AddEventListener(msgType, (Delegate)listener);
    }

    public void AddEventListener<T>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T> listener)
    {
        AddEventListener(msgType, (Delegate)listener);
    }

    public void AddEventListener<T1, T2>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2> listener)
    {
        AddEventListener(msgType, (Delegate)listener);
    }
    public void AddEventListener<T1, T2, T3>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3> listener)
    {
        AddEventListener(msgType, (Delegate)listener);
    }
    public void AddEventListener<T1, T2, T3, T4>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4> listener)
    {
        AddEventListener(msgType, (Delegate)listener);
    }
    public void AddEventListener<T1, T2, T3, T4, T5>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4, T5> listener)
    {
        AddEventListener(msgType, (Delegate)listener);
    }

    public void AddEventListener<T1, T2, T3, T4, T5, T6>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4, T5, T6> listener)
    {
        AddEventListener(msgType, (Delegate)listener);
    }

    public void AddEventListener<T1, T2, T3, T4, T5, T6, T7>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7> listener)
    {
        AddEventListener(msgType, (Delegate)listener);
    }

    public void AddEventListener<T1, T2, T3, T4, T5, T6, T7, T8>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7, T8> listener)
    {
        AddEventListener(msgType, (Delegate)listener);
    }
    public void AddEventListener<T1, T2, T3, T4, T5, T6, T7, T8, T9>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7, T8, T9> listener)
    {
        AddEventListener(msgType, (Delegate)listener);
    }
    private void AddEventListener(ENUM_MSG_TYPE msgType, Delegate cb)
    {
        if (!HasEventListener(msgType))
        {
            eventListeners[msgType] = null;
        }
        Delegate lis = eventListeners[msgType];
        eventListeners[msgType] = Delegate.Combine(lis, cb);
    }

    #endregion

    #region RemoveListener

    //移除监听
    public void RemoveEventListener(ENUM_MSG_TYPE msgType, NotifycationDelegate listener)
    {
        RemoveEventListener(msgType, (Delegate)listener);
    }
    public void RemoveEventListener<T>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T> listener)
    {
        RemoveEventListener(msgType, (Delegate)listener);
    }
    public void RemoveEventListener<T1, T2>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2> listener)
    {
        RemoveEventListener(msgType, (Delegate)listener);
    }
    public void RemoveEventListener<T1, T2, T3>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3> listener)
    {
        RemoveEventListener(msgType, (Delegate)listener);
    }
    public void RemoveEventListener<T1, T2, T3, T4>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4> listener)
    {
        RemoveEventListener(msgType, (Delegate)listener);
    }
    public void RemoveEventListener<T1, T2, T3, T4, T5>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4, T5> listener)
    {
        RemoveEventListener(msgType, (Delegate)listener);
    }

    public void RemoveEventListener<T1, T2, T3, T4, T5, T6>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4, T5, T6> listener)
    {
        RemoveEventListener(msgType, (Delegate)listener);
    }

    public void RemoveEventListener<T1, T2, T3, T4, T5, T6, T7>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7> listener)
    {
        RemoveEventListener(msgType, (Delegate)listener);
    }

    public void RemoveEventListener<T1, T2, T3, T4, T5, T6, T7, T8>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7, T8> listener)
    {
        RemoveEventListener(msgType, (Delegate)listener);
    }
    public void RemoveEventListener<T1, T2, T3, T4, T5, T6, T7, T8, T9>(ENUM_MSG_TYPE msgType, NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7, T8, T9> listener)
    {
        RemoveEventListener(msgType, (Delegate)listener);
    }
    private void RemoveEventListener(ENUM_MSG_TYPE msgType, Delegate cb)
    {
        if (HasEventListener(msgType))
        {
            Delegate lis = eventListeners[msgType];
            eventListeners[msgType] = Delegate.Remove(lis, cb);
            if (null == eventListeners[msgType])
            {
                RemoveEventListener(msgType);
            }
        }
    }

    public void RemoveEventListener(ENUM_MSG_TYPE msgType)
    {
        eventListeners.Remove(msgType);
    }

    #endregion

    #region Notify
    public void Notify(ENUM_MSG_TYPE msgType)
    {
        if (HasEventListener(msgType))
        {
            ((NotifycationDelegate)eventListeners[msgType])();
        }
    }
    public void Notify<T>(ENUM_MSG_TYPE msgType, T args)
    {
        if (HasEventListener(msgType))
        {
            ((NotifycationDelegate<T>)eventListeners[msgType])(args);
        }
    }
    public void Notify<T1, T2>(ENUM_MSG_TYPE msgType, T1 args1, T2 args2)
    {
        if (HasEventListener(msgType))
        {
            ((NotifycationDelegate<T1, T2>)eventListeners[msgType])(args1, args2);
        }
    }
    public void Notify<T1, T2, T3>(ENUM_MSG_TYPE msgType, T1 args1, T2 args2, T3 args3)
    {
        if (HasEventListener(msgType))
        {
            ((NotifycationDelegate<T1, T2, T3>)eventListeners[msgType])(args1, args2, args3);
        }
    }
    public void Notify<T1, T2, T3, T4>(ENUM_MSG_TYPE msgType, T1 args1, T2 args2, T3 args3, T4 args4)
    {
        if (HasEventListener(msgType))
        {
            ((NotifycationDelegate<T1, T2, T3, T4>)eventListeners[msgType])(args1, args2, args3, args4);
        }
    }
    public void Notify<T1, T2, T3, T4, T5>(ENUM_MSG_TYPE msgType, T1 args1, T2 args2, T3 args3, T4 args4, T5 args5)
    {
        if (HasEventListener(msgType))
        {
            ((NotifycationDelegate<T1, T2, T3, T4, T5>)eventListeners[msgType])(args1, args2, args3, args4, args5);
        }
    }

    public void Notify<T1, T2, T3, T4, T5, T6>(ENUM_MSG_TYPE msgType, T1 args1, T2 args2, T3 args3, T4 args4, T5 args5, T6 args6)
    {
        if (HasEventListener(msgType))
        {
            ((NotifycationDelegate<T1, T2, T3, T4, T5, T6>)eventListeners[msgType])(args1, args2, args3, args4, args5, args6);
        }
    }

    public void Notify<T1, T2, T3, T4, T5, T6, T7>(ENUM_MSG_TYPE msgType, T1 args1, T2 args2, T3 args3, T4 args4, T5 args5, T6 args6, T7 args7)
    {
        if (HasEventListener(msgType))
        {
            ((NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7>)eventListeners[msgType])(args1, args2, args3, args4, args5, args6, args7);
        }
    }

    public void Notify<T1, T2, T3, T4, T5, T6, T7, T8>(ENUM_MSG_TYPE msgType, T1 args1, T2 args2, T3 args3, T4 args4, T5 args5, T6 args6, T7 args7, T8 args8)
    {
        if (HasEventListener(msgType))
        {
            ((NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7, T8>)eventListeners[msgType])(args1, args2, args3, args4, args5, args6, args7, args8);
        }
    }
    public void Notify<T1, T2, T3, T4, T5, T6, T7, T8, T9>(ENUM_MSG_TYPE msgType, T1 args1, T2 args2, T3 args3, T4 args4, T5 args5, T6 args6, T7 args7, T8 args8, T9 args9)
    {
        if (HasEventListener(msgType))
        {
            ((NotifycationDelegate<T1, T2, T3, T4, T5, T6, T7, T8, T9>)eventListeners[msgType])(args1, args2, args3, args4, args5, args6, args7, args8, args9);
        }
    }
    #endregion

    //是否存在指定事件的监听
    public bool HasEventListener(ENUM_MSG_TYPE msgType)
    {
        return eventListeners.ContainsKey(msgType);
    }
}
