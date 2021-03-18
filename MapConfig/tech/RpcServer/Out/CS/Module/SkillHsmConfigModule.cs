/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleSkillHsmConfig.cs
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


public class SkillHsmConfigRPC
{
	public const int ModuleId = 30;
	
	private static SkillHsmConfigRPC m_Instance = null;
	public static SkillHsmConfigRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SkillHsmConfigRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
