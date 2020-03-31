// Chapter 5 - Exercise 2 - Operators
#include <stdio.h>

#define LIMIT 10

int main(void) {

  int input = 0;
  int max;

  printf("number: ");
  scanf("%d", &input);
  max = input + LIMIT;

  while (input <= max) {
    printf("%d\n", input++);
  }

  return 0;
}