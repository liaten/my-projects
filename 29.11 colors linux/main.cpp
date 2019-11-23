#include <iostream>
#include <time.h>
using namespace std;

int colors_count(int num)
{
    int count=1;
    bool endcycle=1;
    while (endcycle)
    {
        /* code */
    }
    
}

int main()
{
    int N;
    cout<<"Введите число N: ";
    cin>>N;
    int s[N][N];
    srand (time(NULL));
    for(int i=0;i<N+2;i++)
    {
        for(int j=0;j<N+2;j++)
        {
            if(i==0 || j==0 || i==N+1 || j==N+1) s[i][j]=0;
            else s[i][j]=rand()%7+1;
            cout<<s[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++) colors_count;
    }
    system("pause");
    return 0;
}