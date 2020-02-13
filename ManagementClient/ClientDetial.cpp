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
	Model->setHeaderData(0, Qt::Horizontal, tr("����ID"));
	Model->setHeaderData(1, Qt::Horizontal, tr("����Ա"));
	Model->setHeaderData(2, Qt::Horizontal, tr("��������"));
	Model->setHeaderData(3, Qt::Horizontal, tr("���ò�Ʒ"));
	Model->setHeaderData(4, Qt::Horizontal, tr("��ɱ�ʶ"));
	Model->setHeaderData(5, Qt::Horizontal, tr("ʱ��"));
	ui.tableView_reciveDetial->setModel(Model);
	ui.tableView_reciveDetial->show();
	//�����б�����
	ui.tableView_reciveDetial->verticalHeader()->setVisible(false); 
	ui.tableView_reciveDetial->setSelectionBehavior(QAbstractItemView::SelectRows); 
	ui.tableView_reciveDetial->setSelectionMode(QAbstractItemView::SingleSelection); 
	ui.tableView_reciveDetial->setAutoScroll(true);
//	ui.tableView_reciveDetial->horizontalHeader()->setStretchLastSection(true); //���һ��������
	ui.tableView_reciveDetial->resizeColumnsToContents();  // ����Ӧ���*/
}
