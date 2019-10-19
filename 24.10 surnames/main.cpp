#include <iostream>     //ввод вывод
#include <clocale>      //русский язык
#include <fstream>      //для работы с текстом
#include <cstring>      //проверяет длину строки
#include <windows.h>    //win api на все случаи жизни
using namespace std;    //ввод вывод

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream in;
    in.open ("input.txt",ios::in);
    ofstream out;          // поток для записи
    out.open("output.txt", ios::trunc);
    string word;
    int minw=2048000;
    int maxw=0;
    while (in >> word)
    {
        for(int i=0;i<word.length();i++)
        {
            if (!isalnum(word[i])) word[i]=' ';
            if (isupper(word[i])) word[i]=tolower(word[i]);
        }
        if((word.length()>maxw) && (word[0]!=' '))maxw=word.length();
        else if((word.length()<minw) && (word[0]!=' ') )minw=word.length();
        if(word[0]!=' ')out<< word <<" ";
    }
    if(minw!=2048000 || maxw!=0)
    {
        in.close();
        out.close();
        cout<<"Максимальная длина слова: "<<maxw<<endl<<"Минимальная длина слова: "<<minw<<endl;
        in.open ("output.txt", ios::in);
        while(in>>word)
        {
            if(word.length()==maxw)
            {
                outmax.close();
                outmax.open("output_max.txt", ios::app);
                outmax<<word<<' ';
            }
            if(word.length()==minw)
            {
                outmin.close();
                outmin.open("output_min.txt", ios::app);
                outmin<<word<<' ';
            }
        }
        in.close();
        out.close();outmin.close();outmax.close();
        cout<<"Все обработанные слова: ";
        in.open("output.txt",ios::in);
        while(in>>word) cout<<word<<' ';
        in.close();
        in.open("output_max.txt",ios::in);
        cout<<"\nВсе слова с длиной "<<maxw<<": ";
        while(in>>word) cout<<word<<' ';
        in.close();
        in.open("output_min.txt",ios::in);
        cout<<"\nВсе слова с длиной "<<minw<<": ";
        while(in>>word) cout<<word<<' ';
    }
    //else cout<<"В файле не введены слова, файл пустой, или файл не открылся."<<endl;
    else
    {
    }
    return 0;
}