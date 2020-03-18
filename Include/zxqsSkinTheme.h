#define KX_ZXQSSKIN_MAIN_VERSION 1
#define KX_ZXQSSKIN_SUB_VERSION 1
#define KX_ZXQSSKIN_VERSION ((KX_ZXQSSKIN_MAIN_VERSION << 16) + KX_ZXQSSKIN_SUB_VERSION)
#pragma once
#include <QObject>
#include <string>
#define CODE_LIB_SOLUTION
#ifdef  CODE_LIB_SOLUTION
#define CODE_LIB_EXPORT __declspec(dllexport)
#else
#define CODE_LIB_EXPORT __declspec(dllimport)
#endif

class  zxqsSkinTheme : public QObject
{
	Q_OBJECT
public:
	virtual bool LoadSkin() = 0;
	virtual std::string GetLastErr() = 0;
};
CODE_LIB_EXPORT zxqsSkinTheme * _stdcall zxqsSkinThemeInstance(int version = KX_ZXQSSKIN_VERSION);