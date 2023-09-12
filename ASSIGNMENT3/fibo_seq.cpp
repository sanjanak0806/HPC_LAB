// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <omp.h>
// int fib(int x) {
//    if((x==1)||(x==0)) {
//       return(x);
//    }else {
//       return(fib(x-1)+fib(x-2));
//    }
// }
// int main() {
//      int n,result;
//   printf("Enter the term: ");
//     scanf("%d", &n);
//     double start_time_serial = omp_get_wtime();
//    result=fib(n);
//    double end_time_serial= omp_get_wtime();
//   printf("Parallel Method Time: %f seconds\n", (end_time_serial - start_time_serial));
//   printf("Result is %d\n", result);
//    return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
int fib(int n)
{
	int a = 0, b = 1, c, i;
	if (n == 0)
		return a;
	for (i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

// Driver code
int main()
{
	 int n,result;
  printf("Enter the term: ");
    scanf("%d", &n);
    double start_time_serial = omp_get_wtime();
   result=fib(n);
   double end_time_serial= omp_get_wtime();
  printf("Sequential Method Time: %f seconds\n", (end_time_serial - start_time_serial));
  printf("Result is %d\n", result);
   return 0;
}

// This code is contributed by Code_Mech
