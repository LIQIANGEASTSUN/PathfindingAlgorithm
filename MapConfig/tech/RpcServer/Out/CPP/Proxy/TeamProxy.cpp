/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     TeamProxy.h
* Author:       甘业清
* Date:         2020/3/18
* Description:  组队 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "TeamProxy.h"

struct TeamRegisterProxyT
{
    TeamRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("Team");
    }
};
static TeamRegisterProxyT TeamRegisterProxyInstance;

int TeamCarpProxy::GetTeam( INT64 hintId, TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply)
{
	return RpcCall(28,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int TeamCarpProxy::GetTeam( const string& hintStr, TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply)
{
	return RpcCall(28,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}
int TeamCarpProxy::TeamOver( INT64 hintId, TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply)
{
	return RpcCall(28,2, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int TeamCarpProxy::TeamOver( const string& hintStr, TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply)
{
	return RpcCall(28,2, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}


int TeamRandProxy::GetTeam( TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply)
{
	return RpcCall(28,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}
int TeamRandProxy::TeamOver( TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply)
{
	return RpcCall(28,2, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}


int TeamRoundProxy::GetTeam( TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply)
{
	return RpcCall(28,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}
int TeamRoundProxy::TeamOver( TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply)
{
	return RpcCall(28,2, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}


int TeamAppointProxy::GetTeam( const TStr& nodeName, TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply)
{
	return RpcCall(28,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}
int TeamAppointProxy::TeamOver( const TStr& nodeName, TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply)
{
	return RpcCall(28,2, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}


int TeamConsistencyProxy::GetTeam( TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply)
{
	return RpcCall(28,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}
int TeamConsistencyProxy::TeamOver( TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply)
{
	return RpcCall(28,2, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}


