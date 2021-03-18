#ifndef __TABLE_CONFIG_H
#define __TABLE_CONFIG_H
#include "BaseConfigEx.h"
struct table_activityT : ConfigBaseT
{
	virtual ~table_activityT()
	{
	}
	table_activityT()
	{
		FileName = "table_activity.csv";
		_kf =
		{
			{"ActivityID",{INT_FD, &ActivityID}},
			{"ActivityStyle",{INT_FD, &ActivityStyle}},
			{"Name",{TSTR_FD, &Name}},
			{"BB",{TSTR_FD, &BB}},
			{"ActivityType",{INT_FD, &ActivityType}},
			{"GateUIRes",{TSTR_FD, &GateUIRes}},
			{"PreviewUIRes",{TSTR_FD, &PreviewUIRes}},
			{"StartUIRes",{TSTR_FD, &StartUIRes}},
			{"MainUIRes",{TSTR_FD, &MainUIRes}},
			{"TaskRewardUIRes",{TSTR_FD, &TaskRewardUIRes}},
			{"LevelId",{INT_FD, &LevelId}},
			{"Prosperity",{INT_FD, &Prosperity}},
			{"ActivityPointId",{INT_FD, &ActivityPointId}},
			{"TaskAwardDrop",{INT_FD, &TaskAwardDrop}},
			{"TaskAwardType1",{INT_FD, &TaskAwardType1}},
			{"TaskAwardTypeID1",{INT_FD, &TaskAwardTypeID1}},
			{"TaskAwardNum1",{INT_FD, &TaskAwardNum1}},
			{"TaskAwardType2",{INT_FD, &TaskAwardType2}},
			{"TaskAwardTypeID2",{INT_FD, &TaskAwardTypeID2}},
			{"TaskAwardNum2",{INT_FD, &TaskAwardNum2}},
			{"TaskAwardType3",{INT_FD, &TaskAwardType3}},
			{"TaskAwardTypeID3",{INT_FD, &TaskAwardTypeID3}},
			{"TaskAwardNum3",{INT_FD, &TaskAwardNum3}},
			{"PreviewTime",{TSTR_FD, &PreviewTime}},
			{"StartTime",{TSTR_FD, &StartTime}},
			{"RewardTime",{TSTR_FD, &RewardTime}},
			{"CloseTime",{TSTR_FD, &CloseTime}},
			{"DoublePriceFirst",{FLOAT_FD, &DoublePriceFirst}},
			{"DoublePriceFirstReset",{FLOAT_FD, &DoublePriceFirstReset}},
			{"PointIconAtlas",{TSTR_FD, &PointIconAtlas}},
			{"PointIcon",{TSTR_FD, &PointIcon}},
			{"PointEffect",{TSTR_FD, &PointEffect}},
			{"NameKey",{TSTR_FD, &NameKey}},
			{"BBKey",{TSTR_FD, &BBKey}}
		};
	}
	virtual table_activityT* create()
	{
		return new table_activityT();
	}
	enum
	{
	};
	INT32 ActivityID = 0;            //活动ID
	INT32 ActivityStyle = 0;				//活动方式
	TStr Name = "";				//活动名称
	TStr BB = "";				//描述内容
	INT32 ActivityType = 0;				//活动类型
	TStr GateUIRes = "";				//主界面按钮
	TStr PreviewUIRes = "";				//预览UI
	TStr StartUIRes = "";				//进入UI
	TStr MainUIRes = "";				//主界面UI
	TStr TaskRewardUIRes = "";				//奖励界面UI
	INT32 LevelId = 0;				//对应关卡ID
	INT32 Prosperity = 0;				//部落之力要求
	INT32 ActivityPointId = 0;				//积分奖励ID
	INT32 TaskAwardDrop = 0;				//10任务奖励DropID
	INT32 TaskAwardType1 = 0;				//10任务奖励类型1
	INT32 TaskAwardTypeID1 = 0;				//10任务奖励类型1ID
	INT32 TaskAwardNum1 = 0;				//10任务奖励数量1
	INT32 TaskAwardType2 = 0;				//10任务奖励类型2
	INT32 TaskAwardTypeID2 = 0;				//10任务奖励类型2ID
	INT32 TaskAwardNum2 = 0;				//10任务奖励数量2
	INT32 TaskAwardType3 = 0;				//10任务奖励类型3
	INT32 TaskAwardTypeID3 = 0;				//10任务奖励类型3ID
	INT32 TaskAwardNum3 = 0;				//10任务奖励数量3
	TStr PreviewTime = "";				//预开启时间
	TStr StartTime = "";				//正式开启时间
	TStr RewardTime = "";				//领取奖励时间
	TStr CloseTime = "";				//关闭时间
	float DoublePriceFirst = 0.0f;				//翻倍初始价格
	float DoublePriceFirstReset = 0.0f;				//翻倍重置初始价格
	TStr PointIconAtlas = "";				//积分Icon所在图集
	TStr PointIcon = "";				//积分Icon
	TStr PointEffect = "";				//积分飞跃特效
	TStr NameKey = "";				//活动名称Key
	TStr BBKey = "";				//描述内容Key
};
CreateCsvClass(table_activity);

struct table_activity_pointsT : ConfigBaseT
{
	virtual ~table_activity_pointsT()
	{
	}
	table_activity_pointsT()
	{
		FileName = "table_activity_points.csv";
		_kf =
		{
			{"NumberID",{INT_FD, &NumberID}},
			{"ActivityPointId",{INT_FD, &ActivityPointId}},
			{"Score",{INT_FD, &Score}},
			{"Type",{INT_FD, &Type}},
			{"TypeId",{INT_FD, &TypeId}},
			{"TypeNum",{INT_FD, &TypeNum}},
			{"SentPlace",{INT_FD, &SentPlace}},
			{"CurrencyType",{INT_FD, &CurrencyType}},
			{"Price",{FLOAT_FD, &Price}}
		};
	}
	virtual table_activity_pointsT* create()
	{
		return new table_activity_pointsT();
	}
	enum
	{
	};
	INT32 NumberID = 0;            //流水
	INT32 ActivityPointId = 0;				//积分奖励ID
	INT32 Score = 0;				//所需分数
	INT32 Type = 0;				//类型
	INT32 TypeId = 0;				//类型ID
	INT32 TypeNum = 0;				//类型数量
	INT32 SentPlace = 0;				//发送位置
	INT32 CurrencyType = 0;				//补买支付类型
	float Price = 0.0f;				//补买价格
};
CreateCsvClass(table_activity_points);

struct table_activity_shop1T : ConfigBaseT
{
	virtual ~table_activity_shop1T()
	{
	}
	table_activity_shop1T()
	{
		FileName = "table_activity_shop1.csv";
		_kf =
		{
			{"Number",{INT_FD, &Number}},
			{"GoodsID",{INT_FD, &GoodsID}},
			{"ActivityID",{INT_FD, &ActivityID}},
			{"PackID",{INT_FD, &PackID}},
			{"PackLimit",{INT_FD, &PackLimit}},
			{"PackName",{TSTR_FD, &PackName}},
			{"PackDiscount",{TSTR_FD, &PackDiscount}},
			{"Title",{TSTR_FD, &Title}},
			{"TargetName1",{TSTR_FD, &TargetName1}},
			{"TargetName2",{TSTR_FD, &TargetName2}},
			{"LocationID1",{INT_FD, &LocationID1}},
			{"Type1",{INT_FD, &Type1}},
			{"TypeID1",{INT_FD, &TypeID1}},
			{"Quantity1",{INT_FD, &Quantity1}},
			{"Target1",{INT_FD, &Target1}},
			{"Tips1",{INT_FD, &Tips1}},
			{"LocationID2",{INT_FD, &LocationID2}},
			{"Type2",{INT_FD, &Type2}},
			{"TypeID2",{INT_FD, &TypeID2}},
			{"Quantity2",{INT_FD, &Quantity2}},
			{"Target2",{INT_FD, &Target2}},
			{"Tips2",{INT_FD, &Tips2}},
			{"LocationID3",{INT_FD, &LocationID3}},
			{"Type3",{INT_FD, &Type3}},
			{"TypeID3",{INT_FD, &TypeID3}},
			{"Quantity3",{INT_FD, &Quantity3}},
			{"Target3",{INT_FD, &Target3}},
			{"Tips3",{INT_FD, &Tips3}},
			{"LocationID4",{INT_FD, &LocationID4}},
			{"Type4",{INT_FD, &Type4}},
			{"TypeID4",{INT_FD, &TypeID4}},
			{"Quantity4",{INT_FD, &Quantity4}},
			{"Target4",{INT_FD, &Target4}},
			{"Tips4",{INT_FD, &Tips4}},
			{"LocationID5",{INT_FD, &LocationID5}},
			{"Type5",{INT_FD, &Type5}},
			{"TypeID5",{INT_FD, &TypeID5}},
			{"Quantity5",{INT_FD, &Quantity5}},
			{"Target5",{INT_FD, &Target5}},
			{"Tips5",{INT_FD, &Tips5}},
			{"PackCurrencyType",{INT_FD, &PackCurrencyType}},
			{"PackPrice",{FLOAT_FD, &PackPrice}},
			{"AppleID",{TSTR_FD, &AppleID}},
			{"ShowTime1",{INT_FD, &ShowTime1}},
			{"ShowTime2",{INT_FD, &ShowTime2}},
			{"ShowTime3",{INT_FD, &ShowTime3}},
			{"PackNameKey",{TSTR_FD, &PackNameKey}},
			{"PackDiscountKey",{TSTR_FD, &PackDiscountKey}},
			{"TitleKey",{TSTR_FD, &TitleKey}},
			{"TargetName1Key",{TSTR_FD, &TargetName1Key}},
			{"TargetName2Key",{TSTR_FD, &TargetName2Key}},
			{"BoxTipsKey",{TSTR_FD, &BoxTipsKey}}
		};
	}
	virtual table_activity_shop1T* create()
	{
		return new table_activity_shop1T();
	}
	enum
	{
	};
	INT32 Number = 0;            //流水号
	INT32 GoodsID = 0;				//活动商店1ID
	INT32 ActivityID = 0;				//所属活动ID
	INT32 PackID = 0;				//包裹ID
	INT32 PackLimit = 0;				//包裹购买次数限制
	TStr PackName = "";				//包裹名
	TStr PackDiscount = "";				//包裹折扣显示
	TStr Title = "";				//标题
	TStr TargetName1 = "";				//目标名称1
	TStr TargetName2 = "";				//目标名称2
	INT32 LocationID1 = 0;				//位置ID1
	INT32 Type1 = 0;				//商品类型1
	INT32 TypeID1 = 0;				//类型ID1
	INT32 Quantity1 = 0;				//商品数量1
	INT32 Target1 = 0;				//发送位置1
	INT32 Tips1 = 0;				//显示tips1
	INT32 LocationID2 = 0;				//位置ID2
	INT32 Type2 = 0;				//商品类型2
	INT32 TypeID2 = 0;				//类型ID2
	INT32 Quantity2 = 0;				//商品数量2
	INT32 Target2 = 0;				//发送位置2
	INT32 Tips2 = 0;				//显示tips2
	INT32 LocationID3 = 0;				//位置ID3
	INT32 Type3 = 0;				//商品类型3
	INT32 TypeID3 = 0;				//类型ID3
	INT32 Quantity3 = 0;				//商品数量3
	INT32 Target3 = 0;				//发送位置3
	INT32 Tips3 = 0;				//显示tips3
	INT32 LocationID4 = 0;				//位置ID4
	INT32 Type4 = 0;				//商品类型4
	INT32 TypeID4 = 0;				//类型ID4
	INT32 Quantity4 = 0;				//商品数量4
	INT32 Target4 = 0;				//发送位置4
	INT32 Tips4 = 0;				//显示tips4
	INT32 LocationID5 = 0;				//位置ID5
	INT32 Type5 = 0;				//商品类型5
	INT32 TypeID5 = 0;				//类型ID5
	INT32 Quantity5 = 0;				//商品数量5
	INT32 Target5 = 0;				//发送位置5
	INT32 Tips5 = 0;				//显示tips5
	INT32 PackCurrencyType = 0;				//包裹支付类型
	float PackPrice = 0.0f;				//包裹价格
	TStr AppleID = "";				//苹果商品ID
	INT32 ShowTime1 = 0;				//第一次展示时间
	INT32 ShowTime2 = 0;				//第二次展示时间
	INT32 ShowTime3 = 0;				//第三次展示时间
	TStr PackNameKey = "";				//包裹名Key
	TStr PackDiscountKey = "";				//包裹折扣显示
	TStr TitleKey = "";				//标题Key
	TStr TargetName1Key = "";				//目标名称1Key
	TStr TargetName2Key = "";				//目标名称2Key
	TStr BoxTipsKey = "";				//宝箱Tipskey
};
CreateCsvClass(table_activity_shop1);

struct table_activity_shop2T : ConfigBaseT
{
	virtual ~table_activity_shop2T()
	{
	}
	table_activity_shop2T()
	{
		FileName = "table_activity_shop2.csv";
		_kf =
		{
			{"BagID",{INT_FD, &BagID}},
			{"ActivityID",{INT_FD, &ActivityID}},
			{"ArticleID",{INT_FD, &ArticleID}},
			{"ScoreNum",{TSTR_FD, &ScoreNum}},
			{"BagICurrencyType",{INT_FD, &BagICurrencyType}},
			{"BagPrice",{INT_FD, &BagPrice}},
			{"AppleID",{TSTR_FD, &AppleID}},
			{"ShowTime",{INT_FD, &ShowTime}},
			{"FreeCD",{INT_FD, &FreeCD}},
			{"Type1",{INT_FD, &Type1}},
			{"Type1ID",{INT_FD, &Type1ID}},
			{"Type2",{INT_FD, &Type2}},
			{"Type2ID",{INT_FD, &Type2ID}},
			{"Text1",{TSTR_FD, &Text1}},
			{"Text2",{TSTR_FD, &Text2}},
			{"Text3",{TSTR_FD, &Text3}},
			{"TipText2",{TSTR_FD, &TipText2}},
			{"TipText1",{TSTR_FD, &TipText1}},
			{"Award1Percent",{TSTR_FD, &Award1Percent}},
			{"Award1NameKey",{TSTR_FD, &Award1NameKey}},
			{"Award1Name",{TSTR_FD, &Award1Name}},
			{"Award2Percent",{TSTR_FD, &Award2Percent}},
			{"Award2NameKey",{TSTR_FD, &Award2NameKey}},
			{"Award2Name",{TSTR_FD, &Award2Name}},
			{"Award3Percent",{TSTR_FD, &Award3Percent}},
			{"Award3NameKey",{TSTR_FD, &Award3NameKey}},
			{"Award3Name",{TSTR_FD, &Award3Name}},
			{"Award4Percent",{TSTR_FD, &Award4Percent}},
			{"Award4NameKey",{TSTR_FD, &Award4NameKey}},
			{"Award4Name",{TSTR_FD, &Award4Name}},
			{"Award5Percent",{TSTR_FD, &Award5Percent}},
			{"Award5NameKey",{TSTR_FD, &Award5NameKey}},
			{"Award5Name",{TSTR_FD, &Award5Name}},
			{"Award6Percent",{TSTR_FD, &Award6Percent}},
			{"Award6NameKey",{TSTR_FD, &Award6NameKey}},
			{"Award6Name",{TSTR_FD, &Award6Name}},
			{"Award7Percent",{TSTR_FD, &Award7Percent}},
			{"Award7NameKey",{TSTR_FD, &Award7NameKey}},
			{"Award7Name",{TSTR_FD, &Award7Name}},
			{"Award8Percent",{TSTR_FD, &Award8Percent}},
			{"Award8NameKey",{TSTR_FD, &Award8NameKey}},
			{"Award8Name",{TSTR_FD, &Award8Name}},
			{"Award9Percent",{TSTR_FD, &Award9Percent}},
			{"Award9NameKey",{TSTR_FD, &Award9NameKey}},
			{"Award9Name",{TSTR_FD, &Award9Name}},
			{"Award10Percent",{TSTR_FD, &Award10Percent}},
			{"Award10NameKey",{TSTR_FD, &Award10NameKey}},
			{"Award10Name",{TSTR_FD, &Award10Name}},
			{"Text1Key",{TSTR_FD, &Text1Key}},
			{"Text2Key",{TSTR_FD, &Text2Key}},
			{"Text3Key",{TSTR_FD, &Text3Key}},
			{"TipText1Key",{TSTR_FD, &TipText1Key}},
			{"TipText2Key",{TSTR_FD, &TipText2Key}}
		};
	}
	virtual table_activity_shop2T* create()
	{
		return new table_activity_shop2T();
	}
	enum
	{
	};
	INT32 BagID = 0;            //锦囊ID
	INT32 ActivityID = 0;				//所属活动ID
	INT32 ArticleID = 0;				//获得道具ID
	TStr ScoreNum = "";				//必得积分
	INT32 BagICurrencyType = 0;				//锦囊支付类型
	INT32 BagPrice = 0;				//锦囊价格
	TStr AppleID = "";				//苹果商品ID
	INT32 ShowTime = 0;				//展示时间
	INT32 FreeCD = 0;				//免费冷却
	INT32 Type1 = 0;				//预览奖励1类型
	INT32 Type1ID = 0;				//预览奖励1ID
	INT32 Type2 = 0;				//预览奖励2类型
	INT32 Type2ID = 0;				//预览奖励2ID
	TStr Text1 = "";				//提示1
	TStr Text2 = "";				//提示2
	TStr Text3 = "";				//提示3
	TStr TipText2 = "";				//信息提示文字2
	TStr TipText1 = "";				//信息提示文字1
	TStr Award1Percent = "";				//奖品1
几率
	TStr Award1NameKey = "";				//奖品1
名字Key
	TStr Award1Name = "";				//奖品1
名字
	TStr Award2Percent = "";				//奖品2
几率
	TStr Award2NameKey = "";				//奖品2
名字Key
	TStr Award2Name = "";				//奖品2
名字
	TStr Award3Percent = "";				//奖品3
几率
	TStr Award3NameKey = "";				//奖品3
名字Key
	TStr Award3Name = "";				//奖品3
名字
	TStr Award4Percent = "";				//奖品4
几率
	TStr Award4NameKey = "";				//奖品4
名字Key
	TStr Award4Name = "";				//奖品4
名字
	TStr Award5Percent = "";				//奖品5
几率
	TStr Award5NameKey = "";				//奖品5
名字Key
	TStr Award5Name = "";				//奖品5
名字
	TStr Award6Percent = "";				//奖品6
几率
	TStr Award6NameKey = "";				//奖品6
名字Key
	TStr Award6Name = "";				//奖品6
名字
	TStr Award7Percent = "";				//奖品7
几率
	TStr Award7NameKey = "";				//奖品7
名字Key
	TStr Award7Name = "";				//奖品7
名字
	TStr Award8Percent = "";				//奖品8
几率
	TStr Award8NameKey = "";				//奖品8
名字Key
	TStr Award8Name = "";				//奖品8
名字
	TStr Award9Percent = "";				//奖品9
几率
	TStr Award9NameKey = "";				//奖品9
名字Key
	TStr Award9Name = "";				//奖品9
名字
	TStr Award10Percent = "";				//奖品10
几率
	TStr Award10NameKey = "";				//奖品10
名字Key
	TStr Award10Name = "";				//奖品10
名字
	TStr Text1Key = "";				//提示1Key
	TStr Text2Key = "";				//提示2Key
	TStr Text3Key = "";				//提示3Key
	TStr TipText1Key = "";				//信息提示文字1Key
	TStr TipText2Key = "";				//信息提示文字2Key
};
CreateCsvClass(table_activity_shop2);

struct table_advertisementT : ConfigBaseT
{
	virtual ~table_advertisementT()
	{
	}
	table_advertisementT()
	{
		FileName = "table_advertisement.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"AdAffectType",{INT_FD, &AdAffectType}},
			{"Advertisement",{TSTR_FD, &Advertisement}},
			{"MaxTime",{INT_FD, &MaxTime}},
			{"CD",{INT_FD, &CD}},
			{"EffectNum1",{FLOAT_FD, &EffectNum1}},
			{"EffectNum2",{FLOAT_FD, &EffectNum2}}
		};
	}
	virtual table_advertisementT* create()
	{
		return new table_advertisementT();
	}
	enum
	{
	};
	INT32 ID = 0;            //广告ID
	INT32 AdAffectType = 0;				//广告类型
	TStr Advertisement = "";				//广告类型
	INT32 MaxTime = 0;				//日最大限定次数
	INT32 CD = 0;				//每次触发后的固有CD
	float EffectNum1 = 0.0f;				//参数1
	float EffectNum2 = 0.0f;				//参数2
};
CreateCsvClass(table_advertisement);

struct table_advertisement_awardT : ConfigBaseT
{
	virtual ~table_advertisement_awardT()
	{
	}
	table_advertisement_awardT()
	{
		FileName = "table_advertisement_award.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"AdvertisementGroupID",{INT_FD, &AdvertisementGroupID}},
			{"RanGroupID",{INT_FD, &RanGroupID}},
			{"JudgeValue",{INT_FD, &JudgeValue}},
			{"Weight",{INT_FD, &Weight}},
			{"ArticleType",{INT_FD, &ArticleType}},
			{"Article",{INT_FD, &Article}},
			{"ProductMin",{INT_FD, &ProductMin}},
			{"ProductMax",{INT_FD, &ProductMax}}
		};
	}
	virtual table_advertisement_awardT* create()
	{
		return new table_advertisement_awardT();
	}
	enum
	{
	};
	INT32 ID = 0;            //流水
	INT32 AdvertisementGroupID = 0;				//规则组ID
	INT32 RanGroupID = 0;				//随机组ID
	INT32 JudgeValue = 0;				//判定数值
	INT32 Weight = 0;				//组内随机权重
	INT32 ArticleType = 0;				//道具类型
	INT32 Article = 0;				//需求道具
	INT32 ProductMin = 0;				//MIN值
	INT32 ProductMax = 0;				//MAX值
};
CreateCsvClass(table_advertisement_award);

struct table_advertisement_layeredT : ConfigBaseT
{
	virtual ~table_advertisement_layeredT()
	{
	}
	table_advertisement_layeredT()
	{
		FileName = "table_advertisement_layered.csv";
		_kf =
		{
			{"Number",{INT_FD, &Number}},
			{"UserType",{TSTR_FD, &UserType}},
			{"Tactics",{INT_FD, &Tactics}},
			{"Para1",{FLOAT_FD, &Para1}},
			{"Para2",{FLOAT_FD, &Para2}},
			{"Para3",{FLOAT_FD, &Para3}},
			{"Para4",{FLOAT_FD, &Para4}},
			{"Para5",{FLOAT_FD, &Para5}}
		};
	}
	virtual table_advertisement_layeredT* create()
	{
		return new table_advertisement_layeredT();
	}
	enum
	{
	};
	INT32 Number = 0;            //流水号
	TStr UserType = "";				//用户类别
	INT32 Tactics = 0;				//策略1
	float Para1 = 0.0f;				//参数1
	float Para2 = 0.0f;				//参数2
	float Para3 = 0.0f;				//参数3
	float Para4 = 0.0f;				//参数4
	float Para5 = 0.0f;				//参数5
};
CreateCsvClass(table_advertisement_layered);

