/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleDBCache.cs
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


public class DBCacheRPC
{
	public const int ModuleId = 25;
	
	private static DBCacheRPC m_Instance = null;
	public static DBCacheRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new DBCacheRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
