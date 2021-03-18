/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleAuth.cpp
* Author:       甘业清
* Description:  认证服务类，包含以下内容
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

#include "ModuleAuth.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleAuth);

//认证服务实现类构造函数
ModuleAuth::ModuleAuth()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleAuth::CliRpcAuth);

	RpcImpInfoT Imp;
	Imp.Name = "Auth";
	Imp.Code = 12;
	Imp.RegisterCallback( 1, this, &ModuleAuth::SvrRpcOffline);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//认证服务实现类析构函数
ModuleAuth::~ModuleAuth()
{

}


//获取模块ID
UINT8 ModuleAuth::GetModuleId()
{
	return MODULE_ID_AUTH;
}

//获取模块名字
TStr ModuleAuth::GetModuleName()
{
	return "Auth";
}

//初始化
bool ModuleAuth::Initialize()
{

	return true;
}

//结束退出
void ModuleAuth::Finalize()
{

}


//毫秒级Tick回调
void ModuleAuth::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleAuth::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleAuth::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleAuth::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleAuth::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleAuth::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleAuth::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleAuth::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleAuth::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleAuth::OnPublish(const TStr& publishString)
{
	
}
