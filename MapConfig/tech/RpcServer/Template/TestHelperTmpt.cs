#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


$RpcAskHelper$


public class $Template$TestHelper : MonoBehaviour
{
$RpcAskVar$

$CallRpcFunction$

}

[CustomEditor(typeof($Template$TestHelper))]
public class $Template$Tester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
$CallRpcButton$

    }

}
#endif