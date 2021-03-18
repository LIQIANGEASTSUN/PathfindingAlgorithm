/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     SkillConfigProxy.h
* Author:       甘业清
* Date:         2019/1/22/二
* Description:  技能配置 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "SkillConfigProxy.h"

struct SkillConfigRegisterProxyT
{
    SkillConfigRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("SkillConfig");
    }
};
static SkillConfigRegisterProxyT SkillConfigRegisterProxyInstance;

int SkillConfigCarpProxy::Sync( INT64 hintId, SkillConfigRpcSyncNotify& notify)
{
	return RpcCall(14,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int SkillConfigCarpProxy::Sync( const string& hintStr, SkillConfigRpcSyncNotify& notify)
{
	return RpcCall(14,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}


int SkillConfigRandProxy::Sync( SkillConfigRpcSyncNotify& notify)
{
	return RpcCall(14,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}


int SkillConfigRoundProxy::Sync( SkillConfigRpcSyncNotify& notify)
{
	return RpcCall(14,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}


int SkillConfigAppointProxy::Sync( const TStr& nodeName, SkillConfigRpcSyncNotify& notify)
{
	return RpcCall(14,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}


int SkillConfigConsistencyProxy::Sync( SkillConfigRpcSyncNotify& notify)
{
	return RpcCall(14,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}


