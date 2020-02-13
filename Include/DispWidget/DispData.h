#pragma once
#include <QPointF>
#include <QRectF>
#include <QString>
#include <QVector>
#include <QColor>
#include "DispWidget/DispWidgetExport.h"
#include "QVariant"

enum DispType
{
	line,
	rect,
	rotatedRect,
	poly,
	align,
	grid,
	text,
	path,
	cross,
	arrows,
	arrow,
	alignArrow,
	circle,
	codeArrow,
	synCodeArrow,
	custom = 20
};

enum DispFlag
{
	DispFlag_Selectable = 0x0001,
	DispFlag_Movable = 0x0002,
	DispFlag_Resizable = 0x0004,
	DispFlag_HasCaption = 0x0008,
};

class DLL_DISP_WIDGET_API QDispColor
{
public:
	QDispColor() {
		Clear();
	}

	void Clear()
	{
		_color = 0;
		_bFill = false;
		_fillColor = 0;
		_bOpacity = false;
		_opacity = 0.5;
	}
	void SetColor(QColor color) { _color = color.rgb(); }
	QColor GetQColor() const { return QColor(_color); }
	void Fill(bool bFill) { _bFill = bFill; }
	bool GetFill() const { return _bFill; }
	void SetFillColor(QColor color) { _fillColor = color.rgb(); }
	QColor GetQFillColor() const { return QColor(_fillColor); }
	bool Opacity() const { return _bOpacity; }
	void SetOpacity(bool bOpacity) { _bOpacity = bOpacity; }
	void SetOpacityRatio(qreal opacity) { _opacity = opacity; }
	qreal GetOpacityRatio() const { return _opacity; }

private:
	QRgb                _color;
	bool                _bFill;
	QRgb                _fillColor;
	bool                _bOpacity;
	qreal               _opacity;

public:
	bool operator != (const QDispColor& color) const
	{
		if (_color != color._color)			return true;
		if (_bFill != color._bFill)			return true;
		if (_fillColor != color._fillColor)	return true;
		if (_bOpacity != color._bOpacity)	return true;
		if (_opacity != color._opacity)		return true;
		return false;
	}
};

class DLL_DISP_WIDGET_API QDispVertex
{
public:
	QDispVertex() {}

	void Clear() { _vertexs.clear(); }
	int GetCount() const { return _vertexs.size(); }
	void Add(const QPointF& point) { _vertexs.push_back(point); }
	void Add(qreal ax, qreal ay) { Add(QPointF(ax, ay)); }

	const QVector<QPointF>& Vertexs() const { return _vertexs; }
	QVector<QPointF>& Vertexs() { return _vertexs; }

	const QPointF& Vertex(int nVertexIndex) const
	{
		if (nVertexIndex < _vertexs.size())
		{
			return _vertexs[nVertexIndex];
		}
		else
			throw std::exception();
	}

	bool Modify(int nVertexIndex, const QPointF& point)
	{
		if (nVertexIndex < _vertexs.size())
		{
			_vertexs[nVertexIndex] = point;
		}
		return false;
	}

	bool Modify(int nVertexIndex, qreal ax, qreal ay) { return Modify(nVertexIndex, QPointF(ax, ay)); }

private:
	QVector<QPointF>    _vertexs;

public:
	bool operator != (const QDispVertex& vertex) const
	{
		if (_vertexs.size() != vertex._vertexs.size())	return true;
		for (int i = 0; i < _vertexs.size(); ++i)
		{
			if (_vertexs[i] != vertex._vertexs[i])		return true;
		}
		return false;
	}
};

class DLL_DISP_WIDGET_API QGridData
{
public:
	QGridData() : _pVertex(NULL), _nRows(0), _nCols(0), _whole(false) { Clear(); }

	QGridData(QDispVertex* pVertex) : _pVertex(pVertex), _nRows(0), _nCols(0), _whole(false) { Clear(); }

