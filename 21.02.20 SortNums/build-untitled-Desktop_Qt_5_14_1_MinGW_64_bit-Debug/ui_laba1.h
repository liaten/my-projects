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
#include <QtWidgets/QGridLayout>
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
    QSpinBox *number;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;

    void setupUi(QDialog *Laba1)
    {
        if (Laba1->objectName().isEmpty())
            Laba1->setObjectName(QString::fromUtf8("Laba1"));
        Laba1->resize(721, 72);
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

        number = new QSpinBox(Laba1);
        number->setObjectName(QString::fromUtf8("number"));
        number->setMinimum(1);
        number->setMaximum(999999999);

        horizontalLayout_2->addWidget(number);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        pushButton = new QPushButton(Laba1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(Laba1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(Laba1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        label_6 = new QLabel(Laba1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_5 = new QLabel(Laba1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(Laba1);

        QMetaObject::connectSlotsByName(Laba1);
    } // setupUi

    void retranslateUi(QDialog *Laba1)
    {
        Laba1->setWindowTitle(QCoreApplication::translate("Laba1", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Laba1", "\320\227\320\260\320\264\320\260\321\207\320\260: \320\276\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 N \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\321\205 \321\207\320\270\321\201\320\265\320\273 \320\276\321\202 0 \320\264\320\276 N \320\274\320\265\321\202\320\276\320\264\320\276\320\274 \321\203\320\261\321\213\320\262\320\260\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("Laba1", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\276 N: ", nullptr));
        pushButton->setText(QCoreApplication::translate("Laba1", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\270 \320\276\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        label_6->setText(QCoreApplication::translate("Laba1", "\320\236\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \320\274\320\260\321\201\321\201\320\270\320\262:", nullptr));
        label_5->setText(QCoreApplication::translate("Laba1", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \320\274\320\260\321\201\321\201\320\270\320\262:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Laba1: public Ui_Laba1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABA1_H
