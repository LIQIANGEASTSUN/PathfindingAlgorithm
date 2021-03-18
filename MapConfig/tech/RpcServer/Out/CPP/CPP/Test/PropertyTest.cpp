#include "CMDD.h"
#include "PropertyRpc.pb.h"

PropertyRpcAddExpAsk AddExpAsk;
PropertyRpcAddExpReply AddExpReply;


struct PropertyRpcInfoT
{
 	PropertyRpcInfoT()
	{
		AddExpAsk.set_uid(-1);
		AddExpAsk.set_exp(0);
		RegisterRpcOperation("Property::AddExp", 13, 1, &AddExpAsk, &AddExpReply);

	}
};

static PropertyRpcInfoT gInstancePropertyRpcInfo;