	void SetVertex(QDispVertex* pVertex)
	{
		_pVertex = pVertex;
	}
	void Clear()
	{
		SetRowCount(1);
		SetColCount(1);
		_whole = false;
	}
	void SetRowCount(int nRows)
	{
		if (nRows != _nRows)
		{
			_rows.clear();
			_nRows = nRows;
			if (_nRows > 0)
			{
				_rows.resize(_nRows);
				AutoAdjust();
			}
		}
	}
	void SetColCount(int nCols)
	{
		if (nCols != _nCols)
		{
			_nCols = nCols;
			_cols.clear();
			if (_nCols > 0)
			{
				_cols.resize(_nCols);
				AutoAdjust();
			}
		}
	}
	int GetRowCount() const { return _nRows; }
	int GetColCount() const { return _nCols; }
	void AutoAdjust()
	{
		QRectF boundRect(0, 0, 0, 0);
		if (_pVertex)
		{
			boundRect.setRect(_pVertex->Vertex(0).x(), _pVertex->Vertex(0).y(),
				_pVertex->Vertex(1).x() - _pVertex->Vertex(0).x(),
				_pVertex->Vertex(1).y() - _pVertex->Vertex(0).y());
		}
		if (_nRows > 0)
		{
			qreal auto_height = boundRect.height() / _nRows;
			for (int i = 0; i < _nRows; ++i)
			{
				if (i == _nRows - 1)
				{
					_rows[i] = boundRect.bottom();
				}
				else
				{
					_rows[i] = boundRect.top() + auto_height * (i + 1);
				}
			}
		}

		if (_nCols > 0)
		{
			qreal auto_width = boundRect.width() / _nCols;
			for (int i = 0; i < _nCols; ++i)
			{
				if (i == _nCols - 1)
				{
					_cols[i] = boundRect.right();
				}
				else
				{
					_cols[i] = boundRect.left() + auto_width * (i + 1);
				}
			}
		}
	}
	void SetGridRowCoordinate(int nRowIndex, qreal coordi)
	{
		if (nRowIndex < _nRows)
		{
			_rows[nRowIndex] = coordi;
		}
	}
	qreal GetGridRowCoordinate(int nRowIndex) const
	{
		if (nRowIndex < _nRows)
		{
			return _rows[nRowIndex];
		}
		else
		{
			return 0;
		}
	}
	void SetGridColCoordinate(int nColIndex, qreal coordi)
	{
		if (nColIndex < _nCols)
		{
			_cols[nColIndex] = coordi;
		}
	}
	qreal GetGridColCoordinate(int nColIndex) const
	{
		if (nColIndex < _nCols)
		{
			return _cols[nColIndex];
		}
		else
		{
			return 0;
		}
	}
	QRectF GetGridRect(int nRowIndex, int nColIndex) const
	{
		QRectF boundRect(_pVertex->Vertex(0), _pVertex->Vertex(1));
		if (nRowIndex < _nRows && nColIndex < _nCols)
		{
			qreal top, left, right, bottom;
			if (nRowIndex == 0)
			{
				top = boundRect.top();
			}
			else
			{
				top = _rows[nRowIndex - 1];
			}
			bottom = _rows[nRowIndex];

			if (nColIndex == 0)
			{
				left = boundRect.left();
			}
			else
			{
				left = _cols[nColIndex - 1];
			}
			right = _cols[nColIndex];

			return QRectF(left, top, right - left, bottom - top);
		}
		else
		{
			return boundRect;
		}
	}

	void SetSelectWhole(bool bWhole = false) { _whole = bWhole; }
	bool GetSelectWhole() const { return _whole; }

private:
	QDispVertex         *_pVertex;
	int                 _nRows;
	int                 _nCols;
	QVector<qreal>      _rows;
	QVector<qreal>      _cols;
	bool                _whole;

public:
	bool operator != (const QGridData& data) const
	{
		if (_nRows != data._nRows)				return true;
		if (_nCols != data._nCols)				return true;
		if (_rows.size() != data._rows.size())	return true;
		for (int i = 0; i < _rows.size(); ++i)
		{
			if (_rows[i] != data._rows[i])		return true;
		}
		if (_cols.size() != data._cols.size())	return true;
		for (int i = 0; i < _cols.size(); ++i)
		{
			if (_cols[i] != data._cols[i])		return true;
		}
		if (_whole != data._whole)				return true;
		return false;
	}
};

