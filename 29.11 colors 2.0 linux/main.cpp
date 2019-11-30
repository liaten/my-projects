#include <iostream>
#include <time.h>
using namespace std;
//  функция подсчета
unsigned CountColors(int** a, unsigned x, unsigned y, unsigned &colors)
{
    if(a[x][y]==a[x][y+1])
    {
        colors++;
        return CountColors(a,x,y+1,colors);
        //cout<<"справа ";
    }
    if(a[x][y]==a[x+1][y])
    {
        colors++;
        return CountColors(a,x+1,y,colors);
        //cout<<"снизу ";
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
    unsigned c;
    for(unsigned i=1;i<N+1;i++)
    {
        for(unsigned j=1;j<N+1;j++)
        {
            if(a[i][j]==a[i][j+1] || a[i][j]==a[i+1][j]) 
            {
                c=0;
                cout<<i<<' '<<j<<" = "<<CountColors(a,i,j,c)+1<<" ; Значение \""<<a[i][j]<<"\""<<endl;
            }
        }
    }
    for (unsigned i = 0; i < N; ++i)  delete[] a[i];
    delete[] a;
    return 0;
}