#include <stdio.h>

int ukloni_stotine(int n);

int main() {
    int x;
    printf("Unesite broj ");    // za slucaj da se prvo unese nula
    scanf("%d", &x);
    if (x==0) return 0;
    printf("%d\n", ukloni_stotine(x));
    while(x!=0) {
        printf("Unesite broj: ");
        scanf("%d", &x);
        printf("%d\n", ukloni_stotine(x));
    }
}

int ukloni_stotine(int n) {
    n=n%100+(n/100)*100;
    return n;
}
