#include <stdio.h>
#include <string.h>
#define MAX 101

int main() {
    char s[MAX], t[MAX];
    scanf("%s %s", s, t);
    int i, j, br_preklapanja=0, r;
    for(i=0; s[i]; i++) {
        r=1;
        for(j=0; t[j]; j++) {
            if(t[j]==s[i+j]) 
                r*=1;
            else {
                r*=0;
                break;
            }
        }
        if(r) 
            br_preklapanja++;
    }
    printf("%d\n", br_preklapanja);
}
