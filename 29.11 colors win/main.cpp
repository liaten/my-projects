#include <iostream>
#include <time.h>
using namespace std;

//бот больше не путает лево и право, с ним все в порядке, лучше его не трогать :D
//2.0 изменил теперь прога смотрит только направо и вниз, есть идея сделать циклично
unsigned short IsNearSame(int** a, int x, int y)
{
  unsigned short result=0;
  //if(a[x][y]==a[x-1][y]) result+=1; //есть такое же число сверху
  if(a[x][y]==a[x][y+1]) result+=1; //справа
  if(a[x][y]==a[x+1][y]) result+=2; //снизу
  //if(a[x][y]==a[x][y-1]) result+=8; //слева
  return result;
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
    for(unsigned i=1;i<N+1;i++)
    {
        for(unsigned j=1;j<N+1;j++)
        {
            if(IsNearSame(a,i,j)!=0)
            {
                cout<<"["<<i<<"]["<<j<<"] (вниз, вправо) E значение "<<a[i][j]<<' ';
                //if(IsNearSame(a,i,j) & (1<<0)) cout<<"сверху ";
                if(IsNearSame(a,i,j) & (1<<0)) cout<<"справа ";
                if(IsNearSame(a,i,j) & (1<<1)) cout<<"снизу ";
                //if(IsNearSame(a,i,j) & (1<<3)) cout<<"слева ";
                cout<<endl;
            }
        }
    }
    for (unsigned i = 0; i < N; ++i)  delete[] a[i];
    delete[] a;
    return 0;
}