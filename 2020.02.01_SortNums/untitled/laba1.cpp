#include "laba1.h"
#include "ui_laba1.h"
#include <iostream>
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
        out.close();

        int BUFF_FOR_NUMS;
        int COUNTER=1;
        int maxnum=N;   // правильно заполненное макс число
        int maxmax=N;   // ЧИСЛОВОЙ МАКСИМУМ
        ofstream changes;   //Поток изменений
        changes.open("changes.txt",ios::trunc);
        while(maxmax!=-1)
        {
            for(int i=0;i<maxnum;i++)
            {
                if(a[i]==maxmax)
                {
                    BUFF_FOR_NUMS=a[maxnum-1];
                    a[maxnum-1]=a[i];
                    a[i]=BUFF_FOR_NUMS;
                    maxnum--;
                }
            }
            for(int i=0;i<N;i++)
            {
                changes<<a[i];
                if(i<N-1)
                {
                    changes<<' ';
                }
            }
            changes<<'\n';
            COUNTER++;
            if(COUNTER%2==0) maxmax--;
        }
        changes.close();

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
            out2.close();
        }
}
