/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleID.cs
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


public class IDRPC
{
	public const int ModuleId = 11;
	
	private static IDRPC m_Instance = null;
	public static IDRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new IDRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
