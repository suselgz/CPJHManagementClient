#include "stdafx.h"
#include "ManagementClient.h"

ManagementClient::ManagementClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	InitStatusBar();
	InitQssInfo();
	InitClientAndDetialInfo();
	SetClientInfoEnabled(true);
	m_nSelClientNo = 0;
	m_OnlineNetMsg = new QOnlineNetMsg();
	m_OnlineNetMsg->InitSNetwork();
	connect(m_OnlineNetMsg, &QOnlineNetMsg::SendNetConnected, this, &ManagementClient::RevNetConnectStatus);
	connect(m_OnlineNetMsg, &QOnlineNetMsg::SendRevNumToPm, this, &ManagementClient::SetClientInfo);
	showMaximized();
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
	this->setWindowState(Qt::WindowFullScreen);
}

ManagementClient::~ManagementClient()
{
	delete m_skin;
	delete m_OnlineNetMsg;
}

void ManagementClient::on_pushButton_Exit_clicked(void)
{
	close();
}

void ManagementClient::ClientInfoChecked(int nClientNo)
{
	//test

	NET_MSG_MODIFY_INFO* modify_info = new NET_MSG_MODIFY_INFO;
	cv::Mat srcImg = cv::imread("1.jpg");
	modify_info->nSerial = 100000;
	int a = srcImg.step;
	modify_info->dataLen = srcImg.cols*srcImg.rows*srcImg.channels();
	modify_info->imgWidth = srcImg.cols;
	modify_info->imgHeight = srcImg.rows;
	modify_info->imgStep = srcImg.step;
	modify_info->nCheckNum = 9;
	modify_info->checkResultType = 101;
	modify_info->modifyResult = 0;
	modify_info->packetDataBuf = new BYTE[modify_info->dataLen];
	memcpy(modify_info->packetDataBuf, srcImg.data, modify_info->dataLen);
	
	GlobalParam::netMsg[0].push_back(modify_info);
	//test

	if (GlobalParam::netMsg[nClientNo].empty())
	{
		return;  //队列无数据则返回。
	}
	BagModify* bagModify = new BagModify(nClientNo);
	bagModify->setWindowModality(Qt::ApplicationModal);
	connect(bagModify, SIGNAL(sendUpdataToMain(int)), this, SLOT(RevModifyWidgetInfo(int)));
	bagModify->show();
}

void ManagementClient::RevNetConnectStatus(NET_CONNECT_STATUS net_status)
{
	m_ClientDetial->SetNetConnectStatus(net_status);
}

void ManagementClient::RevModifyWidgetInfo(int nClientNo)
{
	switch (nClientNo)
	{
	case NET_CONNECT_MACHINE_CODE::MACHINE1_CODE:
		GlobalParam::clintInfo[0].nTotalRetrieve--;
		SetClientInfo(GlobalParam::clintInfo[0], NET_CONNECT_MACHINE_CODE::MACHINE1_CODE);
		break;
	case NET_CONNECT_MACHINE_CODE::MACHINE2_CODE:
		GlobalParam::clintInfo[1].nTotalRetrieve--;
		SetClientInfo(GlobalParam::clintInfo[1], NET_CONNECT_MACHINE_CODE::MACHINE2_CODE);
		break;
	case NET_CONNECT_MACHINE_CODE::MACHINE3_CODE:
		GlobalParam::clintInfo[2].nTotalRetrieve--;
		SetClientInfo(GlobalParam::clintInfo[2], NET_CONNECT_MACHINE_CODE::MACHINE3_CODE);
		break;
	default:
		break;
	}
}

void ManagementClient::InitStatusBar(void)
{
	QLabel *per1 = new QLabel("研制单位：", this);

	QLabel *per2 = new QLabel("深圳市中钞科信金融科技有限公司", this);

	QLabel *per3 = new QLabel("", this);

	statusBar()->addPermanentWidget(per1);

	statusBar()->addPermanentWidget(per2, 2);

	statusBar()->insertPermanentWidget(2, per3, 3);
}

void ManagementClient::InitClientAndDetialInfo(void)
{
	m_ClientDetial = ui.frame_clientDetial;

	m_pClientInfo[0] = ui.frame_clintInfo00;
	m_pClientInfo[1] = ui.frame_clintInfo01;
	m_pClientInfo[2] = ui.frame_clintInfo02;
	GET_REFRESH_INFO refresh_info;
	if (!GlobalParam::dal.m_DataBaseOperator.GetRefreshInfo(refresh_info))
	{
		//读取基础数据失败
	}
	m_ClientDetial->SetpatchCode(refresh_info.patchCode);
	m_ClientDetial->SetproductType(refresh_info.productName);
	m_ClientDetial->SetpreAmount(QString::number(refresh_info.preSetAmount));
	m_ClientDetial->SetdestroyBox(refresh_info.destroyBoxNum);
	m_ClientDetial->SetdestroyBag(refresh_info.destroyBagNum);
	m_ClientDetial->SetdestroyNum(refresh_info.destroyNum);
	for (int i = 0; i < refresh_info.operatorCount; i++)
	{
		m_pClientInfo[i]->m_nClientNo = i;
		connect(m_pClientInfo[i], SIGNAL(ClientInfoChecked(int)), this, SLOT(ClientInfoChecked(int)));
		GlobalParam::clintInfo[i].nMachineId = refresh_info.operator_info[i].machineID;
		GlobalParam::clintInfo[i].machineName = refresh_info.operator_info[i].machineName;
		GlobalParam::clintInfo[i].nOperatorId = refresh_info.operator_info[i].operatorID;
		GlobalParam::clintInfo[i].operatorName = refresh_info.operator_info[i].operatorName;
		m_pClientInfo[i]->SetClientInfo(GlobalParam::clintInfo[i]);
	}
}

void ManagementClient::SetClientInfo(CLIENT_INFO client_info, int machineCode)
{
	switch (machineCode)
	{
	case NET_CONNECT_MACHINE_CODE::MACHINE1_CODE:
		m_pClientInfo[0]->SetClientInfo(client_info);
		break;
	case NET_CONNECT_MACHINE_CODE::MACHINE2_CODE:
		m_pClientInfo[1]->SetClientInfo(client_info);
		break;
	case NET_CONNECT_MACHINE_CODE::MACHINE3_CODE:
		m_pClientInfo[2]->SetClientInfo(client_info);
		break;
	default:
		break;
	}
}

void ManagementClient::InitQssInfo(void)
{
	m_skin = zxqsSkinThemeInstance();
	if (!m_skin->LoadSkin())
	{
		std::string err = m_skin->GetLastErr();
		QString qs = QString::fromLocal8Bit(err.c_str());
		QMessageBox::information(NULL, "注意", qs);
	}
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
