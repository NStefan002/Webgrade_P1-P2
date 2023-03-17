#include <stdio.h>
#include <string.h>
#define MAX 101

int main() {
    char lanac_1[MAX], lanac_2[MAX];
    int i, r=0;
    scanf("%s", lanac_1);
    scanf("%s", lanac_2);
    for(i=0; i<strlen(lanac_1); i++) {
        if (!((lanac_1[i]=='a' && lanac_2[i]=='t') || (lanac_1[i]=='t' && lanac_2[i]=='a') || (lanac_1[i]=='c' && lanac_2[i]=='g') || (lanac_1[i]=='g' && lanac_2[i]=='c')))
            r++;
    }
    printf("%d\n", r);
}
