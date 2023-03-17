#include <stdio.h>

int min(int x, int y, int z);

int main() {
    int a, b, c;
    printf("Unesite brojeve: ");
    scanf("%d%d%d", &a, &b, &c);
    printf("Minimum je: %d", min(a,b,c));
}

int min(int x, int y, int z) {
    int min=x;
    if(min>y) min=y;
    if(min>z) min=z;
    return min;
}
