/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleRaft.cs
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


public class RaftRPC
{
	public const int ModuleId = 18;
	
	private static RaftRPC m_Instance = null;
	public static RaftRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new RaftRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
