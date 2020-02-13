#ifndef BAGMODIFY_H
#define BAGMODIFY_H

#include <QWidget>
#include "ui_BagModify.h"

#include <QFileDialog>
#include "DispScene.h"
#include "opencv2/opencv.hpp"
class BagModify : public QWidget
{
	Q_OBJECT

public:
	BagModify(QWidget *parent = 0);
	~BagModify();

private:
	Ui::BagModify ui;
	QDispScene *m_scene;
	void InitDispScene();
};

#endif // BAGMODIFY_H
