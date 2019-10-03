#include <iostream>
#include <clocale>
#include <fstream> //для работы с текстом
#include <cstring> //проверяет длину строки
using namespace std;

int main()
{
    setlocale(LC_ALL,"Rus");
    ifstream file;
    file.open ("input.txt", ios::out);
    
/*
    ifstream file2;
    file2.open ("output.txt",ios::in);*/

    string word;
    int minw=1024;
    int maxw=0;
    while (file >> word)
    {
        for(int i=0;i<word.length();i++)
        {
            if (!isalpha(word[i]))word[i]=NULL;
        }
        if(word.length()>maxw)maxw=word.length();
        else if(word.length()<minw)minw=word.length();
        if(word[0]!=NULL)cout<<"\"" << word <<"\""<< '\t';
    }
    if(minw!=1024 || maxw!=0) /*cout<<endl<<minw<<endl<<maxw<<endl;*/
    {
        while (file >> word)
        {
            ofstream out;          // поток для записи
            out.open("output.txt"); // окрываем файл для записи
                out << "Hello World!" << endl;
           /* if(word.length()==minw)
            {
            }
            else if(word.length()==maxw)
            {
            }*/
        }
        cout<<endl;
    }
    else cout<<"В файле не введены слова, файл пустой, или файл не открылся."<<endl;

    return 0;
}