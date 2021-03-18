/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleFight.cs
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


public class FightRPC
{
	public const int ModuleId = 19;
	
	private static FightRPC m_Instance = null;
	public static FightRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new FightRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{
		SocSingleton<GameSocket>.Instance.RegisterNotify(1951, StartCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1952, SyncUserPropCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1954, HPChangeCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1955, RoveOverCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1956, SkillTransferCB);

		return true;
	}

	//Fight-->漫游结束 RPC通知
	public void RoveOver(int Timer)
	{
		FightRpcRoveOverNotify notifyPB = new FightRpcRoveOverNotify();
		notifyPB.Timer = Timer;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 1955;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcRoveOverNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}

	//Fight-->传送 RPC通知
	public void SkillTransfer(int ObjId, int SkillId, int TargetObjId, Vector3PB TargetPos, int Ret, int Type)
	{
		FightRpcSkillTransferNotify notifyPB = new FightRpcSkillTransferNotify();
		notifyPB.ObjId = ObjId;
		notifyPB.SkillId = SkillId;
		notifyPB.TargetObjId = TargetObjId;
		notifyPB.TargetPos = TargetPos;
		notifyPB.Ret = Ret;
		notifyPB.Type = Type;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 1956;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSkillTransferNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}


	//Fight-->进入房间 RPC请求
	public void InsertRoom(string Key, ReplyHandler replyCB)
	{
		FightRpcInsertRoomAsk askPB = new FightRpcInsertRoomAsk();
		askPB.Key = Key;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 1953;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcInsertRoomAsk>(askMsg.protoMS, askPB);
		SocSingleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			FightRpcInsertRoomReply replyPB = ProtoBuf.Serializer.Deserialize<FightRpcInsertRoomReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}


	//Fight-->开始 服务器通知回调
	public static void StartCB( ModMessage notifyMsg )
	{
		FightRpcStartNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcStartNotify> (notifyMsg.protoMS);
		if( StartCBDelegate != null )
			StartCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback StartCBDelegate = null;
	//Fight-->同步属性 服务器通知回调
	public static void SyncUserPropCB( ModMessage notifyMsg )
	{
		FightRpcSyncUserPropNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSyncUserPropNotify> (notifyMsg.protoMS);
		if( SyncUserPropCBDelegate != null )
			SyncUserPropCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SyncUserPropCBDelegate = null;
	//Fight-->生命值变化 服务器通知回调
	public static void HPChangeCB( ModMessage notifyMsg )
	{
		FightRpcHPChangeNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcHPChangeNotify> (notifyMsg.protoMS);
		if( HPChangeCBDelegate != null )
			HPChangeCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback HPChangeCBDelegate = null;
	//Fight-->漫游结束 服务器通知回调
	public static void RoveOverCB( ModMessage notifyMsg )
	{
		FightRpcRoveOverNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcRoveOverNotify> (notifyMsg.protoMS);
		if( RoveOverCBDelegate != null )
			RoveOverCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback RoveOverCBDelegate = null;
	//Fight-->传送 服务器通知回调
	public static void SkillTransferCB( ModMessage notifyMsg )
	{
		FightRpcSkillTransferNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSkillTransferNotify> (notifyMsg.protoMS);
		if( SkillTransferCBDelegate != null )
			SkillTransferCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SkillTransferCBDelegate = null;

}
