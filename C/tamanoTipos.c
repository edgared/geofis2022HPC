#include<stdio.h>

int main(void)
{
    // tamaño en bytes de los tipo s de datos
    printf("Tamaño en bytes que ocupa un char: %ld \n", sizeof(char));
    printf("Tamaño en bytes que ocupa un short: %ld \n", sizeof(short int));
    printf("Tamaño en bytes que ocupa un int: %ld \n", sizeof(int));
    printf("Tamaño en bytes que ocupa un long int: %ld \n", sizeof(long int));
    printf("Tamaño en bytes que ocupa un long long int: %ld \n", sizeof(long long int));
    printf("Tamaño en bytes que ocupa un float: %ld \n", sizeof (float));
    printf("Tamaño en bytes que ocupa un double: %ld \n", sizeof (double));
    printf("Tamaño en bytes que ocupa un long double: %ld \n", sizeof(long double));
    return 0;
}
