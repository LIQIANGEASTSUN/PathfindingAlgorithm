/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleFight.h
* Author:       甘业清
* Description:  Fight类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相关回调函数
*               ★用户创建上下线回调函数
*               ★服务器RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_FIGHT_H
#define __MODULE_FIGHT_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "FightCliRpc.pb.h"



//Fight实现类
class ModuleFight : public ModuleBase
{
	DECLARE_INSTANCE(ModuleFight);
public:
	friend class			ModuleMgr;

public:
	//Fight实现类构造函数
	ModuleFight();
	
	//Fight实现类析构函数
	virtual					~ModuleFight();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 uid, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 uid, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 uid );
	
	//配置表更新
	virtual void			OnConfigReload(const TStr& tableName);
	
	//有发布信息
	virtual void			OnPublish(const TStr& publishString);

public:
	/********************************************************************************************
	* Function:       SendToClientSyncUserInfo
	* Description:    Fight-->服务器定时同步异步通知操作函数
	* Input:          FightRpcSyncUserInfoNotify& Notify 服务器定时同步服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSyncUserInfo( INT64 UserId, FightRpcSyncUserInfoNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcBulletShoot
	* Description:    Fight-->发射异步通知操作函数
	* Input:          FightRpcBulletShootNotify& Notify 发射双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcBulletShoot( clientInfoT& clientInfo, FightRpcBulletShootNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientBulletShoot
	* Description:    Fight-->发射异步通知操作函数
	* Input:          FightRpcBulletShootNotify& Notify 发射双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientBulletShoot( INT64 UserId, FightRpcBulletShootNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientGameEnd
	* Description:    Fight-->服务器通知异步通知操作函数
	* Input:          FightRpcGameEndNotify& Notify 服务器通知服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientGameEnd( INT64 UserId, FightRpcGameEndNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientRevive
	* Description:    Fight-->复活异步通知操作函数
	* Input:          FightRpcReviveNotify& Notify 复活通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientRevive( INT64 UserId, FightRpcReviveNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientDead
	* Description:    Fight-->死亡异步通知操作函数
	* Input:          FightRpcDeadNotify& Notify 死亡通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientDead( INT64 UserId, FightRpcDeadNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcStat
	* Description:    Fight-->状态异步通知操作函数
	* Input:          FightRpcStatNotify& Notify 状态双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcStat( clientInfoT& clientInfo, FightRpcStatNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientStat
	* Description:    Fight-->状态异步通知操作函数
	* Input:          FightRpcStatNotify& Notify 状态双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientStat( INT64 UserId, FightRpcStatNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientShake
	* Description:    Fight-->震动异步通知操作函数
	* Input:          FightRpcShakeNotify& Notify 震动通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientShake( INT64 UserId, FightRpcShakeNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientBulletDistroy
	* Description:    Fight-->子弹销毁异步通知操作函数
	* Input:          FightRpcBulletDistroyNotify& Notify 子弹销毁通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientBulletDistroy( INT64 UserId, FightRpcBulletDistroyNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientSpray
	* Description:    Fight-->喷涂异步通知操作函数
	* Input:          FightRpcSprayNotify& Notify 喷涂通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSpray( INT64 UserId, FightRpcSprayNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcReady
	* Description:    Fight-->准备同步调用操作函数
	* Input:          FightRpcReadyAsk& Ask 准备请求
	* Output:         FightRpcReadyReply& Reply 准备回应
	********************************************************************************************/
	void CliRpcReady( clientInfoT& clientInfo, FightRpcReadyAsk& Ask, FightRpcReadyReply& Reply );

	/********************************************************************************************
	* Function:       CliRpcLogin
	* Description:    Fight-->登陆同步调用操作函数
	* Input:          FightRpcLoginAsk& Ask 登陆请求
	* Output:         FightRpcLoginReply& Reply 登陆回应
	********************************************************************************************/
	void CliRpcLogin( clientInfoT& clientInfo, FightRpcLoginAsk& Ask, FightRpcLoginReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientStart
	* Description:    Fight-->开始异步通知操作函数
	* Input:          FightRpcStartNotify& Notify 开始服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientStart( INT64 UserId, FightRpcStartNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientSpeed
	* Description:    Fight-->移动速度异步通知操作函数
	* Input:          FightRpcSpeedNotify& Notify 移动速度服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSpeed( INT64 UserId, FightRpcSpeedNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientHit
	* Description:    Fight-->受击异步通知操作函数
	* Input:          FightRpcHitNotify& Notify 受击服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientHit( INT64 UserId, FightRpcHitNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcSkillAction
	* Description:    Fight-->技能操作异步通知操作函数
	* Input:          FightRpcSkillActionNotify& Notify 技能操作双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcSkillAction( clientInfoT& clientInfo, FightRpcSkillActionNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientSkillAction
	* Description:    Fight-->技能操作异步通知操作函数
	* Input:          FightRpcSkillActionNotify& Notify 技能操作双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSkillAction( INT64 UserId, FightRpcSkillActionNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcSkillOper
	* Description:    Fight-->技能释放异步通知操作函数
	* Input:          FightRpcSkillOperNotify& Notify 技能释放双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcSkillOper( clientInfoT& clientInfo, FightRpcSkillOperNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientSkillOper
	* Description:    Fight-->技能释放异步通知操作函数
	* Input:          FightRpcSkillOperNotify& Notify 技能释放双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSkillOper( INT64 UserId, FightRpcSkillOperNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcSkillShotBullet
	* Description:    Fight-->技能发出子弹异步通知操作函数
	* Input:          FightRpcSkillShotBulletNotify& Notify 技能发出子弹双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcSkillShotBullet( clientInfoT& clientInfo, FightRpcSkillShotBulletNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientSkillShotBullet
	* Description:    Fight-->技能发出子弹异步通知操作函数
	* Input:          FightRpcSkillShotBulletNotify& Notify 技能发出子弹双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSkillShotBullet( INT64 UserId, FightRpcSkillShotBulletNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientRotateInfo
	* Description:    Fight-->旋转面异步通知操作函数
	* Input:          FightRpcRotateInfoNotify& Notify 旋转面服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientRotateInfo( INT64 UserId, FightRpcRotateInfoNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcSkillShotTrajectoryConfig
	* Description:    Fight-->发射配置文件异步通知操作函数
	* Input:          FightRpcSkillShotTrajectoryConfigNotify& Notify 发射配置文件双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcSkillShotTrajectoryConfig( clientInfoT& clientInfo, FightRpcSkillShotTrajectoryConfigNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientSkillShotTrajectoryConfig
	* Description:    Fight-->发射配置文件异步通知操作函数
	* Input:          FightRpcSkillShotTrajectoryConfigNotify& Notify 发射配置文件双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSkillShotTrajectoryConfig( INT64 UserId, FightRpcSkillShotTrajectoryConfigNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncUserProp
	* Description:    Fight-->同步属性异步通知操作函数
	* Input:          FightRpcSyncUserPropNotify& Notify 同步属性服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSyncUserProp( INT64 UserId, FightRpcSyncUserPropNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcInsertRoom
	* Description:    Fight-->进入房间同步调用操作函数
	* Input:          FightRpcInsertRoomAsk& Ask 进入房间请求
	* Output:         FightRpcInsertRoomReply& Reply 进入房间回应
	********************************************************************************************/
	void CliRpcInsertRoom( clientInfoT& clientInfo, FightRpcInsertRoomAsk& Ask, FightRpcInsertRoomReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientAddPlayer
	* Description:    Fight-->增加玩家异步通知操作函数
	* Input:          FightRpcAddPlayerNotify& Notify 增加玩家服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientAddPlayer( INT64 UserId, FightRpcAddPlayerNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcGetPlayer
	* Description:    Fight-->获取角色同步调用操作函数
	* Input:          FightRpcGetPlayerAsk& Ask 获取角色请求
	* Output:         FightRpcGetPlayerReply& Reply 获取角色回应
	********************************************************************************************/
	void CliRpcGetPlayer( clientInfoT& clientInfo, FightRpcGetPlayerAsk& Ask, FightRpcGetPlayerReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientSyncAttackProp
	* Description:    Fight-->推送战斗数据异步通知操作函数
	* Input:          FightRpcSyncAttackPropNotify& Notify 推送战斗数据通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSyncAttackProp( INT64 UserId, FightRpcSyncAttackPropNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientRemoveNpc
	* Description:    Fight-->Npc移除通知异步通知操作函数
	* Input:          FightRpcRemoveNpcNotify& Notify Npc移除通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientRemoveNpc( INT64 UserId, FightRpcRemoveNpcNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientAddNpc
	* Description:    Fight-->创建NPC异步通知操作函数
	* Input:          FightRpcAddNpcNotify& Notify 创建NPC服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientAddNpc( INT64 UserId, FightRpcAddNpcNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientChangeBuff
	* Description:    Fight-->增加buff异步通知操作函数
	* Input:          FightRpcChangeBuffNotify& Notify 增加buff服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientChangeBuff( INT64 UserId, FightRpcChangeBuffNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcSyncUserDir
	* Description:    Fight-->广播玩家朝向异步通知操作函数
	* Input:          FightRpcSyncUserDirNotify& Notify 广播玩家朝向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcSyncUserDir( clientInfoT& clientInfo, FightRpcSyncUserDirNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientSyncUserDir
	* Description:    Fight-->广播玩家朝向异步通知操作函数
	* Input:          FightRpcSyncUserDirNotify& Notify 广播玩家朝向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSyncUserDir( INT64 UserId, FightRpcSyncUserDirNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientNpcState
	* Description:    Fight-->Npc状态变化异步通知操作函数
	* Input:          FightRpcNpcStateNotify& Notify Npc状态变化通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientNpcState( INT64 UserId, FightRpcNpcStateNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientActTime
	* Description:    Fight-->战斗时间修正异步通知操作函数
	* Input:          FightRpcActTimeNotify& Notify 战斗时间修正服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientActTime( INT64 UserId, FightRpcActTimeNotify& Notify );



public:


};

//Fight类的枚举定义
enum ConstFightE
{
	MODULE_ID_FIGHT                              = 19,	//Fight模块ID
	RPC_CODE_FIGHT_SYNCUSERINFO_NOTIFY           = 1951,	//Fight-->服务器定时同步-->通知
	RPC_CODE_FIGHT_BULLETSHOOT_NOTIFY            = 1952,	//Fight-->发射-->通知
	RPC_CODE_FIGHT_GAMEEND_NOTIFY                = 1953,	//Fight-->服务器通知-->通知
	RPC_CODE_FIGHT_REVIVE_NOTIFY                 = 1954,	//Fight-->复活-->通知
	RPC_CODE_FIGHT_DEAD_NOTIFY                   = 1955,	//Fight-->死亡-->通知
	RPC_CODE_FIGHT_STAT_NOTIFY                   = 1956,	//Fight-->状态-->通知
	RPC_CODE_FIGHT_SHAKE_NOTIFY                  = 1957,	//Fight-->震动-->通知
	RPC_CODE_FIGHT_BULLETDISTROY_NOTIFY          = 1958,	//Fight-->子弹销毁-->通知
	RPC_CODE_FIGHT_SPRAY_NOTIFY                  = 1959,	//Fight-->喷涂-->通知
	RPC_CODE_FIGHT_READY_REQUEST                 = 1960,	//Fight-->准备-->请求
	RPC_CODE_FIGHT_LOGIN_REQUEST                 = 1961,	//Fight-->登陆-->请求
	RPC_CODE_FIGHT_START_NOTIFY                  = 1962,	//Fight-->开始-->通知
	RPC_CODE_FIGHT_SPEED_NOTIFY                  = 1963,	//Fight-->移动速度-->通知
	RPC_CODE_FIGHT_HIT_NOTIFY                    = 1964,	//Fight-->受击-->通知
	RPC_CODE_FIGHT_SKILLACTION_NOTIFY            = 1965,	//Fight-->技能操作-->通知
	RPC_CODE_FIGHT_SKILLOPER_NOTIFY              = 1966,	//Fight-->技能释放-->通知
	RPC_CODE_FIGHT_SKILLSHOTBULLET_NOTIFY        = 1967,	//Fight-->技能发出子弹-->通知
	RPC_CODE_FIGHT_ROTATEINFO_NOTIFY             = 1968,	//Fight-->旋转面-->通知
	RPC_CODE_FIGHT_SKILLSHOTTRAJECTORYCONFIG_NOTIFY= 1969,	//Fight-->发射配置文件-->通知
	RPC_CODE_FIGHT_SYNCUSERPROP_NOTIFY           = 1970,	//Fight-->同步属性-->通知
	RPC_CODE_FIGHT_INSERTROOM_REQUEST            = 1971,	//Fight-->进入房间-->请求
	RPC_CODE_FIGHT_ADDPLAYER_NOTIFY              = 1972,	//Fight-->增加玩家-->通知
	RPC_CODE_FIGHT_GETPLAYER_REQUEST             = 1973,	//Fight-->获取角色-->请求
	RPC_CODE_FIGHT_SYNCATTACKPROP_NOTIFY         = 1974,	//Fight-->推送战斗数据-->通知
	RPC_CODE_FIGHT_REMOVENPC_NOTIFY              = 1975,	//Fight-->Npc移除通知-->通知
	RPC_CODE_FIGHT_ADDNPC_NOTIFY                 = 1976,	//Fight-->创建NPC-->通知
	RPC_CODE_FIGHT_CHANGEBUFF_NOTIFY             = 1977,	//Fight-->增加buff-->通知
	RPC_CODE_FIGHT_SYNCUSERDIR_NOTIFY            = 1978,	//Fight-->广播玩家朝向-->通知
	RPC_CODE_FIGHT_NPCSTATE_NOTIFY               = 1979,	//Fight-->Npc状态变化-->通知
	RPC_CODE_FIGHT_ACTTIME_NOTIFY                = 1980,	//Fight-->战斗时间修正-->通知


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<FightRpcSyncUserInfoNotify>{ enum{ID=RPC_CODE_FIGHT_SYNCUSERINFO_NOTIFY};};
template<> struct MessageIdT<FightRpcBulletShootNotify>{ enum{ID=RPC_CODE_FIGHT_BULLETSHOOT_NOTIFY};};
template<> struct MessageIdT<FightRpcGameEndNotify>{ enum{ID=RPC_CODE_FIGHT_GAMEEND_NOTIFY};};
template<> struct MessageIdT<FightRpcReviveNotify>{ enum{ID=RPC_CODE_FIGHT_REVIVE_NOTIFY};};
template<> struct MessageIdT<FightRpcDeadNotify>{ enum{ID=RPC_CODE_FIGHT_DEAD_NOTIFY};};
template<> struct MessageIdT<FightRpcStatNotify>{ enum{ID=RPC_CODE_FIGHT_STAT_NOTIFY};};
template<> struct MessageIdT<FightRpcShakeNotify>{ enum{ID=RPC_CODE_FIGHT_SHAKE_NOTIFY};};
template<> struct MessageIdT<FightRpcBulletDistroyNotify>{ enum{ID=RPC_CODE_FIGHT_BULLETDISTROY_NOTIFY};};
template<> struct MessageIdT<FightRpcSprayNotify>{ enum{ID=RPC_CODE_FIGHT_SPRAY_NOTIFY};};
template<> struct MessageIdT<FightRpcReadyAsk>{ enum{ID=RPC_CODE_FIGHT_READY_REQUEST};};
template<> struct MessageIdT<FightRpcReadyReply>{ enum{ID=RPC_CODE_FIGHT_READY_REQUEST};};
template<> struct MessageIdT<FightRpcLoginAsk>{ enum{ID=RPC_CODE_FIGHT_LOGIN_REQUEST};};
template<> struct MessageIdT<FightRpcLoginReply>{ enum{ID=RPC_CODE_FIGHT_LOGIN_REQUEST};};
template<> struct MessageIdT<FightRpcStartNotify>{ enum{ID=RPC_CODE_FIGHT_START_NOTIFY};};
template<> struct MessageIdT<FightRpcSpeedNotify>{ enum{ID=RPC_CODE_FIGHT_SPEED_NOTIFY};};
template<> struct MessageIdT<FightRpcHitNotify>{ enum{ID=RPC_CODE_FIGHT_HIT_NOTIFY};};
template<> struct MessageIdT<FightRpcSkillActionNotify>{ enum{ID=RPC_CODE_FIGHT_SKILLACTION_NOTIFY};};
template<> struct MessageIdT<FightRpcSkillOperNotify>{ enum{ID=RPC_CODE_FIGHT_SKILLOPER_NOTIFY};};
template<> struct MessageIdT<FightRpcSkillShotBulletNotify>{ enum{ID=RPC_CODE_FIGHT_SKILLSHOTBULLET_NOTIFY};};
template<> struct MessageIdT<FightRpcRotateInfoNotify>{ enum{ID=RPC_CODE_FIGHT_ROTATEINFO_NOTIFY};};
template<> struct MessageIdT<FightRpcSkillShotTrajectoryConfigNotify>{ enum{ID=RPC_CODE_FIGHT_SKILLSHOTTRAJECTORYCONFIG_NOTIFY};};
template<> struct MessageIdT<FightRpcSyncUserPropNotify>{ enum{ID=RPC_CODE_FIGHT_SYNCUSERPROP_NOTIFY};};
template<> struct MessageIdT<FightRpcInsertRoomAsk>{ enum{ID=RPC_CODE_FIGHT_INSERTROOM_REQUEST};};
template<> struct MessageIdT<FightRpcInsertRoomReply>{ enum{ID=RPC_CODE_FIGHT_INSERTROOM_REQUEST};};
template<> struct MessageIdT<FightRpcAddPlayerNotify>{ enum{ID=RPC_CODE_FIGHT_ADDPLAYER_NOTIFY};};
template<> struct MessageIdT<FightRpcGetPlayerAsk>{ enum{ID=RPC_CODE_FIGHT_GETPLAYER_REQUEST};};
template<> struct MessageIdT<FightRpcGetPlayerReply>{ enum{ID=RPC_CODE_FIGHT_GETPLAYER_REQUEST};};
template<> struct MessageIdT<FightRpcSyncAttackPropNotify>{ enum{ID=RPC_CODE_FIGHT_SYNCATTACKPROP_NOTIFY};};
template<> struct MessageIdT<FightRpcRemoveNpcNotify>{ enum{ID=RPC_CODE_FIGHT_REMOVENPC_NOTIFY};};
template<> struct MessageIdT<FightRpcAddNpcNotify>{ enum{ID=RPC_CODE_FIGHT_ADDNPC_NOTIFY};};
template<> struct MessageIdT<FightRpcChangeBuffNotify>{ enum{ID=RPC_CODE_FIGHT_CHANGEBUFF_NOTIFY};};
template<> struct MessageIdT<FightRpcSyncUserDirNotify>{ enum{ID=RPC_CODE_FIGHT_SYNCUSERDIR_NOTIFY};};
template<> struct MessageIdT<FightRpcNpcStateNotify>{ enum{ID=RPC_CODE_FIGHT_NPCSTATE_NOTIFY};};
template<> struct MessageIdT<FightRpcActTimeNotify>{ enum{ID=RPC_CODE_FIGHT_ACTTIME_NOTIFY};};


#endif