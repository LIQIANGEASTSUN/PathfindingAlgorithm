#ifndef __GATE_PROXY_H
#define __GATE_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "GateSvrRpc.pb.h"

//接入服务一致性调用代理类
class GateCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Gate"; }
	
	//发送消息调用
	int SendMsg( INT64 hintId, GateRpcSendMsgNotify& notify);
	int SendMsg( const string& hintStr, GateRpcSendMsgNotify& notify);
	//广播消息调用
	int BroadcastMsg( INT64 hintId, GateRpcBroadcastMsgNotify& notify);
	int BroadcastMsg( const string& hintStr, GateRpcBroadcastMsgNotify& notify);
	//关闭连接调用
	int CloseNode( INT64 hintId, GateRpcCloseNodeNotify& notify);
	int CloseNode( const string& hintStr, GateRpcCloseNodeNotify& notify);
	//模块注册调用
	int RegisterModule( INT64 hintId, GateRpcRegisterModuleNotify& notify);
	int RegisterModule( const string& hintStr, GateRpcRegisterModuleNotify& notify);
	//踢人调用
	int Kick( INT64 hintId, GateRpcKickNotify& notify);
	int Kick( const string& hintStr, GateRpcKickNotify& notify);
	//节点上线调用
	int Online( INT64 hintId, GateRpcOnlineNotify& notify);
	int Online( const string& hintStr, GateRpcOnlineNotify& notify);

};

//接入服务随机调用代理类
class GateRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Gate"; }
	
	//发送消息调用
	int SendMsg( GateRpcSendMsgNotify& notify);
	//广播消息调用
	int BroadcastMsg( GateRpcBroadcastMsgNotify& notify);
	//关闭连接调用
	int CloseNode( GateRpcCloseNodeNotify& notify);
	//模块注册调用
	int RegisterModule( GateRpcRegisterModuleNotify& notify);
	//踢人调用
	int Kick( GateRpcKickNotify& notify);
	//节点上线调用
	int Online( GateRpcOnlineNotify& notify);

};

//接入服务轮询调用代理类
class GateRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Gate"; }
	
	//发送消息调用
	int SendMsg( GateRpcSendMsgNotify& notify);
	//广播消息调用
	int BroadcastMsg( GateRpcBroadcastMsgNotify& notify);
	//关闭连接调用
	int CloseNode( GateRpcCloseNodeNotify& notify);
	//模块注册调用
	int RegisterModule( GateRpcRegisterModuleNotify& notify);
	//踢人调用
	int Kick( GateRpcKickNotify& notify);
	//节点上线调用
	int Online( GateRpcOnlineNotify& notify);

};

//接入服务指定调用代理类
class GateAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Gate"; }
	
	//发送消息调用
	int SendMsg( const TStr& nodeName, GateRpcSendMsgNotify& notify);
	//广播消息调用
	int BroadcastMsg( const TStr& nodeName, GateRpcBroadcastMsgNotify& notify);
	//关闭连接调用
	int CloseNode( const TStr& nodeName, GateRpcCloseNodeNotify& notify);
	//模块注册调用
	int RegisterModule( const TStr& nodeName, GateRpcRegisterModuleNotify& notify);
	//踢人调用
	int Kick( const TStr& nodeName, GateRpcKickNotify& notify);
	//节点上线调用
	int Online( const TStr& nodeName, GateRpcOnlineNotify& notify);

};


//接入服务全部调用代理类
class GateConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Gate"; }
	
	//发送消息调用
	int SendMsg( GateRpcSendMsgNotify& notify);
	//广播消息调用
	int BroadcastMsg( GateRpcBroadcastMsgNotify& notify);
	//关闭连接调用
	int CloseNode( GateRpcCloseNodeNotify& notify);
	//模块注册调用
	int RegisterModule( GateRpcRegisterModuleNotify& notify);
	//踢人调用
	int Kick( GateRpcKickNotify& notify);
	//节点上线调用
	int Online( GateRpcOnlineNotify& notify);

};


#endif//__GATE_PROXY_H

