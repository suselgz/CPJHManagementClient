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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <dispview.h>

QT_BEGIN_NAMESPACE

class Ui_BagModify
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame_modifyW;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QDispView *graphicsView;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_12;
    QLabel *label_machineName;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_serial;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QComboBox *comboBox_identfyNum;
    QLabel *label_3;
    QLabel *label_info;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *checkBox_delete;
    QLabel *label;
    QCheckBox *checkBox_envelope;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QCheckBox *checkBox_numErrType;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_OK;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_3;
    QPushButton *pushButton_Cancel;

    void setupUi(QWidget *BagModify)
    {
        if (BagModify->objectName().isEmpty())
            BagModify->setObjectName(QStringLiteral("BagModify"));
        BagModify->resize(829, 464);
        horizontalLayout = new QHBoxLayout(BagModify);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_modifyW = new QFrame(BagModify);
        frame_modifyW->setObjectName(QStringLiteral("frame_modifyW"));
        frame_modifyW->setMinimumSize(QSize(0, 0));
        frame_modifyW->setFrameShape(QFrame::StyledPanel);
        frame_modifyW->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_modifyW);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        graphicsView = new QDispView(frame_modifyW);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setMinimumSize(QSize(0, 0));
        graphicsView->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(frame_modifyW);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 1, 0, 1, 1);

        label_machineName = new QLabel(groupBox_2);
        label_machineName->setObjectName(QStringLiteral("label_machineName"));

        gridLayout_2->addWidget(label_machineName, 1, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 0, 0, 1, 1);

        label_serial = new QLabel(groupBox_2);
        label_serial->setObjectName(QStringLiteral("label_serial"));

        gridLayout_2->addWidget(label_serial, 5, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 5, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 2, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 6, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(frame_modifyW);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox_identfyNum = new QComboBox(groupBox);
        comboBox_identfyNum->setObjectName(QStringLiteral("comboBox_identfyNum"));

        gridLayout->addWidget(comboBox_identfyNum, 1, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 5, 1, 1, 1);

        label_info = new QLabel(groupBox);
        label_info->setObjectName(QStringLiteral("label_info"));

        gridLayout->addWidget(label_info, 7, 3, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 2, 1, 1, 1);

        checkBox_delete = new QCheckBox(groupBox);
        checkBox_delete->setObjectName(QStringLiteral("checkBox_delete"));

        gridLayout->addWidget(checkBox_delete, 5, 3, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        checkBox_envelope = new QCheckBox(groupBox);
        checkBox_envelope->setObjectName(QStringLiteral("checkBox_envelope"));

        gridLayout->addWidget(checkBox_envelope, 3, 5, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 3, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 6, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 0, 1, 1, 1);

        checkBox_numErrType = new QCheckBox(groupBox);
        checkBox_numErrType->setObjectName(QStringLiteral("checkBox_numErrType"));

        gridLayout->addWidget(checkBox_numErrType, 3, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 3, 4, 1, 1);

        pushButton_OK = new QPushButton(groupBox);
        pushButton_OK->setObjectName(QStringLiteral("pushButton_OK"));

        gridLayout->addWidget(pushButton_OK, 8, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 7, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        pushButton_Cancel = new QPushButton(groupBox);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        gridLayout->addWidget(pushButton_Cancel, 8, 3, 1, 1);


        verticalLayout->addWidget(groupBox);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        graphicsView->raise();
        groupBox_2->raise();

        horizontalLayout->addWidget(frame_modifyW);


        retranslateUi(BagModify);

        QMetaObject::connectSlotsByName(BagModify);
    } // setupUi

    void retranslateUi(QWidget *BagModify)
    {
        BagModify->setWindowTitle(QApplication::translate("BagModify", "\351\224\231\350\257\257\344\277\256\346\224\271\345\257\271\350\257\235\346\241\206", 0));
        groupBox_2->setTitle(QString());
        label_12->setText(QApplication::translate("BagModify", "\346\234\272\345\217\260\344\277\241\346\201\257\357\274\232", 0));
        label_machineName->setText(QApplication::translate("BagModify", "\344\277\241\346\201\257", 0));
        label_serial->setText(QApplication::translate("BagModify", "\344\277\241\346\201\257", 0));
        label_9->setText(QApplication::translate("BagModify", "\351\222\261\346\215\206\345\272\217\345\217\267\357\274\232", 0));
        groupBox->setTitle(QString());
        comboBox_identfyNum->clear();
        comboBox_identfyNum->insertItems(0, QStringList()
         << QApplication::translate("BagModify", "0", 0)
         << QApplication::translate("BagModify", "1", 0)
         << QApplication::translate("BagModify", "2", 0)
         << QApplication::translate("BagModify", "3", 0)
         << QApplication::translate("BagModify", "4", 0)
         << QApplication::translate("BagModify", "5", 0)
         << QApplication::translate("BagModify", "6", 0)
         << QApplication::translate("BagModify", "7", 0)
         << QApplication::translate("BagModify", "8", 0)
         << QApplication::translate("BagModify", "9", 0)
         << QApplication::translate("BagModify", "10", 0)
         << QApplication::translate("BagModify", "11", 0)
         << QApplication::translate("BagModify", "12", 0)
        );
        label_3->setText(QApplication::translate("BagModify", "\346\230\257\345\220\246\345\210\240\345\233\276\357\274\232", 0));
        label_info->setText(QApplication::translate("BagModify", "\344\277\241\346\201\257", 0));
        checkBox_delete->setText(QApplication::translate("BagModify", "\346\230\257", 0));
        label->setText(QApplication::translate("BagModify", "\350\257\206\345\210\253\346\212\212\346\225\260\357\274\232", 0));
        checkBox_envelope->setText(QApplication::translate("BagModify", "\344\277\241\345\260\201", 0));
        label_2->setText(QApplication::translate("BagModify", "\346\212\245\350\255\246\347\261\273\345\236\213\357\274\232", 0));
        checkBox_numErrType->setText(QApplication::translate("BagModify", "\346\212\212\346\225\260\351\224\231\350\257\257", 0));
        pushButton_OK->setText(QApplication::translate("BagModify", "\347\241\256\350\256\244", 0));
        label_4->setText(QApplication::translate("BagModify", "\346\216\210\346\235\203\344\277\241\346\201\257\357\274\232", 0));
        pushButton_Cancel->setText(QApplication::translate("BagModify", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class BagModify: public Ui_BagModify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAGMODIFY_H
