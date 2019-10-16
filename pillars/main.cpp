#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int n=0, m=0, l=0, center=0, c=0, c1=0, b=0, a=0;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество строк матрицы, m: ";
	cin >> m;
	cout << endl << "Введите количество столбцов матрицы, n: ";
	cin >> n;
	srand(time(0));
	int s1[n][m];
	for (int i = 0; i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			s1[i][j] = ( rand() % ((n*m)+1) );
			cout << s1[i][j] << "\t";
		}
		cout << endl;
	}

	int s2[m];
	for (int i = 0; i < n;i++) s2[i] = i;
	
	if (n % 2 == 0) center = n / 2;
	else center = (n / 2) + 1;
	
	for (int i = 0;i < center; i++)
	{
		s2[i] = c + c1;
		c++;
		c1++;
	}
	cout << endl;
	if (n % 2 == 0)
	{
		for (int i = center; i > 0; i--)
		{
			s2[i + b] = c + c1 - a - 1;
			c--;
			b = b + 2;
			a++;
		}
	}
	else
	{
		for (int i = center; i > 0; i--)
		{
			s2[i + b] = c + c1 - a - 3;
			c--;
			b = b + 2;
			a++;
		}
	}

	for (int j = 0; j < m;j++)
	{
		for (int i = 0; i < n;i++)
		{
			l = s2[i];
			cout << s1[j][l] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n;i++) cout << s2[i] + 1 << "\t";
	return 0;
}