/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleSkillConfig.cpp
* Author:       甘业清
* Description:  技能配置类，包含以下内容
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

#include "ModuleSkillConfig.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleSkillConfig);

//技能配置实现类构造函数
ModuleSkillConfig::ModuleSkillConfig()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleSkillConfig::CliRpcsync);

	RpcImpInfoT Imp;
	Imp.Name = "SkillConfig";
	Imp.Code = 17;

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//技能配置实现类析构函数
ModuleSkillConfig::~ModuleSkillConfig()
{

}


//获取模块ID
UINT8 ModuleSkillConfig::GetModuleId()
{
	return MODULE_ID_SKILLCONFIG;
}

//获取模块名字
TStr ModuleSkillConfig::GetModuleName()
{
	return "SkillConfig";
}

//初始化
bool ModuleSkillConfig::Initialize()
{

	return true;
}

//结束退出
void ModuleSkillConfig::Finalize()
{

}


//毫秒级Tick回调
void ModuleSkillConfig::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleSkillConfig::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleSkillConfig::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleSkillConfig::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleSkillConfig::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleSkillConfig::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleSkillConfig::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleSkillConfig::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleSkillConfig::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleSkillConfig::OnPublish(const TStr& publishString)
{
	
}
