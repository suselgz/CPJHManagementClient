#pragma once
#include <QGraphicsItem>
#include "DispWidget/DispData.h"
#include <QCursor>
#include <QPainter>

#define TRACKER_RANGE			5
#define TRACKER_LEN				(TRACKER_RANGE * 2 + 1)

class QGraphicHook;

class DLL_DISP_WIDGET_API QGraphic
{
public:
	QGraphic();
	QGraphic(QDispData* pData);

	virtual ~QGraphic(){}

public:
	virtual bool SetData(QDispData* pData);
	virtual QGraphicsItem* GetQGrapchicItem();

	virtual int GetHandleCount()  const;
	virtual int GetHideHandleCount()  const;
	virtual QRectF GetHandleTrackerRect(int nHandleIndex)  const;
	virtual QCursor GetHandleCursor(int nHandleIndex)  const;

	virtual int HitTest(const QPointF& point)  const;
	virtual void MoveHandleTo(int nHandleIndex, const QPointF& point, const QPointF& dif);
	virtual void MoveTo(const QPointF& dif);

	virtual void Draw(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	virtual void DrawTracker(QPainter* painter);
	virtual void DrawCaption(QPainter* painter);

public:
	QDispData* GetData() { return m_pData; }
	QRectF MakeTrackerRect(const QPointF& trackerPoint)  const;
	QRectF MakeTrackerRect(qreal x, qreal y)  const;
	QRectF MakeTrackerRect(QPointF pt1, QPointF pt2)  const;
	bool IsCaptionValid() const;
	bool IsMovable() const;
	bool IsSelectable() const;

	bool IsInserting() const { return m_isInsert; }
	void SetInsert(bool isInsert){ m_isInsert = isInsert; }

	void setHook(QGraphicHook* hook) { m_hook = hook; }
	QGraphicHook* hook() const { return m_hook; }
	
	void setZoomView(QGraphicsView* pView) { m_zoomView = pView; }
	QGraphicsView* getZoomView() { return m_zoomView; }
protected:
	QDispData *m_pData;
	QRectF     m_rectCaption;
	QGraphicHook* m_hook = nullptr;
	bool m_isInsert = false;
	QGraphicsView* m_zoomView = nullptr;
};

class QGraphicHook
{
public:
	virtual void itemResize() = 0;
	virtual void itemMove() = 0;
	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) = 0;
	virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event) = 0;
	virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) = 0;
	virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event) = 0;
	virtual void dropEvent(QGraphicsSceneDragDropEvent *event) = 0;
	virtual void focusInEvent(QFocusEvent *event) = 0;
	virtual void focusOutEvent(QFocusEvent *event) = 0;
	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) = 0;
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) = 0;
	virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event) = 0;
	virtual void inputMethodEvent(QInputMethodEvent *event) = 0;
	virtual void inputMethodQuery(Qt::InputMethodQuery query) const = 0;
	virtual void itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) = 0;
	virtual void keyPressEvent(QKeyEvent *event) = 0;
	virtual void keyReleaseEvent(QKeyEvent *event) = 0;
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) = 0;
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) = 0;
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) = 0;
	virtual void sceneEvent(QEvent *event) = 0;
	virtual void sceneEventFilter(QGraphicsItem *watched, QEvent *event) = 0;
	virtual void wheelEvent(QGraphicsSceneWheelEvent *event) = 0;
};

