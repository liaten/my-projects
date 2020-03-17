#include "numbersort.h"
#include "Random.h"
#include "ui_numbersort.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QVector>
#include <QProcess>
//#include <QStatusBar>
//#include <QTimer>

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

void NumberSort::shekerSort(QVector <int>& mass, int count)
{
    QMessageBox m;
    int left = 0, right = count - 1; // левая и правая границы сортируемой области массива
  int flag = 1;  // флаг наличия перемещений
  //int prohodnum=0;
  // Выполнение цикла пока левая граница не сомкнётся с правой
  // или пока в массиве имеются перемещения
  while ((left < right) && flag > 0)
  {
    flag = 0;
    for (int i = left; i<right; i++)  //двигаемся слева направо
    {
      if (mass[i]<mass[i + 1]) // если следующий элемент меньше текущего,
      {             // меняем их местами
        int t = mass[i];
        mass[i] = mass[i + 1];
        mass[i + 1] = t;
        flag = 1;      // перемещения в этом цикле были
      }
    }
    right--; // сдвигаем правую границу на предыдущий элемент
    for (int i = right; i>left; i--)  //двигаемся справа налево
    {
      if (mass[i - 1]<mass[i]) // если предыдущий элемент больше текущего,
      {            // меняем их местами
        int t = mass[i];
        mass[i] = mass[i - 1];
        mass[i - 1] = t;
        flag = 1;    // перемещения в этом цикле были
      }
    }
    left++; // сдвигаем левую границу на следующий элемент
    //prohodnum++;
    //m.setText("Выполнено проходов: "+QString::number(prohodnum));
    //QTimer::singleShot(10, &m, SLOT(close()));
    //m.exec();
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
        shekerSort(array, array.size() - 1);
        time = timer.elapsed() ;
        QMessageBox::information(this,"Info","Массив был отсортирован за " + QString::number(time) + " миллисекунд(ы) ");

        buff = "";
        QTextStream writestream(&Output);
        for(int i = 0; i < array.size()-1; i++){
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
