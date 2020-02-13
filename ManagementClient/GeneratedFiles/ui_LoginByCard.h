/********************************************************************************
** Form generated from reading UI file 'LoginByCard.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINBYCARD_H
#define UI_LOGINBYCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginByCard
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *LoginByCard)
    {
        if (LoginByCard->objectName().isEmpty())
            LoginByCard->setObjectName(QStringLiteral("LoginByCard"));
        LoginByCard->resize(381, 251);
        gridLayout = new QGridLayout(LoginByCard);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(LoginByCard);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(LoginByCard);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 1, 1);


        retranslateUi(LoginByCard);

        QMetaObject::connectSlotsByName(LoginByCard);
    } // setupUi

    void retranslateUi(QWidget *LoginByCard)
    {
        LoginByCard->setWindowTitle(QApplication::translate("LoginByCard", "LoginByCard", 0));
        label_2->setText(QApplication::translate("LoginByCard", "\350\257\273\345\215\241\345\231\250\347\212\266\346\200\201", 0));
        label->setText(QApplication::translate("LoginByCard", "\350\257\267\345\210\267\345\267\245\345\215\241", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginByCard: public Ui_LoginByCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINBYCARD_H
