using System.Collections.Generic;

public class UIConfig
{
    private UIPlaneType _type;
    private UIBasePlane _basePlane;
    private string _assetName;
    private string _layer;
    // 互斥面板
    private HashSet<UIPlaneType> _mutualHash;
    // 挂起面板
    private HashSet<UIPlaneType> _hungupHash;
    public UIConfig(UIPlaneType type, UIBasePlane basePlane, string assetName, string layer)
    {
        _type = type;
        _basePlane = basePlane;
        _assetName = assetName;
        _layer = layer;
    }

    public void SetMutualHash(HashSet<UIPlaneType> hash)
    {
        _mutualHash = hash;
    }

    public void SetHungupHash(HashSet<UIPlaneType> hash)
    {
        _hungupHash = hash;
    }

    public UIPlaneType Type
    {
        get { return _type; }
    }

    public UIBasePlane BasePlane
    {
        get { return _basePlane; }
    }

    public string AssetName
    {
        get { return _assetName; }
    }

    public string Layer
    {
        get { return _layer; }
    }

    public HashSet<UIPlaneType> MutualHash
    {
        get { return _mutualHash; }
    }

    public HashSet<UIPlaneType> HungupHash
    {
        get { return _hungupHash; }
    }
}

public enum UIPlaneType
{
    Scene_Loading,   // Scene Loading 

    Role_Operation,  // 角色操作界面
}