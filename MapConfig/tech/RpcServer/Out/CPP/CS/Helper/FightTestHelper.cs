#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class FightRpcBulletShootNotifyHelper
{
	public long Uid;
	public int Bid;
	public FightVector3PB Pos;
	public float Mass;
	public float Vv;
	public int Id;
	public int ObjId;
	public int TrajId;
	public FightVector3PB Velocity;
	public int NSeed;
}
[System.Serializable]
public class FightRpcStatNotifyHelper
{
	public long Uid;
	public int State;
	public FightVector3PB Pos;
	public int Result;
	public FightVector3PB RockDir;
	public FightVector3PB MoveDir;
	public FightVector3PB UpDir;
	public int FootTriangleID;
	public int WallTriangleID;
	public FightVector3PB Rotation;
}
[System.Serializable]
public class FightRpcReadyAskHelper
{
}
[System.Serializable]
public class FightRpcLoginAskHelper
{
}
[System.Serializable]
public class FightRpcSkillActionNotifyHelper
{
	public int RoleId;
	public int SkillId;
	public int OperType;
}
[System.Serializable]
public class FightRpcSkillOperNotifyHelper
{
	public long RoleId;
	public int SkillId;
	public int OperType;
	public int Ret;
	public bool IsNpc;
}
[System.Serializable]
public class FightRpcSkillShotBulletNotifyHelper
{
	public long RoleId;
	public int SkillId;
	public List<FightVector3PB> Pos;
	public float HForward;
	public float VForward;
	public int MillSecond;
	public int ObjId;
	public bool BJump;
}
[System.Serializable]
public class FightRpcSkillShotTrajectoryConfigNotifyHelper
{
	public long RoleId;
	public int SkillId;
	public int ObjId;
	public int Id;
	public int EventBaseId;
	public int NSeed;
}
[System.Serializable]
public class FightRpcInsertRoomAskHelper
{
	public string Key;
}
[System.Serializable]
public class FightRpcGetPlayerAskHelper
{
	public long Uid;
}
[System.Serializable]
public class FightRpcSyncUserDirNotifyHelper
{
	public long Uid;
	public float HAngle;
}



public class FightTestHelper : MonoBehaviour
{
	public FightRpcBulletShootNotifyHelper FightRpcBulletShootNotifyVar;
	public FightRpcStatNotifyHelper FightRpcStatNotifyVar;
	public FightRpcReadyAskHelper FightRpcReadyAskVar;
	public FightRpcLoginAskHelper FightRpcLoginAskVar;
	public FightRpcSkillActionNotifyHelper FightRpcSkillActionNotifyVar;
	public FightRpcSkillOperNotifyHelper FightRpcSkillOperNotifyVar;
	public FightRpcSkillShotBulletNotifyHelper FightRpcSkillShotBulletNotifyVar;
	public FightRpcSkillShotTrajectoryConfigNotifyHelper FightRpcSkillShotTrajectoryConfigNotifyVar;
	public FightRpcInsertRoomAskHelper FightRpcInsertRoomAskVar;
	public FightRpcGetPlayerAskHelper FightRpcGetPlayerAskVar;
	public FightRpcSyncUserDirNotifyHelper FightRpcSyncUserDirNotifyVar;


