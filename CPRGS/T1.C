#include<stdio.h>

int main() {

    int x;
    char cb;

    printf("\nEnter Something into %p, where %d is stored\n", &x, x);
    scanf("%d", &x);    
    getchar();
    printf("\nx loc - %p\n", &x);
    printf("\nYou entered: %d \nNow Enter Something again:\n", x);
    scanf("%d", &cb); // Trying to capture Integer into a char pointer
    printf("\nYou entered: %c - %d in %p \n", cb, cb, &cb);
    printf("\nNow Try Again:\n");
    getchar();
    scanf("%f", &x);    
    printf("\nx loc - %p\n", &x);
    printf("\nYou entered: %d - %f in %p \n", x, x, &x);
    printf("\nx loc - %p\n", &x);
    return 0;
}