#include <stdio.h>
#define MAX 100

void ucitaj(float m[][MAX], int n) {
    int i, j;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%f", &m[i][j]);
}

int kososimetricna(float m[][MAX], int n) {
    int i, j, r=1;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(-m[i][j]==m[j][i])
                r*=1;
            else
                r*=0;
    return r;
//             1 2 3    1 4 7
//             4 5 6    2 5 8
//             7 8 9    3 6 9
}

float min_max(float m[][MAX], int n){
    float min=m[0][0], max=m[0][0];
    int i, j, r=1;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            if(min>m[i][j])
                min=m[i][j];
            if(max<m[i][j])
                max=m[i][j];
        }
    if(kososimetricna(m,n)) 
        return min;
    else 
        return max;
}

int main() {
    int n;
    float m[MAX][MAX];
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    ucitaj(m,n);
    printf("%.2f\n", min_max(m,n));
}
