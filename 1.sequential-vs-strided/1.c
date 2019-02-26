//sequential access

#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS 10000

int main()
{
  int* arr = calloc(ELEMENTS, sizeof(int));
  int i, sum = 0 , iterations = 0;

  //initalize input
  for (i = 0; i < ELEMENTS; i++)
    arr[i] = 9; //bcoz 9 is my lucky number

  //calculate sum
  for (i = 0; i < ELEMENTS; i++) {
    sum += arr[i];
    iterations++;
  }

  printf("Sum: %d; Iterations: %d\n", sum, iterations);

  free(arr);
  return 0;
}

