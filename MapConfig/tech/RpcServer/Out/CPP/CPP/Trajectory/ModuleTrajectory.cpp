/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTrajectory.cpp
* Author:       甘业清
* Description:  弹道配置类，包含以下内容
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

#include "ModuleTrajectory.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleTrajectory);

//弹道配置实现类构造函数
ModuleTrajectory::ModuleTrajectory()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTrajectory::CliRpcSync);

	RpcImpInfoT Imp;
	Imp.Name = "Trajectory";
	Imp.Code = 16;

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//弹道配置实现类析构函数
ModuleTrajectory::~ModuleTrajectory()
{

}


//获取模块ID
UINT8 ModuleTrajectory::GetModuleId()
{
	return MODULE_ID_TRAJECTORY;
}

//获取模块名字
TStr ModuleTrajectory::GetModuleName()
{
	return "Trajectory";
}

//初始化
bool ModuleTrajectory::Initialize()
{

	return true;
}

//结束退出
void ModuleTrajectory::Finalize()
{

}


//毫秒级Tick回调
void ModuleTrajectory::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleTrajectory::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleTrajectory::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleTrajectory::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleTrajectory::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleTrajectory::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleTrajectory::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleTrajectory::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleTrajectory::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleTrajectory::OnPublish(const TStr& publishString)
{
	
}
