/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     BattleSPVPProxy.h
* Author:       甘业清
* Date:         2020/3/18
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
int BattleSPVPCarpProxy::ConnectAIService( INT64 hintId, BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply)
{
	return RpcCall(23,2, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int BattleSPVPCarpProxy::ConnectAIService( const string& hintStr, BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply)
{
	return RpcCall(23,2, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}
int BattleSPVPCarpProxy::AINoticeOper( INT64 hintId, BattleSPVPRpcAINoticeOperNotify& notify)
{
	return RpcCall(23,3, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int BattleSPVPCarpProxy::AINoticeOper( const string& hintStr, BattleSPVPRpcAINoticeOperNotify& notify)
{
	return RpcCall(23,3, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}


int BattleSPVPRandProxy::CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply)
{
	return RpcCall(23,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}
int BattleSPVPRandProxy::ConnectAIService( BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply)
{
	return RpcCall(23,2, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}
int BattleSPVPRandProxy::AINoticeOper( BattleSPVPRpcAINoticeOperNotify& notify)
{
	return RpcCall(23,3, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}


int BattleSPVPRoundProxy::CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply)
{
	return RpcCall(23,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}
int BattleSPVPRoundProxy::ConnectAIService( BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply)
{
	return RpcCall(23,2, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}
int BattleSPVPRoundProxy::AINoticeOper( BattleSPVPRpcAINoticeOperNotify& notify)
{
	return RpcCall(23,3, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}


int BattleSPVPAppointProxy::CreateRoomSPVP( const TStr& nodeName, BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply)
{
	return RpcCall(23,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}
int BattleSPVPAppointProxy::ConnectAIService( const TStr& nodeName, BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply)
{
	return RpcCall(23,2, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}
int BattleSPVPAppointProxy::AINoticeOper( const TStr& nodeName, BattleSPVPRpcAINoticeOperNotify& notify)
{
	return RpcCall(23,3, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}


int BattleSPVPConsistencyProxy::CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply)
{
	return RpcCall(23,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}
int BattleSPVPConsistencyProxy::ConnectAIService( BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply)
{
	return RpcCall(23,2, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}
int BattleSPVPConsistencyProxy::AINoticeOper( BattleSPVPRpcAINoticeOperNotify& notify)
{
	return RpcCall(23,3, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}


