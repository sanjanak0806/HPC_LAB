#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
int main() {
    int totalPoints = 10000000; 
    int pointsInsideCircle = 0; 
    double x, y;
    printf("Enter the number of terms: ");
    scanf("%d", &totalPoints);
    double start_time_serial = omp_get_wtime();
    for (int i = 0; i < totalPoints; ++i) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1.0) {
            pointsInsideCircle++;
        }
    }
    double pi = 4.0 * pointsInsideCircle / totalPoints;
    double end_time_serial = omp_get_wtime();
    printf("serial Method Time: %f seconds\n", (end_time_serial - start_time_serial));
    printf("Estimated value of pi: %f\n", pi);
    return 0;
}
