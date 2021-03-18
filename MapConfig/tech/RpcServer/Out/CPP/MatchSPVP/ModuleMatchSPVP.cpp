/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMatchSPVP.cpp
* Author:       甘业清
* Description:  匹配类，包含以下内容
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

#include "ModuleMatchSPVP.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleMatchSPVP);

//匹配实现类构造函数
ModuleMatchSPVP::ModuleMatchSPVP()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleMatchSPVP::CliRpcStartMatch);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleMatchSPVP::CliRpcInvitation);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleMatchSPVP::CliRpcAgreeInvitation);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleMatchSPVP::CliRpcSelectHero);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleMatchSPVP::CliRpcGetStatus);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleMatchSPVP::CliRpcShotOff);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleMatchSPVP::CliRpcSelectScene);

	RpcImpInfoT Imp;
	Imp.Name = "MatchSPVP";
	Imp.Code = 21;
	Imp.RegisterCallback( 1, this, &ModuleMatchSPVP::SvrRpcBattleNum);
	Imp.RegisterCallback( 2, this, &ModuleMatchSPVP::SvrRpcAINum);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//匹配实现类析构函数
ModuleMatchSPVP::~ModuleMatchSPVP()
{

}


//获取模块ID
UINT8 ModuleMatchSPVP::GetModuleId()
{
	return MODULE_ID_MATCHSPVP;
}

//获取模块名字
TStr ModuleMatchSPVP::GetModuleName()
{
	return "MatchSPVP";
}

//初始化
bool ModuleMatchSPVP::Initialize()
{

	return true;
}

//结束退出
void ModuleMatchSPVP::Finalize()
{

}


//毫秒级Tick回调
void ModuleMatchSPVP::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleMatchSPVP::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleMatchSPVP::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleMatchSPVP::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleMatchSPVP::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleMatchSPVP::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleMatchSPVP::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleMatchSPVP::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleMatchSPVP::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleMatchSPVP::OnPublish(const TStr& publishString)
{
	
}
