#include <iostream>
#include <string>
using namespace std;
struct finance
{
    int pounds;
    int shillings;
    int pence;
};
 
finance converter (finance money)
{
    money.shillings = money.shillings + money.pence / 12;
    money.pence = money.pence % 12;
    money.pounds = money.pounds + money.shillings / 20;
    money.shillings = money.shillings % 20;
    return money;
}
 
finance delta_adder (finance money, int d_pound, int d_shilling, int d_penny)
{
    money.pence = money.pence + d_penny;
    money.shillings = money.shillings + money.pence / 12 + d_shilling;
    money.pence = money.pence % 12;
    money.pounds = money.pounds + money.shillings / 20 + d_pound;
    money.shillings = money.shillings % 20;
    return money;
}
 
finance double_adder (finance Money1, finance Money2)
{
    Money1.pence = Money1.pence + Money2.pence;
    Money1.shillings = Money1.shillings + Money2.shillings + Money1.pence / 12;
    Money1.pence = Money1.pence % 12;
    Money1.pounds = Money1.pounds + Money2.pounds + Money1.shillings / 20;
    Money1.shillings = Money1.shillings % 20;
    return Money1;
}
 
finance subtractor (finance Money1, finance Money2)
{
    Money1.pence = (Money1.pounds * 20 + Money1.shillings) * 12 + Money1.pence;
    Money2.pence = (Money2.pounds * 20 + Money2.shillings) * 12 + Money2.pence;
    if (Money1.pence>Money2.pence)
    {
        Money1.pence = Money1.pence - Money2.pence;
        Money1.shillings = Money1.pence / 12;
        Money1.pence = Money1.pence % 12;
        Money1.pounds = Money1.shillings / 20;
        Money1.shillings = Money1.shillings % 20;
        return Money1;
    }
    else
    {
        Money2.pence = Money2.pence - Money1.pence;
        Money2.shillings = Money2.pence / 12;
        Money2.pence = Money2.pence % 12;
        Money2.pounds = Money2.shillings / 20;
        Money2.shillings = Money2.shillings % 20;
        return Money2;
    }
}
 
finance penny_converter (finance money)
{
    money.pence = (money.pounds * 20 + money.shillings) * 12 + money.pence;
    money.pounds = 0;
    money.shillings = 0;
    return money;
}
 
void output (finance &money)
{
    if(money.pence>12)
    {
      money.shillings+=money.pence/12;
      money.pence%=12;
    }
    if(money.shillings>20)
    {
      money.pounds+=money.shillings/20;
      money.shillings%=20;
    }
    cout << money.pounds << "-" << money.shillings << "-" << money.pence << endl;
}
 
