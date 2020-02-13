/********************************************************************************
** Form generated from reading UI file 'RetrieveDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETRIEVEDLG_H
#define UI_RETRIEVEDLG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_RetrieveDlg
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_ProductType;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_productType;
    QGroupBox *groupBox_KunNum;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox_Number;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Submit;

    void setupUi(QDialog *RetrieveDlg)
    {
        if (RetrieveDlg->objectName().isEmpty())
            RetrieveDlg->setObjectName(QStringLiteral("RetrieveDlg"));
        RetrieveDlg->resize(455, 343);
        gridLayout = new QGridLayout(RetrieveDlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_ProductType = new QGroupBox(RetrieveDlg);
        groupBox_ProductType->setObjectName(QStringLiteral("groupBox_ProductType"));
        gridLayout_2 = new QGridLayout(groupBox_ProductType);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_productType = new QGridLayout();
        gridLayout_productType->setSpacing(6);
        gridLayout_productType->setObjectName(QStringLiteral("gridLayout_productType"));

        gridLayout_2->addLayout(gridLayout_productType, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_ProductType, 0, 0, 1, 1);

        groupBox_KunNum = new QGroupBox(RetrieveDlg);
        groupBox_KunNum->setObjectName(QStringLiteral("groupBox_KunNum"));
        horizontalLayout = new QHBoxLayout(groupBox_KunNum);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_KunNum);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox_Number = new QSpinBox(groupBox_KunNum);
        spinBox_Number->setObjectName(QStringLiteral("spinBox_Number"));
        spinBox_Number->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(spinBox_Number);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(groupBox_KunNum, 1, 0, 1, 1);

        pushButton_Submit = new QPushButton(RetrieveDlg);
        pushButton_Submit->setObjectName(QStringLiteral("pushButton_Submit"));

        gridLayout->addWidget(pushButton_Submit, 2, 0, 1, 1);


        retranslateUi(RetrieveDlg);

        QMetaObject::connectSlotsByName(RetrieveDlg);
    } // setupUi

    void retranslateUi(QDialog *RetrieveDlg)
    {
        RetrieveDlg->setWindowTitle(QApplication::translate("RetrieveDlg", "RetrieveDlg", 0));
        groupBox_ProductType->setTitle(QApplication::translate("RetrieveDlg", "\345\223\201\347\247\215\351\200\211\346\213\251", 0));
        groupBox_KunNum->setTitle(QApplication::translate("RetrieveDlg", "\346\215\206\346\225\260\350\256\276\347\275\256\357\274\232", 0));
        label->setText(QApplication::translate("RetrieveDlg", "\345\233\236\346\224\266\346\215\206\346\225\260\357\274\232", 0));
        pushButton_Submit->setText(QApplication::translate("RetrieveDlg", "\346\217\220\344\272\244", 0));
    } // retranslateUi

};

namespace Ui {
    class RetrieveDlg: public Ui_RetrieveDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETRIEVEDLG_H
