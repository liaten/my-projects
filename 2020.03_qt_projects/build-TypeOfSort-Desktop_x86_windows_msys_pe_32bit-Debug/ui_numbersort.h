/********************************************************************************
** Form generated from reading UI file 'numbersort.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMBERSORT_H
#define UI_NUMBERSORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NumberSort
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QPushButton *CreatArray;
    QPushButton *SortArray;
    QPushButton *ShowCreatedArray;
    QPushButton *ShowSortArray;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *NumberSort)
    {
        if (NumberSort->objectName().isEmpty())
            NumberSort->setObjectName(QString::fromUtf8("NumberSort"));
        NumberSort->setEnabled(true);
        NumberSort->resize(492, 179);
        NumberSort->setAutoFillBackground(false);
        centralwidget = new QWidget(NumberSort);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(492, 138));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        CreatArray = new QPushButton(centralwidget);
        CreatArray->setObjectName(QString::fromUtf8("CreatArray"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CreatArray->sizePolicy().hasHeightForWidth());
        CreatArray->setSizePolicy(sizePolicy1);
        CreatArray->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(CreatArray, 0, 0, 1, 1);

        SortArray = new QPushButton(centralwidget);
        SortArray->setObjectName(QString::fromUtf8("SortArray"));
        sizePolicy1.setHeightForWidth(SortArray->sizePolicy().hasHeightForWidth());
        SortArray->setSizePolicy(sizePolicy1);
        SortArray->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(SortArray, 0, 1, 1, 1);

        ShowCreatedArray = new QPushButton(centralwidget);
        ShowCreatedArray->setObjectName(QString::fromUtf8("ShowCreatedArray"));

        gridLayout->addWidget(ShowCreatedArray, 1, 0, 1, 1);

        ShowSortArray = new QPushButton(centralwidget);
        ShowSortArray->setObjectName(QString::fromUtf8("ShowSortArray"));

        gridLayout->addWidget(ShowSortArray, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        NumberSort->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NumberSort);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 492, 21));
        NumberSort->setMenuBar(menubar);
        statusBar = new QStatusBar(NumberSort);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        NumberSort->setStatusBar(statusBar);

        retranslateUi(NumberSort);

        CreatArray->setDefault(true);


        QMetaObject::connectSlotsByName(NumberSort);
    } // setupUi

    void retranslateUi(QMainWindow *NumberSort)
    {
        NumberSort->setWindowTitle(QCoreApplication::translate("NumberSort", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260 \320\234\320\260\321\201\321\201\320\270\320\262\320\260", nullptr));
        label->setText(QCoreApplication::translate("NumberSort", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\207\320\270\321\201\320\273\320\276 N:", nullptr));
        CreatArray->setText(QCoreApplication::translate("NumberSort", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\274\320\260\321\201\321\201\320\270\320\262", nullptr));
        SortArray->setText(QCoreApplication::translate("NumberSort", "\320\236\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\274\320\260\321\201\321\201\320\270\320\262", nullptr));
        ShowCreatedArray->setText(QCoreApplication::translate("NumberSort", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\276\320\267\320\264\320\260\320\275\320\275\321\213\320\271 \320\274\320\260\321\201\321\201\320\270\320\262", nullptr));
        ShowSortArray->setText(QCoreApplication::translate("NumberSort", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\276\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \320\274\320\260\321\201\321\201\320\270\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NumberSort: public Ui_NumberSort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMBERSORT_H
