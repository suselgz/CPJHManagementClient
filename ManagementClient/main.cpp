#include "stdafx.h"
#include "ManagementClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GlobalParam::InitGlobalParam();
	ManagementClient w;
	w.show();
	return a.exec();
}
