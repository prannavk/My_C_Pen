#include <stdio.h>

int main() {
    char *sp = "pink";
    char sp2[] = "pink";
    sp2[1] = 'u';
    // sp[1] = 'o'; // Uncommenting this returns an error
    printf("\n%s and %s", sp, sp2);
    return 0;
}