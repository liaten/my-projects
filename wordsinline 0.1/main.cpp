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
    ofstream out;          // поток для записи
    out.open("output.txt", ios::trunc);
    string word;
    int minw=1024;
    int maxw=0;
    while (in >> word)
    {
        for(int i=0;i<word.length();i++)
        {
            if (!isalnum(word[i])) word[i]=' ';
            if (isupper(word[i])) word[i]=tolower(word[i]);
        }
        if(word.length()>maxw)maxw=word.length();
        else if(word.length()<minw)minw=word.length();
        if(word[0]!=' ')out<< word <<" ";
    }
    in.close();
    out.close();
    if(minw!=1024 || maxw!=0) /*cout<<endl<<minw<<endl<<maxw<<endl;*/
    {
        cout<<endl<<maxw<<endl<<minw<<endl;
        in.open ("output.txt", ios::in);
        while(in>>word)
        {
            if(word.length()==maxw)
            {
                out.close();
                out.open("output_max.txt", ios::app);
                out<<word<<' ';
            }
            if(word.length()==minw)
            {
                out.close();
                out.open("output_min.txt", ios::app);
                out<<word<<' ';
            }

        }
        in.close();
        out.close();
        in.open("output_max.txt",ios::in);
        while(1)
        {
            ;
        }

    }

    else cout<<"В файле не введены слова, файл пустой, или файл не открылся."<<endl;

    return 0;
}