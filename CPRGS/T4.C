#include <stdio.h>
#include <string.h>

void printArray(int array[], int size)
{
    int t = 0;
    printf("\nArray of size %d:\n", (size * sizeof(int)));
    for (t = 0; t <= size - 1; t++)
    {
        printf("%d at %p\n", array[t], &array[t]);
    }
    printf("\n");
}

int main()
{

    // ARRAYS
    int array[5];
    memset(array, 0, sizeof(array));
    printArray(array, 5);

    int ar2[4];
    printArray(ar2, 4);

    int ar3[6] = {1, 34, 52, 11, 29, 82};
    printArray(ar3, 6);
    printf("\nHolup Wait: %d == %d \n", ar3[4], 4[ar3]);
    printf(" %u \n %u\n", ar3, &ar3);
    printf(" %u - %d\n", (ar3 + 1), *(ar3 + 1));

    int ar4[7] = {25, 34};
    printArray(ar4, 7);

    printf("\n");
    return 0;
}