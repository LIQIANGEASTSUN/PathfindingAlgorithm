using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class RoleView : MonoBehaviour
{
    private TPPMoveAndRotateRocker _tPPMoveAndRotateRocker;
    private Transform _rockerBtnTr;
    private Button _pathFindBtn;

    // Start is called before the first frame update
    void Start()
    {
        _rockerBtnTr = transform.Find("ThirdPersonPerspective/TPPMoveAndRotateRocker");
        _tPPMoveAndRotateRocker = new TPPMoveAndRotateRocker(_rockerBtnTr);

        _pathFindBtn = transform.Find("PathFindBtn").GetComponent<Button>();
        _pathFindBtn.onClick.AddListener(PathFindClick);
    }

    // Update is called once per frame
    void Update()
    {
        _tPPMoveAndRotateRocker.Update();
    }

    private void PathFindClick()
    {
        GameNotifycation.GetInstance().Notify(ENUM_MSG_TYPE.MSG_PATH_FIND);
    }

}
