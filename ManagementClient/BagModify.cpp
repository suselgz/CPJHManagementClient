#include "stdafx.h"
#include "BagModify.h"

BagModify::BagModify(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	InitDispScene();
	this->setWindowFlags(Qt::Widget | Qt::WindowStaysOnTopHint);
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
