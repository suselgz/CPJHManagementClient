#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ManagementClient.h"
#include "ClientInfo.h"
#include "DAL.h"
#include "zxqsSkinTheme.h"
#include "BagModify.h"
#include "QOnlineNetMsg.h"
#include "ClientDetial.h"
class ManagementClient : public QMainWindow
{
	Q_OBJECT

public:
	ManagementClient(QWidget *parent = Q_NULLPTR);
	~ManagementClient();
private:
	void WriteMsgList(QString msg);
private:
	Ui::ManagementClientClass ui;
	ClientInfo * m_pClientInfo[CLIENT_NUM_INFO];
	int m_nSelClientNo;
	DAL m_dal;
	zxqsSkinTheme* m_skin;
	BagModify* m_bagModify;
	QOnlineNetMsg* m_OnlineNetMsg;
	ClientDetial* m_ClientDetial;
	QVector<DIC_MACHINE> m_vecDicMachine;
	void InitStatusBar(void);
	void InitClientAndDetialInfo(void);
	void InitQssInfo(void);
	void SetClientInfoEnabled(bool bEnabled = false);
private slots:
	void on_pushButton_Exit_clicked(void);
	void ClientInfoChecked(int nClientNo);
	void RevNetConnectStatus(NET_CONNECT_STATUS net_status);
	void SetClientInfo(CLIENT_INFO client_info, int machineCode);
	void RevModifyWidgetInfo(int nClientNo);
};
