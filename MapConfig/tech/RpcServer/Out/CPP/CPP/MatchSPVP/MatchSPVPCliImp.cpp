/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcMatchSPVPImp.cpp
* Author:       甘业清
* Description:  匹配类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ModuleMatchSPVP.h"
#include "UserMgr.h"


/********************************************************************************************
* Function:       CliRpcStartMatch
* Description:    匹配-->开始匹配同步调用操作函数
* Input:          MatchSPVPRpcStartMatchAsk& Ask 开始匹配请求
* Output:         MatchSPVPRpcStartMatchReply& Reply 开始匹配回应
********************************************************************************************/
void ModuleMatchSPVP::CliRpcStartMatch( clientInfoT& clientInfo, MatchSPVPRpcStartMatchAsk& Ask, MatchSPVPRpcStartMatchReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2100);
}

/********************************************************************************************
* Function:       SendToClientMatchBroadcas
* Description:    匹配-->匹配通知异步通知操作函数
* Input:          MatchSPVPRpcMatchBroadcasNotify& Notify 匹配通知服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatchSPVP::SendToClientMatchBroadcas( INT64 UserId, MatchSPVPRpcMatchBroadcasNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcInvitation
* Description:    匹配-->邀请同步调用操作函数
* Input:          MatchSPVPRpcInvitationAsk& Ask 邀请请求
* Output:         MatchSPVPRpcInvitationReply& Reply 邀请回应
********************************************************************************************/
void ModuleMatchSPVP::CliRpcInvitation( clientInfoT& clientInfo, MatchSPVPRpcInvitationAsk& Ask, MatchSPVPRpcInvitationReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2100);
}

/********************************************************************************************
* Function:       CliRpcAgreeInvitation
* Description:    匹配-->同意邀请回应异步通知操作函数
* Input:          MatchSPVPRpcAgreeInvitationNotify& Notify 同意邀请回应双向通知
* Output:         无
********************************************************************************************/
void ModuleMatchSPVP::CliRpcAgreeInvitation( clientInfoT& clientInfo, MatchSPVPRpcAgreeInvitationNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientAgreeInvitation
* Description:    匹配-->同意邀请回应异步通知操作函数
* Input:          MatchSPVPRpcAgreeInvitationNotify& Notify 同意邀请回应双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatchSPVP::SendToClientAgreeInvitation( INT64 UserId, MatchSPVPRpcAgreeInvitationNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientStartSelect
* Description:    匹配-->开始选择界面异步通知操作函数
* Input:          MatchSPVPRpcStartSelectNotify& Notify 开始选择界面服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatchSPVP::SendToClientStartSelect( INT64 UserId, MatchSPVPRpcStartSelectNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcSelectHero
* Description:    匹配-->选择英雄同步调用操作函数
* Input:          MatchSPVPRpcSelectHeroAsk& Ask 选择英雄请求
* Output:         MatchSPVPRpcSelectHeroReply& Reply 选择英雄回应
********************************************************************************************/
void ModuleMatchSPVP::CliRpcSelectHero( clientInfoT& clientInfo, MatchSPVPRpcSelectHeroAsk& Ask, MatchSPVPRpcSelectHeroReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2100);
}

/********************************************************************************************
* Function:       SendToClientStartGame
* Description:    匹配-->开始游戏异步通知操作函数
* Input:          MatchSPVPRpcStartGameNotify& Notify 开始游戏服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatchSPVP::SendToClientStartGame( INT64 UserId, MatchSPVPRpcStartGameNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientDeleteMatch
* Description:    匹配-->取消匹配异步通知操作函数
* Input:          MatchSPVPRpcDeleteMatchNotify& Notify 取消匹配服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatchSPVP::SendToClientDeleteMatch( INT64 UserId, MatchSPVPRpcDeleteMatchNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcGetStatus
* Description:    匹配-->获取状态同步调用操作函数
* Input:          MatchSPVPRpcGetStatusAsk& Ask 获取状态请求
* Output:         MatchSPVPRpcGetStatusReply& Reply 获取状态回应
********************************************************************************************/
void ModuleMatchSPVP::CliRpcGetStatus( clientInfoT& clientInfo, MatchSPVPRpcGetStatusAsk& Ask, MatchSPVPRpcGetStatusReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2100);
}

/********************************************************************************************
* Function:       SendToClientChangeStatus
* Description:    匹配-->修改状态异步通知操作函数
* Input:          MatchSPVPRpcChangeStatusNotify& Notify 修改状态服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatchSPVP::SendToClientChangeStatus( INT64 UserId, MatchSPVPRpcChangeStatusNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcShotOff
* Description:    匹配-->剔出同步调用操作函数
* Input:          MatchSPVPRpcShotOffAsk& Ask 剔出请求
* Output:         MatchSPVPRpcShotOffReply& Reply 剔出回应
********************************************************************************************/
void ModuleMatchSPVP::CliRpcShotOff( clientInfoT& clientInfo, MatchSPVPRpcShotOffAsk& Ask, MatchSPVPRpcShotOffReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(2100);
}

/********************************************************************************************
* Function:       CliRpcSelectScene
* Description:    匹配-->选择场景异步通知操作函数
* Input:          MatchSPVPRpcSelectSceneNotify& Notify 选择场景双向通知
* Output:         无
********************************************************************************************/
void ModuleMatchSPVP::CliRpcSelectScene( clientInfoT& clientInfo, MatchSPVPRpcSelectSceneNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientSelectScene
* Description:    匹配-->选择场景异步通知操作函数
* Input:          MatchSPVPRpcSelectSceneNotify& Notify 选择场景双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatchSPVP::SendToClientSelectScene( INT64 UserId, MatchSPVPRpcSelectSceneNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}



