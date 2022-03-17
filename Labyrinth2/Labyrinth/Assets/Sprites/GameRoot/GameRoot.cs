using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameRoot : MonoBehaviour
{
    private LabyrinthCreate _labyrinthCreate;
    private LabyrinthLogic _labyrinthLogic;
    // Start is called before the first frame update
    void Start()
    {
        _labyrinthCreate = new LabyrinthCreate();
        _labyrinthCreate.Init();

        _labyrinthLogic = new LabyrinthLogic(_labyrinthCreate.MapDataBase);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
