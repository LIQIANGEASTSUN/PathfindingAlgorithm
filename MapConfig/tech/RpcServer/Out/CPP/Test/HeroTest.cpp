#include "CMDD.h"
#include "HeroRpc.pb.h"

HeroRpcCheckHeroIDAsk CheckHeroIDAsk;
HeroRpcCheckHeroIDReply CheckHeroIDReply;


struct HeroRpcInfoT
{
 	HeroRpcInfoT()
	{
		CheckHeroIDAsk.set_heroid(-1);
		CheckHeroIDAsk.set_uid(-1);
		RegisterRpcOperation("Hero::CheckHeroID", 20, 1, &CheckHeroIDAsk, &CheckHeroIDReply);

	}
};

static HeroRpcInfoT gInstanceHeroRpcInfo;

