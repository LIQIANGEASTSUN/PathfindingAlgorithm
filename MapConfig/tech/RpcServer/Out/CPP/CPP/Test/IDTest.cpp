#include "CMDD.h"
#include "IDRpc.pb.h"

IDRpcIDAsk IDAsk;
IDRpcIDReply IDReply;
IDRpcAddUserNotify AddUserNotify;


struct IDRpcInfoT
{
 	IDRpcInfoT()
	{
		IDAsk.set_fieldname("");
		IDAsk.set_username("");
		RegisterRpcOperation("ID::ID", 11, 1, &IDAsk, &IDReply);
		AddUserNotify.set_username("");
		AddUserNotify.set_id(-1);
		RegisterRpcOperation("ID::AddUser", 11, 2, &AddUserNotify, nullptr);

	}
};

static IDRpcInfoT gInstanceIDRpcInfo;

