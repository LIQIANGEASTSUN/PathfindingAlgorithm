using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using PathFinding;

public class GameRoot : MonoBehaviour
{
    public static GameRoot Instance;

    private LabyrinthCreate _labyrinthCreate;
    private AStar _aStar;
    private FindPath _findPath;
    // Start is called before the first frame update
    void Start()
    {
        Instance = this;
        ConfigLoad.Instance.Load(LoadConfigCallBack);
    }

    // Update is called once per frame
    void Update()
    {
        if (null != _findPath)
        {
            _findPath.Update();
        }
        RoleController.GetInstance().LateUpdate();
    }

    private void OnGUI()
    {
        if (null != _findPath)
        {
            _findPath.OnGUI();
        }
    }

    private void LoadConfigCallBack()
    {
        _labyrinthCreate = new LabyrinthCreate();
        _labyrinthCreate.Init();

        _aStar = new AStar(_labyrinthCreate.MapData);
        _findPath = new FindPath(_labyrinthCreate.MapData, _aStar);
    }

}
