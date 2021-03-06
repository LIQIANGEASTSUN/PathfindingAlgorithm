/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMysqlSharding.cpp
* Author:       甘业清
* Description:  MYSQL分片代理类，包含以下内容
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

#include "ModuleMysqlSharding.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(ModuleMysqlSharding);

//MYSQL分片代理实现类构造函数
ModuleMysqlSharding::ModuleMysqlSharding()
{

	RpcImpInfoT Imp;
	Imp.Name = "MysqlSharding";
	Imp.Code = 7;
	Imp.RegisterCallback( 1, this, &ModuleMysqlSharding::SvrRpcGetTableInfo);
	Imp.RegisterCallback( 2, this, &ModuleMysqlSharding::SvrRpcExecute);
	Imp.RegisterCallback( 3, this, &ModuleMysqlSharding::SvrRpcTransaction);

	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//MYSQL分片代理实现类析构函数
ModuleMysqlSharding::~ModuleMysqlSharding()
{

}


//获取模块ID
UINT8 ModuleMysqlSharding::GetModuleId()
{
	return MODULE_ID_MYSQLSHARDING;
}

//获取模块名字
TStr ModuleMysqlSharding::GetModuleName()
{
	return "MysqlSharding";
}

//初始化
bool ModuleMysqlSharding::Initialize()
{

	return true;
}

//结束退出
void ModuleMysqlSharding::Finalize()
{

}


//毫秒级Tick回调
void ModuleMysqlSharding::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleMysqlSharding::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleMysqlSharding::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleMysqlSharding::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleMysqlSharding::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleMysqlSharding::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void ModuleMysqlSharding::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleMysqlSharding::OnUserOffline( INT64 uid )
{

}

//配置表更新
void ModuleMysqlSharding::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void ModuleMysqlSharding::OnPublish(const TStr& publishString)
{
	
}
