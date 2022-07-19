#include<stdio.h>

int main(void)
{
    int a = 1;
    float b = 4.0;
    int c = 2, d = 3;
    char letra = 'a';
    printf("Numero entero =%d \n", 28);
    printf("Numero entero =%5d \n", 28);  // total, 5 espacios
    printf("Numero real =%f \n", 28.2);
    printf("Numero real =%10.4f %d \n", 28.2, 10101); // total 10 espacios y 4 decimales 

    printf ("b = %f \n", b);
    printf ("c = %d \n", c);
    printf ("d = %d \n", d);
    printf ("La letra es %c \n", letra );

    return 0;
}
