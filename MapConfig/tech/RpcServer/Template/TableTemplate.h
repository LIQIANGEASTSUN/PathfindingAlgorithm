#ifndef __TAB_$TABLENAME$_H
#define __TAB_$TABLENAME$_H
#include "TableBase.h"

struct $TableName$FldT : DataBaseT
{
	$TableName$FldT()
	{
		_kf = 
		{
$MapSetFields$
		};
	}
	virtual ~$TableName$FldT(){}

	virtual DataBaseT* create()
	{
		return new $TableName$FldT();
	}
	virtual INT64 priKeyValue()
	{
	    return _$PrimaryKey$;
	}


	virtual TStr jsonData()
	{
		TStr strData = "{";
$JsonData$
		strData += "}";
		return strData;
	}
$DefineField$
};

class Tab$TableName$ : public TableBase
{
public:
	static Tab$TableName$& Instance()
	{
		static Tab$TableName$ sInstanceTab$TableName$;
		return sInstanceTab$TableName$;
	}

	virtual ~Tab$TableName$() {}

	//返回结果需要delete
	$TableName$FldT* selectPK(INT64 key)
	{
		if (!doSelect(key, 1) || _selectedData.empty())
			return nullptr;
		$TableName$FldT* pRec = ($TableName$FldT*)_selectedData[0];
		for (int n = 1; n < (int)_selectedData.size(); n++)
			delete _selectedData[n];
		_selectedData.clear();
		return pRec;
	}

	//返回结果需要delete
	vector<$TableName$FldT*> selectSK(INT64 key)
	{
		vector<$TableName$FldT*> vRecords;
		if (!doSelect(key, 2) || _selectedData.empty())
			return vRecords;
		for (int i = 0; i < (int)_selectedData.size(); i++)
			vRecords.push_back(($TableName$FldT*)_selectedData[i]);
		_selectedData.clear();
		return vRecords;
	}
	Tab$TableName$& carp(INT64 key)
	{
		_carpKey = key;
		return *this;
	}
	Tab$TableName$& F(const TStr& fld)
	{
		vector<TStr> vFld = fld.Split(" ,");
		for (auto& f : vFld)
			_mapFV[f] = "";
		return *this;
	}
	Tab$TableName$& syncToUid(INT64 uid)
	{
		_syncUid = uid;
		return *this;
	}

protected:
	Tab$TableName$()
	{
		_tableName = "$TableName$";
		_primaryKey = "$PrimaryKey$";
		_subsidiaryKey = "$SubKey$";
		_pDataStruct = new $TableName$FldT();
	}
};

#endif 
