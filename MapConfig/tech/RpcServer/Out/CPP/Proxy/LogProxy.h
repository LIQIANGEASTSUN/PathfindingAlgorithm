#ifndef __LOG_PROXY_H
#define __LOG_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "LogSvrRpc.pb.h"

//日志服务一致性调用代理类
class LogCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Log"; }
	
	//保存日志调用
	int Save( INT64 hintId, LogRpcSaveNotify& notify);
	int Save( const string& hintStr, LogRpcSaveNotify& notify);

};

//日志服务随机调用代理类
class LogRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Log"; }
	
	//保存日志调用
	int Save( LogRpcSaveNotify& notify);

};

//日志服务轮询调用代理类
class LogRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Log"; }
	
	//保存日志调用
	int Save( LogRpcSaveNotify& notify);

};

//日志服务指定调用代理类
class LogAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Log"; }
	
	//保存日志调用
	int Save( const TStr& nodeName, LogRpcSaveNotify& notify);

};


//日志服务全部调用代理类
class LogConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Log"; }
	
	//保存日志调用
	int Save( LogRpcSaveNotify& notify);

};


#endif//__LOG_PROXY_H

