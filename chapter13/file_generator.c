// Chapter 13 -
/* Generates a binary file with floating point numbers
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "numbers.dat"

int main(int argc, char *argv[]) {
  FILE *f_output;
  float *numbers;
  int elements;

  if (argc < 2) {
    printf("Usage: %s <number of elements>", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ((f_output = fopen(FILENAME, "wb")) == NULL) {
    fprintf(stderr, "Couldn't open the file");
    exit(EXIT_FAILURE);
  }

  elements = atoi(argv[1]);
  numbers = (float *)malloc(elements * sizeof(float));

  for (int i = 0; i < elements; i++) {
    numbers[i] = 100.0 * i + 1.0 / (i + 1);
  }

  fwrite(numbers, sizeof(numbers[0]), elements, f_output);

  free(numbers);
  fclose(f_output);

  return EXIT_SUCCESS;
}