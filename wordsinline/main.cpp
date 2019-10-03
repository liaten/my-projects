#include <iostream>
#include <clocale>
//#include <cctype>
#include <cstring> //библиотека строк, для предварительного опустошения строки как массива
//#include <cstdio>
using namespace std;

int main()
{
    setlocale( LC_ALL,"Russian" );
    //cout << "Программа предназначена для нахождения наибольшего и наименьшего слова в строке\n";
    const size_t N = 512;
    char s[N];
    int Acount=0;
    int Bcount=0;
    int minword=N;
    int maxword=0;
    char savemin[N];
    char savemax[N];
    memset(s, NULL, sizeof(s));

    while (!(Acount==0)!=1)
    {
        cout << "Введите текст, не используя русские буквы. Они не работают! :( ...\nВведите строчку: ";
        fgets( s, N, stdin );
        for(int i=0;i<N;i++)
        {
            if(isalnum(s[i])) Acount++;
            if(Acount>0)break;
        }
    }
    //тут меняю код
    for(int i=0;i<N;i++)
    {
        if(!isalnum(s[i])) continue;
        else
        {
            for(int j=i;j<N;j++)
            {
                if(Bcount>maxword)
                {
                    maxword=Bcount;
                }
                if(Bcount<minword)
                {
                    minword=Bcount;
                }
                if(isalnum(s[j])) Bcount++;
                else if(s[j]=' ') break;
                else continue;
            }
        }
    }
    return 0;
}