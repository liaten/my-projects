#include <iostream>
#include <string>
using namespace std;
 
struct finance
{
    int pound;
    int shilling;
    int penny;
};
 
finance converter (finance Money)
{
    Money.shilling = Money.shilling + Money.penny / 12;
    Money.penny = Money.penny % 12;
    Money.pound = Money.pound + Money.shilling / 20;
    Money.shilling = Money.shilling % 20;
    return Money;
}
 
finance delta_adder (finance Money, int d_pound, int d_shilling, int d_penny)
{
    Money.penny = Money.penny + d_penny;
    Money.shilling = Money.shilling + Money.penny / 12 + d_shilling;
    Money.penny = Money.penny % 12;
    Money.pound = Money.pound + Money.shilling / 20 + d_pound;
    Money.shilling = Money.shilling % 20;
    return Money;
}
 
finance double_adder (finance Money1, finance Money2)
{
    Money1.penny = Money1.penny + Money2.penny;
    Money1.shilling = Money1.shilling + Money2.shilling + Money1.penny / 12;
    Money1.penny = Money1.penny % 12;
    Money1.pound = Money1.pound + Money2.pound + Money1.shilling / 20;
    Money1.shilling = Money1.shilling % 20;
    return Money1;
}
 
finance subtractor (finance Money1, finance Money2)
{
    Money1.penny = (Money1.pound * 20 + Money1.shilling) * 12 + Money1.penny;
    Money2.penny = (Money2.pound * 20 + Money2.shilling) * 12 + Money2.penny;
    if (Money1.penny>Money2.penny)
    {
        Money1.penny = Money1.penny - Money2.penny;
        Money1.shilling = Money1.penny / 12;
        Money1.penny = Money1.penny % 12;
        Money1.pound = Money1.shilling / 20;
        Money1.shilling = Money1.shilling % 20;
        return Money1;
    }
    else
    {
        Money2.penny = Money2.penny - Money1.penny;
        Money2.shilling = Money2.penny / 12;
        Money2.penny = Money2.penny % 12;
        Money2.pound = Money2.shilling / 20;
        Money2.shilling = Money2.shilling % 20;
        return Money2;
    }
}
 
finance penny_converter (finance Money)
{
    Money.penny = (Money.pound * 20 + Money.shilling) * 12 + Money.penny;
    Money.pound = 0;
    Money.shilling = 0;
    return Money;
}
 
void output (finance Money)
{
    if(Money.penny>12)
    {
      Money.shilling+=Money.penny/12;
      Money.penny%=12;
    }
    if(Money.shilling>20)
    {
      Money.pound+=Money.shilling/20;
      Money.shilling%=20;
    }
    cout << Money.pound << "-" << Money.shilling << "-" << Money.penny << endl;
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
        finance Money;
        cout << "Введите количество фунтов: ";
        cin >> Money.pound;
        cout << "Введите количество шиллингов: ";
        cin >> Money.shilling;
        cout << "Введите количество пенсов: ";
        cin >> Money.penny;
        switch (ki)
        {
            case 1:
                Money = converter(Money);
                cout << "Корректное значение: ";
                output (Money);
                break;
            case 2:
                int d_pound, d_shilling, d_penny;
                cout << "Введите количество фунтов, которое необходимо прибавить: ";
                cin >> d_pound;
                cout << "Введите количество шиллингов, которое необходимо прибавить: ";
                cin >> d_shilling;
                cout << "Введите количество пенсов, которое необходимо прибавить: ";
                cin >> d_penny;
                Money = delta_adder(Money, d_pound, d_shilling, d_penny);
                cout << "Конечная сумма: ";
                output (Money);
                break;
            case 3:
                finance SMoney;
                cout << "Введите количество фунтов второй денежной суммы: ";
                cin >> SMoney.pound;
                cout << "Введите количество шиллингов второй денежной суммы: ";
                cin >> SMoney.shilling;
                cout << "Введите количество пенсов второй денежной суммы: ";
                cin >> SMoney.penny;
                Money = double_adder(Money, SMoney);
                cout << "Конечная сумма: ";
                output (Money);
                break;
            case 4:
                finance RMoney;
                cout << "Введите количество фунтов второй денежной суммы: ";
                cin >> RMoney.pound;
                cout << "Введите количество шиллингов второй денежной суммы: ";
                cin >> RMoney.shilling;
                cout << "Введите количество пенсов второй денежной суммы: ";
                cin >> RMoney.penny;
                Money = subtractor(Money, RMoney);
                cout << "Разность: ";
                output (Money);
                break;
            case 5:
                Money = penny_converter(Money);
                cout << "Денежная сумма в пенсах: ";
                output (Money);
                break;
            case 6:
                cout << "Денежная сумма в формате <<99-99-99>>: ";
                output (Money);
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
        finance Money [kol];
        for (i = 0; i < kol; i++)
        {
            cout << "Введите количество фунтов денежной суммы № " << i+1 << " : ";
            cin >> Money[i].pound;
            cout << "Введите количество шиллингов денежной суммы № " << i+1 << " : ";
            cin >> Money[i].shilling;
            cout << "Введите количество пенсов денежной суммы № " << i+1 << " : ";
            cin >> Money[i].penny;
        }
        finance Common = Money[0];
        for (i = 1; i < kol; i++)   Common =double_adder(Common,Money[i]);
        Common = penny_converter(Common);
        int min = Common.penny, max = 0;
        Common.penny = Common.penny / kol;
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
                Delta = subtractor(Money[i],Money[j]);
                Delta = penny_converter(Delta);
                if (Delta.penny<min)
                {
                    min = Delta.penny;
                    n[0] = i;
                    n[1] = j;
                }
                if (Delta.penny>max)
                {
                    max = Delta.penny;
                    f[0] = i;
                    f[1] = j;
                }
                Delta.penny = 0;
            }
        if (ki==8)
        {
            cout << "Пара денежных сумм, с наиболее близким значением: " << endl;
            output(Money[n[0]]);
            output(Money[n[1]]);
            cout << "Пара денежных сумм, с наиболее далёким значением: " << endl;
            output(Money[f[0]]);
            output(Money[f[1]]);
        }
    }
    /*cout << "\nКакую операцию вы хотите выполнить?\n"
    << "1. Проверка корректности значения\n"
    << "2. Увеличение суммы на заданное количество денежных единиц\n"
    << "3. Сложение двух денежных сумм\n"
    << "4. Вычисление разности двух денежных сумм\n"
    << "5. Перевод денежной суммы в пенсы\n"
    << "6. Вывод денежной суммы в формате <<99-99-99>>\n"
    << "7. Вывод среднего значения\n"
    << "8. Вывод пары сумм, наиболее близких и далёких по значению\n"
    << "9. Выход из программы\n";*/
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
