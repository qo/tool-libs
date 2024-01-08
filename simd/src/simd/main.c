#include <stdio.h>

#include <immintrin.h>

int main() {

  const size_t size = 100000000;
  double *arr = malloc(size * sizeof(double));

  srand(0);
  for (size_t i = 0; i < size; i++) {
    arr[i] = rand();
  }

  __m128d vsum = _mm_set1_pd(0.0);

  for (int i = 0; i < size; i += 2) {
    __m128d v = _mm_load_pd(&arr[i]);
    vsum = _mm_add_pd(vsum, v);
  }

  vsum = _mm_hadd_pd(vsum, vsum);

  double sum = _mm_cvtsd_f64(vsum);

  printf("%f\n", sum);

  return 0;
}
