/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleTeam.cs
Author:
Description:
Version:	  1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


public class TeamRPC
{
	public const int ModuleId = 28;
	
	private static TeamRPC m_Instance = null;
	public static TeamRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new TeamRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{
		SocSingleton<LogicSocket>.Instance.RegisterNotify(2852, AddTeamNoifyCB);
		SocSingleton<LogicSocket>.Instance.RegisterNotify(2853, GetTeamCB);

		return true;
	}

	//组队-->拉队友收到的消息 RPC通知
	public void AddTeamNoify(SmallUser User, SmallUser BeUser, int IsOk, int Type)
	{
		TeamRpcAddTeamNoifyNotify notifyPB = new TeamRpcAddTeamNoifyNotify();
		notifyPB.User = User;
		notifyPB.BeUser = BeUser;
		notifyPB.IsOk = IsOk;
		notifyPB.Type = Type;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 2852;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcAddTeamNoifyNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<LogicSocket>.Instance.SendNotify(notifyMsg);
	}

	//组队-->获取team消息 RPC通知
	public void GetTeam(TeamTeamV Team)
	{
		TeamRpcGetTeamNotify notifyPB = new TeamRpcGetTeamNotify();
		notifyPB.Team = Team;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 2853;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcGetTeamNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<LogicSocket>.Instance.SendNotify(notifyMsg);
	}


	//组队-->拉队友 RPC请求
	public void PullTeammate(int UID, string UserName, int Type, ReplyHandler replyCB)
	{
		TeamRpcPullTeammateAsk askPB = new TeamRpcPullTeammateAsk();
		askPB.UID = UID;
		askPB.UserName = UserName;
		askPB.Type = Type;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2851;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcPullTeammateAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcPullTeammateReply replyPB = ProtoBuf.Serializer.Deserialize<TeamRpcPullTeammateReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//组队-->操作队伍 RPC请求
	public void CtrlTeam(int Type, int UID, ReplyHandler replyCB)
	{
		TeamRpcCtrlTeamAsk askPB = new TeamRpcCtrlTeamAsk();
		askPB.Type = Type;
		askPB.UID = UID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2854;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcCtrlTeamAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcCtrlTeamReply replyPB = ProtoBuf.Serializer.Deserialize<TeamRpcCtrlTeamReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//组队-->寻找队伍 RPC请求
	public void FindTeam(long TeamID, ReplyHandler replyCB)
	{
		TeamRpcFindTeamAsk askPB = new TeamRpcFindTeamAsk();
		askPB.TeamID = TeamID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2855;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<TeamRpcFindTeamAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			TeamRpcFindTeamReply replyPB = ProtoBuf.Serializer.Deserialize<TeamRpcFindTeamReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}


	//组队-->拉队友收到的消息 服务器通知回调
	public static void AddTeamNoifyCB( ModMessage notifyMsg )
	{
		TeamRpcAddTeamNoifyNotify notifyPB = ProtoBuf.Serializer.Deserialize<TeamRpcAddTeamNoifyNotify> (notifyMsg.protoMS);
		if( AddTeamNoifyCBDelegate != null )
			AddTeamNoifyCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback AddTeamNoifyCBDelegate = null;
	//组队-->获取team消息 服务器通知回调
	public static void GetTeamCB( ModMessage notifyMsg )
	{
		TeamRpcGetTeamNotify notifyPB = ProtoBuf.Serializer.Deserialize<TeamRpcGetTeamNotify> (notifyMsg.protoMS);
		if( GetTeamCBDelegate != null )
			GetTeamCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback GetTeamCBDelegate = null;

}
