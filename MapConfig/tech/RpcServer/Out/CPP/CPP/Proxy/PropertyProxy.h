#ifndef __PROPERTY_PROXY_H
#define __PROPERTY_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "PropertySvrRpc.pb.h"

//用户属性一致性调用代理类
class PropertyCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Property"; }
	
	//增加经验调用
	int AddExp( INT64 hintId, PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply);
	int AddExp( const string& hintStr, PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply);

};

//用户属性随机调用代理类
class PropertyRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Property"; }
	
	//增加经验调用
	int AddExp( PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply);

};

//用户属性轮询调用代理类
class PropertyRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Property"; }
	
	//增加经验调用
	int AddExp( PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply);

};

//用户属性指定调用代理类
class PropertyAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Property"; }
	
	//增加经验调用
	int AddExp( const TStr& nodeName, PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply);

};


//用户属性全部调用代理类
class PropertyConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Property"; }
	
	//增加经验调用
	int AddExp( PropertyRpcAddExpAsk& ask, PropertyRpcAddExpReply& reply);

};


#endif//__PROPERTY_PROXY_H

