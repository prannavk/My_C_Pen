#include<stdio.h>

// C I/O
int main() {
    int num;
    int * nump = &num;
    int * nump2 = nump;

    char ch;
    float fl;
    int cn, cr = 0;

    printf("\nEnter 2 Integers\n");
    scanf("%d", nump2);
    scanf("%d", &cn);

    // For clearing input buffer
    while((getchar()) != '\n') {
        cr++;
    }

    printf("\nEnter a Character\n");
    scanf("%c", &ch);    

    printf("\nNow Enter a Float\n");
    scanf("%f", &fl);

    printf("\n\nYou entered this Integer: %d, which is stored at %p", num, nump2);
    printf("\n Also: entered: %d and cr is %d\n", cn, cr);
    printf("\n\nYou entered this Character: %c, which is stored at %p", ch, &ch);
    printf("\n\nYou entered this Float: %f, which is stored at %p", fl, &fl);

    int se = 0;
    printf("\nEnter a number:\n");
    int cse = scanf(" %d", &se);
    printf("\n\n%d %d\n", se, cse);

    return 0;
}