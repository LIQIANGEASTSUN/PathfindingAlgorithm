#ifndef __TABLE_CONFIG_H
#define __TABLE_CONFIG_H
#include "BaseConfigEx.h"
struct Terrain1T : ConfigBaseT
{
	virtual ~Terrain1T()
	{
	}
	Terrain1T()
	{
		FileName = "Terrain1.csv";
		_kf =
		{
			{"Terraiin",{INT_FD, &Terraiin}},
			{"ColCount",{INT_FD, &ColCount}},
			{"col0",{TSTR_FD, &col0}},
			{"col1",{TSTR_FD, &col1}},
			{"col2",{TSTR_FD, &col2}},
			{"col3",{TSTR_FD, &col3}},
			{"col4",{TSTR_FD, &col4}},
			{"col5",{TSTR_FD, &col5}},
			{"col6",{TSTR_FD, &col6}},
			{"col7",{TSTR_FD, &col7}},
			{"col8",{TSTR_FD, &col8}},
			{"col9",{TSTR_FD, &col9}},
			{"col10",{TSTR_FD, &col10}},
			{"col11",{TSTR_FD, &col11}},
			{"col12",{TSTR_FD, &col12}},
			{"col13",{TSTR_FD, &col13}},
			{"col14",{TSTR_FD, &col14}},
			{"col15",{TSTR_FD, &col15}},
			{"col16",{TSTR_FD, &col16}},
			{"col17",{TSTR_FD, &col17}},
			{"col18",{TSTR_FD, &col18}},
			{"col19",{TSTR_FD, &col19}}
		};
	}
	virtual Terrain1T* create()
	{
		return new Terrain1T();
	}
	enum
	{
	};
	INT32 Terraiin = 0;            //主键
	INT32 ColCount = 0;				//总列数
	TStr col0 = "";				//列0
	TStr col1 = "";				//列1
	TStr col2 = "";				//列2
	TStr col3 = "";				//列3
	TStr col4 = "";				//列4
	TStr col5 = "";				//列5
	TStr col6 = "";				//列6
	TStr col7 = "";				//列7
	TStr col8 = "";				//列8
	TStr col9 = "";				//列9
	TStr col10 = "";				//列10
	TStr col11 = "";				//列11
	TStr col12 = "";				//列12
	TStr col13 = "";				//列13
	TStr col14 = "";				//列14
	TStr col15 = "";				//列15
	TStr col16 = "";				//列16
	TStr col17 = "";				//列17
	TStr col18 = "";				//列18
	TStr col19 = "";				//列19
};
CreateCsvClass(Terrain1);

struct Terrain2T : ConfigBaseT
{
	virtual ~Terrain2T()
	{
	}
	Terrain2T()
	{
		FileName = "Terrain2.csv";
		_kf =
		{
			{"Terraiin",{INT_FD, &Terraiin}},
			{"ColCount",{INT_FD, &ColCount}},
			{"col0",{TSTR_FD, &col0}},
			{"col1",{TSTR_FD, &col1}},
			{"col2",{TSTR_FD, &col2}},
			{"col3",{TSTR_FD, &col3}},
			{"col4",{TSTR_FD, &col4}},
			{"col5",{TSTR_FD, &col5}},
			{"col6",{TSTR_FD, &col6}},
			{"col7",{TSTR_FD, &col7}},
			{"col8",{TSTR_FD, &col8}},
			{"col9",{TSTR_FD, &col9}},
			{"col10",{TSTR_FD, &col10}},
			{"col11",{TSTR_FD, &col11}},
			{"col12",{TSTR_FD, &col12}},
			{"col13",{TSTR_FD, &col13}},
			{"col14",{TSTR_FD, &col14}},
			{"col15",{TSTR_FD, &col15}},
			{"col16",{TSTR_FD, &col16}},
			{"col17",{TSTR_FD, &col17}},
			{"col18",{TSTR_FD, &col18}},
			{"col19",{TSTR_FD, &col19}}
		};
	}
	virtual Terrain2T* create()
	{
		return new Terrain2T();
	}
	enum
	{
	};
	INT32 Terraiin = 0;            //主键
	INT32 ColCount = 0;				//总列数
	TStr col0 = "";				//列0
	TStr col1 = "";				//列1
	TStr col2 = "";				//列2
	TStr col3 = "";				//列3
	TStr col4 = "";				//列4
	TStr col5 = "";				//列5
	TStr col6 = "";				//列6
	TStr col7 = "";				//列7
	TStr col8 = "";				//列8
	TStr col9 = "";				//列9
	TStr col10 = "";				//列10
	TStr col11 = "";				//列11
	TStr col12 = "";				//列12
	TStr col13 = "";				//列13
	TStr col14 = "";				//列14
	TStr col15 = "";				//列15
	TStr col16 = "";				//列16
	TStr col17 = "";				//列17
	TStr col18 = "";				//列18
	TStr col19 = "";				//列19
};
CreateCsvClass(Terrain2);

