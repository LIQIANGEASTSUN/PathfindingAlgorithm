/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 Moduletestone.cs
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


public class testoneRPC
{
	public const int ModuleId = 26;
	
	private static testoneRPC m_Instance = null;
	public static testoneRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new testoneRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
