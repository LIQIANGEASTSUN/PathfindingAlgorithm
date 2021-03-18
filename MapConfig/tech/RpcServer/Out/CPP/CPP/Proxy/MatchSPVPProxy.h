#ifndef __MATCHSPVP_PROXY_H
#define __MATCHSPVP_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "MatchSPVPSvrRpc.pb.h"

//匹配一致性调用代理类
class MatchSPVPCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "MatchSPVP"; }
	
	//报告状态调用
	int BattleNum( INT64 hintId, MatchSPVPRpcBattleNumNotify& notify);
	int BattleNum( const string& hintStr, MatchSPVPRpcBattleNumNotify& notify);

};

//匹配随机调用代理类
class MatchSPVPRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "MatchSPVP"; }
	
	//报告状态调用
	int BattleNum( MatchSPVPRpcBattleNumNotify& notify);

};

//匹配轮询调用代理类
class MatchSPVPRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "MatchSPVP"; }
	
	//报告状态调用
	int BattleNum( MatchSPVPRpcBattleNumNotify& notify);

};

//匹配指定调用代理类
class MatchSPVPAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "MatchSPVP"; }
	
	//报告状态调用
	int BattleNum( const TStr& nodeName, MatchSPVPRpcBattleNumNotify& notify);

};


//匹配全部调用代理类
class MatchSPVPConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "MatchSPVP"; }
	
	//报告状态调用
	int BattleNum( MatchSPVPRpcBattleNumNotify& notify);

};


#endif//__MATCHSPVP_PROXY_H

