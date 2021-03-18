/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleMatchSPVP.cs
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


public class MatchSPVPRPC
{
	public const int ModuleId = 21;
	
	private static MatchSPVPRPC m_Instance = null;
	public static MatchSPVPRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MatchSPVPRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{
		SocSingleton<LogicSocket>.Instance.RegisterNotify(2152, MatchBroadcasCB);
		SocSingleton<LogicSocket>.Instance.RegisterNotify(2154, AgreeInvitationCB);
		SocSingleton<LogicSocket>.Instance.RegisterNotify(2155, StartSelectCB);
		SocSingleton<LogicSocket>.Instance.RegisterNotify(2157, StartGameCB);
		SocSingleton<LogicSocket>.Instance.RegisterNotify(2158, DeleteMatchCB);
		SocSingleton<LogicSocket>.Instance.RegisterNotify(2160, ChangeStatusCB);
		SocSingleton<LogicSocket>.Instance.RegisterNotify(2162, SelectSceneCB);

		return true;
	}

	//匹配-->同意邀请回应 RPC通知
	public void AgreeInvitation(long Uid, int IsAgree, int Type)
	{
		MatchSPVPRpcAgreeInvitationNotify notifyPB = new MatchSPVPRpcAgreeInvitationNotify();
		notifyPB.Uid = Uid;
		notifyPB.IsAgree = IsAgree;
		notifyPB.Type = Type;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 2154;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchSPVPRpcAgreeInvitationNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<LogicSocket>.Instance.SendNotify(notifyMsg);
	}

	//匹配-->选择场景 RPC通知
	public void SelectScene(int SceneID)
	{
		MatchSPVPRpcSelectSceneNotify notifyPB = new MatchSPVPRpcSelectSceneNotify();
		notifyPB.SceneID = SceneID;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 2162;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchSPVPRpcSelectSceneNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<LogicSocket>.Instance.SendNotify(notifyMsg);
	}


	//匹配-->开始匹配 RPC请求
	public void StartMatch(int IsMatch, int SceneID, ReplyHandler replyCB)
	{
		MatchSPVPRpcStartMatchAsk askPB = new MatchSPVPRpcStartMatchAsk();
		askPB.IsMatch = IsMatch;
		askPB.SceneID = SceneID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2151;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchSPVPRpcStartMatchAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MatchSPVPRpcStartMatchReply replyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcStartMatchReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//匹配-->邀请 RPC请求
	public void Invitation(long Uid, ReplyHandler replyCB)
	{
		MatchSPVPRpcInvitationAsk askPB = new MatchSPVPRpcInvitationAsk();
		askPB.Uid = Uid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2153;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchSPVPRpcInvitationAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MatchSPVPRpcInvitationReply replyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcInvitationReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//匹配-->选择英雄 RPC请求
	public void SelectHero(int HeroID, ReplyHandler replyCB)
	{
		MatchSPVPRpcSelectHeroAsk askPB = new MatchSPVPRpcSelectHeroAsk();
		askPB.HeroID = HeroID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2156;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchSPVPRpcSelectHeroAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MatchSPVPRpcSelectHeroReply replyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcSelectHeroReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//匹配-->获取状态 RPC请求
	public void GetStatus(ReplyHandler replyCB)
	{
		MatchSPVPRpcGetStatusAsk askPB = new MatchSPVPRpcGetStatusAsk();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2159;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchSPVPRpcGetStatusAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MatchSPVPRpcGetStatusReply replyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcGetStatusReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//匹配-->剔出 RPC请求
	public void ShotOff(long Uid, ReplyHandler replyCB)
	{
		MatchSPVPRpcShotOffAsk askPB = new MatchSPVPRpcShotOffAsk();
		askPB.Uid = Uid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2161;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<MatchSPVPRpcShotOffAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			MatchSPVPRpcShotOffReply replyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcShotOffReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}


	//匹配-->匹配通知 服务器通知回调
	public static void MatchBroadcasCB( ModMessage notifyMsg )
	{
		MatchSPVPRpcMatchBroadcasNotify notifyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcMatchBroadcasNotify> (notifyMsg.protoMS);
		if( MatchBroadcasCBDelegate != null )
			MatchBroadcasCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback MatchBroadcasCBDelegate = null;
	//匹配-->同意邀请回应 服务器通知回调
	public static void AgreeInvitationCB( ModMessage notifyMsg )
	{
		MatchSPVPRpcAgreeInvitationNotify notifyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcAgreeInvitationNotify> (notifyMsg.protoMS);
		if( AgreeInvitationCBDelegate != null )
			AgreeInvitationCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback AgreeInvitationCBDelegate = null;
	//匹配-->开始选择界面 服务器通知回调
	public static void StartSelectCB( ModMessage notifyMsg )
	{
		MatchSPVPRpcStartSelectNotify notifyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcStartSelectNotify> (notifyMsg.protoMS);
		if( StartSelectCBDelegate != null )
			StartSelectCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback StartSelectCBDelegate = null;
	//匹配-->开始游戏 服务器通知回调
	public static void StartGameCB( ModMessage notifyMsg )
	{
		MatchSPVPRpcStartGameNotify notifyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcStartGameNotify> (notifyMsg.protoMS);
		if( StartGameCBDelegate != null )
			StartGameCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback StartGameCBDelegate = null;
	//匹配-->取消匹配 服务器通知回调
	public static void DeleteMatchCB( ModMessage notifyMsg )
	{
		MatchSPVPRpcDeleteMatchNotify notifyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcDeleteMatchNotify> (notifyMsg.protoMS);
		if( DeleteMatchCBDelegate != null )
			DeleteMatchCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback DeleteMatchCBDelegate = null;
	//匹配-->修改状态 服务器通知回调
	public static void ChangeStatusCB( ModMessage notifyMsg )
	{
		MatchSPVPRpcChangeStatusNotify notifyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcChangeStatusNotify> (notifyMsg.protoMS);
		if( ChangeStatusCBDelegate != null )
			ChangeStatusCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback ChangeStatusCBDelegate = null;
	//匹配-->选择场景 服务器通知回调
	public static void SelectSceneCB( ModMessage notifyMsg )
	{
		MatchSPVPRpcSelectSceneNotify notifyPB = ProtoBuf.Serializer.Deserialize<MatchSPVPRpcSelectSceneNotify> (notifyMsg.protoMS);
		if( SelectSceneCBDelegate != null )
			SelectSceneCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SelectSceneCBDelegate = null;

}