struct table_articleT : ConfigBaseT
{
	virtual ~table_articleT()
	{
	}
	table_articleT()
	{
		FileName = "table_article.csv";
		_kf =
		{
			{"ArticleId",{INT_FD, &ArticleId}},
			{"Name",{TSTR_FD, &Name}},
			{"Image",{TSTR_FD, &Image}},
			{"Annotation",{TSTR_FD, &Annotation}},
			{"Descript",{TSTR_FD, &Descript}},
			{"ArticleLevel",{INT_FD, &ArticleLevel}},
			{"ArticleQuality",{INT_FD, &ArticleQuality}},
			{"EnableMove",{INT_FD, &EnableMove}},
			{"HomePrice",{INT_FD, &HomePrice}},
			{"LevelPrice",{INT_FD, &LevelPrice}},
			{"EnableMerge",{INT_FD, &EnableMerge}},
			{"ShowType",{INT_FD, &ShowType}},
			{"StealLimit",{INT_FD, &StealLimit}},
			{"SizeWidth",{INT_FD, &SizeWidth}},
			{"SizeHeight",{INT_FD, &SizeHeight}},
			{"ArticleType",{INT_FD, &ArticleType}},
			{"ArticleFunction",{INT_FD, &ArticleFunction}},
			{"AiConfig",{TSTR_FD, &AiConfig}},
			{"Score",{INT_FD, &Score}},
			{"DeathcellAI",{INT_FD, &DeathcellAI}},
			{"Guide",{INT_FD, &Guide}},
			{"SurvivalTimeMin",{FLOAT_FD, &SurvivalTimeMin}},
			{"SurvivalTimeMax",{FLOAT_FD, &SurvivalTimeMax}},
			{"SurvivalDropProbability",{FLOAT_FD, &SurvivalDropProbability}},
			{"SurvivalTimeDropId",{INT_FD, &SurvivalTimeDropId}},
			{"LevelAppear",{INT_FD, &LevelAppear}},
			{"AwardType",{INT_FD, &AwardType}},
			{"Award",{INT_FD, &Award}},
			{"BuildId",{INT_FD, &BuildId}},
			{"BuildDragonCount",{INT_FD, &BuildDragonCount}},
			{"BuildTime",{FLOAT_FD, &BuildTime}},
			{"BuildImmediatelyPrice",{INT_FD, &BuildImmediatelyPrice}},
			{"GoldUpperLimit",{INT_FD, &GoldUpperLimit}},
			{"OreUpperLimit",{INT_FD, &OreUpperLimit}},
			{"ResetTime",{INT_FD, &ResetTime}},
			{"UnLockSleepPrice",{INT_FD, &UnLockSleepPrice}},
			{"UnLockWaitSleepPrice",{INT_FD, &UnLockWaitSleepPrice}},
			{"HeroResetTime",{INT_FD, &HeroResetTime}},
			{"HeroUnLockSleepPrice",{INT_FD, &HeroUnLockSleepPrice}},
			{"ReceiptGroup",{INT_FD, &ReceiptGroup}},
			{"Exp",{INT_FD, &Exp}},
			{"UpResetTime",{INT_FD, &UpResetTime}},
			{"UpUnLockSleepPrice",{INT_FD, &UpUnLockSleepPrice}},
			{"VideoTime",{INT_FD, &VideoTime}},
			{"ExpUpgradeID",{INT_FD, &ExpUpgradeID}},
			{"CreatureID",{INT_FD, &CreatureID}},
			{"ReceiptChangeType",{INT_FD, &ReceiptChangeType}},
			{"ReceiptChangeCost",{INT_FD, &ReceiptChangeCost}},
			{"ReceiptCD",{INT_FD, &ReceiptCD}},
			{"CostType",{INT_FD, &CostType}},
			{"Cost",{INT_FD, &Cost}},
			{"UpgradeID",{INT_FD, &UpgradeID}},
			{"UpgradeDropId",{INT_FD, &UpgradeDropId}},
			{"UpgradeType",{TSTR_FD, &UpgradeType}},
			{"TreasureDropId1",{INT_FD, &TreasureDropId1}},
			{"TreasureUnLockCostType1",{INT_FD, &TreasureUnLockCostType1}},
			{"TreasureUnLockCost1",{INT_FD, &TreasureUnLockCost1}},
			{"TreasureDropId2",{INT_FD, &TreasureDropId2}},
			{"TreasureUnLockCostType2",{INT_FD, &TreasureUnLockCostType2}},
			{"TreasureUnLockCost2",{INT_FD, &TreasureUnLockCost2}},
			{"TreasureDropId3",{INT_FD, &TreasureDropId3}},
			{"TreasureUnLockCostType3",{INT_FD, &TreasureUnLockCostType3}},
			{"TreasureUnLockCost3",{INT_FD, &TreasureUnLockCost3}},
			{"TreasureDropId4",{INT_FD, &TreasureDropId4}},
			{"TreasureUnLockCostType4",{INT_FD, &TreasureUnLockCostType4}},
			{"TreasureUnLockCost4",{INT_FD, &TreasureUnLockCost4}},
			{"TreasureDropId5",{INT_FD, &TreasureDropId5}},
			{"TreasureUnLockCostType5",{INT_FD, &TreasureUnLockCostType5}},
			{"TreasureUnLockCost5",{INT_FD, &TreasureUnLockCost5}},
			{"ClickDropProbability1",{FLOAT_FD, &ClickDropProbability1}},
			{"ClickDropId1",{INT_FD, &ClickDropId1}},
			{"ClickProductCD1",{FLOAT_FD, &ClickProductCD1}},
			{"ClickMin1",{INT_FD, &ClickMin1}},
			{"ClickMax1",{INT_FD, &ClickMax1}},
			{"ClickDieType1",{INT_FD, &ClickDieType1}},
			{"ClickLimitDestroy1",{INT_FD, &ClickLimitDestroy1}},
			{"ClickDeadDropProbability1",{FLOAT_FD, &ClickDeadDropProbability1}},
			{"ClickDeadDrop1",{INT_FD, &ClickDeadDrop1}},
			{"ClickDropProbability2",{FLOAT_FD, &ClickDropProbability2}},
			{"ClickDropId2",{INT_FD, &ClickDropId2}},
			{"ClickProductCD2",{FLOAT_FD, &ClickProductCD2}},
			{"ClickMin2",{INT_FD, &ClickMin2}},
			{"ClickMax2",{INT_FD, &ClickMax2}},
			{"ClickDieType2",{INT_FD, &ClickDieType2}},
			{"ClickLimitDestroy2",{INT_FD, &ClickLimitDestroy2}},
			{"ClickDeadDropProbability2",{FLOAT_FD, &ClickDeadDropProbability2}},
			{"ClickDeadDrop2",{INT_FD, &ClickDeadDrop2}},
			{"ClickTutorial",{INT_FD, &ClickTutorial}},
			{"TimeDropProbability1",{FLOAT_FD, &TimeDropProbability1}},
			{"TimeDropId1",{INT_FD, &TimeDropId1}},
			{"TimeDropPlaceType1",{INT_FD, &TimeDropPlaceType1}},
			{"TimeMin1",{FLOAT_FD, &TimeMin1}},
			{"TimeMax1",{FLOAT_FD, &TimeMax1}},
			{"TimeAvalid1",{FLOAT_FD, &TimeAvalid1}},
			{"TimeCD1",{FLOAT_FD, &TimeCD1}},
			{"TimeBodyLimit1",{INT_FD, &TimeBodyLimit1}},
			{"TimeTotalLimit1",{INT_FD, &TimeTotalLimit1}},
			{"TimeRanLimit1",{INT_FD, &TimeRanLimit1}},
			{"TimeDieCount1",{INT_FD, &TimeDieCount1}},
			{"TimeShow1",{INT_FD, &TimeShow1}},
			{"TimeDropProbability2",{FLOAT_FD, &TimeDropProbability2}},
			{"TimeDropId2",{INT_FD, &TimeDropId2}},
			{"TimeDropPlaceType2",{INT_FD, &TimeDropPlaceType2}},
			{"TimeMin2",{FLOAT_FD, &TimeMin2}},
			{"TimeMax2",{FLOAT_FD, &TimeMax2}},
			{"TimeAvalid2",{FLOAT_FD, &TimeAvalid2}},
			{"TimeCD2",{FLOAT_FD, &TimeCD2}},
			{"TimeBodyLimit2",{INT_FD, &TimeBodyLimit2}},
			{"TimeTotalLimit2",{INT_FD, &TimeTotalLimit2}},
			{"TimeRanLimit2",{INT_FD, &TimeRanLimit2}},
			{"TimeDieCount2",{INT_FD, &TimeDieCount2}},
			{"TimeShow2",{INT_FD, &TimeShow2}},
			{"CollectProbability",{FLOAT_FD, &CollectProbability}},
			{"CollectDropId",{INT_FD, &CollectDropId}},
			{"CollectTime",{FLOAT_FD, &CollectTime}},
			{"CollectRecoverMin",{FLOAT_FD, &CollectRecoverMin}},
			{"CollectRecoverMax",{FLOAT_FD, &CollectRecoverMax}},
			{"CollectDragonCount",{INT_FD, &CollectDragonCount}},
			{"CollectTimesMin",{INT_FD, &CollectTimesMin}},
			{"CollectTimesMax",{INT_FD, &CollectTimesMax}},
			{"CollectEndType",{INT_FD, &CollectEndType}},
			{"CollectType",{INT_FD, &CollectType}},
			{"CollectLessen",{INT_FD, &CollectLessen}},
			{"CollectDeadDrop",{INT_FD, &CollectDeadDrop}},
			{"AttackDamage",{INT_FD, &AttackDamage}},
			{"AttackUpperLimit",{INT_FD, &AttackUpperLimit}},
			{"AttackDropProbability",{FLOAT_FD, &AttackDropProbability}},
			{"AttackDropId",{INT_FD, &AttackDropId}},
			{"CallDragonGroup",{INT_FD, &CallDragonGroup}},
			{"CallDragonCount",{INT_FD, &CallDragonCount}},
			{"ClickUnLockCell",{INT_FD, &ClickUnLockCell}},
			{"ClickUnLockCellDelay",{FLOAT_FD, &ClickUnLockCellDelay}},
			{"BatteryDistanceMin",{INT_FD, &BatteryDistanceMin}},
			{"BatteryDistanceMax",{INT_FD, &BatteryDistanceMax}},
			{"BatteryRange",{INT_FD, &BatteryRange}},
			{"BatteryTime",{FLOAT_FD, &BatteryTime}},
			{"BatteryHealing",{INT_FD, &BatteryHealing}},
			{"BatteryVeer",{INT_FD, &BatteryVeer}},
			{"PolluteTime",{FLOAT_FD, &PolluteTime}},
			{"UIShow",{TSTR_FD, &UIShow}},
			{"BatteryShellImage",{TSTR_FD, &BatteryShellImage}},
			{"BatteryHitImage",{TSTR_FD, &BatteryHitImage}},
			{"BatterySendSound",{TSTR_FD, &BatterySendSound}},
			{"TimeDropEffect1Location",{TSTR_FD, &TimeDropEffect1Location}},
			{"TimeDropEffect1",{TSTR_FD, &TimeDropEffect1}},
			{"ReceiveEffectLocation",{TSTR_FD, &ReceiveEffectLocation}},
			{"ReceiveEffect",{TSTR_FD, &ReceiveEffect}},
			{"TimeDropEffect2",{TSTR_FD, &TimeDropEffect2}},
			{"TimeDropEffect2Location",{TSTR_FD, &TimeDropEffect2Location}},
			{"TimeDropEffect3Location",{TSTR_FD, &TimeDropEffect3Location}},
			{"TimeDropEffect3",{TSTR_FD, &TimeDropEffect3}},
			{"EnableClickEffectLocation",{TSTR_FD, &EnableClickEffectLocation}},
			{"EnableClickEffect",{TSTR_FD, &EnableClickEffect}},
			{"ClickEffectLocation",{TSTR_FD, &ClickEffectLocation}},
			{"ClickEffect",{TSTR_FD, &ClickEffect}},
			{"ClickTureEffectLocation",{TSTR_FD, &ClickTureEffectLocation}},
			{"ClickTureEffect",{TSTR_FD, &ClickTureEffect}},
			{"BuildEffectLocation",{TSTR_FD, &BuildEffectLocation}},
			{"BuildEffect",{TSTR_FD, &BuildEffect}},
			{"BuildAffirmEffectLocation",{TSTR_FD, &BuildAffirmEffectLocation}},
			{"BuildAffirmEffect",{TSTR_FD, &BuildAffirmEffect}},
			{"CollectEffectLocation",{TSTR_FD, &CollectEffectLocation}},
			{"CollectEffect",{TSTR_FD, &CollectEffect}},
			{"CollectAffirmEffectLocation",{TSTR_FD, &CollectAffirmEffectLocation}},
			{"CollectAffirmEffect",{TSTR_FD, &CollectAffirmEffect}},
			{"BornEffectLocation",{TSTR_FD, &BornEffectLocation}},
			{"BornEffect",{TSTR_FD, &BornEffect}},
			{"DeadKillEffectLocation",{TSTR_FD, &DeadKillEffectLocation}},
			{"DeadKillEffect",{TSTR_FD, &DeadKillEffect}},
			{"DeadTimeEffectLocation",{TSTR_FD, &DeadTimeEffectLocation}},
			{"DeadTimeEffect",{TSTR_FD, &DeadTimeEffect}},
			{"SellEffectLocation",{TSTR_FD, &SellEffectLocation}},
			{"SellEffect",{TSTR_FD, &SellEffect}},
			{"DestroyEffectLocation",{TSTR_FD, &DestroyEffectLocation}},
			{"DestroyEffect",{TSTR_FD, &DestroyEffect}},
			{"Location",{TSTR_FD, &Location}},
			{"BoxUnlockEffect",{TSTR_FD, &BoxUnlockEffect}},
			{"BoxOpenEffectLocation",{TSTR_FD, &BoxOpenEffectLocation}},
			{"BoxOpenEffect",{TSTR_FD, &BoxOpenEffect}},
			{"BoxUnlockEffectLocation",{TSTR_FD, &BoxUnlockEffectLocation}},
			{"BoxWaitUnlockEffect",{TSTR_FD, &BoxWaitUnlockEffect}},
			{"BoxUnlockImageLocation",{TSTR_FD, &BoxUnlockImageLocation}},
			{"BoxUnlockImage",{TSTR_FD, &BoxUnlockImage}},
			{"StandbyEffectLocation",{TSTR_FD, &StandbyEffectLocation}},
			{"StandbyEffect",{TSTR_FD, &StandbyEffect}},
			{"CrossEffectLocation",{TSTR_FD, &CrossEffectLocation}},
			{"CrossEffect",{TSTR_FD, &CrossEffect}},
			{"HeroLvupLocation",{TSTR_FD, &HeroLvupLocation}},
			{"HeroLvup",{TSTR_FD, &HeroLvup}},
			{"UpEffectLocation",{TSTR_FD, &UpEffectLocation}},
			{"UpEffect",{TSTR_FD, &UpEffect}},
			{"BerestingEffectLocation",{TSTR_FD, &BerestingEffectLocation}},
			{"BerestingEffect",{TSTR_FD, &BerestingEffect}},
			{"LevelTargetEffectLocation",{TSTR_FD, &LevelTargetEffectLocation}},
			{"LevelTargetEffect",{TSTR_FD, &LevelTargetEffect}},
			{"SoundClick",{TSTR_FD, &SoundClick}},
			{"SelectSound",{TSTR_FD, &SelectSound}},
			{"CollectSound",{TSTR_FD, &CollectSound}},
			{"CollectSoundGroupCount",{INT_FD, &CollectSoundGroupCount}},
			{"UnlockchestSound",{TSTR_FD, &UnlockchestSound}},
			{"OpenchestSound",{TSTR_FD, &OpenchestSound}},
			{"DeleteSound",{TSTR_FD, &DeleteSound}},
			{"DestorySound",{TSTR_FD, &DestorySound}},
			{"ActcofSound",{TSTR_FD, &ActcofSound}},
			{"PutdownSound",{TSTR_FD, &PutdownSound}},
			{"AppearSound",{TSTR_FD, &AppearSound}},
			{"BuildingSound",{TSTR_FD, &BuildingSound}},
			{"BuildSoundGroupCount",{INT_FD, &BuildSoundGroupCount}},
			{"ProducingSound1",{TSTR_FD, &ProducingSound1}},
			{"ProducingSound2",{TSTR_FD, &ProducingSound2}},
			{"RewardquaSound",{TSTR_FD, &RewardquaSound}},
			{"CallDragon",{TSTR_FD, &CallDragon}},
			{"CallDragonback",{TSTR_FD, &CallDragonback}},
			{"PopUpSound",{TSTR_FD, &PopUpSound}},
			{"ComboSound",{TSTR_FD, &ComboSound}},
			{"UIModel",{TSTR_FD, &UIModel}},
			{"Namekey",{TSTR_FD, &Namekey}},
			{"DescriptKey",{TSTR_FD, &DescriptKey}}
		};
	}
	virtual table_articleT* create()
	{
		return new table_articleT();
	}
	enum
	{
	};
	INT32 ArticleId = 0;            //道具ID
	TStr Name = "";				//名称
	TStr Image = "";				//图片
	TStr Annotation = "";				//备注
	TStr Descript = "";				//描述
	INT32 ArticleLevel = 0;				//【基础属性】
等级
	INT32 ArticleQuality = 0;				//【基础属性】
品质
	INT32 EnableMove = 0;				//【基础属性】
是否可移动
	INT32 HomePrice = 0;				//【基础属性】
家园出售属性
	INT32 LevelPrice = 0;				//【基础属性】
关卡出售属性
	INT32 EnableMerge = 0;				//【基础属性】
是否可合成
	INT32 ShowType = 0;				//【基础属性】
显示方法
	INT32 StealLimit = 0;				//【基础属性】
是否可被偷取
	INT32 SizeWidth = 0;				//【尺寸】
长
	INT32 SizeHeight = 0;				//【尺寸】
宽
	INT32 ArticleType = 0;				//【道具类型】
	INT32 ArticleFunction = 0;				//【道具功能】
	TStr AiConfig = "";				//【AI】
	INT32 Score = 0;				//【合成】
积分值
	INT32 DeathcellAI = 0;				//【死地上AI开关】
	INT32 Guide = 0;				//【指引脚本】
	float SurvivalTimeMin = 0.0f;				//【基础属性】
生存时间Min
	float SurvivalTimeMax = 0.0f;				//【基础属性】
生存时间Max
	float SurvivalDropProbability = 0.0f;				//【时间消失】
掉落几率
	INT32 SurvivalTimeDropId = 0;				//【时间消失】
掉落ID
	INT32 LevelAppear = 0;				//【关卡属性】
是否允许被关卡结算选中
	INT32 AwardType = 0;				//【关卡属性】
关卡付费
奖励价格
	INT32 Award = 0;				//【关卡属性】
关卡付费
奖励价格
	INT32 BuildId = 0;				//【建造】
后道具ID
	INT32 BuildDragonCount = 0;				//【建造】
同时建造龙数
	float BuildTime = 0.0f;				//【建造】
建造时间
	INT32 BuildImmediatelyPrice = 0;				//【建造】
秒建造时间所需钻石
	INT32 GoldUpperLimit = 0;				//【金币屋】
金币上限
	INT32 OreUpperLimit = 0;				//【矿石屋】
矿石上限
	INT32 ResetTime = 0;				//【龙屋】
休息时间
	INT32 UnLockSleepPrice = 0;				//【龙屋】
正在休息龙
1钻石对应时间
	INT32 UnLockWaitSleepPrice = 0;				//【龙屋】
等待休息龙
1钻石对应时间
	INT32 HeroResetTime = 0;				//【英雄】
休息时间
	INT32 HeroUnLockSleepPrice = 0;				//【英雄祭坛】
1钻石对应时间
	INT32 ReceiptGroup = 0;				//当前等级祭坛
调用订单组ID
	INT32 Exp = 0;				//升级需求经验值
-1表示无法升级
	INT32 UpResetTime = 0;				//升级所需时间
	INT32 UpUnLockSleepPrice = 0;				//【英雄升级】
1钻石对应时间
	INT32 VideoTime = 0;				//观看广告减少时间
	INT32 ExpUpgradeID = 0;				//经验升级后跳转道具ID
	INT32 CreatureID = 0;				//英雄生物ID 
	INT32 ReceiptChangeType = 0;				//更换订单
花费类型【废弃】
	INT32 ReceiptChangeCost = 0;				//【寺庙】
消耗值【废弃】
	INT32 ReceiptCD = 0;				//订单CD
英雄祭坛专用【废弃】
	INT32 CostType = 0;				//【寺庙】
消耗类型
	INT32 Cost = 0;				//【寺庙】
消耗值
	INT32 UpgradeID = 0;				//【寺庙】
升级后道具ID
	INT32 UpgradeDropId = 0;				//【寺庙】
升级奖励掉落ID
	TStr UpgradeType = "";				//【寺庙】
升级表现
	INT32 TreasureDropId1 = 0;				//【宝箱1】
掉落ID
	INT32 TreasureUnLockCostType1 = 0;				//【宝箱1】
解锁消耗类型
	INT32 TreasureUnLockCost1 = 0;				//【宝箱1】
消耗值
	INT32 TreasureDropId2 = 0;				//【宝箱2】
掉落ID
	INT32 TreasureUnLockCostType2 = 0;				//【宝箱2】
解锁消耗类型
	INT32 TreasureUnLockCost2 = 0;				//【宝箱2】
消耗值
	INT32 TreasureDropId3 = 0;				//【宝箱3】
掉落ID
	INT32 TreasureUnLockCostType3 = 0;				//【宝箱3】
解锁消耗类型
	INT32 TreasureUnLockCost3 = 0;				//【宝箱3】
消耗值
	INT32 TreasureDropId4 = 0;				//【宝箱4】
掉落ID
	INT32 TreasureUnLockCostType4 = 0;				//【宝箱4】
解锁消耗类型
	INT32 TreasureUnLockCost4 = 0;				//【宝箱4】
消耗值
	INT32 TreasureDropId5 = 0;				//【宝箱5】
掉落ID
	INT32 TreasureUnLockCostType5 = 0;				//【宝箱5】
解锁消耗类型
	INT32 TreasureUnLockCost5 = 0;				//【宝箱5】
消耗值
	float ClickDropProbability1 = 0.0f;				//【点击1】
掉落几率
	INT32 ClickDropId1 = 0;				//【点击1】
掉落id
	float ClickProductCD1 = 0.0f;				//【点击1】
产出cd
	INT32 ClickMin1 = 0;				//【点击1】
次数Min
	INT32 ClickMax1 = 0;				//【点击1】
次数Max
	INT32 ClickDieType1 = 0;				//【点击1】
消亡类型
	INT32 ClickLimitDestroy1 = 0;				//【点击1】
达到次数
后消亡
	float ClickDeadDropProbability1 = 0.0f;				//【点击1】
达到次数
后消亡时掉落几率
	INT32 ClickDeadDrop1 = 0;				//【点击1】
达到次数
后消亡时掉落ID
	float ClickDropProbability2 = 0.0f;				//【点击2】
掉落几率
	INT32 ClickDropId2 = 0;				//【点击2】
掉落id
	float ClickProductCD2 = 0.0f;				//【点击2】
产出cd
	INT32 ClickMin2 = 0;				//【点击2】
次数Min
	INT32 ClickMax2 = 0;				//【点击2】
次数Max
	INT32 ClickDieType2 = 0;				//【点击2】
消亡类型
	INT32 ClickLimitDestroy2 = 0;				//【点击2】
达到次数
是否消亡
	float ClickDeadDropProbability2 = 0.0f;				//【点击2】
达到次数
后消亡时掉落几率
	INT32 ClickDeadDrop2 = 0;				//【点击2】
达到次数
后消亡时掉落
	INT32 ClickTutorial = 0;				//【新手引导】
填写唯一的关卡ID
	float TimeDropProbability1 = 0.0f;				//【时间1】
掉落几率
	INT32 TimeDropId1 = 0;				//【时间1】
掉落id
	INT32 TimeDropPlaceType1 = 0;				//【时间1】
产出类型
	float TimeMin1 = 0.0f;				//【时间1】
产出时间Min
	float TimeMax1 = 0.0f;				//【时间1】
产出时间Max
	float TimeAvalid1 = 0.0f;				//【时间1】
产出有效总时间
	float TimeCD1 = 0.0f;				//【时间1】
产出CD时间
	INT32 TimeBodyLimit1 = 0;				//【时间1】
身上上限
	INT32 TimeTotalLimit1 = 0;				//【时间1】
内部上限
	INT32 TimeRanLimit1 = 0;				//【时间1】
限制次数
	INT32 TimeDieCount1 = 0;				//【时间1】
消亡次数
	INT32 TimeShow1 = 0;				//显示
	float TimeDropProbability2 = 0.0f;				//【时间2】
掉落几率
	INT32 TimeDropId2 = 0;				//【时间2】
掉落id
	INT32 TimeDropPlaceType2 = 0;				//【时间2】
产出类型
	float TimeMin2 = 0.0f;				//【时间2】
产出时间Min
	float TimeMax2 = 0.0f;				//【时间2】
产出时间Max
	float TimeAvalid2 = 0.0f;				//【时间2】
产出有效总时间
	float TimeCD2 = 0.0f;				//【时间2】
产出CD时间
	INT32 TimeBodyLimit2 = 0;				//【时间2】
身上上限
	INT32 TimeTotalLimit2 = 0;				//【时间2】
内部上限
	INT32 TimeRanLimit2 = 0;				//【时间2】
限制次数
	INT32 TimeDieCount2 = 0;				//【时间2】
消亡次数
	INT32 TimeShow2 = 0;				//【时间2】
显示
	float CollectProbability = 0.0f;				//【采集】
掉落几率
	INT32 CollectDropId = 0;				//【采集】
掉落id
	float CollectTime = 0.0f;				//【采集】
采集时间
	float CollectRecoverMin = 0.0f;				//【采集】
恢复时间Min
	float CollectRecoverMax = 0.0f;				//【采集】
恢复时间Max
	INT32 CollectDragonCount = 0;				//【采集】
同时龙数量
	INT32 CollectTimesMin = 0;				//【采集】
次数Min
	INT32 CollectTimesMax = 0;				//【采集】
次数Max
	INT32 CollectEndType = 0;				//【采集】
次数到时处理
	INT32 CollectType = 0;				//【采集】
显示方式
	INT32 CollectLessen = 0;				//【采集】
缩小类型
	INT32 CollectDeadDrop = 0;				//【采集】
达到次数
后消亡时掉落
	INT32 AttackDamage = 0;				//【击杀】
血量
	INT32 AttackUpperLimit = 0;				//【击杀】
受击个数上限
	float AttackDropProbability = 0.0f;				//【击杀】
掉落几率
	INT32 AttackDropId = 0;				//【击杀】
掉落id
	INT32 CallDragonGroup = 0;				//【巨龙之门】
召唤组ID
	INT32 CallDragonCount = 0;				//【巨龙之门】
召唤数量
	INT32 ClickUnLockCell = 0;				//【点击直接解锁地块】
 数量
	float ClickUnLockCellDelay = 0.0f;				//【点击直接解锁地块】
 延迟时间
	INT32 BatteryDistanceMin = 0;				//【炮塔】
攻击圈数Min
	INT32 BatteryDistanceMax = 0;				//【炮塔】
攻击圈数Max
	INT32 BatteryRange = 0;				//【炮塔】
溅射范围
	float BatteryTime = 0.0f;				//【炮塔】
攻击频率
	INT32 BatteryHealing = 0;				//【炮塔】
给予治愈值
	INT32 BatteryVeer = 0;				//【炮塔】
是否转向
	float PolluteTime = 0.0f;				//【被污染时
时间修正系数】
	TStr UIShow = "";				//UI弹窗使用资源
	TStr BatteryShellImage = "";				//【炮塔】
子弹资源
	TStr BatteryHitImage = "";				//【炮塔】
命中特效
	TStr BatterySendSound = "";				//【炮塔】
开炮声音
	TStr TimeDropEffect1Location = "";				//【时间】
挂载位置：产出物
上持续特效位置
	TStr TimeDropEffect1 = "";				//【时间】
挂载位置：产出物
上持续特效
	TStr ReceiveEffectLocation = "";				//【时间】
挂载位置：原道具
上持续特效位置
	TStr ReceiveEffect = "";				//【时间】
挂载位置：原道具
上持续特效
	TStr TimeDropEffect2 = "";				//【时间】
产出在周围时
播放位置
	TStr TimeDropEffect2Location = "";				//【时间】
产出在周围时
	TStr TimeDropEffect3Location = "";				//【时间】
产出在内部时
播放位置
	TStr TimeDropEffect3 = "";				//【时间】
产出在内部时
	TStr EnableClickEffectLocation = "";				//【点击】
可点击时原道具上循环
播放位置
	TStr EnableClickEffect = "";				//【点击】
可点击时原道具上循环
播放特效
	TStr ClickEffectLocation = "";				//【点击】
有点击功能单机时
播放位置
	TStr ClickEffect = "";				//【点击】
有点击功能单机时
	TStr ClickTureEffectLocation = "";				//【点击】
成功触发点击掉落时
播放位置
	TStr ClickTureEffect = "";				//【点击】
成功触发点击掉落时
	TStr BuildEffectLocation = "";				//【建造】
建造中特效
播放位置
	TStr BuildEffect = "";				//【建造】
建造中特效
	TStr BuildAffirmEffectLocation = "";				//【建造】
建造确认特效
播放位置
	TStr BuildAffirmEffect = "";				//【建造】
建造确认特效
	TStr CollectEffectLocation = "";				//【采集】
采集中特效
播放位置
	TStr CollectEffect = "";				//【采集】
采集中特效
	TStr CollectAffirmEffectLocation = "";				//【采集】
确认采集特效
播放位置
	TStr CollectAffirmEffect = "";				//【采集】
确认采集特效
	TStr BornEffectLocation = "";				//【出生】
播放位置
	TStr BornEffect = "";				//【出生】
出生特效
	TStr DeadKillEffectLocation = "";				//【被击杀】
播放位置
	TStr DeadKillEffect = "";				//【被击杀】
特效
	TStr DeadTimeEffectLocation = "";				//【时间死亡】
播放位置
	TStr DeadTimeEffect = "";				//【时间死亡】
特效
	TStr SellEffectLocation = "";				//【出售】
播放位置
	TStr SellEffect = "";				//【出售】
特效
	TStr DestroyEffectLocation = "";				//【销毁】
播放位置
	TStr DestroyEffect = "";				//【销毁】
特效
	TStr Location = "";				//【宝箱解锁】
播放位置
	TStr BoxUnlockEffect = "";				//【宝箱解锁】
特效
	TStr BoxOpenEffectLocation = "";				//【宝箱打开】
播放位置
	TStr BoxOpenEffect = "";				//【宝箱打开】
特效
	TStr BoxUnlockEffectLocation = "";				//【宝箱待解锁】
播放位置
	TStr BoxWaitUnlockEffect = "";				//【宝箱待解锁】
特效
	TStr BoxUnlockImageLocation = "";				//【宝箱待解锁】
图片位置
	TStr BoxUnlockImage = "";				//【宝箱待解锁】
图片
	TStr StandbyEffectLocation = "";				//【待机特】效
播放位置
	TStr StandbyEffect = "";				//【待机特效】
	TStr CrossEffectLocation = "";				//【十字解锁】
使用特效位置
	TStr CrossEffect = "";				//【十字解锁】
使用特效
	TStr HeroLvupLocation = "";				//【英雄升级祭坛待机】效播放位置
	TStr HeroLvup = "";				//【英雄升级祭坛待机】
使用特效
	TStr UpEffectLocation = "";				//【升级】
使用特效位置
	TStr UpEffect = "";				//【升级】
使用特效
	TStr BerestingEffectLocation = "";				//【休息屋】
人在休息时特效挂点
	TStr BerestingEffect = "";				//【休息屋】
有人在休息时特效
	TStr LevelTargetEffectLocation = "";				//通关条件特效
挂点
	TStr LevelTargetEffect = "";				//通关条件特效
	TStr SoundClick = "";				//点击音效
	TStr SelectSound = "";				//选中音效
	TStr CollectSound = "";				//【采集】
采集中音效
	INT32 CollectSoundGroupCount = 0;				//【采集】
音效随机组内容数量
	TStr UnlockchestSound = "";				//【宝箱】
解锁音效
	TStr OpenchestSound = "";				//【宝箱】
打开音效
	TStr DeleteSound = "";				//【道具】
删除音效
	TStr DestorySound = "";				//【道具】
删除音效
	TStr ActcofSound = "";				//【行为】
行为确认音效
	TStr PutdownSound = "";				//【采集】
采集后放置音效
	TStr AppearSound = "";				//【道具】
道具出现音效
	TStr BuildingSound = "";				//【建筑】
建筑建造音效
	INT32 BuildSoundGroupCount = 0;				//【建筑】
建筑随机组内容数量
	TStr ProducingSound1 = "";				//【道具】
道具时间产出音效1
	TStr ProducingSound2 = "";				//【道具】
道具时间产出音效2
	TStr RewardquaSound = "";				//【道具】
奖励品质音效
	TStr CallDragon = "";				//召唤音效
	TStr CallDragonback = "";				//返回音效
	TStr PopUpSound = "";				//冒出音效
	TStr ComboSound = "";				//连击音效
	TStr UIModel = "";				//UI英雄面板
专用形象
	TStr Namekey = "";				//Key
	TStr DescriptKey = "";				//Key
};
CreateCsvClass(table_article);

struct table_article_borderT : ConfigBaseT
{
	virtual ~table_article_borderT()
	{
	}
	table_article_borderT()
	{
		FileName = "table_article_border.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"Comment",{TSTR_FD, &Comment}},
			{"Res",{TSTR_FD, &Res}}
		};
	}
	virtual table_article_borderT* create()
	{
		return new table_article_borderT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	TStr Comment = "";				//描述
	TStr Res = "";				//底框资源名称
};
CreateCsvClass(table_article_border);

struct table_article_conditionT : ConfigBaseT
{
	virtual ~table_article_conditionT()
	{
	}
	table_article_conditionT()
	{
		FileName = "table_article_condition.csv";
		_kf =
		{
			{"Status",{INT_FD, &Status}},
			{"Remark",{TSTR_FD, &Remark}},
			{"StatusName",{TSTR_FD, &StatusName}},
			{"PolluteLand",{INT_FD, &PolluteLand}},
			{"NormalLand",{INT_FD, &NormalLand}},
			{"PitchOn",{INT_FD, &PitchOn}},
			{"Drag",{INT_FD, &Drag}},
			{"MoveTo",{INT_FD, &MoveTo}},
			{"Birth",{INT_FD, &Birth}},
			{"NotLive",{INT_FD, &NotLive}},
			{"ByThunder",{INT_FD, &ByThunder}},
			{"AboutofActivity",{INT_FD, &AboutofActivity}},
			{"BeBeingActivity",{INT_FD, &BeBeingActivity}},
			{"ActiveMergePreview",{INT_FD, &ActiveMergePreview}},
			{"BeMergePreview",{INT_FD, &BeMergePreview}},
			{"Mergeing",{INT_FD, &Mergeing}},
			{"MountThunder",{INT_FD, &MountThunder}},
			{"AboutofDead",{INT_FD, &AboutofDead}},
			{"Attack",{INT_FD, &Attack}},
			{"Bubblebig",{INT_FD, &Bubblebig}}
		};
	}
	virtual table_article_conditionT* create()
	{
		return new table_article_conditionT();
	}
	enum
	{
	};
	INT32 Status = 0;            //状态ID
	TStr Remark = "";				//备注
	TStr StatusName = "";				//Status
	INT32 PolluteLand = 0;				//状态1
	INT32 NormalLand = 0;				//状态2
	INT32 PitchOn = 0;				//状态3
	INT32 Drag = 0;				//状态4
	INT32 MoveTo = 0;				//状态5
	INT32 Birth = 0;				//状态6
	INT32 NotLive = 0;				//状态7
	INT32 ByThunder = 0;				//状态8
	INT32 AboutofActivity = 0;				//状态9
	INT32 BeBeingActivity = 0;				//状态
	INT32 ActiveMergePreview = 0;				//状态10
	INT32 BeMergePreview = 0;				//状态11
	INT32 Mergeing = 0;				//状态12
	INT32 MountThunder = 0;				//状态13
	INT32 AboutofDead = 0;				//状态14
	INT32 Attack = 0;				//状态15
	INT32 Bubblebig = 0;				//状态16
};
CreateCsvClass(table_article_condition);

struct table_article_showT : ConfigBaseT
{
	virtual ~table_article_showT()
	{
	}
	table_article_showT()
	{
		FileName = "table_article_show.csv";
		_kf =
		{
			{"ArticleSourceType",{INT_FD, &ArticleSourceType}},
			{"Remarks",{TSTR_FD, &Remarks}},
			{"IsMove",{INT_FD, &IsMove}},
			{"IsShake",{INT_FD, &IsShake}},
			{"IsZoomInOut",{INT_FD, &IsZoomInOut}},
			{"IsZoomIn",{INT_FD, &IsZoomIn}},
			{"OriginScale",{FLOAT_FD, &OriginScale}}
		};
	}
	virtual table_article_showT* create()
	{
		return new table_article_showT();
	}
	enum
	{
	};
	INT32 ArticleSourceType = 0;            //道具来源类型
	TStr Remarks = "";				//备注
	INT32 IsMove = 0;				//是否飞跃
	INT32 IsShake = 0;				//是否咕悠
	INT32 IsZoomInOut = 0;				//是否先变大再缩小
	INT32 IsZoomIn = 0;				//是否从小变大
	float OriginScale = 0.0f;				//原始缩放大小
};
CreateCsvClass(table_article_show);

