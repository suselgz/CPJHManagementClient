#pragma once

#include <QObject>
#include "DAL.h"
#include "Define.h"
#include "Netcmd.h"
#include <queue>
using namespace std;
class GlobalParam : public QObject
{
	Q_OBJECT

public:
	GlobalParam(QObject *parent);
	~GlobalParam();
public:
	static void InitGlobalParam(QObject *parent = NULL);
	static void FreeGlobalParam(void);
	static void InitDal(QObject *parent);
	static void GetSetting(void);
	static void WriteLog(QString inputStr, QString fileDir);
public:
	static QString orgPath;
	static DAL dal;
	static DB_SETTING dbSetting;
	static CLIENT_INFO clintInfo[CLIENT_NUM_INFO];
	static queue<NET_MSG_MODIFY_INFO> netMsg[CLIENT_NUM_INFO];
	static queue<int> Test[CLIENT_NUM_INFO];
};
