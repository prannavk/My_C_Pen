#include <stdio.h>

/** 
 * 1D Array Traversals in C Programming
 * @author Krishna Pranav
 * 
*/

void printArray1(int ar[], int N);
void printPtrArray(int **p, int N);
// void example(int ar[]);

int main() {

    int pr[8] = {72, 68, 54, 43, 19};
    pr[7] = 435;    
    
    // Traversing int Array using integer variable
    int size = (int) (sizeof(pr) / sizeof(pr + 0));
    int t = size;    
    printf("Array eles using pos var \n");
    loop:
        if(t > 0) {
            printf("%d ", *(pr + (size - t)));
            t--;
            goto loop;
        }
    printf("\n");


    // Traversing int Array using pointers:
    int *mp = pr;
    int *lastp = mp + (sizeof(pr) / sizeof(*(pr + 0))) - 1; // Note: sizeof(*(pr + 0)) and sizeof(pr + 0) give the same output
    printf("Array eles using ptrs \n");
    while(mp <= lastp) {
        printf("%d ", *mp);
        mp++;
    }
    printf("\n");

    // Traversing int Array using function
    // proof of absence of sizeOf information when we pass array as a parameter to a function - 1
    int *ap = pr;
    int len = (sizeof(pr) / sizeof(*(pr + 0)));
    int *lp = ap + len - 1;
    printf("In Main: %d %d %d\n", ap, len, lp);
    printf("Also Here: &a + 1 gives: %d", (&pr + 1));
    printArray1(ap, len);

    // Array of Pointers
    int a1 = 3;
    int a2 = 7;
    int a8 = 44;
    int *p[4] = {&a1, &a2, &a8, (pr + 3)};    

    // Traversing using a variable:
    int plen = (int) (sizeof(p) / sizeof(p + 0));
    for(int i = 0; i < plen; i++)
        printf("%d ", **(p + i));
    printf("\n");

    // Traversing using a pointer
    int *(*ppar) = p;
    int **lpp = (ppar) + (sizeof(p) / sizeof(p + 0)) - 1;
    while(ppar <= lpp) {
        printf("%d ", **(ppar));
        ppar++;
    }
    printf("\n");

    // Traversing using a function
    printPtrArray(p, (int) (sizeof(p) / sizeof(p + 0)));

    // Dynamic Alloc 1D Array:
    // Check TPGa.C

    return 0;
}

void printArray1(int ar[], int N) {
    // proof of absence of sizeOf information - 2
    printf("\nInside the function : ");
    int *ap = ar;
    int len = (sizeof(ar) / sizeof(*(ar + 0)));
    int *lp = ap + len - 1;
    printf("%d %d %d <- See the difference\n", ap, len, lp);
    printf("Also Here: &a + 1 gives: %d", (&ar + 1));

    // Traversing using given N
    for(int i = 0; i < N; i++)
        printf("%d ", *(ar + i));
    printf("\n");
}

void printPtrArray(int **p, int N) {
    for(int i = 0; i < N; i++)
        printf("%d ", **(p + i));
    printf("\n");
}