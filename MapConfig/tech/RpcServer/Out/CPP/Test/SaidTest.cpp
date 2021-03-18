#include "CMDD.h"
#include "SaidRpc.pb.h"

SaidRpcCreateLoadRoomNotify CreateLoadRoomNotify;
SaidRpcMessageForwardNotify MessageForwardNotify;


struct SaidRpcInfoT
{
 	SaidRpcInfoT()
	{
		CreateLoadRoomNotify.set_id(-1);
		CreateLoadRoomNotify.add_uid(0);
		RegisterRpcOperation("Said::CreateLoadRoom", 22, 1, &CreateLoadRoomNotify, nullptr);
		MessageForwardNotify.set_value("");
		MessageForwardNotify.set_id(-1);
		RegisterRpcOperation("Said::MessageForward", 22, 2, &MessageForwardNotify, nullptr);

	}
};

static SaidRpcInfoT gInstanceSaidRpcInfo;

