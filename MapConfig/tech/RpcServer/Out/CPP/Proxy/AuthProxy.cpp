/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     AuthProxy.h
* Author:       甘业清
* Date:         2020/3/18
* Description:  认证服务 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "AuthProxy.h"

struct AuthRegisterProxyT
{
    AuthRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("Auth");
    }
};
static AuthRegisterProxyT AuthRegisterProxyInstance;

int AuthCarpProxy::Offline( INT64 hintId, AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply)
{
	return RpcCall(12,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int AuthCarpProxy::Offline( const string& hintStr, AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply)
{
	return RpcCall(12,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}


int AuthRandProxy::Offline( AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply)
{
	return RpcCall(12,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}


int AuthRoundProxy::Offline( AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply)
{
	return RpcCall(12,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}


int AuthAppointProxy::Offline( const TStr& nodeName, AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply)
{
	return RpcCall(12,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}


int AuthConsistencyProxy::Offline( AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply)
{
	return RpcCall(12,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}


