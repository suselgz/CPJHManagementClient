#pragma once

#include <QObject>
#include "Netcmd.h"

class QOnlineNetMsg : public QObject, public CNetMsgHook
{
	Q_OBJECT

public:
	QOnlineNetMsg();
	~QOnlineNetMsg();

protected:
	void _stdcall OnClientConnectingToServer(void * userData, int cid, int userID){ ; }
	void _stdcall OnClientConnectedToServer(void * userData, int cid, int userID) { ; }
	void _stdcall OnClientConnectToServerTimeout(void * userData, int cid, int userID){; }
	void _stdcall OnClientDisconnectedFromServer(void * userData, int cid, int userID) { ; }
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
	bool SendMsgToMachine(NET_MSG_MODIFY_INFO *send_info,int nMachineID);
signals:
	void SendNetConnected(NET_CONNECT_STATUS);
	void SendRevNumToPm(CLIENT_INFO,int);
private:
	NET_CONNECT_STATUS m_net_status;
	
	CNetMsg * m_pNetServer;  
	int m_nStationID[3];
};
