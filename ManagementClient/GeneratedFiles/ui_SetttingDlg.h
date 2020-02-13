/********************************************************************************
** Form generated from reading UI file 'SetttingDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTTINGDLG_H
#define UI_SETTTINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetttingDlg
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_basicSetting;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *comboBox_machineGroup;
    QLabel *label_title_machineGroup;
    QCheckBox *checkBox_basicSetting;
    QWidget *tab_dbSetting;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLabel *label_userPwd;
    QLineEdit *lineEdit_dbName;
    QLabel *label_dbName;
    QLineEdit *lineEdit_userPwd;
    QLabel *label_dbIp;
    QLabel *label_userName;
    QLineEdit *lineEdit_userName;
    QLineEdit *lineEdit_dbIp;
    QCheckBox *checkBox_dbSetting;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_dbserverPort;
    QLineEdit *lineEdit_dbserverPort;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_apply;
    QPushButton *pushButton_cencel;

    void setupUi(QDialog *SetttingDlg)
    {
        if (SetttingDlg->objectName().isEmpty())
            SetttingDlg->setObjectName(QStringLiteral("SetttingDlg"));
        SetttingDlg->resize(725, 484);
        verticalLayout = new QVBoxLayout(SetttingDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(SetttingDlg);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_basicSetting = new QWidget();
        tab_basicSetting->setObjectName(QStringLiteral("tab_basicSetting"));
        gridLayout_2 = new QGridLayout(tab_basicSetting);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_2 = new QGroupBox(tab_basicSetting);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 30, 445, 375));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_machineGroup = new QComboBox(layoutWidget);
        comboBox_machineGroup->setObjectName(QStringLiteral("comboBox_machineGroup"));

        gridLayout->addWidget(comboBox_machineGroup, 1, 1, 1, 1);

        label_title_machineGroup = new QLabel(layoutWidget);
        label_title_machineGroup->setObjectName(QStringLiteral("label_title_machineGroup"));

        gridLayout->addWidget(label_title_machineGroup, 1, 0, 1, 1);

        checkBox_basicSetting = new QCheckBox(layoutWidget);
        checkBox_basicSetting->setObjectName(QStringLiteral("checkBox_basicSetting"));

        gridLayout->addWidget(checkBox_basicSetting, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_basicSetting, QString());
        tab_dbSetting = new QWidget();
        tab_dbSetting->setObjectName(QStringLiteral("tab_dbSetting"));
        gridLayout_4 = new QGridLayout(tab_dbSetting);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox = new QGroupBox(tab_dbSetting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 580, 375));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_userPwd = new QLabel(layoutWidget1);
        label_userPwd->setObjectName(QStringLiteral("label_userPwd"));

        gridLayout_3->addWidget(label_userPwd, 4, 0, 1, 1);

        lineEdit_dbName = new QLineEdit(layoutWidget1);
        lineEdit_dbName->setObjectName(QStringLiteral("lineEdit_dbName"));

        gridLayout_3->addWidget(lineEdit_dbName, 2, 1, 1, 1);

        label_dbName = new QLabel(layoutWidget1);
        label_dbName->setObjectName(QStringLiteral("label_dbName"));

        gridLayout_3->addWidget(label_dbName, 2, 0, 1, 1);

        lineEdit_userPwd = new QLineEdit(layoutWidget1);
        lineEdit_userPwd->setObjectName(QStringLiteral("lineEdit_userPwd"));

        gridLayout_3->addWidget(lineEdit_userPwd, 4, 1, 1, 1);

        label_dbIp = new QLabel(layoutWidget1);
        label_dbIp->setObjectName(QStringLiteral("label_dbIp"));

        gridLayout_3->addWidget(label_dbIp, 1, 0, 1, 1);

        label_userName = new QLabel(layoutWidget1);
        label_userName->setObjectName(QStringLiteral("label_userName"));

        gridLayout_3->addWidget(label_userName, 3, 0, 1, 1);

        lineEdit_userName = new QLineEdit(layoutWidget1);
        lineEdit_userName->setObjectName(QStringLiteral("lineEdit_userName"));

        gridLayout_3->addWidget(lineEdit_userName, 3, 1, 1, 1);

        lineEdit_dbIp = new QLineEdit(layoutWidget1);
        lineEdit_dbIp->setObjectName(QStringLiteral("lineEdit_dbIp"));
        lineEdit_dbIp->setFrame(true);
        lineEdit_dbIp->setClearButtonEnabled(true);

        gridLayout_3->addWidget(lineEdit_dbIp, 1, 1, 1, 1);

        checkBox_dbSetting = new QCheckBox(layoutWidget1);
        checkBox_dbSetting->setObjectName(QStringLiteral("checkBox_dbSetting"));

        gridLayout_3->addWidget(checkBox_dbSetting, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        tabWidget->addTab(tab_dbSetting, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_dbserverPort = new QLabel(groupBox_3);
        label_dbserverPort->setObjectName(QStringLiteral("label_dbserverPort"));

        horizontalLayout_2->addWidget(label_dbserverPort);

        lineEdit_dbserverPort = new QLineEdit(groupBox_3);
        lineEdit_dbserverPort->setObjectName(QStringLiteral("lineEdit_dbserverPort"));
        lineEdit_dbserverPort->setFrame(true);
        lineEdit_dbserverPort->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(lineEdit_dbserverPort);


        gridLayout_5->addWidget(groupBox_3, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_apply = new QPushButton(SetttingDlg);
        pushButton_apply->setObjectName(QStringLiteral("pushButton_apply"));

        horizontalLayout->addWidget(pushButton_apply);

        pushButton_cencel = new QPushButton(SetttingDlg);
        pushButton_cencel->setObjectName(QStringLiteral("pushButton_cencel"));

        horizontalLayout->addWidget(pushButton_cencel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SetttingDlg);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SetttingDlg);
    } // setupUi

    void retranslateUi(QDialog *SetttingDlg)
    {
        SetttingDlg->setWindowTitle(QApplication::translate("SetttingDlg", "SetttingDlg", 0));
        groupBox_2->setTitle(QString());
        label_title_machineGroup->setText(QApplication::translate("SetttingDlg", "\350\256\276\345\244\207\347\273\204\351\200\211\346\213\251\357\274\232", 0));
        checkBox_basicSetting->setText(QApplication::translate("SetttingDlg", "\344\277\256\346\224\271", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_basicSetting), QApplication::translate("SetttingDlg", "\345\237\272\347\241\200\350\256\276\347\275\256", 0));
        groupBox->setTitle(QString());
        label_userPwd->setText(QApplication::translate("SetttingDlg", "\345\257\206\347\240\201\357\274\232", 0));
        label_dbName->setText(QApplication::translate("SetttingDlg", "\346\225\260\346\215\256\345\272\223\345\220\215\347\247\260\357\274\232", 0));
        label_dbIp->setText(QApplication::translate("SetttingDlg", "\346\225\260\346\215\256\345\272\223IP\357\274\232", 0));
        label_userName->setText(QApplication::translate("SetttingDlg", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        lineEdit_dbIp->setInputMask(QString());
        lineEdit_dbIp->setText(QString());
        lineEdit_dbIp->setPlaceholderText(QString());
        checkBox_dbSetting->setText(QApplication::translate("SetttingDlg", "\344\277\256\346\224\271", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_dbSetting), QApplication::translate("SetttingDlg", "\346\225\260\346\215\256\345\272\223\350\256\276\347\275\256", 0));
        groupBox_3->setTitle(QString());
        label_dbserverPort->setText(QApplication::translate("SetttingDlg", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232", 0));
        lineEdit_dbserverPort->setInputMask(QString());
        lineEdit_dbserverPort->setText(QString());
        lineEdit_dbserverPort->setPlaceholderText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SetttingDlg", "\346\234\215\345\212\241\345\231\250", 0));
        pushButton_apply->setText(QApplication::translate("SetttingDlg", "\345\272\224\347\224\250", 0));
        pushButton_cencel->setText(QApplication::translate("SetttingDlg", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class SetttingDlg: public Ui_SetttingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTTINGDLG_H
