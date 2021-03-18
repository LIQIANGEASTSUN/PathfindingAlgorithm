/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcLoginImp.cpp
* Author:       甘业清
* Description:  登陆类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ModuleLogin.h"
#include "UserMgr.h"


/********************************************************************************************
* Function:       CliRpcReady
* Description:    登陆-->准备同步调用操作函数
* Input:          LoginRpcReadyAsk& Ask 准备请求
* Output:         LoginRpcReadyReply& Reply 准备回应
********************************************************************************************/
void ModuleLogin::CliRpcReady( clientInfoT& clientInfo, LoginRpcReadyAsk& Ask, LoginRpcReadyReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(0);
}

/********************************************************************************************
* Function:       CliRpcStart
* Description:    登陆-->开始游戏异步通知操作函数
* Input:          LoginRpcStartNotify& Notify 开始游戏通知
* Output:         无
********************************************************************************************/
void ModuleLogin::CliRpcStart( clientInfoT& clientInfo, LoginRpcStartNotify& Notify )
{

	//逻辑代码


}