struct table_article_uishowT : ConfigBaseT
{
	virtual ~table_article_uishowT()
	{
	}
	table_article_uishowT()
	{
		FileName = "table_article_uishow.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"ImageForm",{INT_FD, &ImageForm}},
			{"Image",{TSTR_FD, &Image}},
			{"AtlasName",{TSTR_FD, &AtlasName}},
			{"TokenChr",{TSTR_FD, &TokenChr}}
		};
	}
	virtual table_article_uishowT* create()
	{
		return new table_article_uishowT();
	}
	enum
	{
	};
	INT32 ID = 0;            //articleID
	INT32 ImageForm = 0;				//图片来源
	TStr Image = "";				//图片资源
	TStr AtlasName = "";				//图集名称
	TStr TokenChr = "";				//品质
};
CreateCsvClass(table_article_uishow);

struct table_article_zoomT : ConfigBaseT
{
	virtual ~table_article_zoomT()
	{
	}
	table_article_zoomT()
	{
		FileName = "table_article_zoom.csv";
		_kf =
		{
			{"CollectType",{INT_FD, &CollectType}},
			{"time1",{FLOAT_FD, &time1}},
			{"time2",{FLOAT_FD, &time2}},
			{"time3",{FLOAT_FD, &time3}},
			{"time4",{FLOAT_FD, &time4}},
			{"time5",{FLOAT_FD, &time5}},
			{"time6",{FLOAT_FD, &time6}},
			{"time7",{FLOAT_FD, &time7}},
			{"time8",{FLOAT_FD, &time8}},
			{"time9",{FLOAT_FD, &time9}},
			{"time10",{FLOAT_FD, &time10}},
			{"time11",{FLOAT_FD, &time11}},
			{"time12",{FLOAT_FD, &time12}},
			{"time13",{FLOAT_FD, &time13}},
			{"time14",{FLOAT_FD, &time14}},
			{"time15",{FLOAT_FD, &time15}},
			{"time16",{FLOAT_FD, &time16}},
			{"time17",{FLOAT_FD, &time17}},
			{"time18",{FLOAT_FD, &time18}},
			{"time19",{FLOAT_FD, &time19}},
			{"time20",{FLOAT_FD, &time20}},
			{"time21",{FLOAT_FD, &time21}},
			{"time22",{FLOAT_FD, &time22}},
			{"time23",{FLOAT_FD, &time23}},
			{"time24",{FLOAT_FD, &time24}},
			{"time25",{FLOAT_FD, &time25}},
			{"time26",{FLOAT_FD, &time26}},
			{"time27",{FLOAT_FD, &time27}},
			{"time28",{FLOAT_FD, &time28}},
			{"time29",{FLOAT_FD, &time29}},
			{"time30",{FLOAT_FD, &time30}}
		};
	}
	virtual table_article_zoomT* create()
	{
		return new table_article_zoomT();
	}
	enum
	{
	};
	INT32 CollectType = 0;            //类型ID
	float time1 = 0.0f;				//次数1
	float time2 = 0.0f;				//次数2
	float time3 = 0.0f;				//次数3
	float time4 = 0.0f;				//次数4
	float time5 = 0.0f;				//次数5
	float time6 = 0.0f;				//次数6
	float time7 = 0.0f;				//次数7
	float time8 = 0.0f;				//次数8
	float time9 = 0.0f;				//次数9
	float time10 = 0.0f;				//次数10
	float time11 = 0.0f;				//次数11
	float time12 = 0.0f;				//次数12
	float time13 = 0.0f;				//次数13
	float time14 = 0.0f;				//次数14
	float time15 = 0.0f;				//次数15
	float time16 = 0.0f;				//次数16
	float time17 = 0.0f;				//次数17
	float time18 = 0.0f;				//次数18
	float time19 = 0.0f;				//次数19
	float time20 = 0.0f;				//次数20
	float time21 = 0.0f;				//次数21
	float time22 = 0.0f;				//次数22
	float time23 = 0.0f;				//次数23
	float time24 = 0.0f;				//次数24
	float time25 = 0.0f;				//次数25
	float time26 = 0.0f;				//次数26
	float time27 = 0.0f;				//次数27
	float time28 = 0.0f;				//次数28
	float time29 = 0.0f;				//次数29
	float time30 = 0.0f;				//次数30
};
CreateCsvClass(table_article_zoom);

struct table_award_everydayT : ConfigBaseT
{
	virtual ~table_award_everydayT()
	{
	}
	table_award_everydayT()
	{
		FileName = "table_award_everyday.csv";
		_kf =
		{
			{"AwardId",{INT_FD, &AwardId}},
			{"TodayAwardType",{INT_FD, &TodayAwardType}},
			{"TaskAward2",{INT_FD, &TaskAward2}},
			{"Num2",{INT_FD, &Num2}}
		};
	}
	virtual table_award_everydayT* create()
	{
		return new table_award_everydayT();
	}
	enum
	{
	};
	INT32 AwardId = 0;            //任务id
	INT32 TodayAwardType = 0;				//任务奖励1显示
	INT32 TaskAward2 = 0;				//任务奖励2
	INT32 Num2 = 0;				//奖励数量
};
CreateCsvClass(table_award_everyday);

struct table_baseconfigT : ConfigBaseT
{
	virtual ~table_baseconfigT()
	{
	}
	table_baseconfigT()
	{
		FileName = "table_baseconfig.csv";
		_kf =
		{
			{"Number",{INT_FD, &Number}},
			{"Describe",{TSTR_FD, &Describe}},
			{"Parameter1",{FLOAT_FD, &Parameter1}},
			{"Parameter2",{FLOAT_FD, &Parameter2}},
			{"Parameter3",{FLOAT_FD, &Parameter3}},
			{"Parameter4",{FLOAT_FD, &Parameter4}},
			{"Parameter5",{FLOAT_FD, &Parameter5}},
			{"Parameter6",{TSTR_FD, &Parameter6}}
		};
	}
	virtual table_baseconfigT* create()
	{
		return new table_baseconfigT();
	}
	enum
	{
	};
	INT32 Number = 0;            //序号
	TStr Describe = "";				//描述
	float Parameter1 = 0.0f;				//参数1
	float Parameter2 = 0.0f;				//参数2
	float Parameter3 = 0.0f;				//参数3
	float Parameter4 = 0.0f;				//参数4
	float Parameter5 = 0.0f;				//参数5
	TStr Parameter6 = "";				//参数6
};
CreateCsvClass(table_baseconfig);

struct table_behaviortreeT : ConfigBaseT
{
	virtual ~table_behaviortreeT()
	{
	}
	table_behaviortreeT()
	{
		FileName = "table_behaviortree.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"EnName",{TSTR_FD, &EnName}},
			{"CnName",{TSTR_FD, &CnName}},
			{"Type",{INT_FD, &Type}},
			{"FloatValue",{FLOAT_FD, &FloatValue}},
			{"IntValue",{INT_FD, &IntValue}},
			{"LongValue",{TSTR_FD, &LongValue}},
			{"BoolValue",{INT_FD, &BoolValue}},
			{"StringValue",{TSTR_FD, &StringValue}}
		};
	}
	virtual table_behaviortreeT* create()
	{
		return new table_behaviortreeT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	TStr EnName = "";				//英文名称
	TStr CnName = "";				//中文说明文字
	INT32 Type = 0;				//类型
	float FloatValue = 0.0f;				//float值
	INT32 IntValue = 0;				//int值
	TStr LongValue = "";				//long值
	INT32 BoolValue = 0;				//bool值
	TStr StringValue = "";				//string值
};
CreateCsvClass(table_behaviortree);

struct table_bubbleT : ConfigBaseT
{
	virtual ~table_bubbleT()
	{
	}
	table_bubbleT()
	{
		FileName = "table_bubble.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"NameText",{TSTR_FD, &NameText}},
			{"Describe",{TSTR_FD, &Describe}},
			{"NameImageLocation",{TSTR_FD, &NameImageLocation}},
			{"NameImage",{TSTR_FD, &NameImage}},
			{"StandbyImage",{TSTR_FD, &StandbyImage}},
			{"PreviewLocation",{TSTR_FD, &PreviewLocation}},
			{"StandbyEffectLocation",{TSTR_FD, &StandbyEffectLocation}},
			{"StandbyEffect",{TSTR_FD, &StandbyEffect}},
			{"BirthEffectLocation",{TSTR_FD, &BirthEffectLocation}},
			{"BirthEffect",{TSTR_FD, &BirthEffect}},
			{"ImageOpenEffectLocation",{TSTR_FD, &ImageOpenEffectLocation}},
			{"ImageOpenEffect",{TSTR_FD, &ImageOpenEffect}},
			{"OpenSound",{TSTR_FD, &OpenSound}},
			{"Remark",{TSTR_FD, &Remark}},
			{"NameTextKey",{TSTR_FD, &NameTextKey}},
			{"DescribeKey",{TSTR_FD, &DescribeKey}}
		};
	}
	virtual table_bubbleT* create()
	{
		return new table_bubbleT();
	}
	enum
	{
	};
	INT32 ID = 0;            //泡泡ID
	TStr NameText = "";				//名称
	TStr Describe = "";				//描述
	TStr NameImageLocation = "";				//文字图片
播放位置
	TStr NameImage = "";				//文字图片
	TStr StandbyImage = "";				//待机资源图片
	TStr PreviewLocation = "";				//预览挂点
	TStr StandbyEffectLocation = "";				//待机特效
播放位置
	TStr StandbyEffect = "";				//待机特效
	TStr BirthEffectLocation = "";				//出现时特效
播放位置
	TStr BirthEffect = "";				//出现时特效
	TStr ImageOpenEffectLocation = "";				//打开资源特效
播放位置
	TStr ImageOpenEffect = "";				//打开资源特效
	TStr OpenSound = "";				//打开气泡音效
	TStr Remark = "";				//备注
	TStr NameTextKey = "";				//Key
	TStr DescribeKey = "";				//Key
};
CreateCsvClass(table_bubble);

struct table_bubble_bigT : ConfigBaseT
{
	virtual ~table_bubble_bigT()
	{
	}
	table_bubble_bigT()
	{
		FileName = "table_bubble_big.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"Level",{INT_FD, &Level}},
			{"UnLcokType",{INT_FD, &UnLcokType}},
			{"UnLockPrice",{INT_FD, &UnLockPrice}},
			{"UnLockTime",{INT_FD, &UnLockTime}},
			{"Image",{TSTR_FD, &Image}},
			{"StandbyEffectLocation",{TSTR_FD, &StandbyEffectLocation}},
			{"StandbyEffect",{TSTR_FD, &StandbyEffect}},
			{"UnLockEffectLocation",{TSTR_FD, &UnLockEffectLocation}},
			{"UnLockEffect",{TSTR_FD, &UnLockEffect}},
			{"OpenEffectLocation",{TSTR_FD, &OpenEffectLocation}},
			{"OpenEffect",{TSTR_FD, &OpenEffect}},
			{"JarbornSound",{TSTR_FD, &JarbornSound}},
			{"JarpanelSound",{TSTR_FD, &JarpanelSound}},
			{"JaropenSound1",{TSTR_FD, &JaropenSound1}},
			{"JaropenSound2",{TSTR_FD, &JaropenSound2}}
		};
	}
	virtual table_bubble_bigT* create()
	{
		return new table_bubble_bigT();
	}
	enum
	{
	};
	INT32 ID = 0;            //大泡泡ID
	INT32 Level = 0;				//等级
	INT32 UnLcokType = 0;				//大泡泡
解锁类型
	INT32 UnLockPrice = 0;				//大泡泡
解锁值
	INT32 UnLockTime = 0;				//倒计时时间
	TStr Image = "";				//图片资源
	TStr StandbyEffectLocation = "";				//特效播放位置
	TStr StandbyEffect = "";				//待机特效
	TStr UnLockEffectLocation = "";				//特效播放位置
	TStr UnLockEffect = "";				//解锁特效
	TStr OpenEffectLocation = "";				//特效播放位置
	TStr OpenEffect = "";				//打开特效
	TStr JarbornSound = "";				//生成维罐音效
	TStr JarpanelSound = "";				//打开维罐音效
	TStr JaropenSound1 = "";				//花费解锁音效
	TStr JaropenSound2 = "";				//最终确认音效
};
CreateCsvClass(table_bubble_big);

struct table_bubble_conditionT : ConfigBaseT
{
	virtual ~table_bubble_conditionT()
	{
	}
	table_bubble_conditionT()
	{
		FileName = "table_bubble_condition.csv";
		_kf =
		{
			{"Status",{INT_FD, &Status}},
			{"Remark",{TSTR_FD, &Remark}},
			{"StatusName",{TSTR_FD, &StatusName}},
			{"PolluteLand",{INT_FD, &PolluteLand}},
			{"NormalLand",{INT_FD, &NormalLand}},
			{"PitchOn",{INT_FD, &PitchOn}},
			{"Drag",{INT_FD, &Drag}},
			{"MoveTo",{INT_FD, &MoveTo}}
		};
	}
	virtual table_bubble_conditionT* create()
	{
		return new table_bubble_conditionT();
	}
	enum
	{
	};
	INT32 Status = 0;            //状态ID
	TStr Remark = "";				//备注
	TStr StatusName = "";				//Status
	INT32 PolluteLand = 0;				//状态1
	INT32 NormalLand = 0;				//状态2
	INT32 PitchOn = 0;				//状态3
	INT32 Drag = 0;				//状态4
	INT32 MoveTo = 0;				//状态5
};
CreateCsvClass(table_bubble_condition);

struct table_buffT : ConfigBaseT
{
	virtual ~table_buffT()
	{
	}
	table_buffT()
	{
		FileName = "table_buff.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"BuffType",{INT_FD, &BuffType}},
			{"BuffLevel",{INT_FD, &BuffLevel}},
			{"BuffParam",{TSTR_FD, &BuffParam}},
			{"BuffImage",{TSTR_FD, &BuffImage}},
			{"TipsIndex",{INT_FD, &TipsIndex}},
			{"DisplayAnimation",{TSTR_FD, &DisplayAnimation}},
			{"TipsLeft",{INT_FD, &TipsLeft}},
			{"TipsRight",{INT_FD, &TipsRight}},
			{"BuffDescript",{TSTR_FD, &BuffDescript}},
			{"BuffDescriptKey",{TSTR_FD, &BuffDescriptKey}},
			{"BuffDescriptKey2",{TSTR_FD, &BuffDescriptKey2}},
			{"BuffDescriptKey3",{TSTR_FD, &BuffDescriptKey3}},
			{"BuffDescriptKey4",{TSTR_FD, &BuffDescriptKey4}},
			{"BuffNameKey",{TSTR_FD, &BuffNameKey}}
		};
	}
	virtual table_buffT* create()
	{
		return new table_buffT();
	}
	enum
	{
	};
	INT32 ID = 0;            //buffid
	INT32 BuffType = 0;				//BUFF生效类型
	INT32 BuffLevel = 0;				//BUFF等级
	TStr BuffParam = "";				//BUFF效果参数
	TStr BuffImage = "";				//技能图标
	INT32 TipsIndex = 0;				//技能展示图片
	TStr DisplayAnimation = "";				//技能展示动画
	INT32 TipsLeft = 0;				//技能tips左侧展示
	INT32 TipsRight = 0;				//技能tips右侧展示
	TStr BuffDescript = "";				//技能描述
	TStr BuffDescriptKey = "";				//Key
	TStr BuffDescriptKey2 = "";				//Key2
	TStr BuffDescriptKey3 = "";				//Key3
	TStr BuffDescriptKey4 = "";				//Key4
	TStr BuffNameKey = "";				//名称KEY
};
CreateCsvClass(table_buff);

struct table_combo_showT : ConfigBaseT
{
	virtual ~table_combo_showT()
	{
	}
	table_combo_showT()
	{
		FileName = "table_combo_show.csv";
		_kf =
		{
			{"Continuous",{INT_FD, &Continuous}},
			{"ContinuousImage",{TSTR_FD, &ContinuousImage}},
			{"ContinuousScore",{FLOAT_FD, &ContinuousScore}},
			{"ContinuousEffect",{TSTR_FD, &ContinuousEffect}}
		};
	}
	virtual table_combo_showT* create()
	{
		return new table_combo_showT();
	}
	enum
	{
	};
	INT32 Continuous = 0;            //连击次数
	TStr ContinuousImage = "";				//连击图片
	float ContinuousScore = 0.0f;				//连击积分系数
	TStr ContinuousEffect = "";				//连击特效
};
CreateCsvClass(table_combo_show);

struct table_contactusT : ConfigBaseT
{
	virtual ~table_contactusT()
	{
	}
	table_contactusT()
	{
		FileName = "table_contactus.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"Sort",{INT_FD, &Sort}},
			{"OutpostID",{TSTR_FD, &OutpostID}},
			{"Key",{TSTR_FD, &Key}}
		};
	}
	virtual table_contactusT* create()
	{
		return new table_contactusT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	INT32 Sort = 0;				//排序
	TStr OutpostID = "";				//描述
	TStr Key = "";				//本地化KEY
};
CreateCsvClass(table_contactus);

struct table_creatureT : ConfigBaseT
{
	virtual ~table_creatureT()
	{
	}
	table_creatureT()
	{
		FileName = "table_creature.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"Name",{TSTR_FD, &Name}},
			{"Comment",{TSTR_FD, &Comment}},
			{"UiImage",{TSTR_FD, &UiImage}},
			{"Res",{TSTR_FD, &Res}},
			{"Preview",{TSTR_FD, &Preview}},
			{"Skin0",{TSTR_FD, &Skin0}},
			{"Skin0ImageType",{INT_FD, &Skin0ImageType}},
			{"Skin0Direction",{INT_FD, &Skin0Direction}},
			{"Des",{TSTR_FD, &Des}},
			{"HomePrice",{INT_FD, &HomePrice}},
			{"CreatureQuality",{INT_FD, &CreatureQuality}},
			{"LevelPrice",{INT_FD, &LevelPrice}},
			{"CreatureType",{INT_FD, &CreatureType}},
			{"CreatureLevel",{INT_FD, &CreatureLevel}},
			{"MaxMarking",{INT_FD, &MaxMarking}},
			{"HeroType",{INT_FD, &HeroType}},
			{"FunctionType",{INT_FD, &FunctionType}},
			{"AIConfig",{TSTR_FD, &AIConfig}},
			{"ActivityCDMin",{INT_FD, &ActivityCDMin}},
			{"ActivityCDMax",{INT_FD, &ActivityCDMax}},
			{"CanMerge",{INT_FD, &CanMerge}},
			{"MoveType",{INT_FD, &MoveType}},
			{"Population",{INT_FD, &Population}},
			{"Hp",{FLOAT_FD, &Hp}},
			{"DeadDrop",{INT_FD, &DeadDrop}},
			{"SP",{INT_FD, &SP}},
			{"WalkSpeed",{FLOAT_FD, &WalkSpeed}},
			{"RunSpeed",{FLOAT_FD, &RunSpeed}},
			{"CollectSpeed",{FLOAT_FD, &CollectSpeed}},
			{"CollectSpeed2",{FLOAT_FD, &CollectSpeed2}},
			{"BuildSpeed",{FLOAT_FD, &BuildSpeed}},
			{"Tendency1",{INT_FD, &Tendency1}},
			{"Tendency2",{INT_FD, &Tendency2}},
			{"Tendency3",{INT_FD, &Tendency3}},
			{"Tendency4",{INT_FD, &Tendency4}},
			{"Tendency5",{INT_FD, &Tendency5}},
			{"TrendArticleTypeID",{INT_FD, &TrendArticleTypeID}},
			{"TrendLvMin",{INT_FD, &TrendLvMin}},
			{"TrendLvMax",{INT_FD, &TrendLvMax}},
			{"TrendArticleID",{INT_FD, &TrendArticleID}},
			{"TrendPonit",{FLOAT_FD, &TrendPonit}},
			{"CollectExpend",{INT_FD, &CollectExpend}},
			{"BuildExpend",{INT_FD, &BuildExpend}},
			{"AttackExpend",{INT_FD, &AttackExpend}},
			{"AtkSpeed",{FLOAT_FD, &AtkSpeed}},
			{"Atk",{FLOAT_FD, &Atk}},
			{"CombatEffect",{INT_FD, &CombatEffect}},
			{"AtkDis",{FLOAT_FD, &AtkDis}},
			{"AtkRange",{FLOAT_FD, &AtkRange}},
			{"ActTestingTime",{FLOAT_FD, &ActTestingTime}},
			{"PatSpTimeMin",{FLOAT_FD, &PatSpTimeMin}},
			{"PatSpTimeMax",{FLOAT_FD, &PatSpTimeMax}},
			{"PolluteWeight",{INT_FD, &PolluteWeight}},
			{"PolluteRange",{INT_FD, &PolluteRange}},
			{"PolluteTime",{FLOAT_FD, &PolluteTime}},
			{"PolluteValue",{INT_FD, &PolluteValue}},
			{"MergeTime",{FLOAT_FD, &MergeTime}},
			{"BornPointValue",{FLOAT_FD, &BornPointValue}},
			{"BornTime",{INT_FD, &BornTime}},
			{"MergeCD",{INT_FD, &MergeCD}},
			{"MergeRate",{FLOAT_FD, &MergeRate}},
			{"StealWeight",{INT_FD, &StealWeight}},
			{"StealRange",{INT_FD, &StealRange}},
			{"Steal",{FLOAT_FD, &Steal}},
			{"Buff1",{INT_FD, &Buff1}},
			{"Buff2",{INT_FD, &Buff2}},
			{"Buff3",{INT_FD, &Buff3}},
			{"ActiveTime",{INT_FD, &ActiveTime}},
			{"LevelAppear",{INT_FD, &LevelAppear}},
			{"AwardType",{INT_FD, &AwardType}},
			{"Award",{INT_FD, &Award}},
			{"Score",{INT_FD, &Score}},
			{"CarriageLocation",{TSTR_FD, &CarriageLocation}},
			{"BornTextOdds",{FLOAT_FD, &BornTextOdds}},
			{"BornText1",{TSTR_FD, &BornText1}},
			{"BornText2",{TSTR_FD, &BornText2}},
			{"BornText3",{TSTR_FD, &BornText3}},
			{"ClickTextOdds",{FLOAT_FD, &ClickTextOdds}},
			{"ClickText1",{TSTR_FD, &ClickText1}},
			{"ClickText2",{TSTR_FD, &ClickText2}},
			{"ClickText3",{TSTR_FD, &ClickText3}},
			{"BuildMoveTextOdds",{FLOAT_FD, &BuildMoveTextOdds}},
			{"BuildMoveText1",{TSTR_FD, &BuildMoveText1}},
			{"BuildMoveText2",{TSTR_FD, &BuildMoveText2}},
			{"BuildMoveText3",{TSTR_FD, &BuildMoveText3}},
			{"BuildTextOdds",{FLOAT_FD, &BuildTextOdds}},
			{"BuildText1",{TSTR_FD, &BuildText1}},
			{"BuildText2",{TSTR_FD, &BuildText2}},
			{"BuildText3",{TSTR_FD, &BuildText3}},
			{"CollectMoveTextOdds",{FLOAT_FD, &CollectMoveTextOdds}},
			{"CollectMoveText1",{TSTR_FD, &CollectMoveText1}},
			{"CollectMoveText2",{TSTR_FD, &CollectMoveText2}},
			{"CollectMoveText3",{TSTR_FD, &CollectMoveText3}},
			{"CollectTextOdds",{FLOAT_FD, &CollectTextOdds}},
			{"CollectText1",{TSTR_FD, &CollectText1}},
			{"CollectText2",{TSTR_FD, &CollectText2}},
			{"CollectText3",{TSTR_FD, &CollectText3}},
			{"NoSpaceTextOdds",{FLOAT_FD, &NoSpaceTextOdds}},
			{"NoSpaceText1",{TSTR_FD, &NoSpaceText1}},
			{"NoSpaceText2",{TSTR_FD, &NoSpaceText2}},
			{"NoSpaceText3",{TSTR_FD, &NoSpaceText3}},
			{"SleepTextOdds",{FLOAT_FD, &SleepTextOdds}},
			{"SleepText1",{TSTR_FD, &SleepText1}},
			{"SleepText2",{TSTR_FD, &SleepText2}},
			{"SleepText3",{TSTR_FD, &SleepText3}},
			{"SleepOverTextOdds",{FLOAT_FD, &SleepOverTextOdds}},
			{"SleepOverText1",{TSTR_FD, &SleepOverText1}},
			{"SleepOverText2",{TSTR_FD, &SleepOverText2}},
			{"SleepOverText3",{TSTR_FD, &SleepOverText3}},
			{"StrollTextOdds",{FLOAT_FD, &StrollTextOdds}},
			{"StrollTextMin",{FLOAT_FD, &StrollTextMin}},
			{"StrollTextMax",{FLOAT_FD, &StrollTextMax}},
			{"StrollText1",{TSTR_FD, &StrollText1}},
			{"StrollText2",{TSTR_FD, &StrollText2}},
			{"StrollText3",{TSTR_FD, &StrollText3}},
			{"StandbyTextOdds",{FLOAT_FD, &StandbyTextOdds}},
			{"StandbyText1",{TSTR_FD, &StandbyText1}},
			{"StandbyText2",{TSTR_FD, &StandbyText2}},
			{"StandbyText3",{TSTR_FD, &StandbyText3}},
			{"AttackMoveTextOdds",{FLOAT_FD, &AttackMoveTextOdds}},
			{"AttackMoveText1",{TSTR_FD, &AttackMoveText1}},
			{"AttackMoveText2",{TSTR_FD, &AttackMoveText2}},
			{"AttackMoveText3",{TSTR_FD, &AttackMoveText3}},
			{"AttackTextOdds",{FLOAT_FD, &AttackTextOdds}},
			{"AttackText1",{TSTR_FD, &AttackText1}},
			{"AttackText2",{TSTR_FD, &AttackText2}},
			{"AttackText3",{TSTR_FD, &AttackText3}},
			{"PolluteBobyEffectLocation",{TSTR_FD, &PolluteBobyEffectLocation}},
			{"PolluteBobyEffect",{TSTR_FD, &PolluteBobyEffect}},
			{"PolluteLandEffect",{TSTR_FD, &PolluteLandEffect}},
			{"StealBobyEffectLocation",{TSTR_FD, &StealBobyEffectLocation}},
			{"StealBobyEffect",{TSTR_FD, &StealBobyEffect}},
			{"StealLandEffect",{TSTR_FD, &StealLandEffect}},
			{"SufferEffectLocation",{TSTR_FD, &SufferEffectLocation}},
			{"SufferEffect",{TSTR_FD, &SufferEffect}},
			{"BirthEffectLocation",{TSTR_FD, &BirthEffectLocation}},
			{"BirthEffect",{TSTR_FD, &BirthEffect}},
			{"UpEffectLocation",{TSTR_FD, &UpEffectLocation}},
			{"UpEffect",{TSTR_FD, &UpEffect}},
			{"DelayAtkEffectBack",{FLOAT_FD, &DelayAtkEffectBack}},
			{"DelayAtkEffectFront",{FLOAT_FD, &DelayAtkEffectFront}},
			{"CombatEffectLocation",{TSTR_FD, &CombatEffectLocation}},
			{"AtkEffect",{TSTR_FD, &AtkEffect}},
			{"AttackSound",{TSTR_FD, &AttackSound}},
			{"UnderattackSound",{TSTR_FD, &UnderattackSound}},
			{"StartpoSound",{TSTR_FD, &StartpoSound}},
			{"PollutingSound",{TSTR_FD, &PollutingSound}},
			{"StartstSound",{TSTR_FD, &StartstSound}},
			{"StealingSound",{TSTR_FD, &StealingSound}},
			{"BornSound",{TSTR_FD, &BornSound}},
			{"RewardquaSound",{TSTR_FD, &RewardquaSound}},
			{"CallSound",{TSTR_FD, &CallSound}},
			{"ReturnSound",{TSTR_FD, &ReturnSound}},
			{"NameKey",{TSTR_FD, &NameKey}},
			{"DesKey",{TSTR_FD, &DesKey}}
		};
	}
	virtual table_creatureT* create()
	{
		return new table_creatureT();
	}
	enum
	{
	};
	INT32 ID = 0;            //id
	TStr Name = "";				//名称
	TStr Comment = "";				//备注
	TStr UiImage = "";				//UI图标
	TStr Res = "";				//资源
	TStr Preview = "";				//预览图
	TStr Skin0 = "";				//皮肤
	INT32 Skin0ImageType = 0;				//形象类型
	INT32 Skin0Direction = 0;				//方向规则
	TStr Des = "";				//描述
	INT32 HomePrice = 0;				//【基础属性】
家园：售卖或销毁
	INT32 CreatureQuality = 0;				//【基础属性】
品质
	INT32 LevelPrice = 0;				//【基础属性】
关卡：售卖或销毁
	INT32 CreatureType = 0;				//【基础属性】
类别
	INT32 CreatureLevel = 0;				//【基础属性】
等级
	INT32 MaxMarking = 0;				//【基础属性】
最高等级标识
	INT32 HeroType = 0;				//【基础属性】
英雄类别ID
	INT32 FunctionType = 0;				//【AI】
行为功能
	TStr AIConfig = "";				//【AI】
AI配置
	INT32 ActivityCDMin = 0;				//怪物活动CD
Min
	INT32 ActivityCDMax = 0;				//怪物活动CD
Max
	INT32 CanMerge = 0;				//能否合成
	INT32 MoveType = 0;				//移动方式
	INT32 Population = 0;				//人口值
	float Hp = 0.0f;				//血量
	INT32 DeadDrop = 0;				//死亡掉落
	INT32 SP = 0;				//行动力值
	float WalkSpeed = 0.0f;				//走：速度
	float RunSpeed = 0.0f;				//跑：速度
	float CollectSpeed = 0.0f;				//采集速度
乘法修正
	float CollectSpeed2 = 0.0f;				//采集速度
固定修正
	float BuildSpeed = 0.0f;				//建筑速度修正
	INT32 Tendency1 = 0;				//采集倾向
规则1
	INT32 Tendency2 = 0;				//采集倾向
规则2
	INT32 Tendency3 = 0;				//采集倾向
规则3
	INT32 Tendency4 = 0;				//采集倾向
规则4
	INT32 Tendency5 = 0;				//采集倾向
规则5
	INT32 TrendArticleTypeID = 0;				//采集倾向
