/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleLogin.h
* Author:       甘业清
* Description:  登陆类，包含以下内容
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

#ifndef __MODULE_LOGIN_H
#define __MODULE_LOGIN_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "LoginCliRpc.pb.h"



//登陆实现类
class ModuleLogin : public ModuleBase
{
	DECLARE_INSTANCE(ModuleLogin);
public:
	friend class			ModuleMgr;

public:
	//登陆实现类构造函数
	ModuleLogin();
	
	//登陆实现类析构函数
	virtual					~ModuleLogin();

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
	* Function:       CliRpcReady
	* Description:    登陆-->准备同步调用操作函数
	* Input:          LoginRpcReadyAsk& Ask 准备请求
	* Output:         LoginRpcReadyReply& Reply 准备回应
	********************************************************************************************/
	void CliRpcReady( clientInfoT& clientInfo, LoginRpcReadyAsk& Ask, LoginRpcReadyReply& Reply );

	/********************************************************************************************
	* Function:       CliRpcStart
	* Description:    登陆-->开始游戏异步通知操作函数
	* Input:          LoginRpcStartNotify& Notify 开始游戏通知
	* Output:         无
	********************************************************************************************/
	void CliRpcStart( clientInfoT& clientInfo, LoginRpcStartNotify& Notify );



public:


};

//登陆类的枚举定义
enum ConstLoginE
{
	MODULE_ID_LOGIN                              = 20,	//登陆模块ID
	RPC_CODE_LOGIN_READY_REQUEST                 = 2051,	//登陆-->准备-->请求
	RPC_CODE_LOGIN_START_NOTIFY                  = 2052,	//登陆-->开始游戏-->通知


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<LoginRpcReadyAsk>{ enum{ID=RPC_CODE_LOGIN_READY_REQUEST};};
template<> struct MessageIdT<LoginRpcReadyReply>{ enum{ID=RPC_CODE_LOGIN_READY_REQUEST};};
template<> struct MessageIdT<LoginRpcStartNotify>{ enum{ID=RPC_CODE_LOGIN_START_NOTIFY};};


#endif