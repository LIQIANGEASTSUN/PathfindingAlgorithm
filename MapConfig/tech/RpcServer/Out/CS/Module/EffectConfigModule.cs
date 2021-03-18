/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleEffectConfig.cs
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


public class EffectConfigRPC
{
	public const int ModuleId = 26;
	
	private static EffectConfigRPC m_Instance = null;
	public static EffectConfigRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new EffectConfigRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
