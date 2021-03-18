#ifndef __SAID_PROXY_H
#define __SAID_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "SaidSvrRpc.pb.h"

//聊天一致性调用代理类
class SaidCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Said"; }
	
	//创建读取房间调用
	int CreateLoadRoom( INT64 hintId, SaidRpcCreateLoadRoomNotify& notify);
	int CreateLoadRoom( const string& hintStr, SaidRpcCreateLoadRoomNotify& notify);
	//消息转发调用
	int MessageForward( INT64 hintId, SaidRpcMessageForwardNotify& notify);
	int MessageForward( const string& hintStr, SaidRpcMessageForwardNotify& notify);

};

//聊天随机调用代理类
class SaidRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Said"; }
	
	//创建读取房间调用
	int CreateLoadRoom( SaidRpcCreateLoadRoomNotify& notify);
	//消息转发调用
	int MessageForward( SaidRpcMessageForwardNotify& notify);

};

//聊天轮询调用代理类
class SaidRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Said"; }
	
	//创建读取房间调用
	int CreateLoadRoom( SaidRpcCreateLoadRoomNotify& notify);
	//消息转发调用
	int MessageForward( SaidRpcMessageForwardNotify& notify);

};

//聊天指定调用代理类
class SaidAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Said"; }
	
	//创建读取房间调用
	int CreateLoadRoom( const TStr& nodeName, SaidRpcCreateLoadRoomNotify& notify);
	//消息转发调用
	int MessageForward( const TStr& nodeName, SaidRpcMessageForwardNotify& notify);

};


//聊天全部调用代理类
class SaidConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Said"; }
	
	//创建读取房间调用
	int CreateLoadRoom( SaidRpcCreateLoadRoomNotify& notify);
	//消息转发调用
	int MessageForward( SaidRpcMessageForwardNotify& notify);

};


#endif//__SAID_PROXY_H

