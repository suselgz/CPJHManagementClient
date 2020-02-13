#include "stdafx.h"
#include "DAL.h"

DAL::DAL(QObject *parent)
	: QObject(parent)
{
	m_DataBaseOperator.SetDb(&m_db);
}

DAL::~DAL()
{
}

void DAL::SetDb(QString hostName, QString dbName, QString userName, QString password)
{
	m_hostName = hostName;
	m_dbName = dbName;
	m_userName = userName;
	m_password = password;
}

bool DAL::ConnectDb(void)
{
	m_db = QSqlDatabase::addDatabase("QMYSQL");
	m_db.setHostName(m_hostName);
	m_db.setDatabaseName(m_dbName);
	m_db.setUserName(m_userName);
	m_db.setPassword(m_password);
	if (!m_db.open())
	{
		QString err = m_db.lastError().text();
		QMessageBox::information(NULL, "注意", QString("数据库连接失败，请联系管理人员！错误描述：%1").arg(err));
		return false;
	}
	return true;
}

bool DAL::DisConnectDb(void)
{
	return true;
}
