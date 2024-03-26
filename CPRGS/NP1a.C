#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n > 0){
        char word[101];
        scanf("%s", word);
        int wLen = strlen(word);
        if(wLen <= 10) {
            printf("%s\n", word);
        }
        else {
            printf("%c%d%c\n", word[0], (wLen - 2), word[wLen - 1]);
        }
        n--;
    }
    return 0;
}