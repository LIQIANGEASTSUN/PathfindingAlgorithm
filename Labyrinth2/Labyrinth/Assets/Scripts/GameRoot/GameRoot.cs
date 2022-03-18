using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameRoot : MonoBehaviour
{
    public static GameRoot Instance;
    private Level _level;

    // Start is called before the first frame update
    void Start()
    {
        Instance = this;
        ConfigLoad.Instance.Load(LoadConfigCallBack);
    }

    // Update is called once per frame
    void Update()
    {
        if (null != _level)
        {
            _level.Update();
        }
    }

    private void LoadConfigCallBack()
    {
        _level = new Level();
    }

}
