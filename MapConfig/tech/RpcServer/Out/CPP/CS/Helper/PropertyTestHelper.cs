#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class PropertyRpcSyncAskHelper
{
}



public class PropertyTestHelper : MonoBehaviour
{
	public PropertyRpcSyncAskHelper PropertyRpcSyncAskVar;


	public void TestSync()
	{
		PropertyRPC.Instance.Sync(delegate(object obj){});
	}


}

[CustomEditor(typeof(PropertyTestHelper))]
public class PropertyTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Sync"))
		{
			PropertyTestHelper rpc = target as PropertyTestHelper;
			if( rpc ) rpc.TestSync();
		}


    }

}
#endif