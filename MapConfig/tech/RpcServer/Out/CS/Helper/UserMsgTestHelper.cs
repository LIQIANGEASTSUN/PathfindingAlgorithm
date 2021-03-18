#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class UserMsgTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(UserMsgTestHelper))]
public class UserMsgTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif