/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleSPVPMatch.cpp
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

#include "ModuleSPVPMatch.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleSPVPMatch);

//匹配实现类构造函数
ModuleSPVPMatch::ModuleSPVPMatch()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleSPVPMatch::CliRpcStartMatch);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleSPVPMatch::CliRpcInvitation);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleSPVPMatch::CliRpcAgreeInvitation);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleSPVPMatch::CliRpcSelectHero);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleSPVPMatch::CliRpcGetStatus);

	RpcImpInfoT Imp;
	Imp.Name = "SPVPMatch";
	Imp.Code = 21;

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//匹配实现类析构函数
ModuleSPVPMatch::~ModuleSPVPMatch()
{

}


//获取模块ID
UINT8 ModuleSPVPMatch::GetModuleId()
{
	return MODULE_ID_SPVPMATCH;
}

//获取模块名字
TStr ModuleSPVPMatch::GetModuleName()
{
	return "SPVPMatch";
}

//初始化
bool ModuleSPVPMatch::Initialize()
{

	return true;
}

//结束退出
void ModuleSPVPMatch::Finalize()
{

}


//毫秒级Tick回调
void ModuleSPVPMatch::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleSPVPMatch::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleSPVPMatch::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleSPVPMatch::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleSPVPMatch::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleSPVPMatch::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleSPVPMatch::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleSPVPMatch::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleSPVPMatch::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleSPVPMatch::OnPublish(const TStr& publishString)
{
	
}
