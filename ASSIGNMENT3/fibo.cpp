#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
int fibonacci(int n)
{
  int i, j;
  if (n < 2)
    return n;
  else
  {
#pragma omp task shared(i)
    i = fibonacci(n - 1);
#pragma omp task shared(j)
    j = fibonacci(n - 2);

#pragma omp taskwait
    return i + j;
  }
}

int main()
{

  int n;
  printf("Enter the term: ");
    scanf("%d", &n);
  // cin >> n;
  int result;
   double start_time_parallel = omp_get_wtime();
#pragma omp parallel
  {
#pragma omp single

    result = fibonacci(n);
  }
  double end_time_parallel = omp_get_wtime();
  printf("Parallel Method Time: %f seconds\n", (end_time_parallel - start_time_parallel));
  printf("Result is %d\n", result);
}