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
* Function:       SendToClientSyncUserInfo
* Description:    Fight-->服务器定时同步异步通知操作函数
* Input:          FightRpcSyncUserInfoNotify& Notify 服务器定时同步服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSyncUserInfo( INT64 UserId, FightRpcSyncUserInfoNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcBulletShoot
* Description:    Fight-->发射异步通知操作函数
* Input:          FightRpcBulletShootNotify& Notify 发射双向通知
* Output:         无
********************************************************************************************/
void ModuleFight::CliRpcBulletShoot( clientInfoT& clientInfo, FightRpcBulletShootNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientBulletShoot
* Description:    Fight-->发射异步通知操作函数
* Input:          FightRpcBulletShootNotify& Notify 发射双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientBulletShoot( INT64 UserId, FightRpcBulletShootNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientGameEnd
* Description:    Fight-->服务器通知异步通知操作函数
* Input:          FightRpcGameEndNotify& Notify 服务器通知服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientGameEnd( INT64 UserId, FightRpcGameEndNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientRevive
* Description:    Fight-->复活异步通知操作函数
* Input:          FightRpcReviveNotify& Notify 复活通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientRevive( INT64 UserId, FightRpcReviveNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientDead
* Description:    Fight-->死亡异步通知操作函数
* Input:          FightRpcDeadNotify& Notify 死亡通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientDead( INT64 UserId, FightRpcDeadNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcStat
* Description:    Fight-->状态异步通知操作函数
* Input:          FightRpcStatNotify& Notify 状态双向通知
* Output:         无
********************************************************************************************/
void ModuleFight::CliRpcStat( clientInfoT& clientInfo, FightRpcStatNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientStat
* Description:    Fight-->状态异步通知操作函数
* Input:          FightRpcStatNotify& Notify 状态双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientStat( INT64 UserId, FightRpcStatNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientShake
* Description:    Fight-->震动异步通知操作函数
* Input:          FightRpcShakeNotify& Notify 震动通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientShake( INT64 UserId, FightRpcShakeNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientBulletDistroy
* Description:    Fight-->子弹销毁异步通知操作函数
* Input:          FightRpcBulletDistroyNotify& Notify 子弹销毁通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientBulletDistroy( INT64 UserId, FightRpcBulletDistroyNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSpray
* Description:    Fight-->喷涂异步通知操作函数
* Input:          FightRpcSprayNotify& Notify 喷涂通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSpray( INT64 UserId, FightRpcSprayNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcReady
* Description:    Fight-->准备同步调用操作函数
* Input:          FightRpcReadyAsk& Ask 准备请求
* Output:         FightRpcReadyReply& Reply 准备回应
********************************************************************************************/
void ModuleFight::CliRpcReady( clientInfoT& clientInfo, FightRpcReadyAsk& Ask, FightRpcReadyReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(1900);
}

/********************************************************************************************
* Function:       CliRpcLogin
* Description:    Fight-->登陆同步调用操作函数
* Input:          FightRpcLoginAsk& Ask 登陆请求
* Output:         FightRpcLoginReply& Reply 登陆回应
********************************************************************************************/
void ModuleFight::CliRpcLogin( clientInfoT& clientInfo, FightRpcLoginAsk& Ask, FightRpcLoginReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(1900);
}

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
* Function:       SendToClientSpeed
* Description:    Fight-->移动速度异步通知操作函数
* Input:          FightRpcSpeedNotify& Notify 移动速度服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSpeed( INT64 UserId, FightRpcSpeedNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientHit
* Description:    Fight-->受击异步通知操作函数
* Input:          FightRpcHitNotify& Notify 受击服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientHit( INT64 UserId, FightRpcHitNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcSkillAction
* Description:    Fight-->技能操作异步通知操作函数
* Input:          FightRpcSkillActionNotify& Notify 技能操作双向通知
* Output:         无
********************************************************************************************/
void ModuleFight::CliRpcSkillAction( clientInfoT& clientInfo, FightRpcSkillActionNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientSkillAction
* Description:    Fight-->技能操作异步通知操作函数
* Input:          FightRpcSkillActionNotify& Notify 技能操作双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSkillAction( INT64 UserId, FightRpcSkillActionNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcSkillOper
* Description:    Fight-->技能释放异步通知操作函数
* Input:          FightRpcSkillOperNotify& Notify 技能释放双向通知
* Output:         无
********************************************************************************************/
void ModuleFight::CliRpcSkillOper( clientInfoT& clientInfo, FightRpcSkillOperNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientSkillOper
* Description:    Fight-->技能释放异步通知操作函数
* Input:          FightRpcSkillOperNotify& Notify 技能释放双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSkillOper( INT64 UserId, FightRpcSkillOperNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcSkillShotBullet
* Description:    Fight-->技能发出子弹异步通知操作函数
* Input:          FightRpcSkillShotBulletNotify& Notify 技能发出子弹双向通知
* Output:         无
********************************************************************************************/
void ModuleFight::CliRpcSkillShotBullet( clientInfoT& clientInfo, FightRpcSkillShotBulletNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientSkillShotBullet
* Description:    Fight-->技能发出子弹异步通知操作函数
* Input:          FightRpcSkillShotBulletNotify& Notify 技能发出子弹双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSkillShotBullet( INT64 UserId, FightRpcSkillShotBulletNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientRotateInfo
* Description:    Fight-->旋转面异步通知操作函数
* Input:          FightRpcRotateInfoNotify& Notify 旋转面服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientRotateInfo( INT64 UserId, FightRpcRotateInfoNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcSkillShotTrajectoryConfig
* Description:    Fight-->发射配置文件异步通知操作函数
* Input:          FightRpcSkillShotTrajectoryConfigNotify& Notify 发射配置文件双向通知
* Output:         无
********************************************************************************************/
void ModuleFight::CliRpcSkillShotTrajectoryConfig( clientInfoT& clientInfo, FightRpcSkillShotTrajectoryConfigNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientSkillShotTrajectoryConfig
* Description:    Fight-->发射配置文件异步通知操作函数
* Input:          FightRpcSkillShotTrajectoryConfigNotify& Notify 发射配置文件双向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSkillShotTrajectoryConfig( INT64 UserId, FightRpcSkillShotTrajectoryConfigNotify& Notify )
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
* Function:       SendToClientAddPlayer
* Description:    Fight-->增加玩家异步通知操作函数
* Input:          FightRpcAddPlayerNotify& Notify 增加玩家服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientAddPlayer( INT64 UserId, FightRpcAddPlayerNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcGetPlayer
* Description:    Fight-->获取角色同步调用操作函数
* Input:          FightRpcGetPlayerAsk& Ask 获取角色请求
* Output:         FightRpcGetPlayerReply& Reply 获取角色回应
********************************************************************************************/
void ModuleFight::CliRpcGetPlayer( clientInfoT& clientInfo, FightRpcGetPlayerAsk& Ask, FightRpcGetPlayerReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(1900);
}

/********************************************************************************************
* Function:       SendToClientSyncAttackProp
* Description:    Fight-->推送战斗数据异步通知操作函数
* Input:          FightRpcSyncAttackPropNotify& Notify 推送战斗数据通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSyncAttackProp( INT64 UserId, FightRpcSyncAttackPropNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientRemoveNpc
* Description:    Fight-->Npc移除通知异步通知操作函数
* Input:          FightRpcRemoveNpcNotify& Notify Npc移除通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientRemoveNpc( INT64 UserId, FightRpcRemoveNpcNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientAddNpc
* Description:    Fight-->创建NPC异步通知操作函数
* Input:          FightRpcAddNpcNotify& Notify 创建NPC服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientAddNpc( INT64 UserId, FightRpcAddNpcNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientChangeBuff
* Description:    Fight-->增加buff异步通知操作函数
* Input:          FightRpcChangeBuffNotify& Notify 增加buff服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientChangeBuff( INT64 UserId, FightRpcChangeBuffNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       CliRpcSyncUserDir
* Description:    Fight-->广播玩家朝向异步通知操作函数
* Input:          FightRpcSyncUserDirNotify& Notify 广播玩家朝向通知
* Output:         无
********************************************************************************************/
void ModuleFight::CliRpcSyncUserDir( clientInfoT& clientInfo, FightRpcSyncUserDirNotify& Notify )
{

	//逻辑代码


}

/********************************************************************************************
* Function:       SendToClientSyncUserDir
* Description:    Fight-->广播玩家朝向异步通知操作函数
* Input:          FightRpcSyncUserDirNotify& Notify 广播玩家朝向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientSyncUserDir( INT64 UserId, FightRpcSyncUserDirNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientNpcState
* Description:    Fight-->Npc状态变化异步通知操作函数
* Input:          FightRpcNpcStateNotify& Notify Npc状态变化通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientNpcState( INT64 UserId, FightRpcNpcStateNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientActTime
* Description:    Fight-->战斗时间修正异步通知操作函数
* Input:          FightRpcActTimeNotify& Notify 战斗时间修正服务器通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleFight::SendToClientActTime( INT64 UserId, FightRpcActTimeNotify& Notify )
{
	UserMgr::Instance().SendMsg( UserId, 0, Notify );
}



