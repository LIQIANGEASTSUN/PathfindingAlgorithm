#ifndef __FRESULT_PROXY_H
#define __FRESULT_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "FResultSvrRpc.pb.h"

//战斗结果演算一致性调用代理类
class FResultCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "FResult"; }
	
	//计算战斗结果调用
	int CalculationFResult( INT64 hintId, FResultRpcCalculationFResultNotify& notify);
	int CalculationFResult( const string& hintStr, FResultRpcCalculationFResultNotify& notify);

};

//战斗结果演算随机调用代理类
class FResultRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "FResult"; }
	
	//计算战斗结果调用
	int CalculationFResult( FResultRpcCalculationFResultNotify& notify);

};

//战斗结果演算轮询调用代理类
class FResultRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "FResult"; }
	
	//计算战斗结果调用
	int CalculationFResult( FResultRpcCalculationFResultNotify& notify);

};

//战斗结果演算指定调用代理类
class FResultAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "FResult"; }
	
	//计算战斗结果调用
	int CalculationFResult( const TStr& nodeName, FResultRpcCalculationFResultNotify& notify);

};


//战斗结果演算全部调用代理类
class FResultConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "FResult"; }
	
	//计算战斗结果调用
	int CalculationFResult( FResultRpcCalculationFResultNotify& notify);

};


#endif//__FRESULT_PROXY_H

