#include "CMDD.h"
#include "TeamRpc.pb.h"

TeamRpcGetTeamAsk GetTeamAsk;
TeamRpcGetTeamReply GetTeamReply;
TeamRpcTeamOverAsk TeamOverAsk;
TeamRpcTeamOverReply TeamOverReply;


struct TeamRpcInfoT
{
 	TeamRpcInfoT()
	{
		GetTeamAsk.set_teamid(-1);
		GetTeamAsk.set_uid(-1);
		RegisterRpcOperation("Team::GetTeam", 28, 1, &GetTeamAsk, &GetTeamReply);
		TeamOverAsk.set_teamid(-1);
		RegisterRpcOperation("Team::TeamOver", 28, 2, &TeamOverAsk, &TeamOverReply);

	}
};

static TeamRpcInfoT gInstanceTeamRpcInfo;

