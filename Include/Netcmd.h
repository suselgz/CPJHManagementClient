#pragma  once
#include "NetMsg.h"
#define IMAGE_STATION_K_COUNTS 24
#define SHEET_K_X_COUNTS 5
//���紫�ʹ���ͼ���С����Ŀ
#define ERROR_IMAGE_WIDTH 180
#define ERROR_IMAGE_HEIGHT 120
#define ERROR_IMAGE_SIZE (ERROR_IMAGE_WIDTH * ERROR_IMAGE_HEIGHT * 3)
#define ERROR_IMAGE_MONO_SIZE (ERROR_IMAGE_WIDTH * ERROR_IMAGE_HEIGHT)
#define MAX_ERROR_IMAGE_COUNT 50
#define NETPACKET_TYPE_TOVS_PENMA_IMAGE					0x16		//��վ��������ͼ��
//ȱ����Ϣ���紫�ͻ����С
#define NET_SEND_BUFFER_SIZE 20
#define SHIMA 251
//����������С���ɼ�������ţ�����֮ǰ���͵�һ�ŵĽ��
#define MACHINE_SEND_BUFFER_SIZE 2

//����������������������
#define NET_CONTINUE_ERROR_SHEET_COUNT 2
#define NET_CONTINUE_ERROR_K_COUNT 2


#define DN_COUNT                        16
#define MSG_IMG_DATA_SIZE 1024*1024
#define NET_CMD_NOTIFY_HAOMA_BASIC				39

enum STATION_TYPE_CONST
{
	STATION_TYPE_SLAVE_FIRST,
	STATION_TYPE_SLAVE_SECOND,
	STATION_TYPE_SLAVE_THIRD,
	STATION_TYPE_COUNT,
};

enum NET_PACKET_MSG_TYPE_CONST
{
	NET_PACKET_MSG_TYPE_CHECK_RESULT = 1,
	NET_PACKET_MSG_TYPE_CHECK_RESULT_REPLY,
	NET_PACKET_MSG_TYPE_CHECK_RESULT_DETAIL, //������ϸ�����Ϣ
	NET_PACKET_MSG_TYPE_ERROR_IMAGE,         //�������ͼ��
	NET_PACKET_MSG_TYPE_START_DET,           //��ʼ���
	NET_PACKET_MSG_TYPE_STOP_DET,            //ֹͣ���
	NET_PACKET_MSG_TYPE_START_SEND,          //��ʼ����
	NET_PACKET_MSG_TYPE_STOP_SEND,           //ֹͣ����
	NET_PACKET_MSG_TYPE_BUILD_LAB_MODEL,     //�ؽ�LABģ��
	NET_PACKET_MSG_TYPE_RELEARN_LAB_MODEL,   //��ѧLABģ��
	NET_PACKET_MSG_TYPE_SHUTDOWN,            //�ػ�
	NET_PACKET_MSG_TYPE_SAVE_TEMPLATE,       //����ģ��ͼ��
	NET_PACKET_MSG_TYPE_SHEET_START_INFO,    //��վ������ʼ������Ϣ
	NET_PACKET_MSG_TYPE_SHEET_NUMBER_RECOG_RESULT, //����ʶ����
	NET_PACKET_MSG_TYPE_TEMPLATE_STAT,       //��ǰģ��״̬
	NET_PACKET_MSG_TYPE_COUNT,
};

