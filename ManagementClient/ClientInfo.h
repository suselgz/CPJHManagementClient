#pragma once

#include <QFrame>
#include "ui_ClientInfo.h"
#include <QTimer>
class ClientInfo : public QFrame
{
	Q_OBJECT

public:
	ClientInfo(QWidget *parent = Q_NULLPTR);
	~ClientInfo();
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseDoubleClickEvent(QMouseEvent *event);
	
	int  m_nClientNo;
	
	void SetLight(bool nRct);
	void SetChecked(bool bChecked);
	void SetClientInfo(CLIENT_INFO clientInfo);
	void ModifyTotalRecive(int nValue);
	void ModifyTotalRetrieve(int nValue);
	void ReSet(void);
public slots:
	void TimeOut();
private:
	Ui::ClientInfo ui;
	QTimer *m_timer;
	bool m_bSel;
signals:
	void ClientInfoChecked(int nClientNo);
	void ClientInfoDoubleClick(int nClientNo);
};
