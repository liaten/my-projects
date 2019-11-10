#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int TRSIZE;
    cin>>TRSIZE;
    int maxlen=TRSIZE*2;
    for(int i=1;i<TRSIZE+1;i++)
    {
        for(int j=1;j<TRSIZE+1;j++)
        {
            for(int k=1;k<maxlen+1;k++)
            {
                putchar('O');
                putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}