#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  const size_t size = 100000000;
  double *arr = malloc(size * sizeof(double));

  srand(0);
  for (size_t i = 0; i < size; i++) {
    arr[i] = rand();
  }
  
  double sum = 0;
  for (size_t i = 0; i < size; i++) {
    sum += arr[i];
  }

  printf("%lf\n", sum);

  free(arr);
  
  return 0;
}
