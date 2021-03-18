/********************************************************************************************
* Copyright (C), 2011-2035, AGAN Tech. Co., Ltd.
* FileName:     ModuleTeam.h
* Author:       甘业清
* Description:  组队类，包含以下内容
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

#ifndef __MODULE_TEAM_H
#define __MODULE_TEAM_H


#include "ModuleBase.h"
#include "RpcCenter.h"
#include "MsgIdMgr.h"
#include "TeamSvrRpc.pb.h"
#include "TeamCliRpc.pb.h"



//组队实现类
class ModuleTeam : public ModuleBase
{
	DECLARE_INSTANCE(ModuleTeam);
public:
	friend class			ModuleMgr;

public:
	//组队实现类构造函数
	ModuleTeam();
	
	//组队实现类析构函数
	virtual					~ModuleTeam();

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
	* Function:       CliRpcPullTeammate
	* Description:    组队-->拉队友同步调用操作函数
	* Input:          TeamRpcPullTeammateAsk& Ask 拉队友请求
	* Output:         TeamRpcPullTeammateReply& Reply 拉队友回应
	********************************************************************************************/
	void CliRpcPullTeammate( clientInfoT& clientInfo, TeamRpcPullTeammateAsk& Ask, TeamRpcPullTeammateReply& Reply );

	/********************************************************************************************
	* Function:       CliRpcAddTeamNoify
	* Description:    组队-->拉队友收到的消息异步通知操作函数
	* Input:          TeamRpcAddTeamNoifyNotify& Notify 拉队友收到的消息双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcAddTeamNoify( clientInfoT& clientInfo, TeamRpcAddTeamNoifyNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientAddTeamNoify
	* Description:    组队-->拉队友收到的消息异步通知操作函数
	* Input:          TeamRpcAddTeamNoifyNotify& Notify 拉队友收到的消息双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientAddTeamNoify( INT64 UserId, TeamRpcAddTeamNoifyNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcGetTeam
	* Description:    组队-->获取team消息异步通知操作函数
	* Input:          TeamRpcGetTeamNotify& Notify 获取team消息双向通知
	* Output:         无
	********************************************************************************************/
	void CliRpcGetTeam( clientInfoT& clientInfo, TeamRpcGetTeamNotify& Notify );

	/********************************************************************************************
	* Function:       SendToClientGetTeam
	* Description:    组队-->获取team消息异步通知操作函数
	* Input:          TeamRpcGetTeamNotify& Notify 获取team消息双向通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	void SendToClientGetTeam( INT64 UserId, TeamRpcGetTeamNotify& Notify );

	/********************************************************************************************
	* Function:       CliRpcCtrlTeam
	* Description:    组队-->操作队伍同步调用操作函数
	* Input:          TeamRpcCtrlTeamAsk& Ask 操作队伍请求
	* Output:         TeamRpcCtrlTeamReply& Reply 操作队伍回应
	********************************************************************************************/
	void CliRpcCtrlTeam( clientInfoT& clientInfo, TeamRpcCtrlTeamAsk& Ask, TeamRpcCtrlTeamReply& Reply );

	/********************************************************************************************
	* Function:       CliRpcFindTeam
	* Description:    组队-->寻找队伍同步调用操作函数
	* Input:          TeamRpcFindTeamAsk& Ask 寻找队伍请求
	* Output:         TeamRpcFindTeamReply& Reply 寻找队伍回应
	********************************************************************************************/
	void CliRpcFindTeam( clientInfoT& clientInfo, TeamRpcFindTeamAsk& Ask, TeamRpcFindTeamReply& Reply );



public:
	//获取队伍函数实现
	void SvrRpcGetTeam( int nodeId, TeamRpcGetTeamAsk& ask, TeamRpcGetTeamReply& reply);
	//组队成功函数实现
	void SvrRpcTeamOver( int nodeId, TeamRpcTeamOverAsk& ask, TeamRpcTeamOverReply& reply);


};

//组队类的枚举定义
enum ConstTeamE
{
	MODULE_ID_TEAM                               = 28,	//组队模块ID
	RPC_CODE_TEAM_PULLTEAMMATE_REQUEST           = 2851,	//组队-->拉队友-->请求
	RPC_CODE_TEAM_ADDTEAMNOIFY_NOTIFY            = 2852,	//组队-->拉队友收到的消息-->通知
	RPC_CODE_TEAM_GETTEAM_NOTIFY                 = 2853,	//组队-->获取team消息-->通知
	RPC_CODE_TEAM_CTRLTEAM_REQUEST               = 2854,	//组队-->操作队伍-->请求
	RPC_CODE_TEAM_FINDTEAM_REQUEST               = 2855,	//组队-->寻找队伍-->请求


};

template<typename T> struct MessageIdT;
template<> struct MessageIdT<TeamRpcPullTeammateAsk>{ enum{ID=RPC_CODE_TEAM_PULLTEAMMATE_REQUEST};};
template<> struct MessageIdT<TeamRpcPullTeammateReply>{ enum{ID=RPC_CODE_TEAM_PULLTEAMMATE_REQUEST};};
template<> struct MessageIdT<TeamRpcAddTeamNoifyNotify>{ enum{ID=RPC_CODE_TEAM_ADDTEAMNOIFY_NOTIFY};};
template<> struct MessageIdT<TeamRpcGetTeamNotify>{ enum{ID=RPC_CODE_TEAM_GETTEAM_NOTIFY};};
template<> struct MessageIdT<TeamRpcCtrlTeamAsk>{ enum{ID=RPC_CODE_TEAM_CTRLTEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcCtrlTeamReply>{ enum{ID=RPC_CODE_TEAM_CTRLTEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcFindTeamAsk>{ enum{ID=RPC_CODE_TEAM_FINDTEAM_REQUEST};};
template<> struct MessageIdT<TeamRpcFindTeamReply>{ enum{ID=RPC_CODE_TEAM_FINDTEAM_REQUEST};};


#endif