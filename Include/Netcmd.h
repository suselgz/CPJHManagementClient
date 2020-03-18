#pragma  once
#include "NetMsg.h"
#define IMAGE_STATION_K_COUNTS 24
#define SHEET_K_X_COUNTS 5
//网络传送错误图像大小及数目
#define ERROR_IMAGE_WIDTH 180
#define ERROR_IMAGE_HEIGHT 120
#define ERROR_IMAGE_SIZE (ERROR_IMAGE_WIDTH * ERROR_IMAGE_HEIGHT * 3)
#define ERROR_IMAGE_MONO_SIZE (ERROR_IMAGE_WIDTH * ERROR_IMAGE_HEIGHT)
#define MAX_ERROR_IMAGE_COUNT 50
#define NETPACKET_TYPE_TOVS_PENMA_IMAGE					0x16		//从站发送喷码图像
//缺陷信息网络传送缓存大小
#define NET_SEND_BUFFER_SIZE 20
#define SHIMA 251
//背面机缓存大小，采集完第三张，处理之前发送第一张的结果
#define MACHINE_SEND_BUFFER_SIZE 2

//连续出错张数，报连续废
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
	NET_PACKET_MSG_TYPE_CHECK_RESULT_DETAIL, //发送详细检测信息
	NET_PACKET_MSG_TYPE_ERROR_IMAGE,         //发送误差图像
	NET_PACKET_MSG_TYPE_START_DET,           //开始检测
	NET_PACKET_MSG_TYPE_STOP_DET,            //停止检测
	NET_PACKET_MSG_TYPE_START_SEND,          //开始发包
	NET_PACKET_MSG_TYPE_STOP_SEND,           //停止发包
	NET_PACKET_MSG_TYPE_BUILD_LAB_MODEL,     //重建LAB模板
	NET_PACKET_MSG_TYPE_RELEARN_LAB_MODEL,   //再学LAB模板
	NET_PACKET_MSG_TYPE_SHUTDOWN,            //关机
	NET_PACKET_MSG_TYPE_SAVE_TEMPLATE,       //保存模板图像
	NET_PACKET_MSG_TYPE_SHEET_START_INFO,    //主站发送起始大张信息
	NET_PACKET_MSG_TYPE_SHEET_NUMBER_RECOG_RESULT, //号码识别结果
	NET_PACKET_MSG_TYPE_TEMPLATE_STAT,       //当前模板状态
	NET_PACKET_MSG_TYPE_COUNT,
};

//#pragma pack(push , 6)
// 号控主站发送的车号、冠字信息等
struct NET_MSG_HAOMA_BASIC_INFO
{
	int		operator_id;		// 机长ID   0:未完成,1:已完成
	int		machine_id;			// 机台号ID
	int		process_id;			// 工序ID
	int		type_index;			// 品种代码
	int		workunit_index;		// 台班ID
	char	batch[10];			// 车号
//	char	headGroup[12];
	char	headGroup[8];
	char	smallCode[4];		// 冠号		注意：退位后的1K大号或者40K大号，根据冠号录入方式进行判别
	char	workunit_name[10];	// 台班
	char	operator_name[10];	// 机长姓名
	char	process_name[10];	// 工序名称
	char	product_type[10];	// 产品品种
	char	machine_name[20];	// 机台名称
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
	int						bestMScore;				//最佳匹配多点得分
	int						bestLScore;				//最佳匹配少点得分
	int						bestColorScore;			//串色得分
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

	int						Gate;					//二值阈值
	int						GateH;					//红号中黑点分隔阈值
	int						GateL;					//黑号中红点分隔阈值

	int						Gray;					//号码灰度
	int						DotCount;

	int                     BestFitStand;
	int						ReconCheckStand;

	int						errType;				//错误类型
	char					Sym;					//最可能号码

	int						ExpMLScore;				//期望号匹配得分
	ALPHA_COMPARE_RESULT	cmpResult;				//匹配结果
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
// 	int errInfo;           //错误标识
// 	int chehao;            //车号
// 	int serialNumber;      //序列号
// 	int sheetNumber;       //8位大张号
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

// 号控主站发送给在线清数抽样标志
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
	int stationID;                 //从站号
	int xInWholeSheet;             //误差图像在大张中的列 0-4
	int yInWholeSheet;             //误差图像在该列的开位 0-7
	int sheetNumber;               //大张号
	int serialNumber;              //大张序列号
	int type;                      //0:背面; 1:正面 
	int errType;                   //错误类型
	int errEnergy;                 //残点能量
	BYTE r[ERROR_IMAGE_MONO_SIZE]; //r通道
	BYTE g[ERROR_IMAGE_MONO_SIZE]; //g通道
	BYTE b[ERROR_IMAGE_MONO_SIZE]; //b通道
};

//大张缺陷信息,每大张一个包
struct NET_PACKET_ERROR_DETAIL_INFO
{
	int stationID;     //图像采集从站号
	int sheetNumber;   //大张号
	int serialNumber;  //大张序列号
	int sheetInfo;     //0:大张无错; 10:无纸; 11:过版纸;
	int errType[IMAGE_STATION_K_COUNTS]; //1~9;每开的错误类型,只保存最严重错误
	int errEnergy[IMAGE_STATION_K_COUNTS];//误差能量
	int continueError[SHEET_K_X_COUNTS]; //1：连续废
};

enum NET_PACKET_SHEET_ERROR_TYPE_CONST 
{
	NET_PACKET_SHEET_ERROR_TYPE_PRESS = -1,      //离压
	NET_PACKET_SHEET_ERROR_TYPE_OK = 0,          //大张无错
	NET_PACKET_SHEET_ERROR_TYPE_WHITE,           //白点
	NET_PACKET_SHEET_ERROR_TYPE_ERROR,           //深浅
	NET_PACKET_SHEET_ERROR_TYPE_PARTIAL,         //折角
	NET_PACKET_SHEET_ERROR_TYPE_DIRTY,           //黑点
	NET_PACKET_SHEET_ERROR_TYPE_SIDE_GUIDE,      //侧规
	NET_PACKET_SHEET_ERROR_TYPE_FRONT_GUIDE,     //前规
	NET_PACKET_SHEET_ERROR_TYPE_MAYBE,           //疑似
	NET_PACKET_SHEET_ERROR_TYPE_THREAD,          //安全线
	NET_PACKET_SHEET_ERROR_TYPE_ANTICOPY_CIRCLE, //防复印圈
	NET_PACKET_SHEET_ERROR_TYPE_EMPTY = 10,      //大张空张
	NET_PACKET_SHEET_ERROR_TYPE_IMP = 11,        //过版纸	
	NET_PACKET_SHEET_ERROR_TYPE_PRESS_NOT_DET = 14,   //离压未检
	NET_PACKET_SHEET_ERROR_TYPE_NOT_DET = 15,    //超时未检
	NET_PACKET_SHEET_ERROR_TYPE_TEMPLATE = 16,   //学习模板
	NET_PACKET_SHEET_ERROR_TYPE_COUNT,
};

struct NET_PACKET_SHEET_START_INFO
{
	int CheHao;              //车号
	int startSheetNumber;    //8位起始大张号
	int backNowNumber;       //4位大张号
};



struct NET_SEND_BUFFER
{
	NET_PACKET_ERROR_IMAGE_INFO errImage[IMAGE_STATION_K_COUNTS];
	NET_PACKET_ERROR_DETAIL_INFO errDetail;
};