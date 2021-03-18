#include "CMDD.h"
#include "UserMsgRpc.pb.h"

UserMsgRpcExecAsk ExecAsk;
UserMsgRpcExecReply ExecReply;


struct UserMsgRpcInfoT
{
 	UserMsgRpcInfoT()
	{
		ExecAsk.set_msg("");
		ExecAsk.set_clientnodeid(-1);
		ExecAsk.set_uid(-1);
		RegisterRpcOperation("UserMsg::Exec", 9, 1, &ExecAsk, &ExecReply);

	}
};

static UserMsgRpcInfoT gInstanceUserMsgRpcInfo;

