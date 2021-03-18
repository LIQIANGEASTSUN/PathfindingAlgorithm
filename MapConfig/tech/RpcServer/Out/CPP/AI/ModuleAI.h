/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleAI.h
* Author:       甘业清
* Description:  AI 类，包含以下内容
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

#ifndef __MODULE_AI_H
#define __MODULE_AI_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "AISvrRpc.pb.h"



//AI 实现类
class ModuleAI : public ModuleBase
{
	DECLARE_INSTANCE(ModuleAI);
public:
	friend class			ModuleMgr;

public:
	//AI 实现类构造函数
	ModuleAI();
	
	//AI 实现类析构函数
	virtual					~ModuleAI();

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


public:
	//通知创建AI场景函数实现
	void SvrRpcCreateAIScene( int nodeId, AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply);
	//删除场景函数实现
	void SvrRpcDeleteAIScene( int nodeId, AIRpcDeleteAISceneNotify& notify);
	//加载玩家函数实现
	void SvrRpcLoadUsers( int nodeId, AIRpcLoadUsersNotify& notify);
	//通知AI操作函数实现
	void SvrRpcNoticeAIUserOper( int nodeId, AIRpcNoticeAIUserOperNotify& notify);
	//更新场景信息函数实现
	void SvrRpcNoticeUpdateSceneInfo( int nodeId, AIRpcNoticeUpdateSceneInfoNotify& notify);
	//delete user函数实现
	void SvrRpcDeleteUser( int nodeId, AIRpcDeleteUserNotify& notify);


};

//AI 类的枚举定义
enum ConstAIE
{
	MODULE_ID_AI                                 = 27,	//AI 模块ID


};

template<typename T> struct MessageIdT;


#endif