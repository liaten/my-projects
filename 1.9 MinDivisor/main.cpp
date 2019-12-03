#include <iostream>
#include <cmath>
using namespace std;
int MinDivisor(int n)
{
    int divisor=n;
    for(int i=sqrt(n);i>=2;i--)
    {
        if(n%i==0) divisor=i;
    }
    return divisor;
}
int main()
{
  int N;
  cin>>N;
  cout<<MinDivisor(N);
  return 0;
}