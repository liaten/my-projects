#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Write a function that calculates the first N prime numbers and put these numbers in the array passed to it. 
int main()
{
    int N;
    cout<<"Введите число: ";
    cin>>N;
    int numcount=0;
    int *a = new int[N*N];
    int *b = new int[N];
    for (int i = 0; i < N*N; i++)
    {
        a[i] = i;
    }
    for (int p = 2; p < N*N; p++)
    {
        if(numcount==N) break;
        if (a[p] != 0)
        {
            b[numcount]=a[p];
            cout <<numcount+1<<':'<< b[numcount] << endl;
            for (int j = p*p; j < N*N; j += p)
            {
                a[j] = 0;
            }
            numcount++;
        }
    }
    return 0;
}