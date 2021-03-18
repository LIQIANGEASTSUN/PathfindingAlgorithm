/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleHero.cpp
* Author:       甘业清
* Description:  英雄类，包含以下内容
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

#include "ModuleHero.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleHero);

//英雄实现类构造函数
ModuleHero::ModuleHero()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleHero::CliRpcSync);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleHero::CliRpcActive);

	RpcImpInfoT Imp;
	Imp.Name = "Hero";
	Imp.Code = 20;
	Imp.RegisterCallback( 1, this, &ModuleHero::SvrRpcCheckHeroID);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//英雄实现类析构函数
ModuleHero::~ModuleHero()
{

}


//获取模块ID
UINT8 ModuleHero::GetModuleId()
{
	return MODULE_ID_HERO;
}

//获取模块名字
TStr ModuleHero::GetModuleName()
{
	return "Hero";
}

//初始化
bool ModuleHero::Initialize()
{

	return true;
}

//结束退出
void ModuleHero::Finalize()
{

}


//毫秒级Tick回调
void ModuleHero::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleHero::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleHero::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleHero::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleHero::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleHero::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleHero::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleHero::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleHero::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleHero::OnPublish(const TStr& publishString)
{
	
}
