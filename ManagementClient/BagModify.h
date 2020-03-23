#ifndef BAGMODIFY_H
#define BAGMODIFY_H

#include <QWidget>
#include "ui_BagModify.h"

#include <QFileDialog>
#include "DispScene.h"

class BagModify : public QWidget
{
	Q_OBJECT

public:
	BagModify(int nClientNo);
	~BagModify();

private:
	Ui::BagModify ui;
	QDispScene *m_scene;
	int m_nclientNo;
	int m_comBoSelIndex;
	NET_MSG_MODIFY_INFO* m_modify_info;
	void InitDispScene();
	void InitModifyInfo(int nClientNo);
	int GetErrTypeInfo();
signals:
	void sendUpdataToMain(NET_MSG_MODIFY_INFO*,int);
public slots:
	void comboBoxSel();
	void on_pushButton_OK_clicked();
};

#endif // BAGMODIFY_H