//#pragma pack(push , 6)
// �ſ���վ���͵ĳ��š�������Ϣ��
struct NET_MSG_HAOMA_BASIC_INFO
{
	int		operator_id;		// ����ID   0:δ���,1:�����
	int		machine_id;			// ��̨��ID
	int		process_id;			// ����ID
	int		type_index;			// Ʒ�ִ���
	int		workunit_index;		// ̨��ID
	char	batch[10];			// ����
//	char	headGroup[12];
	char	headGroup[8];
	char	smallCode[4];		// �ں�		ע�⣺��λ���1K��Ż���40K��ţ����ݹں�¼�뷽ʽ�����б�
	char	workunit_name[10];	// ̨��
	char	operator_name[10];	// ��������
	char	process_name[10];	// ��������
	char	product_type[10];	// ��ƷƷ��
	char	machine_name[20];	// ��̨����
	char	produce_time[30];
	char	szSecondNum[6];
	BYTE	reserved[256 - sizeof(int)* 5 - sizeof(char)* 112];
	BOOL operator != (const NET_MSG_HAOMA_BASIC_INFO & info)
	{
		if (operator_id != info.operator_id)		return TRUE;
		if (machine_id != info.machine_id)			return TRUE;
		if (process_id != info.process_id)			return TRUE;
		if (type_index != info.type_index)			return TRUE;
		if (workunit_index != info.workunit_index)	return TRUE;
		if (0 != strcmp(batch, info.batch))			return TRUE;
		if (0 != strcmp(headGroup, info.headGroup))	return TRUE;
		if (0 != strcmp(smallCode, info.smallCode))	return TRUE;
		if (0 != strcmp(workunit_name, info.workunit_name))	return TRUE;
		if (0 != strcmp(operator_name, info.operator_name))	return TRUE;
		if (0 != strcmp(process_name, info.process_name))	return TRUE;
		if (0 != strcmp(product_type, info.product_type))	return TRUE;
		if (0 != strcmp(machine_name, info.machine_name))	return TRUE;
		if (0 != strcmp(produce_time, info.produce_time))	return TRUE;
		if (0 != strcmp(szSecondNum, info.szSecondNum))	return TRUE;
		return FALSE;
	}
};
#pragma pack (pop)
struct SEARCH_EDGE_RECT
{
	int						Left;
	int						Top;
	int						Right;
	int						Bottom;
};

struct ALPHA_COMPARE_RESULT
{
	int						bestMScore;				//���ƥ����÷�
	int						bestLScore;				//���ƥ���ٵ�÷�
	int						bestColorScore;			//��ɫ�÷�
	int						MoreDotCount;
	int						ReMoreDotCount;
	int						LessDotCount;
	int						ReLessDotCount;
	int						ColorDotCount;
	int						ReColorDotCount;
	int						FitCount;
};
struct ALPHA_CODE
{
	int						RowSite;
	int						ColSite;

	int						Gate;					//��ֵ��ֵ
	int						GateH;					//����кڵ�ָ���ֵ
	int						GateL;					//�ں��к��ָ���ֵ

	int						Gray;					//����Ҷ�
	int						DotCount;

	int                     BestFitStand;
	int						ReconCheckStand;

	int						errType;				//��������
	char					Sym;					//����ܺ���

	int						ExpMLScore;				//������ƥ��÷�
	ALPHA_COMPARE_RESULT	cmpResult;				//ƥ����
};


struct ALPHA_KARA_RESULT
{
	int						ErrorClass;
	int						ErrorType;
	int						BigCodeValue;
	int						BigSheetValue;
	int						ErrorOccurSite;
	int						SearchLineX;
	int						SearchLineY;
	int						BaseGray;
	SEARCH_EDGE_RECT		AlphaRect;
	ALPHA_CODE				Code[DN_COUNT];
};
struct ALPHA_PROCESS_RESULT :ALPHA_KARA_RESULT
{
	double					dealTime;
};
// struct NET_PACKET_SHEET_NUMBER_RECOG_RESULT
// {
// 	int errInfo;           //�����ʶ
// 	int chehao;            //����
// 	int serialNumber;      //���к�
// 	int sheetNumber;       //8λ���ź�
// };
struct NET_PACKET_SHEET_NUMBER_RECOG_RESULT
{
	INT64 nSerial;
	int nErrorInfo;
	char szPsn[30];
};
//add by xwang for ocr
struct NET_MSG_PACKET_REALPENMAPARA
{
	MV_IMAGE_FMT imgfmt;
	NET_PACKET_SHEET_NUMBER_RECOG_RESULT sheetInf;
	//ALPHA_PROCESS_CONFIG config;
	//ALPHA_PROCESS_TYPE exp;
	ALPHA_PROCESS_RESULT result;

};

