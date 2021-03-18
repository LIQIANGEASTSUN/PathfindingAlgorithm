/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleAI.cs
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


public class AIRPC
{
	public const int ModuleId = 27;
	
	private static AIRPC m_Instance = null;
	public static AIRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new AIRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
