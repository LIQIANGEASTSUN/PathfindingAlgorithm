using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class UIBasePlane : IUIController
{
    protected UIPlaneType _planeType;
    protected Transform _tr;
    protected IUIDataBase _data;
    private IUIView _view;
    private IUIModel _model;

    public virtual void Init(UIPlaneType type)
    {
        _planeType = type;
    }

    public virtual void OnEnter(IUIDataBase data)
    {
        _data = data;
        View.Init(_tr, this);
        Model.Init(data);
    }

    public virtual void Exit()
    {
    }

    public virtual void Update()
    {
    }

    public virtual void HangUp()
    {
    }

    public virtual void Resume()
    {
    }

    public void Close()
    {
        UIManager.GetInstance().Close(_planeType);
    }

    protected void Back()
    {
        UIManager.GetInstance().Back();
    }

    public Transform Tr
    {
        get { return _tr; }
        set { _tr = value; }
    }

    protected IUIView View
    {
        get {
            return _view;
        }
        set { _view = value; }
    }

    protected IUIModel Model
    {
        get { return _model; }
        set { _model = value; }
    }
}
