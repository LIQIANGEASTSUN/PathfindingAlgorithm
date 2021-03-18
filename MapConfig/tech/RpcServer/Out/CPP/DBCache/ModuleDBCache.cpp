/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleDBCache.cpp
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

#include "ModuleDBCache.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleDBCache);

//数据缓存服务器实现类构造函数
ModuleDBCache::ModuleDBCache()
{

	RpcImpInfoT Imp;
	Imp.Name = "DBCache";
	Imp.Code = 25;
	Imp.RegisterCallback( 1, this, &ModuleDBCache::SvrRpcInsert);
	Imp.RegisterCallback( 2, this, &ModuleDBCache::SvrRpcDelete);
	Imp.RegisterCallback( 3, this, &ModuleDBCache::SvrRpcUpdate);
	Imp.RegisterCallback( 4, this, &ModuleDBCache::SvrRpcSelect);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//数据缓存服务器实现类析构函数
ModuleDBCache::~ModuleDBCache()
{

}


//获取模块ID
UINT8 ModuleDBCache::GetModuleId()
{
	return MODULE_ID_DBCACHE;
}

//获取模块名字
TStr ModuleDBCache::GetModuleName()
{
	return "DBCache";
}

//初始化
bool ModuleDBCache::Initialize()
{

	return true;
}

//结束退出
void ModuleDBCache::Finalize()
{

}


//毫秒级Tick回调
void ModuleDBCache::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleDBCache::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleDBCache::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleDBCache::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleDBCache::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleDBCache::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleDBCache::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleDBCache::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleDBCache::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleDBCache::OnPublish(const TStr& publishString)
{
	
}
