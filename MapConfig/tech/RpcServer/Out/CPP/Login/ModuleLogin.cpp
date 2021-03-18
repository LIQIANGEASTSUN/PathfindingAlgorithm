/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleLogin.cpp
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

#include "ModuleLogin.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleLogin);

//登陆实现类构造函数
ModuleLogin::ModuleLogin()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleLogin::CliRpcReady);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleLogin::CliRpcStart);

	RpcImpInfoT Imp;
	Imp.Name = "Login";
	Imp.Code = 20;

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//登陆实现类析构函数
ModuleLogin::~ModuleLogin()
{

}


//获取模块ID
UINT8 ModuleLogin::GetModuleId()
{
	return MODULE_ID_LOGIN;
}

//获取模块名字
TStr ModuleLogin::GetModuleName()
{
	return "Login";
}

//初始化
bool ModuleLogin::Initialize()
{

	return true;
}

//结束退出
void ModuleLogin::Finalize()
{

}


//毫秒级Tick回调
void ModuleLogin::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleLogin::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleLogin::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleLogin::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleLogin::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleLogin::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleLogin::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleLogin::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleLogin::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleLogin::OnPublish(const TStr& publishString)
{
	
}
