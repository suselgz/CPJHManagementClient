/********************************************************************************
** Form generated from reading UI file 'ClientDetial.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDETIAL_H
#define UI_CLIENTDETIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientDetial
{
public:
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_managerName;
    QLabel *label_totalRecive;
    QLabel *label_machineName;
    QLabel *label_title_totalRecive;
    QLabel *label_title_totalRetrieve;
    QLabel *label_totalRetrieve;
    QLabel *label_title_managerName;
    QLabel *label_title_exceptionCount;
    QLabel *label_exceptionCount;
    QLabel *label_operatorName;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTableView *tableView_reciveDetial;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView_exceptionDetial;

    void setupUi(QFrame *ClientDetial)
    {
        if (ClientDetial->objectName().isEmpty())
            ClientDetial->setObjectName(QStringLiteral("ClientDetial"));
        ClientDetial->resize(384, 302);
        ClientDetial->setStyleSheet(QStringLiteral(""));
        verticalLayout_4 = new QVBoxLayout(ClientDetial);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_managerName = new QLabel(ClientDetial);
        label_managerName->setObjectName(QStringLiteral("label_managerName"));

        gridLayout->addWidget(label_managerName, 3, 1, 1, 1);

        label_totalRecive = new QLabel(ClientDetial);
        label_totalRecive->setObjectName(QStringLiteral("label_totalRecive"));

        gridLayout->addWidget(label_totalRecive, 2, 1, 1, 1);

        label_machineName = new QLabel(ClientDetial);
        label_machineName->setObjectName(QStringLiteral("label_machineName"));

        gridLayout->addWidget(label_machineName, 1, 0, 1, 1);

        label_title_totalRecive = new QLabel(ClientDetial);
        label_title_totalRecive->setObjectName(QStringLiteral("label_title_totalRecive"));

        gridLayout->addWidget(label_title_totalRecive, 2, 0, 1, 1);

        label_title_totalRetrieve = new QLabel(ClientDetial);
        label_title_totalRetrieve->setObjectName(QStringLiteral("label_title_totalRetrieve"));

        gridLayout->addWidget(label_title_totalRetrieve, 2, 2, 1, 1);

        label_totalRetrieve = new QLabel(ClientDetial);
        label_totalRetrieve->setObjectName(QStringLiteral("label_totalRetrieve"));

        gridLayout->addWidget(label_totalRetrieve, 2, 3, 1, 1);

        label_title_managerName = new QLabel(ClientDetial);
        label_title_managerName->setObjectName(QStringLiteral("label_title_managerName"));

        gridLayout->addWidget(label_title_managerName, 3, 0, 1, 1);

        label_title_exceptionCount = new QLabel(ClientDetial);
        label_title_exceptionCount->setObjectName(QStringLiteral("label_title_exceptionCount"));

        gridLayout->addWidget(label_title_exceptionCount, 3, 2, 1, 1);

        label_exceptionCount = new QLabel(ClientDetial);
        label_exceptionCount->setObjectName(QStringLiteral("label_exceptionCount"));

        gridLayout->addWidget(label_exceptionCount, 3, 3, 1, 1);

        label_operatorName = new QLabel(ClientDetial);
        label_operatorName->setObjectName(QStringLiteral("label_operatorName"));

        gridLayout->addWidget(label_operatorName, 1, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        tabWidget = new QTabWidget(ClientDetial);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableView_reciveDetial = new QTableView(tab);
        tableView_reciveDetial->setObjectName(QStringLiteral("tableView_reciveDetial"));

        verticalLayout->addWidget(tableView_reciveDetial);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tableView_exceptionDetial = new QTableView(tab_3);
        tableView_exceptionDetial->setObjectName(QStringLiteral("tableView_exceptionDetial"));

        verticalLayout_3->addWidget(tableView_exceptionDetial);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_4->addWidget(tabWidget);


        retranslateUi(ClientDetial);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientDetial);
    } // setupUi

    void retranslateUi(QFrame *ClientDetial)
    {
        ClientDetial->setWindowTitle(QApplication::translate("ClientDetial", "ClientDetial", 0));
        label_managerName->setText(QString());
        label_totalRecive->setText(QString());
        label_machineName->setText(QApplication::translate("ClientDetial", "\346\211\271\346\254\241\347\274\226\345\217\267\357\274\232", 0));
        label_title_totalRecive->setText(QApplication::translate("ClientDetial", "\351\224\200\346\257\201\346\200\273\346\225\260\357\274\232", 0));
        label_title_totalRetrieve->setText(QApplication::translate("ClientDetial", "\345\267\262\351\224\200\346\200\273\346\225\260\357\274\232", 0));
        label_totalRetrieve->setText(QString());
        label_title_managerName->setText(QApplication::translate("ClientDetial", "\351\224\200\346\257\201\347\256\261\346\225\260\357\274\232", 0));
        label_title_exceptionCount->setText(QApplication::translate("ClientDetial", "\351\224\200\346\257\201\346\215\206\346\225\260\357\274\232", 0));
        label_exceptionCount->setText(QString());
        label_operatorName->setText(QApplication::translate("ClientDetial", "\344\272\247\345\223\201\347\261\273\345\236\213\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ClientDetial", "\344\277\256\346\224\271\350\257\246\346\203\205", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ClientDetial", "\346\227\245\345\277\227\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientDetial: public Ui_ClientDetial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDETIAL_H
