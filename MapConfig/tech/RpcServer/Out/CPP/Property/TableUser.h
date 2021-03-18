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
			{"mmr",{DOUBLE_FD, &_mmr}},
			{"status",{INT_FD, &_status}},
			{"lv",{INT_FD, &_lv}},
			{"exp",{INT_FD, &_exp}},
			{"continueWinActNum",{INT_FD, &_continueWinActNum}},
			{"continueLoseActNum",{INT_FD, &_continueLoseActNum}},
			{"allActNum",{INT_FD, &_allActNum}},
			{"nickName",{TSTR_FD, &_nickName}},
			{"headIcon",{INT_FD, &_headIcon}},
			{"gold",{INT_FD, &_gold}},
			{"diamond",{INT_FD, &_diamond}},
			{"channel",{INT_FD, &_channel}},

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
		strData += ",\"mmr\":\""+ to_string(_mmr)+"\"";
		strData += ",\"status\":\""+ to_string(_status)+"\"";
		strData += ",\"lv\":\""+ to_string(_lv)+"\"";
		strData += ",\"exp\":\""+ to_string(_exp)+"\"";
		strData += ",\"continueWinActNum\":\""+ to_string(_continueWinActNum)+"\"";
		strData += ",\"continueLoseActNum\":\""+ to_string(_continueLoseActNum)+"\"";
		strData += ",\"allActNum\":\""+ to_string(_allActNum)+"\"";
		strData += ",\"nickName\":\"" + _nickName+"\"";
		strData += ",\"headIcon\":\""+ to_string(_headIcon)+"\"";
		strData += ",\"gold\":\""+ to_string(_gold)+"\"";
		strData += ",\"diamond\":\""+ to_string(_diamond)+"\"";
		strData += ",\"channel\":\""+ to_string(_channel)+"\"";

		strData += "}";
		return strData;
	}
	INT64 _uid = 0;            //id
	TStr _name = "";           //用户名
	int _mtime = 0;            //修改时间
	TStr _pwd = "";            //密码
	double _mmr = 0;           //积分
	int _status = 0;           //状态
	int _lv = 0;               //等级
	int _exp = 0;              //经验
	int _continueWinActNum = 0;//连胜
	int _continueLoseActNum = 0;//连败
	int _allActNum = 0;        //所有战斗次数
	TStr _nickName = "";       //昵称 BASE64编码过
	int _headIcon = 0;         //头像
	int _gold = 0;             //金币
	int _diamond = 0;          //钻石
	int _channel = 0;          //渠道

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
