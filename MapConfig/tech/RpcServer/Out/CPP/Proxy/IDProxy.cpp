/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     IDProxy.h
* Author:       甘业清
* Date:         2020/3/18
* Description:  ID生成 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "IDProxy.h"

struct IDRegisterProxyT
{
    IDRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("ID");
    }
};
static IDRegisterProxyT IDRegisterProxyInstance;

int IDCarpProxy::ID( INT64 hintId, IDRpcIDAsk& ask, IDRpcIDReply& reply)
{
	return RpcCall(11,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int IDCarpProxy::ID( const string& hintStr, IDRpcIDAsk& ask, IDRpcIDReply& reply)
{
	return RpcCall(11,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}
int IDCarpProxy::AddUser( INT64 hintId, IDRpcAddUserNotify& notify)
{
	return RpcCall(11,2, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int IDCarpProxy::AddUser( const string& hintStr, IDRpcAddUserNotify& notify)
{
	return RpcCall(11,2, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}


int IDRandProxy::ID( IDRpcIDAsk& ask, IDRpcIDReply& reply)
{
	return RpcCall(11,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}
int IDRandProxy::AddUser( IDRpcAddUserNotify& notify)
{
	return RpcCall(11,2, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}


int IDRoundProxy::ID( IDRpcIDAsk& ask, IDRpcIDReply& reply)
{
	return RpcCall(11,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}
int IDRoundProxy::AddUser( IDRpcAddUserNotify& notify)
{
	return RpcCall(11,2, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}


int IDAppointProxy::ID( const TStr& nodeName, IDRpcIDAsk& ask, IDRpcIDReply& reply)
{
	return RpcCall(11,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}
int IDAppointProxy::AddUser( const TStr& nodeName, IDRpcAddUserNotify& notify)
{
	return RpcCall(11,2, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}


int IDConsistencyProxy::ID( IDRpcIDAsk& ask, IDRpcIDReply& reply)
{
	return RpcCall(11,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}
int IDConsistencyProxy::AddUser( IDRpcAddUserNotify& notify)
{
	return RpcCall(11,2, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}


