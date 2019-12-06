#include <iostream>
#include <map>
using namespace std;
//английские деньги

struct eng_money
{
public:
//012***6
//  0)Ввод
    void enter(eng_money,unsigned &i)
    {
        cout<<"Введите данные денежной суммы №"<<i<<'\n';
        cout<<"Фунты: ";
        cin>>pounds;
        cout<<"Шиллинги: ";
        cin>>shillings;
        cout<<"Пенсы: ";
        cin>>pence;
    }
//  6)Вывод
    void output(eng_money,unsigned &i)
    {
        cout<<"Денежная сумма №"<<i<<": <<"<<pounds<<'-'<<shillings<<'-'<<pence<<">>\n";
    }
//  1)Проверка корректности значения
    void correct_value(eng_money)
    {
        if(pence>=12)
        {
            shillings+=(pence/12);
            pence%=12;
        }
        if(shillings>=20)
        {
            pounds+=(shillings/20);
            shillings%=20;
        }
    }
//  2)Увеличение заданной суммы
    void increase(eng_money,unsigned &i)
    {
        unsigned pounds_increment, shillings_increment, pence_increment;
        cout<<"На сколько хотите увеличить денежную сумму №"<<i<<"? \nФунты: ";
        cin>>pounds_increment;
        cout<<"Шиллинги: ";
        cin>>shillings_increment;
        cout<<"Пенсы: ";
        cin>>pence_increment;
        if(pounds_increment!=0)
        {
            shillings_increment+=(pounds_increment*20);
            pounds_increment=0;
        }
        if(shillings_increment!=0)
        {
            pence_increment+=(shillings_increment*12);
            shillings_increment=0;
        }
        if(pounds!=0)
        {
            shillings+=(pounds*20);
            pounds=0;
        }
        if(shillings!=0)
        {
            pence+=(shillings*12);
            shillings=0;
        }
        pence+=pence_increment;
    }
private:
    unsigned pounds;    //фунты
    unsigned shillings; //шиллинги
    unsigned pence;     //пенсы
};
int main()
{
    unsigned N; //количество денежных сумм
    map<string,eng_money>purse;
    cout<<"Введите количество денежных сумм: ";
    cin>>N;
    for(unsigned i=1;i<N+1;i++)
    {
        purse[to_string(i)].enter(purse[to_string(i)],i);       //ввод
        purse[to_string(i)].correct_value(purse[to_string(i)]); //проверка и перевод
        purse[to_string(i)].increase(purse[to_string(i)],i);    //увеличение
        purse[to_string(i)].correct_value(purse[to_string(i)]); //проверка и перевод
        purse[to_string(i)].output(purse[to_string(i)],i);      //вывод

    }return 0;
}