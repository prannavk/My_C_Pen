#include <stdio.h>

typedef unsigned char byte;

int main() {
    double d = 0.9;
    byte *p = (byte *)&d; // Typecast the pointer

    for (int i = 0; i < sizeof(double); i++) {
        printf("\nByte %d: 0x%02X - %Lf\n", i, p[i], p[i]);
        // Can Perform further operations with p[i]
    }

    return 0;
}