道具类别ID
	INT32 TrendLvMin = 0;				//采集倾向
等级Min
	INT32 TrendLvMax = 0;				//采集倾向
等级Max
	INT32 TrendArticleID = 0;				//采集倾向
道具ID
	float TrendPonit = 0.0f;				//倾向程度
百分比
	INT32 CollectExpend = 0;				//采集
消耗行动力
	INT32 BuildExpend = 0;				//建造
消耗行动力
	INT32 AttackExpend = 0;				//攻击
消耗行动力
	float AtkSpeed = 0.0f;				//【攻击】
攻速
	float Atk = 0.0f;				//【攻击】
攻击力
	INT32 CombatEffect = 0;				//【攻击】
攻击类型
	float AtkDis = 0.0f;				//【攻击】
攻击距离
	float AtkRange = 0.0f;				//【攻击】
攻击范围
	float ActTestingTime = 0.0f;				//【怪物行为】
检测时间
	float PatSpTimeMin = 0.0f;				//【怪物行为】
巡逻走时间
Min
	float PatSpTimeMax = 0.0f;				//【怪物行为】
巡逻走时间
Max
	INT32 PolluteWeight = 0;				//【怪物行为】
污染权重
	INT32 PolluteRange = 0;				//【怪物行为】
污染范围
	float PolluteTime = 0.0f;				//【怪物行为】
污染时间
	INT32 PolluteValue = 0;				//【怪物行为】
污染值
	float MergeTime = 0.0f;				//【怪物行为】
等待合并时间
	float BornPointValue = 0.0f;				//【怪物行为】
出生半径
	INT32 BornTime = 0;				//【怪物行为】
出生等待时间
	INT32 MergeCD = 0;				//【怪物行为】
合成CD
	float MergeRate = 0.0f;				//【怪物行为】
触发概率
	INT32 StealWeight = 0;				//【怪物行为】
偷取权重
	INT32 StealRange = 0;				//【怪物行为】
偷取范围
	float Steal = 0.0f;				//【怪物行为】
偷取时间
	INT32 Buff1 = 0;				//【英雄系统】
调用BUFFID1
	INT32 Buff2 = 0;				//【英雄系统】
调用BUFFID2
	INT32 Buff3 = 0;				//【英雄系统】
调用BUFFID3
	INT32 ActiveTime = 0;				//【英雄系统】
活动时间
	INT32 LevelAppear = 0;				//【关卡属性】
是否允许被关卡结算选中
	INT32 AwardType = 0;				//【关卡属性】
关卡付费
奖励价格
	INT32 Award = 0;				//【关卡属性】
关卡付费
奖励价格
	INT32 Score = 0;				//【合成】
积分值
	TStr CarriageLocation = "";				//【采集】
运输的挂点
	float BornTextOdds = 0.0f;				//出生文字
几率
	TStr BornText1 = "";				//出生文字1
	TStr BornText2 = "";				//出生文字2
	TStr BornText3 = "";				//出生文字3
	float ClickTextOdds = 0.0f;				//点击反馈
文字几率
	TStr ClickText1 = "";				//点击反馈
文字1
	TStr ClickText2 = "";				//点击反馈
文字2
	TStr ClickText3 = "";				//点击反馈
文字3
	float BuildMoveTextOdds = 0.0f;				//建筑移动
文字几率
	TStr BuildMoveText1 = "";				//建筑移动
文字1
	TStr BuildMoveText2 = "";				//建筑移动
文字2
	TStr BuildMoveText3 = "";				//建筑移动
文字3
	float BuildTextOdds = 0.0f;				//建筑读条
文字几率
	TStr BuildText1 = "";				//建筑读条
文字1
	TStr BuildText2 = "";				//建筑读条
文字2
	TStr BuildText3 = "";				//建筑读条
文字3
	float CollectMoveTextOdds = 0.0f;				//采集移动
文字几率
	TStr CollectMoveText1 = "";				//采集移动
文字1
	TStr CollectMoveText2 = "";				//采集移动
文字2
	TStr CollectMoveText3 = "";				//采集移动
文字3
	float CollectTextOdds = 0.0f;				//采集读条
文字几率
	TStr CollectText1 = "";				//采集读条
文字1
	TStr CollectText2 = "";				//采集读条
文字2
	TStr CollectText3 = "";				//采集读条
文字3
	float NoSpaceTextOdds = 0.0f;				//无空地警报
文字几率
	TStr NoSpaceText1 = "";				//无空地警报
文字1
	TStr NoSpaceText2 = "";				//无空地警报
文字2
	TStr NoSpaceText3 = "";				//无空地警报
文字3
	float SleepTextOdds = 0.0f;				//去睡觉过程
文字几率
	TStr SleepText1 = "";				//去睡觉过程
文字1
	TStr SleepText2 = "";				//去睡觉过程
文字2
	TStr SleepText3 = "";				//去睡觉过程
文字3
	float SleepOverTextOdds = 0.0f;				//休息完成
文字几率
	TStr SleepOverText1 = "";				//休息完成
文字1
	TStr SleepOverText2 = "";				//休息完成
文字2
	TStr SleepOverText3 = "";				//休息完成
文字3
	float StrollTextOdds = 0.0f;				//溜达过程
文字几率
	float StrollTextMin = 0.0f;				//溜达过程
文字CDMin
	float StrollTextMax = 0.0f;				//溜达过程
文字CDMax
	TStr StrollText1 = "";				//溜达过程
文字1
	TStr StrollText2 = "";				//溜达过程
文字2
	TStr StrollText3 = "";				//溜达过程
文字3
	float StandbyTextOdds = 0.0f;				//待机
文字几率
	TStr StandbyText1 = "";				//待机
文字1
	TStr StandbyText2 = "";				//待机
文字2
	TStr StandbyText3 = "";				//待机
文字3
	float AttackMoveTextOdds = 0.0f;				//向攻击移动过程
文字几率
	TStr AttackMoveText1 = "";				//向攻击移动过程
文字1
	TStr AttackMoveText2 = "";				//向攻击移动过程
文字2
	TStr AttackMoveText3 = "";				//向攻击移动过程
文字3
	float AttackTextOdds = 0.0f;				//攻击过程
文字几率
	TStr AttackText1 = "";				//攻击过程
文字1
	TStr AttackText2 = "";				//攻击过程
文字2
	TStr AttackText3 = "";				//攻击过程
文字3
	TStr PolluteBobyEffectLocation = "";				//【污染】
身上特效播放位置
	TStr PolluteBobyEffect = "";				//【污染】
身上特效
	TStr PolluteLandEffect = "";				//【污染】
地上特效
	TStr StealBobyEffectLocation = "";				//偷取身上
特效
播放位置
	TStr StealBobyEffect = "";				//偷取身上
特效
	TStr StealLandEffect = "";				//偷取地上
特效
	TStr SufferEffectLocation = "";				//受击特效
播放位置
	TStr SufferEffect = "";				//受击特效
	TStr BirthEffectLocation = "";				//出生特效
播放位置
	TStr BirthEffect = "";				//出生特效
	TStr UpEffectLocation = "";				//【英雄升级】
特效播放位置
	TStr UpEffect = "";				//【英雄升级】
特效
	float DelayAtkEffectBack = 0.0f;				//攻击特效
延迟时间背向
	float DelayAtkEffectFront = 0.0f;				//攻击特效
延迟时间正向
	TStr CombatEffectLocation = "";				//攻击特效
特效挂点
	TStr AtkEffect = "";				//攻击特效
	TStr AttackSound = "";				//【生物】
攻击音效
	TStr UnderattackSound = "";				//【生物】
攻击后的受击音效
	TStr StartpoSound = "";				//【怪物】
开始污染音效
	TStr PollutingSound = "";				//【怪物】
污染土地音效
	TStr StartstSound = "";				//【怪物】
开始偷取音效
	TStr StealingSound = "";				//【怪物】
偷取音效
	TStr BornSound = "";				//【生物】
出生音效
	TStr RewardquaSound = "";				//【生物】
奖励品质音效
	TStr CallSound = "";				//【生物】
传送门召唤音效
	TStr ReturnSound = "";				//【生物】
返回音效
	TStr NameKey = "";				//Key
	TStr DesKey = "";				//Key
};
CreateCsvClass(table_creature);

struct table_creature_vitalityT : ConfigBaseT
{
	virtual ~table_creature_vitalityT()
	{
	}
	table_creature_vitalityT()
	{
		FileName = "table_creature_vitality.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"PopulationMin",{INT_FD, &PopulationMin}},
			{"PopulationMax",{INT_FD, &PopulationMax}},
			{"DiamondVitality",{INT_FD, &DiamondVitality}},
			{"FreeVitality",{INT_FD, &FreeVitality}},
			{"BirthVitality",{INT_FD, &BirthVitality}},
			{"BirthWaitMin",{INT_FD, &BirthWaitMin}},
			{"BirthWaitMax",{INT_FD, &BirthWaitMax}},
			{"ClickWaitMin",{INT_FD, &ClickWaitMin}},
			{"ClickWaitMax",{INT_FD, &ClickWaitMax}},
			{"BulildWaitMin",{INT_FD, &BulildWaitMin}},
			{"BulildWaitMax",{INT_FD, &BulildWaitMax}},
			{"CollectWaitMin",{INT_FD, &CollectWaitMin}},
			{"CollectWaitMax",{INT_FD, &CollectWaitMax}},
			{"AttackWaitMin",{INT_FD, &AttackWaitMin}},
			{"AttackWaitMax",{INT_FD, &AttackWaitMax}},
			{"ScreenNumber",{INT_FD, &ScreenNumber}},
			{"WalkTimeMin",{INT_FD, &WalkTimeMin}},
			{"WalkTimeMax",{INT_FD, &WalkTimeMax}},
			{"IdleNumberMin",{INT_FD, &IdleNumberMin}},
			{"IdleNumberMax",{INT_FD, &IdleNumberMax}}
		};
	}
	virtual table_creature_vitalityT* create()
	{
		return new table_creature_vitalityT();
	}
	enum
	{
	};
	INT32 ID = 0;            //类型ID
	INT32 PopulationMin = 0;				//人口下限
	INT32 PopulationMax = 0;				//人口上限
	INT32 DiamondVitality = 0;				//付费
额外行动力
	INT32 FreeVitality = 0;				//免费
额外行动力
	INT32 BirthVitality = 0;				//出生额外体力
	INT32 BirthWaitMin = 0;				//出生等待
时间Min
	INT32 BirthWaitMax = 0;				//出生等待
时间Max
	INT32 ClickWaitMin = 0;				//点击等待
时间Min
	INT32 ClickWaitMax = 0;				//点击等待
时间Max
	INT32 BulildWaitMin = 0;				//建造完成
等待时间Min
	INT32 BulildWaitMax = 0;				//建造完成
等待时间Max
	INT32 CollectWaitMin = 0;				//采集完成
等待时间Min
	INT32 CollectWaitMax = 0;				//采集完成
等待时间Max
	INT32 AttackWaitMin = 0;				//攻击完成
等待时间Min
	INT32 AttackWaitMax = 0;				//攻击完成
等待时间Max
	INT32 ScreenNumber = 0;				//最大同屏闲置
数量
	INT32 WalkTimeMin = 0;				//溜达时间
随机区间Min
	INT32 WalkTimeMax = 0;				//溜达时间
随机区间Max
	INT32 IdleNumberMin = 0;				//原地等待
随机区间Min
	INT32 IdleNumberMax = 0;				//原地等待
随机区间Max
};
CreateCsvClass(table_creature_vitality);

struct table_dailyboxT : ConfigBaseT
{
	virtual ~table_dailyboxT()
	{
	}
	table_dailyboxT()
	{
		FileName = "table_dailybox.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"GroupID",{INT_FD, &GroupID}},
			{"Index",{INT_FD, &Index}},
			{"GoodsType1",{INT_FD, &GoodsType1}},
			{"SpriteID1",{INT_FD, &SpriteID1}},
			{"Number1",{INT_FD, &Number1}},
			{"GoodsType2",{INT_FD, &GoodsType2}},
			{"SpriteID2",{INT_FD, &SpriteID2}},
			{"Number2",{INT_FD, &Number2}},
			{"GoodsNameKey",{TSTR_FD, &GoodsNameKey}},
			{"GoodsDescKey",{TSTR_FD, &GoodsDescKey}}
		};
	}
	virtual table_dailyboxT* create()
	{
		return new table_dailyboxT();
	}
	enum
	{
	};
	INT32 ID = 0;            //序号
	INT32 GroupID = 0;				//组ID
	INT32 Index = 0;				//实际序列
	INT32 GoodsType1 = 0;				//道具类型
	INT32 SpriteID1 = 0;				//道具ID
	INT32 Number1 = 0;				//道具数量
	INT32 GoodsType2 = 0;				//道具类型
	INT32 SpriteID2 = 0;				//道具ID
	INT32 Number2 = 0;				//道具数量
	TStr GoodsNameKey = "";				//Key
	TStr GoodsDescKey = "";				//Key
};
CreateCsvClass(table_dailybox);

struct table_dropT : ConfigBaseT
{
	virtual ~table_dropT()
	{
	}
	table_dropT()
	{
		FileName = "table_drop.csv";
		_kf =
		{
			{"Id",{INT_FD, &Id}},
			{"DropId",{INT_FD, &DropId}},
			{"Respositories",{INT_FD, &Respositories}},
			{"RespositoriesPriority",{INT_FD, &RespositoriesPriority}},
			{"Probability",{FLOAT_FD, &Probability}},
			{"RandomMin",{INT_FD, &RandomMin}},
			{"RandomMax",{INT_FD, &RandomMax}},
			{"ExcludeRepeat",{INT_FD, &ExcludeRepeat}},
			{"Priority",{INT_FD, &Priority}},
			{"ItemType",{INT_FD, &ItemType}},
			{"ArticleId",{INT_FD, &ArticleId}},
			{"ProductMin",{INT_FD, &ProductMin}},
			{"ProductMax",{INT_FD, &ProductMax}},
			{"ArticleState",{INT_FD, &ArticleState}},
			{"PlaceType",{INT_FD, &PlaceType}},
			{"TweenType",{INT_FD, &TweenType}},
			{"BubbleId",{INT_FD, &BubbleId}},
			{"BubbleBigId",{FLOAT_FD, &BubbleBigId}}
		};
	}
	virtual table_dropT* create()
	{
		return new table_dropT();
	}
	enum
	{
	};
	INT32 Id = 0;            //序号
	INT32 DropId = 0;				//掉落ID
	INT32 Respositories = 0;				//子库序号
	INT32 RespositoriesPriority = 0;				//子库权值
	float Probability = 0.0f;				//几率
	INT32 RandomMin = 0;				//随机次数
Min
	INT32 RandomMax = 0;				//随机次数
Max
	INT32 ExcludeRepeat = 0;				//是否排重
	INT32 Priority = 0;				//权值
	INT32 ItemType = 0;				//产出类型
	INT32 ArticleId = 0;				//道具id
怪物ID
	INT32 ProductMin = 0;				//MIN值
	INT32 ProductMax = 0;				//MAX值
	INT32 ArticleState = 0;				//道具状态
	INT32 PlaceType = 0;				//掉落
位置规则
	INT32 TweenType = 0;				//显示
	INT32 BubbleId = 0;				//泡泡ID
	float BubbleBigId = 0.0f;				//大泡泡ID
};
CreateCsvClass(table_drop);

struct table_drop_changeT : ConfigBaseT
{
	virtual ~table_drop_changeT()
	{
	}
	table_drop_changeT()
	{
		FileName = "table_drop_change.csv";
		_kf =
		{
			{"DropID",{INT_FD, &DropID}},
			{"Level9999",{INT_FD, &Level9999}},
			{"Level9998",{INT_FD, &Level9998}},
			{"Level9997",{INT_FD, &Level9997}},
			{"Level901",{INT_FD, &Level901}},
			{"Level902",{INT_FD, &Level902}},
			{"Level903",{INT_FD, &Level903}},
			{"Level904",{INT_FD, &Level904}},
			{"Level1101",{INT_FD, &Level1101}},
			{"Level9041",{INT_FD, &Level9041}},
			{"level905",{INT_FD, &level905}},
			{"Level100",{INT_FD, &Level100}},
			{"Level101",{INT_FD, &Level101}},
			{"Level102",{INT_FD, &Level102}},
			{"Level103",{INT_FD, &Level103}},
			{"Level104",{INT_FD, &Level104}},
			{"Level105",{INT_FD, &Level105}},
			{"Level106",{INT_FD, &Level106}},
			{"Level107",{INT_FD, &Level107}},
			{"Level651",{INT_FD, &Level651}},
			{"Level501",{INT_FD, &Level501}},
			{"Level109",{INT_FD, &Level109}},
			{"Level110",{INT_FD, &Level110}},
			{"Level111",{INT_FD, &Level111}},
			{"Level112",{INT_FD, &Level112}},
			{"Level499",{INT_FD, &Level499}},
			{"Level114",{INT_FD, &Level114}},
			{"Level652",{INT_FD, &Level652}},
			{"Level502",{INT_FD, &Level502}},
			{"Level115",{INT_FD, &Level115}},
			{"Level116",{INT_FD, &Level116}},
			{"Level117",{INT_FD, &Level117}},
			{"Level653",{INT_FD, &Level653}},
			{"Level503",{INT_FD, &Level503}},
			{"Level119",{INT_FD, &Level119}},
			{"Level118",{INT_FD, &Level118}},
			{"Level654",{INT_FD, &Level654}},
			{"Level504",{INT_FD, &Level504}},
			{"Level120",{INT_FD, &Level120}},
			{"Level121",{INT_FD, &Level121}},
			{"Level122",{INT_FD, &Level122}},
			{"Level123",{INT_FD, &Level123}},
			{"Level124",{INT_FD, &Level124}},
			{"Level801",{INT_FD, &Level801}},
			{"Level125",{INT_FD, &Level125}},
			{"Level655",{INT_FD, &Level655}},
			{"Level505",{INT_FD, &Level505}},
			{"Level126",{INT_FD, &Level126}},
			{"Level128",{INT_FD, &Level128}},
			{"Level127",{INT_FD, &Level127}},
			{"Level129",{INT_FD, &Level129}},
			{"Level130",{INT_FD, &Level130}},
			{"Level133",{INT_FD, &Level133}},
			{"Level134",{INT_FD, &Level134}},
			{"Level131",{INT_FD, &Level131}},
			{"Level656",{INT_FD, &Level656}},
			{"Level506",{INT_FD, &Level506}},
			{"Level132",{INT_FD, &Level132}},
			{"Level135",{INT_FD, &Level135}},
			{"Level657",{INT_FD, &Level657}},
			{"Level507",{INT_FD, &Level507}},
			{"Level136",{INT_FD, &Level136}},
			{"Level802",{INT_FD, &Level802}},
			{"Level137",{INT_FD, &Level137}},
			{"Level138",{INT_FD, &Level138}},
			{"Level658",{INT_FD, &Level658}},
			{"Level508",{INT_FD, &Level508}},
			{"Level139",{INT_FD, &Level139}},
			{"Level140",{INT_FD, &Level140}},
			{"Level141",{INT_FD, &Level141}},
			{"Level142",{INT_FD, &Level142}},
			{"Level143",{INT_FD, &Level143}},
			{"Level144",{INT_FD, &Level144}},
			{"Level145",{INT_FD, &Level145}},
			{"Level146",{INT_FD, &Level146}},
			{"Level147",{INT_FD, &Level147}},
			{"Level659",{INT_FD, &Level659}},
			{"Level509",{INT_FD, &Level509}},
			{"Level148",{INT_FD, &Level148}},
			{"Level149",{INT_FD, &Level149}},
			{"Level150",{INT_FD, &Level150}},
			{"Level151",{INT_FD, &Level151}},
			{"Level152",{INT_FD, &Level152}},
			{"Level153",{INT_FD, &Level153}},
			{"Level660",{INT_FD, &Level660}},
			{"Level510",{INT_FD, &Level510}},
			{"Level154",{INT_FD, &Level154}},
			{"Level155",{INT_FD, &Level155}},
			{"Level156",{INT_FD, &Level156}},
			{"Level661",{INT_FD, &Level661}},
			{"Level511",{INT_FD, &Level511}},
			{"Level157",{INT_FD, &Level157}},
			{"Level158",{INT_FD, &Level158}},
			{"Level159",{INT_FD, &Level159}},
			{"Level803",{INT_FD, &Level803}},
			{"Level160",{INT_FD, &Level160}},
			{"Level161",{INT_FD, &Level161}},
			{"Level662",{INT_FD, &Level662}},
			{"Level512",{INT_FD, &Level512}},
			{"Level162",{INT_FD, &Level162}},
			{"Level163",{INT_FD, &Level163}},
			{"Level164",{INT_FD, &Level164}},
			{"Level663",{INT_FD, &Level663}},
			{"Level513",{INT_FD, &Level513}},
			{"Level165",{INT_FD, &Level165}},
			{"Level166",{INT_FD, &Level166}},
			{"Level167",{INT_FD, &Level167}},
			{"Level168",{INT_FD, &Level168}},
			{"Level804",{INT_FD, &Level804}},
			{"Level169",{INT_FD, &Level169}},
			{"Level170",{INT_FD, &Level170}},
			{"Level171",{INT_FD, &Level171}},
			{"Level172",{INT_FD, &Level172}},
			{"Level173",{INT_FD, &Level173}},
			{"Level664",{INT_FD, &Level664}},
			{"Level514",{INT_FD, &Level514}},
			{"Level174",{INT_FD, &Level174}},
			{"Level805",{INT_FD, &Level805}},
			{"Level175",{INT_FD, &Level175}},
			{"Level176",{INT_FD, &Level176}},
			{"Level177",{INT_FD, &Level177}},
			{"Level178",{INT_FD, &Level178}},
			{"Level179",{INT_FD, &Level179}},
			{"Level180",{INT_FD, &Level180}},
			{"Level665",{INT_FD, &Level665}},
			{"Level515",{INT_FD, &Level515}},
			{"Level181",{INT_FD, &Level181}},
			{"Level182",{INT_FD, &Level182}},
			{"Level183",{INT_FD, &Level183}},
			{"Level184",{INT_FD, &Level184}},
			{"Level185",{INT_FD, &Level185}},
			{"Level186",{INT_FD, &Level186}},
			{"Level806",{INT_FD, &Level806}},
			{"Level187",{INT_FD, &Level187}},
			{"Level666",{INT_FD, &Level666}},
			{"Level516",{INT_FD, &Level516}},
			{"Level807",{INT_FD, &Level807}},
			{"Level188",{INT_FD, &Level188}},
			{"Level189",{INT_FD, &Level189}},
			{"Level190",{INT_FD, &Level190}},
			{"Level191",{INT_FD, &Level191}},
			{"Level192",{INT_FD, &Level192}},
			{"Level193",{INT_FD, &Level193}},
			{"Level194",{INT_FD, &Level194}},
			{"Level667",{INT_FD, &Level667}},
			{"Level517",{INT_FD, &Level517}},
			{"Level195",{INT_FD, &Level195}},
			{"Level196",{INT_FD, &Level196}},
			{"Level197",{INT_FD, &Level197}},
			{"Level498",{INT_FD, &Level498}},
			{"Level198",{INT_FD, &Level198}},
			{"Level808",{INT_FD, &Level808}},
			{"Level199",{INT_FD, &Level199}},
			{"Level668",{INT_FD, &Level668}},
			{"Level518",{INT_FD, &Level518}},
			{"Level200",{INT_FD, &Level200}},
			{"Level201",{INT_FD, &Level201}},
			{"Level202",{INT_FD, &Level202}},
			{"Level809",{INT_FD, &Level809}},
			{"Level203",{INT_FD, &Level203}},
			{"Level204",{INT_FD, &Level204}},
			{"Level205",{INT_FD, &Level205}},
			{"Level206",{INT_FD, &Level206}},
			{"Level669",{INT_FD, &Level669}},
			{"Level519",{INT_FD, &Level519}},
			{"Level207",{INT_FD, &Level207}},
			{"Level208",{INT_FD, &Level208}},
			{"Level209",{INT_FD, &Level209}},
			{"Level810",{INT_FD, &Level810}},
			{"Level670",{INT_FD, &Level670}},
			{"Level520",{INT_FD, &Level520}},
			{"Level210",{INT_FD, &Level210}},
			{"Level211",{INT_FD, &Level211}},
			{"Level212",{INT_FD, &Level212}},
			{"Level671",{INT_FD, &Level671}},
			{"Level521",{INT_FD, &Level521}},
			{"Level213",{INT_FD, &Level213}},
			{"Level214",{INT_FD, &Level214}},
			{"Level215",{INT_FD, &Level215}},
			{"Level216",{INT_FD, &Level216}},
			{"Level217",{INT_FD, &Level217}},
			{"Level218",{INT_FD, &Level218}},
			{"Level672",{INT_FD, &Level672}},
			{"Level522",{INT_FD, &Level522}},
			{"Level219",{INT_FD, &Level219}},
			{"Level220",{INT_FD, &Level220}},
			{"Level221",{INT_FD, &Level221}},
			{"Level222",{INT_FD, &Level222}},
			{"Level223",{INT_FD, &Level223}},
			{"Level224",{INT_FD, &Level224}},
			{"Level673",{INT_FD, &Level673}},
			{"Level523",{INT_FD, &Level523}},
			{"Level225",{INT_FD, &Level225}},
			{"Level226",{INT_FD, &Level226}},
			{"Level811",{INT_FD, &Level811}},
			{"Level227",{INT_FD, &Level227}},
			{"Level228",{INT_FD, &Level228}},
			{"Level229",{INT_FD, &Level229}},
			{"Level674",{INT_FD, &Level674}},
			{"Level524",{INT_FD, &Level524}},
			{"Level230",{INT_FD, &Level230}},
			{"Level231",{INT_FD, &Level231}},
			{"Level232",{INT_FD, &Level232}},
			{"Level233",{INT_FD, &Level233}},
			{"Level675",{INT_FD, &Level675}},
			{"Level525",{INT_FD, &Level525}},
			{"Level234",{INT_FD, &Level234}},
			{"Level235",{INT_FD, &Level235}},
			{"Level236",{INT_FD, &Level236}},
			{"Level237",{INT_FD, &Level237}},
			{"Level238",{INT_FD, &Level238}},
			{"Level239",{INT_FD, &Level239}},
			{"Level240",{INT_FD, &Level240}},
			{"Level241",{INT_FD, &Level241}},
			{"Level242",{INT_FD, &Level242}},
			{"Level243",{INT_FD, &Level243}},
			{"Level244",{INT_FD, &Level244}},
			{"Level676",{INT_FD, &Level676}},
			{"Level526",{INT_FD, &Level526}},
			{"Level245",{INT_FD, &Level245}},
			{"Level812",{INT_FD, &Level812}},
			{"Level246",{INT_FD, &Level246}},
			{"Level1001",{INT_FD, &Level1001}},
			{"Level247",{INT_FD, &Level247}},
			{"Level248",{INT_FD, &Level248}},
			{"Level249",{INT_FD, &Level249}},
			{"Level250",{INT_FD, &Level250}},
			{"Level251",{INT_FD, &Level251}},
			{"Level252",{INT_FD, &Level252}},
			{"Level253",{INT_FD, &Level253}},
			{"Level677",{INT_FD, &Level677}},
			{"Level527",{INT_FD, &Level527}},
			{"Level254",{INT_FD, &Level254}},
			{"Level255",{INT_FD, &Level255}},
			{"Level256",{INT_FD, &Level256}},
			{"Level257",{INT_FD, &Level257}},
			{"Level258",{INT_FD, &Level258}},
			{"Level678",{INT_FD, &Level678}},
			{"Level528",{INT_FD, &Level528}},
			{"Level259",{INT_FD, &Level259}},
			{"Level260",{INT_FD, &Level260}},
			{"Level261",{INT_FD, &Level261}},
			{"Level262",{INT_FD, &Level262}},
			{"Level263",{INT_FD, &Level263}},
			{"Level264",{INT_FD, &Level264}},
			{"Level265",{INT_FD, &Level265}},
			{"Level266",{INT_FD, &Level266}},
			{"Level267",{INT_FD, &Level267}},
			{"level679",{INT_FD, &level679}},
			{"level529",{INT_FD, &level529}},
			{"level268",{INT_FD, &level268}},
			{"level269",{INT_FD, &level269}},
			{"level813",{INT_FD, &level813}},
			{"level270",{INT_FD, &level270}},
			{"level271",{INT_FD, &level271}},
			{"level680",{INT_FD, &level680}},
			{"level530",{INT_FD, &level530}},
			{"level814",{INT_FD, &level814}},
			{"level272",{INT_FD, &level272}},
			{"level273",{INT_FD, &level273}},
			{"level274",{INT_FD, &level274}},
			{"level275",{INT_FD, &level275}},
			{"level276",{INT_FD, &level276}},
			{"level277",{INT_FD, &level277}},
			{"level278",{INT_FD, &level278}},
			{"level279",{INT_FD, &level279}},
			{"level815",{INT_FD, &level815}},
			{"level280",{INT_FD, &level280}},
			{"level281",{INT_FD, &level281}},
			{"level282",{INT_FD, &level282}},
			{"level283",{INT_FD, &level283}},
			{"level284",{INT_FD, &level284}},
			{"level285",{INT_FD, &level285}},
			{"level816",{INT_FD, &level816}},
			{"level286",{INT_FD, &level286}},
			{"level287",{INT_FD, &level287}}
		};
	}
	virtual table_drop_changeT* create()
	{
		return new table_drop_changeT();
	}
	enum
	{
	};
	INT32 DropID = 0;            //掉落id
	INT32 Level9999 = 0;				//家园
	INT32 Level9998 = 0;				//世界地图
	INT32 Level9997 = 0;				//前哨
	INT32 Level901 = 0;				//活动1
	INT32 Level902 = 0;				//活动2
	INT32 Level903 = 0;				//活动3
	INT32 Level904 = 0;				//活动4
	INT32 Level1101 = 0;				//活动1复制
	INT32 Level9041 = 0;				//活动4复制
	INT32 level905 = 0;				//活动5
	INT32 Level100 = 0;				//关卡1
	INT32 Level101 = 0;				//关卡2
	INT32 Level102 = 0;				//关卡3
	INT32 Level103 = 0;				//关卡4
	INT32 Level104 = 0;				//关卡5
	INT32 Level105 = 0;				//关卡6
	INT32 Level106 = 0;				//关卡7
	INT32 Level107 = 0;				//关卡8
	INT32 Level651 = 0;				//关卡9
	INT32 Level501 = 0;				//关卡10
	INT32 Level109 = 0;				//关卡11
	INT32 Level110 = 0;				//关卡12
	INT32 Level111 = 0;				//关卡13
	INT32 Level112 = 0;				//关卡14
	INT32 Level499 = 0;				//关卡15
	INT32 Level114 = 0;				//关卡16
	INT32 Level652 = 0;				//关卡17
	INT32 Level502 = 0;				//关卡18
	INT32 Level115 = 0;				//关卡19
	INT32 Level116 = 0;				//关卡20
	INT32 Level117 = 0;				//关卡21
	INT32 Level653 = 0;				//关卡22
	INT32 Level503 = 0;				//关卡23
	INT32 Level119 = 0;				//关卡24
	INT32 Level118 = 0;				//关卡25
	INT32 Level654 = 0;				//关卡26
	INT32 Level504 = 0;				//关卡27
	INT32 Level120 = 0;				//关卡28
	INT32 Level121 = 0;				//关卡29
	INT32 Level122 = 0;				//关卡30
	INT32 Level123 = 0;				//关卡31
	INT32 Level124 = 0;				//关卡32
	INT32 Level801 = 0;				//关卡33
	INT32 Level125 = 0;				//关卡34
	INT32 Level655 = 0;				//关卡35
	INT32 Level505 = 0;				//关卡36
	INT32 Level126 = 0;				//关卡37
	INT32 Level128 = 0;				//关卡38
	INT32 Level127 = 0;				//关卡39
	INT32 Level129 = 0;				//关卡40
	INT32 Level130 = 0;				//关卡41
	INT32 Level133 = 0;				//关卡42
	INT32 Level134 = 0;				//关卡43
	INT32 Level131 = 0;				//关卡44
	INT32 Level656 = 0;				//关卡45
	INT32 Level506 = 0;				//关卡46
	INT32 Level132 = 0;				//关卡47
	INT32 Level135 = 0;				//关卡48
	INT32 Level657 = 0;				//关卡49
	INT32 Level507 = 0;				//关卡50
	INT32 Level136 = 0;				//关卡51
	INT32 Level802 = 0;				//关卡52
	INT32 Level137 = 0;				//关卡53
	INT32 Level138 = 0;				//关卡54
	INT32 Level658 = 0;				//关卡55
	INT32 Level508 = 0;				//关卡56
	INT32 Level139 = 0;				//关卡57
	INT32 Level140 = 0;				//关卡58
	INT32 Level141 = 0;				//关卡59
	INT32 Level142 = 0;				//关卡60
	INT32 Level143 = 0;				//关卡61
	INT32 Level144 = 0;				//关卡62
	INT32 Level145 = 0;				//关卡63
	INT32 Level146 = 0;				//关卡64
	INT32 Level147 = 0;				//关卡65
	INT32 Level659 = 0;				//关卡66
	INT32 Level509 = 0;				//关卡67
	INT32 Level148 = 0;				//关卡68
	INT32 Level149 = 0;				//关卡69
	INT32 Level150 = 0;				//关卡70
	INT32 Level151 = 0;				//关卡71
	INT32 Level152 = 0;				//关卡72
	INT32 Level153 = 0;				//关卡73
	INT32 Level660 = 0;				//关卡74
	INT32 Level510 = 0;				//关卡75
	INT32 Level154 = 0;				//关卡76
	INT32 Level155 = 0;				//关卡77
	INT32 Level156 = 0;				//关卡78
	INT32 Level661 = 0;				//关卡79
	INT32 Level511 = 0;				//关卡80
	INT32 Level157 = 0;				//关卡81
	INT32 Level158 = 0;				//关卡82
	INT32 Level159 = 0;				//关卡83
	INT32 Level803 = 0;				//关卡84
	INT32 Level160 = 0;				//关卡85
	INT32 Level161 = 0;				//关卡86
	INT32 Level662 = 0;				//关卡87
	INT32 Level512 = 0;				//关卡88
	INT32 Level162 = 0;				//关卡89
	INT32 Level163 = 0;				//关卡90
	INT32 Level164 = 0;				//关卡91
	INT32 Level663 = 0;				//关卡92
	INT32 Level513 = 0;				//关卡93
	INT32 Level165 = 0;				//关卡94
	INT32 Level166 = 0;				//关卡95
	INT32 Level167 = 0;				//关卡96
	INT32 Level168 = 0;				//关卡97
	INT32 Level804 = 0;				//关卡98
	INT32 Level169 = 0;				//关卡99
	INT32 Level170 = 0;				//关卡100
	INT32 Level171 = 0;				//关卡101
	INT32 Level172 = 0;				//关卡102
	INT32 Level173 = 0;				//关卡103
	INT32 Level664 = 0;				//关卡104
	INT32 Level514 = 0;				//关卡105
	INT32 Level174 = 0;				//关卡106
	INT32 Level805 = 0;				//关卡107
	INT32 Level175 = 0;				//关卡108
	INT32 Level176 = 0;				//关卡109
	INT32 Level177 = 0;				//关卡110
	INT32 Level178 = 0;				//关卡111
	INT32 Level179 = 0;				//关卡112
	INT32 Level180 = 0;				//关卡113
	INT32 Level665 = 0;				//关卡114
	INT32 Level515 = 0;				//关卡115
	INT32 Level181 = 0;				//关卡116
	INT32 Level182 = 0;				//关卡117
	INT32 Level183 = 0;				//关卡118
	INT32 Level184 = 0;				//关卡119
	INT32 Level185 = 0;				//关卡120
	INT32 Level186 = 0;				//关卡121
	INT32 Level806 = 0;				//关卡122
	INT32 Level187 = 0;				//关卡123
	INT32 Level666 = 0;				//关卡124
	INT32 Level516 = 0;				//关卡125
	INT32 Level807 = 0;				//关卡126
	INT32 Level188 = 0;				//关卡127
	INT32 Level189 = 0;				//关卡128
	INT32 Level190 = 0;				//关卡129
	INT32 Level191 = 0;				//关卡130
	INT32 Level192 = 0;				//关卡131
	INT32 Level193 = 0;				//关卡132
	INT32 Level194 = 0;				//关卡133
	INT32 Level667 = 0;				//关卡134
	INT32 Level517 = 0;				//关卡135
	INT32 Level195 = 0;				//关卡136
	INT32 Level196 = 0;				//关卡137
	INT32 Level197 = 0;				//关卡138
	INT32 Level498 = 0;				//关卡139
	INT32 Level198 = 0;				//关卡140
	INT32 Level808 = 0;				//关卡141
	INT32 Level199 = 0;				//关卡142
	INT32 Level668 = 0;				//关卡143
	INT32 Level518 = 0;				//关卡144
	INT32 Level200 = 0;				//关卡145
	INT32 Level201 = 0;				//关卡146
	INT32 Level202 = 0;				//关卡147
	INT32 Level809 = 0;				//关卡148
	INT32 Level203 = 0;				//关卡149
	INT32 Level204 = 0;				//关卡150
	INT32 Level205 = 0;				//关卡151
	INT32 Level206 = 0;				//关卡152
	INT32 Level669 = 0;				//关卡153
	INT32 Level519 = 0;				//关卡154
	INT32 Level207 = 0;				//关卡155
	INT32 Level208 = 0;				//关卡156
	INT32 Level209 = 0;				//关卡157
	INT32 Level810 = 0;				//关卡158
	INT32 Level670 = 0;				//关卡159
	INT32 Level520 = 0;				//关卡160
	INT32 Level210 = 0;				//关卡161
	INT32 Level211 = 0;				//关卡162
	INT32 Level212 = 0;				//关卡163
	INT32 Level671 = 0;				//关卡164
	INT32 Level521 = 0;				//关卡165
	INT32 Level213 = 0;				//关卡166
	INT32 Level214 = 0;				//关卡167
	INT32 Level215 = 0;				//关卡168
	INT32 Level216 = 0;				//关卡169
	INT32 Level217 = 0;				//关卡170
	INT32 Level218 = 0;				//关卡171
	INT32 Level672 = 0;				//关卡172
	INT32 Level522 = 0;				//关卡173
	INT32 Level219 = 0;				//关卡174
	INT32 Level220 = 0;				//关卡175
	INT32 Level221 = 0;				//关卡176
	INT32 Level222 = 0;				//关卡177
	INT32 Level223 = 0;				//关卡178
	INT32 Level224 = 0;				//关卡179
	INT32 Level673 = 0;				//关卡180
	INT32 Level523 = 0;				//关卡181
	INT32 Level225 = 0;				//关卡182
	INT32 Level226 = 0;				//关卡183
	INT32 Level811 = 0;				//关卡184
	INT32 Level227 = 0;				//关卡185
	INT32 Level228 = 0;				//关卡186
	INT32 Level229 = 0;				//关卡187
	INT32 Level674 = 0;				//关卡188
	INT32 Level524 = 0;				//关卡189
	INT32 Level230 = 0;				//关卡190
	INT32 Level231 = 0;				//关卡191
	INT32 Level232 = 0;				//关卡192
	INT32 Level233 = 0;				//关卡193
	INT32 Level675 = 0;				//关卡194
	INT32 Level525 = 0;				//关卡195
	INT32 Level234 = 0;				//关卡196
	INT32 Level235 = 0;				//关卡197
	INT32 Level236 = 0;				//关卡198
	INT32 Level237 = 0;				//关卡199
	INT32 Level238 = 0;				//关卡200
	INT32 Level239 = 0;				//关卡201
	INT32 Level240 = 0;				//关卡202
	INT32 Level241 = 0;				//关卡204
	INT32 Level242 = 0;				//关卡205
	INT32 Level243 = 0;				//关卡206
	INT32 Level244 = 0;				//关卡207
	INT32 Level676 = 0;				//关卡208
	INT32 Level526 = 0;				//关卡209
	INT32 Level245 = 0;				//关卡210
	INT32 Level812 = 0;				//关卡211
	INT32 Level246 = 0;				//关卡212
	INT32 Level1001 = 0;				//关卡213
	INT32 Level247 = 0;				//关卡214
	INT32 Level248 = 0;				//关卡215
	INT32 Level249 = 0;				//关卡216
	INT32 Level250 = 0;				//关卡217
	INT32 Level251 = 0;				//关卡218
	INT32 Level252 = 0;				//关卡219
	INT32 Level253 = 0;				//关卡220
	INT32 Level677 = 0;				//关卡221
	INT32 Level527 = 0;				//关卡222
	INT32 Level254 = 0;				//关卡223
	INT32 Level255 = 0;				//关卡224
	INT32 Level256 = 0;				//关卡225
	INT32 Level257 = 0;				//关卡228
	INT32 Level258 = 0;				//关卡229
	INT32 Level678 = 0;				//关卡230
	INT32 Level528 = 0;				//关卡231
	INT32 Level259 = 0;				//关卡232
	INT32 Level260 = 0;				//关卡233
	INT32 Level261 = 0;				//关卡234
	INT32 Level262 = 0;				//关卡235
	INT32 Level263 = 0;				//关卡236
	INT32 Level264 = 0;				//关卡237
	INT32 Level265 = 0;				//关卡238
	INT32 Level266 = 0;				//关卡239
	INT32 Level267 = 0;				//关卡240
	INT32 level679 = 0;				//关卡241
	INT32 level529 = 0;				//关卡242
	INT32 level268 = 0;				//关卡243
	INT32 level269 = 0;				//关卡244
	INT32 level813 = 0;				//关卡245
	INT32 level270 = 0;				//关卡246
	INT32 level271 = 0;				//关卡247
	INT32 level680 = 0;				//关卡248
	INT32 level530 = 0;				//关卡249
	INT32 level814 = 0;				//关卡250
	INT32 level272 = 0;				//关卡251
	INT32 level273 = 0;				//关卡252
	INT32 level274 = 0;				//关卡253
	INT32 level275 = 0;				//关卡254
	INT32 level276 = 0;				//关卡255
	INT32 level277 = 0;				//关卡256
	INT32 level278 = 0;				//关卡257
	INT32 level279 = 0;				//关卡258
	INT32 level815 = 0;				//关卡259
	INT32 level280 = 0;				//关卡260
	INT32 level281 = 0;				//关卡261
	INT32 level282 = 0;				//关卡262
	INT32 level283 = 0;				//关卡263
	INT32 level284 = 0;				//关卡264
	INT32 level285 = 0;				//关卡265
	INT32 level816 = 0;				//关卡266
	INT32 level286 = 0;				//关卡267
	INT32 level287 = 0;				//关卡268
};
CreateCsvClass(table_drop_change);

