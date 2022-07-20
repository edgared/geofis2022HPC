/********************************************************************
* Programa "Hola" en OpenMP
*********************************************************************/

#include <stdio.h>
#include <omp.h>

int main()
{
    int nthreads, tid;

    // Expande un grupo de threads
    #pragma omp parallel private(tid)      // Cada thread contiene sus propias copias
    {                                      // de variables
        tid = omp_get_thread_num();        // Obtiene el identificador del thread
        nthreads = omp_get_num_threads();  // Obtiene el número de threads
        printf("Hola desde el thread %d de %d threads\n", tid, nthreads);
    }  
    // Todos los threads se unen al thread maestro y finalizan
    return 0;
}
