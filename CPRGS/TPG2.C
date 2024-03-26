#include <stdio.h>

/** 
 * 2D Arrays in C Programming
 * @author Krishna Pranav
 * 
*/

void print2DArray1(int (*pr)[], int rows, int cols);
void print2DArray1e(int *pr, int rows, int cols);
void print2DArray2SingleLine(int (*pr)[], int blocs);
void print2DArray2SingleLine2(int (*pr)[], int rows, int cols);
void print2DArray3a(int (*pr)[], int rows, int cols);
void print2DArray3b(int *S, int *E);

int main() {
    
    int dr[4][4] = {
        {11, 222, 14, 65},
        {68, 9, 10, 42},
        {365, 980, 72, 373},
        {28, 32, 97, 71}
    };
    int ak[4];

    int er[4][4] = {
        {41, 32, 64, 75},
        {68, 9},
        {3, 80, 12}        
    };

    int *ep = er[0];    
    int *ep2 = &er[0][0];

    printf("\n%d == %d == %d == %d == %d\n", er, ep, ep2, &er, *er);
    printf("\n%d == %d == %d == %d == %d\n", er[0][0], *(ep + 0), *ep2, **er, *ep);
    printf("\n%d == %d, and %d == %d == %d\n", ep + 1, ep2 + 1, er[1], *(er + 1), &er[1]);
    printf("\n%d != %d == %d != %d\n", er[1] + 1, &er[1] + 1, er[1] + sizeof(er + 0), *er[1] + 1);
    printf("\n%d == %d == %d == %d, %d\n", er[1][0], *(ep2 + sizeof(ep)), *(*(er + 1) + 0), *(ep + sizeof(ep) - 1), *(++ep));

    // Calculating Rows
    int ec = ((int) (sizeof(er) / sizeof(er[0])));
    int el = ((int) (sizeof(er[0]) / sizeof(er[0][0]))); // Of 1st Row
    printf("\n %d %d", el, ec);

    printf("\n----------------------------\n");

    printf("Printing... 1.\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++)
            printf("%d ", *(*(dr + i) + j)); // printf("%d ", dr[i][j]);
        printf("\n");
    }
    printf("\n----------------------------\n");

    printf("Printing... 2.\n");
    for(int i = 0; i < ec; i++) {
        for(int j = 0; j < el; j++)
            printf("%d ", *(*(er + i) + j)); // printf("%d ", er[i][j]);
        printf("\n");
    }
    printf("\n----------------------------\n3.\n");

    int dcols = (int) (sizeof(dr[0]) / sizeof(dr[0][0]));
    int (*pdr)[dcols] = dr;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < dcols; j++)
            printf("%d ", *(*(pdr + i) + j)); // printf("%d ", er[i][j]);
        printf("\n");
    }
    printf("\n----------------------------\n4.\n");

    // Printing 2D Arrays -> using Only Single Loop
    int bLen = sizeof(dr) / sizeof((dr + 0) + 0); // sizeof(dr) / sizeof(dr + 0); 
    int aLen = sizeof(dr + 0);   
    printf("%d %d %d %d ", sizeof(dr), sizeof(dr + 2), sizeof(dr[0] + 0), bLen);
    printf("%d %d %d\n\n", **dr, **(dr + 2), **(dr + 5));        
    for(int i = 0; i < bLen; i++) {
        int pValue = *(*(dr + (i/bLen)) + (i%bLen));
        printf("%d ", pValue);
        if(i%aLen == 3)
            printf("\n");
    }
    printf("\n----------------------------\n");

    // Row crawler
    printf("5. Row Crawler \n");
    int m = sizeof(er + 0);    
    for(int i = 0; i < m; i++) {
        int *p = *(er + i);
        int *lastInRow = p + sizeof(p) - 1;
        while(p <= lastInRow) {                    
            printf("%d ", *p);
            p++;
        }
        printf("\n");        
    }
    printf("\n----------------------------\n6.");


    // Complete 2D Array Crawler - using only pointer
    printf("2D array only using 1 loop and pointers----------------------------\n");
    int *lastlastp = &dr[0][0] + sizeof(dr)/sizeof(dr[0][0]) - 1;
    int *tp = *dr;
    while(tp < lastlastp) {
        printf("%d ", *tp);
        tp++;                
    }
    printf("\n\n----------------------------\n");

    // 2D Arrays and functions
    print2DArray1(dr, 4, dcols);    
    int ecls = ((int) (sizeof(er[0]) / sizeof(er[0][0])));
    print2DArray1(er, ecls, ecls);
    print2DArray2SingleLine(dr, bLen);
    print2DArray2SingleLine2(dr, 4, dcols);
    print2DArray3a(er, ecls, ecls);
    print2DArray3b(*(er + 0), (*(er + 0) + (ecls * ecls) - 1));
    
    int qnm[2][3] = {
        {17990, 289120, 55250},
        {350100, 43520, 87860}
    };

    print2DArray1(qnm, 2, 3);
    printf("\n%d %d %d\n", sizeof(qnm), sizeof(*(qnm + 0)), (sizeof(qnm) / sizeof(*(qnm + 0))));
    printf("\n%d %d %d\n", sizeof(qnm), sizeof(qnm[0]), (sizeof(qnm) / sizeof(qnm[0])));
    int qnm_rows = (sizeof(qnm) / sizeof(*(qnm + 0))); // sizeof complete 2D Array / sizeof first row
    int qnm_cols = (sizeof(*(qnm + 0)) / sizeof(*(*(qnm + 0) + 0))); // sizeof first row / sizeof first element

    print2DArray1e(*(qnm + 0) + 0, qnm_rows, qnm_cols);
    print2DArray2SingleLine(qnm, (sizeof(qnm) / (sizeof(*(*(qnm + 0) + 0)))));
    print2DArray2SingleLine2(qnm, qnm_rows, qnm_cols);
    print2DArray3a(qnm, qnm_rows, qnm_cols);
    print2DArray3b(*(qnm + 0), (*(qnm + 0) + (qnm_rows * qnm_cols) - 1));
    
    return 0;
}

