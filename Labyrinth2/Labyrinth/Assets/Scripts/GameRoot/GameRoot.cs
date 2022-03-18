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
        go.transform.position = new Vector3(0.5f, 1.5f, 0);
        go.transform.localScale = Vector3.one * 0.2f;
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
            if (null == node)
            {
                Debug.LogError("node is null:" + go.transform.position.ToString("f2"));
            }
            else
            {
                Vector2 position = _labyrinthCreate.MapData.NodeToPosition(node);
                Debug.LogError(go.transform.position.ToString("f2") + "  Node:" + new Vector2Int(node.Row, node.Col) + "   position:" + position.x + ", " + position.y);
            }
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
