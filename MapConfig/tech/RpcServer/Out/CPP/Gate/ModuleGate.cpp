/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleGate.cpp
* Author:       甘业清
* Description:  接入服务类，包含以下内容
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

#include "ModuleGate.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleGate);

//接入服务实现类构造函数
ModuleGate::ModuleGate()
{

	RpcImpInfoT Imp;
	Imp.Name = "Gate";
	Imp.Code = 8;
	Imp.RegisterCallback( 1, this, &ModuleGate::SvrRpcSendMsg);
	Imp.RegisterCallback( 2, this, &ModuleGate::SvrRpcBroadcastMsg);
	Imp.RegisterCallback( 3, this, &ModuleGate::SvrRpcCloseNode);
	Imp.RegisterCallback( 4, this, &ModuleGate::SvrRpcRegisterModule);
	Imp.RegisterCallback( 5, this, &ModuleGate::SvrRpcKick);
	Imp.RegisterCallback( 6, this, &ModuleGate::SvrRpcOnline);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//接入服务实现类析构函数
ModuleGate::~ModuleGate()
{

}


//获取模块ID
UINT8 ModuleGate::GetModuleId()
{
	return MODULE_ID_GATE;
}

//获取模块名字
TStr ModuleGate::GetModuleName()
{
	return "Gate";
}

//初始化
bool ModuleGate::Initialize()
{

	return true;
}

//结束退出
void ModuleGate::Finalize()
{

}


//毫秒级Tick回调
void ModuleGate::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleGate::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleGate::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleGate::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleGate::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleGate::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleGate::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleGate::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleGate::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleGate::OnPublish(const TStr& publishString)
{
	
}
