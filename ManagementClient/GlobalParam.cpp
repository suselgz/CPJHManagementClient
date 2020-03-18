#include "stdafx.h"
#include "GlobalParam.h"
DAL GlobalParam::dal;
DB_SETTING GlobalParam::dbSetting;
CLIENT_INFO GlobalParam::clintInfo[CLIENT_NUM_INFO];
QString GlobalParam::orgPath;
vector<NET_MSG_MODIFY_INFO*> GlobalParam::netMsg[CLIENT_NUM_INFO];
GlobalParam::GlobalParam(QObject *parent)
	: QObject(parent)
{
}

GlobalParam::~GlobalParam()
{
}

void GlobalParam::InitGlobalParam(QObject *parent /*= NULL*/)
{
	QDir dir;
	dir.currentPath();
	dir.cdUp();
	orgPath = dir.absolutePath();
	GetSetting();
	if (!dbSetting.dbIp.isEmpty() &&
		!dbSetting.dbName.isEmpty() &&
		!dbSetting.userName.isEmpty() &&
		!dbSetting.userPwd.isEmpty() &&
		!dbSetting.serverPort.isEmpty()
		)
	{
		InitDal(parent);
	}
	else
	{
		QMessageBox::information(NULL, "注意", QString("数据库连接字段读取失败，请联系管理人员！"));
	}
}

void GlobalParam::FreeGlobalParam(void)
{

}

void GlobalParam::InitDal(QObject *parent)
{
	dal.SetDb(dbSetting.dbIp, dbSetting.dbName, dbSetting.userName, dbSetting.userPwd);
	dal.ConnectDb();
}

void GlobalParam::GetSetting(void)
{
	QSettings* pSettings = new QSettings("SysConfig.ini", QSettings::IniFormat);
	pSettings->setIniCodec(QTextCodec::codecForName("utf-8"));
	dbSetting.dbIp = pSettings->value("/db/dbIp").toString();
	dbSetting.dbName = pSettings->value("/db/dbName").toString();
	dbSetting.userName = pSettings->value("/db/userName").toString();
	dbSetting.userPwd = pSettings->value("/db/userPwd").toString();
	dbSetting.serverPort = pSettings->value("/db/serverPort").toString();
	delete pSettings;
	pSettings = nullptr;
}

void GlobalParam::WriteLog(QString inputStr, QString fileDir)
{
	QDir dir;
	QString path = orgPath + "/log/" + fileDir;
	if (!dir.exists(path))
	{
		dir.mkpath(path);
	}
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_data = current_date_time.toString("yyyy-MM-dd");
	QString logfile = path + "/" + current_data + ".txt";
	QString current_time = current_date_time.toString("hh:mm:ss:zzz");
	QFile file(logfile);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
	{
		return;
	}
	QTextStream stream(&file);
	stream << current_time + "   " + inputStr << "\n";
	file.close();
}