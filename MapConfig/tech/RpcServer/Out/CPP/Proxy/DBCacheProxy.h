#ifndef __DBCACHE_PROXY_H
#define __DBCACHE_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "DBCacheSvrRpc.pb.h"

//数据缓存服务器一致性调用代理类
class DBCacheCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "DBCache"; }
	
	//添加数据调用
	int Insert( INT64 hintId, DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply);
	int Insert( const string& hintStr, DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply);
	//删除数据调用
	int Delete( INT64 hintId, DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply);
	int Delete( const string& hintStr, DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply);
	//修改数据调用
	int Update( INT64 hintId, DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply);
	int Update( const string& hintStr, DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply);
	//查询数据调用
	int Select( INT64 hintId, DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply);
	int Select( const string& hintStr, DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply);

};

//数据缓存服务器随机调用代理类
class DBCacheRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "DBCache"; }
	
	//添加数据调用
	int Insert( DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply);
	//删除数据调用
	int Delete( DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply);
	//修改数据调用
	int Update( DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply);
	//查询数据调用
	int Select( DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply);

};

//数据缓存服务器轮询调用代理类
class DBCacheRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "DBCache"; }
	
	//添加数据调用
	int Insert( DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply);
	//删除数据调用
	int Delete( DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply);
	//修改数据调用
	int Update( DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply);
	//查询数据调用
	int Select( DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply);

};

//数据缓存服务器指定调用代理类
class DBCacheAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "DBCache"; }
	
	//添加数据调用
	int Insert( const TStr& nodeName, DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply);
	//删除数据调用
	int Delete( const TStr& nodeName, DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply);
	//修改数据调用
	int Update( const TStr& nodeName, DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply);
	//查询数据调用
	int Select( const TStr& nodeName, DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply);

};


//数据缓存服务器全部调用代理类
class DBCacheConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "DBCache"; }
	
	//添加数据调用
	int Insert( DBCacheRpcInsertAsk& ask, DBCacheRpcInsertReply& reply);
	//删除数据调用
	int Delete( DBCacheRpcDeleteAsk& ask, DBCacheRpcDeleteReply& reply);
	//修改数据调用
	int Update( DBCacheRpcUpdateAsk& ask, DBCacheRpcUpdateReply& reply);
	//查询数据调用
	int Select( DBCacheRpcSelectAsk& ask, DBCacheRpcSelectReply& reply);

};


#endif//__DBCACHE_PROXY_H