struct table_encyclopaediaT : ConfigBaseT
{
	virtual ~table_encyclopaediaT()
	{
	}
	table_encyclopaediaT()
	{
		FileName = "table_encyclopaedia.csv";
		_kf =
		{
			{"ChainGroupID",{INT_FD, &ChainGroupID}},
			{"SubtabID",{INT_FD, &SubtabID}},
			{"ChainGroupName",{TSTR_FD, &ChainGroupName}},
			{"ShowOrder",{INT_FD, &ShowOrder}},
			{"ChainInShow",{INT_FD, &ChainInShow}},
			{"ChainCoverImage",{TSTR_FD, &ChainCoverImage}},
			{"ChainColorName",{TSTR_FD, &ChainColorName}},
			{"ChainTabImage",{TSTR_FD, &ChainTabImage}},
			{"ChainGroupPopulationMin",{INT_FD, &ChainGroupPopulationMin}},
			{"GoodsID",{INT_FD, &GoodsID}},
			{"remark",{TSTR_FD, &remark}},
			{"ChainGroupNameKey",{TSTR_FD, &ChainGroupNameKey}}
		};
	}
	virtual table_encyclopaediaT* create()
	{
		return new table_encyclopaediaT();
	}
	enum
	{
	};
	INT32 ChainGroupID = 0;            //合成链组ID
	INT32 SubtabID = 0;				//页签ID
	TStr ChainGroupName = "";				//名称
	INT32 ShowOrder = 0;				//序号
	INT32 ChainInShow = 0;				//是否在图鉴里显示
	TStr ChainCoverImage = "";				//链组图集图片
	TStr ChainColorName = "";				//链组图集颜色底图
	TStr ChainTabImage = "";				//链组页签图片
	INT32 ChainGroupPopulationMin = 0;				//人口界面显示的最小ID
	INT32 GoodsID = 0;				//商品ID
	TStr remark = "";				//备注
	TStr ChainGroupNameKey = "";				//Key
};
CreateCsvClass(table_encyclopaedia);

struct table_healing_cellT : ConfigBaseT
{
	virtual ~table_healing_cellT()
	{
	}
	table_healing_cellT()
	{
		FileName = "table_healing_cell.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"ScopeMin",{INT_FD, &ScopeMin}},
			{"ScopeMax",{INT_FD, &ScopeMax}},
			{"Index",{INT_FD, &Index}},
			{"ResName",{TSTR_FD, &ResName}},
			{"Sound",{TSTR_FD, &Sound}}
		};
	}
	virtual table_healing_cellT* create()
	{
		return new table_healing_cellT();
	}
	enum
	{
	};
	INT32 ID = 0;            //序号
	INT32 ScopeMin = 0;				//地块所需治愈值Min
	INT32 ScopeMax = 0;				//地块所需治愈值Max
	INT32 Index = 0;				//治愈特效
播放位置
	TStr ResName = "";				//治愈特效
	TStr Sound = "";				//治愈音效
};
CreateCsvClass(table_healing_cell);

struct table_healing_showT : ConfigBaseT
{
	virtual ~table_healing_showT()
	{
	}
	table_healing_showT()
	{
		FileName = "table_healing_show.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"ScopeMin",{INT_FD, &ScopeMin}},
			{"ScopeMax",{INT_FD, &ScopeMax}},
			{"Number",{INT_FD, &Number}},
			{"ResName",{TSTR_FD, &ResName}},
			{"Arrive",{TSTR_FD, &Arrive}},
			{"Enlarge",{FLOAT_FD, &Enlarge}}
		};
	}
	virtual table_healing_showT* create()
	{
		return new table_healing_showT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	INT32 ScopeMin = 0;				//(区间
	INT32 ScopeMax = 0;				//区间]
	INT32 Number = 0;				//单位
	TStr ResName = "";				//飞跃过程特效
	TStr Arrive = "";				//飞到特效
	float Enlarge = 0.0f;				//特效缩放比例
};
CreateCsvClass(table_healing_show);

struct table_heroT : ConfigBaseT
{
	virtual ~table_heroT()
	{
	}
	table_heroT()
	{
		FileName = "table_hero.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"HeroType",{INT_FD, &HeroType}},
			{"HeroExperience",{INT_FD, &HeroExperience}},
			{"ActionSwitch",{INT_FD, &ActionSwitch}},
			{"ActionSwitchPara",{INT_FD, &ActionSwitchPara}},
			{"SkinCount",{INT_FD, &SkinCount}},
			{"SkillCD",{INT_FD, &SkillCD}},
			{"SkillCount",{INT_FD, &SkillCount}},
			{"CollectTrend0Switch",{INT_FD, &CollectTrend0Switch}},
			{"CollectTrend0Para",{INT_FD, &CollectTrend0Para}},
			{"CollectTrend1Switch",{INT_FD, &CollectTrend1Switch}},
			{"CollectTrend1Para",{INT_FD, &CollectTrend1Para}},
			{"CollectTrend2Switch",{INT_FD, &CollectTrend2Switch}},
			{"CollectTrend2Para",{INT_FD, &CollectTrend2Para}},
			{"CollectTrend3Switch",{INT_FD, &CollectTrend3Switch}},
			{"CollectTrend3Para",{INT_FD, &CollectTrend3Para}},
			{"Skin0Switch",{INT_FD, &Skin0Switch}},
			{"Skin0SwitchPara1",{INT_FD, &Skin0SwitchPara1}},
			{"Skin0SwitchPara2",{INT_FD, &Skin0SwitchPara2}},
			{"Skin0SwitchPara3",{INT_FD, &Skin0SwitchPara3}},
			{"Skin0Resource",{TSTR_FD, &Skin0Resource}},
			{"Skin0HeadResource",{TSTR_FD, &Skin0HeadResource}},
			{"Skin1Switch",{INT_FD, &Skin1Switch}},
			{"Skin1SwitchPara1",{INT_FD, &Skin1SwitchPara1}},
			{"Skin1SwitchPara2",{INT_FD, &Skin1SwitchPara2}},
			{"Skin1SwitchPara3",{INT_FD, &Skin1SwitchPara3}},
			{"Skin1Resource",{TSTR_FD, &Skin1Resource}},
			{"Skin1HeadResource",{TSTR_FD, &Skin1HeadResource}},
			{"invitation",{INT_FD, &invitation}},
			{"price",{INT_FD, &price}}
		};
	}
	virtual table_heroT* create()
	{
		return new table_heroT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	INT32 HeroType = 0;				//英雄类ID
	INT32 HeroExperience = 0;				//免费体验无限行动力
时间
	INT32 ActionSwitch = 0;				//开启无限行动力
条件种类
	INT32 ActionSwitchPara = 0;				//开启无限体力
条件参数
	INT32 SkinCount = 0;				//拥有皮肤数量
	INT32 SkillCD = 0;				//技能恢复时间
	INT32 SkillCount = 0;				//技能时间
触发次数
	INT32 CollectTrend0Switch = 0;				//采集倾向0开启条件
	INT32 CollectTrend0Para = 0;				//采集倾向0开启条件
参数
	INT32 CollectTrend1Switch = 0;				//采集倾向1开启条件
	INT32 CollectTrend1Para = 0;				//采集倾向1开启条件
参数
	INT32 CollectTrend2Switch = 0;				//采集倾向2开启条件
	INT32 CollectTrend2Para = 0;				//采集倾向2开启条件
参数
	INT32 CollectTrend3Switch = 0;				//采集倾向3开启条件
	INT32 CollectTrend3Para = 0;				//采集倾向3开启条件
参数
	INT32 Skin0Switch = 0;				//皮肤1开启条件种类
	INT32 Skin0SwitchPara1 = 0;				//皮肤1开启条件
参数1
	INT32 Skin0SwitchPara2 = 0;				//皮肤1开启条件
参数2
	INT32 Skin0SwitchPara3 = 0;				//皮肤1开启条件
参数3
	TStr Skin0Resource = "";				//皮肤1资源
	TStr Skin0HeadResource = "";				//皮肤1头像资源
	INT32 Skin1Switch = 0;				//皮肤2开启条件种类
	INT32 Skin1SwitchPara1 = 0;				//皮肤2开启条件
参数1
	INT32 Skin1SwitchPara2 = 0;				//皮肤2开启条件
参数2
	INT32 Skin1SwitchPara3 = 0;				//皮肤2开启条件
参数3
	TStr Skin1Resource = "";				//皮肤2资源
	TStr Skin1HeadResource = "";				//皮肤2头像资源
	INT32 invitation = 0;				//能否邀请
	INT32 price = 0;				//价格（钻石）
};
CreateCsvClass(table_hero);

struct table_homelevelT : ConfigBaseT
{
	virtual ~table_homelevelT()
	{
	}
	table_homelevelT()
	{
		FileName = "table_homelevel.csv";
		_kf =
		{
			{"Home_Level",{INT_FD, &Home_Level}},
			{"Score",{INT_FD, &Score}}
		};
	}
	virtual table_homelevelT* create()
	{
		return new table_homelevelT();
	}
	enum
	{
	};
	INT32 Home_Level = 0;            //家园等级
	INT32 Score = 0;				//积分上限
};
CreateCsvClass(table_homelevel);

struct table_hotfixT : ConfigBaseT
{
	virtual ~table_hotfixT()
	{
	}
	table_hotfixT()
	{
		FileName = "table_hotfix.csv";
		_kf =
		{
			{"NumID",{INT_FD, &NumID}},
			{"Versions",{TSTR_FD, &Versions}},
			{"TargetType",{INT_FD, &TargetType}},
			{"Method",{INT_FD, &Method}},
			{"Parameter1",{INT_FD, &Parameter1}},
			{"Value",{TSTR_FD, &Value}},
			{"ConditionID",{TSTR_FD, &ConditionID}}
		};
	}
	virtual table_hotfixT* create()
	{
		return new table_hotfixT();
	}
	enum
	{
	};
	INT32 NumID = 0;            //流水号
	TStr Versions = "";				//版本号
	INT32 TargetType = 0;				//目标类型
	INT32 Method = 0;				//修改方式
	INT32 Parameter1 = 0;				//类型参数1
	TStr Value = "";				//修正值
	TStr ConditionID = "";				//条件
};
CreateCsvClass(table_hotfix);

struct table_hotfix_conditionT : ConfigBaseT
{
	virtual ~table_hotfix_conditionT()
	{
	}
	table_hotfix_conditionT()
	{
		FileName = "table_hotfix_condition.csv";
		_kf =
		{
			{"ConditionID",{INT_FD, &ConditionID}},
			{"Operators",{INT_FD, &Operators}},
			{"Parameter1",{INT_FD, &Parameter1}},
			{"Parameter2",{TSTR_FD, &Parameter2}}
		};
	}
	virtual table_hotfix_conditionT* create()
	{
		return new table_hotfix_conditionT();
	}
	enum
	{
	};
	INT32 ConditionID = 0;            //条件ID
	INT32 Operators = 0;				//条件操作符
	INT32 Parameter1 = 0;				//条件参数1
	TStr Parameter2 = "";				//条件参数2
};
CreateCsvClass(table_hotfix_condition);

struct table_levelT : ConfigBaseT
{
	virtual ~table_levelT()
	{
	}
	table_levelT()
	{
		FileName = "table_level.csv";
		_kf =
		{
			{"Id",{INT_FD, &Id}},
			{"Type",{INT_FD, &Type}},
			{"FlowType",{INT_FD, &FlowType}},
			{"Name",{TSTR_FD, &Name}},
			{"Icon",{TSTR_FD, &Icon}},
			{"Map",{TSTR_FD, &Map}},
			{"Tutorial",{INT_FD, &Tutorial}},
			{"LockedId",{INT_FD, &LockedId}},
			{"LevelGroup",{INT_FD, &LevelGroup}},
			{"EnergyExpend",{INT_FD, &EnergyExpend}},
			{"PreviewReward1Type",{INT_FD, &PreviewReward1Type}},
			{"PreviewReward1Id",{INT_FD, &PreviewReward1Id}},
			{"PreviewReward2Type",{INT_FD, &PreviewReward2Type}},
			{"PreviewReward2Id",{INT_FD, &PreviewReward2Id}},
			{"PreviewReward3Type",{INT_FD, &PreviewReward3Type}},
			{"PreviewReward3Id",{INT_FD, &PreviewReward3Id}},
			{"RepetitiveReward1Type",{INT_FD, &RepetitiveReward1Type}},
			{"RepetitiveReward1Id",{INT_FD, &RepetitiveReward1Id}},
			{"RepetitiveReward2Type",{INT_FD, &RepetitiveReward2Type}},
			{"RepetitiveReward2Id",{INT_FD, &RepetitiveReward2Id}},
			{"RepetitiveReward3Type",{INT_FD, &RepetitiveReward3Type}},
			{"RepetitiveReward3Id",{INT_FD, &RepetitiveReward3Id}},
			{"Task1Id",{INT_FD, &Task1Id}},
			{"Task2Id",{INT_FD, &Task2Id}},
			{"Task3Id",{INT_FD, &Task3Id}},
			{"CompletedConditionType",{INT_FD, &CompletedConditionType}},
			{"CompletedConditionId",{INT_FD, &CompletedConditionId}},
			{"CompletedConditionNum",{INT_FD, &CompletedConditionNum}},
			{"CompletedConditionTitle",{TSTR_FD, &CompletedConditionTitle}},
			{"CompletedConditionDescribe",{TSTR_FD, &CompletedConditionDescribe}},
			{"LimitingTime1",{INT_FD, &LimitingTime1}},
			{"TimeBoughtType1",{INT_FD, &TimeBoughtType1}},
			{"LimitingTime2",{INT_FD, &LimitingTime2}},
			{"TimeBoughtType2",{INT_FD, &TimeBoughtType2}},
			{"LimitingTime3",{INT_FD, &LimitingTime3}},
			{"TimeBoughtType3",{INT_FD, &TimeBoughtType3}},
			{"ReplacedNeedValue",{INT_FD, &ReplacedNeedValue}},
			{"ReplacedId",{INT_FD, &ReplacedId}},
			{"RepetitiveRewardWhetherNeedRecordReplaced",{INT_FD, &RepetitiveRewardWhetherNeedRecordReplaced}},
			{"StarType",{INT_FD, &StarType}},
			{"StarParameter1",{INT_FD, &StarParameter1}},
			{"StarParameter2",{INT_FD, &StarParameter2}},
			{"StarParameter3",{INT_FD, &StarParameter3}},
			{"ShopSwitch",{INT_FD, &ShopSwitch}},
			{"ShopGrpupId",{INT_FD, &ShopGrpupId}},
			{"BoxType",{INT_FD, &BoxType}},
			{"ZeroStarFreeAward",{INT_FD, &ZeroStarFreeAward}},
			{"OneStarFreeAward",{INT_FD, &OneStarFreeAward}},
			{"OneStarExtraPrice",{INT_FD, &OneStarExtraPrice}},
			{"TwoStarFreeAward",{INT_FD, &TwoStarFreeAward}},
			{"TwoStarExtraPrice",{INT_FD, &TwoStarExtraPrice}},
			{"ThreeStarFreeAward",{INT_FD, &ThreeStarFreeAward}},
			{"ThreeStarExtraPrice",{INT_FD, &ThreeStarExtraPrice}},
			{"Appear1Id",{INT_FD, &Appear1Id}},
			{"Appear1Value",{INT_FD, &Appear1Value}},
			{"Appear2Id",{INT_FD, &Appear2Id}},
			{"Appear2Value",{INT_FD, &Appear2Value}},
			{"Appear3Id",{INT_FD, &Appear3Id}},
			{"Appear3Value",{INT_FD, &Appear3Value}},
			{"SettledPaidAwardId",{INT_FD, &SettledPaidAwardId}},
			{"PaidAwardSceneNumMin",{INT_FD, &PaidAwardSceneNumMin}},
			{"PaidAwardSceneNumMax",{INT_FD, &PaidAwardSceneNumMax}},
			{"ExtraPaidAwardPossibility",{FLOAT_FD, &ExtraPaidAwardPossibility}},
			{"ExtraPaidAwardId",{INT_FD, &ExtraPaidAwardId}},
			{"StartTime",{INT_FD, &StartTime}},
			{"EndTime",{INT_FD, &EndTime}},
			{"ExtractionId",{INT_FD, &ExtractionId}},
			{"AutoFreeId",{INT_FD, &AutoFreeId}},
			{"CostType",{INT_FD, &CostType}},
			{"Backgroundmusic",{TSTR_FD, &Backgroundmusic}},
			{"IntoSound",{TSTR_FD, &IntoSound}},
			{"LeftSound",{TSTR_FD, &LeftSound}},
			{"SuccessSound",{TSTR_FD, &SuccessSound}},
			{"FailedSound",{TSTR_FD, &FailedSound}},
			{"RedoSound",{TSTR_FD, &RedoSound}},
			{"NewlevelSound",{TSTR_FD, &NewlevelSound}},
			{"HiddenlevelSound",{TSTR_FD, &HiddenlevelSound}},
			{"Calculus",{INT_FD, &Calculus}},
			{"NameKey",{TSTR_FD, &NameKey}},
			{"CompletedConditionTitleKey",{TSTR_FD, &CompletedConditionTitleKey}},
			{"CompletedConditionDescribeKey",{TSTR_FD, &CompletedConditionDescribeKey}},
			{"AwardUI",{INT_FD, &AwardUI}}
		};
	}
	virtual table_levelT* create()
	{
		return new table_levelT();
	}
	enum
	{
	};
	INT32 Id = 0;            //关卡id
	INT32 Type = 0;				//关卡类型
	INT32 FlowType = 0;				//流程类型
	TStr Name = "";				//关卡名称
	TStr Icon = "";				//关卡图标
	TStr Map = "";				//调用地图
	INT32 Tutorial = 0;				//是否出现指引
	INT32 LockedId = 0;				//前置关卡
	INT32 LevelGroup = 0;				//后置关卡组
	INT32 EnergyExpend = 0;				//体力消耗
	INT32 PreviewReward1Type = 0;				//预览奖励1类型
	INT32 PreviewReward1Id = 0;				//预览奖励1ID
	INT32 PreviewReward2Type = 0;				//预览奖励2类型
	INT32 PreviewReward2Id = 0;				//预览奖励2ID
	INT32 PreviewReward3Type = 0;				//预览奖励3类型
	INT32 PreviewReward3Id = 0;				//预览奖励3ID
	INT32 RepetitiveReward1Type = 0;				//重复通关奖励1类型
	INT32 RepetitiveReward1Id = 0;				//重复通关奖励1ID
	INT32 RepetitiveReward2Type = 0;				//重复通关奖励2类型
	INT32 RepetitiveReward2Id = 0;				//重复通关奖励2ID
	INT32 RepetitiveReward3Type = 0;				//重复通关奖励3类型
	INT32 RepetitiveReward3Id = 0;				//重复通关奖励3ID
	INT32 Task1Id = 0;				//任务1ID
	INT32 Task2Id = 0;				//任务2ID
	INT32 Task3Id = 0;				//任务3ID
	INT32 CompletedConditionType = 0;				//过关条件类型
	INT32 CompletedConditionId = 0;				//过关条件ID
	INT32 CompletedConditionNum = 0;				//过关条件数量
	TStr CompletedConditionTitle = "";				//过关条件题头
	TStr CompletedConditionDescribe = "";				//过关条件说明
	INT32 LimitingTime1 = 0;				//时间限制1
	INT32 TimeBoughtType1 = 0;				//时间购买类型1
	INT32 LimitingTime2 = 0;				//时间限制2
	INT32 TimeBoughtType2 = 0;				//时间购买类型2
	INT32 LimitingTime3 = 0;				//时间限制3
	INT32 TimeBoughtType3 = 0;				//时间购买类型3
	INT32 ReplacedNeedValue = 0;				//关卡替换需通关次数
	INT32 ReplacedId = 0;				//关卡替换ID
	INT32 RepetitiveRewardWhetherNeedRecordReplaced = 0;				//重复通关奖励是否记录替换前关卡
	INT32 StarType = 0;				//关卡星级判定类型
	INT32 StarParameter1 = 0;				//星级判定
参数1
	INT32 StarParameter2 = 0;				//星级判定
参数2
	INT32 StarParameter3 = 0;				//星级判定
参数3
	INT32 ShopSwitch = 0;				//关卡商店
是否开启
	INT32 ShopGrpupId = 0;				//关卡商店
商品组ID
	INT32 BoxType = 0;				//宝箱奖励类型
	INT32 ZeroStarFreeAward = 0;				//零星免费奖励
	INT32 OneStarFreeAward = 0;				//一星免费奖励
	INT32 OneStarExtraPrice = 0;				//一星额外付费奖励价格
	INT32 TwoStarFreeAward = 0;				//二星免费奖励
	INT32 TwoStarExtraPrice = 0;				//二星额外付费奖励价格
	INT32 ThreeStarFreeAward = 0;				//三星免费奖励
	INT32 ThreeStarExtraPrice = 0;				//三星额外付费奖励价格
	INT32 Appear1Id = 0;				//关卡结算时冒出
物品1掉落ID
	INT32 Appear1Value = 0;				//关卡结算时冒出
物品1掉落权值
	INT32 Appear2Id = 0;				//关卡结算时冒出
物品2掉落ID
	INT32 Appear2Value = 0;				//关卡结算时冒出
物品2掉落权值
	INT32 Appear3Id = 0;				//关卡结算时冒出
物品3掉落ID
	INT32 Appear3Value = 0;				//关卡结算时冒出
物品3掉落权值
	INT32 SettledPaidAwardId = 0;				//固定付费奖励掉落ID
	INT32 PaidAwardSceneNumMin = 0;				//付费奖励场上道具
随机数量MIN
	INT32 PaidAwardSceneNumMax = 0;				//付费奖励场上道具
随机数量MAX
	float ExtraPaidAwardPossibility = 0.0f;				//额外付费奖励
概率
	INT32 ExtraPaidAwardId = 0;				//额外付费奖励
掉落ID
	INT32 StartTime = 0;				//开启时间
	INT32 EndTime = 0;				//关闭时间
	INT32 ExtractionId = 0;				//抽取掉落库
	INT32 AutoFreeId = 0;				//自动免费
掉落ID
	INT32 CostType = 0;				//龙干活消耗值
	TStr Backgroundmusic = "";				//背景音乐
	TStr IntoSound = "";				//进入自己营地音效
	TStr LeftSound = "";				//离开营地音效
	TStr SuccessSound = "";				//关卡成功音效
	TStr FailedSound = "";				//关卡失败音效
	TStr RedoSound = "";				//关卡重来音效
	TStr NewlevelSound = "";				//新关卡开启音效
	TStr HiddenlevelSound = "";				//隐藏关卡发现音效
	INT32 Calculus = 0;				//是否演算
	TStr NameKey = "";				//关卡名称
	TStr CompletedConditionTitleKey = "";				//过关条件题头
	TStr CompletedConditionDescribeKey = "";				//过关条件说明
	INT32 AwardUI = 0;				//结算后是够有奖励界面
};
CreateCsvClass(table_level);

