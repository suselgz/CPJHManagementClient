#include "stdafx.h"
#include "ClientInfo.h"

ClientInfo::ClientInfo(QWidget *parent)
	: QFrame(parent)
{
	ui.setupUi(this);
	m_bSel = true;
	m_timer = new QTimer(this);
	connect(m_timer, SIGNAL(timeout()), this, SLOT(TimeOut()));
	SetChecked(false);
	ReSet();
}

ClientInfo::~ClientInfo()
{
}

void ClientInfo::mousePressEvent(QMouseEvent *event)
{
	SetChecked(true);
	emit ClientInfoChecked(m_nClientNo);
}

void ClientInfo::SetLight(bool nRct)
{
	if (nRct)
	{
		m_timer->start(1000);
	}
	else
	{
		m_timer->stop();
	}
	
}

void ClientInfo::SetChecked(bool bChecked)
{
	if (bChecked == false)
	{
		this->setStyleSheet("background-color: rgb(191,220,237 );");
	}
	else
	{
		this->setStyleSheet("background-color: rgb(163,227,211);");
	}
}

void ClientInfo::SetClientInfo(CLIENT_INFO clientInfo)
{
	ui.label_machineName->setText(clientInfo.machineName);
	ui.label_operatorName->setText(clientInfo.operatorName);
	ui.label_totalRecive->setText(QString::number(clientInfo.nTotalRecive));
	ui.label_totalRetrieve->setText(QString::number(clientInfo.nTotalRetrieve));
}

void ClientInfo::ModifyTotalRecive(int nValue)
{
	ui.label_totalRecive->setText(QString::number(nValue));
}

void ClientInfo::ModifyTotalRetrieve(int nValue)
{
	ui.label_totalRetrieve->setText(QString::number(nValue));
}

void ClientInfo::ReSet(void)
{
	ui.label_machineName->clear();
	ui.label_operatorName->clear();
	ui.label_totalRecive->clear();
	ui.label_totalRetrieve->clear();
}

void ClientInfo::TimeOut()
{
	SetChecked(m_bSel);
	if (m_bSel)
	{
		m_bSel = false;
	}
	else
	{
		m_bSel = true;
	}
	
}
