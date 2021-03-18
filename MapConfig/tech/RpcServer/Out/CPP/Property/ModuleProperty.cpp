/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleProperty.cpp
* Author:       甘业清
* Description:  用户属性类，包含以下内容
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

#include "ModuleProperty.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleProperty);

//用户属性实现类构造函数
ModuleProperty::ModuleProperty()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleProperty::CliRpcSync);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleProperty::CliRpcChangeHead);

	RpcImpInfoT Imp;
	Imp.Name = "Property";
	Imp.Code = 13;
	Imp.RegisterCallback( 1, this, &ModuleProperty::SvrRpcAddValue);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//用户属性实现类析构函数
ModuleProperty::~ModuleProperty()
{

}


//获取模块ID
UINT8 ModuleProperty::GetModuleId()
{
	return MODULE_ID_PROPERTY;
}

//获取模块名字
TStr ModuleProperty::GetModuleName()
{
	return "Property";
}

//初始化
bool ModuleProperty::Initialize()
{

	return true;
}

//结束退出
void ModuleProperty::Finalize()
{

}


//毫秒级Tick回调
void ModuleProperty::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleProperty::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleProperty::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleProperty::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleProperty::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleProperty::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleProperty::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleProperty::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleProperty::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleProperty::OnPublish(const TStr& publishString)
{
	
}
