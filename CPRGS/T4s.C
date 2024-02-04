#include <stdio.h>
#define AREA(A, B) A *B
#define EXPRESSION1(A, B, C) (A * (B + 1) - (C % 223))

// Analyse the output carefully
int main()
{
  printf("Expression result: %d\n ", EXPRESSION1(38, 42, 4460));
  printf("Area result: %d\n ", AREA(40 + 8, 1 + 20));
  return 0;
}