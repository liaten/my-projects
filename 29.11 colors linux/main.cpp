#include <iostream>
#include <time.h>
using namespace std;



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

    for (unsigned i = 0; i < N; ++i)  delete[] a[i];
    delete[] a;
    //system("pause");
    return 0;
}
