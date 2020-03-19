#include "stdafx.h"
#include "ImgLib.h"
#include "QOnlineNetMsg.h"
#include "MvImage.h"

typedef CNetMsg * _stdcall CreateCNetMsgInstanceFun(int version);
static HMODULE hNetDLL;
static CreateCNetMsgInstanceFun * fCreateNet;
#pragma execution_character_set("utf-8")
//创建CNetMsg实例
CNetMsg * CreateNetMsg()
{
	if (fCreateNet == 0)
	{
#ifdef _DEBUG
		hNetDLL = LoadLibrary(TEXT("NetMsg_rd.dll"));
#else
		hNetDLL = LoadLibrary(TEXT("NetMsg_rd.dll"));
#endif
		fCreateNet = (CreateCNetMsgInstanceFun *)GetProcAddress(hNetDLL, (LPCSTR)1);
	}
	if (fCreateNet)
	{
		return fCreateNet(NET_MSG_VERSION);
	}
	return 0;
}

typedef CNetMsg * _stdcall CreateCNetMsgInstanceFunWithNum(int version, int num);
static HMODULE hNetDLLWithNum;
static CreateCNetMsgInstanceFunWithNum * fCreateNetWithNum;
//创建CNetMsg实例

static LPCTSTR netStatusTxtTab[] = { TEXT("断开"), TEXT("连接") };

QOnlineNetMsg::QOnlineNetMsg()
{
	memset(&m_net_status, 0, sizeof(NET_CONNECT_STATUS));
	qRegisterMetaType<NET_CONNECT_STATUS>("NET_CONNECT_STATUS");
}

QOnlineNetMsg::~QOnlineNetMsg()
{
	FreeNetwork();
}

void QOnlineNetMsg::OnServerStationConnected(void * userData, int stationID)
{
	if (userData == m_pNetServer)
	{
		switch (stationID)
		{
		case NET_CONNECT_MACHINE_CODE::MACHINE1_CODE:
			m_net_status.m_pNetMachine1 = true;
			m_nStationID[0] = stationID;
			break;
		case NET_CONNECT_MACHINE_CODE::MACHINE2_CODE:
			m_net_status.m_pNetMachine2 = true;
			m_nStationID[1] = stationID;
			break;
		case NET_CONNECT_MACHINE_CODE::MACHINE3_CODE:
			m_net_status.m_pNetMachine3 = true;
			m_nStationID[2] = stationID;
			break;
		default:
			break;
		}
		emit SendNetConnected(m_net_status);
	}
}

void QOnlineNetMsg::OnServerStationDisconnected(void * userData, int stationID)
{
	if (userData == m_pNetServer)
	{
		switch (stationID)
		{
		case NET_CONNECT_MACHINE_CODE::MACHINE1_CODE:
			m_net_status.m_pNetMachine1 = false;
			break;
		case NET_CONNECT_MACHINE_CODE::MACHINE2_CODE:
			m_net_status.m_pNetMachine2 = false;
			break;
		case NET_CONNECT_MACHINE_CODE::MACHINE3_CODE:
			m_net_status.m_pNetMachine3 = false;
			break;
		default:
			break;
		}
		emit SendNetConnected(m_net_status);
	}
}

