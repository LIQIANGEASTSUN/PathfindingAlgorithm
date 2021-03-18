/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 Module$Template$.cs
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


public class $Template$RPC
{
	public const int ModuleId = $ModId$;
	
	private static $Template$RPC m_Instance = null;
	public static $Template$RPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new $Template$RPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{
$RegisterCB$
		return true;
	}

$NotifyRpc$
$InteractRpc$
$NotifyCallback$
}
