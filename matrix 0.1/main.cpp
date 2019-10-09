#include <iostream>
//#include <math.h>
using namespace std;
int main()
{
    int n,m; //n - столбцы// m -строки
    cin>>n>>m;
    int s[m][n];
    int r=0+rand()%(n*m);
    cout<<r;
    return 0;
}