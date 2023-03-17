#include <stdio.h>
#define MAX 100

void premesti(int a[], int indeksi[], int n);

int main() {
    int n, a[MAX], indeksi[MAX];
    scanf("%d", &n);
    if (n<=0 || n>MAX) {
        puts("-1");
        return 1;
    }
    int i;
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(i=0; i<n; i++) {
        scanf("%d", &indeksi[i]);
        if(indeksi[i]>=n || indeksi[i]<0) {
            puts("-1");
            return 1;
        }
    }
    premesti(a,indeksi,n);
    for(i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}

void premesti(int a[], int indeksi[], int n) {
    int i,p, b[MAX];
    for(i=0; i<n; i++) {
        p = indeksi[i];
        a[p] = b[i];
    }
    for(i=0; i<n; i++) {
        a[i] = b[i];
    }
}
