// Chapter 3 - exercise 1 - Test limits on integer and float

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
  int int_max = INT_MAX;
  float float_max = FLT_MAX;
  float float_min = FLT_MIN;

  printf("int_max: \t\t%d\n", int_max);
  printf("int_max + 1: \t\t%d\n", int_max + 1);

  printf("float_max: \t\t%e\n", float_max);
  printf("float_max + 1: \t\t%e\n", float_max + 20000.0);

  printf("float_min: \t\t%e\n", float_min);
  printf("float_min - 1: \t\t%e\n", float_min + 20000.0);
}