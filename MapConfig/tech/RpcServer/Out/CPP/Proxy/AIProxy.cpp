/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     AIProxy.h
* Author:       甘业清
* Date:         2020/3/18
* Description:  AI  RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "AIProxy.h"

struct AIRegisterProxyT
{
    AIRegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("AI");
    }
};
static AIRegisterProxyT AIRegisterProxyInstance;

int AICarpProxy::CreateAIScene( INT64 hintId, AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply)
{
	return RpcCall(27,1, RPC_CALL_MODE_CARP, nullptr, hintId, "", &ask, &reply);
}
int AICarpProxy::CreateAIScene( const string& hintStr, AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply)
{
	return RpcCall(27,1, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &ask, &reply);
}
int AICarpProxy::DeleteAIScene( INT64 hintId, AIRpcDeleteAISceneNotify& notify)
{
	return RpcCall(27,2, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int AICarpProxy::DeleteAIScene( const string& hintStr, AIRpcDeleteAISceneNotify& notify)
{
	return RpcCall(27,2, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int AICarpProxy::LoadUsers( INT64 hintId, AIRpcLoadUsersNotify& notify)
{
	return RpcCall(27,3, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int AICarpProxy::LoadUsers( const string& hintStr, AIRpcLoadUsersNotify& notify)
{
	return RpcCall(27,3, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int AICarpProxy::NoticeAIUserOper( INT64 hintId, AIRpcNoticeAIUserOperNotify& notify)
{
	return RpcCall(27,4, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int AICarpProxy::NoticeAIUserOper( const string& hintStr, AIRpcNoticeAIUserOperNotify& notify)
{
	return RpcCall(27,4, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int AICarpProxy::NoticeUpdateSceneInfo( INT64 hintId, AIRpcNoticeUpdateSceneInfoNotify& notify)
{
	return RpcCall(27,5, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int AICarpProxy::NoticeUpdateSceneInfo( const string& hintStr, AIRpcNoticeUpdateSceneInfoNotify& notify)
{
	return RpcCall(27,5, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}
int AICarpProxy::DeleteUser( INT64 hintId, AIRpcDeleteUserNotify& notify)
{
	return RpcCall(27,6, RPC_CALL_MODE_CARP, nullptr, hintId, "", &notify);
}
int AICarpProxy::DeleteUser( const string& hintStr, AIRpcDeleteUserNotify& notify)
{
	return RpcCall(27,6, RPC_CALL_MODE_CARP, nullptr, 0, hintStr, &notify);
}


int AIRandProxy::CreateAIScene( AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply)
{
	return RpcCall(27,1, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &ask, &reply);
}
int AIRandProxy::DeleteAIScene( AIRpcDeleteAISceneNotify& notify)
{
	return RpcCall(27,2, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int AIRandProxy::LoadUsers( AIRpcLoadUsersNotify& notify)
{
	return RpcCall(27,3, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int AIRandProxy::NoticeAIUserOper( AIRpcNoticeAIUserOperNotify& notify)
{
	return RpcCall(27,4, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int AIRandProxy::NoticeUpdateSceneInfo( AIRpcNoticeUpdateSceneInfoNotify& notify)
{
	return RpcCall(27,5, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}
int AIRandProxy::DeleteUser( AIRpcDeleteUserNotify& notify)
{
	return RpcCall(27,6, RPC_CALL_MODE_RANDOM, nullptr, 0, "", &notify);
}


int AIRoundProxy::CreateAIScene( AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply)
{
	return RpcCall(27,1, RPC_CALL_MODE_ROUND, nullptr, 0, "", &ask, &reply);
}
int AIRoundProxy::DeleteAIScene( AIRpcDeleteAISceneNotify& notify)
{
	return RpcCall(27,2, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int AIRoundProxy::LoadUsers( AIRpcLoadUsersNotify& notify)
{
	return RpcCall(27,3, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int AIRoundProxy::NoticeAIUserOper( AIRpcNoticeAIUserOperNotify& notify)
{
	return RpcCall(27,4, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int AIRoundProxy::NoticeUpdateSceneInfo( AIRpcNoticeUpdateSceneInfoNotify& notify)
{
	return RpcCall(27,5, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}
int AIRoundProxy::DeleteUser( AIRpcDeleteUserNotify& notify)
{
	return RpcCall(27,6, RPC_CALL_MODE_ROUND, nullptr, 0, "", &notify);
}


int AIAppointProxy::CreateAIScene( const TStr& nodeName, AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply)
{
	return RpcCall(27,1, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &ask, &reply);
}
int AIAppointProxy::DeleteAIScene( const TStr& nodeName, AIRpcDeleteAISceneNotify& notify)
{
	return RpcCall(27,2, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int AIAppointProxy::LoadUsers( const TStr& nodeName, AIRpcLoadUsersNotify& notify)
{
	return RpcCall(27,3, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int AIAppointProxy::NoticeAIUserOper( const TStr& nodeName, AIRpcNoticeAIUserOperNotify& notify)
{
	return RpcCall(27,4, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int AIAppointProxy::NoticeUpdateSceneInfo( const TStr& nodeName, AIRpcNoticeUpdateSceneInfoNotify& notify)
{
	return RpcCall(27,5, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}
int AIAppointProxy::DeleteUser( const TStr& nodeName, AIRpcDeleteUserNotify& notify)
{
	return RpcCall(27,6, RPC_CALL_MODE_APPOINT, nodeName, 0, "", &notify);
}


int AIConsistencyProxy::CreateAIScene( AIRpcCreateAISceneAsk& ask, AIRpcCreateAISceneReply& reply)
{
	return RpcCall(27,1, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &ask, &reply);
}
int AIConsistencyProxy::DeleteAIScene( AIRpcDeleteAISceneNotify& notify)
{
	return RpcCall(27,2, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int AIConsistencyProxy::LoadUsers( AIRpcLoadUsersNotify& notify)
{
	return RpcCall(27,3, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int AIConsistencyProxy::NoticeAIUserOper( AIRpcNoticeAIUserOperNotify& notify)
{
	return RpcCall(27,4, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int AIConsistencyProxy::NoticeUpdateSceneInfo( AIRpcNoticeUpdateSceneInfoNotify& notify)
{
	return RpcCall(27,5, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}
int AIConsistencyProxy::DeleteUser( AIRpcDeleteUserNotify& notify)
{
	return RpcCall(27,6, RPC_CALL_MODE_CONSISTENCY, nullptr, 0, "", &notify);
}


