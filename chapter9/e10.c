// Chapter 9 - exercise 10
/* Chapter 6, “C Control Statements: Looping,” (Listing 6.20) shows a power()
function that returned the result of raising a type double number to a positive
integer value. Improve the function so that it correctly handles negative
powers. Also, build into the function that 0 to any power other than 0 is 0 and
that any number to the 0 power is 1. (It should report that 0 to the 0 is
undefined, then say it’s using a value of 1.) Use a loop. Test the function in a
program.
 */
#include <ctype.h>
#include <stdio.h>

void to_base_n(int, int);
int read_numbers(int *, int *);

int main(void) {

  int number, base;
  number = base = 0;

  while (read_numbers(&number, &base) == 2) {
    printf("%d base %d = ", number, base);
    to_base_n(number, base);
    printf("\n");
  }

  return 0;
}

void to_base_n(int number, int base) {
  if (number < base) {
    printf("%d", number);
    return;
  }
  to_base_n(number / base, base);
  printf("%d", number % base);
}

int read_numbers(int *number, int *exp) {
  printf("number, base: ");
  return scanf("%d,%d", number, exp);
}
