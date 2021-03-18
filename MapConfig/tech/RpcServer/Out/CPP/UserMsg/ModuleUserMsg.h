/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleUserMsg.h
* Author:       甘业清
* Description:  GATE调用此RPC处理用户的请求类，包含以下内容
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

#ifndef __MODULE_USERMSG_H
#define __MODULE_USERMSG_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "UserMsgSvrRpc.pb.h"



//GATE调用此RPC处理用户的请求实现类
class ModuleUserMsg : public ModuleBase
{
	DECLARE_INSTANCE(ModuleUserMsg);
public:
	friend class			ModuleMgr;

public:
	//GATE调用此RPC处理用户的请求实现类构造函数
	ModuleUserMsg();
	
	//GATE调用此RPC处理用户的请求实现类析构函数
	virtual					~ModuleUserMsg();

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
	//执行函数实现
	void SvrRpcExec( int nodeId, UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply);


};

//GATE调用此RPC处理用户的请求类的枚举定义
enum ConstUserMsgE
{
	MODULE_ID_USERMSG                            = 9,	//GATE调用此RPC处理用户的请求模块ID


};

template<typename T> struct MessageIdT;


#endif