int main(int argc, char** argv)
{
    string key;
    char ki;
    int i;
    cout << "Какую операцию вы хотите выполнить?\n"
    << "1. Проверка корректности значения\n"
    << "2. Увеличение суммы на заданное количество денежных единиц\n"
    << "3. Сложение двух денежных сумм\n"
    << "4. Вычисление разности двух денежных сумм\n"
    << "5. Перевод денежной суммы в пенсы\n"
    << "6. Вывод денежной суммы в формате <<99-99-99>>\n"
    << "7. Вывод среднего значения\n"
    << "8. Вывод пары сумм, наиболее близких и далёких по значению\n";
    cout << "Введите номер операции: ";
    cin >> key;
    ki = 0;
    for (i=0; key[i]!='\0'; i++)
        {
            ki = ki * 10;
            ki+=key[i] - '0';
        }
    if ((ki<1)||(ki>8)) do
        {
            cout << "Необходимо ввести цифру от 1 до 8.\n" << "Попробуйте снова: ";
            cin >> key;
            ki = 0;
            for (i=0; key[i]!='\0'; i++)
            {
                ki = ki * 10;
                ki+=key[i] - '0';
            }
        }
        while ((ki<1)||(ki>8));
    do
    {
    if (ki<7)
    {
        finance money;
        cout << "Введите количество фунтов: ";
        cin >> money.pounds;
        cout << "Введите количество шиллингов: ";
        cin >> money.shillings;
        cout << "Введите количество пенсов: ";
        cin >> money.pence;
        switch (ki)
        {
            case 1:
                money = converter(money);
                cout << "Корректное значение: ";
                output (money);
                break;
            case 2:
                int d_pound, d_shilling, d_penny;
                cout << "Введите количество фунтов, которое необходимо прибавить: ";
                cin >> d_pound;
                cout << "Введите количество шиллингов, которое необходимо прибавить: ";
                cin >> d_shilling;
                cout << "Введите количество пенсов, которое необходимо прибавить: ";
                cin >> d_penny;
                money = delta_adder(money, d_pound, d_shilling, d_penny);
                cout << "Конечная сумма: ";
                output (money);
                break;
            case 3:
                finance SMoney;
                cout << "Введите количество фунтов второй денежной суммы: ";
                cin >> SMoney.pounds;
                cout << "Введите количество шиллингов второй денежной суммы: ";
                cin >> SMoney.shillings;
                cout << "Введите количество пенсов второй денежной суммы: ";
                cin >> SMoney.pence;
                money = double_adder(money, SMoney);
                cout << "Конечная сумма: ";
                output (money);
                break;
            case 4:
                finance RMoney;
                cout << "Введите количество фунтов второй денежной суммы: ";
                cin >> RMoney.pounds;
                cout << "Введите количество шиллингов второй денежной суммы: ";
                cin >> RMoney.shillings;
                cout << "Введите количество пенсов второй денежной суммы: ";
                cin >> RMoney.pence;
                money = subtractor(money, RMoney);
                cout << "Разность: ";
                output (money);
                break;
            case 5:
                money = penny_converter(money);
                cout << "Денежная сумма в пенсах: ";
                output (money);
                break;
            case 6:
                cout << "Денежная сумма в формате <<99-99-99>>: ";
                output (money);
                break;
        }
    }
    else
    {
        int kol;
        cout << "Введите колличество денежных сумм: ";
        cin >> kol;
        if (kol < 2) do
        {
            cout << "Для продолжения необходимо, чтобы денежных сумм было несколько.\n" << "Попробуйте снова: ";
            cin >> kol;
        }
        while (kol < 2);
        finance money [kol];
        for (i = 0; i < kol; i++)
        {
            cout << "Введите количество фунтов денежной суммы № " << i+1 << " : ";
            cin >> money[i].pounds;
            cout << "Введите количество шиллингов денежной суммы № " << i+1 << " : ";
            cin >> money[i].shillings;
            cout << "Введите количество пенсов денежной суммы № " << i+1 << " : ";
            cin >> money[i].pence;
        }
        finance Common = money[0];
        for (i = 1; i < kol; i++)   Common =double_adder(Common,money[i]);
        Common = penny_converter(Common);
        int min = Common.pence, max = 0;
        Common.pence = Common.pence / kol;
        Common = converter(Common);
        if (ki==7)
        {
            cout << "Среднее значение денежных сумм: ";
            output(Common);
        }
        int j, n [2] , f [2];
        finance Delta;
        for (i = 0; i < (kol-1); i++)
            for (j = (i+1); j < kol; j++)
            {
                Delta = subtractor(money[i],money[j]);
                Delta = penny_converter(Delta);
                if (Delta.pence<min)
                {
                    min = Delta.pence;
                    n[0] = i;
                    n[1] = j;
                }
                if (Delta.pence>max)
                {
                    max = Delta.pence;
                    f[0] = i;
                    f[1] = j;
                }
                Delta.pence = 0;
            }
        if (ki==8)
        {
            cout << "Пара денежных сумм, с наиболее близким значением: " << endl;
            output(money[n[0]]);
            output(money[n[1]]);
            cout << "Пара денежных сумм, с наиболее далёким значением: " << endl;
            output(money[f[0]]);
            output(money[f[1]]);
        }
    }
    cout << "Введите номер операции: ";
    cin >> key;
    ki = 0;
    for (i=0; key[i]!='\0'; i++)
        {
            ki = ki * 10;
            ki+=key[i] - '0';
        }
    if ((ki<1)||(ki>9)) do
        {
            cout << "Необходимо ввести цифру от 1 до 8.\n" << "Попробуйте снова: ";
            cin >> key;
            ki = 0;
            for (i=0; key[i]!='\0'; i++)
            {
                ki = ki * 10;
                ki+=key[i] - '0';
            }
        }
        while ((ki<1)||(ki>9));
    }
    while (ki!=9);
    return 0;
}
