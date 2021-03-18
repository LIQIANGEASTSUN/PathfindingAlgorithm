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
	* Function:       SendToClientStart
	* Description:    Fight-->开始异步通知操作函数
	* Input:          FightRpcStartNotify& Notify 开始服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientStart( INT64 UserId, FightRpcStartNotify& Notify );

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
	* Function:       SendToClientHPChange
	* Description:    Fight-->生命值变化异步通知操作函数
	* Input:          FightRpcHPChangeNotify& Notify 生命值变化服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientHPChange( INT64 UserId, FightRpcHPChangeNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcRoveOver
	* Description:    Fight-->漫游结束异步通知操作函数
	* Input:          FightRpcRoveOverNotify& Notify 漫游结束双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcRoveOver( clientInfoT& clientInfo, FightRpcRoveOverNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientRoveOver
	* Description:    Fight-->漫游结束异步通知操作函数
	* Input:          FightRpcRoveOverNotify& Notify 漫游结束双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientRoveOver( INT64 UserId, FightRpcRoveOverNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcSkillTransfer
	* Description:    Fight-->传送异步通知操作函数
	* Input:          FightRpcSkillTransferNotify& Notify 传送通知
	* Output:         无
	********************************************************************************************/
	void CliRpcSkillTransfer( clientInfoT& clientInfo, FightRpcSkillTransferNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientSkillTransfer
	* Description:    Fight-->传送异步通知操作函数
	* Input:          FightRpcSkillTransferNotify& Notify 传送通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSkillTransfer( INT64 UserId, FightRpcSkillTransferNotify& Notify );



public:


};

//Fight类的枚举定义
enum ConstFightE
{
	MODULE_ID_FIGHT                              = 19,	//Fight模块ID
	RPC_CODE_FIGHT_START_NOTIFY                  = 1951,	//Fight-->开始-->通知
	RPC_CODE_FIGHT_SYNCUSERPROP_NOTIFY           = 1952,	//Fight-->同步属性-->通知
	RPC_CODE_FIGHT_INSERTROOM_REQUEST            = 1953,	//Fight-->进入房间-->请求
	RPC_CODE_FIGHT_HPCHANGE_NOTIFY               = 1954,	//Fight-->生命值变化-->通知
	RPC_CODE_FIGHT_ROVEOVER_NOTIFY               = 1955,	//Fight-->漫游结束-->通知
	RPC_CODE_FIGHT_SKILLTRANSFER_NOTIFY          = 1956,	//Fight-->传送-->通知


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<FightRpcStartNotify>{ enum{ID=RPC_CODE_FIGHT_START_NOTIFY};};
template<> struct MessageIdT<FightRpcSyncUserPropNotify>{ enum{ID=RPC_CODE_FIGHT_SYNCUSERPROP_NOTIFY};};
template<> struct MessageIdT<FightRpcInsertRoomAsk>{ enum{ID=RPC_CODE_FIGHT_INSERTROOM_REQUEST};};
template<> struct MessageIdT<FightRpcInsertRoomReply>{ enum{ID=RPC_CODE_FIGHT_INSERTROOM_REQUEST};};
template<> struct MessageIdT<FightRpcHPChangeNotify>{ enum{ID=RPC_CODE_FIGHT_HPCHANGE_NOTIFY};};
template<> struct MessageIdT<FightRpcRoveOverNotify>{ enum{ID=RPC_CODE_FIGHT_ROVEOVER_NOTIFY};};
template<> struct MessageIdT<FightRpcSkillTransferNotify>{ enum{ID=RPC_CODE_FIGHT_SKILLTRANSFER_NOTIFY};};


#endif