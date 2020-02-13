#pragma once

#include <QFrame>
#include "ui_ClientDetial.h"
class ClientDetial : public QFrame
{
	Q_OBJECT

public:
	ClientDetial(QWidget *parent = Q_NULLPTR);
	~ClientDetial();
	void SetMachineName(QString machineName);
	void SetOperatorName(QString operatorName);
	void SetManagerName(QString managerName);
	void SetTotalRecive(int nTotalRecive);
	void SetTotalRetrieve(int nTotalRetrieve);
	void SetTableReciveDetial(QString operatorName);
private:
	Ui::ClientDetial ui;
	
};
