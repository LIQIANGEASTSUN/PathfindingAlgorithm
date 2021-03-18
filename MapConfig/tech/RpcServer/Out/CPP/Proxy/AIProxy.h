#ifndef __AI_PROXY_H
#define __AI_PROXY_H

#include "BASE.h"
#include "RpcCenter.h"
#include "AISvrRpc.pb.h"

//AI 一致性调用代理类
class AICarpProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "AI"; }
	
	//通知创建AI场景调用
	int CreateAIScene( INT64 hintId, AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply);
	int CreateAIScene( const string& hintStr, AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply);
	//删除场景调用
	int DeleteAIScene( INT64 hintId, AIRpcDeleteAISceneNotify& notify);
	int DeleteAIScene( const string& hintStr, AIRpcDeleteAISceneNotify& notify);
	//加载玩家调用
	int LoadUsers( INT64 hintId, AIRpcLoadUsersNotify& notify);
	int LoadUsers( const string& hintStr, AIRpcLoadUsersNotify& notify);
	//通知AI操作调用
	int NoticeAIUserOper( INT64 hintId, AIRpcNoticeAIUserOperNotify& notify);
	int NoticeAIUserOper( const string& hintStr, AIRpcNoticeAIUserOperNotify& notify);
	//更新场景信息调用
	int NoticeUpdateSceneInfo( INT64 hintId, AIRpcNoticeUpdateSceneInfoNotify& notify);
	int NoticeUpdateSceneInfo( const string& hintStr, AIRpcNoticeUpdateSceneInfoNotify& notify);
	//delete user调用
	int DeleteUser( INT64 hintId, AIRpcDeleteUserNotify& notify);
	int DeleteUser( const string& hintStr, AIRpcDeleteUserNotify& notify);

};

//AI 随机调用代理类
class AIRandProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "AI"; }
	
	//通知创建AI场景调用
	int CreateAIScene( AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply);
	//删除场景调用
	int DeleteAIScene( AIRpcDeleteAISceneNotify& notify);
	//加载玩家调用
	int LoadUsers( AIRpcLoadUsersNotify& notify);
	//通知AI操作调用
	int NoticeAIUserOper( AIRpcNoticeAIUserOperNotify& notify);
	//更新场景信息调用
	int NoticeUpdateSceneInfo( AIRpcNoticeUpdateSceneInfoNotify& notify);
	//delete user调用
	int DeleteUser( AIRpcDeleteUserNotify& notify);

};

//AI 轮询调用代理类
class AIRoundProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "AI"; }
	
	//通知创建AI场景调用
	int CreateAIScene( AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply);
	//删除场景调用
	int DeleteAIScene( AIRpcDeleteAISceneNotify& notify);
	//加载玩家调用
	int LoadUsers( AIRpcLoadUsersNotify& notify);
	//通知AI操作调用
	int NoticeAIUserOper( AIRpcNoticeAIUserOperNotify& notify);
	//更新场景信息调用
	int NoticeUpdateSceneInfo( AIRpcNoticeUpdateSceneInfoNotify& notify);
	//delete user调用
	int DeleteUser( AIRpcDeleteUserNotify& notify);

};

//AI 指定调用代理类
class AIAppointProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "AI"; }
	
	//通知创建AI场景调用
	int CreateAIScene( const TStr& nodeName, AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply);
	//删除场景调用
	int DeleteAIScene( const TStr& nodeName, AIRpcDeleteAISceneNotify& notify);
	//加载玩家调用
	int LoadUsers( const TStr& nodeName, AIRpcLoadUsersNotify& notify);
	//通知AI操作调用
	int NoticeAIUserOper( const TStr& nodeName, AIRpcNoticeAIUserOperNotify& notify);
	//更新场景信息调用
	int NoticeUpdateSceneInfo( const TStr& nodeName, AIRpcNoticeUpdateSceneInfoNotify& notify);
	//delete user调用
	int DeleteUser( const TStr& nodeName, AIRpcDeleteUserNotify& notify);

};


//AI 全部调用代理类
class AIConsistencyProxy : public RpcProxy
{
public:
    virtual const char* GetProxyName() { return "AI"; }
	
	//通知创建AI场景调用
	int CreateAIScene( AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply);
	//删除场景调用
	int DeleteAIScene( AIRpcDeleteAISceneNotify& notify);
	//加载玩家调用
	int LoadUsers( AIRpcLoadUsersNotify& notify);
	//通知AI操作调用
	int NoticeAIUserOper( AIRpcNoticeAIUserOperNotify& notify);
	//更新场景信息调用
	int NoticeUpdateSceneInfo( AIRpcNoticeUpdateSceneInfoNotify& notify);
	//delete user调用
	int DeleteUser( AIRpcDeleteUserNotify& notify);

};


#endif//__AI_PROXY_H

