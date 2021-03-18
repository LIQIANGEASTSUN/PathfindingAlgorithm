#ifndef __MYSQLSHARDING_PROXY_H
#define __MYSQLSHARDING_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "MysqlShardingSvrRpc.pb.h"

//MYSQL分片代理一致性调用代理类
class MysqlShardingCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "MysqlSharding"; }
	
	//获取表信息调用
	int GetTableInfo( INT64 hintId, MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply);
	int GetTableInfo( const string& hintStr, MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply);
	//执行SQL语句调用
	int Execute( INT64 hintId, MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply);
	int Execute( const string& hintStr, MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply);
	//执行事务调用
	int Transaction( INT64 hintId, MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply);
	int Transaction( const string& hintStr, MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply);

};

//MYSQL分片代理随机调用代理类
class MysqlShardingRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "MysqlSharding"; }
	
	//获取表信息调用
	int GetTableInfo( MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply);
	//执行SQL语句调用
	int Execute( MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply);
	//执行事务调用
	int Transaction( MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply);

};

//MYSQL分片代理轮询调用代理类
class MysqlShardingRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "MysqlSharding"; }
	
	//获取表信息调用
	int GetTableInfo( MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply);
	//执行SQL语句调用
	int Execute( MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply);
	//执行事务调用
	int Transaction( MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply);

};

//MYSQL分片代理指定调用代理类
class MysqlShardingAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "MysqlSharding"; }
	
	//获取表信息调用
	int GetTableInfo( const TStr& nodeName, MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply);
	//执行SQL语句调用
	int Execute( const TStr& nodeName, MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply);
	//执行事务调用
	int Transaction( const TStr& nodeName, MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply);

};


//MYSQL分片代理全部调用代理类
class MysqlShardingConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "MysqlSharding"; }
	
	//获取表信息调用
	int GetTableInfo( MysqlShardingRpcGetTableInfoAsk& ask, MysqlShardingRpcGetTableInfoReply& reply);
	//执行SQL语句调用
	int Execute( MysqlShardingRpcExecuteAsk& ask, MysqlShardingRpcExecuteReply& reply);
	//执行事务调用
	int Transaction( MysqlShardingRpcTransactionAsk& ask, MysqlShardingRpcTransactionReply& reply);

};


#endif//__MYSQLSHARDING_PROXY_H

