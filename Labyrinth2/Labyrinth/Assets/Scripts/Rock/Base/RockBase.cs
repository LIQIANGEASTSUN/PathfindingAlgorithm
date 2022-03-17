using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RockBase : IRock
{
    public static RockGroupEnum workingGroup = RockGroupEnum.NONE;

    [SerializeField]
    protected RectTransform _target;
    protected float _targetAreaRadius = 0;
    //[SerializeField]
    //protected Vector2 _designScreen = GameConstants.GAME_RESOLUTION;
    [SerializeField]
    protected Rect _pickUpArea;
    [SerializeField]
    protected Rect _activeArea;
    [SerializeField]
    protected RockGroupEnum _group = RockGroupEnum.NONE;

    protected IRock _iRock;
    protected FingerGestureTouch fingerGestureTouch;
    protected Vector2 _originScreenPosition = Vector2.zero;
    protected Vector2 _startPosition = Vector2.zero;

    /// <summary>
    /// 
    /// </summary>
    /// <param name="target"></param>
    /// <param name="iRock"></param>
    /// <param name="minPickPos">拾取区域最小点坐标</param>
    /// <param name="pickSize">拾取区域宽高</param>
    /// <param name="minActiveCenter">作用区域最小点坐标</param>
    /// <param name="activeSize"></param>
    /// <param name="ignoreAllUI"></param>
    public void Init(RectTransform target, IRock iRock, Vector2 minPickPos, Vector2 pickSize, Vector2 minActiveCenter, Vector2 activeSize)
    {
        Rect pickUpArea = new Rect(minPickPos, pickSize);
        Rect activeArea = new Rect(minActiveCenter, activeSize);

        Init(target, iRock, pickUpArea, activeArea);
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="target"></param>
    /// <param name="iRock"></param>
    /// <param name="pickCenter">拾取区域中心点坐标</param>
    /// <param name="pickWidth">拾取区域宽</param>
    /// <param name="pickHeight">拾取区域高</param>
    /// <param name="activeCenter">有效区域中心点坐标</param>
    /// <param name="activeWidth"></param>
    /// <param name="activeHeight"></param>
    public void Init(RectTransform target, IRock iRock, Vector2 pickCenter, float pickWidth, float pickHeight, Vector2 activeCenter, float activeWidth, float activeHeight)
    {
        Rect pickUpArea = CreateRect(pickCenter, pickWidth, pickHeight);
        Rect activeArea = CreateRect(activeCenter, activeWidth, activeHeight);

        Init(target, iRock, pickUpArea, activeArea);
    }

    private void Init(RectTransform target, IRock iRock, Rect pickArea, Rect activeArea)
    {
        _target = target;
        _iRock = iRock;

        _pickUpArea = pickArea;
        _activeArea = activeArea; 

        fingerGestureTouch = new FingerGestureTouch();
        fingerGestureTouch.Init(_pickUpArea, _activeArea);
        fingerGestureTouch.SetRock(this);
    }

    public void TargetAreaRadiu(float radius)
    {
        _targetAreaRadius = radius;
    }

    private Rect CreateRect(Vector2 center, float width, float height)
    {
        float aspectWidth = Length(width);
        float aspectHeight = Length(height);

        center.x -= aspectWidth * 0.5f;
        center.y -= aspectHeight * 0.5f;
        Rect rect = new Rect(center, new Vector2(aspectWidth, aspectHeight));

        return rect;
    }

    public void SetGroup(RockGroupEnum group)
    {
        _group = group;
    }

    // Update is called once per frame
    public virtual void Update()
    {
        ReceiveInput();
    }

    public virtual void ReceiveInput()
    {
        if ((_group & workingGroup) == _group)
        {
            if (fingerGestureTouch.IsWorking)
            {
                fingerGestureTouch.ReceiveInout();
            }
        }
        else
        {
            fingerGestureTouch.ReceiveInout();
        }
    }

    private bool HasTarget { get { return null != _target; } }

    public void Begin(Vector2 pos)
    {
        workingGroup |= _group;

        pos = ConversionDevicePositionToDesignPosition(pos);
        _startPosition = pos;

        if (HasTarget)
        {
            _target.anchoredPosition = Vector3.zero;
            _originScreenPosition = Utility.PositionConvert.UIPositionToScreenPosition(_target.position);
        }

        if (null != _iRock)
        {
            _iRock.Begin(Vector2.zero);
        }
    }

    public void Move(Vector2 pos, float percentage)
    {
        pos = ConversionDevicePositionToDesignPosition(pos);
        float length = Length(_targetAreaRadius);
        if (HasTarget)
        {
            Vector2 offsetPos = pos - _startPosition;
            if ((offsetPos).magnitude > length)
            {
                offsetPos = offsetPos.normalized * length;
            }
            Vector2 newScreenPos = _originScreenPosition + offsetPos;

            Vector3 uiPos = Utility.PositionConvert.ScreenToUIPosition(_target, newScreenPos, UICamera.Instance.Camera);
            _target.position = uiPos;
        }

        if (null != _iRock)
        {
            Vector3 dir = (pos - _startPosition);
            percentage = (_targetAreaRadius > 0) ? (dir.magnitude / length) : 1;
            _iRock.Move(dir, percentage);
        }
    }

    public void End(Vector2 pos)
    {
        workingGroup &= ~_group;

        pos = ConversionDevicePositionToDesignPosition(pos);
        if (HasTarget)
        {
            _target.anchoredPosition3D = Vector3.zero;
        }

        if (null != _iRock)
        {
            _iRock.End(pos - _startPosition);
        }
    }

    private Vector2 ConversionDevicePositionToDesignPosition(Vector2 pos)
    {
        //float width = pos.x / Screen.width * _designScreen.x;
        //float hight = pos.y / Screen.height * _designScreen.y;
        //return new Vector2(width, hight);
        return pos;
    }

    public float Length(float length)
    {
        return UIUtils.GetInstance().GetUIRelativeLength(length);
    }

    #region 
    public void InitDrawArea()
    {
        if (null == Camera.main)
        {
            return;
        }

        GLDrawArea glDrawAre = Camera.main.transform.GetComponent<GLDrawArea>();
        if (null == glDrawAre)
        {
            glDrawAre = Camera.main.gameObject.AddComponent<GLDrawArea>();
        }

        glDrawAre.AddDreaArea(_pickUpArea, Color.green);
        glDrawAre.AddDreaArea(_activeArea, Color.blue);
    }
    #endregion
}
