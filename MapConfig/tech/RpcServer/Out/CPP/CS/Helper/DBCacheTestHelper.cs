#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class DBCacheTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(DBCacheTestHelper))]
public class DBCacheTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif