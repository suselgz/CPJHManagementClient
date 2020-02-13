#include "stdafx.h"
#include "DataBaseOperator.h"

DataBaseOperator::DataBaseOperator(QObject *parent)
	: QObject(parent)
{
}

DataBaseOperator::~DataBaseOperator()
{
}

bool DataBaseOperator::SetDb(QSqlDatabase* pDb)
{
	m_pDb = pDb;
	return true;
}


bool DataBaseOperator::GetDicMachineList(QVector<DIC_MACHINE> &vecDicMachine)
{
	bool ret = false;
	QString sql = QString("SELECT * FROM cpjh.dic_machines");

	QSqlQuery query(sql, *m_pDb);
	while (query.next())
	{
		DIC_MACHINE dicMachine;
		dicMachine.MACHINE_ID = query.value(0).toInt();
		dicMachine.MACHINE_CODE = query.value(1).toString().toStdString();
		dicMachine.MACHINE_NAME = query.value(2).toString().toStdString();
		dicMachine.USE_FLAG = query.value(3).toInt();
		dicMachine.START_DATE = query.value(4).toString().toStdString();
		dicMachine.END_DATE = query.value(5).toString().toStdString();
		dicMachine.NOTE = query.value(6).toString().toStdString();
		vecDicMachine.push_back(dicMachine);
		ret &= true;
	}
	return ret;
}

QSqlTableModel* DataBaseOperator::GetAllModel()
{
	QSqlTableModel* pModel = new QSqlTableModel(this, *m_pDb);
	pModel->setTable("dic_machines");
	pModel->select();
	pModel->setHeaderData(0, Qt::Horizontal, tr("设备序号"));
	pModel->setHeaderData(1, Qt::Horizontal, tr("设备类型"));
	pModel->setHeaderData(2, Qt::Horizontal, tr("设备编码"));
	pModel->setHeaderData(3, Qt::Horizontal, tr("设备名称"));
	pModel->setHeaderData(4, Qt::Horizontal, tr("启用状态"));
	pModel->setHeaderData(0, Qt::Horizontal, tr("启用时间"));
	pModel->setHeaderData(1, Qt::Horizontal, tr("禁用时间"));
	pModel->setHeaderData(2, Qt::Horizontal, tr("说明"));
	pModel->setHeaderData(3, Qt::Horizontal, tr("设备分组"));
	pModel->setHeaderData(4, Qt::Horizontal, tr("操作人员ID"));
	return pModel;
}

QSqlTableModel* DataBaseOperator::GetModelByGroupString(QString groupString)
{
	QSqlTableModel* pModel = new QSqlTableModel(this, *m_pDb);
	pModel->setTable("dic_machines");
	pModel->setFilter(QString("GROUP_STRING =%1").arg(groupString));
	pModel->select();
	pModel->setHeaderData(0, Qt::Horizontal, tr("设备序号"));
	pModel->setHeaderData(1, Qt::Horizontal, tr("设备类型"));
	pModel->setHeaderData(2, Qt::Horizontal, tr("设备编码"));
	pModel->setHeaderData(3, Qt::Horizontal, tr("设备名称"));
	pModel->setHeaderData(4, Qt::Horizontal, tr("启用状态"));
	pModel->setHeaderData(0, Qt::Horizontal, tr("启用时间"));
	pModel->setHeaderData(1, Qt::Horizontal, tr("禁用时间"));
	pModel->setHeaderData(2, Qt::Horizontal, tr("说明"));
	pModel->setHeaderData(3, Qt::Horizontal, tr("设备分组"));
	pModel->setHeaderData(4, Qt::Horizontal, tr("操作人员ID"));
	return pModel;
}
