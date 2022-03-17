using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameRoot : MonoBehaviour
{
    private LabyrinthCreate _labyrinthCreate;
    // Start is called before the first frame update
    void Start()
    {
        _labyrinthCreate = new LabyrinthCreate();
        _labyrinthCreate.Init();
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
