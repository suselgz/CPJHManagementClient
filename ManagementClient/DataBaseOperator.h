#pragma once
#include <QObject>
#include "Define.h"
class DataBaseOperator : public QObject
{
	Q_OBJECT

public:
	DataBaseOperator(QObject *parent = nullptr);
	~DataBaseOperator();
private:
	QSqlDatabase* m_pDb;
public:
	bool SetDb(QSqlDatabase* pDb);
	bool GetDicMachineList(QVector<DIC_MACHINE> &vecDicMachine);
	bool GetRefreshInfo(GET_REFRESH_INFO &refresh_info);
	QSqlTableModel* GetAllModel();
	QSqlTableModel* GetModelByGroupString(QString groupString);
};
