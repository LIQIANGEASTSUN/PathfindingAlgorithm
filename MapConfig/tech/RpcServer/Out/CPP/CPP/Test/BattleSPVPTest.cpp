#include "CMDD.h"
#include "BattleSPVPRpc.pb.h"

BattleSPVPRpcCreateRoomSPVPAsk CreateRoomSPVPAsk;
BattleSPVPRpcCreateRoomSPVPReply CreateRoomSPVPReply;


struct BattleSPVPRpcInfoT
{
 	BattleSPVPRpcInfoT()
	{
		CreateRoomSPVPAsk.set_roomid(-1);
		CreateRoomSPVPAsk.set_sceneconfid(0);
		CreateRoomSPVPAsk.set_sceneid(1);
		RegisterRpcOperation("BattleSPVP::CreateRoomSPVP", 23, 1, &CreateRoomSPVPAsk, &CreateRoomSPVPReply);

	}
};

static BattleSPVPRpcInfoT gInstanceBattleSPVPRpcInfo;