class DLL_DISP_WIDGET_API QDispCaption
{
public:
	QDispCaption() {
		Clear();
	}

	void Clear()
	{
		_caption = "";
		_posDif.setX(10);
		_posDif.setY(-15);
	}
	QString GetCaption() const { return _caption; }
	QPointF GetDif() const { return _posDif; }
	void SetCaption(const QString& caption) { _caption = caption; }
	void SetDif(const QPointF& dif) { _posDif = dif; }

private:
	QString             _caption;
	QPointF             _posDif;

public:
	bool operator != (const QDispCaption& caption) const
	{
		if (_caption != caption._caption)	return true;
		if (_posDif != caption._posDif)		return true;
		return false;
	}
};

class DLL_DISP_WIDGET_API QDispFlag
{
public:
	QDispFlag() {
		Clear();
	}

	void Clear() { _flags = 0; }
	void SetMovable(bool bValid = true)
	{
		if (bValid)
		{
			_flags |= DispFlag::DispFlag_Movable;
		}
		else
		{
			_flags &= (~DispFlag::DispFlag_Movable);
		}
	}
	bool IsMovable() const { return (_flags & DispFlag::DispFlag_Movable) ? true : false; }

	void SetSelectable(bool bValid = true)
	{
		if (bValid)
		{
			_flags |= DispFlag::DispFlag_Selectable;
		}
		else
		{
			_flags &= (~DispFlag::DispFlag_Selectable);
		}
	}
	bool IsSelectable() const { return (_flags & DispFlag::DispFlag_Selectable) ? true : false; }

	void SetHaveCaption(bool bValid = true)
	{
		if (bValid)
		{
			_flags |= DispFlag::DispFlag_HasCaption;
		}
		else
		{
			_flags &= (~DispFlag::DispFlag_HasCaption);
		}
	}
	bool IsHaveCaption() const { return (_flags & DispFlag::DispFlag_HasCaption) ? true : false; }

	void SetResizable(bool bValid = true)
	{
		if (bValid)
		{
			_flags |= DispFlag::DispFlag_Resizable;
		}
		else
		{
			_flags &= (~DispFlag::DispFlag_Resizable);
		}
	}
	bool IsResizable() const { return (_flags & DispFlag::DispFlag_Resizable) ? true : false; }

private:
	unsigned int      _flags;

public:
	bool operator != (const QDispFlag& flag) const
	{
		if (_flags != flag._flags)		return true;
		return false;
	}
};

class DLL_DISP_WIDGET_API QDispData
{
public:
	QDispData()
		: type(DispType::rect), lineWidth(1), angle(0) {
		grid.SetVertex(&vertex);
	}

public:
	int					type;
	QDispFlag           flag;
	QDispColor          color;
	QDispVertex         vertex;
	QDispCaption        caption;
	QGridData           grid;
	qreal				lineWidth;
	qreal				angle;
	QVariant			customData;

public:
	bool operator == (const QDispData& data) const
	{
		if (type != data.type)				return false;
		if (flag != data.flag)				return false;
		if (color != data.color)			return false;
		if (vertex != data.vertex)			return false;
		if (caption != data.caption)		return false;
		if (grid != data.grid)				return false;
		if (lineWidth != data.lineWidth)	return false;
		if (angle != data.angle)			return false;
		if (customData != data.customData)			return false;
		return true;
	}

	QDispData& QDispData::operator = (const QDispData& data)
	{
		this->type = data.type;
		this->flag = data.flag;
		this->color = data.color;
		this->vertex = data.vertex;
		this->caption = data.caption;
		this->grid = data.grid;
		this->lineWidth = data.lineWidth;
		this->angle = data.angle;
		this->customData = data.customData;
		this->grid.SetVertex(&this->vertex);
		return *this;
	}

	QDispData(const QDispData& data)
	{
		this->type = data.type;
		this->flag = data.flag;
		this->color = data.color;
		this->vertex = data.vertex;
		this->caption = data.caption;
		this->grid = data.grid;
		this->lineWidth = data.lineWidth;
		this->angle = data.angle;
		this->customData = data.customData;
		this->grid.SetVertex(&this->vertex);
	}
};

#include <QMetaType>
Q_DECLARE_METATYPE(QDispData);