/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     RaftProxy.h
* Author:       甘业清
* Date:         2019/7/5
* Description:  raft消息 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "RaftProxy.h"

struct RaftRegisterProxyT
{
    RaftRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("Raft");
    }
};
static RaftRegisterProxyT RaftRegisterProxyInstance;

int RaftCarpProxy::Vote( INT64 hintId, RaftRpcVoteNotify& notify)
{
	return RpcCall(18,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int RaftCarpProxy::Vote( const string& hintStr, RaftRpcVoteNotify& notify)
{
	return RpcCall(18,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int RaftCarpProxy::Tick( INT64 hintId, RaftRpcTickNotify& notify)
{
	return RpcCall(18,2, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int RaftCarpProxy::Tick( const string& hintStr, RaftRpcTickNotify& notify)
{
	return RpcCall(18,2, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int RaftCarpProxy::SyncLog( INT64 hintId, RaftRpcSyncLogNotify& notify)
{
	return RpcCall(18,3, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int RaftCarpProxy::SyncLog( const string& hintStr, RaftRpcSyncLogNotify& notify)
{
	return RpcCall(18,3, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}


int RaftRandProxy::Vote( RaftRpcVoteNotify& notify)
{
	return RpcCall(18,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int RaftRandProxy::Tick( RaftRpcTickNotify& notify)
{
	return RpcCall(18,2, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int RaftRandProxy::SyncLog( RaftRpcSyncLogNotify& notify)
{
	return RpcCall(18,3, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}


int RaftRoundProxy::Vote( RaftRpcVoteNotify& notify)
{
	return RpcCall(18,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int RaftRoundProxy::Tick( RaftRpcTickNotify& notify)
{
	return RpcCall(18,2, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int RaftRoundProxy::SyncLog( RaftRpcSyncLogNotify& notify)
{
	return RpcCall(18,3, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}


int RaftAppointProxy::Vote( const TStr& nodeName, RaftRpcVoteNotify& notify)
{
	return RpcCall(18,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int RaftAppointProxy::Tick( const TStr& nodeName, RaftRpcTickNotify& notify)
{
	return RpcCall(18,2, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int RaftAppointProxy::SyncLog( const TStr& nodeName, RaftRpcSyncLogNotify& notify)
{
	return RpcCall(18,3, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}


int RaftConsistencyProxy::Vote( RaftRpcVoteNotify& notify)
{
	return RpcCall(18,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int RaftConsistencyProxy::Tick( RaftRpcTickNotify& notify)
{
	return RpcCall(18,2, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int RaftConsistencyProxy::SyncLog( RaftRpcSyncLogNotify& notify)
{
	return RpcCall(18,3, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}


