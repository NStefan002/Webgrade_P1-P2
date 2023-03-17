#include <stdio.h>
#define MAX 100

int main() {
    int n, m, takmicari[MAX][MAX];
    scanf("%d%d", &n, &m);
    if(n<3 || n>MAX || m<2 || m>MAX) {
        printf("-1\n");
        return 1;
    }
    int i, j;
    for(i=0; i<n; i++) 
        for(j=0; j<m; j++) { 
            scanf("%d", &takmicari[i][j]);
            if(takmicari[i][j]<0 || takmicari[i][j]>10) {
                printf("-1\n");
                return 1;
            }
        }
    
    float prosecna_ocena[MAX]={0}, max_ocena=0; 
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) 
            prosecna_ocena[i]+=takmicari[i][j];
        prosecna_ocena[i]/=m;
        if(prosecna_ocena[i]>max_ocena) {
            max_ocena=prosecna_ocena[i];
        }
    }
    for(i=0; i<n; i++)
        if(prosecna_ocena[i]==max_ocena) 
            printf("%d\n", i);
}
