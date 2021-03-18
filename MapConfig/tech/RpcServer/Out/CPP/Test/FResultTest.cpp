#include "CMDD.h"
#include "FResultRpc.pb.h"

FResultRpcCalculationFResultNotify CalculationFResultNotify;


struct FResultRpcInfoT
{
 	FResultRpcInfoT()
	{
		CalculationFResultNotify.set_type(1);
		CalculationFResultNotify.set_aorbwin(0);
		RegisterRpcOperation("FResult::CalculationFResult", 29, 1, &CalculationFResultNotify, nullptr);

	}
};

static FResultRpcInfoT gInstanceFResultRpcInfo;

