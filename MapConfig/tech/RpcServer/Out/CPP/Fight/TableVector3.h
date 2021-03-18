#ifndef __TAB_VECTOR3_H
#define __TAB_VECTOR3_H
#include "TableBase.h"

struct Vector3FldT : DataBaseT
{
	Vector3FldT()
	{
		_kf = 
		{
			{"z",{FLOAT_FD, &_z}},
			{"y",{FLOAT_FD, &_y}},
			{"z",{FLOAT_FD, &_z}},

		};
	}
	virtual ~Vector3FldT(){}

	virtual DataBaseT* create()
	{
		return new Vector3FldT();
	}
	virtual INT64 subKey()
	{
		return 0;
	}
	virtual void setValue(CloudDB* pQry)
	{
		_z = pQry->FloatField("z");
		_y = pQry->FloatField("y");
		_z = pQry->FloatField("z");

		_hasData = true;
	}

	virtual TStr jsonData()
	{
		TStr strData = "{";
		strData += "\"z\":"+ to_string(_z);
		strData += ",\"y\":"+ to_string(_y);
		strData += ",\"z\":"+ to_string(_z);

		strData += "}";
		return strData;
	}
	float _z = 0;              //
	float _y = 0;              //
	float _z = 0;              //

};

class TabVector3 : public TableBase
{
public:
	static TabVector3& Instance()
	{
		static TabVector3 sInstanceTabVector3;
		return sInstanceTabVector3;
	}

	virtual ~TabVector3() {}

	const Vector3FldT& selectPK(INT64 key)
	{
		static Vector3FldT staticEmptyVector3Fld;
		if (_mapData.count(key) == 0)
		{
			if( !loadPK(key) || _mapData.count(key)==0)
				return staticEmptyVector3Fld;
		}
		return *(Vector3FldT*)_mapData[key];
	}

protected:
	TabVector3()
	{
		_tableName = "Vector3";
		_primaryKey = "";
		_subsidiaryKey = "";
		_pDataStruct = new Vector3FldT();
	}
};

#endif 
