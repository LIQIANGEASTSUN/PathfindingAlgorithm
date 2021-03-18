#ifndef __TAB_USER_H
#define __TAB_USER_H
#include "TableBase.h"

struct UserFldT : DataBaseT
{
	UserFldT()
	{
		_kf = 
		{
			{"uid",{INT64_FD, &_uid}},
			{"name",{TSTR_FD, &_name}},
			{"mtime",{INT_FD, &_mtime}},
			{"pwd",{TSTR_FD, &_pwd}},

		};
	}
	virtual ~UserFldT(){}

	virtual DataBaseT* create()
	{
		return new UserFldT();
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
		strData += ",\"mtime\":\""+ to_string(_mtime)+"\"";
		strData += ",\"pwd\":\"" + _pwd+"\"";

		strData += "}";
		return strData;
	}
	INT64 _uid = 0;            //id
	TStr _name = "";           //用户名
	int _mtime = 0;            //修改时间
	TStr _pwd = "";            //密码

};

class TabUser : public TableBase
{
public:
	static TabUser& Instance()
	{
		static TabUser sInstanceTabUser;
		return sInstanceTabUser;
	}

	virtual ~TabUser() {}

	//返回结果需要delete
	UserFldT* selectPK(INT64 key)
	{
		if (!doSelect(key, 1) || _selectedData.empty())
			return nullptr;
		UserFldT* pRec = (UserFldT*)_selectedData[0];
		for (int n = 1; n < (int)_selectedData.size(); n++)
			delete _selectedData[n];
		_selectedData.clear();
		return pRec;
	}

	//返回结果需要delete
	vector<UserFldT*> selectSK(INT64 key)
	{
		vector<UserFldT*> vRecords;
		if (!doSelect(key, 2) || _selectedData.empty())
			return vRecords;
		for (int i = 0; i < (int)_selectedData.size(); i++)
			vRecords.push_back((UserFldT*)_selectedData[i]);
		_selectedData.clear();
		return vRecords;
	}
	TabUser& carp(INT64 key)
	{
		_carpKey = key;
		return *this;
	}
	TabUser& F(const TStr& fld)
	{
		vector<TStr> vFld = fld.Split(" ,");
		for (auto& f : vFld)
			_mapFV[f] = "";
		return *this;
	}
	TabUser& syncToUid(INT64 uid)
	{
		_syncUid = uid;
		return *this;
	}

protected:
	TabUser()
	{
		_tableName = "User";
		_primaryKey = "uid";
		_subsidiaryKey = "";
		_pDataStruct = new UserFldT();
	}
};

#endif 
