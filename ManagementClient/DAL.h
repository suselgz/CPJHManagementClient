#pragma once

#include <QObject>
#include "DALCommon.h"
#include "DataBaseOperator.h"

class DAL : public QObject
{
	Q_OBJECT

public:
	DAL(QObject *parent = nullptr);
	~DAL();
private:
	QString m_hostName;
	QString m_dbName;
	QString m_userName;
	QString m_password;
	QSqlDatabase m_db;
public:
	DataBaseOperator m_DataBaseOperator;
public:
	void SetDb(QString hostName,QString dbName,QString userName,QString password);
	bool ConnectDb(void);
	bool DisConnectDb(void);
};
