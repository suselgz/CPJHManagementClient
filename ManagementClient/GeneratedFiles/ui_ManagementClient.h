/********************************************************************************
** Form generated from reading UI file 'ManagementClient.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENTCLIENT_H
#define UI_MANAGEMENTCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clientdetial.h"
#include "clientinfo.h"

QT_BEGIN_NAMESPACE

class Ui_ManagementClientClass
{
public:
    QAction *action_exit;
    QAction *action_setting;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_logo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_appTitle;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Exit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    ClientInfo *frame_clintInfo00;
    ClientInfo *frame_clintInfo01;
    ClientInfo *frame_clintInfo02;
    QFrame *frame_clintInfo03;
    QVBoxLayout *verticalLayout;
    ClientDetial *frame_clientDetial;
    QFrame *frame_modify;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ManagementClientClass)
    {
        if (ManagementClientClass->objectName().isEmpty())
            ManagementClientClass->setObjectName(QStringLiteral("ManagementClientClass"));
        ManagementClientClass->resize(1283, 625);
        ManagementClientClass->setStyleSheet(QStringLiteral(""));
        action_exit = new QAction(ManagementClientClass);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/\346\226\260\345\211\215\347\274\200/\351\200\200\345\207\272h.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon);
        action_setting = new QAction(ManagementClientClass);
        action_setting->setObjectName(QStringLiteral("action_setting"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/\346\226\260\345\211\215\347\274\200/\350\256\276\347\275\256h.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_setting->setIcon(icon1);
        centralWidget = new QWidget(ManagementClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_logo = new QLabel(centralWidget);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setMinimumSize(QSize(80, 80));

        horizontalLayout_3->addWidget(label_logo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_appTitle = new QLabel(centralWidget);
        label_appTitle->setObjectName(QStringLiteral("label_appTitle"));
        label_appTitle->setMinimumSize(QSize(0, 0));
        label_appTitle->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label_appTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_Exit = new QPushButton(centralWidget);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));

        horizontalLayout_2->addWidget(pushButton_Exit);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame_clintInfo00 = new ClientInfo(centralWidget);
        frame_clintInfo00->setObjectName(QStringLiteral("frame_clintInfo00"));
        frame_clintInfo00->setStyleSheet(QStringLiteral(""));
        frame_clintInfo00->setFrameShape(QFrame::StyledPanel);
        frame_clintInfo00->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_clintInfo00, 0, 0, 1, 1);

        frame_clintInfo01 = new ClientInfo(centralWidget);
        frame_clintInfo01->setObjectName(QStringLiteral("frame_clintInfo01"));
        frame_clintInfo01->setFrameShape(QFrame::StyledPanel);
        frame_clintInfo01->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_clintInfo01, 0, 1, 1, 1);

        frame_clintInfo02 = new ClientInfo(centralWidget);
        frame_clintInfo02->setObjectName(QStringLiteral("frame_clintInfo02"));
        frame_clintInfo02->setFrameShape(QFrame::StyledPanel);
        frame_clintInfo02->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_clintInfo02, 1, 0, 1, 1);

        frame_clintInfo03 = new QFrame(centralWidget);
        frame_clintInfo03->setObjectName(QStringLiteral("frame_clintInfo03"));
        frame_clintInfo03->setFrameShape(QFrame::StyledPanel);
        frame_clintInfo03->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame_clintInfo03, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_clientDetial = new ClientDetial(centralWidget);
        frame_clientDetial->setObjectName(QStringLiteral("frame_clientDetial"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_clientDetial->sizePolicy().hasHeightForWidth());
        frame_clientDetial->setSizePolicy(sizePolicy);
        frame_clientDetial->setMinimumSize(QSize(0, 0));
        frame_clientDetial->setMaximumSize(QSize(16777215, 16777215));
        frame_clientDetial->setStyleSheet(QStringLiteral(""));
        frame_clientDetial->setFrameShape(QFrame::Box);
        frame_clientDetial->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_clientDetial);

        frame_modify = new QFrame(centralWidget);
        frame_modify->setObjectName(QStringLiteral("frame_modify"));
        frame_modify->setMinimumSize(QSize(0, 0));
        frame_modify->setStyleSheet(QStringLiteral(""));
        frame_modify->setFrameShape(QFrame::StyledPanel);
        frame_modify->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame_modify);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        ManagementClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ManagementClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1283, 23));
        ManagementClientClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(ManagementClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ManagementClientClass->setStatusBar(statusBar);

        retranslateUi(ManagementClientClass);

        QMetaObject::connectSlotsByName(ManagementClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *ManagementClientClass)
    {
        ManagementClientClass->setWindowTitle(QApplication::translate("ManagementClientClass", "ManagementClient", 0));
        action_exit->setText(QApplication::translate("ManagementClientClass", "\351\200\200\345\207\272", 0));
#ifndef QT_NO_TOOLTIP
        action_exit->setToolTip(QApplication::translate("ManagementClientClass", "\351\200\200\345\207\272", 0));
#endif // QT_NO_TOOLTIP
        action_setting->setText(QApplication::translate("ManagementClientClass", "\350\256\276\347\275\256", 0));
#ifndef QT_NO_TOOLTIP
        action_setting->setToolTip(QApplication::translate("ManagementClientClass", "\350\256\276\347\275\256", 0));
#endif // QT_NO_TOOLTIP
        label_logo->setText(QString());
        label_appTitle->setText(QApplication::translate("ManagementClientClass", "\346\256\213\346\215\237\344\272\272\346\260\221\345\270\201\351\224\200\346\257\201\344\275\234\344\270\232\345\275\261\345\203\217\347\256\241\347\220\206\347\263\273\347\273\237-\351\233\206\344\270\255\346\216\210\346\235\203\347\253\257", 0));
        pushButton_Exit->setText(QApplication::translate("ManagementClientClass", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class ManagementClientClass: public Ui_ManagementClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENTCLIENT_H
