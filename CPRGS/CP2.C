#include <stdio.h>

int greatestOf4(int, int, int, int);

int main()
{
    // Program to find greatest of 4 numbers
    int a, b, c, d;
    printf("\nEnter 4 numbers: \n");
    scanf("%d", &a);
    printf("\nAnother One: \n");
    scanf("%d", &b);
    printf("\nAnother One: \n");
    scanf("%d", &c);
    printf("\nAnother One: \n");
    scanf("%d", &d);
    printf("\nOhk, the greatest is %d \n", greatestOf4(a, b, c, d));

    // Seeing How Goto Works:
    printf("\n Ok Ok");
    goto ps;
    printf("\n Ok Ok");
    printf("\n Ok Ok");
    printf("\n Ok Ok");
ps:
    printf("\n Facts");

    return 0;
}

int greatestOf4(int a, int b, int c, int d)
{
    return (d > ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))) ? d : ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));
}