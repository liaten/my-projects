#include <iostream>
#include <clocale>
//#include <cstring>
//#include <cstdio>
using namespace std;
int main()
{
    setlocale( LC_ALL,"Russian" );
    //cout << "Программа предназначена для нахождения наибольшей и наименьшей цифры среди других цифр внутри строки.\n";
    const size_t N = 512;
    char s[N];
    int Acount=0;
    char min_char='9';
    char max_char='0';
    //memset(s, NULL, sizeof(s));

    //тут можно ничего не менять! всё и так работает)
    while (!(Acount==0)!=1)
    {
        cout << "Запрашиваю строчку в которой должны находиться цифры...\nВведите строчку: ";
        fgets( s, N, stdin );
        for(int i=0;i<N;i++)
        {
            if(s[i]>='0' && s[i]<='9')Acount++;
        }
    }
    //тут меняю код
        for(int i=0;i<N;i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                if(s[i]>max_char) max_char=s[i];
                if(s[i]<min_char) min_char=s[i];
            }
        }

    cout << "\nМинимальное значение = " << min_char << "\nМаксимальное значение = " << max_char<<endl;
    return 0;
}