#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska();
float nula(float a, float b, float eps);
float f(float x);

int main()
{
    float a, b, eps;
    scanf("%f%f%f", &a, &b, &eps);
    if(a > b || a == 1 || a <= 0)
        greska();
    
    printf("%f\n", nula(a, b, eps));
    return 0;
}

void greska()
{
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

float nula(float a, float b, float eps)
{
    if(a >= b)
        greska();
    float s = a + (b - a)/2;
    float vredost = f(s);
    // printf("%f %f %f ", a, b, s);
    // printf("%f\n", vredost);
    if(fabs(vredost) < eps)
        return s;
    
    float l_vrednost = f(a);
    if(l_vrednost * vredost < 0.0)  // da li su razl. znaka
        return nula(a, s, eps);
    
    return nula(s, b, eps);
}

float f(float x)
{
    return (5 * sin(x) * log(x));
}