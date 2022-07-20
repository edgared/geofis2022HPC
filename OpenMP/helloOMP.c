/********************************************************************
* Programa "Hola" en OpenMP
*********************************************************************/

#include <omp.h>
#include <stdio.h>

int main()
{
   // Expande un grupo de threads
   #pragma omp parallel
   {
      printf("Hola amigos del mundo OpenMP!\n");
   }
   return 0;   
}
