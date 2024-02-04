#include <stdio.h>

// Recursive Program using pointers to print Numbers in Reverse

static int val = 6;

void fun(int *);

int main()
{
    fun(&val);
    printf("\n Now val value is %d", val);
    return 0;
}

void fun(int *v)
{
    if (*v > 0)
    {
        printf(" %d ", *v);
        *v = *v - 1;
        fun(v);
    }
    else
    {
        printf("\n Ok");
    }
}