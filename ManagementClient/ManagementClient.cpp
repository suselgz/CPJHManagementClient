#include "stdafx.h"
#include "ManagementClient.h"

ManagementClient::ManagementClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	InitStatusBar();
	InitClientInfo();
	InitQssInfo();
	SetClientInfoEnabled(true);
	m_nSelClientNo = 0;
	showMaximized();
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
	this->setWindowState(Qt::WindowFullScreen);
}

ManagementClient::~ManagementClient()
{
	delete m_skin;
}

void ManagementClient::on_pushButton_Exit_clicked(void)
{
	close();
}

void ManagementClient::ClientInfoChecked(int nClientNo)
{
	BagModify* bagModify = new BagModify();
	bagModify->setWindowModality(Qt::ApplicationModal);
	bagModify->show();
/*	CLIENT_INFO clientInfo;
	m_nSelClientNo = nClientNo;

//	GlobalParam::clintInfo = clientInfo;
	ui.frame_clientDetial->SetMachineName(clientInfo.machineName);
	ui.frame_clientDetial->SetOperatorName(clientInfo.operatorName);
	ui.frame_clientDetial->SetManagerName(clientInfo.managerName);
	ui.frame_clientDetial->SetTotalRecive(clientInfo.nTotalRecive);
	ui.frame_clientDetial->SetTotalRetrieve(clientInfo.nTotalRetrieve);
	ui.frame_clientDetial->SetTableReciveDetial(clientInfo.operatorName);

	m_pClientInfo[m_nSelClientNo]->SetClientInfo(clientInfo);*/
}


void ManagementClient::InitStatusBar(void)
{
	QLabel *per1 = new QLabel("研制单位：", this);

	QLabel *per2 = new QLabel("深圳市中钞科信金融科技有限公司", this);

	QLabel *per3 = new QLabel("", this);

	statusBar()->addPermanentWidget(per1); 

	statusBar()->addPermanentWidget(per2,2);

	statusBar()->insertPermanentWidget(2, per3,3);
}

void ManagementClient::InitClientInfo(void)
{
	m_pClientInfo[0] = ui.frame_clintInfo00;
	m_pClientInfo[1] = ui.frame_clintInfo01;
	m_pClientInfo[2] = ui.frame_clintInfo02;
	m_vecDicMachine.clear();
	GlobalParam::dal.m_DataBaseOperator.GetDicMachineList(m_vecDicMachine);
	for (int i = 0; i < m_vecDicMachine.size(); i++)
	{
		connect(m_pClientInfo[i], SIGNAL(ClientInfoChecked(int)), this, SLOT(ClientInfoChecked(int)));
		m_pClientInfo[i]->m_nClientNo = i;
		
		auto iter = m_vecDicMachine.at(i);
		GlobalParam::clintInfo[i].nMachineId = iter.MACHINE_ID;

		GlobalParam::clintInfo[i].machineName = QString::fromStdString(iter.MACHINE_NAME);
		m_pClientInfo[i]->SetClientInfo(GlobalParam::clintInfo[i]);
	}
}

void ManagementClient::InitQssInfo(void)
{
	m_skin = zxqsSkinThemeInstance();
	m_skin->load();
}

void ManagementClient::SetClientInfoEnabled(bool bEnabled /*= false*/)
{
	for (int i = 0; i < CLIENT_NUM_INFO; i++)
	{
		m_pClientInfo[i]->setEnabled(bEnabled);
	}
}

void ManagementClient::WriteMsgList(QString msg)
{
	QString time = QDateTime::currentDateTime().toString("hh:mm:ss");
/*	int count = ui.listWidget->count();
	QListWidgetItem *item = new QListWidgetItem;
	item->setText(time + "   " + msg);
	if (msg != NULL)
	{
		ui.listWidget->insertItem(count + 1, item);
		GlobalParam::WriteLog(msg, "listLog");
	}
	ui.listWidget->scrollToBottom();*/
}
