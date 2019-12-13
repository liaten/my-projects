#include <iostream>
#include <map>
using namespace std;

//английские деньги
struct eng_money
{
public:
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
    };
//  6)Вывод
    void output(eng_money &money)
    {
        cout<<"Денежная сумма: <<"<<money.pounds<<'-'<<money.shillings<<'-'<<money.pence<<">>\n";
    };
//  1)Проверка корректности значения
    void correct_value(eng_money &money)
    {
        to_pence(money);
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
    };
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
    };
//  3)Сумма двух структур
    eng_money summary(eng_money &money1,eng_money &money2)
    {
        eng_money money_sum;
        if(money1.pounds!=0 || money1.shillings!=0) money1=money1.to_pence(money1);
        if(money2.pounds!=0 || money2.shillings!=0) money2=money2.to_pence(money1);
        money_sum.pence=money1.pence+money2.pence;
        money_sum.correct_value(money_sum);
        money1.correct_value(money1);
        money2.correct_value(money2);
        return money_sum;
    };
//  4)Разность двух структур
    eng_money difference(eng_money &money1,eng_money &money2)
    {
        eng_money money_dif;
        if(money1.pounds!=0 || money1.shillings!=0) money1=money1.to_pence(money1);
        if(money2.pounds!=0 || money2.shillings!=0) money2=money2.to_pence(money1);
        money_dif.pence=money1.pence-money2.pence;
        money_dif.correct_value(money_dif);
        money1.correct_value(money1);
        money2.correct_value(money2);
        return money_dif;
    }
//  5)Перевод суммы в пенсы
    eng_money to_pence(eng_money money)
    {
        if(money.pounds>0)
        {
            money.shillings+=money.pounds*20;
            money.pounds=0;
        }
        if(money.shillings>0)
        {
            money.pence+=money.shillings*12;
            money.shillings=0;
        }
        return money;
    };
    void to_zero(eng_money &money)
    {
      money.pence=0;
      money.shillings=0;
      money.pounds=0;
    }
    void mean(eng_money &money, unsigned &N)
    {
      money.to_pence(money);
      money.pence/=N;
      money.correct_value(money);
      cout<<"Среднее значение: <<"<<money.pounds<<"-"<<money.shillings<<"-"<<money.pence<<">>\n";
    }
private:
    long pounds;    //фунты
    long shillings; //шиллинги
    long pence;     //пенсы
};
int main()
{
    unsigned N; //количество денежных сумм
    map<unsigned,eng_money>purse;
    eng_money purse_dif,purse_sum;
    cout<<"Введите количество денежных сумм: ";
    cin>>N;
    unsigned short enter;
    eng_money money_summary; eng_money full_sum;
    for(unsigned i=1;i<N+1;i++)
    {
        purse[i].enter(purse[i],i);
        purse[i].correct_value(purse[i]);
        purse[i].output(purse[i]);
    }
        cout<<"1)Среднее значение, выраженное в том же виде\n2)Пары сумм,наиболее близких и наиболее далеких по значению\n0)Завершить программу\n";
    do
    {
        cout<<"Введите число: ";
        cin>>enter;
        full_sum.to_zero(full_sum);
        full_sum.output(full_sum);
        if(enter==1)
        {
            for(unsigned i=1;i<N;i++)
            {
              money_summary=money_summary.summary(purse[i],purse[i+1]);
              money_summary.output(money_summary);
              full_sum.summary(full_sum, money_summary);
              full_sum.output(full_sum);
              money_summary.to_zero(money_summary);
            }
            //full_sum.mean(full_sum, N);
        }
        if(enter==2)
        {
            //прога номер 2
        }
    } while (enter!=0);
    
    return 0;
}
