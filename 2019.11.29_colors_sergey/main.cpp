#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;
 
int tron (int i, int combo, int car, int k, int *p)
{
    int j = i;
    *(p + i) = 0;
    combo++;
    //cout <<combo<< endl;
    if (*(p + i + 1) == car)
    {
        i++;
        combo = tron(i, combo, car, k, p);
        i = j;
    }
    if (*(p + i - 1) == car)
    {
        i--;
        combo = tron(i, combo, car, k, p);
        i = j;
    }
    if (*(p + i + k + 2) == car)
    {
        i = i+k+2;
        combo = tron(i, combo, car, k, p);
        i = j;
    }
    if (*(p + i - k - 2) == car)
    {
        i = i-k-2;
        combo = tron(i, combo, car, k, p);
        i = j;
    }
    return combo;
}
 
int main()
{
    int k;
    cout << "Введите число: ";
    cin >> k;
    int j, matrix [(k+2)*(k+2)], max, maxcombo = 1, i, combo, car, *p;
    srand( time(NULL) );
    for (j = 0; j < k+2; j++) matrix [j] = 0;
    for (j = k+2; j < (k+2)*(k+1); j++)
    {
        if ((j%(k+2)==0)||((j+1)%(k+2)==0)) matrix [j] = 0;
        else
        {
            matrix [j] = (rand() % 7) + 1;
            cout << matrix [j]<<' ';
        }
        if (j%(k+2)==0) cout << endl;
    }
    for (j = (k+2)*(k+1); j < (k+2)*(k+2); j++) matrix [j] = 0;
    cout << endl;
    /*
    for (i=0;i<(k+2)*(k+2);i++)
    {
        cout << matrix [i];
        if ((i!=0)&&((i+1)%(k+2)==0)) cout << endl;
    }
    */
    int num = 0;
    map<int,int>color;
    p = & matrix[0];
    for (j = k+3; j < (k+2)*(k+1); j++)
    if (matrix [j] != 0)
    {
        combo = 0;
        i = j;
        car = *(p + i);
        max = tron(i, combo, car, k, p);
        if (max > maxcombo)
        {
            num = 0;
            maxcombo = max;
        }
        if (max == maxcombo)
        {
            num++;
            color[num] = car;
        }
       
    }
    cout << endl << "Наибольшее число клеток области одного цвета: " << maxcombo << endl;
    cout << "Таких областей: " << num << endl;
    for (j = 1; j < num+1; j++)
    {
        switch (color[j])
            {
                case 1:
                    cout << "Красная область 1" << endl;
                    break;
                case 2:
                    cout << "Светло-зелёная область 2" << endl;
                    break;
                case 3:
                    cout << "Желтая область 3" << endl;
                    break;
                case 4:
                    cout << "Зелёная область 4" << endl;
                    break;
                case 5:
                    cout << "Голубая область 5" << endl;
                    break;
                case 6:
                    cout << "Синяя область 6" << endl;
                    break;
                case 7:
                    cout << "Лиловая область 7" << endl;
                    break;
            }  
    }
    //system("pause");
    return 0;
}