/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleMatchSPVP.h
* Author:       甘业清
* Description:  匹配类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相关回调函数
*               ★用户创建上下线回调函数
*               ★服务器RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_MATCHSPVP_H
#define __MODULE_MATCHSPVP_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "MatchSPVPSvrRpc.pb.h"
#include "MatchSPVPCliRpc.pb.h"



//匹配实现类
class ModuleMatchSPVP : public ModuleBase
{
	DECLARE_INSTANCE(ModuleMatchSPVP);
public:
	friend class			ModuleMgr;

public:
	//匹配实现类构造函数
	ModuleMatchSPVP();
	
	//匹配实现类析构函数
	virtual					~ModuleMatchSPVP();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 uid, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 uid, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 uid );
	
	//配置表更新
	virtual void			OnConfigReload(const TStr& tableName);
	
	//有发布信息
	virtual void			OnPublish(const TStr& publishString);

public:
	/********************************************************************************************
	* Function:       CliRpcStartMatch
	* Description:    匹配-->开始匹配同步调用操作函数
	* Input:          MatchSPVPRpcStartMatchAsk& Ask 开始匹配请求
	* Output:         MatchSPVPRpcStartMatchReply& Reply 开始匹配回应
	********************************************************************************************/
	void CliRpcStartMatch( clientInfoT& clientInfo, MatchSPVPRpcStartMatchAsk& Ask, MatchSPVPRpcStartMatchReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientMatchBroadcas
	* Description:    匹配-->匹配通知异步通知操作函数
	* Input:          MatchSPVPRpcMatchBroadcasNotify& Notify 匹配通知服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientMatchBroadcas( INT64 UserId, MatchSPVPRpcMatchBroadcasNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcInvitation
	* Description:    匹配-->邀请同步调用操作函数
	* Input:          MatchSPVPRpcInvitationAsk& Ask 邀请请求
	* Output:         MatchSPVPRpcInvitationReply& Reply 邀请回应
	********************************************************************************************/
	void CliRpcInvitation( clientInfoT& clientInfo, MatchSPVPRpcInvitationAsk& Ask, MatchSPVPRpcInvitationReply& Reply );

	/********************************************************************************************
	* Function:       CliRpcAgreeInvitation
	* Description:    匹配-->同意邀请回应异步通知操作函数
	* Input:          MatchSPVPRpcAgreeInvitationNotify& Notify 同意邀请回应双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcAgreeInvitation( clientInfoT& clientInfo, MatchSPVPRpcAgreeInvitationNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientAgreeInvitation
	* Description:    匹配-->同意邀请回应异步通知操作函数
	* Input:          MatchSPVPRpcAgreeInvitationNotify& Notify 同意邀请回应双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientAgreeInvitation( INT64 UserId, MatchSPVPRpcAgreeInvitationNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientStartSelect
	* Description:    匹配-->开始选择界面异步通知操作函数
	* Input:          MatchSPVPRpcStartSelectNotify& Notify 开始选择界面服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientStartSelect( INT64 UserId, MatchSPVPRpcStartSelectNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcSelectHero
	* Description:    匹配-->选择英雄同步调用操作函数
	* Input:          MatchSPVPRpcSelectHeroAsk& Ask 选择英雄请求
	* Output:         MatchSPVPRpcSelectHeroReply& Reply 选择英雄回应
	********************************************************************************************/
	void CliRpcSelectHero( clientInfoT& clientInfo, MatchSPVPRpcSelectHeroAsk& Ask, MatchSPVPRpcSelectHeroReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientStartGame
	* Description:    匹配-->开始游戏异步通知操作函数
	* Input:          MatchSPVPRpcStartGameNotify& Notify 开始游戏服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientStartGame( INT64 UserId, MatchSPVPRpcStartGameNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientDeleteMatch
	* Description:    匹配-->取消匹配异步通知操作函数
	* Input:          MatchSPVPRpcDeleteMatchNotify& Notify 取消匹配服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientDeleteMatch( INT64 UserId, MatchSPVPRpcDeleteMatchNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcGetStatus
	* Description:    匹配-->获取状态同步调用操作函数
	* Input:          MatchSPVPRpcGetStatusAsk& Ask 获取状态请求
	* Output:         MatchSPVPRpcGetStatusReply& Reply 获取状态回应
	********************************************************************************************/
	void CliRpcGetStatus( clientInfoT& clientInfo, MatchSPVPRpcGetStatusAsk& Ask, MatchSPVPRpcGetStatusReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientChangeStatus
	* Description:    匹配-->修改状态异步通知操作函数
	* Input:          MatchSPVPRpcChangeStatusNotify& Notify 修改状态服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientChangeStatus( INT64 UserId, MatchSPVPRpcChangeStatusNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcShotOff
	* Description:    匹配-->剔出同步调用操作函数
	* Input:          MatchSPVPRpcShotOffAsk& Ask 剔出请求
	* Output:         MatchSPVPRpcShotOffReply& Reply 剔出回应
	********************************************************************************************/
	void CliRpcShotOff( clientInfoT& clientInfo, MatchSPVPRpcShotOffAsk& Ask, MatchSPVPRpcShotOffReply& Reply );

	/********************************************************************************************
	* Function:       CliRpcSelectScene
	* Description:    匹配-->选择场景异步通知操作函数
	* Input:          MatchSPVPRpcSelectSceneNotify& Notify 选择场景双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcSelectScene( clientInfoT& clientInfo, MatchSPVPRpcSelectSceneNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientSelectScene
	* Description:    匹配-->选择场景异步通知操作函数
	* Input:          MatchSPVPRpcSelectSceneNotify& Notify 选择场景双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientSelectScene( INT64 UserId, MatchSPVPRpcSelectSceneNotify& Notify );



public:
	//报告状态函数实现
	void SvrRpcBattleNum( int nodeId, MatchSPVPRpcBattleNumNotify& notify);


};

//匹配类的枚举定义
enum ConstMatchSPVPE
{
	MODULE_ID_MATCHSPVP                          = 21,	//匹配模块ID
	RPC_CODE_MATCHSPVP_STARTMATCH_REQUEST        = 2151,	//匹配-->开始匹配-->请求
	RPC_CODE_MATCHSPVP_MATCHBROADCAS_NOTIFY      = 2152,	//匹配-->匹配通知-->通知
	RPC_CODE_MATCHSPVP_INVITATION_REQUEST        = 2153,	//匹配-->邀请-->请求
	RPC_CODE_MATCHSPVP_AGREEINVITATION_NOTIFY    = 2154,	//匹配-->同意邀请回应-->通知
	RPC_CODE_MATCHSPVP_STARTSELECT_NOTIFY        = 2155,	//匹配-->开始选择界面-->通知
	RPC_CODE_MATCHSPVP_SELECTHERO_REQUEST        = 2156,	//匹配-->选择英雄-->请求
	RPC_CODE_MATCHSPVP_STARTGAME_NOTIFY          = 2157,	//匹配-->开始游戏-->通知
	RPC_CODE_MATCHSPVP_DELETEMATCH_NOTIFY        = 2158,	//匹配-->取消匹配-->通知
	RPC_CODE_MATCHSPVP_GETSTATUS_REQUEST         = 2159,	//匹配-->获取状态-->请求
	RPC_CODE_MATCHSPVP_CHANGESTATUS_NOTIFY       = 2160,	//匹配-->修改状态-->通知
	RPC_CODE_MATCHSPVP_SHOTOFF_REQUEST           = 2161,	//匹配-->剔出-->请求
	RPC_CODE_MATCHSPVP_SELECTSCENE_NOTIFY        = 2162,	//匹配-->选择场景-->通知


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<MatchSPVPRpcStartMatchAsk>{ enum{ID=RPC_CODE_MATCHSPVP_STARTMATCH_REQUEST};};
template<> struct MessageIdT<MatchSPVPRpcStartMatchReply>{ enum{ID=RPC_CODE_MATCHSPVP_STARTMATCH_REQUEST};};
template<> struct MessageIdT<MatchSPVPRpcMatchBroadcasNotify>{ enum{ID=RPC_CODE_MATCHSPVP_MATCHBROADCAS_NOTIFY};};
template<> struct MessageIdT<MatchSPVPRpcInvitationAsk>{ enum{ID=RPC_CODE_MATCHSPVP_INVITATION_REQUEST};};
template<> struct MessageIdT<MatchSPVPRpcInvitationReply>{ enum{ID=RPC_CODE_MATCHSPVP_INVITATION_REQUEST};};
template<> struct MessageIdT<MatchSPVPRpcAgreeInvitationNotify>{ enum{ID=RPC_CODE_MATCHSPVP_AGREEINVITATION_NOTIFY};};
template<> struct MessageIdT<MatchSPVPRpcStartSelectNotify>{ enum{ID=RPC_CODE_MATCHSPVP_STARTSELECT_NOTIFY};};
template<> struct MessageIdT<MatchSPVPRpcSelectHeroAsk>{ enum{ID=RPC_CODE_MATCHSPVP_SELECTHERO_REQUEST};};
template<> struct MessageIdT<MatchSPVPRpcSelectHeroReply>{ enum{ID=RPC_CODE_MATCHSPVP_SELECTHERO_REQUEST};};
template<> struct MessageIdT<MatchSPVPRpcStartGameNotify>{ enum{ID=RPC_CODE_MATCHSPVP_STARTGAME_NOTIFY};};
template<> struct MessageIdT<MatchSPVPRpcDeleteMatchNotify>{ enum{ID=RPC_CODE_MATCHSPVP_DELETEMATCH_NOTIFY};};
template<> struct MessageIdT<MatchSPVPRpcGetStatusAsk>{ enum{ID=RPC_CODE_MATCHSPVP_GETSTATUS_REQUEST};};
template<> struct MessageIdT<MatchSPVPRpcGetStatusReply>{ enum{ID=RPC_CODE_MATCHSPVP_GETSTATUS_REQUEST};};
template<> struct MessageIdT<MatchSPVPRpcChangeStatusNotify>{ enum{ID=RPC_CODE_MATCHSPVP_CHANGESTATUS_NOTIFY};};
template<> struct MessageIdT<MatchSPVPRpcShotOffAsk>{ enum{ID=RPC_CODE_MATCHSPVP_SHOTOFF_REQUEST};};
template<> struct MessageIdT<MatchSPVPRpcShotOffReply>{ enum{ID=RPC_CODE_MATCHSPVP_SHOTOFF_REQUEST};};
template<> struct MessageIdT<MatchSPVPRpcSelectSceneNotify>{ enum{ID=RPC_CODE_MATCHSPVP_SELECTSCENE_NOTIFY};};


#endif