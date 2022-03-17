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

        go = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        go.transform.position = new Vector3(0, 0, -1);
    }

    // Update is called once per frame
    void Update()
    {
        if (null != _findPath)
        {
            _findPath.Update();
        }
        RoleController.GetInstance().LateUpdate();

        if (Input.GetKeyDown(KeyCode.A))
        {
            Node node = _labyrinthCreate.MapData.PositionToNode(go.transform.position.x, go.transform.position.y);
            Debug.LogError(node.Row + "   " + node.Col);
        }
    }

    private GameObject go;

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
