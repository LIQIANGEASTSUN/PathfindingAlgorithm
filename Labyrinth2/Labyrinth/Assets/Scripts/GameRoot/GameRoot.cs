using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using PathFinding;

public class GameRoot : MonoBehaviour
{
    private LabyrinthCreate _labyrinthCreate;
    private AStar _aStar;
    private FindPath _findPath;
    // Start is called before the first frame update
    void Start()
    {
        _labyrinthCreate = new LabyrinthCreate();
        _labyrinthCreate.Init();

        _aStar = new AStar(_labyrinthCreate.MapDataBase);
        _findPath = new FindPath(_labyrinthCreate.MapDataBase, _aStar);
    }

    // Update is called once per frame
    void Update()
    {
        _findPath.Update();
        RoleController.GetInstance().LateUpdate();
    }

    private void OnGUI()
    {
        _findPath.OnGUI();
    }
}
