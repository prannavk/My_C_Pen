#include <stdio.h>

// macros or preprocessors
// functions
// structures
// global variables
// main function (written below)

int abglobal;

int main()
{

    // All data types with modifiers

    int a;
    int *ap;
    int *ap2, a2;
    int *ap3, a3; // All legal ways of declaring a pointer

    short int b;
    long int cn;
    unsigned long int cun;
    signed short int ssn;
    unsigned long long gpe;

    float fl1;
    double d1;
    long double dbl;

    char cha;
    unsigned char chb;
    signed char chbc;

    struct N
    {
        int one;
        char two;
        double three;
        long double four;
    };

    struct N *kn;

    printf("\nPrinting all the vars...\n");
    printf("abglobal - %d\n", abglobal);
    printf("\n a - %d\n ap - %p\nap2 - %p\na2 - %d\nap3 - %p\na3 - %d", a, ap, ap2, a2, ap3, a3);
    printf("\nb - %d\ncn - %ld\ncun - %lu\nssn - %d\ngpe - %llu", b, cn, cun, ssn, gpe);
    printf("\nfl1 - %f\nd1 - %lf\ndbl - %Lf\ncha - %c\nchb - %c\nchbc - %c \n", fl1, d1, dbl, cha, chb, chbc);
    printf("\n\nsizeof each type:\n");
    printf("int - %d and int* - %d\n", sizeof(a), sizeof(ap2));
    printf("short int b - %d\n", sizeof(b));
    printf("long int cn - %d\n", sizeof(cn));
    printf("unsigned long int cun - %d\n", sizeof(cun));
    printf("signed short int ssn - %d\n", sizeof(ssn));
    printf("unsigned long long gpe - %d\n", sizeof(gpe));
    printf("float fl1 - %d\n", sizeof(fl1));
    printf("double d1 - %d\n", sizeof(d1));
    printf("long double db1 - %d\n", sizeof(dbl));
    printf("char cha - %d\n", sizeof(cha));
    printf("unsigned char chb - %d\n", sizeof(chb));
    printf("signed char chbc - %d\n\n", sizeof(chbc));
    printf("struct N: %d\n\n", sizeof(*kn));

    return 0;
}