using System.Collections.Generic;
using UnityEngine;

public class UIManager : SingletonObject<UIManager>
{
    private int _instanceID = 0;
    private UIInfoController _uiInfoController;
    private UIConfigController _uiConfigController;

    private Transform _root;
    private Dictionary<string, Transform> _layerDic;

    public UIManager()
    {
        _uiInfoController = new UIInfoController();
        _uiConfigController = new UIConfigController();
        _root = GameObject.Find("UIRoot").transform;
        _layerDic = new Dictionary<string, Transform>();
    }

    public void Update()
    {
        IEnumerable<UIBasePlane> ie = _uiInfoController.GetIEnumerable();
        foreach(var plane in ie)
        {
            plane.Update();
        }
        _uiInfoController.Update();
    }

    /// <summary>
    /// 打开界面
    /// Mutual 从打开界面的栈中从后往前关闭UIConfig中配置的互斥面板
    /// Hungup 从打开界面的栈中从后往前挂起UIConfig中配置的挂起面板
    /// 原则：同一个界面同时只存在一个
    /// 如果要打开的界面已经打开了，例：打开界面 A，目前打开的界面顺
    /// 序为 A-B-C-D，则依次从栈中取出 D、C、B 并关闭，然后刷新界面A
    /// 为什么？避免出现 A-B-C-D-A-B-C-D-A-B-C-D 此类无限循环的界面
    /// </summary>
    public void Open(UIPlaneType type, IUIDataBase data)
    {
        Mutual(type);
        Hungup(type);
        UIPlaneInfo info = _uiInfoController.GetOpenPlaneInfo(type);
        if (null != info)
        {
            UIPlaneInfo lastInfo = _uiInfoController.LastOpenPlaneInfo();
            while (lastInfo.Type != type)
            {
                Close(lastInfo.Type);
                lastInfo = _uiInfoController.LastOpenPlaneInfo();
            }
        }
        Open(info, type, data);
    }

    /// <summary>
    /// 打开界面
    /// Mutual 从打开界面的栈中从后往前关闭UIConfig中配置的互斥面板
    /// Hungup 从打开界面的栈中从后往前挂起UIConfig中配置的挂起面板
    /// 原则：同一个界面同时只存在一个
    /// 如果要打开的界面已经打开了，例：打开界面 A，目前打开的界面顺
    /// 序为 A-B-C-D，则刷新界面A
    /// </summary>
    public void OpenOrRefresh(UIPlaneType type, IUIDataBase data)
    {
        Mutual(type);
        Hungup(type);
        UIPlaneInfo info = _uiInfoController.GetOpenPlaneInfo(type);
        Open(info, type, data);
    }

    private void Open(UIPlaneInfo info, UIPlaneType type, IUIDataBase data)
    {
        if (null == info)
        {
            info = _uiInfoController.GetRecyclePlaneInfo(type);
            if (null == info)
            {
                UIBasePlane plane = LoadPanel(type);
                plane.Init(type);
                info = new UIPlaneInfo(type, InstanceID(), plane);
            }
            _uiInfoController.AddOpenInfo(info);
        }
        if (!info.Plane.Tr.gameObject.activeInHierarchy)
        {
            info.Plane.Tr.gameObject.SetActive(true);
        }
        info.IsRecycle = false;
        info.Plane.OnEnter(data);
    }

    public void Close(UIPlaneType type)
    {
        UIPlaneInfo info = _uiInfoController.GetOpenPlaneInfo(type);
        if (null != info)
        {
            info.IsRecycle = true;
            info.RecycleTime = (int)Time.realtimeSinceStartup;
            info.Plane.Exit();
            info.Plane.Tr.gameObject.SetActive(false);
            _uiInfoController.RemoveCloseInfo(info);
        }
    }

    // 返回上一个界面
    public void Back()
    {
        UIPlaneInfo info = _uiInfoController.LastOpenPlaneInfo();
        if (null != info)
        {
            info.Plane.Resume();
        }
    }

    // 互斥面板，打开一个面板从后往前关掉互斥面板
    private void Mutual(UIPlaneType type)
    {
        UIConfig uiConfig = _uiConfigController.GetConfig(type);
        if (null == uiConfig || null == uiConfig.MutualHash)
        {
            return;
        }

        UIPlaneInfo info = _uiInfoController.LastOpenPlaneInfo();
        while (null != info)
        {
            if (!uiConfig.MutualHash.Contains(info.Type))
            {
                break;
            }
            Close(info.Type);
            info = _uiInfoController.LastOpenPlaneInfo();
        }
    }

    // 挂起面板，打开一个面板挂起最后一个面板
    private void Hungup(UIPlaneType type)
    {
        UIConfig uiConfig = _uiConfigController.GetConfig(type);
        if (null == uiConfig || null == uiConfig.HungupHash)
        {
            return;
        }

        UIPlaneInfo info = _uiInfoController.LastOpenPlaneInfo();
        if (uiConfig.HungupHash.Contains(info.Type))
        {
            info.Plane.HangUp();
        }
    }

    public bool IsOpen(UIPlaneType type)
    {
        UIPlaneInfo info = _uiInfoController.GetOpenPlaneInfo(type);
        return null != info;
    }

    private UIBasePlane LoadPanel(UIPlaneType type)
    {
        UIConfig uiConfig = _uiConfigController.GetConfig(type);
        if (null == uiConfig.BasePlane.Tr)
        {
            GameObject go = Resources.Load<GameObject>(uiConfig.AssetName);
            Transform layerTr = LayerTransform(uiConfig.Layer);
            GameObject instance = GameObject.Instantiate(go, layerTr);
            instance.transform.SetAsLastSibling();
            instance.transform.localScale = Vector3.one;
            instance.transform.rotation = Quaternion.identity;
            instance.transform.localPosition = Vector3.zero;
            uiConfig.BasePlane.Tr = instance.transform;
        }

        return uiConfig.BasePlane;
    }

    private Transform LayerTransform(string layerName)
    {
        Transform tr = null;
        if (!_layerDic.TryGetValue(layerName, out tr))
        {
            tr = _root.Find(layerName);
            _layerDic[layerName] = tr;
        }
        return tr;
    }

    private int InstanceID()
    {
        return ++_instanceID;
    }
}