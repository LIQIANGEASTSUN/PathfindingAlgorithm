#ifndef __AUTH_PROXY_H
#define __AUTH_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "AuthSvrRpc.pb.h"

//认证服务一致性调用代理类
class AuthCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Auth"; }
	
	//用户下线调用
	int Offline( INT64 hintId, AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply);
	int Offline( const string& hintStr, AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply);

};

//认证服务随机调用代理类
class AuthRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Auth"; }
	
	//用户下线调用
	int Offline( AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply);

};

//认证服务轮询调用代理类
class AuthRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Auth"; }
	
	//用户下线调用
	int Offline( AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply);

};

//认证服务指定调用代理类
class AuthAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Auth"; }
	
	//用户下线调用
	int Offline( const TStr& nodeName, AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply);

};


//认证服务全部调用代理类
class AuthConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Auth"; }
	
	//用户下线调用
	int Offline( AuthRpcOfflineAsk& ask, AuthRpcOfflineReply& reply);

};


#endif//__AUTH_PROXY_H

