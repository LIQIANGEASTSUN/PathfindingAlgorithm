/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleIK.cs
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


public class IKRPC
{
	public const int ModuleId = 32;
	
	private static IKRPC m_Instance = null;
	public static IKRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new IKRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
