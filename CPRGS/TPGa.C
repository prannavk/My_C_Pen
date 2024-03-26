#include <stdio.h>
#include <stdlib.h>

void printArr1(int ar[], int N);
void printArr2(int *s, int *e);

int main()
{
    int N;
    printf("Enter N: \n");
    scanf("%d", &N);
    printf("\n...\n");
    int *darr = (int *) malloc(N * sizeof(int));
    if(darr == NULL) {
        printf("Could not create Array, Try Again\n");
        return 1;
    }
    printf("\nEnter Array Elements: \n");
    for (int i = 0; i < N; i++)
        scanf("%d", (darr + i));

    printf("\nArray Elements You entered (Main): \n");
    for(int i = 0; i < N - 1; i++)
        printf("%d, ", *(darr + i));    
    printf("%d\n", *(darr + (N - 1)));

    printArr1(darr, N);
    printArr2(darr, darr + (N - 1));

    return 0;
}

void printArr1(int ar[], int N) {
    printf("\nArray Elements You entered (Fun1): \n");
    for(int i = 0; i < N - 1; i++)
        printf("%d, ", *(ar + i));    
    printf("%d\n", *(ar + (N - 1)));
}

void printArr2(int *s, int *e) {
    printf("\nArray Elements You entered (Fun2): \n");
    while(s < e) {
        printf("%d, ", *s);
        s++;
    }    
    printf("%d \n", *s);
}
