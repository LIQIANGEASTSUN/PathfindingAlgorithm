#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class HeroRpcSyncAskHelper
{
}
[System.Serializable]
public class HeroRpcActiveAskHelper
{
	public int HeroID;
}



public class HeroTestHelper : MonoBehaviour
{
	public HeroRpcSyncAskHelper HeroRpcSyncAskVar;
	public HeroRpcActiveAskHelper HeroRpcActiveAskVar;


	public void TestSync()
	{
		HeroRPC.Instance.Sync(delegate(object obj){});
	}
	public void TestActive()
	{
		HeroRPC.Instance.Active(HeroRpcActiveAskVar.HeroID,delegate(object obj){});
	}


}

[CustomEditor(typeof(HeroTestHelper))]
public class HeroTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Sync"))
		{
			HeroTestHelper rpc = target as HeroTestHelper;
			if( rpc ) rpc.TestSync();
		}
		if (GUILayout.Button("Active"))
		{
			HeroTestHelper rpc = target as HeroTestHelper;
			if( rpc ) rpc.TestActive();
		}


    }

}
#endif