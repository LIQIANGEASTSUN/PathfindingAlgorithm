/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     SaidProxy.h
* Author:       甘业清
* Date:         2019/7/5
* Description:  聊天 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "SaidProxy.h"

struct SaidRegisterProxyT
{
    SaidRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("Said");
    }
};
static SaidRegisterProxyT SaidRegisterProxyInstance;

int SaidCarpProxy::CreateLoadRoom( INT64 hintId, SaidRpcCreateLoadRoomNotify& notify)
{
	return RpcCall(22,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int SaidCarpProxy::CreateLoadRoom( const string& hintStr, SaidRpcCreateLoadRoomNotify& notify)
{
	return RpcCall(22,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int SaidCarpProxy::MessageForward( INT64 hintId, SaidRpcMessageForwardNotify& notify)
{
	return RpcCall(22,2, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int SaidCarpProxy::MessageForward( const string& hintStr, SaidRpcMessageForwardNotify& notify)
{
	return RpcCall(22,2, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}


int SaidRandProxy::CreateLoadRoom( SaidRpcCreateLoadRoomNotify& notify)
{
	return RpcCall(22,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int SaidRandProxy::MessageForward( SaidRpcMessageForwardNotify& notify)
{
	return RpcCall(22,2, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}


int SaidRoundProxy::CreateLoadRoom( SaidRpcCreateLoadRoomNotify& notify)
{
	return RpcCall(22,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int SaidRoundProxy::MessageForward( SaidRpcMessageForwardNotify& notify)
{
	return RpcCall(22,2, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}


int SaidAppointProxy::CreateLoadRoom( const TStr& nodeName, SaidRpcCreateLoadRoomNotify& notify)
{
	return RpcCall(22,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int SaidAppointProxy::MessageForward( const TStr& nodeName, SaidRpcMessageForwardNotify& notify)
{
	return RpcCall(22,2, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}


int SaidConsistencyProxy::CreateLoadRoom( SaidRpcCreateLoadRoomNotify& notify)
{
	return RpcCall(22,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int SaidConsistencyProxy::MessageForward( SaidRpcMessageForwardNotify& notify)
{
	return RpcCall(22,2, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}


