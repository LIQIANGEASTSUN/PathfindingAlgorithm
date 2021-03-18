/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleProperty.h
* Author:       甘业清
* Description:  用户属性类，包含以下内容
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

#ifndef __MODULE_PROPERTY_H
#define __MODULE_PROPERTY_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "PropertySvrRpc.pb.h"
#include "PropertyCliRpc.pb.h"



//用户属性实现类
class ModuleProperty : public ModuleBase
{
	DECLARE_INSTANCE(ModuleProperty);
public:
	friend class			ModuleMgr;

public:
	//用户属性实现类构造函数
	ModuleProperty();
	
	//用户属性实现类析构函数
	virtual					~ModuleProperty();

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
	* Description:    用户属性-->同步同步调用操作函数
	* Input:          PropertyRpcSyncAsk& Ask 同步请求
	* Output:         PropertyRpcSyncReply& Reply 同步回应
	********************************************************************************************/
	void CliRpcSync( clientInfoT& clientInfo, PropertyRpcSyncAsk& Ask, PropertyRpcSyncReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientUpdate
	* Description:    用户属性-->更新数据异步通知操作函数
	* Input:          PropertyRpcUpdateNotify& Notify 更新数据通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientUpdate( INT64 UserId, PropertyRpcUpdateNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcChangeHead
	* Description:    用户属性-->换头像同步调用操作函数
	* Input:          PropertyRpcChangeHeadAsk& Ask 换头像请求
	* Output:         PropertyRpcChangeHeadReply& Reply 换头像回应
	********************************************************************************************/
	void CliRpcChangeHead( clientInfoT& clientInfo, PropertyRpcChangeHeadAsk& Ask, PropertyRpcChangeHeadReply& Reply );



public:
	//增加函数实现
	void SvrRpcAddValue( int nodeId, PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply);


};

//用户属性类的枚举定义
enum ConstPropertyE
{
	MODULE_ID_PROPERTY                           = 13,	//用户属性模块ID
	RPC_CODE_PROPERTY_SYNC_REQUEST               = 1351,	//用户属性-->同步-->请求
	RPC_CODE_PROPERTY_UPDATE_NOTIFY              = 1352,	//用户属性-->更新数据-->通知
	RPC_CODE_PROPERTY_CHANGEHEAD_REQUEST         = 1353,	//用户属性-->换头像-->请求


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<PropertyRpcSyncAsk>{ enum{ID=RPC_CODE_PROPERTY_SYNC_REQUEST};};
template<> struct MessageIdT<PropertyRpcSyncReply>{ enum{ID=RPC_CODE_PROPERTY_SYNC_REQUEST};};
template<> struct MessageIdT<PropertyRpcUpdateNotify>{ enum{ID=RPC_CODE_PROPERTY_UPDATE_NOTIFY};};
template<> struct MessageIdT<PropertyRpcChangeHeadAsk>{ enum{ID=RPC_CODE_PROPERTY_CHANGEHEAD_REQUEST};};
template<> struct MessageIdT<PropertyRpcChangeHeadReply>{ enum{ID=RPC_CODE_PROPERTY_CHANGEHEAD_REQUEST};};


#endif