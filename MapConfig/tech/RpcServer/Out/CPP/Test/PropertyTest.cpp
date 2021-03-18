#include "CMDD.h"
#include "PropertyRpc.pb.h"

PropertyRpcAddExpAsk AddValueAsk;
PropertyRpcAddExpReply AddValueReply;


struct PropertyRpcInfoT
{
 	PropertyRpcInfoT()
	{
		AddValueAsk.set_uid(-1);
		AddValueAsk.set_value(0);
		AddValueAsk.set_type(-1);
		RegisterRpcOperation("Property::AddValue", 13, 1, &AddValueAsk, &AddValueReply);

	}
};

static PropertyRpcInfoT gInstancePropertyRpcInfo;

