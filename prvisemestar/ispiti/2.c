#include <stdio.h>
#include <string.h>
#define MAX 31

int main() {
    char n1[MAX], n2[MAX];
    scanf("%s %s", n1, n2);
    if(strlen(n1)==strlen(n2)) {
        printf("-1\n");
        return 1;
    }
    char p[MAX];
    if(strlen(n1)<strlen(n2)) {
        strcpy(p,n1);
        strcpy(n1,n2);
        strcpy(n2,p);
    } 
    int i, j, r=1;
    for(i=strlen(n1)-strlen(n2), j=0; n1[i]; i++, j++) {
        if(n1[i]==n2[j])
            r*=1;
        else r*=0;
    }
//     printf("%ld\n", strlen(n1));
//     printf("%ld\n", strlen(n2));
    if(r) 
        printf("%ld\n", strlen(n1)-strlen(n2));
    else 
        printf("-1\n");
}
