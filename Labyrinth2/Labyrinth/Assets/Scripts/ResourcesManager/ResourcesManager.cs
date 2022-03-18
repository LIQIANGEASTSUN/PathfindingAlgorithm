using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ResourcesManager : SingletonObject<ResourcesManager>
{

    public T Load<T>(string name) where T : Object
    {
        return Resources.Load<T>(name);
    }

}
