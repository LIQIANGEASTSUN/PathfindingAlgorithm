/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleFight.cpp
* Author:       甘业清
* Description:  Fight类，包含以下内容
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

#include "ModuleFight.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleFight);

//Fight实现类构造函数
ModuleFight::ModuleFight()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFight::CliRpcInsertRoom);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFight::CliRpcRoveOver);
	MsgIdMgr::Instance().MsgRegister( this, &ModuleFight::CliRpcSkillTransfer);

	RpcImpInfoT Imp;
	Imp.Name = "Fight";
	Imp.Code = 19;

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//Fight实现类析构函数
ModuleFight::~ModuleFight()
{

}


//获取模块ID
UINT8 ModuleFight::GetModuleId()
{
	return MODULE_ID_FIGHT;
}

//获取模块名字
TStr ModuleFight::GetModuleName()
{
	return "Fight";
}

//初始化
bool ModuleFight::Initialize()
{

	return true;
}

//结束退出
void ModuleFight::Finalize()
{

}


//毫秒级Tick回调
void ModuleFight::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleFight::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleFight::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleFight::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleFight::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleFight::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleFight::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleFight::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleFight::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleFight::OnPublish(const TStr& publishString)
{
	
}
