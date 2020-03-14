#include "numbersort.h"
#include "Random.h"
#include "ui_numbersort.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QVector>
#include <QProcess>
#include <QStatusBar>
NumberSort::NumberSort(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NumberSort)
{
    ui->setupUi(this);
}

NumberSort::~NumberSort()
{
    delete ui;
}

void NumberSort::quickSort(QVector <int>& array, int left, int right) {

//QuickSort//
   int i = left, j = right;
    int temp;
    int pivot = array[(left + right) / 2];

    while (i <= j) {
        while (array[i] < pivot){
            i++;
        }
        while (array[j] > pivot){
            j--;
        }
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
}

    if (left < j)
        quickSort(array, left, j);
    if (i < right)
        quickSort(array, i, right);

}

void NumberSort::SortShortArray(QVector <int>& ar){
    int temp;
    for (int i = 0; i < ar.size() - 1; i++) {
            for (int j = 0; j < ar.size() - i - 1; j++) {
                if (ar[j] > ar[j + 1]) {
                    // меняем элементы местами
                    temp = ar[j];
                    ar[j] = ar[j + 1];
                    ar[j + 1] = temp;
                }
            }
        }
}

bool NumberSort::sheck_fucntion(QVector <int>& mess){
    for(int i = 0; i < mess.size()-1; i++){
        if(mess[i] <= mess[i+1]){
            continue;
        }else{

            return false;
        }
    }
    return true;
}

void NumberSort::NaturalSort(QVector <int>& array, int size){
    /*  Создаем промежуточные массивы
     *  Серия 1 - mess_1
     *  Cерия 2 - mess_2
     */
    QVector<int> mess_1;
    QVector<int> mess_2;
    QVector<int> result;
    bool shit = true;

    while(!sheck_fucntion(array)){
        /*Сначала записываем первое чисо массива, если оно меньше второго, то
         * записываем в mess_1,а если нет то в mess_1 и меняем ход проверки
         * на mess_2
         */
       if(array[0] <= array[1]){
           mess_1.push_back(array[0]);
           mess_1.push_back(array[1]);
           shit = true;
       }else{
           mess_1.push_back(array[0]);
           mess_1.push_back(0);
           mess_2.push_back(array[1]);
           shit = false;
       }

       for(int j = 1; j < size-1; j++){
           /*Используем распеределение по сериям с помочью флага - shit
            * Если true - mess_1
            * Если False - mess_2
            */
           if(shit){
                if(array[j] <= array[j+1]){
                    mess_1.push_back(array[j+1]);
                }else{
                    mess_1.push_back(0);
                    mess_2.push_back(array[j+1]);
                    shit = false;
                }

           }else{
               if(array[j] <= array[j+1]){
                   mess_2.push_back(array[j+1]);
               }else{
                   mess_2.push_back(0);
                   mess_1.push_back(array[j+1]);
                   shit = true;
               }

           }

       }
       QVector<int> result;
       QVector<int> res;
       mess_1.push_back(0);
       mess_2.push_back(0);
       int m1 = 0;
       int m2 = 0;
       int chg = array.size() - 1;
       int count = 0;
       array.clear();
       while(true){
            while(mess_1[m1] != 0){
                result.push_back(mess_1[m1]);
                count++;
                m1++;
            }
            if(m1 < mess_1.size()-1){
                m1++;
            }

            while(mess_2[m2] != 0){
                 result.push_back(mess_2[m2]);
                 count++;
                 m2++;
            }
            if(m2 < mess_2.size()-1){
                m2++;
            }

            quickSort(result,0,result.size() - 1);
            for(int i = 0; i < result.size(); i++){
                 array.push_back(result[i]);
            }

            result.clear();

            if(count >= chg ){
                 break;
             }
        }
        m1 = 0;
        m2 = 0;
        res.clear();
        mess_1.clear();
        mess_2.clear();
    }

}

void NumberSort::on_SortArray_clicked(){
    QString buff;
    QString check;
    QTime timer;
    int time;
    QVector<int> array ;
    if(flag){
        // Creating File:"output.txt"
        QFile Input("input.txt");
        QFile Output("output.txt");
        if(!Input.open(QIODevice::ReadOnly|QIODevice::Text)){
            ui->statusBar->showMessage("Файл 'input.txt' не был создан.");
            return;
        }

        if(!Output.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
            ui->statusBar->showMessage("Файл 'output.txt' не был создан.");
            return;
        }
        Output.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate);
        // Reading from "input" file
        QTextStream readstream(&Input);
        while(!readstream.atEnd()){
            readstream >> buff;
            array.push_back(buff.toInt());
        }
        Input.close();

        // Sort function
        // quickSort(array,0,array.size() - 1);

        // Writting sorted array

        timer.start();
        NaturalSort(array, array.size() - 1);
        time = timer.elapsed() ;
        QMessageBox::information(this,"Info","Массив был отсортирован за " + QString::number(time) + " миллисекунд ");

        buff = "";
        QTextStream writestream(&Output);
        for(int i = 0; i < array.size(); i++){
            buff =QString::number(array[i]) +  " ";
            writestream << buff;
            buff = "";
        }
        Output.close();


    }else{
         ui->statusBar->showMessage("Не был создан массив чисел");
         return;
    }
}

void NumberSort::on_CreatArray_clicked()
{
   bool ok;
   int buff;
   QString str;
   QString Number = ui->lineEdit->text();
   N = Number.toInt(&ok,10);

   // Cheaking of N - amount of numbers
   if(!ok){
       ui->statusBar->showMessage("Ошибка! Введено не число");
       return;
   }else if(N <= 0){
           ui->statusBar->showMessage("Число N должно быть больше 0");
           return;
   }
   flag = true;
   ui->statusBar->clearMessage();

   //Creating File:"input.txt"

   QFile Input("input.txt");
   if(!Input.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Truncate)){
       ui->statusBar->showMessage("Файл 'input.txt' не был создан.");
   }

   // Changing of stream
   QTextStream writestream(&Input);

   // Creating and writing random number of 1 to 1 million

   for(int i = 0; i < N; i++){
       buff = Random::get(1,N);
       str.setNum(buff);
       str += " ";
       writestream << str;
   }

   // Show that work is done
   str = "";
   str += QString::number(N) + " Чисел было сгенерированно.";

   QMessageBox::information(this,"Info",str);

   Input.close();
}

void NumberSort::on_ShowCreatedArray_clicked()
{
    if(flag){
    QProcess* proc=new QProcess(this);
    proc->start("notepad ./input.txt");
    }else{
        ui->statusBar->showMessage("Не был создан массив чисел для просмотра");
        return;
    }
}

void NumberSort::on_ShowSortArray_clicked()
{
    if(flag){
    QProcess* proc=new QProcess(this);
    proc->start("notepad ./output.txt");
    }else{
        ui->statusBar->showMessage("Не был создан массив чисел для обработки просмотра");
        return;
    }
}
