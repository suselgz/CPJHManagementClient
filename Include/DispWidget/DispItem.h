#pragma once
#include "DispWidget/DispData.h"
#include <QGraphicsItem>
#include "DispWidget/DispWidgetExport.h"

class DLL_DISP_WIDGET_API QDispItem :public QObject
{
	Q_OBJECT
public:
	enum signalCallFlag
	{
		signal_contextMenuEvent = 0x1,
		signal_dragEnterEvent = 0x2,
		signal_dragLeaveEvent = 0x4,
		signal_dragMoveEvent = 0x8,

		signal_dropEvent = 0x10,
		signal_focusInEvent = 0x20,
		signal_focusOutEvent = 0x40,
		signal_hoverEnterEvent = 0x80,

		signal_hoverLeaveEvent = 0x100,
		signal_hoverMoveEvent = 0x200,
		signal_inputMethodEvent = 0x400,
		signal_inputMethodQuery = 0x800,

		signal_itemChange = 0x1000,
		signal_keyPressEvent = 0x2000,
		signal_keyReleaseEvent = 0x4000,
		signal_mouseDoubleClickEvent = 0x8000,

		signal_mouseMoveEvent = 0x10000,
		signal_mousePressEvent = 0x20000,
		signal_mouseReleaseEvent = 0x40000,
		signal_sceneEvent = 0x80000,

		signal_sceneEventFilter = 0x100000,
		signal_wheelEvent = 0x200000,

		signal_itemResize = 0x400000,
		signal_itemMove = 0x800000,
	};
public:
	QDispItem() {}
	QDispItem(const QDispData& data) {}

	virtual bool SetItemData(const QDispData& data) = 0;
	virtual const QDispData* GetItemData() const = 0;
	virtual QGraphicsItem* GetQGraphicsItem() const = 0;
	virtual int GetUniqueID() const = 0;
	virtual void SetSignalCallFlag(signalCallFlag flag, bool isValid) = 0;
	virtual bool GetSignalCallFlag(signalCallFlag flag) const = 0;
	virtual unsigned int GetSignalCallFlag() const = 0;
signals:
	void itemResize(QDispItem* item);
	void itemMove(QDispItem* item);

	void contextMenuEvent(QDispItem* item, QGraphicsSceneContextMenuEvent *event);
	void dragEnterEvent(QDispItem* item, QGraphicsSceneDragDropEvent *event);
	void dragLeaveEvent(QDispItem* item, QGraphicsSceneDragDropEvent *event);
	void dragMoveEvent(QDispItem* item, QGraphicsSceneDragDropEvent *event);
	void dropEvent(QDispItem* item, QGraphicsSceneDragDropEvent *event);
	void focusInEvent(QDispItem* item, QFocusEvent *event);
	void focusOutEvent(QDispItem* item, QFocusEvent *event);
	void hoverEnterEvent(QDispItem* item, QGraphicsSceneHoverEvent *event);
	void hoverLeaveEvent(QDispItem* item, QGraphicsSceneHoverEvent *event);
	void hoverMoveEvent(QDispItem* item, QGraphicsSceneHoverEvent *event);
	void inputMethodEvent(QDispItem* item, QInputMethodEvent *event);
	void inputMethodQuery(QDispItem* item, Qt::InputMethodQuery query) const;
	void itemChange(QDispItem* item, QGraphicsItem::GraphicsItemChange change, const QVariant &value);
	void keyPressEvent(QDispItem* item, QKeyEvent *event);
	void keyReleaseEvent(QDispItem* item, QKeyEvent *event);
	void mouseDoubleClickEvent(QDispItem* item, QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QDispItem* item, QGraphicsSceneMouseEvent *event);
	void mousePressEvent(QDispItem* item, QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QDispItem* item, QGraphicsSceneMouseEvent *event);
	void sceneEvent(QDispItem* item, QEvent *event);
	void sceneEventFilter(QDispItem* item, QGraphicsItem *watched, QEvent *event);
	void wheelEvent(QDispItem* item, QGraphicsSceneWheelEvent *event);
};