struct table_level_boxT : ConfigBaseT
{
	virtual ~table_level_boxT()
	{
	}
	table_level_boxT()
	{
		FileName = "table_level_box.csv";
		_kf =
		{
			{"Id",{INT_FD, &Id}},
			{"BoxType",{INT_FD, &BoxType}},
			{"JudgeValue",{INT_FD, &JudgeValue}},
			{"Box1Id",{INT_FD, &Box1Id}},
			{"Box1Value",{INT_FD, &Box1Value}},
			{"Box1Time",{INT_FD, &Box1Time}},
			{"Box1Cost",{INT_FD, &Box1Cost}},
			{"Advertisement1",{INT_FD, &Advertisement1}},
			{"Box2Id",{INT_FD, &Box2Id}},
			{"Box2Value",{INT_FD, &Box2Value}},
			{"Box2Time",{INT_FD, &Box2Time}},
			{"Box2Cost",{INT_FD, &Box2Cost}},
			{"Advertisement2",{INT_FD, &Advertisement2}},
			{"GetSound",{TSTR_FD, &GetSound}},
			{"UnlockSound",{TSTR_FD, &UnlockSound}}
		};
	}
	virtual table_level_boxT* create()
	{
		return new table_level_boxT();
	}
	enum
	{
	};
	INT32 Id = 0;            //序号
	INT32 BoxType = 0;				//宝箱类型
	INT32 JudgeValue = 0;				//判定数值
	INT32 Box1Id = 0;				//宝箱1
id
	INT32 Box1Value = 0;				//宝箱1
权值
	INT32 Box1Time = 0;				//宝箱1
解锁时间
	INT32 Box1Cost = 0;				//宝箱1解锁花费
	INT32 Advertisement1 = 0;				//观影减少时间
	INT32 Box2Id = 0;				//宝箱2
id
	INT32 Box2Value = 0;				//宝箱2
权值
	INT32 Box2Time = 0;				//宝箱2
解锁时间
	INT32 Box2Cost = 0;				//宝箱2解锁花费
	INT32 Advertisement2 = 0;				//观影减少时间
	TStr GetSound = "";				//宝箱飞入音效
	TStr UnlockSound = "";				//宝箱解锁音效
};
CreateCsvClass(table_level_box);

struct table_level_bugtimeT : ConfigBaseT
{
	virtual ~table_level_bugtimeT()
	{
	}
	table_level_bugtimeT()
	{
		FileName = "table_level_bugtime.csv";
		_kf =
		{
			{"Number",{INT_FD, &Number}},
			{"Type",{INT_FD, &Type}},
			{"Buytime",{INT_FD, &Buytime}},
			{"Diamond",{INT_FD, &Diamond}},
			{"Addtime",{INT_FD, &Addtime}}
		};
	}
	virtual table_level_bugtimeT* create()
	{
		return new table_level_bugtimeT();
	}
	enum
	{
	};
	INT32 Number = 0;            //流水号
	INT32 Type = 0;				//类型
	INT32 Buytime = 0;				//购买次数
	INT32 Diamond = 0;				//钻石数
	INT32 Addtime = 0;				//购买增加时间
};
CreateCsvClass(table_level_bugtime);

struct table_level_cloudgroupT : ConfigBaseT
{
	virtual ~table_level_cloudgroupT()
	{
	}
	table_level_cloudgroupT()
	{
		FileName = "table_level_cloudgroup.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"GroupLeveID",{INT_FD, &GroupLeveID}},
			{"GroupID",{INT_FD, &GroupID}},
			{"GroupType",{INT_FD, &GroupType}},
			{"Unlock1",{INT_FD, &Unlock1}},
			{"UnlockNum1",{INT_FD, &UnlockNum1}},
			{"Unlock2",{INT_FD, &Unlock2}},
			{"UnlockNum2",{FLOAT_FD, &UnlockNum2}},
			{"Unlock3",{INT_FD, &Unlock3}},
			{"UnlockNum3",{FLOAT_FD, &UnlockNum3}},
			{"Unlock4",{INT_FD, &Unlock4}},
			{"UnlockNum4",{FLOAT_FD, &UnlockNum4}},
			{"CenterX",{FLOAT_FD, &CenterX}},
			{"CenterY",{FLOAT_FD, &CenterY}},
			{"GroupImage",{TSTR_FD, &GroupImage}},
			{"GroupDescribe",{TSTR_FD, &GroupDescribe}},
			{"AppleshopID",{TSTR_FD, &AppleshopID}},
			{"CloudHeadResource",{TSTR_FD, &CloudHeadResource}},
			{"UnlockSound",{TSTR_FD, &UnlockSound}}
		};
	}
	virtual table_level_cloudgroupT* create()
	{
		return new table_level_cloudgroupT();
	}
	enum
	{
	};
	INT32 ID = 0;            //序号
	INT32 GroupLeveID = 0;				//所属关卡ID
	INT32 GroupID = 0;				//组ID
	INT32 GroupType = 0;				//组类型
	INT32 Unlock1 = 0;				//解锁条件1（人口）
	INT32 UnlockNum1 = 0;				//数值1
	INT32 Unlock2 = 0;				//解锁条件2（地块组ID）
	float UnlockNum2 = 0.0f;				//数值2
	INT32 Unlock3 = 0;				//解锁条件3（前哨进度）
	float UnlockNum3 = 0.0f;				//数值3
	INT32 Unlock4 = 0;				//解锁条件4（付费）
	float UnlockNum4 = 0.0f;				//数值4
	float CenterX = 0.0f;				//中心点X坐标
	float CenterY = 0.0f;				//中心点Y坐标
	TStr GroupImage = "";				//对应图片资源
	TStr GroupDescribe = "";				//描述文字
	TStr AppleshopID = "";				//苹果
商品ID
	TStr CloudHeadResource = "";				//云头像资源
	TStr UnlockSound = "";				//解锁音效
};
CreateCsvClass(table_level_cloudgroup);

struct table_level_energyT : ConfigBaseT
{
	virtual ~table_level_energyT()
	{
	}
	table_level_energyT()
	{
		FileName = "table_level_energy.csv";
		_kf =
		{
			{"NeedEnergy",{INT_FD, &NeedEnergy}},
			{"Time",{INT_FD, &Time}},
			{"Diamond",{INT_FD, &Diamond}}
		};
	}
	virtual table_level_energyT* create()
	{
		return new table_level_energyT();
	}
	enum
	{
	};
	INT32 NeedEnergy = 0;            //所需体力值
	INT32 Time = 0;				//恢复时间
	INT32 Diamond = 0;				//所需钻石
};
CreateCsvClass(table_level_energy);

struct table_level_eventT : ConfigBaseT
{
	virtual ~table_level_eventT()
	{
	}
	table_level_eventT()
	{
		FileName = "table_level_event.csv";
		_kf =
		{
			{"EventType",{INT_FD, &EventType}},
			{"EventName",{TSTR_FD, &EventName}},
			{"Remark",{TSTR_FD, &Remark}},
			{"EventDescribe",{TSTR_FD, &EventDescribe}},
			{"ShowType",{INT_FD, &ShowType}},
			{"EventImage",{TSTR_FD, &EventImage}},
			{"EventStandbyLocation",{TSTR_FD, &EventStandbyLocation}},
			{"EventStandbyEffect",{TSTR_FD, &EventStandbyEffect}},
			{"EventEffectLocation",{TSTR_FD, &EventEffectLocation}},
			{"EventEffect",{TSTR_FD, &EventEffect}},
			{"EventClickSound",{TSTR_FD, &EventClickSound}},
			{"EventNameKey",{TSTR_FD, &EventNameKey}},
			{"EventDescribeKey",{TSTR_FD, &EventDescribeKey}}
		};
	}
	virtual table_level_eventT* create()
	{
		return new table_level_eventT();
	}
	enum
	{
	};
	INT32 EventType = 0;            //类型ID
	TStr EventName = "";				//名称
	TStr Remark = "";				//备注
	TStr EventDescribe = "";				//描述
	INT32 ShowType = 0;				//表现方式
	TStr EventImage = "";				//美术资源
	TStr EventStandbyLocation = "";				//待机特效
挂点
	TStr EventStandbyEffect = "";				//待机特效
	TStr EventEffectLocation = "";				//点击播放特效
位置
	TStr EventEffect = "";				//点击播放特效
	TStr EventClickSound = "";				//点击音效
	TStr EventNameKey = "";				//Key
	TStr EventDescribeKey = "";				//Key
};
CreateCsvClass(table_level_event);

struct table_level_event_toherT : ConfigBaseT
{
	virtual ~table_level_event_toherT()
	{
	}
	table_level_event_toherT()
	{
		FileName = "table_level_event_toher.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"LevelID",{INT_FD, &LevelID}},
			{"EventID",{INT_FD, &EventID}},
			{"Count",{FLOAT_FD, &Count}},
			{"Parm1",{FLOAT_FD, &Parm1}},
			{"Parm2",{FLOAT_FD, &Parm2}},
			{"Parm3",{FLOAT_FD, &Parm3}}
		};
	}
	virtual table_level_event_toherT* create()
	{
		return new table_level_event_toherT();
	}
	enum
	{
	};
	INT32 ID = 0;            //主键
	INT32 LevelID = 0;				//关卡ID
	INT32 EventID = 0;				//关联事件ID
	float Count = 0.0f;				//区间
	float Parm1 = 0.0f;				//修正产出数量
	float Parm2 = 0.0f;				//影响产出总时长
	float Parm3 = 0.0f;				//影响CD总时长
};
CreateCsvClass(table_level_event_toher);

struct table_level_groupT : ConfigBaseT
{
	virtual ~table_level_groupT()
	{
	}
	table_level_groupT()
	{
		FileName = "table_level_group.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"FormID",{INT_FD, &FormID}},
			{"LevelID",{INT_FD, &LevelID}}
		};
	}
	virtual table_level_groupT* create()
	{
		return new table_level_groupT();
	}
	enum
	{
	};
	INT32 ID = 0;            //序号
	INT32 FormID = 0;				//关卡组ID
	INT32 LevelID = 0;				//关卡ID
};
CreateCsvClass(table_level_group);

struct table_mergeT : ConfigBaseT
{
	virtual ~table_mergeT()
	{
	}
	table_mergeT()
	{
		FileName = "table_merge.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"Comment",{TSTR_FD, &Comment}},
			{"Type",{INT_FD, &Type}},
			{"TEMP",{INT_FD, &TEMP}},
			{"MergeDelay",{FLOAT_FD, &MergeDelay}},
			{"MergeDelayEffect",{TSTR_FD, &MergeDelayEffect}},
			{"ChainGroupID",{INT_FD, &ChainGroupID}},
			{"ChainNumber",{INT_FD, &ChainNumber}},
			{"CallDragonGroup",{INT_FD, &CallDragonGroup}},
			{"OutputStandardID",{INT_FD, &OutputStandardID}},
			{"OutputStandardCountMin",{INT_FD, &OutputStandardCountMin}},
			{"OutputStandardCountMax",{INT_FD, &OutputStandardCountMax}},
			{"ReturnID",{INT_FD, &ReturnID}},
			{"SkipLevelRate",{FLOAT_FD, &SkipLevelRate}},
			{"AdditionalRate_1",{FLOAT_FD, &AdditionalRate_1}},
			{"AdditionalID_1",{INT_FD, &AdditionalID_1}},
			{"AdditionalRate_2",{FLOAT_FD, &AdditionalRate_2}},
			{"AdditionalID_2",{INT_FD, &AdditionalID_2}},
			{"AdditionalRate_3",{FLOAT_FD, &AdditionalRate_3}},
			{"AdditionalID_3",{INT_FD, &AdditionalID_3}},
			{"AdvertisingRate",{FLOAT_FD, &AdvertisingRate}},
			{"AdvertisingDropID",{INT_FD, &AdvertisingDropID}},
			{"WeatherRain",{INT_FD, &WeatherRain}},
			{"WeatherThunder",{INT_FD, &WeatherThunder}},
			{"SpecialRate_1",{FLOAT_FD, &SpecialRate_1}},
			{"SpecialID_1",{INT_FD, &SpecialID_1}},
			{"SpecialRate_2",{FLOAT_FD, &SpecialRate_2}},
			{"SpecialID_2",{INT_FD, &SpecialID_2}},
			{"ComboMergeOutputRate",{FLOAT_FD, &ComboMergeOutputRate}},
			{"ComboMergeOutputID",{INT_FD, &ComboMergeOutputID}},
			{"ComboMergeOutputRate2",{FLOAT_FD, &ComboMergeOutputRate2}},
			{"ComboMergeOutputID2",{INT_FD, &ComboMergeOutputID2}},
			{"None",{FLOAT_FD, &None}},
			{"None2",{INT_FD, &None2}},
			{"RewardCoinType",{INT_FD, &RewardCoinType}},
			{"RewardCoinNumber",{INT_FD, &RewardCoinNumber}},
			{"SoundMerge",{TSTR_FD, &SoundMerge}},
			{"UnlockmanualSound",{TSTR_FD, &UnlockmanualSound}},
			{"MergeEffect",{TSTR_FD, &MergeEffect}}
		};
	}
	virtual table_mergeT* create()
	{
		return new table_mergeT();
	}
	enum
	{
	};
	INT32 ID = 0;            //道具ID
	TStr Comment = "";				//备注
	INT32 Type = 0;				//类别
	INT32 TEMP = 0;				//合成位置（人口模块使用）
	float MergeDelay = 0.0f;				//合成产物
延迟出现时间
	TStr MergeDelayEffect = "";				//合成产物
延迟出现时间
特效
	INT32 ChainGroupID = 0;				//合成
链组
	INT32 ChainNumber = 0;				//合成链
序号
	INT32 CallDragonGroup = 0;				//召唤组ID
	INT32 OutputStandardID = 0;				//标准合成产出
物品ID
	INT32 OutputStandardCountMin = 0;				//标准合成产出
数量Min
	INT32 OutputStandardCountMax = 0;				//标准合成产出
数量Max
	INT32 ReturnID = 0;				//多余道具id
	float SkipLevelRate = 0.0f;				//跳1级几率
	float AdditionalRate_1 = 0.0f;				//额外1
几率
	INT32 AdditionalID_1 = 0;				//额外1
掉落ID
	float AdditionalRate_2 = 0.0f;				//额外2
几率
	INT32 AdditionalID_2 = 0;				//额外2
掉落ID
	float AdditionalRate_3 = 0.0f;				//额外3
几率
	INT32 AdditionalID_3 = 0;				//额外3
掉落ID
	float AdvertisingRate = 0.0f;				//广告泡泡
掉落几率
	INT32 AdvertisingDropID = 0;				//广告泡泡
掉落ID
	INT32 WeatherRain = 0;				//【天气】
雨云专用
	INT32 WeatherThunder = 0;				//【天气】
雷云专用
	float SpecialRate_1 = 0.0f;				//特殊合成1
几率
	INT32 SpecialID_1 = 0;				//特殊合成1
掉落ID
	float SpecialRate_2 = 0.0f;				//特殊合成2
几率
	INT32 SpecialID_2 = 0;				//特殊合成2
掉落ID
	float ComboMergeOutputRate = 0.0f;				//连奖励
几率
	INT32 ComboMergeOutputID = 0;				//连奖励
掉落ID
	float ComboMergeOutputRate2 = 0.0f;				//连奖励2
几率
	INT32 ComboMergeOutputID2 = 0;				//连奖励2
掉落ID
	float None = 0.0f;				//多数合成奖励
几率
	INT32 None2 = 0;				//多数合成奖励
掉落ID
	INT32 RewardCoinType = 0;				//图鉴解锁奖励
种类
	INT32 RewardCoinNumber = 0;				//图鉴解锁奖励
数量
	TStr SoundMerge = "";				//合成音效
	TStr UnlockmanualSound = "";				//【图鉴】
解锁图鉴音效
	TStr MergeEffect = "";				//合成特效
};
CreateCsvClass(table_merge);

struct table_outpostT : ConfigBaseT
{
	virtual ~table_outpostT()
	{
	}
	table_outpostT()
	{
		FileName = "table_outpost.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"OutpostID",{INT_FD, &OutpostID}},
			{"PlanID",{INT_FD, &PlanID}},
			{"PlanName",{TSTR_FD, &PlanName}},
			{"TaskID1",{INT_FD, &TaskID1}},
			{"TaskID2",{INT_FD, &TaskID2}},
			{"TaskID3",{INT_FD, &TaskID3}},
			{"UnlockStars",{INT_FD, &UnlockStars}},
			{"Storyline",{TSTR_FD, &Storyline}},
			{"NpcPath",{TSTR_FD, &NpcPath}},
			{"NPCImage",{TSTR_FD, &NPCImage}},
			{"NPCDirection",{INT_FD, &NPCDirection}},
			{"NpcText",{TSTR_FD, &NpcText}},
			{"FormID",{INT_FD, &FormID}},
			{"PlanNameKey",{TSTR_FD, &PlanNameKey}},
			{"NpcTextKey",{TSTR_FD, &NpcTextKey}}
		};
	}
	virtual table_outpostT* create()
	{
		return new table_outpostT();
	}
	enum
	{
	};
	INT32 ID = 0;            //序号
	INT32 OutpostID = 0;				//哨站ID
	INT32 PlanID = 0;				//进度序号
	TStr PlanName = "";				//进度名称
	INT32 TaskID1 = 0;				//任务id
	INT32 TaskID2 = 0;				//任务2ID
	INT32 TaskID3 = 0;				//任务3ID
	INT32 UnlockStars = 0;				//解锁需求星数
	TStr Storyline = "";				//脚本ID
	TStr NpcPath = "";				//挂任务NPC
	TStr NPCImage = "";				//NPC半身像
	INT32 NPCDirection = 0;				//NPC半身像朝向
	TStr NpcText = "";				//NPC泡泡文字
	INT32 FormID = 0;				//对应关卡组ID
	TStr PlanNameKey = "";				//Key
	TStr NpcTextKey = "";				//Key
};
CreateCsvClass(table_outpost);

struct table_outpost_levelT : ConfigBaseT
{
	virtual ~table_outpost_levelT()
	{
	}
	table_outpost_levelT()
	{
		FileName = "table_outpost_level.csv";
		_kf =
		{
			{"PlanID",{INT_FD, &PlanID}},
			{"FormID",{INT_FD, &FormID}}
		};
	}
	virtual table_outpost_levelT* create()
	{
		return new table_outpost_levelT();
	}
	enum
	{
	};
	INT32 PlanID = 0;            //前哨ID
	INT32 FormID = 0;				//对应关卡组ID
};
CreateCsvClass(table_outpost_level);

struct table_outpost_prizeT : ConfigBaseT
{
	virtual ~table_outpost_prizeT()
	{
	}
	table_outpost_prizeT()
	{
		FileName = "table_outpost_prize.csv";
		_kf =
		{
			{"Number",{INT_FD, &Number}},
			{"OutpostID",{INT_FD, &OutpostID}},
			{"StarMin",{INT_FD, &StarMin}},
			{"StarMax",{INT_FD, &StarMax}},
			{"ResetTime",{INT_FD, &ResetTime}},
			{"Advertisement",{INT_FD, &Advertisement}},
			{"Award1",{INT_FD, &Award1}},
			{"Award2",{INT_FD, &Award2}},
			{"Award3",{INT_FD, &Award3}},
			{"Image",{TSTR_FD, &Image}},
			{"LevelupEffect",{TSTR_FD, &LevelupEffect}},
			{"StarImage",{TSTR_FD, &StarImage}},
			{"StarEffect",{TSTR_FD, &StarEffect}},
			{"BoxEffect",{TSTR_FD, &BoxEffect}},
			{"AttainEffect",{TSTR_FD, &AttainEffect}},
			{"GetEffect",{TSTR_FD, &GetEffect}}
		};
	}
	virtual table_outpost_prizeT* create()
	{
		return new table_outpost_prizeT();
	}
	enum
	{
	};
	INT32 Number = 0;            //序号
	INT32 OutpostID = 0;				//哨站ID
	INT32 StarMin = 0;				//星数Min
≥
	INT32 StarMax = 0;				//星数Max
≤
	INT32 ResetTime = 0;				//刷新时间
单位：秒
	INT32 Advertisement = 0;				//每次观影减少时间
	INT32 Award1 = 0;				//奖励1
	INT32 Award2 = 0;				//奖励2
	INT32 Award3 = 0;				//奖励3
	TStr Image = "";				//图标
	TStr LevelupEffect = "";				//升级特效
	TStr StarImage = "";				//飞行星图标
	TStr StarEffect = "";				//飞星拖尾特效
	TStr BoxEffect = "";				//飞星达到宝箱背景特效
	TStr AttainEffect = "";				//领取奖励宝箱特效
	TStr GetEffect = "";				//领取奖励拖尾特效
};
CreateCsvClass(table_outpost_prize);

struct table_rank_ainameT : ConfigBaseT
{
	virtual ~table_rank_ainameT()
	{
	}
	table_rank_ainameT()
	{
		FileName = "table_rank_ainame.csv";
		_kf =
		{
			{"Num",{INT_FD, &Num}},
			{"AI_Name",{TSTR_FD, &AI_Name}},
			{"Initial",{INT_FD, &Initial}},
			{"Step",{FLOAT_FD, &Step}}
		};
	}
	virtual table_rank_ainameT* create()
	{
		return new table_rank_ainameT();
	}
	enum
	{
	};
	INT32 Num = 0;            //编号
	TStr AI_Name = "";				//名字
	INT32 Initial = 0;				//初始值
	float Step = 0.0f;				//步长值
};
CreateCsvClass(table_rank_ainame);

struct table_rank_rewardT : ConfigBaseT
{
	virtual ~table_rank_rewardT()
	{
	}
	table_rank_rewardT()
	{
		FileName = "table_rank_reward.csv";
		_kf =
		{
			{"Rank",{INT_FD, &Rank}},
			{"RankAwardType1",{INT_FD, &RankAwardType1}},
			{"Awardid1",{INT_FD, &Awardid1}},
			{"Num1",{INT_FD, &Num1}},
			{"RankAwardType2",{INT_FD, &RankAwardType2}},
			{"Awardid2",{INT_FD, &Awardid2}},
			{"Num2",{INT_FD, &Num2}},
			{"RankAwardType3",{INT_FD, &RankAwardType3}},
			{"Awardid3",{INT_FD, &Awardid3}},
			{"Num3",{INT_FD, &Num3}},
			{"RankAwardType4",{INT_FD, &RankAwardType4}},
			{"Awardid4",{INT_FD, &Awardid4}},
			{"Num4",{INT_FD, &Num4}},
			{"RankAwardType5",{INT_FD, &RankAwardType5}},
			{"Awardid5",{INT_FD, &Awardid5}},
			{"Num5",{INT_FD, &Num5}}
		};
	}
	virtual table_rank_rewardT* create()
	{
		return new table_rank_rewardT();
	}
	enum
	{
	};
	INT32 Rank = 0;            //排名
	INT32 RankAwardType1 = 0;				//排名奖励1显示
	INT32 Awardid1 = 0;				//排名奖励1
	INT32 Num1 = 0;				//奖励数量
	INT32 RankAwardType2 = 0;				//排名奖励2显示
	INT32 Awardid2 = 0;				//排名奖励2
	INT32 Num2 = 0;				//奖励数量
	INT32 RankAwardType3 = 0;				//排名奖励3显示
	INT32 Awardid3 = 0;				//排名奖励3
	INT32 Num3 = 0;				//奖励数量
	INT32 RankAwardType4 = 0;				//排名奖励4显示
	INT32 Awardid4 = 0;				//排名奖励4
	INT32 Num4 = 0;				//奖励数量
	INT32 RankAwardType5 = 0;				//排名奖励5显示
	INT32 Awardid5 = 0;				//排名奖励5
	INT32 Num5 = 0;				//奖励数量
};
CreateCsvClass(table_rank_reward);

struct table_receiptT : ConfigBaseT
{
	virtual ~table_receiptT()
	{
	}
	table_receiptT()
	{
		FileName = "table_receipt.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"ReceiptGroup",{INT_FD, &ReceiptGroup}},
			{"Weight",{INT_FD, &Weight}},
			{"ArticleType",{INT_FD, &ArticleType}},
			{"Article",{INT_FD, &Article}},
			{"Number",{INT_FD, &Number}},
			{"Exp",{INT_FD, &Exp}},
			{"IconRes",{INT_FD, &IconRes}},
			{"CommitType",{INT_FD, &CommitType}},
			{"ArticleEffect",{TSTR_FD, &ArticleEffect}},
			{"IsTips",{INT_FD, &IsTips}},
			{"Tips",{TSTR_FD, &Tips}}
		};
	}
	virtual table_receiptT* create()
	{
		return new table_receiptT();
	}
	enum
	{
	};
	INT32 ID = 0;            //订单ID
	INT32 ReceiptGroup = 0;				//订单组
	INT32 Weight = 0;				//权重
	INT32 ArticleType = 0;				//道具类型
	INT32 Article = 0;				//需求道具
	INT32 Number = 0;				//需求数量
	INT32 Exp = 0;				//换算经验
	INT32 IconRes = 0;				//特殊道具图标填充
	INT32 CommitType = 0;				//提交方式
	TStr ArticleEffect = "";				//道具飞行拖尾特效
	INT32 IsTips = 0;				//是否响应tips
	TStr Tips = "";				//点击是tips描述
};
CreateCsvClass(table_receipt);

