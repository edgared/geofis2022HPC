#include<stdio.h> 
#include<complex.h>

int main(void) 
{ 
    double _Complex c1 , c2 , c3; 
    c1 = 1.0 + 3 * I;
    c2 = 1.0 + 3 * I; 
    c3 = c1+c2; 
    printf("La suma es: %.2f %.2f\n", creal(c3), cimag(c3 )); 
    return 0;
}
