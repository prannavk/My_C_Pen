#include<stdio.h>
#include<stdbool.h>

int c = 3;

void m(int*);
void n(int*);

int main() {
    int a = 7;
    int b = 9;
    char ac = 's';
    char bc = 'm';
    _Bool id = a && b;
    _Bool cd = ac && bc;

    printf("\n7 && 9 is %d\ns && m is %d\n", id, cd);
    // printf("\n7 && 9 is %s\ns && m is %s\n", id, cd); // This gives Runtime Error -1073741819


    m(&c);
    return 0;
}

void m(int* y){
    int c = 1;
    n(&c);
    printf("\n%d %d\n", c, *y);
}
void n(int* x){
    printf("\n%d %d\n", *x, c);
    *x = *x + c;
    printf("\n%d %d\n", *x, c);
}