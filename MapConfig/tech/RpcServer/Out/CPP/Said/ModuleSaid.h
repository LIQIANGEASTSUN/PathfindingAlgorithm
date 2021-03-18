/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleSaid.h
* Author:       甘业清
* Description:  聊天类，包含以下内容
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

#ifndef __MODULE_SAID_H
#define __MODULE_SAID_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "SaidSvrRpc.pb.h"
#include "SaidCliRpc.pb.h"



//聊天实现类
class ModuleSaid : public ModuleBase
{
	DECLARE_INSTANCE(ModuleSaid);
public:
	friend class			ModuleMgr;

public:
	//聊天实现类构造函数
	ModuleSaid();
	
	//聊天实现类析构函数
	virtual					~ModuleSaid();

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
	* Function:       CliRpcSaid
	* Description:    聊天-->聊天同步调用操作函数
	* Input:          SaidRpcSaidAsk& Ask 聊天请求
	* Output:         SaidRpcSaidReply& Reply 聊天回应
	********************************************************************************************/
	void CliRpcSaid( clientInfoT& clientInfo, SaidRpcSaidAsk& Ask, SaidRpcSaidReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientSaidBroadcas
	* Description:    聊天-->聊天广播异步通知操作函数
	* Input:          SaidRpcSaidBroadcasNotify& Notify 聊天广播服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSaidBroadcas( INT64 UserId, SaidRpcSaidBroadcasNotify& Notify );



public:
	//创建读取房间函数实现
	void SvrRpcCreateLoadRoom( int nodeId, SaidRpcCreateLoadRoomNotify& notify);
	//消息转发函数实现
	void SvrRpcMessageForward( int nodeId, SaidRpcMessageForwardNotify& notify);


};

//聊天类的枚举定义
enum ConstSaidE
{
	MODULE_ID_SAID                               = 22,	//聊天模块ID
	RPC_CODE_SAID_SAID_REQUEST                   = 2251,	//聊天-->聊天-->请求
	RPC_CODE_SAID_SAIDBROADCAS_NOTIFY            = 2252,	//聊天-->聊天广播-->通知


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<SaidRpcSaidAsk>{ enum{ID=RPC_CODE_SAID_SAID_REQUEST};};
template<> struct MessageIdT<SaidRpcSaidReply>{ enum{ID=RPC_CODE_SAID_SAID_REQUEST};};
template<> struct MessageIdT<SaidRpcSaidBroadcasNotify>{ enum{ID=RPC_CODE_SAID_SAIDBROADCAS_NOTIFY};};


#endif