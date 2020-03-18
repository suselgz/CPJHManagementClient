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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientDetial
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_destroyBag;
    QLabel *label_machine1Status;
    QLabel *label_title_managerName;
    QLabel *label_patchCode;
    QLabel *label_title_totalRetrieve;
    QLabel *label_preSetNum;
    QLabel *label_title_exceptionCount;
    QLabel *label_machine2Status;
    QLabel *label_title_totalRecive_2;
    QLabel *label_operatorName_2;
    QLabel *label_title_totalRecive;
    QLabel *label_machineName_2;
    QLabel *label_destroyBox;
    QLabel *label_machine3Status;
    QLabel *label_productType;
    QLabel *label_machineName;
    QLabel *label_operatorName;
    QLabel *label_destroyNum;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
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
        ClientDetial->resize(523, 308);
        ClientDetial->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(ClientDetial);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_destroyBag = new QLabel(ClientDetial);
        label_destroyBag->setObjectName(QStringLiteral("label_destroyBag"));

        gridLayout->addWidget(label_destroyBag, 2, 7, 1, 1);

        label_machine1Status = new QLabel(ClientDetial);
        label_machine1Status->setObjectName(QStringLiteral("label_machine1Status"));
        label_machine1Status->setMinimumSize(QSize(32, 32));
        label_machine1Status->setMaximumSize(QSize(32, 32));

        gridLayout->addWidget(label_machine1Status, 0, 1, 1, 1);

        label_title_managerName = new QLabel(ClientDetial);
        label_title_managerName->setObjectName(QStringLiteral("label_title_managerName"));

        gridLayout->addWidget(label_title_managerName, 2, 3, 1, 1);

        label_patchCode = new QLabel(ClientDetial);
        label_patchCode->setObjectName(QStringLiteral("label_patchCode"));

        gridLayout->addWidget(label_patchCode, 1, 1, 1, 1);

        label_title_totalRetrieve = new QLabel(ClientDetial);
        label_title_totalRetrieve->setObjectName(QStringLiteral("label_title_totalRetrieve"));

        gridLayout->addWidget(label_title_totalRetrieve, 2, 0, 1, 1);

        label_preSetNum = new QLabel(ClientDetial);
        label_preSetNum->setObjectName(QStringLiteral("label_preSetNum"));

        gridLayout->addWidget(label_preSetNum, 1, 7, 1, 1);

        label_title_exceptionCount = new QLabel(ClientDetial);
        label_title_exceptionCount->setObjectName(QStringLiteral("label_title_exceptionCount"));

        gridLayout->addWidget(label_title_exceptionCount, 2, 6, 1, 1);

        label_machine2Status = new QLabel(ClientDetial);
        label_machine2Status->setObjectName(QStringLiteral("label_machine2Status"));
        label_machine2Status->setMinimumSize(QSize(32, 32));
        label_machine2Status->setMaximumSize(QSize(32, 32));

        gridLayout->addWidget(label_machine2Status, 0, 4, 1, 1);

        label_title_totalRecive_2 = new QLabel(ClientDetial);
        label_title_totalRecive_2->setObjectName(QStringLiteral("label_title_totalRecive_2"));

        gridLayout->addWidget(label_title_totalRecive_2, 0, 6, 1, 1);

        label_operatorName_2 = new QLabel(ClientDetial);
        label_operatorName_2->setObjectName(QStringLiteral("label_operatorName_2"));

        gridLayout->addWidget(label_operatorName_2, 0, 3, 1, 1);

        label_title_totalRecive = new QLabel(ClientDetial);
        label_title_totalRecive->setObjectName(QStringLiteral("label_title_totalRecive"));

        gridLayout->addWidget(label_title_totalRecive, 1, 6, 1, 1);

        label_machineName_2 = new QLabel(ClientDetial);
        label_machineName_2->setObjectName(QStringLiteral("label_machineName_2"));

        gridLayout->addWidget(label_machineName_2, 0, 0, 1, 1);

        label_destroyBox = new QLabel(ClientDetial);
        label_destroyBox->setObjectName(QStringLiteral("label_destroyBox"));

        gridLayout->addWidget(label_destroyBox, 2, 4, 1, 1);

        label_machine3Status = new QLabel(ClientDetial);
        label_machine3Status->setObjectName(QStringLiteral("label_machine3Status"));
        label_machine3Status->setMinimumSize(QSize(32, 32));
        label_machine3Status->setMaximumSize(QSize(32, 32));

        gridLayout->addWidget(label_machine3Status, 0, 7, 1, 1);

        label_productType = new QLabel(ClientDetial);
        label_productType->setObjectName(QStringLiteral("label_productType"));

        gridLayout->addWidget(label_productType, 1, 4, 1, 1);

        label_machineName = new QLabel(ClientDetial);
        label_machineName->setObjectName(QStringLiteral("label_machineName"));

        gridLayout->addWidget(label_machineName, 1, 0, 1, 1);

        label_operatorName = new QLabel(ClientDetial);
        label_operatorName->setObjectName(QStringLiteral("label_operatorName"));

        gridLayout->addWidget(label_operatorName, 1, 3, 1, 1);

        label_destroyNum = new QLabel(ClientDetial);
        label_destroyNum->setObjectName(QStringLiteral("label_destroyNum"));

        gridLayout->addWidget(label_destroyNum, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 5, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

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

        verticalLayout_2->addWidget(tabWidget);


        retranslateUi(ClientDetial);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientDetial);
    } // setupUi

    void retranslateUi(QFrame *ClientDetial)
    {
        ClientDetial->setWindowTitle(QApplication::translate("ClientDetial", "ClientDetial", 0));
        label_destroyBag->setText(QApplication::translate("ClientDetial", "\344\277\241\346\201\257", 0));
        label_machine1Status->setText(QString());
        label_title_managerName->setText(QApplication::translate("ClientDetial", "\345\267\262\351\224\200\347\256\261\346\225\260\357\274\232", 0));
        label_patchCode->setText(QApplication::translate("ClientDetial", "\344\277\241\346\201\257", 0));
        label_title_totalRetrieve->setText(QApplication::translate("ClientDetial", "\345\267\262\351\224\200\346\200\273\346\225\260\357\274\232", 0));
        label_preSetNum->setText(QApplication::translate("ClientDetial", "\344\277\241\346\201\257", 0));
        label_title_exceptionCount->setText(QApplication::translate("ClientDetial", "\345\267\262\351\224\200\346\215\206\346\225\260\357\274\232", 0));
        label_machine2Status->setText(QString());
        label_title_totalRecive_2->setText(QApplication::translate("ClientDetial", "\344\270\211\345\217\267\347\212\266\346\200\201\357\274\232", 0));
        label_operatorName_2->setText(QApplication::translate("ClientDetial", "\344\272\214\345\217\267\347\212\266\346\200\201\357\274\232", 0));
        label_title_totalRecive->setText(QApplication::translate("ClientDetial", "\351\242\204\350\256\276\346\200\273\346\225\260\357\274\232", 0));
        label_machineName_2->setText(QApplication::translate("ClientDetial", "\344\270\200\345\217\267\347\212\266\346\200\201\357\274\232", 0));
        label_destroyBox->setText(QApplication::translate("ClientDetial", "\344\277\241\346\201\257", 0));
        label_machine3Status->setText(QString());
        label_productType->setText(QApplication::translate("ClientDetial", "\344\277\241\346\201\257", 0));
        label_machineName->setText(QApplication::translate("ClientDetial", "\346\211\271\346\254\241\347\274\226\345\217\267\357\274\232", 0));
        label_operatorName->setText(QApplication::translate("ClientDetial", "\344\272\247\345\223\201\347\261\273\345\236\213\357\274\232", 0));
        label_destroyNum->setText(QApplication::translate("ClientDetial", "\344\277\241\346\201\257", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ClientDetial", "\344\277\256\346\224\271\350\257\246\346\203\205", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ClientDetial", "\346\227\245\345\277\227\350\257\246\346\203\205", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientDetial: public Ui_ClientDetial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDETIAL_H
