#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class SkillHsmConfigTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(SkillHsmConfigTestHelper))]
public class SkillHsmConfigTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif