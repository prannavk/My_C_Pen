#include <stdio.h>

int main()
{
    int marks;
    printf("\nEnter Gate Marks:\n");
    scanf("My Marks: %d", &marks);
    
    if (marks > 50)
    {
        printf("\nOhk Cool!!\n");
    }
    else if (marks <= 50 && marks > 40)
    {
        printf("\nOk OK!\n");
    }
    else if (marks <= 40 && marks > 29)
    {
        printf("\nWhat! couldve been better\n");
    }

    printf("\nWhat do u say?\n");
    return 0;
}