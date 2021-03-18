/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleIK.cpp
* Author:       甘业清
* Description:  IK类，包含以下内容
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

#include "ModuleIK.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleIK);

//IK实现类构造函数
ModuleIK::ModuleIK()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleIK::CliRpcsync);

	RpcImpInfoT Imp;
	Imp.Name = "IK";
	Imp.Code = 32;

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//IK实现类析构函数
ModuleIK::~ModuleIK()
{

}


//获取模块ID
UINT8 ModuleIK::GetModuleId()
{
	return MODULE_ID_IK;
}

//获取模块名字
TStr ModuleIK::GetModuleName()
{
	return "IK";
}

//初始化
bool ModuleIK::Initialize()
{

	return true;
}

//结束退出
void ModuleIK::Finalize()
{

}


//毫秒级Tick回调
void ModuleIK::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleIK::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleIK::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleIK::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleIK::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleIK::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleIK::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleIK::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleIK::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleIK::OnPublish(const TStr& publishString)
{
	
}
