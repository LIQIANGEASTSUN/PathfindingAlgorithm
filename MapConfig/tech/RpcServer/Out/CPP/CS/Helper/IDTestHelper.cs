#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class IDTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(IDTestHelper))]
public class IDTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif