/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleRaft.cpp
* Author:       甘业清
* Description:  raft消息类，包含以下内容
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

#include "ModuleRaft.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleRaft);

//raft消息实现类构造函数
ModuleRaft::ModuleRaft()
{

	RpcImpInfoT Imp;
	Imp.Name = "Raft";
	Imp.Code = 18;
	Imp.RegisterCallback( 1, this, &ModuleRaft::SvrRpcVote);
	Imp.RegisterCallback( 2, this, &ModuleRaft::SvrRpcTick);
	Imp.RegisterCallback( 3, this, &ModuleRaft::SvrRpcSyncLog);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//raft消息实现类析构函数
ModuleRaft::~ModuleRaft()
{

}


//获取模块ID
UINT8 ModuleRaft::GetModuleId()
{
	return MODULE_ID_RAFT;
}

//获取模块名字
TStr ModuleRaft::GetModuleName()
{
	return "Raft";
}

//初始化
bool ModuleRaft::Initialize()
{

	return true;
}

//结束退出
void ModuleRaft::Finalize()
{

}


//毫秒级Tick回调
void ModuleRaft::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleRaft::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleRaft::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleRaft::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleRaft::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleRaft::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleRaft::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleRaft::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleRaft::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleRaft::OnPublish(const TStr& publishString)
{
	
}
