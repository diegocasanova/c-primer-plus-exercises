// Chapter 11 - exercise 14
/* Write a power-law program that works on a command-line basis. The first
   command-line argument should be the type double number to be raised to a
   certain power, and the second argument should be the integer power.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if (argc != 3) {
    printf("Usage %s [number] [exponent]\n", argv[0]);
    return 0;
  }

  double exp, num;
  exp = atof(argv[2]);
  num = atof(argv[1]);

  printf("%.2f^%.2f = %.2f\n", num, exp, pow(num, exp));
  return 0;
}
