/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTeam.cpp
* Author:       甘业清
* Description:  组队类，包含以下内容
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

#include "ModuleTeam.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleTeam);

//组队实现类构造函数
ModuleTeam::ModuleTeam()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::CliRpcPullTeammate);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::CliRpcAddTeamNoify);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::CliRpcGetTeam);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::CliRpcCtrlTeam);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleTeam::CliRpcFindTeam);

	RpcImpInfoT Imp;
	Imp.Name = "Team";
	Imp.Code = 28;
	Imp.RegisterCallback( 1, this, &ModuleTeam::SvrRpcGetTeam);
	Imp.RegisterCallback( 2, this, &ModuleTeam::SvrRpcTeamOver);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//组队实现类析构函数
ModuleTeam::~ModuleTeam()
{

}


//获取模块ID
UINT8 ModuleTeam::GetModuleId()
{
	return MODULE_ID_TEAM;
}

//获取模块名字
TStr ModuleTeam::GetModuleName()
{
	return "Team";
}

//初始化
bool ModuleTeam::Initialize()
{

	return true;
}

//结束退出
void ModuleTeam::Finalize()
{

}


//毫秒级Tick回调
void ModuleTeam::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleTeam::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleTeam::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleTeam::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleTeam::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleTeam::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleTeam::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleTeam::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleTeam::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleTeam::OnPublish(const TStr& publishString)
{
	
}
