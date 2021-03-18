/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     LogProxy.h
* Author:       甘业清
* Date:         2020/3/18
* Description:  日志服务 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "LogProxy.h"

struct LogRegisterProxyT
{
    LogRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("Log");
    }
};
static LogRegisterProxyT LogRegisterProxyInstance;

int LogCarpProxy::Save( INT64 hintId, LogRpcSaveNotify& notify)
{
	return RpcCall(24,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int LogCarpProxy::Save( const string& hintStr, LogRpcSaveNotify& notify)
{
	return RpcCall(24,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}


int LogRandProxy::Save( LogRpcSaveNotify& notify)
{
	return RpcCall(24,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}


int LogRoundProxy::Save( LogRpcSaveNotify& notify)
{
	return RpcCall(24,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}


int LogAppointProxy::Save( const TStr& nodeName, LogRpcSaveNotify& notify)
{
	return RpcCall(24,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}


int LogConsistencyProxy::Save( LogRpcSaveNotify& notify)
{
	return RpcCall(24,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}


