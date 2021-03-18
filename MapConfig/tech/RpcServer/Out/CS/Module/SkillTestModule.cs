/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleSkillTest.cs
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


public class SkillTestRPC
{
	public const int ModuleId = 15;
	
	private static SkillTestRPC m_Instance = null;
	public static SkillTestRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new SkillTestRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
