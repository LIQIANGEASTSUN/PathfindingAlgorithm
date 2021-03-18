/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleSkillHsmConfig.cpp
* Author:       甘业清
* Description:  技能层次状态机数据类，包含以下内容
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

#include "ModuleSkillHsmConfig.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleSkillHsmConfig);

//技能层次状态机数据实现类构造函数
ModuleSkillHsmConfig::ModuleSkillHsmConfig()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleSkillHsmConfig::CliRpcSync);

	RpcImpInfoT Imp;
	Imp.Name = "SkillHsmConfig";
	Imp.Code = 30;

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//技能层次状态机数据实现类析构函数
ModuleSkillHsmConfig::~ModuleSkillHsmConfig()
{

}


//获取模块ID
UINT8 ModuleSkillHsmConfig::GetModuleId()
{
	return MODULE_ID_SKILLHSMCONFIG;
}

//获取模块名字
TStr ModuleSkillHsmConfig::GetModuleName()
{
	return "SkillHsmConfig";
}

//初始化
bool ModuleSkillHsmConfig::Initialize()
{

	return true;
}

//结束退出
void ModuleSkillHsmConfig::Finalize()
{

}


//毫秒级Tick回调
void ModuleSkillHsmConfig::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleSkillHsmConfig::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleSkillHsmConfig::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleSkillHsmConfig::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleSkillHsmConfig::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleSkillHsmConfig::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleSkillHsmConfig::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleSkillHsmConfig::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleSkillHsmConfig::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleSkillHsmConfig::OnPublish(const TStr& publishString)
{
	
}
