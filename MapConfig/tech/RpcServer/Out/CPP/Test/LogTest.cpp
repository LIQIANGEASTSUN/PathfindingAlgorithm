#include "CMDD.h"
#include "LogRpc.pb.h"

LogRpcSaveNotify SaveNotify;


struct LogRpcInfoT
{
 	LogRpcInfoT()
	{
		SaveNotify.set_content("");
		SaveNotify.set_logid(-1);
		SaveNotify.set_logseq(-1);
		RegisterRpcOperation("Log::Save", 24, 1, &SaveNotify, nullptr);

	}
};

static LogRpcInfoT gInstanceLogRpcInfo;

