#ifndef _CMvImage_H_
#define _CMvImage_H_

#include "ImgDef.h"
#include "stdio.h"
//#include "ippi.h"

typedef unsigned char UCHAR;

class  CMvImage
{
public:
	CMvImage(void);
	CMvImage(int iWidth, int iHeight, int iType=0);
	CMvImage(int iWidth, int iHeight, int iType, UCHAR* pData);
	CMvImage(const CMvImage& imageSrc){*this = imageSrc;}
	~CMvImage(void);

	bool	SetSize(int iWidth, int iHeight, int iType);
	int		ImageHeight() const;
	int		ImageWidth() const;
	int		ImageType() const;
	int		ImageBpp() const;
	int		ImagePitch() const;
	bool	SetInvalidMem(UCHAR ucVal = 0);
	bool	AttachImage(UCHAR* pData);
	bool	DetachImage();
 	bool	ReadFile(const char* pstrFileName);
 	bool	WriteFile(const char* pstrFileName);
	bool	SaveBmpFile(const char*	pstrFileName) const;
	bool	LoadBmpFile(const char*	pstrFileName);
	bool	CopyImageLines(int iStartLine, int iSrcStartLine, int iCopyLine, CMvImage& image);
	void	SetRealHeight(int nRealHeight) ; 
	int	    GetRealHeight() const;

	MV_IMAGE*	    GetMvImage();
	UCHAR*		    GetImageAddr() const;

	CMvImage&   operator = (const CMvImage& srcImage);

protected:
	MV_IMAGE* m_pImage;
	//image real height
	int	m_iRealHeight;
};
#endif