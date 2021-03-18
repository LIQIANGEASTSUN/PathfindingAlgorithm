#include "CMDD.h"
#include "DBCacheRpc.pb.h"

DBCacheRpcInsertAsk InsertAsk;
DBCacheRpcInsertReply InsertReply;
DBCacheRpcDeleteAsk DeleteAsk;
DBCacheRpcDeleteReply DeleteReply;
DBCacheRpcUpdateAsk UpdateAsk;
DBCacheRpcUpdateReply UpdateReply;
DBCacheRpcSelectAsk SelectAsk;
DBCacheRpcSelectReply SelectReply;


struct DBCacheRpcInfoT
{
 	DBCacheRpcInfoT()
	{
		InsertAsk.set_tabname("");
		InsertAsk.set_primarykey("");
		InsertAsk.set_subsidiarykey("");
		InsertAsk.set_pkvalue("");
		InsertAsk.set_skvalue("");
		RegisterRpcOperation("DBCache::Insert", 25, 1, &InsertAsk, &InsertReply);
		DeleteAsk.set_tabname("");
		DeleteAsk.set_primarykey("");
		DeleteAsk.set_subsidiarykey("");
		DeleteAsk.set_type(0);
		DeleteAsk.set_keyvalue("");
		RegisterRpcOperation("DBCache::Delete", 25, 2, &DeleteAsk, &DeleteReply);
		UpdateAsk.set_tabname("");
		UpdateAsk.set_primarykey("");
		UpdateAsk.set_subsidiarykey("");
		UpdateAsk.set_pkvalue("");
		RegisterRpcOperation("DBCache::Update", 25, 3, &UpdateAsk, &UpdateReply);
		SelectAsk.set_tabname("");
		SelectAsk.set_primarykey("");
		SelectAsk.set_subsidiarykey("");
		SelectAsk.set_type(0);
		SelectAsk.set_keyvalue("");
		SelectAsk.add_fields("");
		RegisterRpcOperation("DBCache::Select", 25, 4, &SelectAsk, &SelectReply);

	}
};

static DBCacheRpcInfoT gInstanceDBCacheRpcInfo;

