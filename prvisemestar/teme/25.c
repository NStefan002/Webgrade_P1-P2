#include <stdio.h>

int main() {
    char c;
    int i=0;
    while ((c=getchar())!=EOF) {
        if (c=='[') 
            i++;
        if (c==']') 
            i--; 
        if (i<0) {
            printf("0\n");
            return 0;
        }
        }
    if (i==0) printf("1\n");
    else printf("0\n");
}
