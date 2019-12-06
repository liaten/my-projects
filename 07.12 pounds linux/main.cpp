#include <iostream>
#include <map>
using namespace std;
//английские деньги

struct eng_money
{
public:
//  0)Ввод
    void enter(eng_money,unsigned i)
    {
        cout<<"Введите данные кошелька №"<<i<<endl;
        cout<<"Фунты: ";
        cin>>pounds;
        cout<<"Шиллинги: ";
        cin>>shillings;
        cout<<"Пенсы: ";
        cin>>pence;
    }
//  1)Проверка корректности значения
    bool correct_value(eng_money)
    {
        if(shillings>=20) return 0;
        if(pence>=12) return 0;
        return 1;
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
        purse[to_string(i)].enter(purse[to_string(i)],i);
        cout<<purse[to_string(i)].correct_value(purse[to_string(i)])<<endl; //проверка на корректность значения
    }
    cout<<"Выберите действие:\n1)Проверка корректности значения\n2)Увеличение заданной суммы\n3)Сложение двух денежных сумм\n4)Вычисление разности денежных сумм\n5)Перевод денежной суммы в пенсы\n6)Вывод денежной суммы в формате <<99-99-99>>\n";
    return 0;
}