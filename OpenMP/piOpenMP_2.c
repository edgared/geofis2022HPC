/********************************************************************
* Cálculo de PI en forma secuencial
*********************************************************************/

#include <stdio.h>
#include <omp.h>

double fabs(double);

double f(double a)
{
    return (4.0/(1.0 + a*a));
}

int main(int argc, char *argv[])
{
    int  n, i;
    double PI25 = 3.141592653589793238462643;
    double pi, h, sum, x;

    printf("Numero de intervalos a usar: ");
    scanf("%d",&n);

    h = 1.0/(double)n;
    sum = 0.0;                   // Suma de intervalos
    // La variable sum es una variable de reducción mediante suma
    #pragma omp parallel for reduction(+:sum) private(x, i)
    for(i = 1; i <= n; i++)
    {
        x = h*((double)i - 0.5);
        sum += f(x);
    }
    pi = h * sum;
    printf("\nPI es aproximadamente %.16f, el error cometido es %.16f\n", pi, fabs(pi - PI25));
    printf("\n");
    return 0;
}
