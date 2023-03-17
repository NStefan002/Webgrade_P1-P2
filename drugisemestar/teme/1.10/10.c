#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

void greska();

int main(int argc, char* argv[]) {
    if(argc != 3)
        greska();
    
    int A[MAX][MAX];
    int m, n;
    m = atoi(argv[1]);
    n = atoi(argv[2]);

    if(m <= 0 || m > MAX || n <= 0 || n > MAX)
        greska();

    int i, j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    
    int v, k, min, max;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            max = A[i][j];
            min = A[i][j];
            for(v = 0; v < m; v++) {
                if(min > A[i][v])
                    min = A[i][v];
            }
            for(k = 0; k < n; k++) {
                if(max < A[k][j])
                    max = A[k][j];
            }
            if(A[i][j] == max && A[i][j] == min) {
                printf("%d %d %d\n", i, j, A[i][j]);
                break;
            }
        }
    }

    return 0;
}

void greska() {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}