void print2DArray1(int (*pr)[], int rows, int cols) {
    printf("\n-----------------In fun 1----------------------\n");
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *((*pr + (i * cols)) + j));
        }
        printf("\n");
    }
}

void print2DArray1e(int *pr, int rows, int cols) {
    printf("\n-----------------In fun 1E----------------------\n");
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d   ", *(pr + i * cols + j));
        }
        printf("\n");
    }
}

void print2DArray2SingleLine(int (*pr)[], int blocs) {
    printf("\n-----------------In fun 2----------------------\n");
    printf("%d -> blocs in this 2D array \n", blocs);
    for(int i = 0; i < blocs - 1; i++) {    
        printf("%d, ", *(*pr + i));
    }
    printf("%d \n\n", *(*pr + blocs - 1));
}

void print2DArray2SingleLine2(int (*pr)[], int rows, int cols) {
    printf("\n-----------------In fun 3----------------------\n");
    int totalElements = rows * cols;
    for (int i = 0; i < totalElements; i++) {
        printf("%d ", *((int *)pr + i));
    }
    printf("\n");
}

void print2DArray3a(int (*pr)[], int rows, int cols) {
    printf("\n-----------------In fun 4----------------------\n");
    int *A = (int *)pr;
    int *B = A + (rows * cols) - 1;
    while(A < B) {
        printf("%d, ", *A);
        A++;
    }
    printf("%d ", *A);
}

void print2DArray3b(int *S, int *E) {
    printf("\n-----------------In fun 5----------------------\n");
    while(S < E) {
        printf("%d, ", *S);
        S++;
    }
    printf("%d ", *S);
}