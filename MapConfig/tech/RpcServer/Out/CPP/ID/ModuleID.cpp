/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleID.cpp
* Author:       甘业清
* Description:  ID生成类，包含以下内容
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

#include "ModuleID.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleID);

//ID生成实现类构造函数
ModuleID::ModuleID()
{

	RpcImpInfoT Imp;
	Imp.Name = "ID";
	Imp.Code = 11;
	Imp.RegisterCallback( 1, this, &ModuleID::SvrRpcID);
	Imp.RegisterCallback( 2, this, &ModuleID::SvrRpcAddUser);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//ID生成实现类析构函数
ModuleID::~ModuleID()
{

}


//获取模块ID
UINT8 ModuleID::GetModuleId()
{
	return MODULE_ID_ID;
}

//获取模块名字
TStr ModuleID::GetModuleName()
{
	return "ID";
}

//初始化
bool ModuleID::Initialize()
{

	return true;
}

//结束退出
void ModuleID::Finalize()
{

}


//毫秒级Tick回调
void ModuleID::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleID::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleID::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleID::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleID::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleID::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleID::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleID::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleID::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleID::OnPublish(const TStr& publishString)
{
	
}
