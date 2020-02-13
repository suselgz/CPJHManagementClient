/********************************************************************************
** Form generated from reading UI file 'ClientInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTINFO_H
#define UI_CLIENTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ClientInfo
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_totalRecive;
    QLabel *label_totalRetrieve;
    QLabel *label_title_totalRecive;
    QLabel *label_title_totalRetrieve_2;
    QLabel *label_title_operatorName;
    QLabel *label_machineName;
    QLabel *label_title_operatorName_2;
    QLabel *label_operatorName;

    void setupUi(QFrame *ClientInfo)
    {
        if (ClientInfo->objectName().isEmpty())
            ClientInfo->setObjectName(QStringLiteral("ClientInfo"));
        ClientInfo->resize(232, 223);
        ClientInfo->setAutoFillBackground(true);
        ClientInfo->setStyleSheet(QStringLiteral("font: 75 12pt \"Agency FB\";"));
        ClientInfo->setFrameShape(QFrame::Box);
        gridLayout_2 = new QGridLayout(ClientInfo);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(9, 9, 9, 9);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        label_totalRecive = new QLabel(ClientInfo);
        label_totalRecive->setObjectName(QStringLiteral("label_totalRecive"));

        gridLayout->addWidget(label_totalRecive, 4, 1, 1, 1);

        label_totalRetrieve = new QLabel(ClientInfo);
        label_totalRetrieve->setObjectName(QStringLiteral("label_totalRetrieve"));

        gridLayout->addWidget(label_totalRetrieve, 5, 1, 1, 1);

        label_title_totalRecive = new QLabel(ClientInfo);
        label_title_totalRecive->setObjectName(QStringLiteral("label_title_totalRecive"));

        gridLayout->addWidget(label_title_totalRecive, 4, 0, 1, 1);

        label_title_totalRetrieve_2 = new QLabel(ClientInfo);
        label_title_totalRetrieve_2->setObjectName(QStringLiteral("label_title_totalRetrieve_2"));

        gridLayout->addWidget(label_title_totalRetrieve_2, 5, 0, 1, 1);

        label_title_operatorName = new QLabel(ClientInfo);
        label_title_operatorName->setObjectName(QStringLiteral("label_title_operatorName"));

        gridLayout->addWidget(label_title_operatorName, 3, 0, 1, 1);

        label_machineName = new QLabel(ClientInfo);
        label_machineName->setObjectName(QStringLiteral("label_machineName"));

        gridLayout->addWidget(label_machineName, 1, 1, 1, 1);

        label_title_operatorName_2 = new QLabel(ClientInfo);
        label_title_operatorName_2->setObjectName(QStringLiteral("label_title_operatorName_2"));

        gridLayout->addWidget(label_title_operatorName_2, 1, 0, 1, 1);

        label_operatorName = new QLabel(ClientInfo);
        label_operatorName->setObjectName(QStringLiteral("label_operatorName"));

        gridLayout->addWidget(label_operatorName, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ClientInfo);

        QMetaObject::connectSlotsByName(ClientInfo);
    } // setupUi

    void retranslateUi(QFrame *ClientInfo)
    {
        ClientInfo->setWindowTitle(QApplication::translate("ClientInfo", "ClientInfo", 0));
        label_totalRecive->setText(QString());
        label_totalRetrieve->setText(QString());
        label_title_totalRecive->setText(QApplication::translate("ClientInfo", "\346\212\245\350\255\246\346\200\273\346\225\260\357\274\232", 0));
        label_title_totalRetrieve_2->setText(QApplication::translate("ClientInfo", "\346\234\252\345\244\204\347\220\206\346\225\260\357\274\232", 0));
        label_title_operatorName->setText(QApplication::translate("ClientInfo", "\346\223\215\344\275\234\345\221\230\357\274\232", 0));
        label_machineName->setText(QString());
        label_title_operatorName_2->setText(QApplication::translate("ClientInfo", "\346\234\272\345\217\260\345\220\215\357\274\232", 0));
        label_operatorName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ClientInfo: public Ui_ClientInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTINFO_H
