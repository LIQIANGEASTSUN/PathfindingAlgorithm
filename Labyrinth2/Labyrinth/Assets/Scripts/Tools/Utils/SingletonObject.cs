using System;
using System.Collections;
using System.Reflection;
using UnityEngine;

/// <summary>
/// 
/// 泛型类不得作为单例或静态
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
public abstract class SingletonObject<T> : System.Object where T : SingletonObject<T>, new() {

    private static T _instance;

    private static readonly object syslock = new object();

    public static T GetInstance() {
        if (null == _instance) {
            CreateInstance();
        }
        return _instance;
    }

    private static void CreateInstance() {
        lock (syslock) {
            if (null == _instance) {
                _instance = new T();
            }
        }
    }

    public virtual void Destroy() {
        _instance = null;
    }

}