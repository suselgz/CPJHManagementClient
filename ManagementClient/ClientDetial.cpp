#include "stdafx.h"
#include "ClientDetial.h"

ClientDetial::ClientDetial(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
}

ClientDetial::~ClientDetial()
{
}

void ClientDetial::SetMachineName(QString machineName)
{
	ui.label_machineName->setText(machineName);
}

void ClientDetial::SetOperatorName(QString operatorName)
{
	ui.label_operatorName->setText(operatorName);
}

void ClientDetial::SetManagerName(QString managerName)
{
	ui.label_managerName->setText(managerName);
}

void ClientDetial::SetTotalRecive(int nTotalRecive)
{
	ui.label_totalRecive->setText(QString::number(nTotalRecive));
}

void ClientDetial::SetTotalRetrieve(int nTotalRetrieve)
{
	ui.label_totalRetrieve->setText(QString::number(nTotalRetrieve));
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
