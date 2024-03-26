#include <stdio.h>
#include <stdlib.h>

/** 
 * 3D Arrays with hardcoded values in C Programming
 * @author Krishna Pranav
 * 
*/

int printError()
{
    printf("Error Occured while creating array:\n");
    return 1;
}

int printOk()
{
    printf("\n--------------Done--------\n");
    return 2;
}

void nl()
{
    printf("\n");
}

int main()
{
    int ***arr3dim;
    int dim1, dim2, dim3;

    printf("Enter dimensions (3 integers): ");
    scanf("%d %d %d", &dim1, &dim2, &dim3);

    printf("\nDims entered: %d %d %d\n", dim1, dim2, dim3);

    arr3dim = (int ***)calloc(dim1, sizeof(int **));
    if (arr3dim == NULL)
    {
        return printError();
    }

    for (int i = 0; i < dim1; i++)
    {
        arr3dim[i] = (int **)malloc(dim2 * sizeof(int *));
        if (arr3dim[i] == NULL)
        {
            return printError();
        }

        for (int j = 0; j < dim2; j++)
        {
            arr3dim[i][j] = (int *)malloc(dim3 * sizeof(int));
            if (arr3dim[i][j] == NULL)
            {
                return printError();
            }
        }
    }

    // Adding count data instead of scanning
    int count = 1;
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            for (int k = 0; k < dim3; k++)
            {
                arr3dim[i][j][k] = count++;
            }
        }
    }

    printf("-----Entered 3D Array elements:--------\n");
    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            for (int k = 0; k < dim3; k++)
            {
                printf("%d ", arr3dim[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            free(arr3dim[i][j]);
        }
        free(arr3dim[i]);
    }
    free(arr3dim);

    return 0;
}

