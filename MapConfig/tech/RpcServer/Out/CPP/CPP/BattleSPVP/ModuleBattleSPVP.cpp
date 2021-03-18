/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBattleSPVP.cpp
* Author:       甘业清
* Description:  战斗同步类，包含以下内容
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

#include "ModuleBattleSPVP.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleBattleSPVP);

//战斗同步实现类构造函数
ModuleBattleSPVP::ModuleBattleSPVP()
{

	RpcImpInfoT Imp;
	Imp.Name = "BattleSPVP";
	Imp.Code = 23;
	Imp.RegisterCallback( 1, this, &ModuleBattleSPVP::SvrRpcCreateRoomSPVP);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//战斗同步实现类析构函数
ModuleBattleSPVP::~ModuleBattleSPVP()
{

}


//获取模块ID
UINT8 ModuleBattleSPVP::GetModuleId()
{
	return MODULE_ID_BATTLESPVP;
}

//获取模块名字
TStr ModuleBattleSPVP::GetModuleName()
{
	return "BattleSPVP";
}

//初始化
bool ModuleBattleSPVP::Initialize()
{

	return true;
}

//结束退出
void ModuleBattleSPVP::Finalize()
{

}


//毫秒级Tick回调
void ModuleBattleSPVP::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleBattleSPVP::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleBattleSPVP::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleBattleSPVP::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleBattleSPVP::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleBattleSPVP::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleBattleSPVP::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleBattleSPVP::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleBattleSPVP::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleBattleSPVP::OnPublish(const TStr& publishString)
{
	
}
