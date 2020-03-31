// Chapter 3 - exercise 5 - years to seconds

#include <stdio.h>

#define SECS_PER_YEAR 31560000

int main(void) {

  unsigned int age;

  printf("Age: ");
  scanf("%d", &age);

  printf("Seconds: %u\n", age * SECS_PER_YEAR);

  return 0;
}