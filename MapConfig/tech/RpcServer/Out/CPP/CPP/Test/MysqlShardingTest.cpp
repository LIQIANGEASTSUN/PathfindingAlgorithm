#include "CMDD.h"
#include "MysqlShardingRpc.pb.h"

MysqlShardingRpcGetTableInfoAsk GetTableInfoAsk;
MysqlShardingRpcGetTableInfoReply GetTableInfoReply;
MysqlShardingRpcExecuteAsk ExecuteAsk;
MysqlShardingRpcExecuteReply ExecuteReply;
MysqlShardingRpcTransactionAsk TransactionAsk;
MysqlShardingRpcTransactionReply TransactionReply;


struct MysqlShardingRpcInfoT
{
 	MysqlShardingRpcInfoT()
	{
		GetTableInfoAsk.set_name("");
		RegisterRpcOperation("MysqlSharding::GetTableInfo", 7, 1, &GetTableInfoAsk, &GetTableInfoReply);
		ExecuteAsk.set_sql("");
		RegisterRpcOperation("MysqlSharding::Execute", 7, 2, &ExecuteAsk, &ExecuteReply);
		TransactionAsk.add_sqlarr("");
		RegisterRpcOperation("MysqlSharding::Transaction", 7, 3, &TransactionAsk, &TransactionReply);

	}
};

static MysqlShardingRpcInfoT gInstanceMysqlShardingRpcInfo;

