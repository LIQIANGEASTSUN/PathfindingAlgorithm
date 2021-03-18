/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     FResultProxy.h
* Author:       甘业清
* Date:         2020/3/18
* Description:  战斗结果演算 RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "FResultProxy.h"

struct FResultRegisterProxyT
{
    FResultRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("FResult");
    }
};
static FResultRegisterProxyT FResultRegisterProxyInstance;

int FResultCarpProxy::CalculationFResult( INT64 hintId, FResultRpcCalculationFResultNotify& notify)
{
	return RpcCall(29,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int FResultCarpProxy::CalculationFResult( const string& hintStr, FResultRpcCalculationFResultNotify& notify)
{
	return RpcCall(29,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}


int FResultRandProxy::CalculationFResult( FResultRpcCalculationFResultNotify& notify)
{
	return RpcCall(29,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}


int FResultRoundProxy::CalculationFResult( FResultRpcCalculationFResultNotify& notify)
{
	return RpcCall(29,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}


int FResultAppointProxy::CalculationFResult( const TStr& nodeName, FResultRpcCalculationFResultNotify& notify)
{
	return RpcCall(29,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}


int FResultConsistencyProxy::CalculationFResult( FResultRpcCalculationFResultNotify& notify)
{
	return RpcCall(29,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}


