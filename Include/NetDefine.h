#pragma once
#include "NetMsg.h"

// Network����
#define NET_MSG_DIR_CS_TO_CLIENT					0		
#define NET_MSG_DIR_CLIENT_TO_CS					1
#define NET_MSG_DIR_VS_TO_CLIENT					2
#define NET_MSG_DIR_CLIENT_TO_VS					3
#define NET_MSG_DIR_CS_TO_VS						4
#define NET_MSG_DIR_VS_TO_CS						5
#define NET_MSG_DIR_CLIENT_TO_CLIENT				6

// COMMAND
#define NET_CMD_NOTIFY_WHITEBALANCE_START			1			// ��ʼ��ƽ��
#define NET_CMD_NOTIFY_WHITEBALANCE_STOP			2			// ֹͣ��ƽ��
#define NET_CMD_NOTIFY_GRAB_START					3			// ��ʼ�ɼ�
#define NET_CMD_NOTIFY_GRAB_STOP					4			// ֹͣ�ɼ�
#define NET_CMD_NOTIFY_WHITEBALANCE_CC2				5			// ѧϰ��ƽ��CC 2����
#define NET_CMD_NOTIFY_WHITEBALANCE_GETIMAGE		6			// �����վ����һ֡��ƽ��ͼ��
#define NET_CMD_NOTIFY_GETONEIMAGE					7			// �����վ����һ֡ʵʱȫ����ͼ��
#define NET_CMD_NOTIFY_ENABLEAUTOSAVE				8			// �����վ��ʼ����ͼ��
#define NET_CMD_NOTIFY_DISABLEAUTOSAVE				9			// �����վֹͣ����ͼ��
#define NET_CMD_NOTIFY_STARTRECREATETEMPLATE		10			// ��ʼ�ؽ�ģ��	
#define NET_CMD_NOTIFY_STOPRECREATETEMPLATE			11			// ֹͣ�ؽ�ģ��
#define NET_CMD_NOTIFY_STARTFREERUN					12			// ��ʼ��������ģʽ
#define NET_CMD_NOTIFY_STOPFREERUN					13			// ֹͣ��������ģʽ
#define NET_CMD_NOTIFY_APPLICATIONEXIT				14			// �����˳�
#define NET_CMD_NOTIFY_UNIQUESN						38			// Ψһ���к�
#define NET_CMD_NOTIFY_HAOMA_BASIC					39			// ������Ϣ
#define NET_CMD_NOTIFY_HAOMA_CFG_CHANGED			40			// ���ͺ����������վ
#define NET_CMD_NOTIFY_MACHINE_SIGNAL				41			// ���ͺ�ѹ��λ�źŵ���վ
#define NET_CMD_NOTIFY_YG_CFG_CHANGED				42			// ӫ�����
#define NET_CMD_NOTIFY_SAVE_CLEAR_IMG				50			//��������ͼ��

// ��վ���͵���ʾվ
#define NETPACKET_TYPE_TOVS_ERROR_INFO				0x10		// ���վ���͵Ĵ����¼������С��ͼ��
#define NETPACKET_TYPE_TOVS_RUNTIME_IMAGE			0x11		// ���վ���͵�ʵʱͼ���ļ���С�ڰ�ͷ�ڶ���
#define NETPACKET_TYPE_FROMVS_AQUIREIMAGE			0x12		// �����վ��ͼ�񣬴�����ʵʱͼ�����������
#define NETPACKET_TYPE_FROMVS_STOPSNATCHREALIMAGE	0x13		// ֹͣ��վ����ͼ�񣬴�����ʵʱͼ�����������
#define NETPACKET_TYPE_TOVS_REALERRORIMAGE			0x14		// ��վ����ʵʱ����ͼ��
#define NETPACKET_TYPE_FROMVS_AQUIREERRORIMAGE		0x15		// �����վ���ʹ���ͼ��
#define NETPACKET_TYPE_TOVS_RMBCODE_IMG				0x16		// ���վ���͵�ͼ��
#define NETPACKET_TYPE_VS_AQUIRECURRENTERRORIMAGE	0x1A		// ����ָ������վ��������һ�Ŵ���ͼ��
//zy add
#define NETPACKET_TYPE_TOVS_STAT_INFO				0x1B		//����ͳ����Ϣ

//end

// ��վ���͵�����վ
#define NETPACKET_TYPE_TOCS_NOTE_ERRORRECORD		0x30		// ���վ���͵�������ս��С�������¼
#define NETPACKET_TYPE_TOCS_SHEET_ERRORRECORD		0x31		// ���վ���͵�������ս�Ĵ��ŵ�·�����¼
#define NETPACKET_TYPE_TOCS_NOTE_NOCHECKED			0x32		// С��δ��
#define NETPACKET_TYPE_TOCS_SHEET_NOCHECKED			0x33		// ����δ��
#define NETPACKET_TYPE_TOCS_REMIND_WHITEBALANCE		0x34		// ֪ͨ������վӦ������ƽ��


struct NET_MSG_CHEHAO_INFO
{
	char strClass[20];
	char strCaptaion[20];
	char strCheHao[20];
	char strIntaglio[20];
	char strOffset[20];
	char strIntaglioAux[20];
	char strOffsetAux[20];
};

struct NET_MSG_HOST_TO_CLIENT
{
	DWORD dwPackageSize;
	DWORD dwNotifyType;
	DWORD dwStationIDFrom;
	DWORD dwCommand;
};

struct NETWORK_CONFIG_SETS
{
	int nConnectTimeout;
	int nRecvTimeout;
	int nHeartBeatTime;
	int nReconnectDelayTime;
	int nHostProvideServerPort;
	int nLocalStationID;
	int nLocalProvideServerPort;
};

struct NET_IMAGE_PACKET_HEAD
{
	DWORD dwPacketSize;
	DWORD dwStationIDFrom;
	DWORD dwImageWidth;
	DWORD dwImageHeight;
	DWORD dwImagePitch;
};

struct NET_MSG_PACKET_AQUIREIMAGEDEFINE
{
	BOOL bIsRealImage, bIsTimeInterval;
	int nTimeInterval, nSheetInterval;
	int bErrorImage;
	int left, top, right, bottom;
	int wLeft, wTop, wRight, wBottom;
};
