#ifndef DispScene_h__
#define DispScene_h__

#pragma once

#include <QGraphicsScene>
#include <QGraphicsSceneEvent>
#include "DispWidget/DispData.h"
#include "DispWidget/DispItem.h"
#include "DispWidget/DispWidgetExport.h"

enum ITEM_FLAG
{
	ITEM_MOVE_USING_ALT_KEY		= 0x01,
};

class DLL_DISP_WIDGET_API QDispScene : public QGraphicsScene
{
	Q_OBJECT
public:
public:
	QDispScene(QObject* parent = nullptr) : QGraphicsScene(parent) { }
	virtual ~QDispScene(){}
	
public:
	virtual QDispItem* AddItem(const QDispData& data) = 0;
	virtual void UpdateItem(QDispItem* pItem) = 0;
	virtual QDispItem* FindItem(int nUniqueID) const = 0;
	virtual bool DeleteItem(const QDispItem* pItem) = 0;
	virtual bool DeleteItem(int nUniqueID) = 0;
	virtual void ShowImage(QImage* pImage, bool bCopyData = false) = 0;
	virtual void ShowImage(const QPixmap& pImage, bool bCopyData = false) = 0;
	virtual uint GetPixelValue(const QPointF& point) const = 0;

	virtual void SetItemFlags(unsigned int flag) = 0;
	virtual unsigned int GetItemFlags() = 0;

	virtual void StartInsert(const QDispData& data) = 0;
	virtual void StartInsert(const QDispData& data, const QRectF& limitRect) = 0;
	virtual void StartInsert(const QDispData& data, const QPolygonF& limitRegion) = 0;
	virtual void StopInsert() = 0;
	virtual void CancelInsert() = 0;

	virtual QList<QDispItem*> GetItems() const = 0;
	virtual QList<QDispItem*> GetSelectItems() const = 0;

signals:
	void InsertBegin(const QDispData& data);
	void InsertEnd(const QDispItem* item);
	void InsertCanceled(const QDispData& data);

	void onMouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent);
	void onMouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
	void onMousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
	void onMouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

extern "C" DLL_DISP_WIDGET_API QDispScene* CreateQDispScenceInstance(QObject* parent = nullptr);


#endif // DispScene_h__