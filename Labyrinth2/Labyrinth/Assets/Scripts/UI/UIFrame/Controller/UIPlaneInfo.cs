
public class UIPlaneInfo
{
    private UIPlaneType _type;
    private int _instanceID;
    private UIBasePlane _plane;
    private int _recycleTime;
    private bool _isRecycle;

    public UIPlaneInfo(UIPlaneType type, int instance, UIBasePlane plane)
    {
        _type = type;
        _instanceID = instance;
        _plane = plane;
    }

    public UIPlaneType Type
    {
        get { return _type; }
    }

    public int InstanceID
    {
        get { return _instanceID; }
    }

    public UIBasePlane Plane
    {
        get { return _plane; }
    }

    public bool IsRecycle
    {
        get { return _isRecycle; }
        set { _isRecycle = true; }
    }

    public int RecycleTime
    {
        get { return _recycleTime; }
        set { _recycleTime = value; }
    }
}
