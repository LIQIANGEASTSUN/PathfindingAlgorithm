/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleAI.cpp
* Author:       甘业清
* Description:  AI 类，包含以下内容
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

#include "ModuleAI.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleAI);

//AI 实现类构造函数
ModuleAI::ModuleAI()
{

	RpcImpInfoT Imp;
	Imp.Name = "AI";
	Imp.Code = 27;
	Imp.RegisterCallback( 1, this, &ModuleAI::SvrRpcCreateAIScene);
	Imp.RegisterCallback( 2, this, &ModuleAI::SvrRpcDeleteAIScene);
	Imp.RegisterCallback( 3, this, &ModuleAI::SvrRpcLoadUsers);
	Imp.RegisterCallback( 4, this, &ModuleAI::SvrRpcNoticeAIUserOper);
	Imp.RegisterCallback( 5, this, &ModuleAI::SvrRpcNoticeUpdateSceneInfo);
	Imp.RegisterCallback( 6, this, &ModuleAI::SvrRpcDeleteUser);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//AI 实现类析构函数
ModuleAI::~ModuleAI()
{

}


//获取模块ID
UINT8 ModuleAI::GetModuleId()
{
	return MODULE_ID_AI;
}

//获取模块名字
TStr ModuleAI::GetModuleName()
{
	return "AI";
}

//初始化
bool ModuleAI::Initialize()
{

	return true;
}

//结束退出
void ModuleAI::Finalize()
{

}


//毫秒级Tick回调
void ModuleAI::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleAI::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleAI::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleAI::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleAI::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleAI::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleAI::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleAI::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleAI::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleAI::OnPublish(const TStr& publishString)
{
	
}
