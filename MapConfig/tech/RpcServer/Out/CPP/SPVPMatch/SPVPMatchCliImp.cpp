/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcSPVPMatchImp.cpp
* Author:       甘业清
* Description:  匹配类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ModuleSPVPMatch.h"
#include "UserMgr.h"


/********************************************************************************************
* Function:       CliRpcStartMatch
* Description:    匹配-->开始匹配同步调用操作函数
* Input:          SPVPMatchRpcStartMatchAsk& Ask 开始匹配请求
* Output:         SPVPMatchRpcStartMatchReply& Reply 开始匹配回应
********************************************************************************************/
void ModuleSPVPMatch::CliRpcStartMatch( clientInfoT& clientInfo, SPVPMatchRpcStartMatchAsk& Ask, SPVPMatchRpcStartMatchReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2100);
}

/********************************************************************************************
* Function:       SendToClientMatchBroadcas
* Description:    匹配-->匹配通知异步通知操作函数
* Input:          SPVPMatchRpcMatchBroadcasNotify& Notify 匹配通知服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleSPVPMatch::SendToClientMatchBroadcas( INT64 UserId, SPVPMatchRpcMatchBroadcasNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcInvitation
* Description:    匹配-->邀请同步调用操作函数
* Input:          SPVPMatchRpcInvitationAsk& Ask 邀请请求
* Output:         SPVPMatchRpcInvitationReply& Reply 邀请回应
********************************************************************************************/
void ModuleSPVPMatch::CliRpcInvitation( clientInfoT& clientInfo, SPVPMatchRpcInvitationAsk& Ask, SPVPMatchRpcInvitationReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2100);
}

/********************************************************************************************
* Function:       CliRpcAgreeInvitation
* Description:    匹配-->同意邀请回应异步通知操作函数
* Input:          SPVPMatchRpcAgreeInvitationNotify& Notify 同意邀请回应双向通知
* Output:         无
********************************************************************************************/
void ModuleSPVPMatch::CliRpcAgreeInvitation( clientInfoT& clientInfo, SPVPMatchRpcAgreeInvitationNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientAgreeInvitation
* Description:    匹配-->同意邀请回应异步通知操作函数
* Input:          SPVPMatchRpcAgreeInvitationNotify& Notify 同意邀请回应双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleSPVPMatch::SendToClientAgreeInvitation( INT64 UserId, SPVPMatchRpcAgreeInvitationNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientStartSelect
* Description:    匹配-->开始选择界面异步通知操作函数
* Input:          SPVPMatchRpcStartSelectNotify& Notify 开始选择界面服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleSPVPMatch::SendToClientStartSelect( INT64 UserId, SPVPMatchRpcStartSelectNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcSelectHero
* Description:    匹配-->选择英雄同步调用操作函数
* Input:          SPVPMatchRpcSelectHeroAsk& Ask 选择英雄请求
* Output:         SPVPMatchRpcSelectHeroReply& Reply 选择英雄回应
********************************************************************************************/
void ModuleSPVPMatch::CliRpcSelectHero( clientInfoT& clientInfo, SPVPMatchRpcSelectHeroAsk& Ask, SPVPMatchRpcSelectHeroReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2100);
}

/********************************************************************************************
* Function:       SendToClientStartGame
* Description:    匹配-->开始游戏异步通知操作函数
* Input:          SPVPMatchRpcStartGameNotify& Notify 开始游戏服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleSPVPMatch::SendToClientStartGame( INT64 UserId, SPVPMatchRpcStartGameNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientDeleteMatch
* Description:    匹配-->取消匹配异步通知操作函数
* Input:          SPVPMatchRpcDeleteMatchNotify& Notify 取消匹配服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleSPVPMatch::SendToClientDeleteMatch( INT64 UserId, SPVPMatchRpcDeleteMatchNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcGetStatus
* Description:    匹配-->获取状态同步调用操作函数
* Input:          SPVPMatchRpcGetStatusAsk& Ask 获取状态请求
* Output:         SPVPMatchRpcGetStatusReply& Reply 获取状态回应
********************************************************************************************/
void ModuleSPVPMatch::CliRpcGetStatus( clientInfoT& clientInfo, SPVPMatchRpcGetStatusAsk& Ask, SPVPMatchRpcGetStatusReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2100);
}

/********************************************************************************************
* Function:       SendToClientChangeStatus
* Description:    匹配-->修改状态异步通知操作函数
* Input:          SPVPMatchRpcChangeStatusNotify& Notify 修改状态服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleSPVPMatch::SendToClientChangeStatus( INT64 UserId, SPVPMatchRpcChangeStatusNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}



