/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleDBCache.h
* Author:       甘业清
* Description:  数据缓存服务器类，包含以下内容
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

#ifndef __MODULE_DBCACHE_H
#define __MODULE_DBCACHE_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "DBCacheSvrRpc.pb.h"



//数据缓存服务器实现类
class ModuleDBCache : public ModuleBase
{
	DECLARE_INSTANCE(ModuleDBCache);
public:
	friend class			ModuleMgr;

public:
	//数据缓存服务器实现类构造函数
	ModuleDBCache();
	
	//数据缓存服务器实现类析构函数
	virtual					~ModuleDBCache();

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
	//添加数据函数实现
	void SvrRpcInsert( int nodeId, DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply);
	//删除数据函数实现
	void SvrRpcDelete( int nodeId, DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply);
	//修改数据函数实现
	void SvrRpcUpdate( int nodeId, DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply);
	//查询数据函数实现
	void SvrRpcSelect( int nodeId, DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply);


};

//数据缓存服务器类的枚举定义
enum ConstDBCacheE
{
	MODULE_ID_DBCACHE                            = 25,	//数据缓存服务器模块ID


};

template<typename T> struct MessageIdT;


#endif