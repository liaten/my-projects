#include <iostream>
//#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int width=0,height=0,center=0,BUFF=0;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество строк матрицы, height: ";
	cin >> height;
	cout << endl << "Введите количество столбцов матрицы, width: ";
	cin >> width;
	cout<<endl;
	srand(time(0));
	int mas[height][width];
	for (int i = 0; i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			//mas[i][j] = ( rand() % ((width*height)+1) );
			mas[i][j]=j;
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}
	bool NOSORT=0;
	if(width>2)
	{
		if (width%2==0) //четные числа
		{
			for(int i=0;i<height;i++)
			{
				for(int j=2;j<width;j++)
				{
					;
				}
			}
		}
		else if (width%2==1) //нечетные числа
		{
			center=width/2;
			//cout<<center<<endl;
			for(int i=0;i<height;i++)
			{
				BUFF=mas[i][1];
				mas[i][1]=mas[i][2];
				mas[i][2]=BUFF;
				if(width>=5)
				{
					for(int j=4;j<width;j++)
					{
						if(j%2==0)
						{
							BUFF=mas[i][j/2];
							mas[i][j/2]=mas[i][j];
							mas[i][j]=BUFF;
						}
						else
						{
							/* code */
						}
						
					}
				}
			}
		}
	}

	cout<<endl;
	for (int i = 0; i < height;i++)
	{
		for (int j = 0;j < width;j++) cout << mas[i][j] << "\t";
		cout << endl;
	}

	return 0;
}