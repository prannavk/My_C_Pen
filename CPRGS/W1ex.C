#include <stdio.h>

static int globnum = 6;
static int num = 7;
static int a = -3;
static int np = -3;

int hehe()
{
    printf("\nokokokhehe\n");
    return 1;
}

int main() {
    for(a++; a++; a++)
        printf("Hello World\n");
    for (int i = 5; i < 3;)
        printf("----------lsjkdnojkn");
    printf("\nokok\n");
    for (; hehe();)
    {
        printf("\n wwww \n");
        break;
    }

    int y = 1;
    if(y == 1)
        printf("\n xyz \n");
    for(;y == 1;) {
        printf("\nSame xyz but using for instead of if\n");
        break;
    }

    
c:
    for (globnum; globnum < 8; globnum++)
    {
        printf("\ngg - %d\n", y);
    }
    y++;
    if (y <= 3)
    {
        printf("\ng back\n");
        goto c;
    }
    for(np++;np++;) {
        printf("\n++++%d++++\n", np++);
    }
    for(;;) { printf("XCV"); break; }
    return 0;
}