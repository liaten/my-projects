#include <iostream>
using namespace std;
 
int main()
{
    int n;
    cout<<"Enter N: ";
    cin >> n;
    int A[n][n];
    int i=1,j,k,p=n/2;
    for(k=1;k<=p;k++){
    for (j=k-1;j<n-k+1;j++)
        A[k-1][j]=i++;
    for (j=k;j<n-k+1;j++)
        A[j][n-k]=i++;
    for (j=n-k-1;j>=k-1;--j)
        A[n-k][j]=i++;
    for (j=n-k-1;j>=k;j--) 
        A[j][k-1]=i++;
    }

    if (n%2==1)     A[p][p]=n*n;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        cout<<" "<<A[i][j];
        if(j==n-1)  cout<<"\n";
  }
  system("pause");
  return 0;
}
