/********************************************************************************
** Form generated from reading UI file 'BaInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAINFO_H
#define UI_BAINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BaInfo
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_4;

    void setupUi(QWidget *BaInfo)
    {
        if (BaInfo->objectName().isEmpty())
            BaInfo->setObjectName(QStringLiteral("BaInfo"));
        BaInfo->resize(249, 160);
        gridLayout_2 = new QGridLayout(BaInfo);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(BaInfo);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_2 = new QLabel(BaInfo);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_6 = new QLabel(BaInfo);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_7 = new QLabel(BaInfo);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 1, 1, 1);

        label = new QLabel(BaInfo);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(BaInfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(BaInfo);

        QMetaObject::connectSlotsByName(BaInfo);
    } // setupUi

    void retranslateUi(QWidget *BaInfo)
    {
        BaInfo->setWindowTitle(QApplication::translate("BaInfo", "BaInfo", 0));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("BaInfo", "\346\212\212\346\240\207\350\257\206\357\274\232", 0));
        label_6->setText(QApplication::translate("BaInfo", "\346\211\216\346\212\212\346\227\266\351\227\264\357\274\232", 0));
        label_7->setText(QString());
        label->setText(QApplication::translate("BaInfo", "\346\212\212\346\225\260\345\272\217\345\217\267\357\274\232", 0));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BaInfo: public Ui_BaInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAINFO_H
