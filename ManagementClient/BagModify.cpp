#include "stdafx.h"
#include "BagModify.h"

BagModify::BagModify(int nClientNo)
{
	ui.setupUi(this);
	qRegisterMetaType<NET_MSG_MODIFY_INFO*>("NET_MSG_MODIFY_INFO*");
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
	m_comBoSelIndex = 10;
	//errType
	m_modify_info = GlobalParam::netMsg[nClientNo].front();
	ui.label_machineName->setText(GlobalParam::clintInfo[nClientNo].machineName);
	ui.label_serial->setText(QString::number(m_modify_info->nSerial));

	if (m_modify_info->checkResultType / 1 % 10)
	{
		//把数错误
		ui.checkBox_numErrType->setCheckState(Qt::Checked);
	}
	if (m_modify_info->checkResultType / 10 % 10)
	{
		//夹把
	}
	if (m_modify_info->checkResultType / 100 % 10)
	{
		//信封
		ui.checkBox_envelope->setCheckState(Qt::Checked);
	}
	if (m_modify_info->checkResultType / 1000 % 10)
	{
		//散把
	}

	const uchar *pSrc = (const uchar*)m_modify_info->packetDataBuf;
	QImage image(pSrc, m_modify_info->imgWidth, m_modify_info->imgHeight, m_modify_info->imgStep, QImage::Format_RGB888);
	m_scene->ShowImage(&image);
	ui.graphicsView->ZoomFit();
}

int BagModify::GetErrTypeInfo()
{
	int index = 0;
	if (ui.checkBox_numErrType->isChecked())
	{
		index = index +RESULT_ERRTYPE::NumErr;
	}
	if (ui.checkBox_envelope->isChecked())
	{
		index = index + RESULT_ERRTYPE::Envelope;
	}
	return index;
}

void BagModify::on_pushButton_OK_clicked()
{
	int errType= GetErrTypeInfo();
	NET_MSG_MODIFY_INFO* send_modify_info=new NET_MSG_MODIFY_INFO;
	memset(send_modify_info, 0, sizeof(NET_MSG_MODIFY_INFO));
	send_modify_info->nSerial = m_modify_info->nSerial;
	send_modify_info->nCheckNum = m_comBoSelIndex;
	send_modify_info->checkResultType = errType;
	send_modify_info->modifyFinish = NET_MODIFY_FLAG::MODIFY_OK;
	if (ui.checkBox_delete->isChecked())
	{
		send_modify_info->deleteInfoType = MODIFY_DELETEIMAGE_FLAG;
	}
	vector<NET_MSG_MODIFY_INFO*>::iterator iter = GlobalParam::netMsg[m_nclientNo].begin();
	GlobalParam::netMsg[m_nclientNo].erase(iter);
	sendUpdataToMain(send_modify_info, m_nclientNo);
	delete send_modify_info;
	close();
}

void BagModify::comboBoxSel()
{
	if (ui.comboBox_identfyNum->currentIndex() == 0)      m_comBoSelIndex = 0;
	else if (ui.comboBox_identfyNum->currentIndex() == 1) m_comBoSelIndex = 1;
	else if (ui.comboBox_identfyNum->currentIndex() == 2) m_comBoSelIndex = 2;
	else if (ui.comboBox_identfyNum->currentIndex() == 3) m_comBoSelIndex = 3;
	else if (ui.comboBox_identfyNum->currentIndex() == 4) m_comBoSelIndex = 4;
	else if (ui.comboBox_identfyNum->currentIndex() == 5) m_comBoSelIndex = 5;
	else if (ui.comboBox_identfyNum->currentIndex() == 6) m_comBoSelIndex = 6;
	else if (ui.comboBox_identfyNum->currentIndex() == 7) m_comBoSelIndex = 7;
	else if (ui.comboBox_identfyNum->currentIndex() == 8) m_comBoSelIndex = 8;
	else if (ui.comboBox_identfyNum->currentIndex() == 9) m_comBoSelIndex = 9;
	else if (ui.comboBox_identfyNum->currentIndex() == 10) m_comBoSelIndex = 10;
	else if (ui.comboBox_identfyNum->currentIndex() == 11) m_comBoSelIndex = 11;
	else if (ui.comboBox_identfyNum->currentIndex() == 12) m_comBoSelIndex = 12;
}
