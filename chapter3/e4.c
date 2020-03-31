// Chapter 3 - exercise 4 - printing floating point
#include <stdio.h>

int main(void) {

  float number;

  printf("Enter a floating-point value: ");
  scanf("%f", &number);

  printf("fixed-point notation: %.6f\n", number);
  printf("exponential notation: %e\n", number);
  printf("p notation: %a\n", number);

  return 0;
}