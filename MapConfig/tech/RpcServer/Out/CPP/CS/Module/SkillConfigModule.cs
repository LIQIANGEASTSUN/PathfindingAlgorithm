/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleSkillConfig.cs
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


public class SkillConfigRPC
{
	public const int ModuleId = 17;
	
	private static SkillConfigRPC m_Instance = null;
	public static SkillConfigRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SkillConfigRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
