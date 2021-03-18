#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class SaidRpcSaidAskHelper
{
	public SaidSaidData Value;
}



public class SaidTestHelper : MonoBehaviour
{
	public SaidRpcSaidAskHelper SaidRpcSaidAskVar;


	public void TestSaid()
	{
		SaidRPC.Instance.Said(SaidRpcSaidAskVar.Value,delegate(object obj){});
	}


}

[CustomEditor(typeof(SaidTestHelper))]
public class SaidTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Said"))
		{
			SaidTestHelper rpc = target as SaidTestHelper;
			if( rpc ) rpc.TestSaid();
		}


    }

}
#endif