#ifndef __BATTLESPVP_PROXY_H
#define __BATTLESPVP_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "BattleSPVPSvrRpc.pb.h"

//战斗同步一致性调用代理类
class BattleSPVPCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "BattleSPVP"; }
	
	//创建房间调用
	int CreateRoomSPVP( INT64 hintId, BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply);
	int CreateRoomSPVP( const string& hintStr, BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply);

};

//战斗同步随机调用代理类
class BattleSPVPRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "BattleSPVP"; }
	
	//创建房间调用
	int CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply);

};

//战斗同步轮询调用代理类
class BattleSPVPRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "BattleSPVP"; }
	
	//创建房间调用
	int CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply);

};

//战斗同步指定调用代理类
class BattleSPVPAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "BattleSPVP"; }
	
	//创建房间调用
	int CreateRoomSPVP( const TStr& nodeName, BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply);

};


//战斗同步全部调用代理类
class BattleSPVPConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "BattleSPVP"; }
	
	//创建房间调用
	int CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply);

};


#endif//__BATTLESPVP_PROXY_H

