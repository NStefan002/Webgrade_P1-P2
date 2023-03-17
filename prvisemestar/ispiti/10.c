#include <stdio.h>
#include <string.h>
#define MAX 101

int main() {
    char s[MAX], t[MAX];
    scanf("%s %s", s, t);
    int duzina=0, r, i, j;
    for(i=0; s[i]; i++) {
        for(j=0; t[j]; j++) {
            if(s[i]==t[j]) {
                duzina++;
                r=1;
                break;
            }
            else 
                r=0;
//             printf("r %d\n", r);
        }
        if(!r) 
            break;
    }
    printf("%d\n", duzina);
}
