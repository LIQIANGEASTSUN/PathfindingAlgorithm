/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleAuth.h
* Author:       甘业清
* Description:  认证服务类，包含以下内容
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

#ifndef __MODULE_AUTH_H
#define __MODULE_AUTH_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "AuthSvrRpc.pb.h"
#include "AuthCliRpc.pb.h"



//认证服务实现类
class ModuleAuth : public ModuleBase
{
	DECLARE_INSTANCE(ModuleAuth);
public:
	friend class			ModuleMgr;

public:
	//认证服务实现类构造函数
	ModuleAuth();
	
	//认证服务实现类析构函数
	virtual					~ModuleAuth();

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
	* Function:       CliRpcAuth
	* Description:    认证服务-->用户认证同步调用操作函数
	* Input:          AuthRpcAuthAsk& Ask 用户认证请求
	* Output:         AuthRpcAuthReply& Reply 用户认证回应
	********************************************************************************************/
	void CliRpcAuth( clientInfoT& clientInfo, AuthRpcAuthAsk& Ask, AuthRpcAuthReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientKick
	* Description:    认证服务-->踢人异步通知操作函数
	* Input:          AuthRpcKickNotify& Notify 踢人服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientKick( INT64 UserId, AuthRpcKickNotify& Notify );



public:
	//用户下线函数实现
	void SvrRpcOffline( int nodeId, AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply);


};

//认证服务类的枚举定义
enum ConstAuthE
{
	MODULE_ID_AUTH                               = 12,	//认证服务模块ID
	RPC_CODE_AUTH_AUTH_REQUEST                   = 1251,	//认证服务-->用户认证-->请求
	RPC_CODE_AUTH_KICK_NOTIFY                    = 1252,	//认证服务-->踢人-->通知


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<AuthRpcAuthAsk>{ enum{ID=RPC_CODE_AUTH_AUTH_REQUEST};};
template<> struct MessageIdT<AuthRpcAuthReply>{ enum{ID=RPC_CODE_AUTH_AUTH_REQUEST};};
template<> struct MessageIdT<AuthRpcKickNotify>{ enum{ID=RPC_CODE_AUTH_KICK_NOTIFY};};


#endif