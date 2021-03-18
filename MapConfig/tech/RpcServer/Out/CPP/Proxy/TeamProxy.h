#ifndef __TEAM_PROXY_H
#define __TEAM_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "TeamSvrRpc.pb.h"

//组队一致性调用代理类
class TeamCarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Team"; }
	
	//获取队伍调用
	int GetTeam( INT64 hintId, TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply);
	int GetTeam( const string& hintStr, TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply);
	//组队成功调用
	int TeamOver( INT64 hintId, TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply);
	int TeamOver( const string& hintStr, TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply);

};

//组队随机调用代理类
class TeamRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Team"; }
	
	//获取队伍调用
	int GetTeam( TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply);
	//组队成功调用
	int TeamOver( TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply);

};

//组队轮询调用代理类
class TeamRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Team"; }
	
	//获取队伍调用
	int GetTeam( TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply);
	//组队成功调用
	int TeamOver( TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply);

};

//组队指定调用代理类
class TeamAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Team"; }
	
	//获取队伍调用
	int GetTeam( const TStr& nodeName, TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply);
	//组队成功调用
	int TeamOver( const TStr& nodeName, TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply);

};


//组队全部调用代理类
class TeamConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "Team"; }
	
	//获取队伍调用
	int GetTeam( TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply);
	//组队成功调用
	int TeamOver( TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply);

};


#endif//__TEAM_PROXY_H

