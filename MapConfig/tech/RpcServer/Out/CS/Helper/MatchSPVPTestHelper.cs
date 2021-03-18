#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class MatchSPVPRpcStartMatchAskHelper
{
	public int IsMatch;
	public int SceneID;
	public int ActiveID;
	public long TeamID;
}
[System.Serializable]
public class MatchSPVPRpcInvitationAskHelper
{
	public long Uid;
}
[System.Serializable]
public class MatchSPVPRpcAgreeInvitationNotifyHelper
{
	public long Uid;
	public int IsAgree;
	public int Type;
}
[System.Serializable]
public class MatchSPVPRpcSelectHeroAskHelper
{
	public int HeroID;
}
[System.Serializable]
public class MatchSPVPRpcGetStatusAskHelper
{
}
[System.Serializable]
public class MatchSPVPRpcShotOffAskHelper
{
	public long Uid;
}
[System.Serializable]
public class MatchSPVPRpcSelectSceneNotifyHelper
{
	public int SceneID;
}



public class MatchSPVPTestHelper : MonoBehaviour
{
	public MatchSPVPRpcStartMatchAskHelper MatchSPVPRpcStartMatchAskVar;
	public MatchSPVPRpcInvitationAskHelper MatchSPVPRpcInvitationAskVar;
	public MatchSPVPRpcAgreeInvitationNotifyHelper MatchSPVPRpcAgreeInvitationNotifyVar;
	public MatchSPVPRpcSelectHeroAskHelper MatchSPVPRpcSelectHeroAskVar;
	public MatchSPVPRpcGetStatusAskHelper MatchSPVPRpcGetStatusAskVar;
	public MatchSPVPRpcShotOffAskHelper MatchSPVPRpcShotOffAskVar;
	public MatchSPVPRpcSelectSceneNotifyHelper MatchSPVPRpcSelectSceneNotifyVar;


	public void TestStartMatch()
	{
		MatchSPVPRPC.Instance.StartMatch(MatchSPVPRpcStartMatchAskVar.IsMatch,MatchSPVPRpcStartMatchAskVar.SceneID,MatchSPVPRpcStartMatchAskVar.ActiveID,MatchSPVPRpcStartMatchAskVar.TeamID,delegate(object obj){});
	}
	public void TestInvitation()
	{
		MatchSPVPRPC.Instance.Invitation(MatchSPVPRpcInvitationAskVar.Uid,delegate(object obj){});
	}
	public void TestAgreeInvitation()
	{
		MatchSPVPRPC.Instance.AgreeInvitation(MatchSPVPRpcAgreeInvitationNotifyVar.Uid,MatchSPVPRpcAgreeInvitationNotifyVar.IsAgree,MatchSPVPRpcAgreeInvitationNotifyVar.Type);
	}
	public void TestSelectHero()
	{
		MatchSPVPRPC.Instance.SelectHero(MatchSPVPRpcSelectHeroAskVar.HeroID,delegate(object obj){});
	}
	public void TestGetStatus()
	{
		MatchSPVPRPC.Instance.GetStatus(delegate(object obj){});
	}
	public void TestShotOff()
	{
		MatchSPVPRPC.Instance.ShotOff(MatchSPVPRpcShotOffAskVar.Uid,delegate(object obj){});
	}
	public void TestSelectScene()
	{
		MatchSPVPRPC.Instance.SelectScene(MatchSPVPRpcSelectSceneNotifyVar.SceneID);
	}


}

[CustomEditor(typeof(MatchSPVPTestHelper))]
public class MatchSPVPTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("StartMatch"))
		{
			MatchSPVPTestHelper rpc = target as MatchSPVPTestHelper;
			if( rpc ) rpc.TestStartMatch();
		}
		if (GUILayout.Button("Invitation"))
		{
			MatchSPVPTestHelper rpc = target as MatchSPVPTestHelper;
			if( rpc ) rpc.TestInvitation();
		}
		if (GUILayout.Button("AgreeInvitation"))
		{
			MatchSPVPTestHelper rpc = target as MatchSPVPTestHelper;
			if( rpc ) rpc.TestAgreeInvitation();
		}
		if (GUILayout.Button("SelectHero"))
		{
			MatchSPVPTestHelper rpc = target as MatchSPVPTestHelper;
			if( rpc ) rpc.TestSelectHero();
		}
		if (GUILayout.Button("GetStatus"))
		{
			MatchSPVPTestHelper rpc = target as MatchSPVPTestHelper;
			if( rpc ) rpc.TestGetStatus();
		}
		if (GUILayout.Button("ShotOff"))
		{
			MatchSPVPTestHelper rpc = target as MatchSPVPTestHelper;
			if( rpc ) rpc.TestShotOff();
		}
		if (GUILayout.Button("SelectScene"))
		{
			MatchSPVPTestHelper rpc = target as MatchSPVPTestHelper;
			if( rpc ) rpc.TestSelectScene();
		}


    }

}
#endif