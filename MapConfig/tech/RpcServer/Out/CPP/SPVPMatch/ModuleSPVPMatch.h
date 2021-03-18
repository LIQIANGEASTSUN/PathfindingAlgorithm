/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleSPVPMatch.h
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

#ifndef __MODULE_SPVPMATCH_H
#define __MODULE_SPVPMATCH_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "SPVPMatchCliRpc.pb.h"



//匹配实现类
class ModuleSPVPMatch : public ModuleBase
{
	DECLARE_INSTANCE(ModuleSPVPMatch);
public:
	friend class			ModuleMgr;

public:
	//匹配实现类构造函数
	ModuleSPVPMatch();
	
	//匹配实现类析构函数
	virtual					~ModuleSPVPMatch();

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
	* Input:          SPVPMatchRpcStartMatchAsk& Ask 开始匹配请求
	* Output:         SPVPMatchRpcStartMatchReply& Reply 开始匹配回应
	********************************************************************************************/
	void CliRpcStartMatch( clientInfoT& clientInfo, SPVPMatchRpcStartMatchAsk& Ask, SPVPMatchRpcStartMatchReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientMatchBroadcas
	* Description:    匹配-->匹配通知异步通知操作函数
	* Input:          SPVPMatchRpcMatchBroadcasNotify& Notify 匹配通知服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientMatchBroadcas( INT64 UserId, SPVPMatchRpcMatchBroadcasNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcInvitation
	* Description:    匹配-->邀请同步调用操作函数
	* Input:          SPVPMatchRpcInvitationAsk& Ask 邀请请求
	* Output:         SPVPMatchRpcInvitationReply& Reply 邀请回应
	********************************************************************************************/
	void CliRpcInvitation( clientInfoT& clientInfo, SPVPMatchRpcInvitationAsk& Ask, SPVPMatchRpcInvitationReply& Reply );

	/********************************************************************************************
	* Function:       CliRpcAgreeInvitation
	* Description:    匹配-->同意邀请回应异步通知操作函数
	* Input:          SPVPMatchRpcAgreeInvitationNotify& Notify 同意邀请回应双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcAgreeInvitation( clientInfoT& clientInfo, SPVPMatchRpcAgreeInvitationNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientAgreeInvitation
	* Description:    匹配-->同意邀请回应异步通知操作函数
	* Input:          SPVPMatchRpcAgreeInvitationNotify& Notify 同意邀请回应双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientAgreeInvitation( INT64 UserId, SPVPMatchRpcAgreeInvitationNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientStartSelect
	* Description:    匹配-->开始选择界面异步通知操作函数
	* Input:          SPVPMatchRpcStartSelectNotify& Notify 开始选择界面服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientStartSelect( INT64 UserId, SPVPMatchRpcStartSelectNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcSelectHero
	* Description:    匹配-->选择英雄同步调用操作函数
	* Input:          SPVPMatchRpcSelectHeroAsk& Ask 选择英雄请求
	* Output:         SPVPMatchRpcSelectHeroReply& Reply 选择英雄回应
	********************************************************************************************/
	void CliRpcSelectHero( clientInfoT& clientInfo, SPVPMatchRpcSelectHeroAsk& Ask, SPVPMatchRpcSelectHeroReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientStartGame
	* Description:    匹配-->开始游戏异步通知操作函数
	* Input:          SPVPMatchRpcStartGameNotify& Notify 开始游戏服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientStartGame( INT64 UserId, SPVPMatchRpcStartGameNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientDeleteMatch
	* Description:    匹配-->取消匹配异步通知操作函数
	* Input:          SPVPMatchRpcDeleteMatchNotify& Notify 取消匹配服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientDeleteMatch( INT64 UserId, SPVPMatchRpcDeleteMatchNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcGetStatus
	* Description:    匹配-->获取状态同步调用操作函数
	* Input:          SPVPMatchRpcGetStatusAsk& Ask 获取状态请求
	* Output:         SPVPMatchRpcGetStatusReply& Reply 获取状态回应
	********************************************************************************************/
	void CliRpcGetStatus( clientInfoT& clientInfo, SPVPMatchRpcGetStatusAsk& Ask, SPVPMatchRpcGetStatusReply& Reply );

	/********************************************************************************************
	* Function:       SendToClientChangeStatus
	* Description:    匹配-->修改状态异步通知操作函数
	* Input:          SPVPMatchRpcChangeStatusNotify& Notify 修改状态服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientChangeStatus( INT64 UserId, SPVPMatchRpcChangeStatusNotify& Notify );



public:


};

//匹配类的枚举定义
enum ConstSPVPMatchE
{
	MODULE_ID_SPVPMATCH                          = 21,	//匹配模块ID
	RPC_CODE_SPVPMATCH_STARTMATCH_REQUEST        = 2151,	//匹配-->开始匹配-->请求
	RPC_CODE_SPVPMATCH_MATCHBROADCAS_NOTIFY      = 2152,	//匹配-->匹配通知-->通知
	RPC_CODE_SPVPMATCH_INVITATION_REQUEST        = 2153,	//匹配-->邀请-->请求
	RPC_CODE_SPVPMATCH_AGREEINVITATION_NOTIFY    = 2154,	//匹配-->同意邀请回应-->通知
	RPC_CODE_SPVPMATCH_STARTSELECT_NOTIFY        = 2155,	//匹配-->开始选择界面-->通知
	RPC_CODE_SPVPMATCH_SELECTHERO_REQUEST        = 2156,	//匹配-->选择英雄-->请求
	RPC_CODE_SPVPMATCH_STARTGAME_NOTIFY          = 2157,	//匹配-->开始游戏-->通知
	RPC_CODE_SPVPMATCH_DELETEMATCH_NOTIFY        = 2158,	//匹配-->取消匹配-->通知
	RPC_CODE_SPVPMATCH_GETSTATUS_REQUEST         = 2159,	//匹配-->获取状态-->请求
	RPC_CODE_SPVPMATCH_CHANGESTATUS_NOTIFY       = 2160,	//匹配-->修改状态-->通知


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<SPVPMatchRpcStartMatchAsk>{ enum{ID=RPC_CODE_SPVPMATCH_STARTMATCH_REQUEST};};
template<> struct MessageIdT<SPVPMatchRpcStartMatchReply>{ enum{ID=RPC_CODE_SPVPMATCH_STARTMATCH_REQUEST};};
template<> struct MessageIdT<SPVPMatchRpcMatchBroadcasNotify>{ enum{ID=RPC_CODE_SPVPMATCH_MATCHBROADCAS_NOTIFY};};
template<> struct MessageIdT<SPVPMatchRpcInvitationAsk>{ enum{ID=RPC_CODE_SPVPMATCH_INVITATION_REQUEST};};
template<> struct MessageIdT<SPVPMatchRpcInvitationReply>{ enum{ID=RPC_CODE_SPVPMATCH_INVITATION_REQUEST};};
template<> struct MessageIdT<SPVPMatchRpcAgreeInvitationNotify>{ enum{ID=RPC_CODE_SPVPMATCH_AGREEINVITATION_NOTIFY};};
template<> struct MessageIdT<SPVPMatchRpcStartSelectNotify>{ enum{ID=RPC_CODE_SPVPMATCH_STARTSELECT_NOTIFY};};
template<> struct MessageIdT<SPVPMatchRpcSelectHeroAsk>{ enum{ID=RPC_CODE_SPVPMATCH_SELECTHERO_REQUEST};};
template<> struct MessageIdT<SPVPMatchRpcSelectHeroReply>{ enum{ID=RPC_CODE_SPVPMATCH_SELECTHERO_REQUEST};};
template<> struct MessageIdT<SPVPMatchRpcStartGameNotify>{ enum{ID=RPC_CODE_SPVPMATCH_STARTGAME_NOTIFY};};
template<> struct MessageIdT<SPVPMatchRpcDeleteMatchNotify>{ enum{ID=RPC_CODE_SPVPMATCH_DELETEMATCH_NOTIFY};};
template<> struct MessageIdT<SPVPMatchRpcGetStatusAsk>{ enum{ID=RPC_CODE_SPVPMATCH_GETSTATUS_REQUEST};};
template<> struct MessageIdT<SPVPMatchRpcGetStatusReply>{ enum{ID=RPC_CODE_SPVPMATCH_GETSTATUS_REQUEST};};
template<> struct MessageIdT<SPVPMatchRpcChangeStatusNotify>{ enum{ID=RPC_CODE_SPVPMATCH_CHANGESTATUS_NOTIFY};};


#endif