/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleGate.cs
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


public class GateRPC
{
	public const int ModuleId = 8;
	
	private static GateRPC m_Instance = null;
	public static GateRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new GateRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
