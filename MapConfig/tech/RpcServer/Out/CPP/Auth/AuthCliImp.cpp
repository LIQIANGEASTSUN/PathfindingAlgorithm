/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcAuthImp.cpp
* Author:       甘业清
* Description:  认证服务类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ModuleAuth.h"
#include "UserMgr.h"


/********************************************************************************************
* Function:       CliRpcAuth
* Description:    认证服务-->用户认证同步调用操作函数
* Input:          AuthRpcAuthAsk& Ask 用户认证请求
* Output:         AuthRpcAuthReply& Reply 用户认证回应
********************************************************************************************/
void ModuleAuth::CliRpcAuth( clientInfoT& clientInfo, AuthRpcAuthAsk& Ask, AuthRpcAuthReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(1200);
}

/********************************************************************************************
* Function:       SendToClientKick
* Description:    认证服务-->踢人异步通知操作函数
* Input:          AuthRpcKickNotify& Notify 踢人服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleAuth::SendToClientKick( INT64 UserId, AuthRpcKickNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}