void QOnlineNetMsg::OnServerRecvStationMsgData(void * userData, int stationID, NET_MSG_PACKET_HEAD * msg, BYTE * packetData)
{
	NET_MSG_MODIFY_INFO * pModifyInfo;
	int index = -1;
	int machineCode = 0;
	if (userData == (void *)m_pNetServer)
	{
		switch (msg->packet_type)
		{
		case NETPACKET_TYPE_TOVS_MACHINE1:
			index = 0;
			machineCode = NET_CONNECT_MACHINE_CODE::MACHINE1_CODE;
			break;
		case NETPACKET_TYPE_TOVS_MACHINE2:
			index = 1;
			machineCode = NET_CONNECT_MACHINE_CODE::MACHINE2_CODE;
			break;
		case NETPACKET_TYPE_TOVS_MACHINE3:
			index = 2;
			machineCode = NET_CONNECT_MACHINE_CODE::MACHINE3_CODE;
			break;
		default:
			break;
		}
		if (index < 0)
		{
			return;
		}
		pModifyInfo = (NET_MSG_MODIFY_INFO *)&msg->PacketReserved;
		if (pModifyInfo->modifyResult == NET_MODIFY_FLAG::MODIFY_NO)
		{
			memcpy(pModifyInfo->packetDataBuf, packetData, pModifyInfo->dataLen);
			GlobalParam::netMsg[index].push_back(pModifyInfo);
			GlobalParam::clintInfo[index].nTotalRecive++;
			GlobalParam::clintInfo[index].nTotalRetrieve++;
			SendRevNumToPm(GlobalParam::clintInfo[index], machineCode);
		}
		else if (pModifyInfo->modifyResult == NET_MODIFY_FLAG::MODIFY_OK)
		{
			GlobalParam::clintInfo[index].nTotalRetrieve--;
			for (vector<NET_MSG_MODIFY_INFO*>::iterator iter = GlobalParam::netMsg[index].begin(); iter != GlobalParam::netMsg[index].end(); ++iter)
			{
				NET_MSG_MODIFY_INFO* info = *iter;
				if (info->nSerial == pModifyInfo->nSerial)
				{
					iter = GlobalParam::netMsg[index].erase(iter);
				}
			}
			SendRevNumToPm(GlobalParam::clintInfo[index], machineCode);
		}
	}
}

void QOnlineNetMsg::InitSNetwork()
{
	m_pNetServer = CreateNetMsg();
	if (m_pNetServer == NULL)
		return;
	NET_MSG_SERVER_CFG serverCfg;
	serverCfg.stationID = 100;
	serverCfg.bindPort = 5000;
	serverCfg.recvTimeout = 200000000;
	m_pNetServer->InitNetwork(NULL, &serverCfg, this, m_pNetServer);
}

void QOnlineNetMsg::InitCNetwork()
{
	/*	NET_MSG_CLIENT_CFG clientCfg;
		clientCfg.stationID = 250;
		clientCfg.connectTimeout = 1000;
		clientCfg.heartBeatTime = 1000;
		clientCfg.recvTimeout = 200000000;
		clientCfg.reconnectDelay = 2000;
		m_pNetMachine1 = CreateNetMsg();
		m_pNetMachine1->InitNetwork(&clientCfg, 0, this, m_pNetMachine1);
		m_nMachine1 = m_pNetMachine1->OpenConnection((LPCTSTR)"192.168.250.101", 5101, 0);
		//	m_connect1 = m_pNetMachine1->OpenConnection((LPCTSTR)g_imgIp.toStdString().c_str(), g_imgPort, 0);
		*/
}


void QOnlineNetMsg::FreeNetwork()
{
	if (m_pNetServer)
	{
		m_pNetServer->FreeNetwork();
		Sleep(1000);
		m_pNetServer->Release();
	}
}

bool QOnlineNetMsg::SendMsgToMachine(int nSerial, int nMachineID)
{
	int index = -1;
	NET_MSG_PACKET_HEAD sendMsg;
	switch (nMachineID)
	{
	case NET_CONNECT_MACHINE_CODE::MACHINE1_CODE:
		sendMsg.stationID = NET_CONNECT_MACHINE_CODE::MACHINE1_CODE;
		sendMsg.packet_type = NETPACKET_TYPE_TOVS_MACHINE1;
		index = 0;
		break;
	case NET_CONNECT_MACHINE_CODE::MACHINE2_CODE:
		sendMsg.stationID = NET_CONNECT_MACHINE_CODE::MACHINE2_CODE;
		sendMsg.packet_type = NETPACKET_TYPE_TOVS_MACHINE2;
		index = 1;
		break;
	case NET_CONNECT_MACHINE_CODE::MACHINE3_CODE:
		sendMsg.stationID = NET_CONNECT_MACHINE_CODE::MACHINE3_CODE;
		sendMsg.packet_type = NETPACKET_TYPE_TOVS_MACHINE3;
		index = 2;
		break;
	default:
		break;
	}
	NET_MSG_MODIFY_INFO *pInfoToPm = (NET_MSG_MODIFY_INFO *)&sendMsg.PacketReserved;
	pInfoToPm->nSerial = nSerial;
	pInfoToPm->modifyResult = NET_MODIFY_FLAG::MODIFY_OK;
	m_pNetServer->SendMsgToClient(m_nStationID[index], &sendMsg, NULL, 0);
	return true;
}
