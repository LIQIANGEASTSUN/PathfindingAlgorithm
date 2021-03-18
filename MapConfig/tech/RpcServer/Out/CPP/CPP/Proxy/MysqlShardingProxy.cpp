/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     MysqlShardingProxy.h
* Author:       甘业清
* Date:         2019/7/5
* Description:  MYSQL分片代理 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "MysqlShardingProxy.h"

struct MysqlShardingRegisterProxyT
{
    MysqlShardingRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("MysqlSharding");
    }
};
static MysqlShardingRegisterProxyT MysqlShardingRegisterProxyInstance;

int MysqlShardingCarpProxy::GetTableInfo( INT64 hintId, MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply)
{
	return RpcCall(7,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int MysqlShardingCarpProxy::GetTableInfo( const string& hintStr, MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply)
{
	return RpcCall(7,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}
int MysqlShardingCarpProxy::Execute( INT64 hintId, MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply)
{
	return RpcCall(7,2, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int MysqlShardingCarpProxy::Execute( const string& hintStr, MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply)
{
	return RpcCall(7,2, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}
int MysqlShardingCarpProxy::Transaction( INT64 hintId, MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply)
{
	return RpcCall(7,3, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int MysqlShardingCarpProxy::Transaction( const string& hintStr, MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply)
{
	return RpcCall(7,3, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}


int MysqlShardingRandProxy::GetTableInfo( MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply)
{
	return RpcCall(7,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}
int MysqlShardingRandProxy::Execute( MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply)
{
	return RpcCall(7,2, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}
int MysqlShardingRandProxy::Transaction( MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply)
{
	return RpcCall(7,3, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}


int MysqlShardingRoundProxy::GetTableInfo( MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply)
{
	return RpcCall(7,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}
int MysqlShardingRoundProxy::Execute( MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply)
{
	return RpcCall(7,2, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}
int MysqlShardingRoundProxy::Transaction( MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply)
{
	return RpcCall(7,3, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}


int MysqlShardingAppointProxy::GetTableInfo( const TStr& nodeName, MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply)
{
	return RpcCall(7,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}
int MysqlShardingAppointProxy::Execute( const TStr& nodeName, MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply)
{
	return RpcCall(7,2, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}
int MysqlShardingAppointProxy::Transaction( const TStr& nodeName, MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply)
{
	return RpcCall(7,3, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}


int MysqlShardingConsistencyProxy::GetTableInfo( MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply)
{
	return RpcCall(7,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}
int MysqlShardingConsistencyProxy::Execute( MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply)
{
	return RpcCall(7,2, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}
int MysqlShardingConsistencyProxy::Transaction( MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply)
{
	return RpcCall(7,3, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}


