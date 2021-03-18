/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleSaid.cpp
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

#include "ModuleSaid.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleSaid);

//聊天实现类构造函数
ModuleSaid::ModuleSaid()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleSaid::CliRpcSaid);

	RpcImpInfoT Imp;
	Imp.Name = "Said";
	Imp.Code = 22;
	Imp.RegisterCallback( 1, this, &ModuleSaid::SvrRpcCreateLoadRoom);
	Imp.RegisterCallback( 2, this, &ModuleSaid::SvrRpcMessageForward);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//聊天实现类析构函数
ModuleSaid::~ModuleSaid()
{

}


//获取模块ID
UINT8 ModuleSaid::GetModuleId()
{
	return MODULE_ID_SAID;
}

//获取模块名字
TStr ModuleSaid::GetModuleName()
{
	return "Said";
}

//初始化
bool ModuleSaid::Initialize()
{

	return true;
}

//结束退出
void ModuleSaid::Finalize()
{

}


//毫秒级Tick回调
void ModuleSaid::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleSaid::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleSaid::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleSaid::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleSaid::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleSaid::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleSaid::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleSaid::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleSaid::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleSaid::OnPublish(const TStr& publishString)
{
	
}
