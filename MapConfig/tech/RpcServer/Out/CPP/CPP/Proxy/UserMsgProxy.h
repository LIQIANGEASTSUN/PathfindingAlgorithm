#ifndef __USERMSG_PROXY_H
#define __USERMSG_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "UserMsgSvrRpc.pb.h"

//GATE调用此RPC处理用户的请求一致性调用代理类
class UserMsgCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "UserMsg"; }
	
	//执行调用
	int Exec( INT64 hintId, UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply);
	int Exec( const string& hintStr, UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply);

};

//GATE调用此RPC处理用户的请求随机调用代理类
class UserMsgRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "UserMsg"; }
	
	//执行调用
	int Exec( UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply);

};

//GATE调用此RPC处理用户的请求轮询调用代理类
class UserMsgRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "UserMsg"; }
	
	//执行调用
	int Exec( UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply);

};

//GATE调用此RPC处理用户的请求指定调用代理类
class UserMsgAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "UserMsg"; }
	
	//执行调用
	int Exec( const TStr& nodeName, UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply);

};


//GATE调用此RPC处理用户的请求全部调用代理类
class UserMsgConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "UserMsg"; }
	
	//执行调用
	int Exec( UserMsgRpcExecAsk& ask, UserMsgRpcExecReply& reply);

};


#endif//__USERMSG_PROXY_H

