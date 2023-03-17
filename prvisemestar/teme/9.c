#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    printf("%d", (x/1000)*100+(x/100%10)*10+(x%100/10)+(x%10)*1000);
}
