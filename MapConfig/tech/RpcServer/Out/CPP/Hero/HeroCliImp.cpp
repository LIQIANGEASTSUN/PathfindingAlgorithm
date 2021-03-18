/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcHeroImp.cpp
* Author:       甘业清
* Description:  英雄类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ModuleHero.h"
#include "UserMgr.h"


/********************************************************************************************
* Function:       CliRpcSync
* Description:    英雄-->同步数据同步调用操作函数
* Input:          HeroRpcSyncAsk& Ask 同步数据请求
* Output:         HeroRpcSyncReply& Reply 同步数据回应
********************************************************************************************/
void ModuleHero::CliRpcSync( clientInfoT& clientInfo, HeroRpcSyncAsk& Ask, HeroRpcSyncReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2000);
}

/********************************************************************************************
* Function:       CliRpcActive
* Description:    英雄-->激活英雄同步调用操作函数
* Input:          HeroRpcActiveAsk& Ask 激活英雄请求
* Output:         HeroRpcActiveReply& Reply 激活英雄回应
********************************************************************************************/
void ModuleHero::CliRpcActive( clientInfoT& clientInfo, HeroRpcActiveAsk& Ask, HeroRpcActiveReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2000);
}



