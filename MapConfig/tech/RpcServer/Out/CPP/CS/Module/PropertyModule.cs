/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleProperty.cs
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


public class PropertyRPC
{
	public const int ModuleId = 13;
	
	private static PropertyRPC m_Instance = null;
	public static PropertyRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new PropertyRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}


	//用户属性-->同步 RPC请求
	public void Sync(ReplyHandler replyCB)
	{
		PropertyRpcSyncAsk askPB = new PropertyRpcSyncAsk();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 1351;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PropertyRpcSyncAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PropertyRpcSyncReply replyPB = ProtoBuf.Serializer.Deserialize<PropertyRpcSyncReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}



}
