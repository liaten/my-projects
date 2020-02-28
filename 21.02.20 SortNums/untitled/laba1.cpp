#include "laba1.h"
#include "ui_laba1.h"
#include <iostream>
#include <time.h>   //рандом по времени
#include <fstream>  //текстовики
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QVector>
#include <QProcess>
#include <QFile>

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
    ui->label_3->setText("");
    ui->label_4->setText("");
    QString number1 = ui -> number -> text();
    int N = number1.toInt();
    int* a = new int [N];
        srand (time(NULL));
        ofstream out;          // Поток вывода
        out.open("start.txt", ios::trunc);
        QString temp,temp2;
        for (int i=0;i<N;i++)
        {
            a[i]=rand() % (N+1);
            //ui->label_3->setNum(a[i]);
            out<<a[i];
            temp = ui->label_3 ->text();
            temp2=QString::number(a[i]);
            temp.append(temp2);
            ui->label_3->setText(temp);
            if(i<N-1)
            {
                out<<' ';
                temp = ui->label_3 ->text();
                temp.append(' ');
                ui->label_3->setText( temp );
            }
        }

        /*int cellcount=N,BUFF;       // BUFF - буферная переменная; cellcount - счетчик места
        while(cellcount!=0)
        {
            for(int i=N;i>-1;i++)        //  i - счетчик наибольшего числа
            {
                for(int j=0;j<cellcount;j++)  //  j - счетчик места в массиве
                {
                    if(a[j]==i)
                    {
                        BUFF=a[cellcount-1];
                        a[cellcount-1]=a[j];
                        a[j]=BUFF;
                        cellcount--;
                    }
                }
            }
        }

        ofstream out2;          // Поток вывода
        out2.open("final.txt", ios::trunc);
        for(int i=0;i<N;i++)
        {
            out2<<a[i];
            temp = ui->label_4 ->text();
            temp2=QString::number(a[i]);
            temp.append(temp2);
            ui->label_4->setText(temp);
            if(i<N-1)
            {
                out2<<' ';
                temp = ui->label_4 ->text();
                temp.append(' ');
                ui->label_4->setText( temp );
            }
        }*/
}

void Laba1::on_pushButton_2_clicked()
{
    ui->label_4->setText("");
    QString number1 = ui -> number -> text();
    QString temp,temp2;
    ofstream out;
    out.open("start.txt", ios::in);
    int N = number1.toInt();
    int* a = new int [N];

    int cellcount=N,BUFF;       // BUFF - буферная переменная; cellcount - счетчик места;
        for(int i=N;i>-1;i++)        //  i - счетчик наибольшего числа
        {
            for(int j=0;j<cellcount;j++)  //  j - счетчик места в массиве
            {
                if(a[j]==i)
                {
                    BUFF=a[cellcount-1];
                    a[cellcount-1]=a[j];
                    a[j]=BUFF;
                    cellcount--;
                }
            }
        }

    ofstream out2;          // Поток вывода
    out2.open("final.txt", ios::trunc);
    for(int i=0;i<N;i++)
    {
        out2<<a[i];
        temp = ui->label_4 ->text();
        temp2=QString::number(a[i]);
        temp.append(temp2);
        ui->label_4->setText(temp);
        if(i<N-1)
        {
            out2<<' ';
            temp = ui->label_4 ->text();
            temp.append(' ');
            ui->label_4->setText( temp );
        }
    }
}
