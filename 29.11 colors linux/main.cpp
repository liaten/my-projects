#include <iostream>
#include <time.h>
using namespace std;
//есть ли сверху то же число
bool is_same_up(int **a, unsigned x, unsigned y,unsigned N)
{
    if(a[x][y]==a[x-1][y] && (x-1)>0) return 1;
    else return 0;
}
//есть ли снизу то же число
bool is_same_down(int **a, unsigned x, unsigned y,unsigned N)
{
    if(a[x][y]==a[x+1][y] && (x+1)<N+1) return 1;
    else return 0;
}
//есть ли слева то же число
bool is_same_left(int **a, unsigned x, unsigned y,unsigned N)
{
    if(a[x][y]==a[x][y-1] && (y-1)>0) return 1;
    else return 0;
}
//есть ли снизу то же число
bool is_same_right(int **a, unsigned x, unsigned y,unsigned N)
{
    if(a[x][y]==a[x][y+1] && (y+1)<N+1) return 1;
    else return 0;
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
            if(is_same_left(a,i,j,N)) cout<<i<<' '<<j<<endl;
        }
    }
    for (unsigned i = 0; i < N; ++i)  delete[] a[i];
    delete[] a;
    return 0;
}