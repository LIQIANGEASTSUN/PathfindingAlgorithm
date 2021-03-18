#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class LoginRpcReadyAskHelper
{
}



public class LoginTestHelper : MonoBehaviour
{
	public LoginRpcReadyAskHelper LoginRpcReadyAskVar;


	public void TestReady()
	{
		LoginRPC.Instance.Ready(delegate(object obj){});
	}


}

[CustomEditor(typeof(LoginTestHelper))]
public class LoginTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Ready"))
		{
			LoginTestHelper rpc = target as LoginTestHelper;
			if( rpc ) rpc.TestReady();
		}


    }

}
#endif