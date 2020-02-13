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
	pModel->setHeaderData(0, Qt::Horizontal, tr("�豸���"));
	pModel->setHeaderData(1, Qt::Horizontal, tr("�豸����"));
	pModel->setHeaderData(2, Qt::Horizontal, tr("�豸����"));
	pModel->setHeaderData(3, Qt::Horizontal, tr("�豸����"));
	pModel->setHeaderData(4, Qt::Horizontal, tr("����״̬"));
	pModel->setHeaderData(0, Qt::Horizontal, tr("����ʱ��"));
	pModel->setHeaderData(1, Qt::Horizontal, tr("����ʱ��"));
	pModel->setHeaderData(2, Qt::Horizontal, tr("˵��"));
	pModel->setHeaderData(3, Qt::Horizontal, tr("�豸����"));
	pModel->setHeaderData(4, Qt::Horizontal, tr("������ԱID"));
	return pModel;
}

QSqlTableModel* DataBaseOperator::GetModelByGroupString(QString groupString)
{
	QSqlTableModel* pModel = new QSqlTableModel(this, *m_pDb);
	pModel->setTable("dic_machines");
	pModel->setFilter(QString("GROUP_STRING =%1").arg(groupString));
	pModel->select();
	pModel->setHeaderData(0, Qt::Horizontal, tr("�豸���"));
	pModel->setHeaderData(1, Qt::Horizontal, tr("�豸����"));
	pModel->setHeaderData(2, Qt::Horizontal, tr("�豸����"));
	pModel->setHeaderData(3, Qt::Horizontal, tr("�豸����"));
	pModel->setHeaderData(4, Qt::Horizontal, tr("����״̬"));
	pModel->setHeaderData(0, Qt::Horizontal, tr("����ʱ��"));
	pModel->setHeaderData(1, Qt::Horizontal, tr("����ʱ��"));
	pModel->setHeaderData(2, Qt::Horizontal, tr("˵��"));
	pModel->setHeaderData(3, Qt::Horizontal, tr("�豸����"));
	pModel->setHeaderData(4, Qt::Horizontal, tr("������ԱID"));
	return pModel;
}
