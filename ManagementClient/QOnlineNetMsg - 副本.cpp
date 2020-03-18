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
	qRegisterMetaType<NET_CONNECT_STATUS>("NET_CONNECT_STATUS");//注册结构体
}

QOnlineNetMsg::~QOnlineNetMsg()
{
	FreeNetwork();
}

void _stdcall QOnlineNetMsg::OnClientConnectedToServer(void * userData, int cid, int userID)
{
	if (userData == (void *)m_pNetMachine1)
	{
		m_net_status.m_pNetMachine1[1] = true;
	}
	if (userData == (void *)m_pNetMachine2)
	{
		m_net_status.m_pNetMachine1[1] = true;
	}
	if (userData == (void *)m_pNetMachine3)
	{
		m_net_status.m_pNetMachine1[1] = true;
	}
	emit SendNetConnected(m_net_status);
}

void _stdcall QOnlineNetMsg::OnClientDisconnectedFromServer(void * userData, int cid, int userID)
{
	if (userData == (void *)m_pNetMachine1)
	{
		m_net_status.m_pNetMachine1[1] = false;
	}
	if (userData == (void *)m_pNetMachine2)
	{
		m_net_status.m_pNetMachine1[1] = false;
	}
	if (userData == (void *)m_pNetMachine3)
	{
		m_net_status.m_pNetMachine1[1] = false;
	}
	emit SendNetConnected(m_net_status);
}
/*void QOnlineNetMsg::OnClientRecieveServerMsgData(void * userData, int cid, int userID, NET_MSG_PACKET_HEAD * msg, BYTE * packetData)
{
			QString tempString;
			switch (msg->packet_type)
			{
			case NETPACKET_TYPE_TOVS_PENMA_IMAGE:
				if (g_pMsgQueue)
				{
					g_nJPEGsize[(g_nHaveReceive % RESULT_QUEUE_LENGTH)] = msg->dataLen - sizeof(NET_MSG_PACKET_REALPENMAPARA);
				}
				else//First time, alloc buffer
				{
					g_pMsgQueue = (PBYTE)GlobalAllocPtr(GPTR, MSG_IMG_DATA_SIZE * RESULT_QUEUE_LENGTH);
					g_nJPEGsize[(g_nHaveReceive % RESULT_QUEUE_LENGTH)] = msg->dataLen - sizeof(NET_MSG_PACKET_REALPENMAPARA);
				}
				memcpy(g_pMsgQueue + ((g_nHaveReceive % RESULT_QUEUE_LENGTH) * MSG_IMG_DATA_SIZE), (PBYTE)packetData, msg->dataLen);
				tempString = QString("MSG接收队列计数%1").arg(g_nHaveReceive);
				WriteRealLog(tempString, "RealProcess");
				SetEvent(g_hReadEvent);
				g_nHaveReceive++;
				break;
			default:
				break;
			}
		}
		if (userData == (void *)m_pNetToDoMain)
		{
			if (msg->type == NET_CMD_NOTIFY_HAOMA_BASIC)
			{
				NET_MSG_HAOMA_BASIC_INFO * pHaomaBasic = (NET_MSG_HAOMA_BASIC_INFO *)&msg->PacketReserved;

				NET_MSG_PACKET msg;
				msg.msgType = MSG_TYPE::_CARNUM_TYPE_;
				QTextCodec *tc = QTextCodec::codecForName("GBK");
				QString qstr;
				qstr = tc->toUnicode(pHaomaBasic->operator_name);
				msg.tbMCheng = qstr;//台班名称
				qstr = tc->toUnicode(pHaomaBasic->process_name);
				msg.jzMCheng = qstr;//台班名称
				msg.carNum = QString(pHaomaBasic->batch); //车号
				msg.finishFlag = pHaomaBasic->operator_id;
				//g_jzHao = m_dataOperate->QueryOperatorIDByOPeratorName();
				QString str = QString("当前车号：%1，收到车号：%2,标识位：%3").arg(g_carNum).arg(msg.carNum).arg(msg.finishFlag);
				WriteRevCarNumLog(str, "ChangeCarLog");
				ChangeCarNum(msg);

			}
			if (msg->type == NET_CMD_NOTIFY_SAMPLE_SHIMA)
			{
				NET_MSG_VS_SAMPLE_INFO* net_sample_info = (NET_MSG_VS_SAMPLE_INFO*)&msg->PacketReserved;
				g_net_sample[g_nsampleRecv%RESULT_QUEUE_LENGTH] = net_sample_info;
				g_nsampleRecv++;
			}
		}
}*/

