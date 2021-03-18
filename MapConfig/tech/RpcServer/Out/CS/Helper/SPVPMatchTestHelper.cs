#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class SPVPMatchRpcStartMatchAskHelper
{
}
[System.Serializable]
public class SPVPMatchRpcInvitationAskHelper
{
	public long Uid;
}
[System.Serializable]
public class SPVPMatchRpcAgreeInvitationNotifyHelper
{
	public long Uid;
	public int IsAgree;
	public int Type;
}
[System.Serializable]
public class SPVPMatchRpcSelectHeroAskHelper
{
	public int HeroID;
}
[System.Serializable]
public class SPVPMatchRpcGetStatusAskHelper
{
}



public class SPVPMatchTestHelper : MonoBehaviour
{
	public SPVPMatchRpcStartMatchAskHelper SPVPMatchRpcStartMatchAskVar;
	public SPVPMatchRpcInvitationAskHelper SPVPMatchRpcInvitationAskVar;
	public SPVPMatchRpcAgreeInvitationNotifyHelper SPVPMatchRpcAgreeInvitationNotifyVar;
	public SPVPMatchRpcSelectHeroAskHelper SPVPMatchRpcSelectHeroAskVar;
	public SPVPMatchRpcGetStatusAskHelper SPVPMatchRpcGetStatusAskVar;


	public void TestStartMatch()
	{
		SPVPMatchRPC.Instance.StartMatch(delegate(object obj){});
	}
	public void TestInvitation()
	{
		SPVPMatchRPC.Instance.Invitation(SPVPMatchRpcInvitationAskVar.Uid,delegate(object obj){});
	}
	public void TestAgreeInvitation()
	{
		SPVPMatchRPC.Instance.AgreeInvitation(SPVPMatchRpcAgreeInvitationNotifyVar.Uid,SPVPMatchRpcAgreeInvitationNotifyVar.IsAgree,SPVPMatchRpcAgreeInvitationNotifyVar.Type);
	}
	public void TestSelectHero()
	{
		SPVPMatchRPC.Instance.SelectHero(SPVPMatchRpcSelectHeroAskVar.HeroID,delegate(object obj){});
	}
	public void TestGetStatus()
	{
		SPVPMatchRPC.Instance.GetStatus(delegate(object obj){});
	}


}

[CustomEditor(typeof(SPVPMatchTestHelper))]
public class SPVPMatchTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("StartMatch"))
		{
			SPVPMatchTestHelper rpc = target as SPVPMatchTestHelper;
			if( rpc ) rpc.TestStartMatch();
		}
		if (GUILayout.Button("Invitation"))
		{
			SPVPMatchTestHelper rpc = target as SPVPMatchTestHelper;
			if( rpc ) rpc.TestInvitation();
		}
		if (GUILayout.Button("AgreeInvitation"))
		{
			SPVPMatchTestHelper rpc = target as SPVPMatchTestHelper;
			if( rpc ) rpc.TestAgreeInvitation();
		}
		if (GUILayout.Button("SelectHero"))
		{
			SPVPMatchTestHelper rpc = target as SPVPMatchTestHelper;
			if( rpc ) rpc.TestSelectHero();
		}
		if (GUILayout.Button("GetStatus"))
		{
			SPVPMatchTestHelper rpc = target as SPVPMatchTestHelper;
			if( rpc ) rpc.TestGetStatus();
		}


    }

}
#endif