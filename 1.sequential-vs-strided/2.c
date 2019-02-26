// strided access

#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS 10000
#define INTERVAL 1000

int main()
{
  int* arr = calloc(ELEMENTS * INTERVAL, sizeof(int));
  int i, sum = 0, iterations = 0;

  //initialze values
  for (i = 0; i < ELEMENTS * INTERVAL; i += INTERVAL) {
      arr[i] = 9;
  }

  //calculate sum
  for (i = 0; i < ELEMENTS * INTERVAL; i += INTERVAL) {
    sum += arr[i];
    iterations++;
  }

  printf("Sum: %d; Iterations: %d\n", sum, iterations);

  free(arr);
  return 0;
}
