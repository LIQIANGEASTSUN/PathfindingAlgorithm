/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleUserMsg.cpp
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

#include "ModuleUserMsg.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleUserMsg);

//GATE调用此RPC处理用户的请求实现类构造函数
ModuleUserMsg::ModuleUserMsg()
{

	RpcImpInfoT Imp;
	Imp.Name = "UserMsg";
	Imp.Code = 9;
	Imp.RegisterCallback( 1, this, &ModuleUserMsg::SvrRpcExec);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//GATE调用此RPC处理用户的请求实现类析构函数
ModuleUserMsg::~ModuleUserMsg()
{

}


//获取模块ID
UINT8 ModuleUserMsg::GetModuleId()
{
	return MODULE_ID_USERMSG;
}

//获取模块名字
TStr ModuleUserMsg::GetModuleName()
{
	return "UserMsg";
}

//初始化
bool ModuleUserMsg::Initialize()
{

	return true;
}

//结束退出
void ModuleUserMsg::Finalize()
{

}


//毫秒级Tick回调
void ModuleUserMsg::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleUserMsg::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleUserMsg::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleUserMsg::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleUserMsg::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleUserMsg::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleUserMsg::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleUserMsg::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleUserMsg::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleUserMsg::OnPublish(const TStr& publishString)
{
	
}
