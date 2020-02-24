#include "laba1.h"
#include "ui_laba1.h"
#include <iostream>
//#include <QMessageBox>
#include <time.h>   //рандом по времени
#include <fstream>  //текстовики

using namespace std;

Laba1::Laba1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Laba1)
{
    ui->setupUi(this);
}

Laba1::~Laba1()
{
    delete ui;
}

void Laba1::on_pushButton_clicked()
{
    QString number1 = ui -> number -> text();
    int N = number1.toInt();
    //ui->label_3->setNum(N);
    int* a = new int [N];
    srand (time(NULL));
    for (int i=0;i<N;i++)
    {
        a[i]=rand() % (N+1);
        ui->label_3->setNum(a[i]);

    }
}

void Laba1::on_pushButton_2_clicked()
{
    QApplication::quit();
}
