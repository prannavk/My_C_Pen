#include <stdio.h>
#include "T8.C"

int y;

extern int ce;

int main()
{
    int x;
    static int c;

    printf("\nglobal %d and local %d and static %d\n", y, x, c);
    printf("\nextern var: %d", ce);
    return 0;
}