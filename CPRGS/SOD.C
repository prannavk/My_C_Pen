#include <stdio.h>

unsigned int sodBase(unsigned int n, unsigned int r) {
    if(n > 0)
        return (n%r) + sodBase(n/r, r);
    else
        return 0;
}

int main() {
    printf("\nsum of digits of 345 in base 10: %d\n", sodBase(345, 10));
    printf("\nsum of digits of 345 in base 2: %d\n", sodBase(345, 2));
    return 0;
}