#pragma once
#include "windows.h"
#include "math.h"

enum MV_IMAGE_TYPE_CONST
{
	MV_IMAGE_TYPE_INVALID		= -2,
	MV_IMAGE_TYPE_BIN			= -1, //bin bit
	MV_IMAGE_TYPE_G8			= 0, //Gray Byte
	MV_IMAGE_TYPE_RGB24			= 1, //RGB 24
	MV_IMAGE_TYPE_RGB32			= 2, //RGB 32

	MV_IMAGE_TYPE_RGB24_PLANAR	= 3, //RGB24 PLANAR
	MV_IMAGE_TYPE_G16			= 4,
	MV_IMAGE_TYPE_COUNT			= 5
};

enum MV_IMAGE_INTERPOLATION_CONST
{
	INTERPOLATION_NN = 0 ,
	INTERPOLATION_LN = 1,
};

#pragma pack(push , 1)


static int pixelSizeTab[] = 
{
	1,8,24,32,8,16,
};

struct MV_IMAGE_FMT
{
	int width , height;
	int type;
};

enum MV_IMAGE_FLAG_CONST
{
	MV_IMAGE_FLAG_IMAGE_DATA_MEM_ALLOC_BY_USER = 0x02,
	MV_IMAGE_FLAG_IMAGE_DATA_MEM_ALLOC_BY_SYSTEM = 0x01
};

struct MV_IMAGE:public MV_IMAGE_FMT
{
	int flag;
	int pitch;
	void * data;
};

struct MV_IMAGE_SUB_STAT
{
	float mean , std;
};

struct MV_IMAGE_STAT:MV_IMAGE_SUB_STAT
{
	int min , max;
};


struct MV_POS
{
	float x , y;
	BOOL operator != (const MV_POS &cfg)
	{
		if (abs(cfg.x - x) > 0.00000001f) return TRUE;
		if (abs(cfg.y - y) > 0.00000001f) return TRUE;
		return FALSE;
	}

};

struct MV_POSI
{
	int x , y;
	BOOL operator != (const MV_POSI &cfg)
	{
		if (cfg.x != x) return TRUE;
		if (cfg.y != y) return TRUE;
		return FALSE;
	}
};


struct MV_LINE
{
	float sx , sy;
	float ex , ey;
};


struct MV_LINEI
{
	int sx , sy;
	int ex , ey;
};

struct MV_RECT
{
	float left,top;
	float right,bottom;
	BOOL operator != (const MV_RECT &cfg)
	{
		if (abs(cfg.left - left)> 0.000001) return TRUE;
		if (abs(cfg.top - top)> 0.000001) return TRUE;
		if (abs(cfg.right - right)> 0.000001) return TRUE;
		if (abs(cfg.bottom - bottom)> 0.000001) return TRUE;
		return FALSE;
	}

	RECT Rect()
	{
		RECT rc = {(long)left,(long)top,(long)right,(long)bottom};
		return rc;
	}
};

struct MV_RECTI
{
	int left,top;
	int right,bottom;
};
//edit by xwang in 20140221
//定义为公共结构，建模站要使用请包涵这个头
struct ALIGN_REGION
{
	MV_RECT kernelRegion;
	MV_RECT searchRegion;
};

#pragma pack(pop)

