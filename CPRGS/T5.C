#include <stdio.h>
#include <string.h>

const int Mi = 4;
const int Mj = 4;

void scenario1(int arr[][Mj])
{
    for (int i = 0; i <= Mi - 1; i++)
    {
        for (int j = 0; j <= Mj - 1; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
}

void scenario2(int *arr, int m, int n)
{
    // Basically Address of A[i][j] = Base + Size of each element(i * n + j)
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf(" %d  ", *((arr + i * n) + j));
        printf("\n");
    }
}

void scenario3(int m, int n, int (*arr)[4])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf(" %d  ", arr[i][j]);
        printf("\n");
    }
}

void printBasicFloatArray();

int main()
{

    printBasicFloatArray();

    // Legal ways to create 2D arrays
    int A2[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int A3[][4] = {
        {41, 55, 28, 14},
        {66, 31, 9, 0},
        {91, 47, 88, 312}};

    int A4[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Giving the same input to both
    int A5[][3] = {11, 22, 33, 44, 55, 66, 77, 88};
    int A6[][4] = {11, 22, 33, 44, 55, 66, 77, 88};

    // 2D Array passing as parameter scenarios
    scenario1(A2);              // Need Global Constants
    scenario2(&A2[0][0], 4, 4); // We use pointer arithmetic and gets the job done without global constants or hardcoding
    scenario3(4, 4, A2);        // Need 1 global const or need to hardcode rows (pointer to an array)

    // Single Array getting stored as 2D Array
    printf("\n");
    scenario2(&A4[0][0], 3, 3);
    printf("\n");
    scenario2(&A5[0][0], 3, 3);
    printf("\n");
    scenario2(&A6[0][0], 2, 4);
    printf("\n\n");

    char B[5][6];
    printf("%u\n", B);
    printf("%u\n", (B + 2)); // B + size of row * 2 i.e. 6 * 2 => B + 12

    return 0;
}

void printBasicFloatArray()
{
    // 2D Arrays
    float A[3][4];
    memset(A, 0.0, sizeof(A));
    // Printing Float Array
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            printf(" %f ", A[i][j]);
        }
        printf("\n");
    }
}