struct table_shopT : ConfigBaseT
{
	virtual ~table_shopT()
	{
	}
	table_shopT()
	{
		FileName = "table_shop.csv";
		_kf =
		{
			{"GoodsID",{INT_FD, &GoodsID}},
			{"GoodsName",{TSTR_FD, &GoodsName}},
			{"Remarks",{TSTR_FD, &Remarks}},
			{"TabID",{INT_FD, &TabID}},
			{"SubFunction",{INT_FD, &SubFunction}},
			{"GoodsGroupID",{INT_FD, &GoodsGroupID}},
			{"GoodsDesc",{TSTR_FD, &GoodsDesc}},
			{"GoodsType",{INT_FD, &GoodsType}},
			{"IDOrNumber_GoodsType",{TSTR_FD, &IDOrNumber_GoodsType}},
			{"Quantity",{INT_FD, &Quantity}},
			{"ShowImageId",{TSTR_FD, &ShowImageId}},
			{"GoodsImageID",{TSTR_FD, &GoodsImageID}},
			{"GoodsType2",{INT_FD, &GoodsType2}},
			{"IDOrNumber_GoodsType2",{TSTR_FD, &IDOrNumber_GoodsType2}},
			{"Quantity2",{INT_FD, &Quantity2}},
			{"ShowImageId2",{TSTR_FD, &ShowImageId2}},
			{"GoodsImageID2",{TSTR_FD, &GoodsImageID2}},
			{"GoodsType3",{INT_FD, &GoodsType3}},
			{"IDOrNumber_GoodsType3",{TSTR_FD, &IDOrNumber_GoodsType3}},
			{"Quantity3",{INT_FD, &Quantity3}},
			{"ShowImageId3",{TSTR_FD, &ShowImageId3}},
			{"GoodsImageID3",{TSTR_FD, &GoodsImageID3}},
			{"GoodsType4",{INT_FD, &GoodsType4}},
			{"IDOrNumber_GoodsType4",{TSTR_FD, &IDOrNumber_GoodsType4}},
			{"Quantity4",{INT_FD, &Quantity4}},
			{"ShowImageId4",{TSTR_FD, &ShowImageId4}},
			{"GoodsImageID4",{TSTR_FD, &GoodsImageID4}},
			{"GoodsType5",{INT_FD, &GoodsType5}},
			{"IDOrNumber_GoodsType5",{TSTR_FD, &IDOrNumber_GoodsType5}},
			{"Quantity5",{INT_FD, &Quantity5}},
			{"ShowImageId5",{TSTR_FD, &ShowImageId5}},
			{"GoodsImageID5",{TSTR_FD, &GoodsImageID5}},
			{"GoodsType6",{INT_FD, &GoodsType6}},
			{"IDOrNumber_GoodsType6",{TSTR_FD, &IDOrNumber_GoodsType6}},
			{"Quantity6",{INT_FD, &Quantity6}},
			{"ShowImageId6",{TSTR_FD, &ShowImageId6}},
			{"GoodsImageID6",{TSTR_FD, &GoodsImageID6}},
			{"DropID_AdditionalGift1",{INT_FD, &DropID_AdditionalGift1}},
			{"DropID_AdditionalGift2",{INT_FD, &DropID_AdditionalGift2}},
			{"DropID_AdditionalGift3",{INT_FD, &DropID_AdditionalGift3}},
			{"OrderedID",{INT_FD, &OrderedID}},
			{"UnlockConditionType",{INT_FD, &UnlockConditionType}},
			{"UnlockCondition_SpriteID",{INT_FD, &UnlockCondition_SpriteID}},
			{"UnlockCondition_Number",{INT_FD, &UnlockCondition_Number}},
			{"CurrencyType",{INT_FD, &CurrencyType}},
			{"InitialPrice",{FLOAT_FD, &InitialPrice}},
			{"PriceCalculationMethodType",{INT_FD, &PriceCalculationMethodType}},
			{"CeilingPrice",{INT_FD, &CeilingPrice}},
			{"Increment",{INT_FD, &Increment}},
			{"LimitedType",{INT_FD, &LimitedType}},
			{"Days",{INT_FD, &Days}},
			{"LimitQuantity",{INT_FD, &LimitQuantity}},
			{"LimitQuantityCD",{INT_FD, &LimitQuantityCD}},
			{"LimitNumber",{INT_FD, &LimitNumber}},
			{"OnShelf_ChainID",{INT_FD, &OnShelf_ChainID}},
			{"OnShelf_Date",{TSTR_FD, &OnShelf_Date}},
			{"OffShelf_Date",{TSTR_FD, &OffShelf_Date}},
			{"OnShelf_Birthday",{INT_FD, &OnShelf_Birthday}},
			{"OffShelf_Birthday",{INT_FD, &OffShelf_Birthday}},
			{"OnShelf_PlanID",{INT_FD, &OnShelf_PlanID}},
			{"DiscountShow",{FLOAT_FD, &DiscountShow}},
			{"Discount",{FLOAT_FD, &Discount}},
			{"CardStyle",{INT_FD, &CardStyle}},
			{"BottomImage",{TSTR_FD, &BottomImage}},
			{"BuyAndCloseView",{INT_FD, &BuyAndCloseView}},
			{"AppleshopID",{TSTR_FD, &AppleshopID}},
			{"GoodsEffect",{TSTR_FD, &GoodsEffect}},
			{"UnlockGoodsSound",{TSTR_FD, &UnlockGoodsSound}},
			{"GoodsNameKey",{TSTR_FD, &GoodsNameKey}},
			{"GoodsDescKey",{TSTR_FD, &GoodsDescKey}}
		};
	}
	virtual table_shopT* create()
	{
		return new table_shopT();
	}
	enum
	{
	};
	INT32 GoodsID = 0;            //商品id
	TStr GoodsName = "";				//商品名称
	TStr Remarks = "";				//备注
	INT32 TabID = 0;				//所属页签
	INT32 SubFunction = 0;				//所属功能
	INT32 GoodsGroupID = 0;				//商品组ID
	TStr GoodsDesc = "";				//商品描述
	INT32 GoodsType = 0;				//商品类别
	TStr IDOrNumber_GoodsType = "";				//道具ID
龙ID
钻石数
	INT32 Quantity = 0;				//商品数量
	TStr ShowImageId = "";				//显示道具ID
	TStr GoodsImageID = "";				//道具图片ID
	INT32 GoodsType2 = 0;				//商品类别
	TStr IDOrNumber_GoodsType2 = "";				//道具ID
龙ID
钻石数
	INT32 Quantity2 = 0;				//商品数量
	TStr ShowImageId2 = "";				//显示道具ID
	TStr GoodsImageID2 = "";				//道具图片ID
	INT32 GoodsType3 = 0;				//商品类别
	TStr IDOrNumber_GoodsType3 = "";				//道具ID
龙ID
钻石数
	INT32 Quantity3 = 0;				//商品数量
	TStr ShowImageId3 = "";				//显示道具ID
	TStr GoodsImageID3 = "";				//道具图片ID
	INT32 GoodsType4 = 0;				//商品类别
	TStr IDOrNumber_GoodsType4 = "";				//道具ID
龙ID
钻石数
	INT32 Quantity4 = 0;				//商品数量
	TStr ShowImageId4 = "";				//显示道具ID
	TStr GoodsImageID4 = "";				//道具图片ID
	INT32 GoodsType5 = 0;				//商品类别
	TStr IDOrNumber_GoodsType5 = "";				//道具ID
龙ID
钻石数
	INT32 Quantity5 = 0;				//商品数量
	TStr ShowImageId5 = "";				//显示道具ID
	TStr GoodsImageID5 = "";				//道具图片ID
	INT32 GoodsType6 = 0;				//商品类别
	TStr IDOrNumber_GoodsType6 = "";				//道具ID
龙ID
钻石数
	INT32 Quantity6 = 0;				//商品数量
	TStr ShowImageId6 = "";				//显示道具ID
	TStr GoodsImageID6 = "";				//道具图片ID
	INT32 DropID_AdditionalGift1 = 0;				//额外赠与1
掉落ID
	INT32 DropID_AdditionalGift2 = 0;				//额外赠与2
掉落ID
	INT32 DropID_AdditionalGift3 = 0;				//额外赠与3
掉落ID
	INT32 OrderedID = 0;				//排序id
	INT32 UnlockConditionType = 0;				//解锁条件（翻卡解锁）
	INT32 UnlockCondition_SpriteID = 0;				//解锁需求道具ID
 或 龙ID
	INT32 UnlockCondition_Number = 0;				//解锁需求数量
	INT32 CurrencyType = 0;				//支付类型
	float InitialPrice = 0.0f;				//初始价格
	INT32 PriceCalculationMethodType = 0;				//价格计算方法
	INT32 CeilingPrice = 0;				//上限价格
	INT32 Increment = 0;				//递增幅度
	INT32 LimitedType = 0;				//限量类型
	INT32 Days = 0;				//天数
	INT32 LimitQuantity = 0;				//限量次数
	INT32 LimitQuantityCD = 0;				//限量次数CD
	INT32 LimitNumber = 0;				//每次限购数量
	INT32 OnShelf_ChainID = 0;				//解锁合成链限制上架
	TStr OnShelf_Date = "";				//时间限制上架
	TStr OffShelf_Date = "";				//时间限制下架
	INT32 OnShelf_Birthday = 0;				//生日限制上架
	INT32 OffShelf_Birthday = 0;				//生日限制下架
	INT32 OnShelf_PlanID = 0;				//前哨进度限制上架
	float DiscountShow = 0.0f;				//显示打折数
	float Discount = 0.0f;				//真实打折数
	INT32 CardStyle = 0;				//商品模板
	TStr BottomImage = "";				//商品底图框
	INT32 BuyAndCloseView = 0;				//购买之后关闭界面与否
	TStr AppleshopID = "";				//苹果
商品ID
	TStr GoodsEffect = "";				//背景特效
	TStr UnlockGoodsSound = "";				//商品解锁音效
	TStr GoodsNameKey = "";				//Key
	TStr GoodsDescKey = "";				//Key
};
CreateCsvClass(table_shop);

struct table_shop_appleidT : ConfigBaseT
{
	virtual ~table_shop_appleidT()
	{
	}
	table_shop_appleidT()
	{
		FileName = "table_shop_appleid.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"AppleShopID",{TSTR_FD, &AppleShopID}},
			{"Name",{TSTR_FD, &Name}},
			{"describe",{TSTR_FD, &describe}},
			{"SellType",{INT_FD, &SellType}},
			{"price",{FLOAT_FD, &price}},
			{"ShopType",{INT_FD, &ShopType}},
			{"ShopID",{INT_FD, &ShopID}}
		};
	}
	virtual table_shop_appleidT* create()
	{
		return new table_shop_appleidT();
	}
	enum
	{
	};
	INT32 ID = 0;            //序号
	TStr AppleShopID = "";				//对应苹果商品ID
	TStr Name = "";				//商品名称
	TStr describe = "";				//描述
	INT32 SellType = 0;				//销售
类型
	float price = 0.0f;				//价格
美元
	INT32 ShopType = 0;				//商品类型
	INT32 ShopID = 0;				//游戏内
商品ID
};
CreateCsvClass(table_shop_appleid);

struct table_shop_groupT : ConfigBaseT
{
	virtual ~table_shop_groupT()
	{
	}
	table_shop_groupT()
	{
		FileName = "table_shop_group.csv";
		_kf =
		{
			{"GoodsGroupID",{INT_FD, &GoodsGroupID}},
			{"StartGoodsID",{INT_FD, &StartGoodsID}},
			{"EndGoodsID",{INT_FD, &EndGoodsID}}
		};
	}
	virtual table_shop_groupT* create()
	{
		return new table_shop_groupT();
	}
	enum
	{
	};
	INT32 GoodsGroupID = 0;            //组ID
	INT32 StartGoodsID = 0;				//起始商品序号
	INT32 EndGoodsID = 0;				//结束商品序号
};
CreateCsvClass(table_shop_group);

struct table_shop_pageT : ConfigBaseT
{
	virtual ~table_shop_pageT()
	{
	}
	table_shop_pageT()
	{
		FileName = "table_shop_page.csv";
		_kf =
		{
			{"TabID",{INT_FD, &TabID}},
			{"TabName",{TSTR_FD, &TabName}},
			{"DisplayInterface",{INT_FD, &DisplayInterface}},
			{"RefreshTime",{INT_FD, &RefreshTime}},
			{"GridNumber",{INT_FD, &GridNumber}},
			{"MysteryItemNumber",{INT_FD, &MysteryItemNumber}},
			{"TabNameKey",{TSTR_FD, &TabNameKey}}
		};
	}
	virtual table_shop_pageT* create()
	{
		return new table_shop_pageT();
	}
	enum
	{
	};
	INT32 TabID = 0;            //页签ID
	TStr TabName = "";				//类别名称
	INT32 DisplayInterface = 0;				//显示位置
	INT32 RefreshTime = 0;				//刷新时间
	INT32 GridNumber = 0;				//格子数
	INT32 MysteryItemNumber = 0;				//神秘物品数量
	TStr TabNameKey = "";				//类别名称Key
};
CreateCsvClass(table_shop_page);

struct table_sound_configT : ConfigBaseT
{
	virtual ~table_sound_configT()
	{
	}
	table_sound_configT()
	{
		FileName = "table_sound_config.csv";
		_kf =
		{
			{"SoundID",{INT_FD, &SoundID}},
			{"SoundType",{INT_FD, &SoundType}},
			{"SoundSource",{TSTR_FD, &SoundSource}},
			{"Remarks",{TSTR_FD, &Remarks}}
		};
	}
	virtual table_sound_configT* create()
	{
		return new table_sound_configT();
	}
	enum
	{
	};
	INT32 SoundID = 0;            //音效ID
	INT32 SoundType = 0;				//音效类型
1-sound
2-music
	TStr SoundSource = "";				//音效资源
	TStr Remarks = "";				//备注
};
CreateCsvClass(table_sound_config);

struct table_story_lineT : ConfigBaseT
{
	virtual ~table_story_lineT()
	{
	}
	table_story_lineT()
	{
		FileName = "table_story_line.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"TemplateID",{INT_FD, &TemplateID}},
			{"Portrait",{TSTR_FD, &Portrait}},
			{"PortraitAspect",{INT_FD, &PortraitAspect}},
			{"NpcNameID",{TSTR_FD, &NpcNameID}},
			{"TextID",{TSTR_FD, &TextID}}
		};
	}
	virtual table_story_lineT* create()
	{
		return new table_story_lineT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	INT32 TemplateID = 0;				//使用模板ID
	TStr Portrait = "";				//半身像资源
	INT32 PortraitAspect = 0;				//半身像朝向
	TStr NpcNameID = "";				//名称Key
	TStr TextID = "";				//描述Key
};
CreateCsvClass(table_story_line);

struct table_story_signalT : ConfigBaseT
{
	virtual ~table_story_signalT()
	{
	}
	table_story_signalT()
	{
		FileName = "table_story_signal.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"Type",{INT_FD, &Type}},
			{"Param1",{TSTR_FD, &Param1}},
			{"Param2",{TSTR_FD, &Param2}},
			{"Param3",{TSTR_FD, &Param3}},
			{"Pause",{INT_FD, &Pause}}
		};
	}
	virtual table_story_signalT* create()
	{
		return new table_story_signalT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	INT32 Type = 0;				//信号类型
	TStr Param1 = "";				//框体引用
	TStr Param2 = "";				//是否引用
	TStr Param3 = "";				//文件引用ID
	INT32 Pause = 0;				//是否暂停
};
CreateCsvClass(table_story_signal);

struct table_systemT : ConfigBaseT
{
	virtual ~table_systemT()
	{
	}
	table_systemT()
	{
		FileName = "table_system.csv";
		_kf =
		{
			{"SystemID",{INT_FD, &SystemID}},
			{"SystemUI",{TSTR_FD, &SystemUI}},
			{"CloseExpression",{TSTR_FD, &CloseExpression}},
			{"ConditionClose0",{INT_FD, &ConditionClose0}},
			{"ClosePara0",{INT_FD, &ClosePara0}},
			{"ConditionClose1",{INT_FD, &ConditionClose1}},
			{"ClosePara1",{INT_FD, &ClosePara1}}
		};
	}
	virtual table_systemT* create()
	{
		return new table_systemT();
	}
	enum
	{
	};
	INT32 SystemID = 0;            //系统ID
	TStr SystemUI = "";				//界面ID
	TStr CloseExpression = "";				//关闭条件关系
	INT32 ConditionClose0 = 0;				//关闭条件0
	INT32 ClosePara0 = 0;				//关闭参数0
	INT32 ConditionClose1 = 0;				//关闭条件1
	INT32 ClosePara1 = 0;				//关闭参数1
};
CreateCsvClass(table_system);

struct table_system_openT : ConfigBaseT
{
	virtual ~table_system_openT()
	{
	}
	table_system_openT()
	{
		FileName = "table_system_open.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"Remark",{TSTR_FD, &Remark}},
			{"OpenExpression",{TSTR_FD, &OpenExpression}},
			{"ConditionOpen0",{INT_FD, &ConditionOpen0}},
			{"OpenPara0",{TSTR_FD, &OpenPara0}},
			{"ConditionOpen1",{INT_FD, &ConditionOpen1}},
			{"OpenPara1",{TSTR_FD, &OpenPara1}},
			{"ConditionOpen2",{INT_FD, &ConditionOpen2}},
			{"OpenPara2",{TSTR_FD, &OpenPara2}},
			{"ConditionOpen3",{INT_FD, &ConditionOpen3}},
			{"OpenPara3",{TSTR_FD, &OpenPara3}},
			{"ConditionOpen4",{INT_FD, &ConditionOpen4}},
			{"OpenPara4",{TSTR_FD, &OpenPara4}}
		};
	}
	virtual table_system_openT* create()
	{
		return new table_system_openT();
	}
	enum
	{
	};
	INT32 ID = 0;            //系统ID
	TStr Remark = "";				//备注
	TStr OpenExpression = "";				//条件之间的关系
	INT32 ConditionOpen0 = 0;				//打开条件0
	TStr OpenPara0 = "";				//打开参数0
	INT32 ConditionOpen1 = 0;				//打开条件1
	TStr OpenPara1 = "";				//打开参数1
	INT32 ConditionOpen2 = 0;				//打开条件2
	TStr OpenPara2 = "";				//打开参数2
	INT32 ConditionOpen3 = 0;				//打开条件3
	TStr OpenPara3 = "";				//打开参数3
	INT32 ConditionOpen4 = 0;				//打开条件4
	TStr OpenPara4 = "";				//打开参数4
};
CreateCsvClass(table_system_open);

struct table_system_shopT : ConfigBaseT
{
	virtual ~table_system_shopT()
	{
	}
	table_system_shopT()
	{
		FileName = "table_system_shop.csv";
		_kf =
		{
			{"SystemID",{INT_FD, &SystemID}},
			{"CurrencyType",{INT_FD, &CurrencyType}},
			{"Price",{FLOAT_FD, &Price}},
			{"AppleshopID",{TSTR_FD, &AppleshopID}},
			{"GoodsType1",{INT_FD, &GoodsType1}},
			{"IDOrNumber_GoodsType1",{INT_FD, &IDOrNumber_GoodsType1}},
			{"Quantity1",{INT_FD, &Quantity1}},
			{"GoodsImage1",{TSTR_FD, &GoodsImage1}},
			{"GoodsType2",{INT_FD, &GoodsType2}},
			{"IDOrNumber_GoodsType2",{INT_FD, &IDOrNumber_GoodsType2}},
			{"Quantity2",{INT_FD, &Quantity2}},
			{"GoodsImage2",{TSTR_FD, &GoodsImage2}},
			{"GoodsType3",{INT_FD, &GoodsType3}},
			{"IDOrNumber_GoodsType3",{INT_FD, &IDOrNumber_GoodsType3}},
			{"Quantity3",{INT_FD, &Quantity3}},
			{"GoodsImage3",{TSTR_FD, &GoodsImage3}},
			{"GoodsType4",{INT_FD, &GoodsType4}},
			{"IDOrNumber_GoodsType4",{INT_FD, &IDOrNumber_GoodsType4}},
			{"Quantity4",{INT_FD, &Quantity4}},
			{"GoodsImage4",{TSTR_FD, &GoodsImage4}},
			{"GoodsType5",{INT_FD, &GoodsType5}},
			{"IDOrNumber_GoodsType5",{INT_FD, &IDOrNumber_GoodsType5}},
			{"Quantity5",{INT_FD, &Quantity5}},
			{"GoodsImage5",{TSTR_FD, &GoodsImage5}},
			{"GoodsType6",{INT_FD, &GoodsType6}},
			{"IDOrNumber_GoodsType6",{INT_FD, &IDOrNumber_GoodsType6}},
			{"Quantity6",{INT_FD, &Quantity6}},
			{"GoodsImage6",{TSTR_FD, &GoodsImage6}},
			{"GoodsType7",{INT_FD, &GoodsType7}},
			{"IDOrNumber_GoodsType7",{INT_FD, &IDOrNumber_GoodsType7}},
			{"Quantity7",{INT_FD, &Quantity7}},
			{"GoodsImage7",{TSTR_FD, &GoodsImage7}},
			{"GoodsType8",{INT_FD, &GoodsType8}},
			{"IDOrNumber_GoodsType8",{INT_FD, &IDOrNumber_GoodsType8}},
			{"Quantity8",{INT_FD, &Quantity8}},
			{"GoodsImage8",{TSTR_FD, &GoodsImage8}}
		};
	}
	virtual table_system_shopT* create()
	{
		return new table_system_shopT();
	}
	enum
	{
	};
	INT32 SystemID = 0;            //系统ID
	INT32 CurrencyType = 0;				//支付类型
	float Price = 0.0f;				//价格
	TStr AppleshopID = "";				//苹果商品id
	INT32 GoodsType1 = 0;				//商品1类型
	INT32 IDOrNumber_GoodsType1 = 0;				//商品1参数
	INT32 Quantity1 = 0;				//商品1数量
	TStr GoodsImage1 = "";				//商品1图
	INT32 GoodsType2 = 0;				//商品2类型
	INT32 IDOrNumber_GoodsType2 = 0;				//商品2参数
	INT32 Quantity2 = 0;				//商品2数量
	TStr GoodsImage2 = "";				//商品2图
	INT32 GoodsType3 = 0;				//商品3类型
	INT32 IDOrNumber_GoodsType3 = 0;				//商品3参数
	INT32 Quantity3 = 0;				//商品3数量
	TStr GoodsImage3 = "";				//商品3图
	INT32 GoodsType4 = 0;				//商品4类型
	INT32 IDOrNumber_GoodsType4 = 0;				//商品4参数
	INT32 Quantity4 = 0;				//商品4数量
	TStr GoodsImage4 = "";				//商品4图
	INT32 GoodsType5 = 0;				//商品5类型
	INT32 IDOrNumber_GoodsType5 = 0;				//商品5参数
	INT32 Quantity5 = 0;				//商品5数量
	TStr GoodsImage5 = "";				//商品5图
	INT32 GoodsType6 = 0;				//商品6类型
	INT32 IDOrNumber_GoodsType6 = 0;				//商品6参数
	INT32 Quantity6 = 0;				//商品6数量
	TStr GoodsImage6 = "";				//商品6图
	INT32 GoodsType7 = 0;				//商品7类型
	INT32 IDOrNumber_GoodsType7 = 0;				//商品7参数
	INT32 Quantity7 = 0;				//商品7数量
	TStr GoodsImage7 = "";				//商品7图
	INT32 GoodsType8 = 0;				//商品8类型
	INT32 IDOrNumber_GoodsType8 = 0;				//商品8参数
	INT32 Quantity8 = 0;				//商品8数量
	TStr GoodsImage8 = "";				//商品8图
};
CreateCsvClass(table_system_shop);

struct table_taskT : ConfigBaseT
{
	virtual ~table_taskT()
	{
	}
	table_taskT()
	{
		FileName = "table_task.csv";
		_kf =
		{
			{"TaskId",{INT_FD, &TaskId}},
			{"Taskdec",{TSTR_FD, &Taskdec}},
			{"TaskIcon",{TSTR_FD, &TaskIcon}},
			{"TaskType",{INT_FD, &TaskType}},
			{"SubTaskType",{INT_FD, &SubTaskType}},
			{"TaskSw",{INT_FD, &TaskSw}},
			{"TaskSwPara1",{INT_FD, &TaskSwPara1}},
			{"TaskSwPara2",{INT_FD, &TaskSwPara2}},
			{"TaskSwPara3",{INT_FD, &TaskSwPara3}},
			{"TaskFollow",{INT_FD, &TaskFollow}},
			{"TaskName",{TSTR_FD, &TaskName}},
			{"TaskTips",{TSTR_FD, &TaskTips}},
			{"TaskAim",{INT_FD, &TaskAim}},
			{"TaskAimPara1",{INT_FD, &TaskAimPara1}},
			{"TaskAimPara2",{INT_FD, &TaskAimPara2}},
			{"TaskAimPara3",{INT_FD, &TaskAimPara3}},
			{"TaskAimPara4",{INT_FD, &TaskAimPara4}},
			{"TaskAimPara5",{INT_FD, &TaskAimPara5}},
			{"TaskAimPara6",{INT_FD, &TaskAimPara6}},
			{"TaskAwardImage",{INT_FD, &TaskAwardImage}},
			{"TaskAward",{INT_FD, &TaskAward}},
			{"TaskAwardPara",{INT_FD, &TaskAwardPara}},
			{"TaskSkipPara1",{INT_FD, &TaskSkipPara1}},
			{"AdvertisingPara1",{INT_FD, &AdvertisingPara1}},
			{"TaskSkipPara2",{INT_FD, &TaskSkipPara2}},
			{"NewtaskSound",{TSTR_FD, &NewtaskSound}},
			{"CompleteSound",{TSTR_FD, &CompleteSound}},
			{"LinkLevel1",{INT_FD, &LinkLevel1}},
			{"LinkLevel2",{INT_FD, &LinkLevel2}},
			{"LinkLevel3",{INT_FD, &LinkLevel3}},
			{"TaskdecKey",{TSTR_FD, &TaskdecKey}},
			{"TaskTipsKey",{TSTR_FD, &TaskTipsKey}}
		};
	}
	virtual table_taskT* create()
	{
		return new table_taskT();
	}
	enum
	{
	};
	INT32 TaskId = 0;            //任务id
	TStr Taskdec = "";				//任务目标
	TStr TaskIcon = "";				//图标ID
	INT32 TaskType = 0;				//任务所属模块
	INT32 SubTaskType = 0;				//任务关联位置
	INT32 TaskSw = 0;				//任务开启条件
	INT32 TaskSwPara1 = 0;				//开启条件参数1
	INT32 TaskSwPara2 = 0;				//开启条件参数2
	INT32 TaskSwPara3 = 0;				//开启条件参数3
	INT32 TaskFollow = 0;				//后续任务参数
	TStr TaskName = "";				//任务名称
	TStr TaskTips = "";				//任务描述
	INT32 TaskAim = 0;				//任务完成条件
	INT32 TaskAimPara1 = 0;				//条件参数1
	INT32 TaskAimPara2 = 0;				//条件参数2
	INT32 TaskAimPara3 = 0;				//条件参数3
	INT32 TaskAimPara4 = 0;				//条件参数4
	INT32 TaskAimPara5 = 0;				//条件参数5
	INT32 TaskAimPara6 = 0;				//条件参数6
	INT32 TaskAwardImage = 0;				//任务奖励显示
	INT32 TaskAward = 0;				//任务奖励
	INT32 TaskAwardPara = 0;				//奖励发放参数
	INT32 TaskSkipPara1 = 0;				//钻石跳过参数
	INT32 AdvertisingPara1 = 0;				//广告
次数配置
	INT32 TaskSkipPara2 = 0;				//广告
钻石参数
	TStr NewtaskSound = "";				//任务开启音效
	TStr CompleteSound = "";				//任务完成音效
	INT32 LinkLevel1 = 0;				//提示关卡1
	INT32 LinkLevel2 = 0;				//提示关卡2
	INT32 LinkLevel3 = 0;				//提示关卡3
	TStr TaskdecKey = "";				//Key
	TStr TaskTipsKey = "";				//Key
};
CreateCsvClass(table_task);

struct table_task_everydayT : ConfigBaseT
{
	virtual ~table_task_everydayT()
	{
	}
	table_task_everydayT()
	{
		FileName = "table_task_everyday.csv";
		_kf =
		{
			{"TaskId",{INT_FD, &TaskId}},
			{"Taskdec",{TSTR_FD, &Taskdec}},
			{"Fixed",{INT_FD, &Fixed}},
			{"TaskAim",{INT_FD, &TaskAim}},
			{"TaskAimPara1",{INT_FD, &TaskAimPara1}},
			{"TaskAimPara2",{INT_FD, &TaskAimPara2}},
			{"TaskAimPara3",{TSTR_FD, &TaskAimPara3}},
			{"TaskAimPara4",{INT_FD, &TaskAimPara4}},
			{"TaskAimPara5",{INT_FD, &TaskAimPara5}},
			{"TaskAimPara6",{INT_FD, &TaskAimPara6}},
			{"CountingRange",{INT_FD, &CountingRange}},
			{"TaskAwardType1",{INT_FD, &TaskAwardType1}},
			{"Awardid1",{INT_FD, &Awardid1}},
			{"Num1",{INT_FD, &Num1}},
			{"TaskAward1Para",{INT_FD, &TaskAward1Para}},
			{"TaskAwardType2",{INT_FD, &TaskAwardType2}},
			{"Awardid2",{INT_FD, &Awardid2}},
			{"Num2",{INT_FD, &Num2}},
			{"TaskAward2Para",{INT_FD, &TaskAward2Para}},
			{"GuideType",{INT_FD, &GuideType}},
			{"GuidePara",{TSTR_FD, &GuidePara}},
			{"GuideParabeizhu",{TSTR_FD, &GuideParabeizhu}},
			{"TaskTipsKey",{TSTR_FD, &TaskTipsKey}},
			{"BubbleTips",{TSTR_FD, &BubbleTips}},
			{"BubbleTipsKey",{TSTR_FD, &BubbleTipsKey}}
		};
	}
	virtual table_task_everydayT* create()
	{
		return new table_task_everydayT();
	}
	enum
	{
	};
	INT32 TaskId = 0;            //任务id
	TStr Taskdec = "";				//任务目标
	INT32 Fixed = 0;				//是否为固定任务
	INT32 TaskAim = 0;				//任务完成条件
	INT32 TaskAimPara1 = 0;				//条件参数1
	INT32 TaskAimPara2 = 0;				//条件参数2
	TStr TaskAimPara3 = "";				//条件参数3
	INT32 TaskAimPara4 = 0;				//条件参数4
	INT32 TaskAimPara5 = 0;				//条件参数5
	INT32 TaskAimPara6 = 0;				//条件参数6
	INT32 CountingRange = 0;				//任务计数范围
	INT32 TaskAwardType1 = 0;				//任务奖励1显示
	INT32 Awardid1 = 0;				//任务奖励1
	INT32 Num1 = 0;				//奖励数量
	INT32 TaskAward1Para = 0;				//奖励1发放参数
	INT32 TaskAwardType2 = 0;				//任务奖励2显示
	INT32 Awardid2 = 0;				//任务奖励2
	INT32 Num2 = 0;				//奖励数量
	INT32 TaskAward2Para = 0;				//奖励2发放参数
	INT32 GuideType = 0;				//引导类型
	TStr GuidePara = "";				//参数
	TStr GuideParabeizhu = "";				//备注
	TStr TaskTipsKey = "";				//Key
	TStr BubbleTips = "";				//气泡提示
	TStr BubbleTipsKey = "";				//Key
};
CreateCsvClass(table_task_everyday);

