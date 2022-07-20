#include<stdio.h>
#include<omp.h>
//#include<stdlib.h>

int main(int argc, char *argv[])
{
    int i,x;

    x = 44;
    #pragma omp parallel for private(x)
    for(i=0;i<=10;i++)
    {
        x = i;
        printf("Número de Thread: %d  ---  x: %d\n",omp_get_thread_num(),x);
    }
    printf("Ahora x es: %d\n",x);
    return 0;
}
