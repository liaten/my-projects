#include <iostream>     //ввод вывод
#include <clocale>      //русский язык
#include <fstream>      //для работы с текстом
#include <cstring>      //проверяет длину строки
using namespace std;    //ввод вывод

int main()
{
    setlocale(LC_ALL,"Rus");
    ifstream in;
    in.open ("input.txt",ios::in);
    //short UPP1=3;
    short UPP;
    int COUNT;
    int COUNT2;
    if(in.is_open())
    {
        //cout<<"Файл ввода открылся\n";
        ofstream out;          // поток для записи
        out.open("output.txt", ios::trunc);
        if(out.is_open())
        {
            //cout<<"Файл вывода открылся\n";
            string s;
            while (getline(in,s))
            {
                
            }
        }
        else cout<<"Файл вывода не открылся\n";
    }
    else cout<<"Файл ввода не открылся\n";
    system("pause");
    return 0;
}