#include "stdafx.h"
#include "BagModify.h"

BagModify::BagModify(int nClientNo)
{
	ui.setupUi(this);
	InitDispScene();
	this->setWindowFlags(Qt::Widget | Qt::WindowStaysOnTopHint);
	InitModifyInfo(nClientNo);
}

BagModify::~BagModify()
{

}

void BagModify::InitDispScene()
{
	m_scene = CreateQDispScenceInstance(this);
	ui.graphicsView->setScene(m_scene);
	ui.graphicsView->setInteractive(true);
	ui.graphicsView->setMouseTracking(true);
	ui.graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
	ui.graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	ui.graphicsView->setRenderHints(QPainter::SmoothPixmapTransform |
	QPainter::TextAntialiasing |
	QPainter::Antialiasing);
}

void BagModify::InitModifyInfo(int nClientNo)
{
	NET_MSG_MODIFY_INFO* modify_info = GlobalParam::netMsg[nClientNo].front();
	vector<NET_MSG_MODIFY_INFO*>::iterator iter = GlobalParam::netMsg[nClientNo].begin();
	GlobalParam::netMsg[nClientNo].erase(iter);
	ui.label_machineName->setText(GlobalParam::clintInfo[nClientNo].machineName);
	ui.label_serial->setText(QString::number(modify_info->nSerial));
//	ui.comboBox_identfyNum

	cv::Mat srcimg = cv::Mat::zeros(modify_info->imgHeight, modify_info->imgWidth, CV_8UC3);
	memcpy(srcimg.data, modify_info->packetDataBuf, modify_info->dataLen);
	cv::cvtColor(srcimg, srcimg, cv::COLOR_RGB2BGR);

	const uchar *pSrc = (const uchar*)srcimg.data;
	QImage image(pSrc, modify_info->imgWidth, modify_info->imgHeight, modify_info->imgStep, QImage::Format_RGB888);
	m_scene->ShowImage(&image);
	ui.graphicsView->ZoomFit();
}
