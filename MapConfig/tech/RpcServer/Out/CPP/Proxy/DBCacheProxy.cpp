/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     DBCacheProxy.h
* Author:       甘业清
* Date:         2020/3/18
* Description:  数据缓存服务器 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "DBCacheProxy.h"

struct DBCacheRegisterProxyT
{
    DBCacheRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("DBCache");
    }
};
static DBCacheRegisterProxyT DBCacheRegisterProxyInstance;

int DBCacheCarpProxy::Insert( INT64 hintId, DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply)
{
	return RpcCall(25,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int DBCacheCarpProxy::Insert( const string& hintStr, DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply)
{
	return RpcCall(25,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}
int DBCacheCarpProxy::Delete( INT64 hintId, DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply)
{
	return RpcCall(25,2, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int DBCacheCarpProxy::Delete( const string& hintStr, DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply)
{
	return RpcCall(25,2, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}
int DBCacheCarpProxy::Update( INT64 hintId, DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply)
{
	return RpcCall(25,3, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int DBCacheCarpProxy::Update( const string& hintStr, DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply)
{
	return RpcCall(25,3, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}
int DBCacheCarpProxy::Select( INT64 hintId, DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply)
{
	return RpcCall(25,4, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int DBCacheCarpProxy::Select( const string& hintStr, DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply)
{
	return RpcCall(25,4, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}


int DBCacheRandProxy::Insert( DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply)
{
	return RpcCall(25,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}
int DBCacheRandProxy::Delete( DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply)
{
	return RpcCall(25,2, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}
int DBCacheRandProxy::Update( DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply)
{
	return RpcCall(25,3, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}
int DBCacheRandProxy::Select( DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply)
{
	return RpcCall(25,4, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}


int DBCacheRoundProxy::Insert( DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply)
{
	return RpcCall(25,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}
int DBCacheRoundProxy::Delete( DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply)
{
	return RpcCall(25,2, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}
int DBCacheRoundProxy::Update( DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply)
{
	return RpcCall(25,3, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}
int DBCacheRoundProxy::Select( DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply)
{
	return RpcCall(25,4, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}


int DBCacheAppointProxy::Insert( const TStr& nodeName, DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply)
{
	return RpcCall(25,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}
int DBCacheAppointProxy::Delete( const TStr& nodeName, DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply)
{
	return RpcCall(25,2, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}
int DBCacheAppointProxy::Update( const TStr& nodeName, DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply)
{
	return RpcCall(25,3, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}
int DBCacheAppointProxy::Select( const TStr& nodeName, DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply)
{
	return RpcCall(25,4, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}


int DBCacheConsistencyProxy::Insert( DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply)
{
	return RpcCall(25,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}
int DBCacheConsistencyProxy::Delete( DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply)
{
	return RpcCall(25,2, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}
int DBCacheConsistencyProxy::Update( DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply)
{
	return RpcCall(25,3, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}
int DBCacheConsistencyProxy::Select( DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply)
{
	return RpcCall(25,4, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}


