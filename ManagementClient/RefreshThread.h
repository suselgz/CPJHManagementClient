#ifndef CAMERAGRABINPUTTHREAD_H
#define CAMERAGRABINPUTTHREAD_H

#include <QObject>
#include <QThread>
#include "Define.h"

class RefreshThread :public QObject, public QThread
{
	Q_OBJECT

public:
	RefreshThread(QObject *parent);
	~RefreshThread();
	void run();
	/*�߳��˳���ʶ*/
	bool m_Exit;
	/*ƫ����*/
signals:
	void sendInfoToMain(GET_REFRESH_INFO);
private:
};

#endif // CAMERAGRABTHREAD_H
