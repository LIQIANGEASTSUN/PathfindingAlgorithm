/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleSaid.cs
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


public class SaidRPC
{
	public const int ModuleId = 22;
	
	private static SaidRPC m_Instance = null;
	public static SaidRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SaidRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{
		SocSingleton<LogicSocket>.Instance.RegisterNotify(2252, SaidBroadcasCB);

		return true;
	}


	//聊天-->聊天 RPC请求
	public void Said(SaidSaidData Value, ReplyHandler replyCB)
	{
		SaidRpcSaidAsk askPB = new SaidRpcSaidAsk();
		askPB.Value = Value;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2251;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<SaidRpcSaidAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			SaidRpcSaidReply replyPB = ProtoBuf.Serializer.Deserialize<SaidRpcSaidReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}


	//聊天-->聊天广播 服务器通知回调
	public static void SaidBroadcasCB( ModMessage notifyMsg )
	{
		SaidRpcSaidBroadcasNotify notifyPB = ProtoBuf.Serializer.Deserialize<SaidRpcSaidBroadcasNotify> (notifyMsg.protoMS);
		if( SaidBroadcasCBDelegate != null )
			SaidBroadcasCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SaidBroadcasCBDelegate = null;

}
