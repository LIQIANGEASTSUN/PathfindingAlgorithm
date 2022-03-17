using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// 游戏中操作人的摇杆
/// </summary>
public class RoleRockerInput : IRock
{
    private RockBase _rockBase;
    private KeyBoardInput _keyBoardInput;

    // 摇杆随手移动的小球移动距离范围
    private float _targetAreaRadius = 0;

    // 拖拽百分比:拖拽距离 / _targetAreaRadius 得值
    private float _maxPercentage = 1;

    private List<IRock> _rockList = new List<IRock>();
    public RoleRockerInput(Transform rockerBtnTr)
    {
        Init(rockerBtnTr);
    }

    public void AddRocker(IRock rock)
    {
        _rockList.Add(rock);
    }

    private void Init(Transform rockerBtnTr)
    {
        // 随着手一动的小球
        RectTransform target = rockerBtnTr.Find("RockerBackground/Rocker").GetComponent<RectTransform>();
        RectTransform targetBg = rockerBtnTr.Find("RockerBackground").GetComponent<RectTransform>();

        // 设置开始拖拽区域为：从屏幕左下角到屏幕正中间之间的位置
        // 只要是在左侧屏幕开始拖拽，都能产生拖拽效果
        Vector2 minPickPos = new Vector2(0, 0);
        Vector2 pickSize = new Vector2(Screen.width * 0.5f, Screen.height);
        Vector2 minActivePos = minPickPos;
        // 设置拖拽过程中手指在activeSize范围内都可以拖动
        Vector2 activeSize = new Vector2(Screen.width, Screen.height);
        _targetAreaRadius = (targetBg.rect.width * 0.5f) - (target.rect.width * 0.5f) - 2f;

        _rockBase = new RockBase();
        _rockBase.Init(target, this, minPickPos, pickSize, minActivePos, activeSize);
        _rockBase.TargetAreaRadiu(_targetAreaRadius);
        _rockBase.SetGroup(RockGroupEnum.ROLE_ROCK);

        _keyBoardInput = new KeyBoardInput(_rockBase, _targetAreaRadius, _maxPercentage);
    }

    public void Update()
    {
        _rockBase.Update();
        _keyBoardInput.Update();
    }

    public void Begin(Vector2 pos)
    {
        foreach(var rocker in _rockList)
        {
            rocker.Begin(pos);
        }
    }

    public void Move(Vector2 pos, float percentage)
    {
        percentage = Mathf.Clamp(percentage, 0, _maxPercentage);
        if (pos.sqrMagnitude > 0 && percentage > 0)
        {
            foreach (var rocker in _rockList)
            {
                rocker.Move(pos, percentage);
            }
        }
    }

    public void End(Vector2 pos)
    {
        foreach (var rocker in _rockList)
        {
            rocker.End(pos);
        }
    }
}

// 在Windows 编辑器下操作键盘 W/A/S/D 也可以控制摇杆 
public class KeyBoardInput
{
    private RockBase _rockBase;
    private float _targetAreaRadius = 0;
    private float _maxPercentage = 1;
    public KeyBoardInput(RockBase rockBase, float targetAreaRadius, float maxPercentage)
    {
        _rockBase = rockBase;
        _targetAreaRadius = targetAreaRadius;
        _maxPercentage = maxPercentage;
    }

    public void Update()
    {
#if UNITY_EDITOR || UNITY_STANDALONE
        KeyDown();
#endif
    }

    private int keyDown = 0;
    private Vector2 dir = Vector2.zero;
    private KeyCode[] keyCodeArr = new KeyCode[4] { KeyCode.W, KeyCode.A, KeyCode.S, KeyCode.D };
    private Vector2[] dirArr = new Vector2[4] { Vector2.up, Vector2.left, Vector2.down, Vector2.right };
    private void KeyDown()
    {
        int newKeyDown = 0;
        dir = Vector2.zero;

        for (int i = 0; i < keyCodeArr.Length; ++i)
        {
            KeyCode keyCode = keyCodeArr[i];
            if (Input.GetKeyDown(keyCode) || Input.GetKey(keyCode))
            {
                newKeyDown |= 1 << i;
                dir += dirArr[i];
            }
        }

        if (keyDown == 0)
        {
            if (newKeyDown != 0)
            {
                _rockBase.Begin(Vector2.zero);
            }
        }
        else
        {
            if (newKeyDown == 0)
            {
                _rockBase.End(dir);
            }
            else
            {
                float length = _rockBase.Length(_targetAreaRadius) * _maxPercentage;
                _rockBase.Move(dir * length, 1);
            }
        }

        keyDown = newKeyDown;
    }
}