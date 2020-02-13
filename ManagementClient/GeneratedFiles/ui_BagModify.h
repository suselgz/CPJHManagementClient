/********************************************************************************
** Form generated from reading UI file 'BagModify.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAGMODIFY_H
#define UI_BAGMODIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <dispview.h>

QT_BEGIN_NAMESPACE

class Ui_BagModify
{
public:
    QHBoxLayout *horizontalLayout_2;
    QDispView *graphicsView;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLabel *label_3;
    QCheckBox *checkBox_3;
    QLabel *label_4;

    void setupUi(QWidget *BagModify)
    {
        if (BagModify->objectName().isEmpty())
            BagModify->setObjectName(QStringLiteral("BagModify"));
        BagModify->resize(628, 300);
        horizontalLayout_2 = new QHBoxLayout(BagModify);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        graphicsView = new QDispView(BagModify);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(0, 0));
        graphicsView->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(graphicsView);

        groupBox = new QGroupBox(BagModify);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 0, 1, 1, 1);

        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        gridLayout->addWidget(checkBox_3, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout_2->addWidget(groupBox);


        retranslateUi(BagModify);

        QMetaObject::connectSlotsByName(BagModify);
    } // setupUi

    void retranslateUi(QWidget *BagModify)
    {
        BagModify->setWindowTitle(QApplication::translate("BagModify", "BagModify", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("BagModify", "\350\257\206\345\210\253\346\212\212\346\225\260\357\274\232", 0));
        label_2->setText(QApplication::translate("BagModify", "\346\212\245\350\255\246\347\261\273\345\236\213\357\274\232", 0));
        checkBox->setText(QApplication::translate("BagModify", "\346\212\212\346\225\260\351\224\231\350\257\257", 0));
        checkBox_2->setText(QApplication::translate("BagModify", "\344\277\241\345\260\201", 0));
        label_3->setText(QApplication::translate("BagModify", "\346\230\257\345\220\246\345\210\240\345\233\276\357\274\232", 0));
        checkBox_3->setText(QApplication::translate("BagModify", "\346\230\257", 0));
        label_4->setText(QApplication::translate("BagModify", "\346\216\210\346\235\203\344\277\241\346\201\257\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class BagModify: public Ui_BagModify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAGMODIFY_H
