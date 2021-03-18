/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleLog.cpp
* Author:       甘业清
* Description:  日志服务类，包含以下内容
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

#include "ModuleLog.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleLog);

//日志服务实现类构造函数
ModuleLog::ModuleLog()
{

	RpcImpInfoT Imp;
	Imp.Name = "Log";
	Imp.Code = 24;
	Imp.RegisterCallback( 1, this, &ModuleLog::SvrRpcSave);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//日志服务实现类析构函数
ModuleLog::~ModuleLog()
{

}


//获取模块ID
UINT8 ModuleLog::GetModuleId()
{
	return MODULE_ID_LOG;
}

//获取模块名字
TStr ModuleLog::GetModuleName()
{
	return "Log";
}

//初始化
bool ModuleLog::Initialize()
{

	return true;
}

//结束退出
void ModuleLog::Finalize()
{

}


//毫秒级Tick回调
void ModuleLog::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleLog::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleLog::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleLog::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleLog::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleLog::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleLog::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleLog::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleLog::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleLog::OnPublish(const TStr& publishString)
{
	
}
