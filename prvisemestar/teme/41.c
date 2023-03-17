#include <stdio.h>
#define MAX 100

void premesti(int a[], int indeksi[], int n) {
    int i, b[MAX];
    for(i=0; i<n; i++) {
        b[i]=a[indeksi[i]];
    }
    for(i=0; i<n; i++) {
        a[i]=b[i];
    }
}

void stampaj(int a[], int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n, a[MAX], indeksi[MAX]; 
    scanf("%d", &n);
    if(n<=0 || n>MAX) {
        printf("-1\n");
        return 1;
    }
    int i;
    for(i=0; i<n; i++) 
        scanf("%d", &a[i]);
    for(i=0; i<n; i++) {
        scanf("%d", &indeksi[i]);
        if(indeksi[i]>=n || indeksi[i]<0) {
            printf("-1\n");
            return 1;
        }
    }
    premesti(a,indeksi,n);
    stampaj(a,n);
}
