#include "CMDD.h"
#include "AIRpc.pb.h"

AIRpcCreateAISceneAsk CreateAISceneAsk;
AIRpcCreateAISceneReply CreateAISceneReply;
AIRpcDeleteAISceneNotify DeleteAISceneNotify;
AIRpcLoadUsersNotify LoadUsersNotify;
AIRpcNoticeAIUserOperNotify NoticeAIUserOperNotify;
AIRpcNoticeUpdateSceneInfoNotify NoticeUpdateSceneInfoNotify;
AIRpcDeleteUserNotify DeleteUserNotify;


struct AIRpcInfoT
{
 	AIRpcInfoT()
	{
		CreateAISceneAsk.set_roomid(-1);
		CreateAISceneAsk.set_sceneconfid(0);
		CreateAISceneAsk.set_sceneid(1);
		CreateAISceneAsk.set_nodename("");
		RegisterRpcOperation("AI::CreateAIScene", 27, 1, &CreateAISceneAsk, &CreateAISceneReply);
		DeleteAISceneNotify.set_roomid(-1);
		DeleteAISceneNotify.set_nodename("");
		DeleteAISceneNotify.set_sceneid(1);
		RegisterRpcOperation("AI::DeleteAIScene", 27, 2, &DeleteAISceneNotify, nullptr);
		LoadUsersNotify.set_userinfo("");
		LoadUsersNotify.set_sceneid(-1);
		RegisterRpcOperation("AI::LoadUsers", 27, 3, &LoadUsersNotify, nullptr);
		NoticeAIUserOperNotify.set_opertype(-1);
		NoticeAIUserOperNotify.set_userid(-1);
		NoticeAIUserOperNotify.add_msginfo("");
		NoticeAIUserOperNotify.set_sceneid(-1);
		RegisterRpcOperation("AI::NoticeAIUserOper", 27, 4, &NoticeAIUserOperNotify, nullptr);
		NoticeUpdateSceneInfoNotify.set_sceneid(-1);
		NoticeUpdateSceneInfoNotify.add_sprayinfo("");
		NoticeUpdateSceneInfoNotify.set_sendtime(-1);
		RegisterRpcOperation("AI::NoticeUpdateSceneInfo", 27, 5, &NoticeUpdateSceneInfoNotify, nullptr);
		DeleteUserNotify.set_uid(-1);
		DeleteUserNotify.set_sceneid(-1);
		RegisterRpcOperation("AI::DeleteUser", 27, 6, &DeleteUserNotify, nullptr);

	}
};

static AIRpcInfoT gInstanceAIRpcInfo;

