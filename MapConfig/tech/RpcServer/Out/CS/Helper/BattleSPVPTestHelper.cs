#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class BattleSPVPTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(BattleSPVPTestHelper))]
public class BattleSPVPTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif