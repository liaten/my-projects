#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int N;
    cout<<"Введите число N:";
    cin>>N;
    int s[N][N];
    srand (time(NULL));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            s[i][j]=rand()%7+1;
            cout<<s[i][j]<<' ';
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}