#include <stdio.h>

// Recursion example 2

void Head(int);

int main()
{
    printf("\n Recursion example 2");
    Head(3);
    printf("\n");
    return 0;
}

void Head(int x)
{
    if (x > 0)
    {
        Head(x - 1);
        printf(" %d ", x);
        Head(x - 1);
    }
    else
    {
        printf(" R ");
    }
}