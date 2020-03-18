#pragma  once

#define IMAGE_STATION_K_COUNTS 40
#define SHEET_K_X_COUNTS 7

//���紫�ʹ���ͼ���С����Ŀ
#define ERROR_IMAGE_WIDTH 180
#define ERROR_IMAGE_HEIGHT 120
#define ERROR_IMAGE_SIZE (ERROR_IMAGE_WIDTH * ERROR_IMAGE_HEIGHT * 3)
#define ERROR_IMAGE_MONO_SIZE (ERROR_IMAGE_WIDTH * ERROR_IMAGE_HEIGHT)
#define MAX_ERROR_IMAGE_COUNT 50

//ȱ����Ϣ���紫�ͻ����С
#define NET_SEND_BUFFER_SIZE 20

//����������С���ɼ�������ţ�����֮ǰ���͵�һ�ŵĽ��
#define MACHINE_SEND_BUFFER_SIZE 2

//����������������������
#define NET_CONTINUE_ERROR_SHEET_COUNT 2
#define NET_CONTINUE_ERROR_K_COUNT 2

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

struct NET_PACKET_SHEET_NUMBER_RECOG_RESULT
{
	int errInfo;           //�����ʶ
	int chehao;            //����
	int serialNumber;      //���к�(����+���к�)
	int sheetNumber;       //����(����+���ź�)
	int codeDetCount;
	int codeGrabCount;
};

struct NET_SEND_BUFFER
{
	NET_PACKET_ERROR_IMAGE_INFO errImage[IMAGE_STATION_K_COUNTS];
	NET_PACKET_ERROR_DETAIL_INFO errDetail;
	int crescentErrorType;
};

enum DET_MACHINE_TYPE_CONST
{
	DET_MACHINE_TYPE_H_FRONT = 0,   //һӡ
	DET_MACHINE_TYPE_H_BACK,		//��ӡ
	DET_MACHINE_TYPE_COUNT,
};