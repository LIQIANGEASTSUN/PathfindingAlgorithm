#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class SkillConfigTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(SkillConfigTestHelper))]
public class SkillConfigTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif