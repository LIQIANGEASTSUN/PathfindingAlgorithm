/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleBattleSPVP.cs
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


public class BattleSPVPRPC
{
	public const int ModuleId = 23;
	
	private static BattleSPVPRPC m_Instance = null;
	public static BattleSPVPRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BattleSPVPRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
