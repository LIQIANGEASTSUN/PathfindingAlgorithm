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
		SocSingleton<LogicSocket>.Instance.RegisterNotify(1352, UpdateCB);

		return true;
	}


	//用户属性-->同步 RPC请求
	public void Sync(long Uid, ReplyHandler replyCB)
	{
		PropertyRpcSyncAsk askPB = new PropertyRpcSyncAsk();
		askPB.Uid = Uid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 1351;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PropertyRpcSyncAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PropertyRpcSyncReply replyPB = ProtoBuf.Serializer.Deserialize<PropertyRpcSyncReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//用户属性-->换头像 RPC请求
	public void ChangeHead(int HeadID, ReplyHandler replyCB)
	{
		PropertyRpcChangeHeadAsk askPB = new PropertyRpcChangeHeadAsk();
		askPB.HeadID = HeadID;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 1353;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<PropertyRpcChangeHeadAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			PropertyRpcChangeHeadReply replyPB = ProtoBuf.Serializer.Deserialize<PropertyRpcChangeHeadReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}


	//用户属性-->更新数据 服务器通知回调
	public static void UpdateCB( ModMessage notifyMsg )
	{
		PropertyRpcUpdateNotify notifyPB = ProtoBuf.Serializer.Deserialize<PropertyRpcUpdateNotify> (notifyMsg.protoMS);
		if( UpdateCBDelegate != null )
			UpdateCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback UpdateCBDelegate = null;

}
