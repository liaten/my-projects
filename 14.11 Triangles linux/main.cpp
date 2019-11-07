#include <stdlib.h>
#include <stdio.h>

#define TRSIZE 5

int main()
{
size_t i, j;

for(i = 1; i <= TRSIZE; ++i)
{
    for(j = TRSIZE; j > i; --j)       putchar(' ');
        for(j = 1; j < 2 * i; ++j)  putchar('*');
        putchar('\n');
    }

    exit(0);
}