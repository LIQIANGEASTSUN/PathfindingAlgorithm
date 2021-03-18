/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleHero.h
* Author:       甘业清
* Description:  英雄类，包含以下内容
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

#ifndef __MODULE_HERO_H
#define __MODULE_HERO_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "HeroSvrRpc.pb.h"
#include "HeroCliRpc.pb.h"



//英雄实现类
class ModuleHero : public ModuleBase
{
	DECLARE_INSTANCE(ModuleHero);
public:
	friend class			ModuleMgr;

public:
	//英雄实现类构造函数
	ModuleHero();
	
	//英雄实现类析构函数
	virtual					~ModuleHero();

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
	* Function:       CliRpcSync
	* Description:    英雄-->同步数据同步调用操作函数
	* Input:          HeroRpcSyncAsk& Ask 同步数据请求
	* Output:         HeroRpcSyncReply& Reply 同步数据回应
	********************************************************************************************/
	void CliRpcSync( clientInfoT& clientInfo, HeroRpcSyncAsk& Ask, HeroRpcSyncReply& Reply );

	/********************************************************************************************
	* Function:       CliRpcActive
	* Description:    英雄-->激活英雄同步调用操作函数
	* Input:          HeroRpcActiveAsk& Ask 激活英雄请求
	* Output:         HeroRpcActiveReply& Reply 激活英雄回应
	********************************************************************************************/
	void CliRpcActive( clientInfoT& clientInfo, HeroRpcActiveAsk& Ask, HeroRpcActiveReply& Reply );



public:
	//检测是不是有这个英雄函数实现
	void SvrRpcCheckHeroID( int nodeId, HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply);


};

//英雄类的枚举定义
enum ConstHeroE
{
	MODULE_ID_HERO                               = 20,	//英雄模块ID
	RPC_CODE_HERO_SYNC_REQUEST                   = 2051,	//英雄-->同步数据-->请求
	RPC_CODE_HERO_ACTIVE_REQUEST                 = 2052,	//英雄-->激活英雄-->请求


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<HeroRpcSyncAsk>{ enum{ID=RPC_CODE_HERO_SYNC_REQUEST};};
template<> struct MessageIdT<HeroRpcSyncReply>{ enum{ID=RPC_CODE_HERO_SYNC_REQUEST};};
template<> struct MessageIdT<HeroRpcActiveAsk>{ enum{ID=RPC_CODE_HERO_ACTIVE_REQUEST};};
template<> struct MessageIdT<HeroRpcActiveReply>{ enum{ID=RPC_CODE_HERO_ACTIVE_REQUEST};};


#endif