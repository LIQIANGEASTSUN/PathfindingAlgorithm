#include "CMDD.h"
#include "GateRpc.pb.h"

GateRpcSendMsgNotify SendMsgNotify;
GateRpcBroadcastMsgNotify BroadcastMsgNotify;
GateRpcCloseNodeNotify CloseNodeNotify;
GateRpcRegisterModuleNotify RegisterModuleNotify;
GateRpcKickNotify KickNotify;
GateRpcOnlineNotify OnlineNotify;


struct GateRpcInfoT
{
 	GateRpcInfoT()
	{
		SendMsgNotify.add_uidarr(-1);
		SendMsgNotify.set_msg("");
		RegisterRpcOperation("Gate::SendMsg", 8, 1, &SendMsgNotify, nullptr);
		BroadcastMsgNotify.set_msg("");
		RegisterRpcOperation("Gate::BroadcastMsg", 8, 2, &BroadcastMsgNotify, nullptr);
		CloseNodeNotify.add_uidarr(-1);
		RegisterRpcOperation("Gate::CloseNode", 8, 3, &CloseNodeNotify, nullptr);
		RegisterModuleNotify.add_moduleidarr(-1);
		RegisterRpcOperation("Gate::RegisterModule", 8, 4, &RegisterModuleNotify, nullptr);
		KickNotify.set_uid(-1);
		RegisterRpcOperation("Gate::Kick", 8, 5, &KickNotify, nullptr);
		OnlineNotify.set_nodeid(-1);
		OnlineNotify.set_uid(-1);
		OnlineNotify.set_name("");
		RegisterRpcOperation("Gate::Online", 8, 6, &OnlineNotify, nullptr);

	}
};

static GateRpcInfoT gInstanceGateRpcInfo;

