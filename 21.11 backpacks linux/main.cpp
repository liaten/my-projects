#include <iostream>
using namespace std;

int main()
{
    int tCOUNT; //счетчик вещей
    int bCOUNT; //счетчик рюкзаков
    cout<<"Введите количество рюкзаков: "; cin>>bCOUNT;
    cout<<"Введите количество вещей: "; cin>>tCOUNT;
    int s[tCOUNT];
    for(int i=0;i<tCOUNT;i++)
    {
        cout<<"Введите массу вещи "<<i+1<<" :";
        cin>>s[i];
    }
    for (int i = 0; i < tCOUNT; i++)
    {
        for (int n = 0; n < tCOUNT; n++)
        {
            if (s[n] > s[n+1])
            {
                s[tCOUNT] = s[n];
                s[n] = s[n + 1];
                s[n + 1] = s[tCOUNT];
            }
        }
    }
    cout<<"Все вещи в порядке возрастания выглядят так: ";
    for (int i = 0; i < tCOUNT; i++)
    {
        cout<<'['<<s[i]<<']';
    }
    putchar('\n');
    return 0;
}