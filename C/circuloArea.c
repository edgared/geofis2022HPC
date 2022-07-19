#include<stdio.h>
//#define PI 3.141593
const double PI = 3.141593;

int main(void)
{
    float radio;
    float area;
    printf("Introduzca el radio: ");
    scanf("%f", &radio);
    area = PI * radio * radio;
    printf("El area del circulo es %5.4f \n", area);
    return 0;
}
