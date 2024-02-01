#include <stdio.h>
#include <stdbool.h>

int add1(int nos)
{
    return ++nos;
}

int addP(int *nos) {
    ++*nos;
    return *nos;
}

int main()
{

    int num = 55;
    int *ptrToNum1 = &num;
    int *ptrToNum2 = &num;
    int *ptrToNum3 = ptrToNum1;

    printf("\n%d\n", add1(*ptrToNum1));
    printf("%d\n", *ptrToNum2);
    printf("%d\n\n", (*ptrToNum3)++);
    printf("\n%d\n", addP(ptrToNum1));
    printf("%d\n", *ptrToNum2);
    printf("%d\n\n", *ptrToNum3);

    double *p, *q;
    double *res1 = p + 1;
    int res2 = p - q;
    printf("Pointer arithmetic see:\n%p is p\n%p is q\nthen\nres1 = %p\nres2 = %d\n", p, q, res1, res2);
    q--;
    printf("look at q: %p is q\n", q);
    printf("also is p >= q? : %d", (p > q));
    // int res3 = p + q; returns an error

    int chk = 2341;
    printf("\n\nchk = %d\n", (*(&chk)));

    return 0;
}