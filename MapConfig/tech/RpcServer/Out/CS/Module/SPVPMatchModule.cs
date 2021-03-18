/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleSPVPMatch.cs
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


public class SPVPMatchRPC
{
	public const int ModuleId = 21;
	
	private static SPVPMatchRPC m_Instance = null;
	public static SPVPMatchRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SPVPMatchRPC();
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

		return true;
	}

	//匹配-->同意邀请回应 RPC通知
	public void AgreeInvitation(long Uid, int IsAgree, int Type)
	{
		SPVPMatchRpcAgreeInvitationNotify notifyPB = new SPVPMatchRpcAgreeInvitationNotify();
		notifyPB.Uid = Uid;
		notifyPB.IsAgree = IsAgree;
		notifyPB.Type = Type;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 2154;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SPVPMatchRpcAgreeInvitationNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<LogicSocket>.Instance.SendNotify(notifyMsg);
	}


	//匹配-->开始匹配 RPC请求
	public void StartMatch(ReplyHandler replyCB)
	{
		SPVPMatchRpcStartMatchAsk askPB = new SPVPMatchRpcStartMatchAsk();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2151;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SPVPMatchRpcStartMatchAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SPVPMatchRpcStartMatchReply replyPB = ProtoBuf.Serializer.Deserialize<SPVPMatchRpcStartMatchReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//匹配-->邀请 RPC请求
	public void Invitation(long Uid, ReplyHandler replyCB)
	{
		SPVPMatchRpcInvitationAsk askPB = new SPVPMatchRpcInvitationAsk();
		askPB.Uid = Uid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2153;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SPVPMatchRpcInvitationAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SPVPMatchRpcInvitationReply replyPB = ProtoBuf.Serializer.Deserialize<SPVPMatchRpcInvitationReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//匹配-->选择英雄 RPC请求
	public void SelectHero(int HeroID, ReplyHandler replyCB)
	{
		SPVPMatchRpcSelectHeroAsk askPB = new SPVPMatchRpcSelectHeroAsk();
		askPB.HeroID = HeroID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2156;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SPVPMatchRpcSelectHeroAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SPVPMatchRpcSelectHeroReply replyPB = ProtoBuf.Serializer.Deserialize<SPVPMatchRpcSelectHeroReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//匹配-->获取状态 RPC请求
	public void GetStatus(ReplyHandler replyCB)
	{
		SPVPMatchRpcGetStatusAsk askPB = new SPVPMatchRpcGetStatusAsk();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2159;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SPVPMatchRpcGetStatusAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SPVPMatchRpcGetStatusReply replyPB = ProtoBuf.Serializer.Deserialize<SPVPMatchRpcGetStatusReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}


	//匹配-->匹配通知 服务器通知回调
	public static void MatchBroadcasCB( ModMessage notifyMsg )
	{
		SPVPMatchRpcMatchBroadcasNotify notifyPB = ProtoBuf.Serializer.Deserialize<SPVPMatchRpcMatchBroadcasNotify> (notifyMsg.protoMS);
		if( MatchBroadcasCBDelegate != null )
			MatchBroadcasCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback MatchBroadcasCBDelegate = null;
	//匹配-->同意邀请回应 服务器通知回调
	public static void AgreeInvitationCB( ModMessage notifyMsg )
	{
		SPVPMatchRpcAgreeInvitationNotify notifyPB = ProtoBuf.Serializer.Deserialize<SPVPMatchRpcAgreeInvitationNotify> (notifyMsg.protoMS);
		if( AgreeInvitationCBDelegate != null )
			AgreeInvitationCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback AgreeInvitationCBDelegate = null;
	//匹配-->开始选择界面 服务器通知回调
	public static void StartSelectCB( ModMessage notifyMsg )
	{
		SPVPMatchRpcStartSelectNotify notifyPB = ProtoBuf.Serializer.Deserialize<SPVPMatchRpcStartSelectNotify> (notifyMsg.protoMS);
		if( StartSelectCBDelegate != null )
			StartSelectCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback StartSelectCBDelegate = null;
	//匹配-->开始游戏 服务器通知回调
	public static void StartGameCB( ModMessage notifyMsg )
	{
		SPVPMatchRpcStartGameNotify notifyPB = ProtoBuf.Serializer.Deserialize<SPVPMatchRpcStartGameNotify> (notifyMsg.protoMS);
		if( StartGameCBDelegate != null )
			StartGameCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback StartGameCBDelegate = null;
	//匹配-->取消匹配 服务器通知回调
	public static void DeleteMatchCB( ModMessage notifyMsg )
	{
		SPVPMatchRpcDeleteMatchNotify notifyPB = ProtoBuf.Serializer.Deserialize<SPVPMatchRpcDeleteMatchNotify> (notifyMsg.protoMS);
		if( DeleteMatchCBDelegate != null )
			DeleteMatchCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback DeleteMatchCBDelegate = null;
	//匹配-->修改状态 服务器通知回调
	public static void ChangeStatusCB( ModMessage notifyMsg )
	{
		SPVPMatchRpcChangeStatusNotify notifyPB = ProtoBuf.Serializer.Deserialize<SPVPMatchRpcChangeStatusNotify> (notifyMsg.protoMS);
		if( ChangeStatusCBDelegate != null )
			ChangeStatusCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback ChangeStatusCBDelegate = null;

}
