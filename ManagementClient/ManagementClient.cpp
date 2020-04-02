#include "stdafx.h"
#include "ManagementClient.h"

ManagementClient::ManagementClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	InitStatusBar();
	InitQssInfo();
	SetClientInfoEnabled(true);
//	Test();
	m_currentTimeLabel = new QLabel;
	m_timer = new QTimer(this);
	connect(m_timer, SIGNAL(timeout()), this, SLOT(TimeOut()));
//	m_timer->start(1000);
	m_nOperatorCount = -1;
	m_bRefresh = false;
	m_refreshThread = new RefreshThread(this);
	connect(m_refreshThread, &RefreshThread::sendInfoToMain, this, &ManagementClient::RevClientAndDetialInfo);
	m_refreshThread->start();
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
	delete m_refreshThread;
}

void ManagementClient::TimeOut()
{
	QDateTime CurrentTime = QDateTime::currentDateTime();

	QString Timestr = CurrentTime.toString("当前时间：yyyy年-MM月-dd日 hh:mm:ss "); //设置显示的格式
	m_currentTimeLabel->setText(Timestr);
	statusBar()->addPermanentWidget(m_currentTimeLabel, 2);
}

void ManagementClient::on_pushButton_Exit_clicked(void)
{
	close();
}

void ManagementClient::ClientInfoChecked(int nClientNo)
{
	if (GlobalParam::netMsg[nClientNo].empty())
	{
		QString operation = "open";
		PCWSTR ope= reinterpret_cast<LPCWSTR>(operation.data());
		QString strAppName = "C:\\Program Files\\RealVNC\\VNC4\\vncviewer.exe";
		PCWSTR appName = reinterpret_cast<LPCWSTR>(strAppName.data());
		QString strPingName = "C:\\Windows\\System32\\ping.exe";
		PCWSTR pingName = reinterpret_cast<LPCWSTR>(strPingName.data());

		switch (nClientNo)
		{
		case NET_CONNECT_MACHINE_CODE::MACHINE1_CODE:
			ShellExecute(NULL, ope, appName, reinterpret_cast<LPCWSTR>(GlobalParam::dbSetting.macine1IP.data()) , NULL, SW_SHOW);
			break;
		case NET_CONNECT_MACHINE_CODE::MACHINE2_CODE:
			ShellExecute(NULL, ope, appName, reinterpret_cast<LPCWSTR>(GlobalParam::dbSetting.macine2IP.data()), NULL, SW_SHOW);
			break;
		case NET_CONNECT_MACHINE_CODE::MACHINE3_CODE:
			ShellExecute(NULL, ope, appName, reinterpret_cast<LPCWSTR>(GlobalParam::dbSetting.macine3IP.data()), NULL, SW_SHOW);
			break;
		}
		return;  //队列无数据则返回。
	}
	int frame_x = ui.frame_modify->x();
	int frame_y = ui.frame_modify->y();
	int frame_width = ui.frame_modify->width();
	int frame_height = ui.frame_modify->height();
	BagModify* bagModify= new BagModify(nClientNo);
	bagModify->resize(frame_width, frame_height);
	bagModify->setWindowModality(Qt::ApplicationModal);
	connect(bagModify, SIGNAL(sendUpdataToMain(NET_MSG_MODIFY_INFO*,int)), this, SLOT(RevModifyWidgetInfo(NET_MSG_MODIFY_INFO*,int)));
	bagModify->show();
	bagModify->move(frame_x, frame_y);
}

void ManagementClient::RevNetConnectStatus(NET_CONNECT_STATUS net_status)
{
	m_ClientDetial->SetNetConnectStatus(net_status);
}

void ManagementClient::RevModifyWidgetInfo(NET_MSG_MODIFY_INFO* modify_info, int nClientNo)
{
	switch (nClientNo)
	{
	case NET_CONNECT_MACHINE_CODE::MACHINE1_CODE:
		GlobalParam::clintInfo[nClientNo].nTotalRetrieve--;
		SetClientInfo(GlobalParam::clintInfo[nClientNo], NET_CONNECT_MACHINE_CODE::MACHINE1_CODE);
		break;
	case NET_CONNECT_MACHINE_CODE::MACHINE2_CODE:
		GlobalParam::clintInfo[nClientNo].nTotalRetrieve--;
		SetClientInfo(GlobalParam::clintInfo[nClientNo], NET_CONNECT_MACHINE_CODE::MACHINE2_CODE);
		break;
	case NET_CONNECT_MACHINE_CODE::MACHINE3_CODE:
		GlobalParam::clintInfo[nClientNo].nTotalRetrieve--;
		SetClientInfo(GlobalParam::clintInfo[nClientNo], NET_CONNECT_MACHINE_CODE::MACHINE3_CODE);
		break;
	default:
		break;
	}
	m_OnlineNetMsg->SendMsgToMachine(modify_info, nClientNo);
	if (GlobalParam::netMsg[nClientNo].empty())
	{
		m_pClientInfo[nClientNo]->SetLight(false);
	}
}

void ManagementClient::InitStatusBar(void)
{
	QLabel *per1 = new QLabel("研制单位：", this);
	QLabel *per2 = new QLabel("深圳市中钞科信金融科技有限公司", this);
	statusBar()->addPermanentWidget(per1);
	statusBar()->addPermanentWidget(per2, 2);
}

