#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int n=0,m=0,center=0,BUFF=0;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество строк матрицы, m: ";
	cin >> m;
	cout << endl << "Введите количество столбцов матрицы, n: ";
	cin >> n;
	srand(time(0));
	int mas1[m][n];
	for (int i = 0; i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			//mas1[i][j] = ( rand() % ((n*m)+1) );
			mas1[i][j]=j;
			cout << mas1[i][j] << "\t";
		}
		cout << endl;
	}
	if(n%2==0)
	{
		
	}
	return 0;
}