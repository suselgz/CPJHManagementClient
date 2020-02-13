#pragma once
#include <QGraphicsView>
#include "DispWidget/DispWidgetExport.h"
#include "QMap"

class QDispViewPrivate;
class DLL_DISP_WIDGET_API QDispView : public QGraphicsView
{
	Q_OBJECT
public:
	QDispView(QWidget *parent = Q_NULLPTR);
	~QDispView();

	qreal Zoom() const;
	void setZoom(qreal dZoom);
	void ZoomIn();
	void ZoomOut();
	void ZoomFit();
	void ZoomFitWidth();
	void ZoomFitHeight();
	void setAutoZoomFit(bool autoZoomFit);
	bool autoZoomFit();
signals:
	void viewPortAreaChanged();
protected:
	virtual void wheelEvent(QWheelEvent *event);
	virtual void scrollContentsBy(int dx, int dy);


	virtual void resizeEvent(QResizeEvent *event) override;

private:
	QDispViewPrivate* d_ptr;
};

class DLL_DISP_WIDGET_API QDispViewViewAeraBinding
{
public:
	void attachDispView(QDispView* dispView);
	void detachDispView(QDispView* dispView);
private:
	QMap<QDispView*, QMetaObject::Connection> m_dispViews;
	bool m_isUpdating = false;
};