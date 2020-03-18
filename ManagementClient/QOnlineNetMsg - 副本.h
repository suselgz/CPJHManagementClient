#pragma once

#include <QObject>
#include "NetCmd.h"

#define NETPACKET_TYPE_TOVS_MACHINE1		        0x1B		//机器1发送数据
#define NETPACKET_TYPE_TOVS_MACHINE2		        0x1C		//机器1发送数据
#define NETPACKET_TYPE_TOVS_MACHINE3		        0x1D		//机器1发送数据

/*0 is Server status,1 is Client status*/
struct NET_CONNECT_STATUS
{
	bool m_pNetMachine1[2];
	bool m_pNetMachine2[2];
	bool m_pNetMachine3[2];
};
enum NET_CONNECT_MACHINE_CODE
{
	MACHINE1_CODE= 101, 
	MACHINE2_CODE= 102,
	MACHINE3_CODE = 103
};

class QOnlineNetMsg : public QObject, public CNetMsgHook
{
	Q_OBJECT

public:
	QOnlineNetMsg();
	~QOnlineNetMsg();

protected:
	void _stdcall OnClientConnectingToServer(void * userData, int cid, int userID){ ; }
	void _stdcall OnClientConnectedToServer(void * userData, int cid, int userID);
	void _stdcall OnClientConnectToServerTimeout(void * userData, int cid, int userID){; }
	void _stdcall OnClientDisconnectedFromServer(void * userData, int cid, int userID);
	void * _stdcall OnGetClientRecieveServerMsgDataBuf(void * userData, int cid, int userID, NET_MSG_PACKET_HEAD * msg){return 0; }
	void _stdcall OnClientRecieveServerMsgData(void * userData, int cid, int userID, NET_MSG_PACKET_HEAD * msg, BYTE * packetData) { ; }
	void _stdcall OnClientServerReplyMsgTimeout(void * userData, int cid, int userID){; }
	void _stdcall OnServerClientConnected(void * userData){; }
	void _stdcall OnServerStationConnected(void * userData, int stationID); 
	void _stdcall OnServerStationDisconnected(void * userData, int stationID); 
	void * _stdcall OnGetServerRecieveStationMsgDataBuf(void * userData, int stationID, NET_MSG_PACKET_HEAD * msg){return 0; }
	void _stdcall OnServerRecvStationMsgData(void * userData, int stationID, NET_MSG_PACKET_HEAD * msg, BYTE * packetData);
	void _stdcall OnServerClientTimeout(void * userData, int stationID){; }

public:
	void InitSNetwork();
	void InitCNetwork();
	void FreeNetwork();
	bool SendMsgToMachine(int nSerial,int nMachineID);
signals:
	void SendNetConnected(NET_CONNECT_STATUS);
private:
	NET_CONNECT_STATUS m_net_status;
	
	CNetMsg * m_pNetServer;  
	CNetMsg * m_pNetMachine1;
	CNetMsg * m_pNetMachine2;
	CNetMsg * m_pNetMachine3;
	int m_nStationID[3];
	int m_nMachine1;
	int m_nMachine2;
	int m_nMachine3;

};
