/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleUserMsg.cs
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


public class UserMsgRPC
{
	public const int ModuleId = 9;
	
	private static UserMsgRPC m_Instance = null;
	public static UserMsgRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new UserMsgRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