template <class T = QGraphicsItem>
class QCustomGraphicItem : public QGraphic, public T
{
	virtual QRectF boundingRect() const
	{
		QRectF rc;
		if (this->IsCaptionValid())
		{
			rc = m_rectCaption.united(T::boundingRect());
		}
		else
		{
			rc = T::boundingRect();
		}
		int handleCount = GetHandleCount() - GetHideHandleCount();
		for (int i = 0; i < handleCount; ++i)
		{
			rc = rc.united(GetHandleTrackerRect(i));
		}
		return rc;
	}
	virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
	{
		if (m_hook) m_hook->contextMenuEvent(event);
		return T::contextMenuEvent(event);
	}
	virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event)
	{
		if (m_hook) m_hook->dragEnterEvent(event);
		return T::dragEnterEvent(event);
	}
	virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
	{
		if (m_hook) m_hook->dragLeaveEvent(event);
		return T::dragLeaveEvent(event);
	}
	virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event)
	{
		if (m_hook) m_hook->dragMoveEvent(event);
		return T::dragMoveEvent(event);
	}
	virtual void dropEvent(QGraphicsSceneDragDropEvent *event)
	{
		if (m_hook) m_hook->dropEvent(event);
		return T::dropEvent(event);
	}
	virtual void focusInEvent(QFocusEvent *event)
	{
		if (m_hook) m_hook->focusInEvent(event);
		return T::focusInEvent(event);
	}
	virtual void focusOutEvent(QFocusEvent *event)
	{
		if (m_hook) m_hook->focusOutEvent(event);
		return T::focusOutEvent(event);
	}
	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event)
	{
		if (m_hook) m_hook->hoverEnterEvent(event);
		return T::hoverEnterEvent(event);
	}
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
	{
		if (m_hook) m_hook->hoverLeaveEvent(event);
		return T::hoverLeaveEvent(event);
	}
	virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event)
	{
		if (m_hook) m_hook->hoverMoveEvent(event);
		return T::hoverMoveEvent(event);
	}
	virtual void inputMethodEvent(QInputMethodEvent *event)
	{
		if (m_hook) m_hook->inputMethodEvent(event);
		return T::inputMethodEvent(event);
	}
	virtual QVariant inputMethodQuery(Qt::InputMethodQuery query) const
	{
		if (m_hook) m_hook->inputMethodQuery(query);
		return T::inputMethodQuery(query);
	}
	virtual QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
	{
		if (m_hook) m_hook->itemChange(change, value);
		return T::itemChange(change, value);
	}
	virtual void keyPressEvent(QKeyEvent *event)
	{
		if (m_hook) m_hook->keyPressEvent(event);
		return T::keyPressEvent(event);
	}
	virtual void keyReleaseEvent(QKeyEvent *event)
	{
		if (m_hook) m_hook->keyReleaseEvent(event);
		return T::keyReleaseEvent(event);
	}
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
	{
		if (m_hook) m_hook->mouseDoubleClickEvent(event);
		return T::mouseDoubleClickEvent(event);
	}
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
	{
		if (m_hook) m_hook->mouseMoveEvent(event);
		return T::mouseMoveEvent(event);
	}
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event)
	{
		if (m_hook) m_hook->mousePressEvent(event);
		return T::mousePressEvent(event);
	}
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
	{
		if (m_hook) m_hook->mouseReleaseEvent(event);
		return T::mouseReleaseEvent(event);
	}
	virtual bool sceneEvent(QEvent *event)
	{
		if (m_hook) m_hook->sceneEvent(event);
		return T::sceneEvent(event);
	}
	virtual bool sceneEventFilter(QGraphicsItem *watched, QEvent *event)
	{
		if (m_hook) m_hook->sceneEventFilter(watched, event);
		return T::sceneEventFilter(watched, event);
	}
	virtual void wheelEvent(QGraphicsSceneWheelEvent *event)
	{
		if (m_hook) m_hook->wheelEvent(event);
		return T::wheelEvent(event);
	}
};

class DLL_DISP_WIDGET_API QDispItemFactory
{
public:
	typedef QGraphic* (*Creator)();
	typedef std::map<int, Creator> CreatorRegistry;

	static void RegisterItem(int dispType, Creator creator);
	static QGraphic* CreateItem(int dispType);
private:
	static CreatorRegistry& Registry();
};

class DLL_DISP_WIDGET_API QDispItemRegisterer {
public:
	QDispItemRegisterer(int dispType, QGraphic* (*creator)());
};

#define REGISTER_QDISPITEM_CLASS(type, Class)							\
  QGraphic* Creator_##Class##_Item() {									\
    return new Class();													\
  }																		\
  QDispItemRegisterer g_creator_##Class(type, Creator_##Class##_Item);
