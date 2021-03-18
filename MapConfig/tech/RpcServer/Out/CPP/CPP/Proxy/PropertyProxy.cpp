/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     PropertyProxy.h
* Author:       甘业清
* Date:         2019/7/5
* Description:  用户属性 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "PropertyProxy.h"

struct PropertyRegisterProxyT
{
    PropertyRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("Property");
    }
};
static PropertyRegisterProxyT PropertyRegisterProxyInstance;

int PropertyCarpProxy::AddExp( INT64 hintId, PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply)
{
	return RpcCall(13,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int PropertyCarpProxy::AddExp( const string& hintStr, PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply)
{
	return RpcCall(13,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}


int PropertyRandProxy::AddExp( PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply)
{
	return RpcCall(13,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}


int PropertyRoundProxy::AddExp( PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply)
{
	return RpcCall(13,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}


int PropertyAppointProxy::AddExp( const TStr& nodeName, PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply)
{
	return RpcCall(13,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}


int PropertyConsistencyProxy::AddExp( PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply)
{
	return RpcCall(13,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}