// �ſ���վ���͸���������������־
struct NET_MSG_VS_SAMPLE_INFO
{
	INT64	nSerial;
	int 	WantShipPosition;
	int 	RealShipPosition;
	BYTE	reserved[64 - sizeof(int)* 2 - sizeof(INT64)];
	BOOL operator != (const NET_MSG_VS_SAMPLE_INFO & cfg)
	{
		if (nSerial != cfg.nSerial)		return TRUE;
		if (WantShipPosition != cfg.WantShipPosition)		return TRUE;
		if (RealShipPosition != cfg.RealShipPosition)		return TRUE;
		return FALSE;
	}
};


struct NET_PACKET_CHECK_RESULT
{
	int checkResult;
	int errorCount;
};

struct NET_PACKET_ERROR_IMAGE_INFO
{
	int stationID;                 //��վ��
	int xInWholeSheet;             //���ͼ���ڴ����е��� 0-4
	int yInWholeSheet;             //���ͼ���ڸ��еĿ�λ 0-7
	int sheetNumber;               //���ź�
	int serialNumber;              //�������к�
	int type;                      //0:����; 1:���� 
	int errType;                   //��������
	int errEnergy;                 //�е�����
	BYTE r[ERROR_IMAGE_MONO_SIZE]; //rͨ��
	BYTE g[ERROR_IMAGE_MONO_SIZE]; //gͨ��
	BYTE b[ERROR_IMAGE_MONO_SIZE]; //bͨ��
};

//����ȱ����Ϣ,ÿ����һ����
struct NET_PACKET_ERROR_DETAIL_INFO
{
	int stationID;     //ͼ��ɼ���վ��
	int sheetNumber;   //���ź�
	int serialNumber;  //�������к�
	int sheetInfo;     //0:�����޴�; 10:��ֽ; 11:����ֽ;
	int errType[IMAGE_STATION_K_COUNTS]; //1~9;ÿ���Ĵ�������,ֻ���������ش���
	int errEnergy[IMAGE_STATION_K_COUNTS];//�������
	int continueError[SHEET_K_X_COUNTS]; //1��������
};

enum NET_PACKET_SHEET_ERROR_TYPE_CONST 
{
	NET_PACKET_SHEET_ERROR_TYPE_PRESS = -1,      //��ѹ
	NET_PACKET_SHEET_ERROR_TYPE_OK = 0,          //�����޴�
	NET_PACKET_SHEET_ERROR_TYPE_WHITE,           //�׵�
	NET_PACKET_SHEET_ERROR_TYPE_ERROR,           //��ǳ
	NET_PACKET_SHEET_ERROR_TYPE_PARTIAL,         //�۽�
	NET_PACKET_SHEET_ERROR_TYPE_DIRTY,           //�ڵ�
	NET_PACKET_SHEET_ERROR_TYPE_SIDE_GUIDE,      //���
	NET_PACKET_SHEET_ERROR_TYPE_FRONT_GUIDE,     //ǰ��
	NET_PACKET_SHEET_ERROR_TYPE_MAYBE,           //����
	NET_PACKET_SHEET_ERROR_TYPE_THREAD,          //��ȫ��
	NET_PACKET_SHEET_ERROR_TYPE_ANTICOPY_CIRCLE, //����ӡȦ
	NET_PACKET_SHEET_ERROR_TYPE_EMPTY = 10,      //���ſ���
	NET_PACKET_SHEET_ERROR_TYPE_IMP = 11,        //����ֽ	
	NET_PACKET_SHEET_ERROR_TYPE_PRESS_NOT_DET = 14,   //��ѹδ��
	NET_PACKET_SHEET_ERROR_TYPE_NOT_DET = 15,    //��ʱδ��
	NET_PACKET_SHEET_ERROR_TYPE_TEMPLATE = 16,   //ѧϰģ��
	NET_PACKET_SHEET_ERROR_TYPE_COUNT,
};

struct NET_PACKET_SHEET_START_INFO
{
	int CheHao;              //����
	int startSheetNumber;    //8λ��ʼ���ź�
	int backNowNumber;       //4λ���ź�
};



struct NET_SEND_BUFFER
{
	NET_PACKET_ERROR_IMAGE_INFO errImage[IMAGE_STATION_K_COUNTS];
	NET_PACKET_ERROR_DETAIL_INFO errDetail;
};