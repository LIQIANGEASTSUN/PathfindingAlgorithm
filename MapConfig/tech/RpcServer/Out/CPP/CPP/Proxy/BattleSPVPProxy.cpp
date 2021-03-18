/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     BattleSPVPProxy.h
* Author:       甘业清
* Date:         2019/7/5
* Description:  战斗同步 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "BattleSPVPProxy.h"

struct BattleSPVPRegisterProxyT
{
    BattleSPVPRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("BattleSPVP");
    }
};
static BattleSPVPRegisterProxyT BattleSPVPRegisterProxyInstance;

int BattleSPVPCarpProxy::CreateRoomSPVP( INT64 hintId, BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply)
{
	return RpcCall(23,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int BattleSPVPCarpProxy::CreateRoomSPVP( const string& hintStr, BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply)
{
	return RpcCall(23,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}


int BattleSPVPRandProxy::CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply)
{
	return RpcCall(23,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}


int BattleSPVPRoundProxy::CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply)
{
	return RpcCall(23,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}


int BattleSPVPAppointProxy::CreateRoomSPVP( const TStr& nodeName, BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply)
{
	return RpcCall(23,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}


int BattleSPVPConsistencyProxy::CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply)
{
	return RpcCall(23,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}


