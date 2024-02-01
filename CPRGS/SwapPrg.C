#include <stdio.h>

void swapNos(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
    printf("\nSwapped!! --- Memory Distance was = %d\n", (i - j));
}

int main()
{
    int a = 588, b = 552;
    int *pA = NULL, *pB = NULL;
    pA = &a;
    pB = &b;

    printf("\nValue of a is %d and b is %d\n", a, b);
    swapNos(pA, pB);
    printf("\nValue of a is %d and b is %d\n", a, b);

    printf("\nAlso...\n"); // Swapping Garbage Values
    int *x;
    int *y;
    printf("%p and %p\n", x, y);
    int xV = *x;
    int yV = *y;
    printf("%p and %p\n", &xV, &yV);
    printf("\nValue of x is %d and y is %d\n", xV, yV);
    swapNos(&xV, &yV);
    printf("\nValue of x is %d and y is %d\n", xV, yV);

    return 0;
}