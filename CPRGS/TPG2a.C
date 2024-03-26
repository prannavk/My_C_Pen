#include <stdio.h>
#include <stdlib.h>

/** 
 * 2D Arrays and Jagged Arrays in C Programming
 * @author Krishna Pranav
 * 
*/

int init2DArray();
void printUsingFunc1(int ****ar, int rows, int cols);
void printJagged(int ***ar, int rows, int *cl);
int init2DJagged();

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
    int c = 1;
    while (c != 0)
    {
        int op;
        printf("\nSelect Option:\n1.2D Array\n2.Jagged 2D Array\n (Enter a number only Please:) \n");
        scanf("%d", &op);
        printf("\nchoice entered: %d\n", op);
        if (op == 1)
        {
            printf("\n2D Array Selected\n");
            if (init2DArray() == 1)
                return 1;
        }
        else if (op == 2)
        {
            printf("\nJagged 2D Array Selected\n");
            if (init2DJagged() == 1)
                return 1;
        }
        else
        {
            printf("\nInvalid Choice\nexited...!");
            c = 0;
        }
    }
    return 0;
}

int init2DArray()
{
    int rows, cols;
    printf("\nEnter Rows:  ");
    scanf("%d", &rows);
    printf("Enter Cols:  ");
    scanf("%d", &cols);

    int **arr = (int **)calloc(rows, sizeof(int *));
    if (arr == NULL)
    {
        return printError();
    }

    for (int i = 0; i < rows; i++)
    {
        *(arr + i) = (int *)calloc(cols, sizeof(int));
        if (*(arr + i) == NULL)
        {
            return printError();
        }
    }

    printf("\nNow Enter Elements: \n");
    for (int i = 0; i < rows; i++)
    {
        printf(" \n ----- Row %d -----\n", i);
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", (*(arr + i) + j));
        }
    }
    while ((getchar()) != '\n')
        ; // Clearing Input Buffer

    printf("\n\nElements you have entered\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            printf("%d ", arr[i][j]);

    int ***p = &arr;
    int ****ref = &p;

    printUsingFunc1(ref, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        free(arr + i);
    }
    free(arr);

    return printOk();
}

void printUsingFunc1(int ****ar, int rows, int cols)
{
    printf("\n--------Printing Elements Inside array from FUnc1---------\n");
    int **ra = **ar;
    int maxl = (rows * cols) - 1;
    for (int i = 0; i < maxl; i++)
    {
        int next_ele = *(*(ra + (i / rows)) + (i % cols));
        printf("%d, ", next_ele);
    }
    printf("%d ", *(*(ra + (rows - 1)) + (cols - 1)));
}

int init2DJagged()
{
    int rows;
    printf("\nEnter Rows:  ");
    scanf("%d", &rows);

    int j_col_data[rows];

    int **arj = (int **)calloc(rows, sizeof(int *));
    if (arj == NULL)
    {
        return printError();
    }

    for (int i = 0; i < rows; i++)
    {
        printf("\nEnter %d row's span or col size:  \n", i + 1);
        scanf("%d", (j_col_data + i));
        *(arj + i) = (int *)calloc(*(j_col_data + i), sizeof(int));
        if (*(arj + i) == NULL)
        {
            return printError();
        }
    }

    printf("\n Now Enter the elements:\n");
    for (int i = 0; i < rows; i++)
    {
        printf("\nEnter Values for %d row\n", i + 1);
        for (int j = 0; j < *(j_col_data + i); j++)
        {
            scanf("%d", (*(arj + i) + j));
        }
    }

    printf("\n-------Elements of Array---------------:\n");
    for (int i = 0; i < rows; i++)
    {
        nl();
        for (int j = 0; j < *(j_col_data + i); j++)
        {
            printf("%d ", *(*(arj + i) + j));
        }
    }

    printJagged(&arj, rows, j_col_data);

    for (int i = 0; i < rows; i++)
    {
        free(arj + i);
    }
    free(arj);

    return printOk();
}

void printJagged(int ***ar, int rows, int *cl)
{
    printf("\n-------Elements of Array from Inside printJagged---------------:\n");
    for (int i = 0; i < rows; i++)
    {
        nl();
        for (int j = 0; j < *(cl + i); j++)
        {
            printf("%d ", *(*(*ar + i) + j));
        }
    }
}