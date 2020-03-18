#ifndef _LOAD_SAVE_H_
#define _LOAD_SAVE_H_

#include "MvImage.h"
#include "string"
#include "vector"

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

	CMvImage* _stdcall imread(const char* filename );
	bool	  _stdcall img_read(const char* filename, CMvImage* pImage);
	bool	  _stdcall imwrite_p(const char* filename, CMvImage& image, const vector<int>& params);
	bool	  _stdcall imwrite(const char* filename, CMvImage& image);
#ifdef __cplusplus
}
#endif

#endif