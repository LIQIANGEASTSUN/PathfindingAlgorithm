#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class TeamRpcPullTeammateAskHelper
{
	public int UID;
	public string UserName;
	public int Type;
}
[System.Serializable]
public class TeamRpcAddTeamNoifyNotifyHelper
{
	public SmallUser User;
	public SmallUser BeUser;
	public int IsOk;
	public int Type;
}
[System.Serializable]
public class TeamRpcGetTeamNotifyHelper
{
	public TeamTeamV Team;
}
[System.Serializable]
public class TeamRpcCtrlTeamAskHelper
{
	public int Type;
	public int UID;
}
[System.Serializable]
public class TeamRpcFindTeamAskHelper
{
	public long TeamID;
}



public class TeamTestHelper : MonoBehaviour
{
	public TeamRpcPullTeammateAskHelper TeamRpcPullTeammateAskVar;
	public TeamRpcAddTeamNoifyNotifyHelper TeamRpcAddTeamNoifyNotifyVar;
	public TeamRpcGetTeamNotifyHelper TeamRpcGetTeamNotifyVar;
	public TeamRpcCtrlTeamAskHelper TeamRpcCtrlTeamAskVar;
	public TeamRpcFindTeamAskHelper TeamRpcFindTeamAskVar;


	public void TestPullTeammate()
	{
		TeamRPC.Instance.PullTeammate(TeamRpcPullTeammateAskVar.UID,TeamRpcPullTeammateAskVar.UserName,TeamRpcPullTeammateAskVar.Type,delegate(object obj){});
	}
	public void TestAddTeamNoify()
	{
		TeamRPC.Instance.AddTeamNoify(TeamRpcAddTeamNoifyNotifyVar.User,TeamRpcAddTeamNoifyNotifyVar.BeUser,TeamRpcAddTeamNoifyNotifyVar.IsOk,TeamRpcAddTeamNoifyNotifyVar.Type);
	}
	public void TestGetTeam()
	{
		TeamRPC.Instance.GetTeam(TeamRpcGetTeamNotifyVar.Team);
	}
	public void TestCtrlTeam()
	{
		TeamRPC.Instance.CtrlTeam(TeamRpcCtrlTeamAskVar.Type,TeamRpcCtrlTeamAskVar.UID,delegate(object obj){});
	}
	public void TestFindTeam()
	{
		TeamRPC.Instance.FindTeam(TeamRpcFindTeamAskVar.TeamID,delegate(object obj){});
	}


}

[CustomEditor(typeof(TeamTestHelper))]
public class TeamTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("PullTeammate"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestPullTeammate();
		}
		if (GUILayout.Button("AddTeamNoify"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestAddTeamNoify();
		}
		if (GUILayout.Button("GetTeam"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestGetTeam();
		}
		if (GUILayout.Button("CtrlTeam"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestCtrlTeam();
		}
		if (GUILayout.Button("FindTeam"))
		{
			TeamTestHelper rpc = target as TeamTestHelper;
			if( rpc ) rpc.TestFindTeam();
		}


    }

}
#endif