/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     MatchSPVPProxy.h
* Author:       甘业清
* Date:         2019/7/5
* Description:  匹配 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "MatchSPVPProxy.h"

struct MatchSPVPRegisterProxyT
{
    MatchSPVPRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("MatchSPVP");
    }
};
static MatchSPVPRegisterProxyT MatchSPVPRegisterProxyInstance;

int MatchSPVPCarpProxy::BattleNum( INT64 hintId, MatchSPVPRpcBattleNumNotify& notify)
{
	return RpcCall(21,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int MatchSPVPCarpProxy::BattleNum( const string& hintStr, MatchSPVPRpcBattleNumNotify& notify)
{
	return RpcCall(21,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}


int MatchSPVPRandProxy::BattleNum( MatchSPVPRpcBattleNumNotify& notify)
{
	return RpcCall(21,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}


int MatchSPVPRoundProxy::BattleNum( MatchSPVPRpcBattleNumNotify& notify)
{
	return RpcCall(21,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}


int MatchSPVPAppointProxy::BattleNum( const TStr& nodeName, MatchSPVPRpcBattleNumNotify& notify)
{
	return RpcCall(21,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}


int MatchSPVPConsistencyProxy::BattleNum( MatchSPVPRpcBattleNumNotify& notify)
{
	return RpcCall(21,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}


