/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleSkillHsmConfig.h
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

#ifndef __MODULE_SKILLHSMCONFIG_H
#define __MODULE_SKILLHSMCONFIG_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "SkillHsmConfigCliRpc.pb.h"



//技能层次状态机数据实现类
class ModuleSkillHsmConfig : public ModuleBase
{
	DECLARE_INSTANCE(ModuleSkillHsmConfig);
public:
	friend class			ModuleMgr;

public:
	//技能层次状态机数据实现类构造函数
	ModuleSkillHsmConfig();
	
	//技能层次状态机数据实现类析构函数
	virtual					~ModuleSkillHsmConfig();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 uid, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 uid, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 uid );
	
	//配置表更新
	virtual void			OnConfigReload(const TStr& tableName);
	
	//有发布信息
	virtual void			OnPublish(const TStr& publishString);

public:
	/********************************************************************************************
	* Function:       CliRpcSync
	* Description:    技能层次状态机数据-->Sync异步通知操作函数
	* Input:          SkillHsmConfigRpcSyncNotify& Notify Sync通知
	* Output:         无
	********************************************************************************************/
	void CliRpcSync( clientInfoT& clientInfo, SkillHsmConfigRpcSyncNotify& Notify );



public:


};

//技能层次状态机数据类的枚举定义
enum ConstSkillHsmConfigE
{
	MODULE_ID_SKILLHSMCONFIG                     = 30,	//技能层次状态机数据模块ID
	RPC_CODE_SKILLHSMCONFIG_SYNC_NOTIFY          = 3051,	//技能层次状态机数据-->Sync-->通知


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<SkillHsmConfigRpcSyncNotify>{ enum{ID=RPC_CODE_SKILLHSMCONFIG_SYNC_NOTIFY};};


#endif