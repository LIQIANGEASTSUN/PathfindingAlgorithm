using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class UICamera
{
    public static readonly UICamera Instance = new UICamera();
    private Camera _uiCamera;

    public Camera Camera
    {
        get
        {
            if (null == _uiCamera)
            {
                _uiCamera = GameObject.Find("UIRoot").transform.Find("Camera").GetComponent<Camera>();
            }
            return _uiCamera;
        }
    }
}
