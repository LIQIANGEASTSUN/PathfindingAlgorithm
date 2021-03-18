/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcPropertyImp.cpp
* Author:       甘业清
* Description:  用户属性类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ModuleProperty.h"
#include "UserMgr.h"


/********************************************************************************************
* Function:       CliRpcSync
* Description:    用户属性-->同步同步调用操作函数
* Input:          PropertyRpcSyncAsk& Ask 同步请求
* Output:         PropertyRpcSyncReply& Reply 同步回应
********************************************************************************************/
void ModuleProperty::CliRpcSync( clientInfoT& clientInfo, PropertyRpcSyncAsk& Ask, PropertyRpcSyncReply& Reply )
{

	//逻辑代码


	//设置返回结果
	Reply.set_result(1300);
}



