#include "CMDD.h"
#include "AuthRpc.pb.h"

AuthRpcOfflineAsk OfflineAsk;
AuthRpcOfflineReply OfflineReply;


struct AuthRpcInfoT
{
 	AuthRpcInfoT()
	{
		OfflineAsk.set_uid(-1);
		RegisterRpcOperation("Auth::Offline", 12, 1, &OfflineAsk, &OfflineReply);

	}
};

static AuthRpcInfoT gInstanceAuthRpcInfo;

