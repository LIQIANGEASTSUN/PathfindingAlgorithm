#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class MysqlShardingTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(MysqlShardingTestHelper))]
public class MysqlShardingTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif