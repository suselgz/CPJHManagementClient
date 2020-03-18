#pragma once

#include <QFrame>
#include "ui_ClientDetial.h"

class ClientDetial : public QFrame
{
	Q_OBJECT

public:
	ClientDetial(QWidget *parent = Q_NULLPTR);
	~ClientDetial();
	void SetNetConnectStatus(NET_CONNECT_STATUS net_status);
	void SetpatchCode(QString patchCode);
	void SetproductType(QString productType);
	void SetpreSetNum(QString preSetNum);
	void SetdestroyNum(int destroyNum);
	void SetdestroyBox(int destroyBox);
	void SetdestroyBag(int destroyBag);
	void SetTableReciveDetial(QString operatorName);

private:
	Ui::ClientDetial ui;
	
	
};
