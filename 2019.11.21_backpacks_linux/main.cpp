#include <iostream>
using namespace std;

//факториал
long double fact(int N)
{
    if(N < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (N == 0) // если пользователь ввел ноль,
        return 1; // возвращаем факториал от нуля
    else // Во всех остальных случаях
        return 2 * fact(N - 1); // делаем рекурсию.
}

int main()
{
    int tCOUNT; //вещи
    const int bCOUNT=2; //рюкзаки
    cout<<"Введите количество вещей: "; cin>>tCOUNT;
    int mas[tCOUNT];  //начальный массив масс вещей
    for(int i=0;i<tCOUNT;i++)
    {
        cout<<"Введите массу вещи "<<i+1<<" :";
        cin>>mas[i];
    }
    // сортировка массива по возрастанию
    for (int i = 0; i < tCOUNT; i++)
    {
        for (int n = 0; n < tCOUNT; n++)
        {
            if (mas[n] > mas[n+1])
            {
                mas[tCOUNT] = mas[n];
                mas[n] = mas[n + 1];
                mas[n + 1] = mas[tCOUNT];
            }
        }
    }
    //вычисление минимальной разницы масс вещей
    /*int mindiff;    //минимальная разница
    mindiff=mas[tCOUNT-1];
    for(int i=0;i<tCOUNT;i++)
        for(int j=0;j<tCOUNT;j++)
            if(abs(mas[i]-mas[j])<mindiff && abs(mas[i]-mas[j])!=0)
                mindiff=abs(mas[i]-mas[j]);
    cout<<"Минимальная разница масс вещей: "<<mindiff<<endl;*/
    //вычисление идеальной массы среднего рюкзака
    /*int defmas;    //Остаток от деления
    int sum=0; //сумма всех масс
    for(int i=0;i<tCOUNT;i++) sum+=mas[i];
    defmas=sum%bCOUNT;
    cout<<"Остаток от деления суммы масс на количество рюкзаков: "<<defmas<<endl;*/
    //вывод начального массива
    cout<<"Все вещи в порядке возрастания: ";
    for (int i = 0; i < tCOUNT; i++) cout<<mas[i]<<' ';
    putchar('\n');
    int back1[tCOUNT];    //1 рюкзак
    int back2[tCOUNT];    //2 рюкзак
    int mas1;   //масса 1 рюкзака
    int mas2;   //масса 2 рюкзака
    long max_i=fact(tCOUNT);   //переборы
    cout<<"Максимальное число переборов: "<<max_i*2<<endl;
    int masdif; //разница масс рюкзаков
    int min_masdif=mas[tCOUNT-1]; //минимальная разница масс рюкзаков
    for(int i=1;i<max_i;i++)
    {
        mas1=0;mas2=0;
        for(int j=0;j<tCOUNT;j++)
        {
            if(i&(1<<j))
            {
                back1[j]=mas[j];
                back2[j]=0;
            }
            else
            {
                back2[j]=mas[j];
                back1[j]=0;
            }
            mas1+=back1[j];
            mas2+=back2[j];
        }
        masdif=abs(mas1-mas2);
        if(masdif<min_masdif) min_masdif=masdif;
        //cout<<min_masdif<<endl;
        //for(int k=0;k<tCOUNT;k++) cout<<back1[k]<<'\t'<<back2[k]<<'\n';
    }
    for(int i=1;i<max_i;i++)
    {
        mas1=0;mas2=0;
        for(short j=0;j<tCOUNT;j++)
        {
            if(i&(1<<j))
            {
                back1[j]=mas[j];
                back2[j]=0;
            }
            else
            {
                back2[j]=mas[j];
                back1[j]=0;
            }
            mas1+=back1[j];
            mas2+=back2[j];
        }
        masdif=abs(mas1-mas2);
        if(masdif==min_masdif)break;
    }
    //for(int k=0;k<tCOUNT;k++) cout<<back1[k]<<'\t'<<back2[k]<<'\n';
    cout<<"Масса 1 рюкзака: "<<mas1<<endl;
    cout<<"Масса 2 рюкзака: "<<mas2<<endl;
    cout<<"Массы вещей первого рюкзака: ";
    for(int k=0;k<tCOUNT;k++)
    {
        if(back1[k]!=0)cout<<back1[k]<<' ';
    }
    cout<<"\nМассы вещей второго рюкзака: ";
    for(int k=0;k<tCOUNT;k++)
    {
        if(back2[k]!=0)cout<<back2[k]<<' ';
    }
    cout<<endl;
    return 0;
}