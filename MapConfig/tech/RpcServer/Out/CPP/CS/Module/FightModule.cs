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
		SocSingleton<GameSocket>.Instance.RegisterNotify(1951, SyncUserInfoCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1952, BulletShootCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1953, GameEndCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1954, ReviveCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1955, DeadCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1956, StatCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1957, ShakeCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1958, BulletDistroyCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1959, SprayCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1962, StartCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1963, SpeedCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1964, HitCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1965, SkillActionCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1966, SkillOperCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1967, SkillShotBulletCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1968, RotateInfoCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1969, SkillShotTrajectoryConfigCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1970, SyncUserPropCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1972, AddPlayerCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1974, SyncAttackPropCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1975, RemoveNpcCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1976, AddNpcCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1977, ChangeBuffCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1978, SyncUserDirCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1979, NpcStateCB);
		SocSingleton<GameSocket>.Instance.RegisterNotify(1980, ActTimeCB);

		return true;
	}

	//Fight-->发射 RPC通知
	public void BulletShoot(long Uid, int Bid, FightVector3PB Pos, float Mass, float Vv, int Id, int ObjId, int TrajId, FightVector3PB Velocity, int NSeed)
	{
		FightRpcBulletShootNotify notifyPB = new FightRpcBulletShootNotify();
		notifyPB.Uid = Uid;
		notifyPB.Bid = Bid;
		notifyPB.Pos = Pos;
		notifyPB.Mass = Mass;
		notifyPB.Vv = Vv;
		notifyPB.Id = Id;
		notifyPB.ObjId = ObjId;
		notifyPB.TrajId = TrajId;
		notifyPB.Velocity = Velocity;
		notifyPB.NSeed = NSeed;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 1952;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcBulletShootNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}

	//Fight-->状态 RPC通知
	public void Stat(long Uid, int State, FightVector3PB Pos, int Result, FightVector3PB RockDir, FightVector3PB MoveDir, FightVector3PB UpDir, int FootTriangleID, int WallTriangleID, FightVector3PB Rotation)
	{
		FightRpcStatNotify notifyPB = new FightRpcStatNotify();
		notifyPB.Uid = Uid;
		notifyPB.State = State;
		notifyPB.Pos = Pos;
		notifyPB.Result = Result;
		notifyPB.RockDir = RockDir;
		notifyPB.MoveDir = MoveDir;
		notifyPB.UpDir = UpDir;
		notifyPB.FootTriangleID = FootTriangleID;
		notifyPB.WallTriangleID = WallTriangleID;
		notifyPB.Rotation = Rotation;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 1956;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcStatNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}

	//Fight-->技能操作 RPC通知
	public void SkillAction(int RoleId, int SkillId, int OperType)
	{
		FightRpcSkillActionNotify notifyPB = new FightRpcSkillActionNotify();
		notifyPB.RoleId = RoleId;
		notifyPB.SkillId = SkillId;
		notifyPB.OperType = OperType;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 1965;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSkillActionNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}

	//Fight-->技能释放 RPC通知
	public void SkillOper(long RoleId, int SkillId, int OperType, int Ret, bool IsNpc)
	{
		FightRpcSkillOperNotify notifyPB = new FightRpcSkillOperNotify();
		notifyPB.RoleId = RoleId;
		notifyPB.SkillId = SkillId;
		notifyPB.OperType = OperType;
		notifyPB.Ret = Ret;
		notifyPB.IsNpc = IsNpc;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 1966;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSkillOperNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}

	//Fight-->技能发出子弹 RPC通知
	public void SkillShotBullet(long RoleId, int SkillId, List<FightVector3PB> Pos, float HForward, float VForward, int MillSecond, int ObjId, bool BJump)
	{
		FightRpcSkillShotBulletNotify notifyPB = new FightRpcSkillShotBulletNotify();
		notifyPB.RoleId = RoleId;
		notifyPB.SkillId = SkillId;
		notifyPB.Pos.AddRange(Pos);
		notifyPB.HForward = HForward;
		notifyPB.VForward = VForward;
		notifyPB.MillSecond = MillSecond;
		notifyPB.ObjId = ObjId;
		notifyPB.BJump = BJump;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 1967;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSkillShotBulletNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}

	//Fight-->发射配置文件 RPC通知
	public void SkillShotTrajectoryConfig(long RoleId, int SkillId, int ObjId, int Id, int EventBaseId, int NSeed)
	{
		FightRpcSkillShotTrajectoryConfigNotify notifyPB = new FightRpcSkillShotTrajectoryConfigNotify();
		notifyPB.RoleId = RoleId;
		notifyPB.SkillId = SkillId;
		notifyPB.ObjId = ObjId;
		notifyPB.Id = Id;
		notifyPB.EventBaseId = EventBaseId;
		notifyPB.NSeed = NSeed;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 1969;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSkillShotTrajectoryConfigNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}

	//Fight-->广播玩家朝向 RPC通知
	public void SyncUserDir(long Uid, float HAngle)
	{
		FightRpcSyncUserDirNotify notifyPB = new FightRpcSyncUserDirNotify();
		notifyPB.Uid = Uid;
		notifyPB.HAngle = HAngle;
		ModMessage notifyMsg = new ModMessage();
		notifyMsg.MsgNum = 1978;
		notifyMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcSyncUserDirNotify>(notifyMsg.protoMS, notifyPB);
		SocSingleton<GameSocket>.Instance.SendNotify(notifyMsg);
	}


	//Fight-->准备 RPC请求
	public void Ready(ReplyHandler replyCB)
	{
		FightRpcReadyAsk askPB = new FightRpcReadyAsk();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 1960;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcReadyAsk>(askMsg.protoMS, askPB);
		SocSingleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			FightRpcReadyReply replyPB = ProtoBuf.Serializer.Deserialize<FightRpcReadyReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//Fight-->登陆 RPC请求
	public void Login(ReplyHandler replyCB)
	{
		FightRpcLoginAsk askPB = new FightRpcLoginAsk();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 1961;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcLoginAsk>(askMsg.protoMS, askPB);
		SocSingleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			FightRpcLoginReply replyPB = ProtoBuf.Serializer.Deserialize<FightRpcLoginReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//Fight-->进入房间 RPC请求
	public void InsertRoom(string Key, ReplyHandler replyCB)
	{
		FightRpcInsertRoomAsk askPB = new FightRpcInsertRoomAsk();
		askPB.Key = Key;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 1971;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcInsertRoomAsk>(askMsg.protoMS, askPB);
		SocSingleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			FightRpcInsertRoomReply replyPB = ProtoBuf.Serializer.Deserialize<FightRpcInsertRoomReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}

	//Fight-->获取角色 RPC请求
	public void GetPlayer(long Uid, ReplyHandler replyCB)
	{
		FightRpcGetPlayerAsk askPB = new FightRpcGetPlayerAsk();
		askPB.Uid = Uid;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 1973;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<FightRpcGetPlayerAsk>(askMsg.protoMS, askPB);
		SocSingleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			FightRpcGetPlayerReply replyPB = ProtoBuf.Serializer.Deserialize<FightRpcGetPlayerReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}


	//Fight-->服务器定时同步 服务器通知回调
	public static void SyncUserInfoCB( ModMessage notifyMsg )
	{
		FightRpcSyncUserInfoNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSyncUserInfoNotify> (notifyMsg.protoMS);
		if( SyncUserInfoCBDelegate != null )
			SyncUserInfoCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SyncUserInfoCBDelegate = null;
	//Fight-->发射 服务器通知回调
	public static void BulletShootCB( ModMessage notifyMsg )
	{
		FightRpcBulletShootNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcBulletShootNotify> (notifyMsg.protoMS);
		if( BulletShootCBDelegate != null )
			BulletShootCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback BulletShootCBDelegate = null;
	//Fight-->服务器通知 服务器通知回调
	public static void GameEndCB( ModMessage notifyMsg )
	{
		FightRpcGameEndNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcGameEndNotify> (notifyMsg.protoMS);
		if( GameEndCBDelegate != null )
			GameEndCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback GameEndCBDelegate = null;
	//Fight-->复活 服务器通知回调
	public static void ReviveCB( ModMessage notifyMsg )
	{
		FightRpcReviveNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcReviveNotify> (notifyMsg.protoMS);
		if( ReviveCBDelegate != null )
			ReviveCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback ReviveCBDelegate = null;
	//Fight-->死亡 服务器通知回调
	public static void DeadCB( ModMessage notifyMsg )
	{
		FightRpcDeadNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcDeadNotify> (notifyMsg.protoMS);
		if( DeadCBDelegate != null )
			DeadCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback DeadCBDelegate = null;
	//Fight-->状态 服务器通知回调
	public static void StatCB( ModMessage notifyMsg )
	{
		FightRpcStatNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcStatNotify> (notifyMsg.protoMS);
		if( StatCBDelegate != null )
			StatCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback StatCBDelegate = null;
	//Fight-->震动 服务器通知回调
	public static void ShakeCB( ModMessage notifyMsg )
	{
		FightRpcShakeNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcShakeNotify> (notifyMsg.protoMS);
		if( ShakeCBDelegate != null )
			ShakeCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback ShakeCBDelegate = null;
	//Fight-->子弹销毁 服务器通知回调
	public static void BulletDistroyCB( ModMessage notifyMsg )
	{
		FightRpcBulletDistroyNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcBulletDistroyNotify> (notifyMsg.protoMS);
		if( BulletDistroyCBDelegate != null )
			BulletDistroyCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback BulletDistroyCBDelegate = null;
	//Fight-->喷涂 服务器通知回调
	public static void SprayCB( ModMessage notifyMsg )
	{
		FightRpcSprayNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSprayNotify> (notifyMsg.protoMS);
		if( SprayCBDelegate != null )
			SprayCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SprayCBDelegate = null;
	//Fight-->开始 服务器通知回调
	public static void StartCB( ModMessage notifyMsg )
	{
		FightRpcStartNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcStartNotify> (notifyMsg.protoMS);
		if( StartCBDelegate != null )
			StartCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback StartCBDelegate = null;
	//Fight-->移动速度 服务器通知回调
	public static void SpeedCB( ModMessage notifyMsg )
	{
		FightRpcSpeedNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSpeedNotify> (notifyMsg.protoMS);
		if( SpeedCBDelegate != null )
			SpeedCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SpeedCBDelegate = null;
	//Fight-->受击 服务器通知回调
	public static void HitCB( ModMessage notifyMsg )
	{
		FightRpcHitNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcHitNotify> (notifyMsg.protoMS);
		if( HitCBDelegate != null )
			HitCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback HitCBDelegate = null;
	//Fight-->技能操作 服务器通知回调
	public static void SkillActionCB( ModMessage notifyMsg )
	{
		FightRpcSkillActionNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSkillActionNotify> (notifyMsg.protoMS);
		if( SkillActionCBDelegate != null )
			SkillActionCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SkillActionCBDelegate = null;
	//Fight-->技能释放 服务器通知回调
	public static void SkillOperCB( ModMessage notifyMsg )
	{
		FightRpcSkillOperNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSkillOperNotify> (notifyMsg.protoMS);
		if( SkillOperCBDelegate != null )
			SkillOperCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SkillOperCBDelegate = null;
	//Fight-->技能发出子弹 服务器通知回调
	public static void SkillShotBulletCB( ModMessage notifyMsg )
	{
		FightRpcSkillShotBulletNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSkillShotBulletNotify> (notifyMsg.protoMS);
		if( SkillShotBulletCBDelegate != null )
			SkillShotBulletCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SkillShotBulletCBDelegate = null;
	//Fight-->旋转面 服务器通知回调
	public static void RotateInfoCB( ModMessage notifyMsg )
	{
		FightRpcRotateInfoNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcRotateInfoNotify> (notifyMsg.protoMS);
		if( RotateInfoCBDelegate != null )
			RotateInfoCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback RotateInfoCBDelegate = null;
	//Fight-->发射配置文件 服务器通知回调
	public static void SkillShotTrajectoryConfigCB( ModMessage notifyMsg )
	{
		FightRpcSkillShotTrajectoryConfigNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSkillShotTrajectoryConfigNotify> (notifyMsg.protoMS);
		if( SkillShotTrajectoryConfigCBDelegate != null )
			SkillShotTrajectoryConfigCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SkillShotTrajectoryConfigCBDelegate = null;
	//Fight-->同步属性 服务器通知回调
	public static void SyncUserPropCB( ModMessage notifyMsg )
	{
		FightRpcSyncUserPropNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSyncUserPropNotify> (notifyMsg.protoMS);
		if( SyncUserPropCBDelegate != null )
			SyncUserPropCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SyncUserPropCBDelegate = null;
	//Fight-->增加玩家 服务器通知回调
	public static void AddPlayerCB( ModMessage notifyMsg )
	{
		FightRpcAddPlayerNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcAddPlayerNotify> (notifyMsg.protoMS);
		if( AddPlayerCBDelegate != null )
			AddPlayerCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback AddPlayerCBDelegate = null;
	//Fight-->推送战斗数据 服务器通知回调
	public static void SyncAttackPropCB( ModMessage notifyMsg )
	{
		FightRpcSyncAttackPropNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSyncAttackPropNotify> (notifyMsg.protoMS);
		if( SyncAttackPropCBDelegate != null )
			SyncAttackPropCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SyncAttackPropCBDelegate = null;
	//Fight-->Npc移除通知 服务器通知回调
	public static void RemoveNpcCB( ModMessage notifyMsg )
	{
		FightRpcRemoveNpcNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcRemoveNpcNotify> (notifyMsg.protoMS);
		if( RemoveNpcCBDelegate != null )
			RemoveNpcCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback RemoveNpcCBDelegate = null;
	//Fight-->创建NPC 服务器通知回调
	public static void AddNpcCB( ModMessage notifyMsg )
	{
		FightRpcAddNpcNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcAddNpcNotify> (notifyMsg.protoMS);
		if( AddNpcCBDelegate != null )
			AddNpcCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback AddNpcCBDelegate = null;
	//Fight-->增加buff 服务器通知回调
	public static void ChangeBuffCB( ModMessage notifyMsg )
	{
		FightRpcChangeBuffNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcChangeBuffNotify> (notifyMsg.protoMS);
		if( ChangeBuffCBDelegate != null )
			ChangeBuffCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback ChangeBuffCBDelegate = null;
	//Fight-->广播玩家朝向 服务器通知回调
	public static void SyncUserDirCB( ModMessage notifyMsg )
	{
		FightRpcSyncUserDirNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcSyncUserDirNotify> (notifyMsg.protoMS);
		if( SyncUserDirCBDelegate != null )
			SyncUserDirCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback SyncUserDirCBDelegate = null;
	//Fight-->Npc状态变化 服务器通知回调
	public static void NpcStateCB( ModMessage notifyMsg )
	{
		FightRpcNpcStateNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcNpcStateNotify> (notifyMsg.protoMS);
		if( NpcStateCBDelegate != null )
			NpcStateCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback NpcStateCBDelegate = null;
	//Fight-->战斗时间修正 服务器通知回调
	public static void ActTimeCB( ModMessage notifyMsg )
	{
		FightRpcActTimeNotify notifyPB = ProtoBuf.Serializer.Deserialize<FightRpcActTimeNotify> (notifyMsg.protoMS);
		if( ActTimeCBDelegate != null )
			ActTimeCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback ActTimeCBDelegate = null;

}
