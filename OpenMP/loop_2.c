#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(int argc, char *argv[])
{
    int i,x;

    x = 44;
    #pragma omp parallel for lastprivate(x)
    for(i=0;i<=10;i++)
    {
        x = i;
        printf("Número de Thread: %d  ---  x: %d\n",omp_get_thread_num(),x);
    }
    printf("Ahora x es: %d\n",x);
    return 0;
}