void ManagementClient::RevClientAndDetialInfo(GET_REFRESH_INFO refresh_info)
{
	m_ClientDetial->SetpatchCode(refresh_info.patchCode);
	m_ClientDetial->SetproductType(refresh_info.productName);
	QString preSetAmount = QString::number(refresh_info.preSetAmount);
	size_t len = preSetAmount.length();
	 for (int index = (int)len - 3; index > 0; index -= 3)
	 {
		 preSetAmount.insert(index, ",");
	 }
	m_ClientDetial->SetpreAmount(preSetAmount);
	m_ClientDetial->SetdestroyBox(refresh_info.destroyBoxNum);
	m_ClientDetial->SetdestroyBag(refresh_info.destroyBagNum);
	m_ClientDetial->SetdestroyNum(refresh_info.destroyNum);
	if (m_nOperatorCount != refresh_info.operatorCount)
	{
		m_bRefresh = true;
	}
	for (int i = 0; i < refresh_info.operatorCount; i++)
	{
		if (m_bRefresh)
		{
			m_pClientInfo[i]->m_nClientNo = i;
			connect(m_pClientInfo[i], SIGNAL(ClientInfoChecked(int)), this, SLOT(ClientInfoChecked(int)));
		}
		GlobalParam::clintInfo[i].nMachineId = refresh_info.operator_info[i].machineID;
		GlobalParam::clintInfo[i].machineName = refresh_info.operator_info[i].machineName;
		GlobalParam::clintInfo[i].nOperatorId = refresh_info.operator_info[i].operatorID;
		GlobalParam::clintInfo[i].operatorName = refresh_info.operator_info[i].operatorName;
		m_pClientInfo[i]->SetClientInfo(GlobalParam::clintInfo[i]);
	}
	m_bRefresh = false;
	m_nOperatorCount = refresh_info.operatorCount;
}

void ManagementClient::SetClientInfo(CLIENT_INFO client_info, int machineCode)
{
	switch (machineCode)
	{
	case NET_CONNECT_MACHINE_CODE::MACHINE1_CODE:
		m_pClientInfo[machineCode]->SetClientInfo(client_info);
		break;
	case NET_CONNECT_MACHINE_CODE::MACHINE2_CODE:
		m_pClientInfo[machineCode]->SetClientInfo(client_info);
		break;
	case NET_CONNECT_MACHINE_CODE::MACHINE3_CODE:
		m_pClientInfo[machineCode]->SetClientInfo(client_info);
		break;
	default:
		break;
	}
	if (GlobalParam::netMsg[machineCode].empty())
	{
		m_pClientInfo[machineCode]->SetLight(false);
	}
	else
	{
		m_pClientInfo[machineCode]->SetLight(true);
	}

}

void ManagementClient::InitQssInfo(void)
{
	m_ClientDetial = ui.frame_clientDetial;
	m_pClientInfo[0] = ui.frame_clintInfo00;
	m_pClientInfo[1] = ui.frame_clintInfo01;
	m_pClientInfo[2] = ui.frame_clintInfo02;
	ui.frame_clintInfo00->setStyleSheet("background-color: rgb(200,240,210);");
	ui.frame_clintInfo01->setStyleSheet("background-color: rgb(200,240,210);");
	ui.frame_clintInfo02->setStyleSheet("background-color: rgb(200,240,210);");
//	ui.frame_clintInfo03->setStyleSheet("background-color: rgb(200,240,210);");
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

void ManagementClient::Test()
{
	NET_MSG_MODIFY_INFO* modify_info = new NET_MSG_MODIFY_INFO;
	cv::Mat srcImg = cv::imread("1.jpg");
	cv::cvtColor(srcImg, srcImg, cv::COLOR_RGB2BGR);
	modify_info->nSerial = 0;
	modify_info->dataLen = srcImg.cols*srcImg.rows*srcImg.channels();
	modify_info->imgWidth = srcImg.cols;
	modify_info->imgHeight = srcImg.rows;
	modify_info->imgStep = srcImg.step;
	modify_info->nCheckNum = 9;
	modify_info->checkResultType = 100;
	modify_info->modifyFinish = 0;

	for (int i = 0; i < 1; i++)
	{
		modify_info->nSerial = i;
		GlobalParam::netMsg[0].push(*modify_info);
		GlobalParam::netMsg[1].push(*modify_info);
		GlobalParam::netMsg[2].push(*modify_info);

		GlobalParam::clintInfo[0].nTotalRecive++;
		GlobalParam::clintInfo[0].nTotalRetrieve++;
		GlobalParam::clintInfo[1].nTotalRecive++;
		GlobalParam::clintInfo[1].nTotalRetrieve++;
		GlobalParam::clintInfo[2].nTotalRecive++;
		GlobalParam::clintInfo[2].nTotalRetrieve++;
	}
	SetClientInfo(GlobalParam::clintInfo[0], NET_CONNECT_MACHINE_CODE::MACHINE1_CODE);
	SetClientInfo(GlobalParam::clintInfo[1], NET_CONNECT_MACHINE_CODE::MACHINE2_CODE);
	SetClientInfo(GlobalParam::clintInfo[2], NET_CONNECT_MACHINE_CODE::MACHINE3_CODE);

	m_pClientInfo[0]->SetLight(true);
	m_pClientInfo[1]->SetLight(true);
	m_pClientInfo[2]->SetLight(true);
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
