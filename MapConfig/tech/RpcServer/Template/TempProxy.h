#ifndef __$TEMPLATE$_PROXY_H
#define __$TEMPLATE$_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "$Template$SvrRpc.pb.h"

//$ModCName$一致性调用代理类
class $Template$CarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "$Template$"; }
	
$CarpProxyDeclare$
};

//$ModCName$随机调用代理类
class $Template$RandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "$Template$"; }
	
$RandProxyDeclare$
};

//$ModCName$轮询调用代理类
class $Template$RoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "$Template$"; }
	
$RoundProxyDeclare$
};

//$ModCName$指定调用代理类
class $Template$AppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "$Template$"; }
	
$AppointProxyDeclare$
};


//$ModCName$全部调用代理类
class $Template$ConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "$Template$"; }
	
$ConsistencyProxyDeclare$
};


#endif//__$TEMPLATE$_PROXY_H

