// Chapter 5 - Exercise 5/6 - Operators
#include <stdio.h>

int main(void) {
  unsigned long long count, sum, square;
  int max;
  count = square = sum = max = 0;

  printf("Enter the max value: ");
  scanf("%d", &max);

  while (count++ < max) {
    sum += count;
    square += count * count;
  }
  printf("sum = %llu\n", sum);
  printf("square = %llu\n", square);

  return 0;
}
