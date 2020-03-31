// Chapter 9 - exercise 10
/* Write and test a Fibonacci() function that uses a loop instead of recursion
 * to calculate Fibonacci numbers.
 */

#include <stdio.h>

unsigned long fibonacci(unsigned);

int main(void) {

  unsigned long number = 0;

  scanf("%ld", &number);
  printf("fibonacci(%ld) = %ld\n", number, fibonacci(number));

  return 0;
}

unsigned long fibonacci(unsigned number) {

  unsigned long a, b, c;
  a = c = 0;
  b = 1;

  for (int i = 0; i < number; i++) {
    c = b + a;
    a = b;
    b = c;
  }

  return a;
}
