#ifndef __TAB_ONLINE_H
#define __TAB_ONLINE_H
#include "TableBase.h"

struct OnlineFldT : DataBaseT
{
	OnlineFldT()
	{
		_kf = 
		{
			{"uid",{INT64_FD, &_uid}},
			{"name",{TSTR_FD, &_name}},
			{"nodeId",{INT_FD, &_nodeId}},
			{"gateName",{TSTR_FD, &_gateName}},

		};
	}
	virtual ~OnlineFldT(){}

	virtual DataBaseT* create()
	{
		return new OnlineFldT();
	}
	virtual INT64 priKeyValue()
	{
	    return _uid;
	}


	virtual TStr jsonData()
	{
		TStr strData = "{";
		strData += "\"uid\":\""+ to_string(_uid)+"\"";
		strData += ",\"name\":\"" + _name+"\"";
		strData += ",\"nodeId\":\""+ to_string(_nodeId)+"\"";
		strData += ",\"gateName\":\"" + _gateName+"\"";

		strData += "}";
		return strData;
	}
	INT64 _uid = 0;            //用户ID
	TStr _name = "";           //用户名
	int _nodeId = 0;           //nodeId
	TStr _gateName = "";       //GATE名字

};

class TabOnline : public TableBase
{
public:
	static TabOnline& Instance()
	{
		static TabOnline sInstanceTabOnline;
		return sInstanceTabOnline;
	}

	virtual ~TabOnline() {}

	//返回结果需要delete
	OnlineFldT* selectPK(INT64 key)
	{
		if (!doSelect(key, 1) || _selectedData.empty())
			return nullptr;
		OnlineFldT* pRec = (OnlineFldT*)_selectedData[0];
		for (int n = 1; n < (int)_selectedData.size(); n++)
			delete _selectedData[n];
		_selectedData.clear();
		return pRec;
	}

	//返回结果需要delete
	vector<OnlineFldT*> selectSK(INT64 key)
	{
		vector<OnlineFldT*> vRecords;
		if (!doSelect(key, 2) || _selectedData.empty())
			return vRecords;
		for (int i = 0; i < (int)_selectedData.size(); i++)
			vRecords.push_back((OnlineFldT*)_selectedData[i]);
		_selectedData.clear();
		return vRecords;
	}
	TabOnline& carp(INT64 key)
	{
		_carpKey = key;
		return *this;
	}
	TabOnline& F(const TStr& fld)
	{
		vector<TStr> vFld = fld.Split(" ,");
		for (auto& f : vFld)
			_mapFV[f] = "";
		return *this;
	}
	TabOnline& syncToUid(INT64 uid)
	{
		_syncUid = uid;
		return *this;
	}

protected:
	TabOnline()
	{
		_tableName = "Online";
		_primaryKey = "uid";
		_subsidiaryKey = "";
		_pDataStruct = new OnlineFldT();
	}
};

#endif 
