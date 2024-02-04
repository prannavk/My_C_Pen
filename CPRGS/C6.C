#include <stdio.h>

struct student
{
    int rno;
    int age;
    float fees;
} std1; // Note: std here is a global variable

struct test 
{
    char key;
    int val;
} t1, *tp;

int main()
{
    struct student s1;    // s1 is local to main
    struct student st[3]; // This an array of type struct
    struct student *ps;   // pointer of student type i.e. points to address of a student struct variable

    printf("struct loc and size -> %u - %d", &s1, sizeof(s1));
    printf("size of struct type ptr -> %d", sizeof(ps));

    // Member access using variable
    s1.rno = 5;
    s1.age = 28;
    s1.fees = 18000;

    ps = &s1;

    // Member access using pointer
    ps->age = 18;

    printf("\n values of s1 struct: rno = %d, age = %d, fees = %0.2lf\n", s1.rno, s1.age, ps->fees);


    tp = &t1;
    

    return 0;
}