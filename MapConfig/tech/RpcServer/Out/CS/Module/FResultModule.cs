/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleFResult.cs
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


public class FResultRPC
{
	public const int ModuleId = 29;
	
	private static FResultRPC m_Instance = null;
	public static FResultRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new FResultRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
