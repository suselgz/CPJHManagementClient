#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ManagementClient.h"
#include "ClientInfo.h"
#include "DAL.h"
#include "zxqsSkinTheme.h"
#include "BagModify.h"
#include "QOnlineNetMsg.h"
#include "ClientDetial.h"
#include <QTimer>
#include "RefreshThread.h"
class ManagementClient : public QMainWindow
{
	Q_OBJECT

public:
	ManagementClient(QWidget *parent = Q_NULLPTR);
	~ManagementClient();
private:
	void WriteMsgList(QString msg);
private:
	QLabel *m_currentTimeLabel;
	Ui::ManagementClientClass ui;
	ClientInfo * m_pClientInfo[CLIENT_NUM_INFO];
	int m_nOperatorCount;
	bool m_bRefresh;
	DAL m_dal;
	zxqsSkinTheme* m_skin;
	BagModify* m_bagModify;
	QOnlineNetMsg* m_OnlineNetMsg;
	ClientDetial* m_ClientDetial;
	RefreshThread* m_refreshThread;
	QTimer *m_timer;
	void InitStatusBar(void);
	void InitQssInfo(void);
	void SetClientInfoEnabled(bool bEnabled = false);
	void Test();
private slots:
    void TimeOut();
	void RevClientAndDetialInfo(GET_REFRESH_INFO refresh_info);
	void on_pushButton_Exit_clicked(void);
	void ClientInfoChecked(int nClientNo);
	void RevNetConnectStatus(NET_CONNECT_STATUS net_status);
	void SetClientInfo(CLIENT_INFO client_info, int machineCode);
	void RevModifyWidgetInfo(NET_MSG_MODIFY_INFO* modify_info,int nClientNo);
};
