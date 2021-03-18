/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleFResult.cpp
* Author:       甘业清
* Description:  战斗结果演算类，包含以下内容
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

#include "ModuleFResult.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleFResult);

//战斗结果演算实现类构造函数
ModuleFResult::ModuleFResult()
{

	RpcImpInfoT Imp;
	Imp.Name = "FResult";
	Imp.Code = 29;
	Imp.RegisterCallback( 1, this, &ModuleFResult::SvrRpcCalculationFResult);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//战斗结果演算实现类析构函数
ModuleFResult::~ModuleFResult()
{

}


//获取模块ID
UINT8 ModuleFResult::GetModuleId()
{
	return MODULE_ID_FRESULT;
}

//获取模块名字
TStr ModuleFResult::GetModuleName()
{
	return "FResult";
}

//初始化
bool ModuleFResult::Initialize()
{

	return true;
}

//结束退出
void ModuleFResult::Finalize()
{

}


//毫秒级Tick回调
void ModuleFResult::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleFResult::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleFResult::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleFResult::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleFResult::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleFResult::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleFResult::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleFResult::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleFResult::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleFResult::OnPublish(const TStr& publishString)
{
	
}
