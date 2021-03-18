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
	//连接AI调用
	int ConnectAIService( INT64 hintId, BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply);
	int ConnectAIService( const string& hintStr, BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply);
	//AI通知操作调用
	int AINoticeOper( INT64 hintId, BattleSPVPRpcAINoticeOperNotify& notify);
	int AINoticeOper( const string& hintStr, BattleSPVPRpcAINoticeOperNotify& notify);

};

//战斗同步随机调用代理类
class BattleSPVPRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "BattleSPVP"; }
	
	//创建房间调用
	int CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply);
	//连接AI调用
	int ConnectAIService( BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply);
	//AI通知操作调用
	int AINoticeOper( BattleSPVPRpcAINoticeOperNotify& notify);

};

//战斗同步轮询调用代理类
class BattleSPVPRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "BattleSPVP"; }
	
	//创建房间调用
	int CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply);
	//连接AI调用
	int ConnectAIService( BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply);
	//AI通知操作调用
	int AINoticeOper( BattleSPVPRpcAINoticeOperNotify& notify);

};

//战斗同步指定调用代理类
class BattleSPVPAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "BattleSPVP"; }
	
	//创建房间调用
	int CreateRoomSPVP( const TStr& nodeName, BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply);
	//连接AI调用
	int ConnectAIService( const TStr& nodeName, BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply);
	//AI通知操作调用
	int AINoticeOper( const TStr& nodeName, BattleSPVPRpcAINoticeOperNotify& notify);

};


//战斗同步全部调用代理类
class BattleSPVPConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "BattleSPVP"; }
	
	//创建房间调用
	int CreateRoomSPVP( BattleSPVPRpcCreateRoomSPVPAsk& ask, BattleSPVPRpcCreateRoomSPVPReply& reply);
	//连接AI调用
	int ConnectAIService( BattleSPVPRpcConnectAIServiceAsk& ask, BattleSPVPRpcConnectAIServiceReply& reply);
	//AI通知操作调用
	int AINoticeOper( BattleSPVPRpcAINoticeOperNotify& notify);

};


#endif//__BATTLESPVP_PROXY_H

