#ifndef __ID_PROXY_H
#define __ID_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "IDSvrRpc.pb.h"

//ID生成一致性调用代理类
class IDCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "ID"; }
	
	//ID调用
	int ID( INT64 hintId, IDRpcIDAsk& ask, IDRpcIDReply& reply);
	int ID( const string& hintStr, IDRpcIDAsk& ask, IDRpcIDReply& reply);
	//添加用户名及uid调用
	int AddUser( INT64 hintId, IDRpcAddUserNotify& notify);
	int AddUser( const string& hintStr, IDRpcAddUserNotify& notify);

};

//ID生成随机调用代理类
class IDRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "ID"; }
	
	//ID调用
	int ID( IDRpcIDAsk& ask, IDRpcIDReply& reply);
	//添加用户名及uid调用
	int AddUser( IDRpcAddUserNotify& notify);

};

//ID生成轮询调用代理类
class IDRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "ID"; }
	
	//ID调用
	int ID( IDRpcIDAsk& ask, IDRpcIDReply& reply);
	//添加用户名及uid调用
	int AddUser( IDRpcAddUserNotify& notify);

};

//ID生成指定调用代理类
class IDAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "ID"; }
	
	//ID调用
	int ID( const TStr& nodeName, IDRpcIDAsk& ask, IDRpcIDReply& reply);
	//添加用户名及uid调用
	int AddUser( const TStr& nodeName, IDRpcAddUserNotify& notify);

};


//ID生成全部调用代理类
class IDConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "ID"; }
	
	//ID调用
	int ID( IDRpcIDAsk& ask, IDRpcIDReply& reply);
	//添加用户名及uid调用
	int AddUser( IDRpcAddUserNotify& notify);

};


#endif//__ID_PROXY_H

