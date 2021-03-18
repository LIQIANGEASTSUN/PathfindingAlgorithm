/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     GateProxy.h
* Author:       甘业清
* Date:         2019/7/5
* Description:  接入服务 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "GateProxy.h"

struct GateRegisterProxyT
{
    GateRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("Gate");
    }
};
static GateRegisterProxyT GateRegisterProxyInstance;

int GateCarpProxy::SendMsg( INT64 hintId, GateRpcSendMsgNotify& notify)
{
	return RpcCall(8,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int GateCarpProxy::SendMsg( const string& hintStr, GateRpcSendMsgNotify& notify)
{
	return RpcCall(8,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int GateCarpProxy::BroadcastMsg( INT64 hintId, GateRpcBroadcastMsgNotify& notify)
{
	return RpcCall(8,2, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int GateCarpProxy::BroadcastMsg( const string& hintStr, GateRpcBroadcastMsgNotify& notify)
{
	return RpcCall(8,2, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int GateCarpProxy::CloseNode( INT64 hintId, GateRpcCloseNodeNotify& notify)
{
	return RpcCall(8,3, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int GateCarpProxy::CloseNode( const string& hintStr, GateRpcCloseNodeNotify& notify)
{
	return RpcCall(8,3, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int GateCarpProxy::RegisterModule( INT64 hintId, GateRpcRegisterModuleNotify& notify)
{
	return RpcCall(8,4, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int GateCarpProxy::RegisterModule( const string& hintStr, GateRpcRegisterModuleNotify& notify)
{
	return RpcCall(8,4, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int GateCarpProxy::Kick( INT64 hintId, GateRpcKickNotify& notify)
{
	return RpcCall(8,5, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int GateCarpProxy::Kick( const string& hintStr, GateRpcKickNotify& notify)
{
	return RpcCall(8,5, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int GateCarpProxy::Online( INT64 hintId, GateRpcOnlineNotify& notify)
{
	return RpcCall(8,6, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int GateCarpProxy::Online( const string& hintStr, GateRpcOnlineNotify& notify)
{
	return RpcCall(8,6, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}


int GateRandProxy::SendMsg( GateRpcSendMsgNotify& notify)
{
	return RpcCall(8,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int GateRandProxy::BroadcastMsg( GateRpcBroadcastMsgNotify& notify)
{
	return RpcCall(8,2, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int GateRandProxy::CloseNode( GateRpcCloseNodeNotify& notify)
{
	return RpcCall(8,3, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int GateRandProxy::RegisterModule( GateRpcRegisterModuleNotify& notify)
{
	return RpcCall(8,4, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int GateRandProxy::Kick( GateRpcKickNotify& notify)
{
	return RpcCall(8,5, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int GateRandProxy::Online( GateRpcOnlineNotify& notify)
{
	return RpcCall(8,6, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}


int GateRoundProxy::SendMsg( GateRpcSendMsgNotify& notify)
{
	return RpcCall(8,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int GateRoundProxy::BroadcastMsg( GateRpcBroadcastMsgNotify& notify)
{
	return RpcCall(8,2, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int GateRoundProxy::CloseNode( GateRpcCloseNodeNotify& notify)
{
	return RpcCall(8,3, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int GateRoundProxy::RegisterModule( GateRpcRegisterModuleNotify& notify)
{
	return RpcCall(8,4, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int GateRoundProxy::Kick( GateRpcKickNotify& notify)
{
	return RpcCall(8,5, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int GateRoundProxy::Online( GateRpcOnlineNotify& notify)
{
	return RpcCall(8,6, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}


int GateAppointProxy::SendMsg( const TStr& nodeName, GateRpcSendMsgNotify& notify)
{
	return RpcCall(8,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int GateAppointProxy::BroadcastMsg( const TStr& nodeName, GateRpcBroadcastMsgNotify& notify)
{
	return RpcCall(8,2, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int GateAppointProxy::CloseNode( const TStr& nodeName, GateRpcCloseNodeNotify& notify)
{
	return RpcCall(8,3, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int GateAppointProxy::RegisterModule( const TStr& nodeName, GateRpcRegisterModuleNotify& notify)
{
	return RpcCall(8,4, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int GateAppointProxy::Kick( const TStr& nodeName, GateRpcKickNotify& notify)
{
	return RpcCall(8,5, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int GateAppointProxy::Online( const TStr& nodeName, GateRpcOnlineNotify& notify)
{
	return RpcCall(8,6, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}


int GateConsistencyProxy::SendMsg( GateRpcSendMsgNotify& notify)
{
	return RpcCall(8,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int GateConsistencyProxy::BroadcastMsg( GateRpcBroadcastMsgNotify& notify)
{
	return RpcCall(8,2, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int GateConsistencyProxy::CloseNode( GateRpcCloseNodeNotify& notify)
{
	return RpcCall(8,3, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int GateConsistencyProxy::RegisterModule( GateRpcRegisterModuleNotify& notify)
{
	return RpcCall(8,4, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int GateConsistencyProxy::Kick( GateRpcKickNotify& notify)
{
	return RpcCall(8,5, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int GateConsistencyProxy::Online( GateRpcOnlineNotify& notify)
{
	return RpcCall(8,6, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}


