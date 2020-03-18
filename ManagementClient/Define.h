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

#define NETPACKET_TYPE_TOVS_MACHINE1		        0x1B		//机器1发送数据
#define NETPACKET_TYPE_TOVS_MACHINE2		        0x1C		//机器2发送数据
#define NETPACKET_TYPE_TOVS_MACHINE3		        0x1D		//机器3发送数据

struct NET_MSG_MODIFY_INFO
{
	INT64	nSerial;
	int     dataLen;
	int     imgWidth;
	int     imgHeight;
	int     imgPitch;
	int     machineID;
	char	machine_name[10];
	char	operator_name[10];	
	char	product_type[10];
	int     nCheckNum;
	int     checkResultType;
	int     modifyResult;  /*0未处理，1已处理*/
	int     deleteInfoType;
	BYTE*   packetDataBuf;
	BYTE	reserved[256 - sizeof(int) * 2 - sizeof(INT64)];
	BOOL operator != (const NET_MSG_MODIFY_INFO & cfg)
	{
		if (nSerial != cfg.nSerial)		return TRUE;
		if (dataLen != cfg.dataLen)		return TRUE;
		if (imgWidth != cfg.imgWidth)   return TRUE;
		if (imgHeight != cfg.imgHeight)   return TRUE;
		if (imgPitch != cfg.imgPitch)   return TRUE;
		if (machineID != cfg.machineID)   return TRUE;
		if (nCheckNum != cfg.nCheckNum)   return TRUE;
		if (checkResultType != cfg.checkResultType)   return TRUE;
		if (modifyResult != cfg.modifyResult)   return TRUE;
		return FALSE;
	}
};
/*0 is Server status,1 is Client status*/
struct NET_CONNECT_STATUS
{
	bool m_pNetMachine1;
	bool m_pNetMachine2;
	bool m_pNetMachine3;
};
enum NET_CONNECT_MACHINE_CODE
{
	MACHINE1_CODE = 101,
	MACHINE2_CODE = 102,
	MACHINE3_CODE = 103
};
enum NET_MODIFY_FLAG
{
	MODIFY_NO = 0,
	MODIFY_OK = 1
};