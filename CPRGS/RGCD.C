#include <stdio.h>

int gcdOf2Nums(int, int);

int main() {
    printf("\nGCD of 15 and 255 = %d\n", gcdOf2Nums(15, 255));
    return 0;
}

int gcdOf2Nums(int x, int y) {
    if(x == 1 || y == 1)
        return 1;
    if(x == y)
        return x;
    if(x > y)
        return gcdOf2Nums(x - y, y);
    else if (x < y)
        return gcdOf2Nums(x, y - x);
}