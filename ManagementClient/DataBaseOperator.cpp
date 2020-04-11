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

bool DataBaseOperator::GetRefreshInfo(GET_REFRESH_INFO &refresh_info)
{

	bool ret = false;
	QString sql;
	sql = QString("select a.BATCH_ID,a.BATCH_CODE,b.AMOUNT,c.PRODUCT_ID,c.PRODUCT_AMOUNT,c.PRODUCT_NAME from\
                   wip_batchs a,wip_batch_info b,dic_products c where a.BATCH_ID=b.BATCH_ID and b.batch_info_id =\
                  (select min(a.batch_info_id) from wip_batch_info a , wip_batchs b where a.BATCH_ID=b.BATCH_ID\
                  and  b.check_flag = 1) and b.PRODUCT_ID=c.PRODUCT_ID");
	QSqlQuery query1(sql, *m_pDb);
	while (query1.next())
	{
		refresh_info.patchID = query1.value(0).toInt();
		refresh_info.patchCode = query1.value(1).toString();
		refresh_info.preSetAmount = query1.value(2).toInt();
		refresh_info.productID = query1.value(3).toInt();
		refresh_info.productAmount = query1.value(4).toInt();
		refresh_info.productName = query1.value(5).toString();
	}
	
	sql = QString("select a.batch_id,b.MACHINE_ID,d.MACHINE_NAME,c.OPERATOR_ID,c.OPERATOR_NAME from\
                           wip_batchs a,wip_batch_operator b,dic_operators c,dic_machines d where\
                           a.BATCH_ID=b.BATCH_ID and b.OPERATOR_ID=c.OPERATOR_ID and b.MACHINE_ID=d.MACHINE_ID and a.check_flag=1 and b.OPERATOR_TYPE_ID=5 ORDER BY b.MACHINE_ID");
	QSqlQuery query2(sql, *m_pDb);
	refresh_info.operatorCount = 0;
	while (query2.next())
	{
		refresh_info.operator_info[refresh_info.operatorCount].patchID= query2.value(0).toInt();
		refresh_info.operator_info[refresh_info.operatorCount].machineID = query2.value(1).toInt();
		refresh_info.operator_info[refresh_info.operatorCount].machineName = query2.value(2).toString();
		refresh_info.operator_info[refresh_info.operatorCount].operatorID = query2.value(3).toInt();
		refresh_info.operator_info[refresh_info.operatorCount].operatorName = query2.value(4).toString();
		refresh_info.operatorCount++;
	}
	sql = QString("select count(c.INSPECT_BOX_ID) as boxCount from wip_batchs a,qa_inspect_master b,qa_inspect_box_slave c\
                           where a.BATCH_ID=b.BATCH_ID and b.INSPECTM_ID=c.INSPECTM_ID and a.BATCH_ID=%1").arg(refresh_info.operator_info->patchID);
	QSqlQuery query3(sql, *m_pDb);
	while (query3.next())
	{
		refresh_info.destroyBoxNum = query3.value(0).toInt();
	}
	sql = QString("select count(e.INSPECT_BAG_ID) as bagCount from qa_inspect_bag_slave e,(select c.INSPECT_BOX_ID from wip_batchs a,qa_inspect_master b,qa_inspect_box_slave c where\
                           a.BATCH_ID=b.BATCH_ID and b.INSPECTM_ID=c.INSPECTM_ID and a.BATCH_ID=%1) f where  e.INSPECT_BOX_ID=f.INSPECT_BOX_ID").arg(refresh_info.operator_info->patchID);
	QSqlQuery query4(sql, *m_pDb);
	while (query4.next())
	{
		refresh_info.destroyBagNum = query4.value(0).toInt();
		ret = true;
	}
	refresh_info.destroyNum = refresh_info.destroyBagNum * 1000 * refresh_info.productAmount;
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
