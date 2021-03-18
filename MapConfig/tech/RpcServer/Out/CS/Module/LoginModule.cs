/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleLogin.cs
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


public class LoginRPC
{
	public const int ModuleId = 20;
	
	private static LoginRPC m_Instance = null;
	public static LoginRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new LoginRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}


	//登陆-->准备 RPC请求
	public void Ready(ReplyHandler replyCB)
	{
		LoginRpcReadyAsk askPB = new LoginRpcReadyAsk();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = 2051;
		askMsg.protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<LoginRpcReadyAsk>(askMsg.protoMS, askPB);
		SocSingleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			LoginRpcReadyReply replyPB = ProtoBuf.Serializer.Deserialize<LoginRpcReadyReply>(replyMsg.protoMS);
			replyCB(replyPB);
		});
	}



}
