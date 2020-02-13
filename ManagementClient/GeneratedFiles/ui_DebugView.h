/********************************************************************************
** Form generated from reading UI file 'DebugView.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGVIEW_H
#define UI_DEBUGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugView
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_moneyBindingMachineDriver;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_btn;
    QPushButton *pushButton_modeLower;
    QPushButton *pushButton_modeUpper;
    QPushButton *pushButton_machineStatus;
    QPushButton *pushButton_inkStatus;
    QGroupBox *groupBox_print;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_qrCode;
    QGridLayout *gridLayout_8;
    QRadioButton *radioButton_qrCode;
    QLabel *label_qrCode;
    QTextEdit *textEdit_qrCode;
    QGroupBox *groupBox_textAndQR;
    QGridLayout *gridLayout_9;
    QRadioButton *radioButton_textAndQR;
    QLineEdit *lineEdit_textAndQRLineOne;
    QLabel *label_textAndQRLineTwo;
    QLineEdit *lineEdit_textAndQRLineTwo;
    QLineEdit *lineEdit_textAndQRLineFour;
    QLabel *label_textAndQRLineThree;
    QLineEdit *lineEdit_textAndQRLineThree;
    QLabel *label_textAndQRLineOne;
    QTextEdit *textEdit_textAndQRQR;
    QLabel *label_textAndQRLineFour;
    QLabel *label_textAndQRQR;
    QGroupBox *groupBox_barCode;
    QGridLayout *gridLayout_7;
    QRadioButton *radioButton_barCode;
    QLabel *label_barCode;
    QLineEdit *lineEdit_barCode;
    QGroupBox *groupBox_text;
    QGridLayout *gridLayout_5;
    QLabel *label_textLineTwo;
    QLabel *label_textLineFour;
    QLabel *label_textLineOne;
    QLabel *label_textLineThree;
    QRadioButton *radioButton_text;
    QCheckBox *checkBox_fontSize;
    QLineEdit *lineEdit_fontSize;
    QLineEdit *lineEdit_textLineOne;
    QLineEdit *lineEdit_textLineTwo;
    QLineEdit *lineEdit_textLineThree;
    QLineEdit *lineEdit_textLineFour;
    QPushButton *pushButton_generate;
    QGroupBox *groupBox_send;
    QHBoxLayout *horizontalLayout;
    QTextEdit *textEdit_send;
    QPushButton *pushButton_send;
    QGroupBox *groupBox_receive;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit_receive;
    QPushButton *pushButton_receive_clear;
    QWidget *tab_2;

    void setupUi(QWidget *DebugView)
    {
        if (DebugView->objectName().isEmpty())
            DebugView->setObjectName(QStringLiteral("DebugView"));
        DebugView->resize(1024, 821);
        gridLayout = new QGridLayout(DebugView);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(DebugView);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_moneyBindingMachineDriver = new QWidget();
        tab_moneyBindingMachineDriver->setObjectName(QStringLiteral("tab_moneyBindingMachineDriver"));
        verticalLayout = new QVBoxLayout(tab_moneyBindingMachineDriver);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_btn = new QGridLayout();
        gridLayout_btn->setSpacing(6);
        gridLayout_btn->setObjectName(QStringLiteral("gridLayout_btn"));
        pushButton_modeLower = new QPushButton(tab_moneyBindingMachineDriver);
        pushButton_modeLower->setObjectName(QStringLiteral("pushButton_modeLower"));

        gridLayout_btn->addWidget(pushButton_modeLower, 0, 1, 1, 1);

        pushButton_modeUpper = new QPushButton(tab_moneyBindingMachineDriver);
        pushButton_modeUpper->setObjectName(QStringLiteral("pushButton_modeUpper"));

        gridLayout_btn->addWidget(pushButton_modeUpper, 0, 0, 1, 1);

        pushButton_machineStatus = new QPushButton(tab_moneyBindingMachineDriver);
        pushButton_machineStatus->setObjectName(QStringLiteral("pushButton_machineStatus"));

        gridLayout_btn->addWidget(pushButton_machineStatus, 1, 0, 1, 1);

        pushButton_inkStatus = new QPushButton(tab_moneyBindingMachineDriver);
        pushButton_inkStatus->setObjectName(QStringLiteral("pushButton_inkStatus"));

        gridLayout_btn->addWidget(pushButton_inkStatus, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_btn);

        groupBox_print = new QGroupBox(tab_moneyBindingMachineDriver);
        groupBox_print->setObjectName(QStringLiteral("groupBox_print"));
        gridLayout_6 = new QGridLayout(groupBox_print);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_qrCode = new QGroupBox(groupBox_print);
        groupBox_qrCode->setObjectName(QStringLiteral("groupBox_qrCode"));
        gridLayout_8 = new QGridLayout(groupBox_qrCode);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        radioButton_qrCode = new QRadioButton(groupBox_qrCode);
        radioButton_qrCode->setObjectName(QStringLiteral("radioButton_qrCode"));

        gridLayout_8->addWidget(radioButton_qrCode, 0, 0, 1, 1);

        label_qrCode = new QLabel(groupBox_qrCode);
        label_qrCode->setObjectName(QStringLiteral("label_qrCode"));

        gridLayout_8->addWidget(label_qrCode, 1, 0, 1, 1);

        textEdit_qrCode = new QTextEdit(groupBox_qrCode);
        textEdit_qrCode->setObjectName(QStringLiteral("textEdit_qrCode"));

        gridLayout_8->addWidget(textEdit_qrCode, 1, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_qrCode, 2, 0, 1, 1);

        groupBox_textAndQR = new QGroupBox(groupBox_print);
        groupBox_textAndQR->setObjectName(QStringLiteral("groupBox_textAndQR"));
        gridLayout_9 = new QGridLayout(groupBox_textAndQR);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        radioButton_textAndQR = new QRadioButton(groupBox_textAndQR);
        radioButton_textAndQR->setObjectName(QStringLiteral("radioButton_textAndQR"));

        gridLayout_9->addWidget(radioButton_textAndQR, 0, 0, 1, 1);

        lineEdit_textAndQRLineOne = new QLineEdit(groupBox_textAndQR);
        lineEdit_textAndQRLineOne->setObjectName(QStringLiteral("lineEdit_textAndQRLineOne"));

        gridLayout_9->addWidget(lineEdit_textAndQRLineOne, 2, 1, 1, 1);

        label_textAndQRLineTwo = new QLabel(groupBox_textAndQR);
        label_textAndQRLineTwo->setObjectName(QStringLiteral("label_textAndQRLineTwo"));

        gridLayout_9->addWidget(label_textAndQRLineTwo, 3, 0, 1, 1);

        lineEdit_textAndQRLineTwo = new QLineEdit(groupBox_textAndQR);
        lineEdit_textAndQRLineTwo->setObjectName(QStringLiteral("lineEdit_textAndQRLineTwo"));

        gridLayout_9->addWidget(lineEdit_textAndQRLineTwo, 3, 1, 1, 1);

        lineEdit_textAndQRLineFour = new QLineEdit(groupBox_textAndQR);
        lineEdit_textAndQRLineFour->setObjectName(QStringLiteral("lineEdit_textAndQRLineFour"));

        gridLayout_9->addWidget(lineEdit_textAndQRLineFour, 5, 1, 1, 1);

        label_textAndQRLineThree = new QLabel(groupBox_textAndQR);
        label_textAndQRLineThree->setObjectName(QStringLiteral("label_textAndQRLineThree"));

        gridLayout_9->addWidget(label_textAndQRLineThree, 4, 0, 1, 1);

        lineEdit_textAndQRLineThree = new QLineEdit(groupBox_textAndQR);
        lineEdit_textAndQRLineThree->setObjectName(QStringLiteral("lineEdit_textAndQRLineThree"));

        gridLayout_9->addWidget(lineEdit_textAndQRLineThree, 4, 1, 1, 1);

        label_textAndQRLineOne = new QLabel(groupBox_textAndQR);
        label_textAndQRLineOne->setObjectName(QStringLiteral("label_textAndQRLineOne"));

        gridLayout_9->addWidget(label_textAndQRLineOne, 2, 0, 1, 1);

        textEdit_textAndQRQR = new QTextEdit(groupBox_textAndQR);
        textEdit_textAndQRQR->setObjectName(QStringLiteral("textEdit_textAndQRQR"));

        gridLayout_9->addWidget(textEdit_textAndQRQR, 1, 1, 1, 1);

        label_textAndQRLineFour = new QLabel(groupBox_textAndQR);
        label_textAndQRLineFour->setObjectName(QStringLiteral("label_textAndQRLineFour"));

        gridLayout_9->addWidget(label_textAndQRLineFour, 5, 0, 1, 1);

        label_textAndQRQR = new QLabel(groupBox_textAndQR);
        label_textAndQRQR->setObjectName(QStringLiteral("label_textAndQRQR"));

        gridLayout_9->addWidget(label_textAndQRQR, 1, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_textAndQR, 0, 1, 3, 1);

        groupBox_barCode = new QGroupBox(groupBox_print);
        groupBox_barCode->setObjectName(QStringLiteral("groupBox_barCode"));
        gridLayout_7 = new QGridLayout(groupBox_barCode);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        radioButton_barCode = new QRadioButton(groupBox_barCode);
        radioButton_barCode->setObjectName(QStringLiteral("radioButton_barCode"));

        gridLayout_7->addWidget(radioButton_barCode, 0, 0, 1, 2);

        label_barCode = new QLabel(groupBox_barCode);
        label_barCode->setObjectName(QStringLiteral("label_barCode"));

        gridLayout_7->addWidget(label_barCode, 1, 0, 1, 1);

        lineEdit_barCode = new QLineEdit(groupBox_barCode);
        lineEdit_barCode->setObjectName(QStringLiteral("lineEdit_barCode"));

        gridLayout_7->addWidget(lineEdit_barCode, 1, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_barCode, 1, 0, 1, 1);

        groupBox_text = new QGroupBox(groupBox_print);
        groupBox_text->setObjectName(QStringLiteral("groupBox_text"));
        gridLayout_5 = new QGridLayout(groupBox_text);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_textLineTwo = new QLabel(groupBox_text);
        label_textLineTwo->setObjectName(QStringLiteral("label_textLineTwo"));

        gridLayout_5->addWidget(label_textLineTwo, 3, 0, 2, 1);

        label_textLineFour = new QLabel(groupBox_text);
        label_textLineFour->setObjectName(QStringLiteral("label_textLineFour"));

        gridLayout_5->addWidget(label_textLineFour, 6, 0, 1, 1);

        label_textLineOne = new QLabel(groupBox_text);
        label_textLineOne->setObjectName(QStringLiteral("label_textLineOne"));

        gridLayout_5->addWidget(label_textLineOne, 1, 0, 2, 1);

        label_textLineThree = new QLabel(groupBox_text);
        label_textLineThree->setObjectName(QStringLiteral("label_textLineThree"));

        gridLayout_5->addWidget(label_textLineThree, 5, 0, 1, 1);

        radioButton_text = new QRadioButton(groupBox_text);
        radioButton_text->setObjectName(QStringLiteral("radioButton_text"));

        gridLayout_5->addWidget(radioButton_text, 0, 0, 1, 1);

        checkBox_fontSize = new QCheckBox(groupBox_text);
        checkBox_fontSize->setObjectName(QStringLiteral("checkBox_fontSize"));

        gridLayout_5->addWidget(checkBox_fontSize, 0, 1, 1, 1);

        lineEdit_fontSize = new QLineEdit(groupBox_text);
        lineEdit_fontSize->setObjectName(QStringLiteral("lineEdit_fontSize"));

        gridLayout_5->addWidget(lineEdit_fontSize, 0, 2, 1, 1);

        lineEdit_textLineOne = new QLineEdit(groupBox_text);
        lineEdit_textLineOne->setObjectName(QStringLiteral("lineEdit_textLineOne"));

        gridLayout_5->addWidget(lineEdit_textLineOne, 1, 1, 1, 2);

        lineEdit_textLineTwo = new QLineEdit(groupBox_text);
        lineEdit_textLineTwo->setObjectName(QStringLiteral("lineEdit_textLineTwo"));

        gridLayout_5->addWidget(lineEdit_textLineTwo, 2, 1, 2, 2);

        lineEdit_textLineThree = new QLineEdit(groupBox_text);
        lineEdit_textLineThree->setObjectName(QStringLiteral("lineEdit_textLineThree"));

        gridLayout_5->addWidget(lineEdit_textLineThree, 4, 1, 2, 2);

        lineEdit_textLineFour = new QLineEdit(groupBox_text);
        lineEdit_textLineFour->setObjectName(QStringLiteral("lineEdit_textLineFour"));

        gridLayout_5->addWidget(lineEdit_textLineFour, 6, 1, 1, 2);


        gridLayout_6->addWidget(groupBox_text, 0, 0, 1, 1);

        pushButton_generate = new QPushButton(groupBox_print);
        pushButton_generate->setObjectName(QStringLiteral("pushButton_generate"));

        gridLayout_6->addWidget(pushButton_generate, 3, 0, 1, 1);

        gridLayout_6->setRowStretch(0, 1);
        gridLayout_6->setRowStretch(1, 1);
        gridLayout_6->setColumnStretch(0, 1);
        gridLayout_6->setColumnStretch(1, 1);

        verticalLayout->addWidget(groupBox_print);

        groupBox_send = new QGroupBox(tab_moneyBindingMachineDriver);
        groupBox_send->setObjectName(QStringLiteral("groupBox_send"));
        horizontalLayout = new QHBoxLayout(groupBox_send);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textEdit_send = new QTextEdit(groupBox_send);
        textEdit_send->setObjectName(QStringLiteral("textEdit_send"));

        horizontalLayout->addWidget(textEdit_send);

        pushButton_send = new QPushButton(groupBox_send);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        horizontalLayout->addWidget(pushButton_send);


        verticalLayout->addWidget(groupBox_send);

        groupBox_receive = new QGroupBox(tab_moneyBindingMachineDriver);
        groupBox_receive->setObjectName(QStringLiteral("groupBox_receive"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_receive);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textEdit_receive = new QTextEdit(groupBox_receive);
        textEdit_receive->setObjectName(QStringLiteral("textEdit_receive"));

        horizontalLayout_2->addWidget(textEdit_receive);

        pushButton_receive_clear = new QPushButton(groupBox_receive);
        pushButton_receive_clear->setObjectName(QStringLiteral("pushButton_receive_clear"));

        horizontalLayout_2->addWidget(pushButton_receive_clear);


        verticalLayout->addWidget(groupBox_receive);

        verticalLayout->setStretch(1, 1);
        tabWidget->addTab(tab_moneyBindingMachineDriver, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(DebugView);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DebugView);
    } // setupUi

    void retranslateUi(QWidget *DebugView)
    {
        DebugView->setWindowTitle(QApplication::translate("DebugView", "DebugView", 0));
        pushButton_modeLower->setText(QApplication::translate("DebugView", "\344\270\213\344\275\215\346\234\272\346\216\247\345\210\266", 0));
        pushButton_modeUpper->setText(QApplication::translate("DebugView", "\344\270\212\344\275\215\346\234\272\346\216\247\345\210\266", 0));
        pushButton_machineStatus->setText(QApplication::translate("DebugView", "\350\216\267\345\217\226\350\256\276\345\244\207\347\212\266\346\200\201", 0));
        pushButton_inkStatus->setText(QApplication::translate("DebugView", "\350\216\267\345\217\226\345\242\250\347\233\222\347\212\266\346\200\201", 0));
        groupBox_print->setTitle(QApplication::translate("DebugView", "\346\211\223\345\215\260", 0));
        groupBox_qrCode->setTitle(QApplication::translate("DebugView", "\344\272\214\347\273\264\347\240\201", 0));
        radioButton_qrCode->setText(QString());
        label_qrCode->setText(QApplication::translate("DebugView", "\345\206\205\345\256\271\357\274\232", 0));
        groupBox_textAndQR->setTitle(QApplication::translate("DebugView", "\344\272\214\347\273\264\347\240\201\344\270\216\346\226\207\346\234\254", 0));
        radioButton_textAndQR->setText(QString());
        label_textAndQRLineTwo->setText(QApplication::translate("DebugView", "\347\254\254\344\272\214\350\241\214\357\274\232", 0));
        label_textAndQRLineThree->setText(QApplication::translate("DebugView", "\347\254\254\344\270\211\350\241\214\357\274\232", 0));
        label_textAndQRLineOne->setText(QApplication::translate("DebugView", "\347\254\254\344\270\200\350\241\214\357\274\232", 0));
        label_textAndQRLineFour->setText(QApplication::translate("DebugView", "\347\254\254\345\233\233\350\241\214\357\274\232", 0));
        label_textAndQRQR->setText(QApplication::translate("DebugView", "\344\272\214\347\273\264\347\240\201\345\206\205\345\256\271\357\274\232", 0));
        groupBox_barCode->setTitle(QApplication::translate("DebugView", "\346\235\241\345\275\242\347\240\201", 0));
        radioButton_barCode->setText(QString());
        label_barCode->setText(QApplication::translate("DebugView", "\345\206\205\345\256\271\357\274\232", 0));
        groupBox_text->setTitle(QApplication::translate("DebugView", "\347\272\257\346\226\207\346\234\254", 0));
        label_textLineTwo->setText(QApplication::translate("DebugView", "\347\254\254\344\272\214\350\241\214\357\274\232", 0));
        label_textLineFour->setText(QApplication::translate("DebugView", "\347\254\254\345\233\233\350\241\214\357\274\232", 0));
        label_textLineOne->setText(QApplication::translate("DebugView", "\347\254\254\344\270\200\350\241\214\357\274\232", 0));
        label_textLineThree->setText(QApplication::translate("DebugView", "\347\254\254\344\270\211\350\241\214\357\274\232", 0));
        radioButton_text->setText(QString());
        checkBox_fontSize->setText(QApplication::translate("DebugView", "\345\255\227\344\275\223\345\244\247\345\260\217", 0));
        pushButton_generate->setText(QApplication::translate("DebugView", "\347\224\237\346\210\220", 0));
        groupBox_send->setTitle(QApplication::translate("DebugView", "\345\217\221\351\200\201\345\214\272", 0));
        pushButton_send->setText(QApplication::translate("DebugView", "\345\217\221\351\200\201", 0));
        groupBox_receive->setTitle(QApplication::translate("DebugView", "\346\216\245\346\224\266\345\214\272", 0));
        pushButton_receive_clear->setText(QApplication::translate("DebugView", "\346\270\205\351\231\244", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_moneyBindingMachineDriver), QApplication::translate("DebugView", "\346\211\216\346\212\212\346\234\272\351\251\261\345\212\250", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DebugView", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class DebugView: public Ui_DebugView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGVIEW_H
