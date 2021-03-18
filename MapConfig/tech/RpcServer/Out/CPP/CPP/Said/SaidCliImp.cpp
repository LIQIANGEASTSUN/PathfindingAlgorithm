/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcSaidImp.cpp
* Author:       甘业清
* Description:  聊天类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ModuleSaid.h"
#include "UserMgr.h"


/********************************************************************************************
* Function:       CliRpcSaid
* Description:    聊天-->聊天同步调用操作函数
* Input:          SaidRpcSaidAsk& Ask 聊天请求
* Output:         SaidRpcSaidReply& Reply 聊天回应
********************************************************************************************/
void ModuleSaid::CliRpcSaid( clientInfoT& clientInfo, SaidRpcSaidAsk& Ask, SaidRpcSaidReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2200);
}

/********************************************************************************************
* Function:       SendToClientSaidBroadcas
* Description:    聊天-->聊天广播异步通知操作函数
* Input:          SaidRpcSaidBroadcasNotify& Notify 聊天广播服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleSaid::SendToClientSaidBroadcas( INT64 UserId, SaidRpcSaidBroadcasNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}



