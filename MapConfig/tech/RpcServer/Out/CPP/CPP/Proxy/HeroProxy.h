#ifndef __HERO_PROXY_H
#define __HERO_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "HeroSvrRpc.pb.h"

//英雄一致性调用代理类
class HeroCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Hero"; }
	
	//检测是不是有这个英雄调用
	int CheckHeroID( INT64 hintId, HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply);
	int CheckHeroID( const string& hintStr, HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply);

};

//英雄随机调用代理类
class HeroRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Hero"; }
	
	//检测是不是有这个英雄调用
	int CheckHeroID( HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply);

};

//英雄轮询调用代理类
class HeroRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Hero"; }
	
	//检测是不是有这个英雄调用
	int CheckHeroID( HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply);

};

//英雄指定调用代理类
class HeroAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Hero"; }
	
	//检测是不是有这个英雄调用
	int CheckHeroID( const TStr& nodeName, HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply);

};


//英雄全部调用代理类
class HeroConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Hero"; }
	
	//检测是不是有这个英雄调用
	int CheckHeroID( HeroRpcCheckHeroIDAsk& ask, HeroRpcCheckHeroIDReply& reply);

};


#endif//__HERO_PROXY_H

