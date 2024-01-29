#include<stdio.h>

// C I/O
int main() {
    int num;
    int * nump = &num;
    int * nump2 = nump;

    char ch;
    float fl;

    printf("\nEnter a Integer\n");
    scanf("%d", nump2);

    // For clearing input buffer
    while((getchar()) != '\n');

    printf("\nEnter a Character\n");
    scanf("%c", &ch);

    printf("\nNow Enter a Float\n");
    scanf("%f", &fl);

    printf("\n\nYou entered this Integer: %d, which is stored at %p", num, nump2);
    printf("\n\nYou entered this Character: %c, which is stored at %p", ch, &ch);
    printf("\n\nYou entered this Float: %f, which is stored at %p", fl, &fl);

    return 0;
}