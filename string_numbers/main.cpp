#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main(){
    cout << "Enter a string:\t";char a[500];
    fgets(a,500,stdin);
    cout <<"Enter order of your number: ";
    int f;      cin>>f;     int count=0;    char save;

    for(int i=0;i<500;i++){
        if(a[i]>='0' && a[i]<='9' && count!=f)count++;
        else if (count==f){
            save=a[i-1];
            break;}}

    cout<<"Value N "<<f<<" is "<<save;
return 0;}