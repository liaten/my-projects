#include <iostream>
#include <clocale>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    setlocale( LC_ALL,"Russian" );
    cout << "Программа предназначена для нахождения числа по его порядку среди других чисел внутри строки.\n";
    const size_t N = 512;
    char s[N];
    int f;
    int count=0;
    char save;

    do
    {   metka1:
    f=0;
        //memset(s, NULL, sizeof(s));
        cout << "Введите строчку: ";

        fgets( s, N, stdin );
        for(int i=0;i<N;i++)
        {
            if (s[i]>='0' && s[i]<='9')count++;
        }
        if(count==0)
        {
            cout<<"В стороке отсутствуют какие либо знаки цифр.\nВведите строку еще раз: ";
            fgets( s, N, stdin );
        }
        //char *p = s;
        //while ( *p ) std::cout << static_cast<int>( *p++ ) << ' ';
        cout << endl;
        cout <<"Введите порядковый номер цифры: ";
        cin>>f;

        for(int i=0;i<N;i++){
            if(s[i]>='0' && s[i]<='9' && count!=f)count++;
            if (count==f){
                save=s[i];
                break;}
        }
        //отладка короче))
        cout<<f<<endl<<count<<endl<<save<<endl;
        if ((count==f) && (count!=0)){
            cout<<"Цифра № "<<f<<" = "<<save<<endl<<endl;
            break;}
        else{
            cout<<"В строке нет чисел или поисковое число введено неверно, введите заново\n";
            goto metka1;}
    } while (!(count==f)!=1);
    return 0;
}