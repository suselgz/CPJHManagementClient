/********************************************************************************
** Form generated from reading UI file 'LoginByName.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINBYNAME_H
#define UI_LOGINBYNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginByName
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_password;
    QLabel *label_name;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_login;

    void setupUi(QWidget *LoginByName)
    {
        if (LoginByName->objectName().isEmpty())
            LoginByName->setObjectName(QStringLiteral("LoginByName"));
        LoginByName->resize(378, 186);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginByName->sizePolicy().hasHeightForWidth());
        LoginByName->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(LoginByName);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_password = new QLabel(LoginByName);
        label_password->setObjectName(QStringLiteral("label_password"));

        gridLayout->addWidget(label_password, 1, 0, 1, 1);

        label_name = new QLabel(LoginByName);
        label_name->setObjectName(QStringLiteral("label_name"));

        gridLayout->addWidget(label_name, 0, 0, 1, 1);

        lineEdit_password = new QLineEdit(LoginByName);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));

        gridLayout->addWidget(lineEdit_password, 1, 1, 1, 1);

        lineEdit_name = new QLineEdit(LoginByName);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_login = new QPushButton(LoginByName);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));

        horizontalLayout_2->addWidget(pushButton_login);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(LoginByName);

        QMetaObject::connectSlotsByName(LoginByName);
    } // setupUi

    void retranslateUi(QWidget *LoginByName)
    {
        LoginByName->setWindowTitle(QApplication::translate("LoginByName", "LoginByName", 0));
        label_password->setText(QApplication::translate("LoginByName", "\345\257\206 \347\240\201\357\274\232", 0));
        label_name->setText(QApplication::translate("LoginByName", "\347\224\250 \346\210\267\357\274\232", 0));
        pushButton_login->setText(QApplication::translate("LoginByName", "\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginByName: public Ui_LoginByName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINBYNAME_H
