#include <stdio.h>

int ce = 44;

union berlin
{
    int row;
    char div;
} ub1;

int main()
{
    ub1.div = 'B';
    // Above allocation is done and value is stored
    printf("\nunion berlin members data: %d - row and %c - div\n", ub1.row, ub1.div);
    ub1.row = 44;
    // This allocation is done and value is stored, but the value of the div member is lost
    printf("\nunion berlin members data now: %d - row and %c - div\n", ub1.row, ub1.div);
    return 0;
}
