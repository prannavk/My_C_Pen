#include <stdio.h>

int main()
{

    int a = 1, be = 0;
    int *cnt;
    cnt = &be;

    while (a <= 5)
    {
        printf(" %d ", cnt);
        cnt = &a;
        a++;
    }

    do
    {
        printf("\nOhk, lets see some patterns\n\n");
    } while (a < 5);

    printf("Nepal Flag:\n\n");
    int v1 = 0, v2 = 0;
    while(v1 < 10) {
        v2 = v1%5;
        do {
            printf("* ");
            v2--;
        } while(v2 >= 0);
        printf("\n");
        v1++;
    }

    printf("\n");
    return 0;
}