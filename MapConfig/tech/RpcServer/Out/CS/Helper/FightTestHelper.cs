#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class FightRpcInsertRoomAskHelper
{
	public string Key;
}
[System.Serializable]
public class FightRpcRoveOverNotifyHelper
{
	public int Timer;
}
[System.Serializable]
public class FightRpcSkillTransferNotifyHelper
{
	public int ObjId;
	public int SkillId;
	public int TargetObjId;
	public Vector3PB TargetPos;
	public int Ret;
	public int Type;
}



public class FightTestHelper : MonoBehaviour
{
	public FightRpcInsertRoomAskHelper FightRpcInsertRoomAskVar;
	public FightRpcRoveOverNotifyHelper FightRpcRoveOverNotifyVar;
	public FightRpcSkillTransferNotifyHelper FightRpcSkillTransferNotifyVar;


	public void TestInsertRoom()
	{
		FightRPC.Instance.InsertRoom(FightRpcInsertRoomAskVar.Key,delegate(object obj){});
	}
	public void TestRoveOver()
	{
		FightRPC.Instance.RoveOver(FightRpcRoveOverNotifyVar.Timer);
	}
	public void TestSkillTransfer()
	{
		FightRPC.Instance.SkillTransfer(FightRpcSkillTransferNotifyVar.ObjId,FightRpcSkillTransferNotifyVar.SkillId,FightRpcSkillTransferNotifyVar.TargetObjId,FightRpcSkillTransferNotifyVar.TargetPos,FightRpcSkillTransferNotifyVar.Ret,FightRpcSkillTransferNotifyVar.Type);
	}


}

[CustomEditor(typeof(FightTestHelper))]
public class FightTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("InsertRoom"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestInsertRoom();
		}
		if (GUILayout.Button("RoveOver"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestRoveOver();
		}
		if (GUILayout.Button("SkillTransfer"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestSkillTransfer();
		}


    }

}
#endif