#include <stdio.h>

// Program to demonstrate function as a Pointer
// Also an example of generic function pointer using void*

//----------------------------------

int sumNos(int, int);
int diffNos(int, int);
int (*eval)(int, int);

//-----------------------------------

void *(*genericEval)(void *, void *);
int *intMul(int *, int *);
double *dblMul(double *, double *);

//------------------------------------

int main()
{
    eval = sumNos;
    printf("\n Ok: %d ", eval(5, 6));
    eval = diffNos;
    printf("\n Ok: %d ", eval(5, 6));

    // Generic Function Pointer using careful Type casting:
    genericEval = (void *(*)(void *, void *))intMul;
    genericEval = (void *(*)(void *, void *))dblMul;

    return 0;
}

int sumNos(int a, int b)
{
    return a + b;
}

int diffNos(int a, int b)
{
    return a - b;
}

int *intMul(int *x, int *y)
{
    static int intRes = 0;
    intRes = *x * *y;
    return &intRes;
}

double *dblMul(double *x, double *y)
{
    static double dblRes = 0.0;
    dblRes = *x * *y;
    return &dblRes;
}