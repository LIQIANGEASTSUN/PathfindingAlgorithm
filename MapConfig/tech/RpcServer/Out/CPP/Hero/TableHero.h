#ifndef __TAB_HERO_H
#define __TAB_HERO_H
#include "TableBase.h"

struct HeroFldT : DataBaseT
{
	HeroFldT()
	{
		_kf = 
		{
			{"mtime",{INT_FD, &_mtime}},
			{"id",{INT64_FD, &_id}},
			{"activetime",{INT_FD, &_activetime}},
			{"uid",{INT64_FD, &_uid}},

		};
	}
	virtual ~HeroFldT(){}

	virtual DataBaseT* create()
	{
		return new HeroFldT();
	}
	virtual INT64 priKeyValue()
	{
	    return _id;
	}


	virtual TStr jsonData()
	{
		TStr strData = "{";
		strData += "\"mtime\":\""+ to_string(_mtime)+"\"";
		strData += ",\"id\":\""+ to_string(_id)+"\"";
		strData += ",\"activetime\":\""+ to_string(_activetime)+"\"";
		strData += ",\"uid\":\""+ to_string(_uid)+"\"";

		strData += "}";
		return strData;
	}
	int _mtime = 0;            //修改时间
	INT64 _id = 0;             //唯一key
	int _activetime = 0;       //激活时间
	INT64 _uid = 0;            //userid

};

class TabHero : public TableBase
{
public:
	static TabHero& Instance()
	{
		static TabHero sInstanceTabHero;
		return sInstanceTabHero;
	}

	virtual ~TabHero() {}

	//返回结果需要delete
	HeroFldT* selectPK(INT64 key)
	{
		if (!doSelect(key, 1) || _selectedData.empty())
			return nullptr;
		HeroFldT* pRec = (HeroFldT*)_selectedData[0];
		for (int n = 1; n < (int)_selectedData.size(); n++)
			delete _selectedData[n];
		_selectedData.clear();
		return pRec;
	}

	//返回结果需要delete
	vector<HeroFldT*> selectSK(INT64 key)
	{
		vector<HeroFldT*> vRecords;
		if (!doSelect(key, 2) || _selectedData.empty())
			return vRecords;
		for (int i = 0; i < (int)_selectedData.size(); i++)
			vRecords.push_back((HeroFldT*)_selectedData[i]);
		_selectedData.clear();
		return vRecords;
	}
	TabHero& carp(INT64 key)
	{
		_carpKey = key;
		return *this;
	}
	TabHero& F(const TStr& fld)
	{
		vector<TStr> vFld = fld.Split(" ,");
		for (auto& f : vFld)
			_mapFV[f] = "";
		return *this;
	}
	TabHero& syncToUid(INT64 uid)
	{
		_syncUid = uid;
		return *this;
	}

protected:
	TabHero()
	{
		_tableName = "Hero";
		_primaryKey = "id";
		_subsidiaryKey = "uid";
		_pDataStruct = new HeroFldT();
	}
};

#endif 
