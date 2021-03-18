#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class AuthRpcAuthAskHelper
{
	public string UserName;
	public string PassWord;
}



public class AuthTestHelper : MonoBehaviour
{
	public AuthRpcAuthAskHelper AuthRpcAuthAskVar;


	public void TestAuth()
	{
		AuthRPC.Instance.Auth(AuthRpcAuthAskVar.UserName,AuthRpcAuthAskVar.PassWord,delegate(object obj){});
	}


}

[CustomEditor(typeof(AuthTestHelper))]
public class AuthTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Auth"))
		{
			AuthTestHelper rpc = target as AuthTestHelper;
			if( rpc ) rpc.TestAuth();
		}


    }

}
#endif