#pragma once

#include "ImgDef.h"

enum ALLOC_IMAGE_FLAG_CONST
{
	ALLOC_IMAGE_FLAG_USER_ALLOC_IMAGE_DATA_MEM = 0x01,
};

MV_IMAGE * _stdcall ImageHeadAlloc();
void _stdcall ImageHeadFree(MV_IMAGE * p);
void *  _stdcall ImageDataAlloc(unsigned size);
void  _stdcall ImageDataFree(void * pd);
MV_IMAGE * _stdcall AllocImage(MV_IMAGE_FMT * fmt , int flag = 0);
void _stdcall FreeImage(MV_IMAGE * img);

void _stdcall MemSet_8u_C1(void * dst , int val , int count);
void _stdcall MemSet_16u_C1(void * dst , int val , int count);
void _stdcall MemSet_8u_C3(void * dst , int val , int count);
void _stdcall MemSet_8u_C4(void * dst , int val , int count);
void _stdcall MemCopy(void * dst , void * src , int count);
void _stdcall FillImage(MV_IMAGE * dst , int val);

void _stdcall ImageMemCopy(void * dst , void * sr , int width , int height , int srcPitch , int dstPitch);
void _stdcall CopyImageData(MV_IMAGE * dst , MV_IMAGE * src);
void _stdcall FlipImage(MV_IMAGE * dst , MV_IMAGE * src);


int _stdcall SaveBMPImage(LPCTSTR file , MV_IMAGE * img);
MV_IMAGE * _stdcall LoadBMPImage(LPCTSTR file);

int _stdcall SaveMVImage(LPCTSTR file , MV_IMAGE * img);
MV_IMAGE * _stdcall LoadMVImage(LPCTSTR file);

void _stdcall ResetCurTime();
double  _stdcall GetCurTime();
void _cdecl  DebugMsg(LPCTSTR lpszFormat, ...);
double  _stdcall GetCurTimeMS();


float _stdcall GetImageAverage_8u_C1R(BYTE * data , int pitch , int width , int height);
float _stdcall GetImageAvgStd_8u_C1R(float  * pstd , BYTE * data , int pitch , int width , int height);

unsigned _stdcall MulDivU(unsigned x , unsigned y , unsigned d);

int _stdcall GetPixelSize(int type);

void _stdcall ImageLut_8u_C1_8u_C4(void * dst , void * src , int width , int height , int srcPitch , int dstPitch , BYTE * lut);
void _stdcall ImageConvert_8u_C1_8u_C4(void * dst , void * src , int width , int height , int srcPitch , int dstPitch);
void _stdcall ImageConvert_8u_C4_8u_C3(void * dst , void * src , int width , int height , int srcPitch , int dstPitch);
void _stdcall ImageConvert_8u_C3_8u_C4(void * dst , void * src , int width , int height , int srcPitch , int dstPitch);
void _stdcall ImageConvert_8u_C4_8u_P4(void ** dstTab , void * src , int width , int height , int srcPitch , int dstPitch);

void _stdcall ImageLut_8u_C1(BYTE * dst , BYTE * src , int width , int height , int srcPitch , int dstPitch , BYTE * lut);
void _stdcall ImageLut_8u_C1I(BYTE * src , int width , int height , int srcPitch ,BYTE * lut);

void _stdcall ImageLut(MV_IMAGE * dstImg , MV_IMAGE * srcImg , void * lut);
void _stdcall ImageApplyLut(MV_IMAGE * dstImg , void * lut);

void _stdcall GetROIImage(MV_IMAGE * roiImg , MV_IMAGE * img , MV_RECTI * roi);

void _stdcall FloatTruncateToInt(int * dst , float * src , int count);
void _stdcall FloatRoundNearToInt(int * dst , float * src , int count);
void _stdcall IntToFloat(float * dst , int * src , int count);
int _stdcall ftoir(float v);
int _stdcall ftoit(float v);
int _stdcall dtoir(double v);
int _stdcall dtoit(double v);
int _stdcall GetPixelValueAtPos(MV_IMAGE * img , MV_POS * pos , int bk , int interpolation);

void * _stdcall InterfaceAlloc(/*unsigned*/size_t size);
void _stdcall InterfaceFree(void * p);

void _stdcall ImageHistogram(int * hist , MV_IMAGE * img , MV_RECTI * roi);
void _stdcall ImageHist_8u(int * hist , BYTE * data , int width , int height , int pitch);

void _stdcall ImageHorizonProjection_8u_C1R(BYTE * horLine , int width , int height , BYTE * data , int pitch);
void _stdcall ImageVerticalProjection_8u_C1R(BYTE * vertLine , int width , int height , BYTE * data , int pitch);

MV_IMAGE * _stdcall LoadJpegImage(LPCTSTR file);
MV_IMAGE * _stdcall LoadJpegImageFromMem(__in BYTE *pSrc, int nJpegSize);
int _stdcall SaveJpegFile(LPCTSTR file, MV_IMAGE * img, int nQuality = 95);
int _stdcall SaveJpegFileToMem(__in BYTE *pDst, int nBuffSize, MV_IMAGE * img, int nQuality = 95);

class CBaseIF
{
public:
	void *operator new(/*unsigned*/size_t size){return InterfaceAlloc(size);}
	void operator delete(void * p){return InterfaceFree(p);}
};

