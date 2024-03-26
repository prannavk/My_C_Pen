#include <stdio.h>

int whatThe();
int r1();

int main() {
    int *p = '\0';
    int *q = NULL;
    if(p == q)
        printf("Yes, Both are Null\n");
    if(&p != &q)
        printf("And, Not same Loc\n");    
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