#include <iostream>
#include <time.h>
using namespace std;

//функция подсчета
//2.0 изменил теперь прога смотрит только направо и вниз
unsigned short IsNearSame(int** a, unsigned x, unsigned y)
{
  unsigned short result=0;
  if(a[x][y]==a[x-1][y]) result+=1; //есть такое же число сверху
  if(a[x][y]==a[x][y+1]) result+=2; //справа
  if(a[x][y]==a[x+1][y]) result+=4; //снизу
  if(a[x][y]==a[x][y-1]) result+=8; //слева
  return result;
}
unsigned CountColors(int** a, int x, int y, int &colors)
{
    if(IsNearSame(a,x,y))
    {
        for(int i=0;i<3;i++)
        {
            if(IsNearSame(a,x,y) & (1<<i)) colors++;
        }
        if(IsNearSame(a,x,y) & (1<<0))
        {
            ;
        }
        if(IsNearSame(a,x,y) & (1<<1))
        {
            ;
        }
        if(IsNearSame(a,x,y) & (1<<2))
        {
            ;
        }
        if(IsNearSame(a,x,y) & (1<<3))
        {
            ;
        }
    }
    else return colors;
}
int main()
{
    unsigned N;
    cout << "Введите число: ";
    cin >> N;
    
    int** a = new int* [N+2];
    for (unsigned i = 0; i < N+2; ++i)  a[i] = new int [N+2];
    srand (time(NULL));
    for(unsigned i=0;i<N+2;i++)
    {
        for(unsigned j=0;j<N+2;j++)
        {
            if(i==0 || j==0 ) a[i][j]=0;
            else if (i==N+1 || j==N+1) a[i][j]=0;
            else a[i][j]=rand()%7+1;
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    int c;      //кол-во цветов для каждого квадратика
    int c_max;  //max кол-во цветов
    for(unsigned i=1;i<N+1;i++)
    {
        for(unsigned j=1;j<N+1;j++)
        {
            c=1;
            cout<<CountColors(a,i,j,c)<<endl;
        }
    }
    for (unsigned i = 0; i < N; ++i)  delete[] a[i];
    delete[] a;
    return 0;
}