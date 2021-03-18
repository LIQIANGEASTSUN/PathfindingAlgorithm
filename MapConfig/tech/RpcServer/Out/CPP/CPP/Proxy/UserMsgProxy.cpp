/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     UserMsgProxy.h
* Author:       甘业清
* Date:         2019/7/5
* Description:  GATE调用此RPC处理用户的请求 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "UserMsgProxy.h"

struct UserMsgRegisterProxyT
{
    UserMsgRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("UserMsg");
    }
};
static UserMsgRegisterProxyT UserMsgRegisterProxyInstance;

int UserMsgCarpProxy::Exec( INT64 hintId, UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply)
{
	return RpcCall(9,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int UserMsgCarpProxy::Exec( const string& hintStr, UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply)
{
	return RpcCall(9,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}


int UserMsgRandProxy::Exec( UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply)
{
	return RpcCall(9,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}


int UserMsgRoundProxy::Exec( UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply)
{
	return RpcCall(9,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}


int UserMsgAppointProxy::Exec( const TStr& nodeName, UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply)
{
	return RpcCall(9,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}


int UserMsgConsistencyProxy::Exec( UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply)
{
	return RpcCall(9,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}


