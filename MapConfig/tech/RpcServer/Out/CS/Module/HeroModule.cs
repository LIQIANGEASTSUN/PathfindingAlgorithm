/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleHero.cs
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


public class HeroRPC
{
	public const int ModuleId = 20;
	
	private static HeroRPC m_Instance = null;
	public static HeroRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new HeroRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}


	//英雄-->同步数据 RPC请求
	public void Sync(ReplyHandler replyCB)
	{
		HeroRpcSyncAsk askPB = new HeroRpcSyncAsk();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2051;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HeroRpcSyncAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HeroRpcSyncReply replyPB = ProtoBuf.Serializer.Deserialize<HeroRpcSyncReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//英雄-->激活英雄 RPC请求
	public void Active(int HeroID, ReplyHandler replyCB)
	{
		HeroRpcActiveAsk askPB = new HeroRpcActiveAsk();
		askPB.HeroID = HeroID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2052;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<HeroRpcActiveAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			HeroRpcActiveReply replyPB = ProtoBuf.Serializer.Deserialize<HeroRpcActiveReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}



}
