#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class SkillTestTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(SkillTestTestHelper))]
public class SkillTestTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif