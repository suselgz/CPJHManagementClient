#include "stdafx.h"
#include "RefreshThread.h"

RefreshThread::RefreshThread(QObject *parent)
	: QObject(parent)
{
	qRegisterMetaType<GET_REFRESH_INFO>("GET_REFRESH_INFO");
	m_Exit = false;
}

RefreshThread::~RefreshThread()
{
	m_Exit = true; 
	this->wait(300);
	this->quit();
}

void RefreshThread::run()
{
	while (!m_Exit)
	{
		GET_REFRESH_INFO refresh_info;
		if (GlobalParam::dal.m_DataBaseOperator.GetRefreshInfo(refresh_info))
		{
			sendInfoToMain(refresh_info);
		}
		Sleep(5000);
	}

}