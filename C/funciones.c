#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int v1, v2, resultado;

    printf("Hola Mundo!\n");
    puts("Hola amigos!\n");

    presentacion();

    printf("Digite un numero n1: \n ");
    scanf("%d", &v1);
    printf("Digite un numero n2: \n ");
    scanf("%d", &v2);

    resultado = multiplicacion(v1,v2);
    printf("El resultado es: %d \n ", resultado);

    salida();
    return 0;
}

// Función
void presentacion(void)
{
    printf("Este es un curso introductorio");
    printf("de Programación Paralela en Geofísica y afines!\n");
}

// Otra función
int multiplicacion(int N1, int N2)
{
    int resultado;
    resultado = N1*N2;
    return(resultado);
}

// Mas una función
void salida(void)
{
  printf("Saliendo del curso\n");
}