struct table_text_cluesT : ConfigBaseT
{
	virtual ~table_text_cluesT()
	{
	}
	table_text_cluesT()
	{
		FileName = "table_text_clues.csv";
		_kf =
		{
			{"Number",{INT_FD, &Number}},
			{"Describe",{TSTR_FD, &Describe}},
			{"Text",{TSTR_FD, &Text}},
			{"TextKey",{TSTR_FD, &TextKey}}
		};
	}
	virtual table_text_cluesT* create()
	{
		return new table_text_cluesT();
	}
	enum
	{
	};
	INT32 Number = 0;            //序号
	TStr Describe = "";				//描述
	TStr Text = "";				//文字
	TStr TextKey = "";				//Key
};
CreateCsvClass(table_text_clues);

struct table_text_localizationT : ConfigBaseT
{
	virtual ~table_text_localizationT()
	{
	}
	table_text_localizationT()
	{
		FileName = "table_text_localization.csv";
		_kf =
		{
			{"Value",{INT_FD, &Value}},
			{"TextKey",{TSTR_FD, &TextKey}},
			{"Chinese",{TSTR_FD, &Chinese}},
			{"English",{TSTR_FD, &English}}
		};
	}
	virtual table_text_localizationT* create()
	{
		return new table_text_localizationT();
	}
	enum
	{
	};
	INT32 Value = 0;            //序号
	TStr TextKey = "";				//Key
	TStr Chinese = "";				//中文
	TStr English = "";				//英文
};
CreateCsvClass(table_text_localization);

struct table_tokenT : ConfigBaseT
{
	virtual ~table_tokenT()
	{
	}
	table_tokenT()
	{
		FileName = "table_token.csv";
		_kf =
		{
			{"TokenId",{INT_FD, &TokenId}},
			{"TokenIcon",{TSTR_FD, &TokenIcon}},
			{"TokenChr",{TSTR_FD, &TokenChr}}
		};
	}
	virtual table_tokenT* create()
	{
		return new table_tokenT();
	}
	enum
	{
	};
	INT32 TokenId = 0;            //代币id
	TStr TokenIcon = "";				//代币图标
	TStr TokenChr = "";				//代币品质
};
CreateCsvClass(table_token);

struct table_tutorial_controlsT : ConfigBaseT
{
	virtual ~table_tutorial_controlsT()
	{
	}
	table_tutorial_controlsT()
	{
		FileName = "table_tutorial_controls.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"Desc",{TSTR_FD, &Desc}},
			{"Path",{TSTR_FD, &Path}}
		};
	}
	virtual table_tutorial_controlsT* create()
	{
		return new table_tutorial_controlsT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	TStr Desc = "";				//功能
	TStr Path = "";				//路径
};
CreateCsvClass(table_tutorial_controls);

struct table_tutorial_eventsT : ConfigBaseT
{
	virtual ~table_tutorial_eventsT()
	{
	}
	table_tutorial_eventsT()
	{
		FileName = "table_tutorial_events.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"EventGroupId",{INT_FD, &EventGroupId}},
			{"EventGroupName",{TSTR_FD, &EventGroupName}},
			{"EventDesc",{TSTR_FD, &EventDesc}},
			{"CompleteType",{INT_FD, &CompleteType}}
		};
	}
	virtual table_tutorial_eventsT* create()
	{
		return new table_tutorial_eventsT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	INT32 EventGroupId = 0;				//事件组
	TStr EventGroupName = "";				//事件组名称
	TStr EventDesc = "";				//事件描述
	INT32 CompleteType = 0;				//内容类型
};
CreateCsvClass(table_tutorial_events);

struct table_tutorial_stepsT : ConfigBaseT
{
	virtual ~table_tutorial_stepsT()
	{
	}
	table_tutorial_stepsT()
	{
		FileName = "table_tutorial_steps.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"GroupID",{INT_FD, &GroupID}},
			{"GroupName",{TSTR_FD, &GroupName}},
			{"GroupStepID",{INT_FD, &GroupStepID}},
			{"NextID",{INT_FD, &NextID}},
			{"WaitTime",{FLOAT_FD, &WaitTime}},
			{"ContentType",{INT_FD, &ContentType}},
			{"EventGroupId",{INT_FD, &EventGroupId}},
			{"IsPause",{INT_FD, &IsPause}},
			{"BIEvent",{INT_FD, &BIEvent}},
			{"ControlID",{INT_FD, &ControlID}},
			{"IsButton",{INT_FD, &IsButton}},
			{"Focus",{INT_FD, &Focus}},
			{"MaskRes",{TSTR_FD, &MaskRes}},
			{"MaskEffect",{TSTR_FD, &MaskEffect}},
			{"UILocation",{INT_FD, &UILocation}},
			{"OffsetX",{INT_FD, &OffsetX}},
			{"OffsetY",{INT_FD, &OffsetY}},
			{"UIText",{TSTR_FD, &UIText}},
			{"DisplayType",{INT_FD, &DisplayType}},
			{"PageNum",{TSTR_FD, &PageNum}},
			{"NpcSide",{INT_FD, &NpcSide}},
			{"Portrait",{TSTR_FD, &Portrait}},
			{"Flip",{INT_FD, &Flip}},
			{"ImageRes",{TSTR_FD, &ImageRes}},
			{"MovieRes",{TSTR_FD, &MovieRes}},
			{"PageText",{TSTR_FD, &PageText}},
			{"Mask",{INT_FD, &Mask}},
			{"CameraTo",{INT_FD, &CameraTo}},
			{"ArrowTo",{INT_FD, &ArrowTo}},
			{"ArrowImage",{TSTR_FD, &ArrowImage}},
			{"ShowTime",{FLOAT_FD, &ShowTime}},
			{"HideTime",{FLOAT_FD, &HideTime}},
			{"UITextKey",{TSTR_FD, &UITextKey}},
			{"GroupNameKey",{TSTR_FD, &GroupNameKey}},
			{"PageTextKey",{TSTR_FD, &PageTextKey}},
			{"ScreenInfoKey",{TSTR_FD, &ScreenInfoKey}}
		};
	}
	virtual table_tutorial_stepsT* create()
	{
		return new table_tutorial_stepsT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	INT32 GroupID = 0;				//指引组
	TStr GroupName = "";				//指引组名称
	INT32 GroupStepID = 0;				//步骤Id
	INT32 NextID = 0;				//下一主键Id
	float WaitTime = 0.0f;				//点击按钮后等待时长
	INT32 ContentType = 0;				//内容类型
	INT32 EventGroupId = 0;				//关联事件组ID
	INT32 IsPause = 0;				//是否暂停
	INT32 BIEvent = 0;				//发送BI打点事件
	INT32 ControlID = 0;				//ControlID表索引
	INT32 IsButton = 0;				//指向按钮或区域
	INT32 Focus = 0;				//是否聚焦
	TStr MaskRes = "";				//蒙版资源
	TStr MaskEffect = "";				//蒙版特效
	INT32 UILocation = 0;				//指引方位
	INT32 OffsetX = 0;				//横向偏移量
	INT32 OffsetY = 0;				//纵向偏移量
	TStr UIText = "";				//UI文本
	INT32 DisplayType = 0;				//展示类型
	TStr PageNum = "";				//页码
	INT32 NpcSide = 0;				//NPC位置
	TStr Portrait = "";				//半身像路径
	INT32 Flip = 0;				//是否翻转
	TStr ImageRes = "";				//图片资源
	TStr MovieRes = "";				//动画资源
	TStr PageText = "";				//页面内容
	INT32 Mask = 0;				//蒙灰
	INT32 CameraTo = 0;				//镜头跳转
	INT32 ArrowTo = 0;				//是否有指向箭头
	TStr ArrowImage = "";				//指示箭头资源文件
	float ShowTime = 0.0f;				//指示存在时间
	float HideTime = 0.0f;				//指示消失时间
	TStr UITextKey = "";				//UI文本
	TStr GroupNameKey = "";				//指引组名称
	TStr PageTextKey = "";				//页面内容
	TStr ScreenInfoKey = "";				//全屏文字内容
};
CreateCsvClass(table_tutorial_steps);

struct table_tutorial_triggersT : ConfigBaseT
{
	virtual ~table_tutorial_triggersT()
	{
	}
	table_tutorial_triggersT()
	{
		FileName = "table_tutorial_triggers.csv";
		_kf =
		{
			{"ID",{INT_FD, &ID}},
			{"Trigger",{INT_FD, &Trigger}},
			{"Param1",{INT_FD, &Param1}},
			{"Param2",{INT_FD, &Param2}},
			{"TriggerScene",{INT_FD, &TriggerScene}},
			{"TriggerLevel",{INT_FD, &TriggerLevel}},
			{"TriggerCount",{INT_FD, &TriggerCount}},
			{"FirstStepId",{INT_FD, &FirstStepId}},
			{"RelateId",{INT_FD, &RelateId}},
			{"IsPause",{INT_FD, &IsPause}}
		};
	}
	virtual table_tutorial_triggersT* create()
	{
		return new table_tutorial_triggersT();
	}
	enum
	{
	};
	INT32 ID = 0;            //ID
	INT32 Trigger = 0;				//触发时机
	INT32 Param1 = 0;				//触发类型
	INT32 Param2 = 0;				//触发参数
	INT32 TriggerScene = 0;				//触发场景
	INT32 TriggerLevel = 0;				//触发关卡
	INT32 TriggerCount = 0;				//触发次数
	INT32 FirstStepId = 0;				//首步骤Id
	INT32 RelateId = 0;				//关联Id
	INT32 IsPause = 0;				//是否暂停(暂时废弃)
};
CreateCsvClass(table_tutorial_triggers);

struct table_weather_rainT : ConfigBaseT
{
	virtual ~table_weather_rainT()
	{
	}
	table_weather_rainT()
	{
		FileName = "table_weather_rain.csv";
		_kf =
		{
			{"RainID",{INT_FD, &RainID}},
			{"Case1",{INT_FD, &Case1}},
			{"Case2",{INT_FD, &Case2}},
			{"Case3",{INT_FD, &Case3}},
			{"Case4",{INT_FD, &Case4}},
			{"Case5",{INT_FD, &Case5}},
			{"Case6",{INT_FD, &Case6}},
			{"Case7",{INT_FD, &Case7}},
			{"Case8",{INT_FD, &Case8}},
			{"Case9",{INT_FD, &Case9}},
			{"Case10",{INT_FD, &Case10}},
			{"drop",{INT_FD, &drop}},
			{"Image",{TSTR_FD, &Image}},
			{"ImageEffect",{TSTR_FD, &ImageEffect}},
			{"SpeedupEffectLocation",{TSTR_FD, &SpeedupEffectLocation}},
			{"SpeedupEffect",{TSTR_FD, &SpeedupEffect}}
		};
	}
	virtual table_weather_rainT* create()
	{
		return new table_weather_rainT();
	}
	enum
	{
	};
	INT32 RainID = 0;            //雨云ID
	INT32 Case1 = 0;				//情况1
	INT32 Case2 = 0;				//情况2
	INT32 Case3 = 0;				//情况3
	INT32 Case4 = 0;				//情况4
	INT32 Case5 = 0;				//情况5
	INT32 Case6 = 0;				//情况6
	INT32 Case7 = 0;				//情况7
	INT32 Case8 = 0;				//情况8
	INT32 Case9 = 0;				//情况9
	INT32 Case10 = 0;				//情况10
	INT32 drop = 0;				//掉落信息
	TStr Image = "";				//美术资源
	TStr ImageEffect = "";				//特效
	TStr SpeedupEffectLocation = "";				//加速时特效挂点
	TStr SpeedupEffect = "";				//加速时特效
};
CreateCsvClass(table_weather_rain);

struct table_weather_raincorrectionT : ConfigBaseT
{
	virtual ~table_weather_raincorrectionT()
	{
	}
	table_weather_raincorrectionT()
	{
		FileName = "table_weather_raincorrection.csv";
		_kf =
		{
			{"RainID",{INT_FD, &RainID}},
			{"RainFunction",{INT_FD, &RainFunction}},
			{"Function1",{INT_FD, &Function1}},
			{"Num1",{FLOAT_FD, &Num1}},
			{"Function2",{INT_FD, &Function2}},
			{"Num2",{FLOAT_FD, &Num2}},
			{"Function4",{INT_FD, &Function4}},
			{"Num4",{FLOAT_FD, &Num4}},
			{"Function8",{INT_FD, &Function8}},
			{"Num8",{FLOAT_FD, &Num8}},
			{"Function16",{INT_FD, &Function16}},
			{"Num16",{FLOAT_FD, &Num16}}
		};
	}
	virtual table_weather_raincorrectionT* create()
	{
		return new table_weather_raincorrectionT();
	}
	enum
	{
	};
	INT32 RainID = 0;            //雨云修正ID
	INT32 RainFunction = 0;				//修正类别和值
	INT32 Function1 = 0;				//修正方法1
	float Num1 = 0.0f;				//修正值1
	INT32 Function2 = 0;				//修正方法2
	float Num2 = 0.0f;				//修正值2
	INT32 Function4 = 0;				//修正方法3
	float Num4 = 0.0f;				//修正值3
	INT32 Function8 = 0;				//修正方法4
	float Num8 = 0.0f;				//修正值4
	INT32 Function16 = 0;				//修正方法5
	float Num16 = 0.0f;				//修正值5
};
CreateCsvClass(table_weather_raincorrection);

struct table_weather_rainruleT : ConfigBaseT
{
	virtual ~table_weather_rainruleT()
	{
	}
	table_weather_rainruleT()
	{
		FileName = "table_weather_rainrule.csv";
		_kf =
		{
			{"ArticleID",{INT_FD, &ArticleID}},
			{"Article101001",{INT_FD, &Article101001}},
			{"Article101002",{INT_FD, &Article101002}},
			{"Article101003",{INT_FD, &Article101003}},
			{"Article101004",{INT_FD, &Article101004}},
			{"Article101005",{INT_FD, &Article101005}},
			{"Article101006",{INT_FD, &Article101006}},
			{"Article101007",{INT_FD, &Article101007}},
			{"Article101008",{INT_FD, &Article101008}},
			{"Article101009",{INT_FD, &Article101009}},
			{"Article101010",{INT_FD, &Article101010}},
			{"Article101011",{INT_FD, &Article101011}},
			{"Article101012",{INT_FD, &Article101012}},
			{"Article101013",{INT_FD, &Article101013}},
			{"Article101014",{INT_FD, &Article101014}},
			{"Article101015",{INT_FD, &Article101015}},
			{"Article101016",{INT_FD, &Article101016}},
			{"Article101017",{INT_FD, &Article101017}},
			{"Article101018",{INT_FD, &Article101018}},
			{"Article101019",{INT_FD, &Article101019}},
			{"Article101020",{INT_FD, &Article101020}},
			{"Article101021",{INT_FD, &Article101021}},
			{"Article101022",{INT_FD, &Article101022}},
			{"Article101023",{INT_FD, &Article101023}},
			{"Article101024",{INT_FD, &Article101024}},
			{"Article101025",{INT_FD, &Article101025}},
			{"Article101026",{INT_FD, &Article101026}},
			{"Article101027",{INT_FD, &Article101027}},
			{"Article101028",{INT_FD, &Article101028}},
			{"Article101029",{INT_FD, &Article101029}},
			{"Article101030",{INT_FD, &Article101030}},
			{"Article101031",{INT_FD, &Article101031}},
			{"Article101032",{INT_FD, &Article101032}},
			{"Article101033",{INT_FD, &Article101033}},
			{"Article101034",{INT_FD, &Article101034}},
			{"Article101035",{INT_FD, &Article101035}},
			{"Article101036",{INT_FD, &Article101036}},
			{"Article101037",{INT_FD, &Article101037}},
			{"Article101038",{INT_FD, &Article101038}},
			{"Article101039",{INT_FD, &Article101039}},
			{"Article101040",{INT_FD, &Article101040}},
			{"Article101041",{INT_FD, &Article101041}},
			{"Article101042",{INT_FD, &Article101042}},
			{"Article101043",{INT_FD, &Article101043}},
			{"Article101044",{INT_FD, &Article101044}},
			{"Article101045",{INT_FD, &Article101045}},
			{"Article101046",{INT_FD, &Article101046}},
			{"Article101047",{INT_FD, &Article101047}},
			{"Article101048",{INT_FD, &Article101048}},
			{"Article101049",{INT_FD, &Article101049}},
			{"Article101050",{INT_FD, &Article101050}},
			{"Article101051",{INT_FD, &Article101051}},
			{"Article101052",{INT_FD, &Article101052}},
			{"Article101053",{INT_FD, &Article101053}},
			{"Article101054",{INT_FD, &Article101054}},
			{"Article101055",{INT_FD, &Article101055}},
			{"Article101056",{INT_FD, &Article101056}},
			{"Article101057",{INT_FD, &Article101057}},
			{"Article101058",{INT_FD, &Article101058}},
			{"Article101059",{INT_FD, &Article101059}},
			{"Article101060",{INT_FD, &Article101060}},
			{"Article101061",{INT_FD, &Article101061}},
			{"Article101062",{INT_FD, &Article101062}},
			{"Article101063",{INT_FD, &Article101063}},
			{"Article101064",{INT_FD, &Article101064}},
			{"Article101065",{INT_FD, &Article101065}},
			{"Article101066",{INT_FD, &Article101066}},
			{"Article101067",{INT_FD, &Article101067}},
			{"Article101068",{INT_FD, &Article101068}},
			{"Article101069",{INT_FD, &Article101069}},
			{"Article101070",{INT_FD, &Article101070}},
			{"Article101071",{INT_FD, &Article101071}},
			{"Article101072",{INT_FD, &Article101072}},
			{"Article101073",{INT_FD, &Article101073}},
			{"Article101074",{INT_FD, &Article101074}},
			{"Article101075",{INT_FD, &Article101075}},
			{"Article101076",{INT_FD, &Article101076}},
			{"Article101077",{INT_FD, &Article101077}},
			{"Article101078",{INT_FD, &Article101078}},
			{"Article101079",{INT_FD, &Article101079}},
			{"Article101080",{INT_FD, &Article101080}},
			{"Article101081",{INT_FD, &Article101081}},
			{"Article101082",{INT_FD, &Article101082}},
			{"Article101083",{INT_FD, &Article101083}},
			{"Article101084",{INT_FD, &Article101084}},
			{"Article101085",{INT_FD, &Article101085}},
			{"Article101086",{INT_FD, &Article101086}},
			{"Article101087",{INT_FD, &Article101087}},
			{"Article101088",{INT_FD, &Article101088}},
			{"Article101089",{INT_FD, &Article101089}},
			{"Article101090",{INT_FD, &Article101090}},
			{"Article101091",{INT_FD, &Article101091}},
			{"Article101092",{INT_FD, &Article101092}},
			{"Article101093",{INT_FD, &Article101093}},
			{"Article101094",{INT_FD, &Article101094}},
			{"Article101095",{INT_FD, &Article101095}},
			{"Article101096",{INT_FD, &Article101096}},
			{"Article101097",{INT_FD, &Article101097}},
			{"Article101098",{INT_FD, &Article101098}},
			{"Article101099",{INT_FD, &Article101099}},
			{"Article101100",{INT_FD, &Article101100}}
		};
	}
	virtual table_weather_rainruleT* create()
	{
		return new table_weather_rainruleT();
	}
	enum
	{
	};
	INT32 ArticleID = 0;            //道具ID
	INT32 Article101001 = 0;				//云道具1
对应修正ID
	INT32 Article101002 = 0;				//云道具2
对应修正ID
	INT32 Article101003 = 0;				//云道具3
对应修正ID
	INT32 Article101004 = 0;				//云道具4
对应修正ID
	INT32 Article101005 = 0;				//云道具5
对应修正ID
	INT32 Article101006 = 0;				//云道具6
对应修正ID
	INT32 Article101007 = 0;				//云道具7
对应修正ID
	INT32 Article101008 = 0;				//云道具8
对应修正ID
	INT32 Article101009 = 0;				//云道具9
对应修正ID
	INT32 Article101010 = 0;				//云道具10
对应修正ID
	INT32 Article101011 = 0;				//云道具11
对应修正ID
	INT32 Article101012 = 0;				//云道具12
对应修正ID
	INT32 Article101013 = 0;				//云道具13
对应修正ID
	INT32 Article101014 = 0;				//云道具14
对应修正ID
	INT32 Article101015 = 0;				//云道具15
对应修正ID
	INT32 Article101016 = 0;				//云道具16
对应修正ID
	INT32 Article101017 = 0;				//云道具17
对应修正ID
	INT32 Article101018 = 0;				//云道具18
对应修正ID
	INT32 Article101019 = 0;				//云道具19
对应修正ID
	INT32 Article101020 = 0;				//云道具20
对应修正ID
	INT32 Article101021 = 0;				//云道具21
对应修正ID
	INT32 Article101022 = 0;				//云道具22
对应修正ID
	INT32 Article101023 = 0;				//云道具23
对应修正ID
	INT32 Article101024 = 0;				//云道具24
对应修正ID
	INT32 Article101025 = 0;				//云道具25
对应修正ID
	INT32 Article101026 = 0;				//云道具26
对应修正ID
	INT32 Article101027 = 0;				//云道具27
对应修正ID
	INT32 Article101028 = 0;				//云道具28
对应修正ID
	INT32 Article101029 = 0;				//云道具29
对应修正ID
	INT32 Article101030 = 0;				//云道具30
对应修正ID
	INT32 Article101031 = 0;				//云道具31
对应修正ID
	INT32 Article101032 = 0;				//云道具32
对应修正ID
	INT32 Article101033 = 0;				//云道具33
对应修正ID
	INT32 Article101034 = 0;				//云道具34
对应修正ID
	INT32 Article101035 = 0;				//云道具35
对应修正ID
	INT32 Article101036 = 0;				//云道具36
对应修正ID
	INT32 Article101037 = 0;				//云道具37
对应修正ID
	INT32 Article101038 = 0;				//云道具38
对应修正ID
	INT32 Article101039 = 0;				//云道具39
对应修正ID
	INT32 Article101040 = 0;				//云道具40
对应修正ID
	INT32 Article101041 = 0;				//云道具41
对应修正ID
	INT32 Article101042 = 0;				//云道具42
对应修正ID
	INT32 Article101043 = 0;				//云道具43
对应修正ID
	INT32 Article101044 = 0;				//云道具44
对应修正ID
	INT32 Article101045 = 0;				//云道具45
对应修正ID
	INT32 Article101046 = 0;				//云道具46
对应修正ID
	INT32 Article101047 = 0;				//云道具47
对应修正ID
	INT32 Article101048 = 0;				//云道具48
对应修正ID
	INT32 Article101049 = 0;				//云道具49
对应修正ID
	INT32 Article101050 = 0;				//云道具50
对应修正ID
	INT32 Article101051 = 0;				//云道具51
对应修正ID
	INT32 Article101052 = 0;				//云道具52
对应修正ID
	INT32 Article101053 = 0;				//云道具53
对应修正ID
	INT32 Article101054 = 0;				//云道具54
对应修正ID
	INT32 Article101055 = 0;				//云道具55
对应修正ID
	INT32 Article101056 = 0;				//云道具56
对应修正ID
	INT32 Article101057 = 0;				//云道具57
对应修正ID
	INT32 Article101058 = 0;				//云道具58
对应修正ID
	INT32 Article101059 = 0;				//云道具59
对应修正ID
	INT32 Article101060 = 0;				//云道具60
对应修正ID
	INT32 Article101061 = 0;				//云道具61
对应修正ID
	INT32 Article101062 = 0;				//云道具62
对应修正ID
	INT32 Article101063 = 0;				//云道具63
对应修正ID
	INT32 Article101064 = 0;				//云道具64
对应修正ID
	INT32 Article101065 = 0;				//云道具65
对应修正ID
	INT32 Article101066 = 0;				//云道具66
对应修正ID
	INT32 Article101067 = 0;				//云道具67
对应修正ID
	INT32 Article101068 = 0;				//云道具68
对应修正ID
	INT32 Article101069 = 0;				//云道具69
对应修正ID
	INT32 Article101070 = 0;				//云道具70
对应修正ID
	INT32 Article101071 = 0;				//云道具71
对应修正ID
	INT32 Article101072 = 0;				//云道具72
对应修正ID
	INT32 Article101073 = 0;				//云道具73
对应修正ID
	INT32 Article101074 = 0;				//云道具74
对应修正ID
	INT32 Article101075 = 0;				//云道具75
对应修正ID
	INT32 Article101076 = 0;				//云道具76
对应修正ID
	INT32 Article101077 = 0;				//云道具77
对应修正ID
	INT32 Article101078 = 0;				//云道具78
对应修正ID
	INT32 Article101079 = 0;				//云道具79
对应修正ID
	INT32 Article101080 = 0;				//云道具80
对应修正ID
	INT32 Article101081 = 0;				//云道具81
对应修正ID
	INT32 Article101082 = 0;				//云道具82
对应修正ID
	INT32 Article101083 = 0;				//云道具83
对应修正ID
	INT32 Article101084 = 0;				//云道具84
对应修正ID
	INT32 Article101085 = 0;				//云道具85
对应修正ID
	INT32 Article101086 = 0;				//云道具86
对应修正ID
	INT32 Article101087 = 0;				//云道具87
对应修正ID
	INT32 Article101088 = 0;				//云道具88
对应修正ID
	INT32 Article101089 = 0;				//云道具89
对应修正ID
	INT32 Article101090 = 0;				//云道具90
对应修正ID
	INT32 Article101091 = 0;				//云道具91
对应修正ID
	INT32 Article101092 = 0;				//云道具92
对应修正ID
	INT32 Article101093 = 0;				//云道具93
对应修正ID
	INT32 Article101094 = 0;				//云道具94
对应修正ID
	INT32 Article101095 = 0;				//云道具95
对应修正ID
	INT32 Article101096 = 0;				//云道具96
对应修正ID
	INT32 Article101097 = 0;				//云道具97
对应修正ID
	INT32 Article101098 = 0;				//云道具98
对应修正ID
	INT32 Article101099 = 0;				//云道具99
对应修正ID
	INT32 Article101100 = 0;				//云道具100
对应修正ID
};
CreateCsvClass(table_weather_rainrule);

struct table_weather_thunderT : ConfigBaseT
{
	virtual ~table_weather_thunderT()
	{
	}
	table_weather_thunderT()
	{
		FileName = "table_weather_thunder.csv";
		_kf =
		{
			{"ThunderID",{INT_FD, &ThunderID}},
			{"Name",{TSTR_FD, &Name}},
			{"Describe",{TSTR_FD, &Describe}},
			{"Level",{INT_FD, &Level}},
			{"SurvivalTime",{FLOAT_FD, &SurvivalTime}},
			{"Range",{INT_FD, &Range}},
			{"ActivateTime",{FLOAT_FD, &ActivateTime}},
			{"PeriodTime",{FLOAT_FD, &PeriodTime}},
			{"AIConfig",{TSTR_FD, &AIConfig}},
			{"CommonImage",{TSTR_FD, &CommonImage}},
			{"PreviewImage",{TSTR_FD, &PreviewImage}},
			{"PreviewEffect",{TSTR_FD, &PreviewEffect}},
			{"ActivateEffect",{TSTR_FD, &ActivateEffect}},
			{"ActivateSound",{TSTR_FD, &ActivateSound}},
			{"NameKey",{TSTR_FD, &NameKey}},
			{"DesKey",{TSTR_FD, &DesKey}}
		};
	}
	virtual table_weather_thunderT* create()
	{
		return new table_weather_thunderT();
	}
	enum
	{
	};
	INT32 ThunderID = 0;            //雷ID
	TStr Name = "";				//名称
	TStr Describe = "";				//描述
	INT32 Level = 0;				//等级
	float SurvivalTime = 0.0f;				//生存时间
	INT32 Range = 0;				//吸附范围
	float ActivateTime = 0.0f;				//激活时间
	float PeriodTime = 0.0f;				//间隔时间
	TStr AIConfig = "";				//AI
	TStr CommonImage = "";				//图片
美术资源
	TStr PreviewImage = "";				//激活效果
	TStr PreviewEffect = "";				//预览特效
	TStr ActivateEffect = "";				//激活特效
	TStr ActivateSound = "";				//激活中
音效
	TStr NameKey = "";				//多语言
名字
	TStr DesKey = "";				//多语言
描述
};
CreateCsvClass(table_weather_thunder);

struct table_worldmapT : ConfigBaseT
{
	virtual ~table_worldmapT()
	{
	}
	table_worldmapT()
	{
		FileName = "table_worldmap.csv";
		_kf =
		{
			{"WorldMapID",{INT_FD, &WorldMapID}},
			{"OutpostID",{INT_FD, &OutpostID}},
			{"OutpostResource",{TSTR_FD, &OutpostResource}},
			{"Rewards1",{TSTR_FD, &Rewards1}},
			{"Rewards2",{TSTR_FD, &Rewards2}},
			{"Rewards3",{TSTR_FD, &Rewards3}},
			{"Backgroundmusic",{TSTR_FD, &Backgroundmusic}}
		};
	}
	virtual table_worldmapT* create()
	{
		return new table_worldmapT();
	}
	enum
	{
	};
	INT32 WorldMapID = 0;            //区间序号
	INT32 OutpostID = 0;				//进入前哨ID
	TStr OutpostResource = "";				//前哨使用资源
	TStr Rewards1 = "";				//奖励1
图标
	TStr Rewards2 = "";				//奖励2
图标
	TStr Rewards3 = "";				//奖励3
图标
	TStr Backgroundmusic = "";				//哨站背景音乐
};
CreateCsvClass(table_worldmap);

#endif