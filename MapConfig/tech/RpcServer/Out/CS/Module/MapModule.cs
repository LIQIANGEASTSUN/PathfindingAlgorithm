/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleMap.cs
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


public class MapRPC
{
	public const int ModuleId = 31;
	
	private static MapRPC m_Instance = null;
	public static MapRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new MapRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
