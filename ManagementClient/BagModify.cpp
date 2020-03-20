#include "stdafx.h"
#include "BagModify.h"

BagModify::BagModify(int nClientNo)
{
	ui.setupUi(this);
	m_nclientNo = nClientNo;
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
	//number
	connect(ui.comboBox_identfyNum, SIGNAL(currentIndexChanged(QString)), this, SLOT(comboBoxSel()));
	ui.comboBox_identfyNum->setCurrentIndex(10);
	//errType
	ui.checkBox_numErrType->setCheckState(Qt::Checked);
	ui.checkBox_envelope->setCheckState(Qt::Checked);
	if (ui.checkBox_numErrType->isChecked())
	{
		
	}

	NET_MSG_MODIFY_INFO* modify_info = GlobalParam::netMsg[nClientNo].front();
	ui.label_machineName->setText(GlobalParam::clintInfo[nClientNo].machineName);
	ui.label_serial->setText(QString::number(modify_info->nSerial));
//	ui.comboBox_identfyNum

// 	cv::Mat srcimg = cv::Mat::zeros(modify_info->imgHeight, modify_info->imgWidth, CV_8UC3);
// 	memcpy(srcimg.data, modify_info->packetDataBuf, modify_info->dataLen);
// 	cv::cvtColor(srcimg, srcimg, cv::COLOR_RGB2BGR);

	const uchar *pSrc = (const uchar*)modify_info->packetDataBuf;
	QImage image(pSrc, modify_info->imgWidth, modify_info->imgHeight, modify_info->imgStep, QImage::Format_RGB888);
	m_scene->ShowImage(&image);
	ui.graphicsView->ZoomFit();
}

void BagModify::on_pushButton_OK_clicked()
{
	vector<NET_MSG_MODIFY_INFO*>::iterator iter = GlobalParam::netMsg[m_nclientNo].begin();
	GlobalParam::netMsg[m_nclientNo].erase(iter);
	sendUpdataToMain(m_nclientNo);
	close();
}

void BagModify::comboBoxSel()
{
	int selIndex = -1;
	if (ui.comboBox_identfyNum->currentIndex() == 0)      selIndex = 0;
	else if (ui.comboBox_identfyNum->currentIndex() == 1) selIndex = 1;
	else if (ui.comboBox_identfyNum->currentIndex() == 2) selIndex = 2;
	else if (ui.comboBox_identfyNum->currentIndex() == 3) selIndex = 3;
	else if (ui.comboBox_identfyNum->currentIndex() == 4) selIndex = 4;
	else if (ui.comboBox_identfyNum->currentIndex() == 5) selIndex = 5;
	else if (ui.comboBox_identfyNum->currentIndex() == 6) selIndex = 6;
	else if (ui.comboBox_identfyNum->currentIndex() == 7) selIndex = 7;
	else if (ui.comboBox_identfyNum->currentIndex() == 8) selIndex = 8;
	else if (ui.comboBox_identfyNum->currentIndex() == 9) selIndex = 9;
	else if (ui.comboBox_identfyNum->currentIndex() == 10) selIndex = 10;
	else if (ui.comboBox_identfyNum->currentIndex() == 11) selIndex = 11;
	else if (ui.comboBox_identfyNum->currentIndex() == 12) selIndex = 12;
}
