/************************************************************
Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
FileName:	 ModuleTrajectory.cs
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


public class TrajectoryRPC
{
	public const int ModuleId = 16;
	
	private static TrajectoryRPC m_Instance = null;
	public static TrajectoryRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new TrajectoryRPC();
			}
			return m_Instance;
		}
	}

	public bool initialize()
	{

		return true;
	}




}
