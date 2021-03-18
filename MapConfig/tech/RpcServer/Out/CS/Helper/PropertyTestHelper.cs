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
	public long Uid;
}
[System.Serializable]
public class PropertyRpcChangeHeadAskHelper
{
	public int HeadID;
}



public class PropertyTestHelper : MonoBehaviour
{
	public PropertyRpcSyncAskHelper PropertyRpcSyncAskVar;
	public PropertyRpcChangeHeadAskHelper PropertyRpcChangeHeadAskVar;


	public void TestSync()
	{
		PropertyRPC.Instance.Sync(PropertyRpcSyncAskVar.Uid,delegate(object obj){});
	}
	public void TestChangeHead()
	{
		PropertyRPC.Instance.ChangeHead(PropertyRpcChangeHeadAskVar.HeadID,delegate(object obj){});
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
		if (GUILayout.Button("ChangeHead"))
		{
			PropertyTestHelper rpc = target as PropertyTestHelper;
			if( rpc ) rpc.TestChangeHead();
		}


    }

}
#endif