void QOnlineNetMsg::OnServerStationConnected(void * userData, int stationID)
{
	if (userData == m_pNetServer)
	{
		switch (stationID)
		{
		case NET_CONNECT_MACHINE_CODE::MACHINE1_CODE:
			m_net_status.m_pNetMachine1[0] = true;
			m_nStationID[0] = stationID;
			break;
		case NET_CONNECT_MACHINE_CODE::MACHINE2_CODE:
			m_net_status.m_pNetMachine2[0] = true;
			m_nStationID[1] = stationID;
			break;
		case NET_CONNECT_MACHINE_CODE::MACHINE3_CODE:
			m_net_status.m_pNetMachine3[0] = true;
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
			m_net_status.m_pNetMachine1[0] = false;
			break;
		case NET_CONNECT_MACHINE_CODE::MACHINE2_CODE:
			m_net_status.m_pNetMachine2[0] = false;
			break;
		case NET_CONNECT_MACHINE_CODE::MACHINE3_CODE:
			m_net_status.m_pNetMachine3[0] = false;
			break;
		default:
			break;
		}
		emit SendNetConnected(m_net_status);
	}
}

void QOnlineNetMsg::OnServerRecvStationMsgData(void * userData, int stationID, NET_MSG_PACKET_HEAD * msg, BYTE * packetData)
{
	if (userData == (void *)m_pNetServer)
	{
		switch (msg->packet_type)
		{
		case NETPACKET_TYPE_TOVS_MACHINE1:
			break;
		case NETPACKET_TYPE_TOVS_MACHINE2:
			break;
		case NETPACKET_TYPE_TOVS_MACHINE3:
			break;
		default:
			break;
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
	NET_MSG_CLIENT_CFG clientCfg;

	clientCfg.stationID = 250;
	clientCfg.connectTimeout = 1000;
	clientCfg.heartBeatTime = 1000;
	clientCfg.recvTimeout = 200000000;
	clientCfg.reconnectDelay = 2000;

	m_pNetMachine1 = CreateNetMsg();
	m_pNetMachine1->InitNetwork(&clientCfg, 0, this, m_pNetMachine1);
	m_nMachine1 = m_pNetMachine1->OpenConnection((LPCTSTR)"192.168.250.101", 5101, 0);
	m_pNetMachine2 = CreateNetMsg();
	m_pNetMachine2->InitNetwork(&clientCfg, 0, this, m_pNetMachine2);
	m_nMachine2 = m_pNetMachine1->OpenConnection((LPCTSTR)"192.168.250.102", 5102, 0);
	m_pNetMachine3 = CreateNetMsg();
	m_pNetMachine3->InitNetwork(&clientCfg, 0, this, m_pNetMachine3);
	m_nMachine3 = m_pNetMachine3->OpenConnection((LPCTSTR)"192.168.250.103", 5103, 0);
	//	m_connect1 = m_pNetMachine1->OpenConnection((LPCTSTR)g_imgIp.toStdString().c_str(), g_imgPort, 0);

}


void QOnlineNetMsg::FreeNetwork()
{
	if (m_pNetServer)
	{
		m_pNetServer->FreeNetwork();
		Sleep(1000);
		m_pNetServer->Release();
	}
	if (m_pNetMachine1)
	{
		m_pNetMachine1->FreeNetwork();
		Sleep(1000);
		m_pNetMachine1->Release();
	}
	if (m_pNetMachine2)
	{
		m_pNetMachine2->FreeNetwork();
		Sleep(1000);
		m_pNetMachine2->Release();
	}
	if (m_pNetMachine3)
	{
		m_pNetMachine3->FreeNetwork();
		Sleep(1000);
		m_pNetMachine3->Release();
	}
}

bool QOnlineNetMsg::SendMsgToMachine(int nSerial, int nMachineID)
{
	int index = -1;
	NET_MSG_PACKET_HEAD sendMsg;
	sendMsg.type = 8;
	sendMsg.dataLen = 0;
	sendMsg.timestamp = (int)GetCurTimeMS();
	sendMsg.packet_comtype = 3;
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
	NET_MSG_VS_SAMPLE_INFO *pInfoToPm = (NET_MSG_VS_SAMPLE_INFO *)&sendMsg.PacketReserved;
	pInfoToPm->nSerial = nSerial;
	m_pNetServer->SendMsgToClient(m_nStationID[index], &sendMsg, NULL, 0);
	return true;
}
