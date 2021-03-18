#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class EffectConfigTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(EffectConfigTestHelper))]
public class EffectConfigTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif