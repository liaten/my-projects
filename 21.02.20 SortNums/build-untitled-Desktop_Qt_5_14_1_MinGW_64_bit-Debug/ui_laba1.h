/********************************************************************************
** Form generated from reading UI file 'laba1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABA1_H
#define UI_LABA1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Laba1
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBox;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Laba1)
    {
        if (Laba1->objectName().isEmpty())
            Laba1->setObjectName(QString::fromUtf8("Laba1"));
        Laba1->resize(473, 72);
        horizontalLayout = new QHBoxLayout(Laba1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(Laba1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Laba1);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label);

        spinBox = new QSpinBox(Laba1);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton = new QPushButton(Laba1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(Laba1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_4->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout_4);


        retranslateUi(Laba1);

        QMetaObject::connectSlotsByName(Laba1);
    } // setupUi

    void retranslateUi(QDialog *Laba1)
    {
        Laba1->setWindowTitle(QCoreApplication::translate("Laba1", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Laba1", "\320\227\320\260\320\264\320\260\321\207\320\260: \320\276\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 N \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\321\205 \321\207\320\270\321\201\320\265\320\273 \320\276\321\202 0 \320\264\320\276 N \320\274\320\265\321\202\320\276\320\264\320\276\320\274 \321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("Laba1", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\276 N: ", nullptr));
        pushButton->setText(QCoreApplication::translate("Laba1", "\320\236\320\272\320\265\320\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Laba1", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Laba1: public Ui_Laba1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABA1_H
