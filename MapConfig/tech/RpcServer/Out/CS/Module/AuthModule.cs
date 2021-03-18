/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleAuth.cs
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


public class AuthRPC
{
	public const int ModuleId = 12;
	
	private static AuthRPC m_Instance = null;
	public static AuthRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new AuthRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{
		SocSingleton<LogicSocket>.Instance.RegisterNotify(1252, KickCB);

		return true;
	}


	//认证服务-->用户认证 RPC请求
	public void Auth(string UserName, string PassWord, ReplyHandler replyCB)
	{
		AuthRpcAuthAsk askPB = new AuthRpcAuthAsk();
		askPB.UserName = UserName;
		askPB.PassWord = PassWord;
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 1251;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<AuthRpcAuthAsk>(askMsg.protoMS, askPB);
		SocSingleton<LogicSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			AuthRpcAuthReply replyPB = ProtoBuf.Serializer.Deserialize<AuthRpcAuthReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}


	//认证服务-->踢人 服务器通知回调
	public static void KickCB( ModMessage notifyMsg )
	{
		AuthRpcKickNotify notifyPB = ProtoBuf.Serializer.Deserialize<AuthRpcKickNotify> (notifyMsg.protoMS);
		if( KickCBDelegate != null )
			KickCBDelegate( notifyPB );
	}
	public static ServerNotifyCallback KickCBDelegate = null;

}
