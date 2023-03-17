#include <stdio.h>
#include <math.h>
#define MAX 101

int main() {
    int n;
    float m[MAX][MAX];
    scanf("%d", &n);
    if(n%2==0 || n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    int i,j;
    for(i=0; i<n; i++) 
        for(j=0; j<n; j++) 
            scanf("%f", &m[i][j]);
    float s, suma=0;
    int r=1;
    for(i=0; i<n; i++) {
        s=0;
        for(j=0; j<n; j++) {
            s+=fabs(m[i][j]);
            suma+=m[i][j];
        }
        if(fabs(m[i][i])>s-fabs(m[i][i]))
            r*=1;
        else 
            r*=0;
    }
    if(r) 
        printf("%.2f\n", suma);
    else 
        printf("0\n");
}
