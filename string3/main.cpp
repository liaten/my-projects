#include <iostream>
#include <clocale>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    setlocale( LC_ALL,"Russian" );
    //cout << "Программа предназначена для нахождения числа по его порядку среди других чисел внутри строки.\n";
    const size_t N = 512;
    char s[N];
    int f;
    int Acount=0;
    int Bcount=0;
    char save;

    while (!(Acount==0)!=1)
    {
        cout << "Запрашиваю строчку в которой должны находиться цифры...\nВведите строчку: ";
        fgets( s, N, stdin );
        for(int i=0;i<N;i++)
        {
            if(s[i]>='0' && s[i]<='9')Acount++;
        }
    }
    while ((Bcount==f)!=1)
    {
        cout << "\nЗапрашиваю порядковое число для определения цифры. Введенное число должно быть меньше длины строки.\nВведите число: ";
        cin >> f;
        for(int i=0;i<N;i++)
        {
            if(Bcount==f){save=s[i-1];break;}
            if(s[i]>='0' && s[i]<='9' && Bcount<f)Bcount++;
        }
    }
    cout << "Цифра № " << f << " = " << save;
    return 0;
}