struct Terrain3T : ConfigBaseT
{
	virtual ~Terrain3T()
	{
	}
	Terrain3T()
	{
		FileName = "Terrain3.csv";
		_kf =
		{
			{"Terraiin",{INT_FD, &Terraiin}},
			{"ColCount",{INT_FD, &ColCount}},
			{"col0",{TSTR_FD, &col0}},
			{"col1",{TSTR_FD, &col1}},
			{"col2",{TSTR_FD, &col2}},
			{"col3",{TSTR_FD, &col3}},
			{"col4",{TSTR_FD, &col4}},
			{"col5",{TSTR_FD, &col5}},
			{"col6",{TSTR_FD, &col6}},
			{"col7",{TSTR_FD, &col7}},
			{"col8",{TSTR_FD, &col8}},
			{"col9",{TSTR_FD, &col9}},
			{"col10",{TSTR_FD, &col10}},
			{"col11",{TSTR_FD, &col11}},
			{"col12",{TSTR_FD, &col12}},
			{"col13",{TSTR_FD, &col13}},
			{"col14",{TSTR_FD, &col14}},
			{"col15",{TSTR_FD, &col15}},
			{"col16",{TSTR_FD, &col16}},
			{"col17",{TSTR_FD, &col17}},
			{"col18",{TSTR_FD, &col18}},
			{"col19",{TSTR_FD, &col19}}
		};
	}
	virtual Terrain3T* create()
	{
		return new Terrain3T();
	}
	enum
	{
	};
	INT32 Terraiin = 0;            //主键
	INT32 ColCount = 0;				//总列数
	TStr col0 = "";				//列0
	TStr col1 = "";				//列1
	TStr col2 = "";				//列2
	TStr col3 = "";				//列3
	TStr col4 = "";				//列4
	TStr col5 = "";				//列5
	TStr col6 = "";				//列6
	TStr col7 = "";				//列7
	TStr col8 = "";				//列8
	TStr col9 = "";				//列9
	TStr col10 = "";				//列10
	TStr col11 = "";				//列11
	TStr col12 = "";				//列12
	TStr col13 = "";				//列13
	TStr col14 = "";				//列14
	TStr col15 = "";				//列15
	TStr col16 = "";				//列16
	TStr col17 = "";				//列17
	TStr col18 = "";				//列18
	TStr col19 = "";				//列19
};
CreateCsvClass(Terrain3);

struct Terrain4T : ConfigBaseT
{
	virtual ~Terrain4T()
	{
	}
	Terrain4T()
	{
		FileName = "Terrain4.csv";
		_kf =
		{
			{"Terraiin",{INT_FD, &Terraiin}},
			{"ColCount",{INT_FD, &ColCount}},
			{"col0",{TSTR_FD, &col0}},
			{"col1",{TSTR_FD, &col1}},
			{"col2",{TSTR_FD, &col2}},
			{"col3",{TSTR_FD, &col3}},
			{"col4",{TSTR_FD, &col4}},
			{"col5",{TSTR_FD, &col5}},
			{"col6",{TSTR_FD, &col6}},
			{"col7",{TSTR_FD, &col7}},
			{"col8",{TSTR_FD, &col8}},
			{"col9",{TSTR_FD, &col9}},
			{"col10",{TSTR_FD, &col10}},
			{"col11",{TSTR_FD, &col11}},
			{"col12",{TSTR_FD, &col12}},
			{"col13",{TSTR_FD, &col13}},
			{"col14",{TSTR_FD, &col14}},
			{"col15",{TSTR_FD, &col15}},
			{"col16",{TSTR_FD, &col16}},
			{"col17",{TSTR_FD, &col17}},
			{"col18",{TSTR_FD, &col18}},
			{"col19",{TSTR_FD, &col19}}
		};
	}
	virtual Terrain4T* create()
	{
		return new Terrain4T();
	}
	enum
	{
	};
	INT32 Terraiin = 0;            //主键
	INT32 ColCount = 0;				//总列数
	TStr col0 = "";				//列0
	TStr col1 = "";				//列1
	TStr col2 = "";				//列2
	TStr col3 = "";				//列3
	TStr col4 = "";				//列4
	TStr col5 = "";				//列5
	TStr col6 = "";				//列6
	TStr col7 = "";				//列7
	TStr col8 = "";				//列8
	TStr col9 = "";				//列9
	TStr col10 = "";				//列10
	TStr col11 = "";				//列11
	TStr col12 = "";				//列12
	TStr col13 = "";				//列13
	TStr col14 = "";				//列14
	TStr col15 = "";				//列15
	TStr col16 = "";				//列16
	TStr col17 = "";				//列17
	TStr col18 = "";				//列18
	TStr col19 = "";				//列19
};
CreateCsvClass(Terrain4);

#endif