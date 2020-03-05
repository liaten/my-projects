#include <iostream>
using namespace std;

int len(int x)
{
	int n=1;
	while ((x/=10) > 0) n++;
	return n;
}

int main()
{
    int n;
    cout<<"Enter N: "; //макс колво элементов в одной строке/столбце
    cin >> n; //n=3
    int A[n][n]; //двумерный массив n*n
    int i=1,j,k,p=n/2; //p=1; в данном случае деление с отрезанием; i присваивается 1
//    cout<<p<<endl; //проверка что такое p
    for(k=1;k<=p;k++) //k=1
    {
        for(j=k-1;j<n-k+1;j++)  //если j меньше n-k+1 (3-1+1=3) выполнять
            A[k-1][j]=i++;      //a[0][0]=i++       //i++ значит что сперва используется число i а затем +1
        for(j=k;j<n-k+1;j++)    //
            A[j][n-k]=i++;      //
        for(j=n-k-1;j>=k-1;--j) //
            A[n-k][j]=i++;      //
        for(j=n-k-1;j>=k;j--)   //
            A[j][k-1]=i++;      //
    }
    int length_max=len(n*n);
//    cout<<length_max<<endl;
    if (n%2==1)     A[p][p]=n*n;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        int s=len(A[i][j]);
        /*do{
            cout<<" ";
            s++;
        }
        while(s<=length_max);*/
        cout<<"\t"<<A[i][j];
        if(j==n-1)  cout<<"\n";
  }
  return 0;
}