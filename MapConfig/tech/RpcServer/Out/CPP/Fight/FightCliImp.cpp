/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcFightImp.cpp
* Author:       甘业清
* Description:  Fight类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ModuleFight.h"
#include "UserMgr.h"


/********************************************************************************************
* Function:       SendToClientStart
* Description:    Fight-->开始异步通知操作函数
* Input:          FightRpcStartNotify& Notify 开始服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientStart( INT64 UserId, FightRpcStartNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSyncUserProp
* Description:    Fight-->同步属性异步通知操作函数
* Input:          FightRpcSyncUserPropNotify& Notify 同步属性服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSyncUserProp( INT64 UserId, FightRpcSyncUserPropNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcInsertRoom
* Description:    Fight-->进入房间同步调用操作函数
* Input:          FightRpcInsertRoomAsk& Ask 进入房间请求
* Output:         FightRpcInsertRoomReply& Reply 进入房间回应
********************************************************************************************/
void ModuleFight::CliRpcInsertRoom( clientInfoT& clientInfo, FightRpcInsertRoomAsk& Ask, FightRpcInsertRoomReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(1900);
}

/********************************************************************************************
* Function:       SendToClientHPChange
* Description:    Fight-->生命值变化异步通知操作函数
* Input:          FightRpcHPChangeNotify& Notify 生命值变化服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientHPChange( INT64 UserId, FightRpcHPChangeNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcRoveOver
* Description:    Fight-->漫游结束异步通知操作函数
* Input:          FightRpcRoveOverNotify& Notify 漫游结束双向通知
* Output:         无
********************************************************************************************/
void ModuleFight::CliRpcRoveOver( clientInfoT& clientInfo, FightRpcRoveOverNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientRoveOver
* Description:    Fight-->漫游结束异步通知操作函数
* Input:          FightRpcRoveOverNotify& Notify 漫游结束双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientRoveOver( INT64 UserId, FightRpcRoveOverNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcSkillTransfer
* Description:    Fight-->传送异步通知操作函数
* Input:          FightRpcSkillTransferNotify& Notify 传送通知
* Output:         无
********************************************************************************************/
void ModuleFight::CliRpcSkillTransfer( clientInfoT& clientInfo, FightRpcSkillTransferNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientSkillTransfer
* Description:    Fight-->传送异步通知操作函数
* Input:          FightRpcSkillTransferNotify& Notify 传送通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSkillTransfer( INT64 UserId, FightRpcSkillTransferNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}



