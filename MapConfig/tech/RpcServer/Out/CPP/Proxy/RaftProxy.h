#ifndef __RAFT_PROXY_H
#define __RAFT_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "RaftSvrRpc.pb.h"

//raft消息一致性调用代理类
class RaftCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Raft"; }
	
	//投票调用
	int Vote( INT64 hintId, RaftRpcVoteNotify& notify);
	int Vote( const string& hintStr, RaftRpcVoteNotify& notify);
	//心跳调用
	int Tick( INT64 hintId, RaftRpcTickNotify& notify);
	int Tick( const string& hintStr, RaftRpcTickNotify& notify);
	//同步日志调用
	int SyncLog( INT64 hintId, RaftRpcSyncLogNotify& notify);
	int SyncLog( const string& hintStr, RaftRpcSyncLogNotify& notify);

};

//raft消息随机调用代理类
class RaftRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Raft"; }
	
	//投票调用
	int Vote( RaftRpcVoteNotify& notify);
	//心跳调用
	int Tick( RaftRpcTickNotify& notify);
	//同步日志调用
	int SyncLog( RaftRpcSyncLogNotify& notify);

};

//raft消息轮询调用代理类
class RaftRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Raft"; }
	
	//投票调用
	int Vote( RaftRpcVoteNotify& notify);
	//心跳调用
	int Tick( RaftRpcTickNotify& notify);
	//同步日志调用
	int SyncLog( RaftRpcSyncLogNotify& notify);

};

//raft消息指定调用代理类
class RaftAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Raft"; }
	
	//投票调用
	int Vote( const TStr& nodeName, RaftRpcVoteNotify& notify);
	//心跳调用
	int Tick( const TStr& nodeName, RaftRpcTickNotify& notify);
	//同步日志调用
	int SyncLog( const TStr& nodeName, RaftRpcSyncLogNotify& notify);

};


//raft消息全部调用代理类
class RaftConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Raft"; }
	
	//投票调用
	int Vote( RaftRpcVoteNotify& notify);
	//心跳调用
	int Tick( RaftRpcTickNotify& notify);
	//同步日志调用
	int SyncLog( RaftRpcSyncLogNotify& notify);

};


#endif//__RAFT_PROXY_H

