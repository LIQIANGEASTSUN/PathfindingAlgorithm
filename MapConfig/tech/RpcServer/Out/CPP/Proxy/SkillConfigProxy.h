#ifndef __SKILLCONFIG_PROXY_H
#define __SKILLCONFIG_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "SkillConfigSvrRpc.pb.h"

//技能配置一致性调用代理类
class SkillConfigCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "SkillConfig"; }
	
	//Sync调用
	int Sync( INT64 hintId, SkillConfigRpcSyncNotify& notify);
	int Sync( const string& hintStr, SkillConfigRpcSyncNotify& notify);

};

//技能配置随机调用代理类
class SkillConfigRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "SkillConfig"; }
	
	//Sync调用
	int Sync( SkillConfigRpcSyncNotify& notify);

};

//技能配置轮询调用代理类
class SkillConfigRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "SkillConfig"; }
	
	//Sync调用
	int Sync( SkillConfigRpcSyncNotify& notify);

};

//技能配置指定调用代理类
class SkillConfigAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "SkillConfig"; }
	
	//Sync调用
	int Sync( const TStr& nodeName, SkillConfigRpcSyncNotify& notify);

};


//技能配置全部调用代理类
class SkillConfigConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "SkillConfig"; }
	
	//Sync调用
	int Sync( SkillConfigRpcSyncNotify& notify);

};


#endif//__SKILLCONFIG_PROXY_H

