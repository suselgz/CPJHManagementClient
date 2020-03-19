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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <dispview.h>

QT_BEGIN_NAMESPACE

class Ui_BagModify
{
public:
    QHBoxLayout *horizontalLayout;
    QDispView *graphicsView;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QLabel *label_9;
    QLabel *label_serial;
    QLabel *label_machineName;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_5;
    QLabel *label;
    QComboBox *comboBox_identfyNum;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_2;
    QCheckBox *checkBox_numErrType;
    QCheckBox *checkBox_envelope;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_3;
    QCheckBox *checkBox_delete;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QLabel *label_info;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *BagModify)
    {
        if (BagModify->objectName().isEmpty())
            BagModify->setObjectName(QStringLiteral("BagModify"));
        BagModify->resize(697, 344);
        horizontalLayout = new QHBoxLayout(BagModify);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        graphicsView = new QDispView(BagModify);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(0, 0));
        graphicsView->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(BagModify);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);

        label_serial = new QLabel(groupBox_2);
        label_serial->setObjectName(QStringLiteral("label_serial"));

        gridLayout_2->addWidget(label_serial, 3, 1, 1, 1);

        label_machineName = new QLabel(groupBox_2);
        label_machineName->setObjectName(QStringLiteral("label_machineName"));

        gridLayout_2->addWidget(label_machineName, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(BagModify);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 0, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        comboBox_identfyNum = new QComboBox(groupBox);
        comboBox_identfyNum->setObjectName(QStringLiteral("comboBox_identfyNum"));

        gridLayout->addWidget(comboBox_identfyNum, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        checkBox_numErrType = new QCheckBox(groupBox);
        checkBox_numErrType->setObjectName(QStringLiteral("checkBox_numErrType"));

        gridLayout->addWidget(checkBox_numErrType, 3, 1, 1, 1);

        checkBox_envelope = new QCheckBox(groupBox);
        checkBox_envelope->setObjectName(QStringLiteral("checkBox_envelope"));

        gridLayout->addWidget(checkBox_envelope, 3, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        checkBox_delete = new QCheckBox(groupBox);
        checkBox_delete->setObjectName(QStringLiteral("checkBox_delete"));

        gridLayout->addWidget(checkBox_delete, 5, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        label_info = new QLabel(groupBox);
        label_info->setObjectName(QStringLiteral("label_info"));

        gridLayout->addWidget(label_info, 7, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 1);


        verticalLayout->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(BagModify);

        QMetaObject::connectSlotsByName(BagModify);
    } // setupUi

    void retranslateUi(QWidget *BagModify)
    {
        BagModify->setWindowTitle(QApplication::translate("BagModify", "\351\224\231\350\257\257\344\277\256\346\224\271\345\257\271\350\257\235\346\241\206", 0));
        groupBox_2->setTitle(QString());
        label_12->setText(QApplication::translate("BagModify", "\346\234\272\345\217\260\344\277\241\346\201\257\357\274\232", 0));
        label_9->setText(QApplication::translate("BagModify", "\351\222\261\346\215\206\345\272\217\345\217\267\357\274\232", 0));
        label_serial->setText(QApplication::translate("BagModify", "\344\277\241\346\201\257", 0));
        label_machineName->setText(QApplication::translate("BagModify", "\344\277\241\346\201\257", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("BagModify", "\350\257\206\345\210\253\346\212\212\346\225\260\357\274\232", 0));
        label_2->setText(QApplication::translate("BagModify", "\346\212\245\350\255\246\347\261\273\345\236\213\357\274\232", 0));
        checkBox_numErrType->setText(QApplication::translate("BagModify", "\346\212\212\346\225\260\351\224\231\350\257\257", 0));
        checkBox_envelope->setText(QApplication::translate("BagModify", "\344\277\241\345\260\201", 0));
        label_3->setText(QApplication::translate("BagModify", "\346\230\257\345\220\246\345\210\240\345\233\276\357\274\232", 0));
        checkBox_delete->setText(QApplication::translate("BagModify", "\346\230\257", 0));
        label_4->setText(QApplication::translate("BagModify", "\346\216\210\346\235\203\344\277\241\346\201\257\357\274\232", 0));
        label_info->setText(QApplication::translate("BagModify", "\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class BagModify: public Ui_BagModify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAGMODIFY_H
