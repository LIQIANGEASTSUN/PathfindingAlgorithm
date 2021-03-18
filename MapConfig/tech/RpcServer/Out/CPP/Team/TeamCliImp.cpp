/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcTeamImp.cpp
* Author:       甘业清
* Description:  组队类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ModuleTeam.h"
#include "UserMgr.h"


/********************************************************************************************
* Function:       CliRpcPullTeammate
* Description:    组队-->拉队友同步调用操作函数
* Input:          TeamRpcPullTeammateAsk& Ask 拉队友请求
* Output:         TeamRpcPullTeammateReply& Reply 拉队友回应
********************************************************************************************/
void ModuleTeam::CliRpcPullTeammate( clientInfoT& clientInfo, TeamRpcPullTeammateAsk& Ask, TeamRpcPullTeammateReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2800);
}

/********************************************************************************************
* Function:       CliRpcAddTeamNoify
* Description:    组队-->拉队友收到的消息异步通知操作函数
* Input:          TeamRpcAddTeamNoifyNotify& Notify 拉队友收到的消息双向通知
* Output:         无
********************************************************************************************/
void ModuleTeam::CliRpcAddTeamNoify( clientInfoT& clientInfo, TeamRpcAddTeamNoifyNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientAddTeamNoify
* Description:    组队-->拉队友收到的消息异步通知操作函数
* Input:          TeamRpcAddTeamNoifyNotify& Notify 拉队友收到的消息双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientAddTeamNoify( INT64 UserId, TeamRpcAddTeamNoifyNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcGetTeam
* Description:    组队-->获取team消息异步通知操作函数
* Input:          TeamRpcGetTeamNotify& Notify 获取team消息双向通知
* Output:         无
********************************************************************************************/
void ModuleTeam::CliRpcGetTeam( clientInfoT& clientInfo, TeamRpcGetTeamNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientGetTeam
* Description:    组队-->获取team消息异步通知操作函数
* Input:          TeamRpcGetTeamNotify& Notify 获取team消息双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientGetTeam( INT64 UserId, TeamRpcGetTeamNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcCtrlTeam
* Description:    组队-->操作队伍同步调用操作函数
* Input:          TeamRpcCtrlTeamAsk& Ask 操作队伍请求
* Output:         TeamRpcCtrlTeamReply& Reply 操作队伍回应
********************************************************************************************/
void ModuleTeam::CliRpcCtrlTeam( clientInfoT& clientInfo, TeamRpcCtrlTeamAsk& Ask, TeamRpcCtrlTeamReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2800);
}

/********************************************************************************************
* Function:       CliRpcFindTeam
* Description:    组队-->寻找队伍同步调用操作函数
* Input:          TeamRpcFindTeamAsk& Ask 寻找队伍请求
* Output:         TeamRpcFindTeamReply& Reply 寻找队伍回应
********************************************************************************************/
void ModuleTeam::CliRpcFindTeam( clientInfoT& clientInfo, TeamRpcFindTeamAsk& Ask, TeamRpcFindTeamReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2800);
}



