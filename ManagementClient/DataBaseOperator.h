#pragma once

#include <QObject>

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
	QSqlTableModel* GetAllModel();
	QSqlTableModel* GetModelByGroupString(QString groupString);
};
