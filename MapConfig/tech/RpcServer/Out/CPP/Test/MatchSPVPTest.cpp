#include "CMDD.h"
#include "MatchSPVPRpc.pb.h"

MatchSPVPRpcBattleNumNotify BattleNumNotify;
MatchSPVPRpcAINumNotify AINumNotify;


struct MatchSPVPRpcInfoT
{
 	MatchSPVPRpcInfoT()
	{
		BattleNumNotify.set_ip("");
		BattleNumNotify.set_port(-1);
		BattleNumNotify.set_scenenum(0);
		RegisterRpcOperation("MatchSPVP::BattleNum", 21, 1, &BattleNumNotify, nullptr);
		AINumNotify.set_ip("");
		AINumNotify.set_port(-1);
		AINumNotify.set_scenenum(0);
		RegisterRpcOperation("MatchSPVP::AINum", 21, 2, &AINumNotify, nullptr);

	}
};

static MatchSPVPRpcInfoT gInstanceMatchSPVPRpcInfo;

