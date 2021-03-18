/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleLog.cs
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


public class LogRPC
{
	public const int ModuleId = 24;
	
	private static LogRPC m_Instance = null;
	public static LogRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new LogRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
