#include <stdio.h>

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int *p1 = &A[0];
    int **pp1 = &p1;

    // Say we want to access A[2] i.e. '3', we can do it as either:
    printf("\n%d ", A[2]);
    // or (using pointers)
    printf("\n%d ", *(p1 + 2));
    printf("\n%d ", *(*pp1 + 2));
    printf("\n\n");

    // --------------------------------------------------------

    int a[10] = {10, 20, 30, 40, 50, 60};
    int *p[] = {a, a+1, a+2, a+3, a+4, a+5};
    int **pp = p;

    pp++;
    printf("%d %d %d \n", pp-p, *pp-a, **pp);
    *pp++;
    printf("%d %d %d \n", pp-p, *pp-a, **pp);
    ++*pp;
    printf("%d %d %d \n", pp-p, *pp-a, **pp);
    ++**pp;
    printf("%d %d %d \n", pp-p, *pp-a, **pp);

    return 0;
}