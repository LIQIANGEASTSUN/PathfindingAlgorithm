/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     HeroProxy.h
* Author:       甘业清
* Date:         2019/7/5
* Description:  英雄 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "HeroProxy.h"

struct HeroRegisterProxyT
{
    HeroRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("Hero");
    }
};
static HeroRegisterProxyT HeroRegisterProxyInstance;

int HeroCarpProxy::CheckHeroID( INT64 hintId, HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply)
{
	return RpcCall(20,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int HeroCarpProxy::CheckHeroID( const string& hintStr, HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply)
{
	return RpcCall(20,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}


int HeroRandProxy::CheckHeroID( HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply)
{
	return RpcCall(20,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}


int HeroRoundProxy::CheckHeroID( HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply)
{
	return RpcCall(20,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}


int HeroAppointProxy::CheckHeroID( const TStr& nodeName, HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply)
{
	return RpcCall(20,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}


int HeroConsistencyProxy::CheckHeroID( HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply)
{
	return RpcCall(20,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}


