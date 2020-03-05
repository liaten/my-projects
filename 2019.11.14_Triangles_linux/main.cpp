//#include <stdlib.h>
//#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int TRSIZE, xput;
    cout<<"Enter number of triangles: ";
    cin>>TRSIZE;        //допустим 3
    int maxlen=TRSIZE*2;
    for(int i=1;i<TRSIZE+1;i++) //построчный вывод
    {
        xput=i*2-1;
        //cout<<TRSIZE-(xput-i)<<endl;
        //cout<<TRSIZE+(xput-i)<<endl;
        for(int j=1;j<TRSIZE+1;j++) //
        {
            for(int k=1;k<maxlen+1;k++)
            {
                if(k>TRSIZE-(xput-i+1) && k<TRSIZE+(xput-i+1)) putchar('*');
                else putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}