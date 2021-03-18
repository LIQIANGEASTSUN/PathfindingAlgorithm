#include "CMDD.h"
#include "RaftRpc.pb.h"

RaftRpcVoteNotify VoteNotify;
RaftRpcTickNotify TickNotify;
RaftRpcSyncLogNotify SyncLogNotify;


struct RaftRpcInfoT
{
 	RaftRpcInfoT()
	{
		VoteNotify.set_type(-1);
		RegisterRpcOperation("Raft::Vote", 18, 1, &VoteNotify, nullptr);
		TickNotify.set_type(-1);
		TickNotify.set_addr("");
		RegisterRpcOperation("Raft::Tick", 18, 2, &TickNotify, nullptr);
		SyncLogNotify.set_type(-1);
		SyncLogNotify.set_data("");
		RegisterRpcOperation("Raft::SyncLog", 18, 3, &SyncLogNotify, nullptr);

	}
};

static RaftRpcInfoT gInstanceRaftRpcInfo;