	public void TestBulletShoot()
	{
		FightRPC.Instance.BulletShoot(FightRpcBulletShootNotifyVar.Uid,FightRpcBulletShootNotifyVar.Bid,FightRpcBulletShootNotifyVar.Pos,FightRpcBulletShootNotifyVar.Mass,FightRpcBulletShootNotifyVar.Vv,FightRpcBulletShootNotifyVar.Id,FightRpcBulletShootNotifyVar.ObjId,FightRpcBulletShootNotifyVar.TrajId,FightRpcBulletShootNotifyVar.Velocity,FightRpcBulletShootNotifyVar.NSeed);
	}
	public void TestStat()
	{
		FightRPC.Instance.Stat(FightRpcStatNotifyVar.Uid,FightRpcStatNotifyVar.State,FightRpcStatNotifyVar.Pos,FightRpcStatNotifyVar.Result,FightRpcStatNotifyVar.RockDir,FightRpcStatNotifyVar.MoveDir,FightRpcStatNotifyVar.UpDir,FightRpcStatNotifyVar.FootTriangleID,FightRpcStatNotifyVar.WallTriangleID,FightRpcStatNotifyVar.Rotation);
	}
	public void TestReady()
	{
		FightRPC.Instance.Ready(delegate(object obj){});
	}
	public void TestLogin()
	{
		FightRPC.Instance.Login(delegate(object obj){});
	}
	public void TestSkillAction()
	{
		FightRPC.Instance.SkillAction(FightRpcSkillActionNotifyVar.RoleId,FightRpcSkillActionNotifyVar.SkillId,FightRpcSkillActionNotifyVar.OperType);
	}
	public void TestSkillOper()
	{
		FightRPC.Instance.SkillOper(FightRpcSkillOperNotifyVar.RoleId,FightRpcSkillOperNotifyVar.SkillId,FightRpcSkillOperNotifyVar.OperType,FightRpcSkillOperNotifyVar.Ret,FightRpcSkillOperNotifyVar.IsNpc);
	}
	public void TestSkillShotBullet()
	{
		FightRPC.Instance.SkillShotBullet(FightRpcSkillShotBulletNotifyVar.RoleId,FightRpcSkillShotBulletNotifyVar.SkillId,FightRpcSkillShotBulletNotifyVar.Pos,FightRpcSkillShotBulletNotifyVar.HForward,FightRpcSkillShotBulletNotifyVar.VForward,FightRpcSkillShotBulletNotifyVar.MillSecond,FightRpcSkillShotBulletNotifyVar.ObjId,FightRpcSkillShotBulletNotifyVar.BJump);
	}
	public void TestSkillShotTrajectoryConfig()
	{
		FightRPC.Instance.SkillShotTrajectoryConfig(FightRpcSkillShotTrajectoryConfigNotifyVar.RoleId,FightRpcSkillShotTrajectoryConfigNotifyVar.SkillId,FightRpcSkillShotTrajectoryConfigNotifyVar.ObjId,FightRpcSkillShotTrajectoryConfigNotifyVar.Id,FightRpcSkillShotTrajectoryConfigNotifyVar.EventBaseId,FightRpcSkillShotTrajectoryConfigNotifyVar.NSeed);
	}
	public void TestInsertRoom()
	{
		FightRPC.Instance.InsertRoom(FightRpcInsertRoomAskVar.Key,delegate(object obj){});
	}
	public void TestGetPlayer()
	{
		FightRPC.Instance.GetPlayer(FightRpcGetPlayerAskVar.Uid,delegate(object obj){});
	}
	public void TestSyncUserDir()
	{
		FightRPC.Instance.SyncUserDir(FightRpcSyncUserDirNotifyVar.Uid,FightRpcSyncUserDirNotifyVar.HAngle);
	}


}

[CustomEditor(typeof(FightTestHelper))]
public class FightTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("BulletShoot"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestBulletShoot();
		}
		if (GUILayout.Button("Stat"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestStat();
		}
		if (GUILayout.Button("Ready"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestReady();
		}
		if (GUILayout.Button("Login"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestLogin();
		}
		if (GUILayout.Button("SkillAction"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestSkillAction();
		}
		if (GUILayout.Button("SkillOper"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestSkillOper();
		}
		if (GUILayout.Button("SkillShotBullet"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestSkillShotBullet();
		}
		if (GUILayout.Button("SkillShotTrajectoryConfig"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestSkillShotTrajectoryConfig();
		}
		if (GUILayout.Button("InsertRoom"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestInsertRoom();
		}
		if (GUILayout.Button("GetPlayer"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestGetPlayer();
		}
		if (GUILayout.Button("SyncUserDir"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestSyncUserDir();
		}


    }

}
#endif