#pragma once
#include "stdafx.h"

#define CLIENT_NUM_INFO 3   //一个管理端配3台客户端
#define MAX_SIZE 1024
typedef struct BASIC_SETTING_TAG
{
	QString groupString;
}BASIC_SETTING;
typedef struct DB_SETTING_TAG
{
	QString dbIp;
	QString dbName;
	QString userName;
	QString userPwd;
	QString serverPort;
}DB_SETTING;
typedef struct CLIENT_INFO_TAG
{
	int nMachineId;
	QString machineName;
	int nOperatorId;
	QString operatorName;
	int nTotalRecive;
	int nTotalRetrieve;
}CLIENT_INFO;

