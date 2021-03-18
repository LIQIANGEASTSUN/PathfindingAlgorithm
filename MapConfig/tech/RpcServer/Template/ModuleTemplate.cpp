/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     Module$Template$.cpp
* Author:       甘业清
* Description:  $ModCName$类，包含以下内容
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

#include "Module$Template$.h"

#ifdef WIN32
#ifdef _DEBUG
#pragma comment(lib,"../MOM/logic.lib")
#endif
#endif


IMPLEMENT_INSTANCE(Module$Template$);

//$ModCName$实现类构造函数
Module$Template$::Module$Template$()
{
$CliOperationImpl$
	RpcImpInfoT Imp;
	Imp.Name = "$Template$";
	Imp.Code = $TemplateCode$;
$ImplementRegister$
	RpcCenter::Instance().RegisterRpcImplement(Imp);
}

//$ModCName$实现类析构函数
Module$Template$::~Module$Template$()
{

}


//获取模块ID
UINT8 Module$Template$::GetModuleId()
{
	return MODULE_ID_$TEMPLATE$;
}

//获取模块名字
TStr Module$Template$::GetModuleName()
{
	return "$Template$";
}

//初始化
bool Module$Template$::Initialize()
{

	return true;
}

//结束退出
void Module$Template$::Finalize()
{

}


//毫秒级Tick回调
void Module$Template$::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void Module$Template$::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void Module$Template$::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void Module$Template$::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void Module$Template$::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void Module$Template$::OnUserCreate( INT64 uid, const TStr& userName )
{

}

//用户上线回调
void Module$Template$::OnUserOnline( INT64 uid, time_t lastLogoutTime )
{

}

//用户下线回调
void Module$Template$::OnUserOffline( INT64 uid )
{

}

//配置表更新
void Module$Template$::OnConfigReload(const TStr& tableName)
{

}

//有发布信息
void Module$Template$::OnPublish(const TStr& publishString)
{
	
}
