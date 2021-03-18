/********************************************************************************************
* Copyright (C), 2011-2025.
* FileName:     $Template$Proxy.h
* Author:       甘业清
* Date:         $Date$
* Description:  $ModCName$ RPC 代理类
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/


#include "$Template$Proxy.h"

struct $Template$RegisterProxyT
{
    $Template$RegisterProxyT()
    {
        RpcCenter::Instance().RegisterRpcProxy("$Template$");
    }
};
static $Template$RegisterProxyT $Template$RegisterProxyInstance;

$CarpProxyCall$

$RandProxyCall$

$RoundProxyCall$

$AppointProxyCall$

$ConsistencyProxyCall$

