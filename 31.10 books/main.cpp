#include <iostream>     //ввод вывод
#include <clocale>
#include <fstream>      //для работы с текстовыми файлами
//#include <cstring>      //проверяет длину строки
#include <string>
#include <map>
//#include <windows.h>    //библа винды

using namespace std;    //ввод вывод
struct library
{
    char *author;   // Фамилия автора книги
    char *title;    // Заголовок
    char *firm;     // Издательство
    int year;       // Год издания
    int pages;      // Количество страниц
    int value;      // Стоимость
};

int main()
{
    setlocale(LC_ALL,"Rus");
    /*SetConsoleCP(1251);
    SetConsoleOutputCP(1251);*/
    ifstream in;    // Поток ввода
    in.open ("input.txt",ios::in);
    short STRCOUNT=1;   // Счетчик строк для внесения в структуру
    if(in.is_open())
    {
        cout<<"Файл ввода открылся\n";
        ofstream out;          // Поток вывода
        out.open("output.txt", ios::trunc);
        if(out.is_open())
        {
            cout<<"Файл вывода открылся\n";
            string s;
            while (getline(in,s)) STRCOUNT++;
            STRCOUNT/=6;
            map<string,library>vars;
            for(int i=1;i<STRCOUNT+1;++i)
            {
                vars["Book"+to_string(i)];
                cout<<"Book"+to_string(i)<<endl;
            }
        }
        else cout<<"Файл вывода не открылся\n";
    }
    else cout<<"Файл ввода не открылся\n";
    system("pause");
    return 0;
}