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
                UPP=0;
                COUNT=0;
                for(int i=0;i<s.length();i++)
                {
                    if(isupper(s[i]))
                    {
                        UPP++;
                        if(UPP==1)
                        {
                            do
                            {
                                i++;
                            } while (islower(s[i]));
                        }
                        if(UPP==2)
                        {
                            i++;
                            s[i]='.';
                            i++;
                            if(s[i]==' ')
                            {
                                s[i]=s[i+1];
                                i++;
                                s[i]='.';
                            }
                        }
                    }
                    if(s[i]=='.' && s[i-1]=='.')s[i]=' ';
                    if(isdigit(s[i]))
                    {
                        COUNT+=(s[i]-'0');
                        s[i]=' ';
                    }
                }
                COUNT2=0;
                for(int i=0;i<s.length();i++)
                {
                    if(s[i]=='.')
                    {
                        COUNT2++;
                        if(COUNT2==2)
                        {
                            i++;
                            while(s[i]==' ')
                            {
                                s.erase(i,1);
                            }
                        }
                    }
                }
                out<<s<<' '<<COUNT<<endl;
                cout<<s<<' '<<COUNT<<endl;
            }
        }
        else cout<<"Файл вывода не открылся\n";
    }
    else cout<<"Файл ввода не открылся\n";

    return 0;
}