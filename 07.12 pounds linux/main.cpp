#include <iostream>
#include <map>
using namespace std;
//английские деньги
struct eng_money
{
    unsigned pounds;    //фунты
    unsigned shillings; //шиллинги
    unsigned pence;     //пенсы
};

bool correct_value()
{
    return 0;
}

int main()
{
    map<string,eng_money>vars;
    vars["Purse1"];vars["Purse2"];
    cout<<"Выберите действие:\n1)Проверка корректности значения\n2)Увеличение заданной суммы\n3)Сложение двух денежных сумм\n4)Вычисление разности денежных сумм\n5)Перевод денежной суммы в пенсы\n6)Вывод денежной суммы в формате <<99-99-99>>\n";
    return 0;
}