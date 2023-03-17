#include <stdio.h>
#include <stdlib.h>

void greska();

int main() {
    int n;
    scanf("%d", &n);
    if(n <= 0)
        greska();

    int* niz;
    niz = (int*)malloc(n * sizeof(int));
    if(NULL == niz)
        greska();

    int i, j, br;

    for(i = 0; i < n; i++)
        scanf("%d", &niz[i]);

    for(i = 0; i < n; i++) {
        br = 0;
        for(j = 0; j < i; j++) {
            if(niz[i] > niz[j])
                br++;
        }
        printf("%d ", br);
    }
    printf("\n");
    
    free(niz);
    return 0;    
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}