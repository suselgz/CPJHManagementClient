/********************************************************************************
** Form generated from reading UI file 'ReciveDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIVEDLG_H
#define UI_RECIVEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReciveDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_machineName;
    QLabel *label_6;
    QLabel *label_operatorName;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_ProductType;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_productType;
    QGroupBox *groupBox_KunNum;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_Number;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *lineEdit_Code;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QTextEdit *textEdit_Note;
    QGroupBox *groupBox_reciveDetial;
    QGridLayout *gridLayout;
    QTableView *tableView_reciveDetial;
    QPushButton *pushButton_Submit;

    void setupUi(QDialog *ReciveDlg)
    {
        if (ReciveDlg->objectName().isEmpty())
            ReciveDlg->setObjectName(QStringLiteral("ReciveDlg"));
        ReciveDlg->resize(800, 724);
        ReciveDlg->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(ReciveDlg);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(ReciveDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QStringLiteral(""));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        label_machineName = new QLabel(groupBox);
        label_machineName->setObjectName(QStringLiteral("label_machineName"));

        horizontalLayout_4->addWidget(label_machineName);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        label_operatorName = new QLabel(groupBox);
        label_operatorName->setObjectName(QStringLiteral("label_operatorName"));

        horizontalLayout_4->addWidget(label_operatorName);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_ProductType = new QGroupBox(ReciveDlg);
        groupBox_ProductType->setObjectName(QStringLiteral("groupBox_ProductType"));
        groupBox_ProductType->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(groupBox_ProductType);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_productType = new QGridLayout();
        gridLayout_productType->setSpacing(6);
        gridLayout_productType->setObjectName(QStringLiteral("gridLayout_productType"));

        gridLayout_2->addLayout(gridLayout_productType, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupBox_ProductType);

        groupBox_KunNum = new QGroupBox(ReciveDlg);
        groupBox_KunNum->setObjectName(QStringLiteral("groupBox_KunNum"));
        groupBox_KunNum->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(groupBox_KunNum);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_KunNum);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(label);

        lineEdit_Number = new QLineEdit(groupBox_KunNum);
        lineEdit_Number->setObjectName(QStringLiteral("lineEdit_Number"));

        horizontalLayout->addWidget(lineEdit_Number);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(groupBox_KunNum);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        lineEdit_Code = new QLineEdit(groupBox_KunNum);
        lineEdit_Code->setObjectName(QStringLiteral("lineEdit_Code"));
        lineEdit_Code->setEnabled(true);
        lineEdit_Code->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_5->addWidget(lineEdit_Code);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox_KunNum);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        textEdit_Note = new QTextEdit(groupBox_KunNum);
        textEdit_Note->setObjectName(QStringLiteral("textEdit_Note"));
        textEdit_Note->setEnabled(true);
        textEdit_Note->setMaximumSize(QSize(16777215, 80));

        horizontalLayout_2->addWidget(textEdit_Note);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(groupBox_KunNum);


        verticalLayout_2->addLayout(horizontalLayout_3);

        groupBox_reciveDetial = new QGroupBox(ReciveDlg);
        groupBox_reciveDetial->setObjectName(QStringLiteral("groupBox_reciveDetial"));
        groupBox_reciveDetial->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(groupBox_reciveDetial);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView_reciveDetial = new QTableView(groupBox_reciveDetial);
        tableView_reciveDetial->setObjectName(QStringLiteral("tableView_reciveDetial"));

        gridLayout->addWidget(tableView_reciveDetial, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_reciveDetial);

        pushButton_Submit = new QPushButton(ReciveDlg);
        pushButton_Submit->setObjectName(QStringLiteral("pushButton_Submit"));

        verticalLayout_2->addWidget(pushButton_Submit);


        retranslateUi(ReciveDlg);

        QMetaObject::connectSlotsByName(ReciveDlg);
    } // setupUi

    void retranslateUi(QDialog *ReciveDlg)
    {
        ReciveDlg->setWindowTitle(QApplication::translate("ReciveDlg", "ReciveDlg", 0));
        groupBox->setTitle(QApplication::translate("ReciveDlg", "\350\256\276\345\244\207\344\277\241\346\201\257", 0));
        label_4->setText(QApplication::translate("ReciveDlg", "\350\256\276\345\244\207\357\274\232", 0));
        label_machineName->setText(QString());
        label_6->setText(QApplication::translate("ReciveDlg", "\345\244\215\347\202\271\345\221\230\357\274\232", 0));
        label_operatorName->setText(QString());
        groupBox_ProductType->setTitle(QApplication::translate("ReciveDlg", "\345\223\201\347\247\215\351\200\211\346\213\251", 0));
        groupBox_KunNum->setTitle(QApplication::translate("ReciveDlg", "\350\256\276\347\275\256\357\274\232", 0));
        label->setText(QApplication::translate("ReciveDlg", "\346\215\206\346\225\260\357\274\232", 0));
        label_2->setText(QApplication::translate("ReciveDlg", "\347\274\226\345\217\267\357\274\232", 0));
        label_3->setText(QApplication::translate("ReciveDlg", "\350\257\264\346\230\216\357\274\232", 0));
        groupBox_reciveDetial->setTitle(QApplication::translate("ReciveDlg", "\351\242\206\347\224\250\344\277\241\346\201\257", 0));
        pushButton_Submit->setText(QApplication::translate("ReciveDlg", "\346\217\220\344\272\244", 0));
    } // retranslateUi

};

namespace Ui {
    class ReciveDlg: public Ui_ReciveDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIVEDLG_H
