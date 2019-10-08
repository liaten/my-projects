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
    ofstream outmax;
    outmax.open("output_max.txt", ios::trunc);
    ofstream outmin;
    outmin.open("output_min.txt", ios::trunc);
    string word;
    string word1;
    string word2;
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
    in.close();
    out.close();
    if(minw!=1024000 || maxw!=0) /*cout<<endl<<minw<<endl<<maxw<<endl;*/
    {
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
        /*
        char cwd1[512];char cwd2[512];
        for(int i=0;i<512;i++){
            cwd1[i]=0;
            cwd2[i]=0;
        }
        while(in>>word)
        {
            if(cwd1[0]='0') {strcpy(cwd1, word.c_str());continue;}
            if(cwd2[0]='0') strcpy(cwd2, word.c_str());
            if(strcmp(cwd1,cwd2))
            {
                out.open("min2.txt", ios::app);
                cout<<cwd1<<' '<<cwd2;
                out.close();
            }
            in.close();
        }*/
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
    else cout<<"В файле не введены слова, файл пустой, или файл не открылся."<<endl;
    return 0;
}