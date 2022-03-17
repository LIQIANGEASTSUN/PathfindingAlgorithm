using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public delegate void FingerGestureHandler(Vector2 position);
public class FingerGestureTouch
{

    private Rect _pickUpArea;  // 捡起区域
    //private Rect _activeArea;  // 作用区域

    private bool isPickUp = false;
    private int actionFingerId = -1;
    private List<Touch> touchList = new List<Touch>();
    private Touch actionTouch;

    private IRock _iRock;

    public FingerGestureTouch()
    {
    }

    public void Init(Rect pickUpArea, Rect activeArea)
    {
        _pickUpArea = pickUpArea;
        //_activeArea = activeArea;
    }

    public void SetRock(IRock iRock)
    {
        _iRock = iRock;
    }

    public bool IsWorking { get { return isPickUp; } }
    
    //RokerBtn手势处理，包含移动平台手指头的和鼠标点击并移动的，不包含键盘的
    public void ReceiveInout()
    {
        //获取Touch数组
        GetInput();
        //计算封装Touch为 Begin Move End
        Execute();
    }

    private int[] mouseIds = new int[] { 0/*, 1, 2*/ };
    private List<Touch> cacheTouchList = new List<Touch>();
    private void GetInput()
    {
        cacheTouchList.Clear();
        cacheTouchList.AddRange(touchList);

        touchList.Clear();

#if UNITY_EDITOR || UNITY_STANDALONE
        for (int i = 0; i < mouseIds.Length; ++i)
        {
            int id = mouseIds[i];
            int fingerId = i;// (1 << i);

            Touch touch = new Touch();
            touch.fingerId = fingerId;
            touch.position = Input.mousePosition;

            bool value = false;

            if (Input.GetMouseButtonDown(id))
            {
                touch.phase = TouchPhase.Began;
                value = true;
            }
            else if (Input.GetMouseButton(id))
            {
                bool isCache = false;
                Touch cacheTouch = GetTouch(fingerId, out isCache, cacheTouchList);
                if (isCache)
                {
                    Vector2 deltaPosition = touch.position - cacheTouch.position;
                    touch.deltaPosition = deltaPosition;
                    touch.phase = TouchPhase.Moved;
                }
                else
                {
                    touch.phase = TouchPhase.Stationary;
                }

                value = true;
            }
            else if (Input.GetMouseButtonUp(id))
            {
                touch.phase = TouchPhase.Ended;
                value = true;
            }

            if (value)
            {
                touchList.Add(touch);
            }
        }
#endif

#if (!UNITY_EDITOR) && (UNITY_IOS || UNITY_ANDROID)
        for (int i = 0; i < Input.touchCount; ++i)
        {
            Touch touch = Input.GetTouch(i);
            touchList.Add(touch);
        }
#endif
    }

    private bool isWaitCallBegan = false;
    private Vector2 beganPosition = Vector2.zero;
    private void Execute()
    {
        //还没有手势在执行，就可以检测是否有Began
        if (!isPickUp)
        {
            for (int i = 0; i < touchList.Count; ++i)
            {
                Touch touch = touchList[i];
                if (touch.phase == TouchPhase.Began)
                {
                    if (!_pickUpArea.Contains(touch.position))
                    {
                        continue;
                    }
                    
                    //点击在区域内，且状态是Began，就认为有手势开始
                    isPickUp = true;
                    //记录活跃手势和id，开始坐标
                    actionTouch = touch;
                    actionFingerId = actionTouch.fingerId;
                    //这个是为了记录是否要触发Began回调
                    isWaitCallBegan = true;
                    beganPosition = touch.position;
                    break;
                }
            }
        }
         
        //如果已经有手势Began了且还没End
        if (isPickUp)
        {
            bool isExist = false;
            //取得活跃的那根手指
            Touch touch = GetTouch(actionFingerId, out isExist);
            if (isExist)
            {
                if (touch.phase == TouchPhase.Moved || touch.phase == TouchPhase.Stationary)
                {
                    actionTouch = touch;
                    actionFingerId = actionTouch.fingerId;

                    //为啥判断第二次
                    if (actionTouch.phase == TouchPhase.Moved || actionTouch.phase == TouchPhase.Stationary)
                    {
                        //刚Began的
                        if (isWaitCallBegan)
                        {
                            if (actionTouch.deltaPosition.magnitude > 0)
                            {
                                BeginEvent(beganPosition);
                                isWaitCallBegan = false;
                                beganPosition = Vector2.zero;
                            }
                        }
                        //不是刚Began的
                        else
                        {
                            MoveEvent(actionTouch.position);
                        }
                    }
                }
                else if (touch.phase == TouchPhase.Ended)
                {
                    isPickUp = false;
                    actionFingerId = -1;
                    isWaitCallBegan = false;
                    EndEvent(touch.position);
                }
            }
            else
            {
                isPickUp = false;
                actionFingerId = -1;
                isWaitCallBegan = false;
                EndEvent(touch.position);
            }
        }
    }

    private Touch GetTouch(int fingerId, out bool value, List<Touch> list)
    {
        Touch touch = new Touch();
        value = false;

        for (int i = 0; i < list.Count; ++i)
        {
            if (fingerId == list[i].fingerId)
            {
                touch = list[i];
                value = true;
                //break;
            }
        }

        return touch;
    }

    private Touch GetTouch(int fingerId, out bool value)
    {
        return GetTouch(fingerId, out value, touchList);
    }

    private void BeginEvent(Vector2 pos)
    {
        if (null != _iRock)
        {
            _iRock.Begin(pos);
        }
    }

    private void MoveEvent(Vector2 pos)
    {
        if (null != _iRock)
        {
            _iRock.Move(pos, 1);
        }
    }

    private void EndEvent(Vector2 pos)
    {
        if (null != _iRock)
        {
            _iRock.End(pos);
        }
    }
}