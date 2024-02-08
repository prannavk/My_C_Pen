#include <stdio.h>

int whatThe();
int r1();

int main() {
    return whatThe();
}

int whatThe() {
    for(r1(); r1(); r1())
        printf("\n%d ok", r1());
    return 0;
}

int r1() {
    static int num = 7;
    return num--;
}