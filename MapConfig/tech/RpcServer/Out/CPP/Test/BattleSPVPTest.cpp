#include "CMDD.h"
#include "BattleSPVPRpc.pb.h"

BattleSPVPRpcCreateRoomSPVPAsk CreateRoomSPVPAsk;
BattleSPVPRpcCreateRoomSPVPReply CreateRoomSPVPReply;
BattleSPVPRpcConnectAIServiceAsk ConnectAIServiceAsk;
BattleSPVPRpcConnectAIServiceReply ConnectAIServiceReply;
BattleSPVPRpcAINoticeOperNotify AINoticeOperNotify;


struct BattleSPVPRpcInfoT
{
 	BattleSPVPRpcInfoT()
	{
		CreateRoomSPVPAsk.set_roomid(-1);
		CreateRoomSPVPAsk.set_sceneconfid(0);
		CreateRoomSPVPAsk.set_sceneid(1);
		RegisterRpcOperation("BattleSPVP::CreateRoomSPVP", 23, 1, &CreateRoomSPVPAsk, &CreateRoomSPVPReply);
		ConnectAIServiceAsk.set_roomid(-1);
		ConnectAIServiceAsk.set_sceneconfid(0);
		ConnectAIServiceAsk.set_sceneid(1);
		ConnectAIServiceAsk.set_nodename("");
		RegisterRpcOperation("BattleSPVP::ConnectAIService", 23, 2, &ConnectAIServiceAsk, &ConnectAIServiceReply);
		AINoticeOperNotify.set_uid(-1);
		AINoticeOperNotify.set_sceneid(-1);
		AINoticeOperNotify.add_msginfo("");
		AINoticeOperNotify.set_type(-1);
		RegisterRpcOperation("BattleSPVP::AINoticeOper", 23, 3, &AINoticeOperNotify, nullptr);

	}
};

static BattleSPVPRpcInfoT gInstanceBattleSPVPRpcInfo;

