#include "stdafx.h"
#include "ClientDetial.h"

ClientDetial::ClientDetial(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	ui.label_machine1Status->setStyleSheet("background-color: rgb(200, 0, 0); border-radius: 15px;");
	ui.label_machine2Status->setStyleSheet("background-color: rgb(200, 0, 0); border-radius: 15px;");
	ui.label_machine3Status->setStyleSheet("background-color: rgb(200, 0, 0); border-radius: 15px;");
	
}

ClientDetial::~ClientDetial()
{
	
}

void ClientDetial::SetNetConnectStatus(NET_CONNECT_STATUS net_status)
{
	if (net_status.m_pNetMachine1)
	{
		ui.label_machine1Status->setStyleSheet("background-color: rgb(0, 200, 0); border-radius: 15px;");
	}
	else
	{
		ui.label_machine1Status->setStyleSheet("background-color: rgb(200, 0, 0); border-radius: 15px;");
	}
	if (net_status.m_pNetMachine2)
	{
		ui.label_machine2Status->setStyleSheet("background-color: rgb(0, 200, 0); border-radius: 15px;");
	}
	else
	{
		ui.label_machine2Status->setStyleSheet("background-color: rgb(200, 0, 0); border-radius: 15px;");
	}
	if (net_status.m_pNetMachine3)
	{
		ui.label_machine3Status->setStyleSheet("background-color: rgb(0, 200, 0); border-radius: 15px;");
	}
	else
	{
		ui.label_machine3Status->setStyleSheet("background-color: rgb(200, 0, 0); border-radius: 15px;");
	}
}

void ClientDetial::SetpatchCode(QString patchCode)
{
	ui.label_patchCode->setText(patchCode);
}

void ClientDetial::SetproductType(QString productType)
{
	ui.label_productType->setText(productType);
}

void ClientDetial::SetpreAmount(QString preAmoun)
{
	ui.label_preSetAmount->setText(preAmoun);
}

void ClientDetial::SetdestroyNum(int destroyNum)
{
	QString num = QString::number(destroyNum);
	size_t len = num.length();
	for (int index = (int)len - 3; index > 0; index -= 3)
	{
		num.insert(index, ",");
	}
	ui.label_destroyNum->setText(num);
}

void ClientDetial::SetdestroyBox(int destroyBox)
{
	QString box = QString::number(destroyBox);
	size_t len = box.length();
	for (int index = (int)len - 3; index > 0; index -= 3)
	{
		box.insert(index, ",");
	}
	ui.label_destroyBox->setText(box);
}

void ClientDetial::SetdestroyBag(int destroyBag)
{
	QString Bag = QString::number(destroyBag);
	size_t len = Bag.length();
	for (int index = (int)len - 3; index > 0; index -= 3)
	{
		Bag.insert(index, ",");
	}
	ui.label_destroyBag->setText(Bag);
}

void ClientDetial::SetTableReciveDetial(QString operatorName)
{
/*	QSqlQueryModel *Model;
	Model =GlobalParam::dal.m_wipReceiveRecordsCURD.GetQueryReciveModel(operatorName);
	Model->setHeaderData(0, Qt::Horizontal, tr("领用ID"));
	Model->setHeaderData(1, Qt::Horizontal, tr("复点员"));
	Model->setHeaderData(2, Qt::Horizontal, tr("领用总数"));
	Model->setHeaderData(3, Qt::Horizontal, tr("领用产品"));
	Model->setHeaderData(4, Qt::Horizontal, tr("完成标识"));
	Model->setHeaderData(5, Qt::Horizontal, tr("时间"));
	ui.tableView_reciveDetial->setModel(Model);
	ui.tableView_reciveDetial->show();
	//设置列表属性
	ui.tableView_reciveDetial->verticalHeader()->setVisible(false); 
	ui.tableView_reciveDetial->setSelectionBehavior(QAbstractItemView::SelectRows); 
	ui.tableView_reciveDetial->setSelectionMode(QAbstractItemView::SingleSelection); 
	ui.tableView_reciveDetial->setAutoScroll(true);
//	ui.tableView_reciveDetial->horizontalHeader()->setStretchLastSection(true); //最后一列填满表
	ui.tableView_reciveDetial->resizeColumnsToContents();  // 自适应宽度*/
}