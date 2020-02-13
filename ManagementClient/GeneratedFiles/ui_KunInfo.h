/********************************************************************************
** Form generated from reading UI file 'KunInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KUNINFO_H
#define UI_KUNINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_KunInfo
{
public:
    QGridLayout *gridLayout;
    QLabel *label_operatorName;
    QLabel *label_managerName;
    QLabel *label_kunid;
    QLabel *label_coupons;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QFrame *KunInfo)
    {
        if (KunInfo->objectName().isEmpty())
            KunInfo->setObjectName(QStringLiteral("KunInfo"));
        KunInfo->resize(103, 152);
        KunInfo->setFrameShape(QFrame::Box);
        gridLayout = new QGridLayout(KunInfo);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_operatorName = new QLabel(KunInfo);
        label_operatorName->setObjectName(QStringLiteral("label_operatorName"));

        gridLayout->addWidget(label_operatorName, 2, 1, 1, 1);

        label_managerName = new QLabel(KunInfo);
        label_managerName->setObjectName(QStringLiteral("label_managerName"));
        label_managerName->setEnabled(true);

        gridLayout->addWidget(label_managerName, 3, 1, 1, 1);

        label_kunid = new QLabel(KunInfo);
        label_kunid->setObjectName(QStringLiteral("label_kunid"));

        gridLayout->addWidget(label_kunid, 0, 1, 1, 1);

        label_coupons = new QLabel(KunInfo);
        label_coupons->setObjectName(QStringLiteral("label_coupons"));

        gridLayout->addWidget(label_coupons, 1, 1, 1, 1);

        label = new QLabel(KunInfo);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(KunInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(KunInfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setEnabled(true);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_4 = new QLabel(KunInfo);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);


        retranslateUi(KunInfo);

        QMetaObject::connectSlotsByName(KunInfo);
    } // setupUi

    void retranslateUi(QFrame *KunInfo)
    {
        KunInfo->setWindowTitle(QApplication::translate("KunInfo", "KunInfo", 0));
        label_operatorName->setText(QString());
        label_managerName->setText(QString());
        label_kunid->setText(QString());
        label_coupons->setText(QString());
        label->setText(QApplication::translate("KunInfo", "\346\215\206ID\357\274\232", 0));
        label_2->setText(QApplication::translate("KunInfo", "\345\244\215\347\202\271\357\274\232", 0));
        label_3->setText(QApplication::translate("KunInfo", "\347\256\241\347\220\206\357\274\232", 0));
        label_4->setText(QApplication::translate("KunInfo", "\345\210\270\345\210\253\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class KunInfo: public Ui_KunInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KUNINFO_H
