#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ManagementClient.h"
#include "ClientInfo.h"
#include "DAL.h"



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
	
	QVector<DIC_MACHINE> m_vecDicMachine;
	void InitStatusBar(void);
	void InitClientInfo(void);
	void InitQssInfo(void);
	void SetClientInfoEnabled(bool bEnabled = false);
private slots:
	void on_pushButton_Exit_clicked(void);
	void ClientInfoChecked(int nClientNo);

};
