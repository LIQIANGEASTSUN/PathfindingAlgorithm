/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleMysqlSharding.cs
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


public class MysqlShardingRPC
{
	public const int ModuleId = 7;
	
	private static MysqlShardingRPC m_Instance = null;
	public static MysqlShardingRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MysqlShardingRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
