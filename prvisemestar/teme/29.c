#include <stdio.h>

int prebroj_manje(int x) {
    int n, br=0;
    while (scanf("%d", &n)!=EOF) {
        if(n<x) br++;
    }
    return br;
}
int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", prebroj_manje(x));
}
