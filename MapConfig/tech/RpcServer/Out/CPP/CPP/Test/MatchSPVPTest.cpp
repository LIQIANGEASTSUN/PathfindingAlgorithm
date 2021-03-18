#include "CMDD.h"
#include "MatchSPVPRpc.pb.h"

MatchSPVPRpcBattleNumNotify BattleNumNotify;


struct MatchSPVPRpcInfoT
{
 	MatchSPVPRpcInfoT()
	{
		BattleNumNotify.set_ip("");
		BattleNumNotify.set_port(-1);
		BattleNumNotify.set_scenenum(0);
		RegisterRpcOperation("MatchSPVP::BattleNum", 21, 1, &BattleNumNotify, nullptr);

	}
};

static MatchSPVPRpcInfoT gInstanceMatchSPVPRpcInfo;

