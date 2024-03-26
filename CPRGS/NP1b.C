#include <stdio.h>

int cRet();
void ret();

int main() {
    int n = 0;
    scanf("%d", &n);
    printf("\nYou entered %d\n", n);
    // while(n > 0) {
    //     printf("\n Ok - %d", n);
    //     n--;
    // }

    int ax = 1;
    long int a = 0;
    long long int b = 0;
    printf("%d, %d, %d\n", sizeof(ax), sizeof(a), sizeof(b));
    while(n--) {
        printf("\n Ok - %d", n);
    }
    ret();
    return 0;
}

int cRet() {
    static int a = 5;
    return a--;
}

void ret() {
    int c = 0;
    for(cRet(); cRet(); cRet()) {
        printf("H %d", cRet(), c);
        c++;
    }
}