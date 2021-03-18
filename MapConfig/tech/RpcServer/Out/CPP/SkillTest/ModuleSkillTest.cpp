/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleSkillTest.cpp
* Author:       甘业清
* Description:  技能测试类，包含以下内容
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

#include "ModuleSkillTest.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleSkillTest);

//技能测试实现类构造函数
ModuleSkillTest::ModuleSkillTest()
{
	MsgIdMgr::Instance().MsgRegister( this, &ModuleSkillTest::CliRpcSync);

	RpcImpInfoT Imp;
	Imp.Name = "SkillTest";
	Imp.Code = 15;

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//技能测试实现类析构函数
ModuleSkillTest::~ModuleSkillTest()
{

}


//获取模块ID
UINT8 ModuleSkillTest::GetModuleId()
{
	return MODULE_ID_SKILLTEST;
}

//获取模块名字
TStr ModuleSkillTest::GetModuleName()
{
	return "SkillTest";
}

//初始化
bool ModuleSkillTest::Initialize()
{

	return true;
}

//结束退出
void ModuleSkillTest::Finalize()
{

}


//毫秒级Tick回调
void ModuleSkillTest::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleSkillTest::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleSkillTest::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleSkillTest::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleSkillTest::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleSkillTest::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleSkillTest::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleSkillTest::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleSkillTest::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleSkillTest::OnPublish(const TStr& publishString)
{
	
}
