# include <math.h>
# include <mpi.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main(int argc, char *argv[]);
int prime_number(int n, int id, int p);
void timestamp( );

/******************************************************************************/
int main(int argc, char *argv[])
{
  int id;
  int ierr;
  int n;
  int n_factor;
  int n_hi;
  int n_lo;
  int p;
  int primes;
  int primes_part;
  double wtime;

  n_lo = 1;
  n_hi = 262144;
  n_factor = 2;
/*
  Initialize MPI.
*/
  ierr = MPI_Init (&argc, &argv);

  if (ierr != 0)
  {
    printf ("\n");
    printf ("PRIME_MPI - Fatal error!\n");
    printf ("  MPI_Init returns nonzero IERR.\n");
    exit (1);
  }
/*
  Get the number of processes.
*/
  ierr = MPI_Comm_size(MPI_COMM_WORLD, &p);
/*
  Determine this processes's rank.
*/
  ierr = MPI_Comm_rank(MPI_COMM_WORLD, &id);

  if (id == 0)
  {
    timestamp( );
    printf("\n");
    printf("PRIME_MPI\n");
    printf("  C/MPI version\n");
    printf("\n" );
    printf("  An MPI example program to count the number of primes.\n");
    printf("  The number of processes is %d\n", p);
    printf("\n");
    printf("         N        Pi          Time\n");
    printf("\n");
  }

  n = n_lo;

  while (n <= n_hi)
  {
    if (id == 0)
    {
      wtime = MPI_Wtime( );
    }
    ierr = MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    primes_part = prime_number(n, id, p);

    ierr = MPI_Reduce ( &primes_part, &primes, 1, MPI_INT, MPI_SUM, 0, 
      MPI_COMM_WORLD);

    if (id == 0)
    {
      wtime = MPI_Wtime ( ) - wtime;
      printf( "  %8d  %8d  %14f\n", n, primes, wtime);
    }
    n = n * n_factor;
  }
/*
  Terminate MPI.
*/
  ierr = MPI_Finalize( );
/*
  Terminate.
*/
  if (id == 0) 
  {
    printf ("\n");         
    printf ("PRIME_MPI - Master process:\n");         
    printf ("  Normal end of execution.\n"); 
    printf ("\n");
    timestamp( );        
  }
  return 0;
}

/******************************************************************************/
int prime_number(int n, int id, int p)
{
  int i;
  int j;
  int prime;
  int total;

  total = 0;

  for (i = 2 + id; i <= n; i = i + p)
  {
    prime = 1;
    for (j = 2; j < i; j++)
    {
      if ((i % j) == 0)
      {
        prime = 0;
        break;
      }
    }
    total = total + prime;
  }
  return total;
}

/******************************************************************************/
void timestamp( )
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  printf ( "%s\n", time_buffer );

  return;
# undef TIME_SIZE
}
