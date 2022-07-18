/********************************************************************
* Programa "Hola" en MPI
*********************************************************************/

#include <mpi.h> 
#include <stdio.h>

int main(int argc, char *argv[])
{
    int myrank, size;
    MPI_Init(&argc, &argv);                  // Inicializa el entorno MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);  // Número de identificación 
                                             // del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);    // Número total de procesos 
    printf("......... Hola desde el proceso %d de %d\n", myrank, size);
    MPI_Finalize();                          // Finaliza el entorno MPI
   return 0;
}
